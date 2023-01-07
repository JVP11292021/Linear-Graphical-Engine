#include "cMatrix.h"
#include "lmm_exceptions.h"
#include "carr.h"

#include <stdlib.h>

// =====================================================================
// Custom matrix functions
// =====================================================================

LMM_FUNC_DECL mat constructMat(f32* items, uint32 rows, uint32 cols) {
	return (mat) {items, rows, cols, rows * cols * sizeof(f32), (rows * cols)};
}

LMM_FUNC_DECL mat* constructDynMat(f32* items, uint32 rows, uint32 cols, uint16 nBytes) {
	mat* m;
	if (nBytes <= 1)
		m = (mat*)malloc(1 * sizeof(mat));
	else
		m = (mat*)malloc(nBytes * sizeof(mat));

	if (!m == NULL) {
		m->items = items;
		m->rows = rows;
		m->cols = cols;
		m->size = rows * cols * sizeof(f32);
		m->totalItems = (rows * cols);
		return m;
	}
	else {
		LMM_EXCEPTION("ERROR::LMM:: Matrix pointer is null.");
	}
}

LMM_FUNC_DECL int8 destructMat(mat* m) {
	free(m->items);

	m->items = NULL;

	if (m->items == NULL)
		return LMM_SUCCESS;
	else {
		LMM_EXCEPTION("ERROR::LMM:: Matrix destruction error.");
	}
}

LMM_FUNC_DECL int8 destructDynMat(mat* m) {
	free(m->items);
	m->items = NULL;

	if (m->items == NULL) {
		free(m);
		m = NULL;

		if (m == NULL)
			return LMM_SUCCESS;
		else {
			LMM_EXCEPTION("ERROR::LMM:: Matrix destruction error.");
		}
	}
	else {
		LMM_EXCEPTION("ERROR::LMM:: Matrix destruction error.");
	}
}


LMM_FUNC_DECL mat addMat(mat a, mat b) {
	if (a.rows == b.rows && a.cols == b.cols) {
		mat m = constructMat(zeros_f(a.rows, a.cols), a.rows, a.cols);

		for (int r = 0; r < a.rows; r++)
			for (int c = 0; c < a.cols; c++)
				m.items[r * a.cols + c] = a.items[r * a.cols + c] + b.items[r * b.cols + c];
		return m;
	}
	else {
		LMM_EXCEPTION("ERROR::LMM:: Matrix rows and cols of mat[A] & mat[b] not the same.");
	}
}

LMM_FUNC_DECL mat subMat(mat a, mat b) {
	if (a.rows == b.rows && a.cols == b.cols) {
		mat m = constructMat(zeros_f(a.rows, a.cols), a.rows, a.cols);

		for (int r = 0; r < a.rows; r++)
			for (int c = 0; c < a.cols; c++)
				m.items[r * a.cols + c] = a.items[r * a.cols + c] - b.items[r * b.cols + c];
		return m;
	}
	else {
		LMM_EXCEPTION("ERROR::LMM:: Matrix rows and cols of mat[A] & mat[b] not the same.");
	}
}

LMM_FUNC_DECL mat negate(mat m) {
	mat nm = constructMat(zeros_f(m.rows, m.cols), m.rows, m.cols);

	for (int r = 0; r < m.rows; r++)
		for (int c = 0; c < m.cols; c++)
			nm.items[r * nm.cols + c] = m.items[r * m.cols + c] * -1;
	return nm;
}


LMM_FUNC_DECL mat sSub(mat m, f32 s) {
	mat nm = constructMat(zeros_f(m.rows, m.cols), m.rows, m.cols);

	for (int r = 0; r < m.rows; r++)
		for (int c = 0; c < m.cols; c++)
			nm.items[r * nm.cols + c] = m.items[r * m.cols + c] - s;
	return nm;
}

LMM_FUNC_DECL mat sAdd(mat m, f32 s) {
	mat nm = constructMat(zeros_f(m.rows, m.cols), m.rows, m.cols);

	for (int r = 0; r < m.rows; r++)
		for (int c = 0; c < m.cols; c++)
			nm.items[r * nm.cols + c] = m.items[r * m.cols + c] + s;
	return nm;
}

LMM_FUNC_DECL mat sDiv(mat m, f32 s) {
	mat nm = constructMat(zeros_f(m.rows, m.cols), m.rows, m.cols);

	for (int r = 0; r < m.rows; r++)
		for (int c = 0; c < m.cols; c++)
			nm.items[r * nm.cols + c] = m.items[r * m.cols + c] / s;
	return nm;
}

LMM_FUNC_DECL mat sMul(mat m, f32 s) {
	mat nm = constructMat(zeros_f(m.rows, m.cols), m.rows, m.cols);

	for (int r = 0; r < m.rows; r++)
		for (int c = 0; c < m.cols; c++)
			nm.items[r * nm.cols + c] = m.items[r * m.cols + c] * s;
	return nm;
}


LMM_FUNC_DECL mat adjoint(mat m) {
	mat adjMat = zerosMat(m.rows, m.cols);

	int sign = 1;

	for (int r = 0; r < m.rows; r++) {
		for (int c = 0; c < m.cols; c++) {
			mat coMat = cofactor(m, r, c);

			sign = ((r + c) % 2 == 0) ? 1 : -1;

			adjMat.items[c * adjMat.cols + r] = (sign) * (determinant(coMat, m.rows - 1));
		}
	}

	return adjMat;
}

LMM_FUNC_DECL mat inverse(mat m) {
	if (m.rows == m.cols) {
		f32 det = determinant(m, m.rows);
		mat invMat = zerosMat(m.rows, m.cols);

		if (det == 0) {
			printf("WARNING::SINGULAR MATRIX, CAN'T FIND ITS INVERSE.\n");
			return m;
		}

		mat adjMat = adjoint(m);

		for (int r = 0; r < m.rows; r++)
			for (int c = 0; c < m.cols; c++)
				invMat.items[r * invMat.cols + c] = adjMat.items[r * adjMat.cols + c] / det;

		return invMat;
	}
	else {
		LMM_EXCEPTION("ERROR::LMM:: Matrix needs to be square to calculate inverse.")
	}
}

LMM_FUNC_DECL f32 determinant(mat m, uint32 n) {
	f32 D = 0; 

	if (n == 1)
		return m.items[0];

	int32 sign = 1;

	for (int f = 0; f < n; f++) {
		mat coMat = cofactor(m, 0, f);
		D += sign * m.items[0 * m.cols + f] * determinant(coMat, n - 1);

		sign = -sign;
	}

	return D;
}

LMM_FUNC_DECL mat cofactor(mat m, uint32 row, uint32 col) {
	int i = 0, j = 0;
	mat coMat = constructMat(zeros_f(m.rows, m.cols), m.rows, m.cols);

	for (int r = 0; r < m.rows; r++)
		for (int c = 0; c < m.cols; c++) {
			if (r != row && c != col) {
				coMat.items[i * coMat.cols + j++] = m.items[r * m.cols + c];

				if (j == m.cols - 1) {
					j = 0;
					i++;
				}
			}
		}
	return coMat;
}


LMM_FUNC_DECL mat dot(mat a, mat b) {
	if (a.cols == b.rows) {
		mat dotMat = zerosMat(a.rows, b.cols);

		for (int r = 0; r < dotMat.rows; r++) {
			for (int c = 0; c < dotMat.cols; c++) {
				for (int k = 0; k < dotMat.cols; k++) {
					dotMat.items[r * dotMat.cols + c] = dotMat.items[r * dotMat.cols + c] + a.items[r * a.cols + k] * b.items[k * b.cols + c];
				}
			}
		}

		return dotMat;
	}
	else {
		LMM_EXCEPTION("ERROR::LMM:: Matrices aren't compatible to calculate dot product");
	}
}


LMM_FUNC_DECL mat transpose(mat m) {
	mat trans = zerosMat(m.cols, m.rows);

	for (int r = 0; r < trans.rows; r++) {
		for (int c = 0; c < trans.cols; c++) {
			trans.items[r * trans.cols + c] = m.items[c * m.cols + r];
		}
	}

	return trans;
}

LMM_FUNC_DECL mat reverse(mat m) {
	mat rev = zerosMat(m.rows, m.cols);

	for (int r = 0; r < rev.rows; r++) {
		for (int c = 0, k = rev.cols - 1; c < k; c++, k--) {
			rev.items[c * rev.cols + r] = m.items[k * m.cols + r];
		}
	}

	return rev;
}

LMM_FUNC_DECL mat identityMat(uint32 rows, uint32 cols) {
	if (rows == cols) {
		f32* ptrArr = (f32*)malloc((rows * cols) * sizeof(f32));

		if (!ptrArr == NULL) {
			for (int r = 0; r < rows; r++) {
				for (int c = 0; c < cols; c++) {
					if (r == c)
						ptrArr[r * cols + c] = 1;
					else
						ptrArr[r * cols + c] = 0;
				}
			}

			return (mat) {
				ptrArr, rows, cols, rows * cols * sizeof(f32), (rows * cols)
			};
		}
		else {
			LMM_EXCEPTION("ERROR::LMM:: Wasn't able to construct matrix pointer");
		}
	}
	else {
		LMM_EXCEPTION("ERROR::LMM:: ID matrix needs to be square.")
	}
}

LMM_FUNC_DECL mat zerosMat(uint32 rows, uint32 cols) {
	f32* ptrArr = (f32*)malloc((rows * cols) * sizeof(f32));

	if (!ptrArr == NULL) {
		for (int r = 0; r < rows; r++) {
			for (int c = 0; c < cols; c++) {
				ptrArr[r * cols + c] = 0;
			}
		}

		return (mat) {
			ptrArr, rows, cols, sizeof(f32), (rows * cols)
		};
	}
	else {
		LMM_EXCEPTION("ERROR::LMM:: Wasn't able to construct matrix pointer");
	}
}

LMM_FUNC_DECL mat onesMat(uint32 rows, uint32 cols) {
	f32* ptrArr = (f32*)malloc((rows * cols) * sizeof(f32));

	if (!ptrArr == NULL) {
		for (int r = 0; r < rows; r++) {
			for (int c = 0; c < cols; c++) {
				ptrArr[r * cols + c] = 1 ;
			}
		}

		return (mat) {
			ptrArr, rows, cols, sizeof(f32), (rows * cols)
		};
	}
	else {
		LMM_EXCEPTION("ERROR::LMM:: Wasn't able to construct matrix pointer");
	}
}

LMM_FUNC_DECL mat translate(mat m, vec4f v) {
	f32 vec_x = v.x;
	f32 vec_y = v.y;
	f32 vec_z = v.z;
	f32 vec_w = v.w;

	for (int r = 0; r < m.rows; r++) {
		for (int c = 0; c < m.cols; c++) {
			if (m.rows <= 4 && m.cols <= 4) {
				if (r == 0)
					m.items[r * m.cols + c] *= vec_x;
				else if (r == 1)
					m.items[r * m.cols + c] *= vec_y;
				else if (r == 2)
					m.items[r * m.cols + c] *= vec_z;
				else if (r == 3)
					m.items[r * m.cols + c] *= vec_w;
			}
			else {
				LMM_EXCEPTION("ERROR::LMM:: Matrix translation not possible.");
				break;
			}
		}
	}
}

LMM_FUNC_DECL void printMat(mat* m) {
	for (int r = 0; r < m->rows; r++) {
		for (int c = 0; c < m->cols; c++) {
			printf("%f ", *(m->items + r * m->cols + c));
		}
		printf("\n");
	}
	printf("\n");
}
