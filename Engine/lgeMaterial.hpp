/*
 ________________________________________________________________________________________
| This source code is from the Github repo: Linear Graphical Engine (LGE)                |
|  Created by: JVP11292021 (J. van Polanen)                                              |
|  Started on: 06-01-2023                                                                |
|                                                                                        |
| Copyright (c) Jessy van Polanen                                                        |
|                                                                                        |
| NOTICE:                                                                                |
|   This notice must remain at the top of each file.                                     |
|________________________________________________________________________________________|
*/


#include "engine_setup.h"
#include "lgeShader.hpp"

#include <../lmm/lmm.h>

_LGE_BEGIN_NP_LGE_GFX

class LGE_API Material {
private:
	Shader* shader;

public:
	Material(Shader*);
	Material(const Material&);

	LGE_CUDA_FUNC_DECL Material operator = (const Material&);

	LGE_CUDA_FUNC_DECL LGE_INLINE void setShader(Shader* shader) { this->shader = shader; }
	LGE_CUDA_FUNC_DECL LGE_INLINE Shader* getShader() const { return this->shader; }
};

class LGE_API MaterialInstance {
private:
	Material* mat;

public:
	MaterialInstance(Material*);
	MaterialInstance(const MaterialInstance&);

	template <typename T>
	LGE_CUDA_FUNC_DECL LGE_INLINE 
		int8 set(const std::string& uniform, T& data) {
		switch (T) {
			case typeid(T) == int32: this->mat->getShader()->setInt(uniform, data); return 1;
			case typeid(T) == f32: this->mat->getShader()->setFloat(uniform, data); return 1;
			case typeid(T) == lmm::vec2: this->mat->getShader()->setVec2(uniform, data); return 1;
			case typeid(T) == lmm::vec3: this->mat->getShader()->setVec3(uniform, data); return 1;
			case typeid(T) == lmm::vec4: this->mat->getShader()->setVec4(uniform, data); return 1;
			case typeid(T) == lmm::mat2: this->mat->getShader()->setMat2(uniform, data); return 1;
			case typeid(T) == lmm::mat3: this->mat->getShader()->setMat3(uniform, data); return 1;
			case typeid(T) == lmm::mat4: this->mat->getShader()->setMat4(uniform, data); return 1;
		}

		lgeASSERT(LGE_FALSE);
		return -1;
	}

	LGE_CUDA_FUNC_DECL LGE_INLINE void setMaterial(Material* material) { this->mat = material; }
	LGE_CUDA_FUNC_DECL LGE_INLINE Material* getMaterial() const { return this->mat; }

};

typedef Material* MaterialRef;
typedef MaterialInstance* MaterialInstanceRef;

_LGE_END_NP_LGE_GFX