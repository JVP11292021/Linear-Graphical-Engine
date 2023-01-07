#include "carr.h"

LMM_FUNC_DECL f32* arrange_f(uint32 rows, uint32 cols) {
	f32* ptrArr = (f32*)malloc((rows * cols) * sizeof(f32));
	uint32 count = 1;

	if (!ptrArr == NULL) {
		for (int r = 0; r < rows; r++) {
			for (int c = 0; c < cols; c++) {
				ptrArr[r * cols + c] = count;
				count++;
			}
		}
		return ptrArr;

	}
	else {
		LMM_EXCEPTION("ERROR::LMM:: Dynamic array error.");
	}
}

LMM_FUNC_DECL f64* arrange_d(uint32 rows, uint32 cols) {
	f64* ptrArr = (f64*)malloc((rows * cols) * sizeof(f64));
	uint32 count = 1;

	if (!ptrArr == NULL) {
		for (int r = 0; r < rows; r++) {
			for (int c = 0; c < cols; c++) {
				ptrArr[r * cols + c] = count;
				count++;
			}
		}
		return ptrArr;

	}
	else {
		LMM_EXCEPTION("ERROR::LMM:: Dynamic array error.");
	}
}

LMM_FUNC_DECL f32* zeros_f(uint32 rows, uint32 cols) {
	f32* ptrArr = (f32*)malloc((rows * cols) * sizeof(f32));

	if (!ptrArr == NULL) {
		for (int r = 0; r < rows; r++) {
			for (int c = 0; c < cols; c++) {
				ptrArr[r * cols + c] = 0;
			}
		}

		return ptrArr;
	}
	else {
		LMM_EXCEPTION("ERROR::LMM:: Dynamic array error.");
	}
}

LMM_FUNC_DECL f64* zeros_d(uint32 rows, uint32 cols) {
	f64* ptrArr = (f64*)malloc((rows * cols) * sizeof(f64));

	if (!ptrArr == NULL) {
		for (int r = 0; r < rows; r++) {
			for (int c = 0; c < cols; c++) {
				ptrArr[r * cols + c] = 0;
			}
		}

		return ptrArr;
	}
	else {
		LMM_EXCEPTION("ERROR::LMM:: Wasn't able to construct matrix pointer");
	}
}

LMM_FUNC_DECL f32* ones_f(uint32 rows, uint32 cols) {
	f32* ptrArr = (f32*)malloc((rows * cols) * sizeof(f32));

	if (!ptrArr == NULL) {
		for (int r = 0; r < rows; r++) {
			for (int c = 0; c < cols; c++) {
				ptrArr[r * cols + c] = 1;
			}
		}

		return ptrArr;
	}
	else {
		LMM_EXCEPTION("ERROR::LMM:: Dynamic array error.");
	}
}

LMM_FUNC_DECL f64* ones_d(uint32 rows, uint32 cols) {
	f64* ptrArr = (f64*)malloc((rows * cols) * sizeof(f64));

	if (!ptrArr == NULL) {
		for (int r = 0; r < rows; r++) {
			for (int c = 0; c < cols; c++) {
				ptrArr[r * cols + c] = 1;
			}
		}

		return ptrArr;
	}
	else {
		LMM_EXCEPTION("ERROR::LMM:: Dynamic array error.");
	}
}

LMM_FUNC_DECL f32* fill_f(uint32 rows, uint32 cols, f32 num) {
	f32* ptrArr = (f32*)malloc((rows * cols) * sizeof(f32));

	if (!ptrArr == NULL) {
		for (int r = 0; r < rows; r++) {
			for (int c = 0; c < cols; c++) {
				ptrArr[r * cols + c] = num;
			}
		}

		return ptrArr;
	}
	else {
		LMM_EXCEPTION("ERROR::LMM:: Dynamic array error.");
	}
}

LMM_FUNC_DECL f64* fill_d(uint32 rows, uint32 cols, f64 num) {
	f64* ptrArr = (f64*)malloc((rows * cols) * sizeof(f64));

	if (!ptrArr == NULL) {
		for (int r = 0; r < rows; r++) {
			for (int c = 0; c < cols; c++) {
				ptrArr[r * cols + c] = num;
			}
		}

		return ptrArr;
	}
	else {
		LMM_EXCEPTION("ERROR::LMM:: Dynamic array error.");
	}
}

LMM_FUNC_DECL f32* identity_f(uint32 rows, uint32 cols) {
	if (rows == cols) {
		f32* ptrArr = (f32*)malloc((rows * cols) * sizeof(f32));

		if (!(ptrArr == NULL)) {
			for (int r = 0; r < rows; r++) {
				for (int c = 0; c < cols; c++) {
					if (r == c)
						ptrArr[r * cols + c] = 1;
					else
						ptrArr[r * cols + c] = 0;
				}
			}

			return ptrArr;
		}
		else {
			LMM_EXCEPTION("ERROR::LMM:: Dynamic array error.");
		}
	}
	else {
		LMM_EXCEPTION("ERROR::LMM:: ID dynamic array needs to be square.")
	}
}

LMM_FUNC_DECL f64* identity_d(uint32 rows, uint32 cols) {
	if (rows == cols) {
		f64* ptrArr = (f64*)malloc((rows * cols) * sizeof(f64));

		if (!(ptrArr == NULL)) {
			for (int r = 0; r < rows; r++) {
				for (int c = 0; c < cols; c++) {
					if (r == c)
						ptrArr[r * cols + c] = 1;
					else
						ptrArr[r * cols + c] = 0;
				}
			}

			return ptrArr;
		}
		else {
			LMM_EXCEPTION("ERROR::LMM:: Dynamic array error.");
		}
	}
	else {
		LMM_EXCEPTION("ERROR::LMM:: ID dynamic array needs to be square.")
	}
}
