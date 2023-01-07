//		*****************************************************************************************
//		* This source code is from the Github repo: Linear Graphical Engine (LGE)				*
//		*	Created by: JVP11292021 (J. van Polanen)											*
//		*	Started on: 06-01-2023																*
//		*																						*
//		* Copyright (c) Jessy van Polanen														*
//		*																						*
//		* NOTICE:																				*
//		*	This notice must remain at the top of each file, any alterations to this notice		*
//		*	strictly breaks the license the user aggreed upon when using this software.			*
//		*****************************************************************************************

#ifndef __LGE_SHADER_INTERFACE__
#define __LGE_SHADER_INTERFACE__

#include "engine_setup.h"
#include <../lmm/lmm.h>

_LGE_BEGIN_NP_LGE_GFX

class LGE_API Shader {
protected:
    uint32 ID;

public:
    virtual ~Shader() {}

    LGE_CUDA_FUNC_DECL virtual void bind() const = 0;
    LGE_CUDA_FUNC_DECL virtual void unbind() const = 0;

    LGE_CUDA_FUNC_DECL LGE_STATIC Shader* create(std::string&);
    LGE_CUDA_FUNC_DECL LGE_STATIC Shader* create(istr, istr, istr = nullptr);

	LGE_CUDA_FUNC_DECL virtual void setBool(const std::string&, bool) = 0;
	LGE_CUDA_FUNC_DECL virtual void setInt(const std::string&, int32) = 0;
	LGE_CUDA_FUNC_DECL virtual void setFloat(const std::string&, f32) = 0;
	LGE_CUDA_FUNC_DECL virtual void setVec2(const std::string&, const lmm::vec2&) = 0;
	LGE_CUDA_FUNC_DECL virtual void setVec2(const std::string&, f32 x, f32 y) = 0;
	LGE_CUDA_FUNC_DECL virtual void setVec3(const std::string&, const lmm::vec3&) = 0;
	LGE_CUDA_FUNC_DECL virtual void setVec3(const std::string&, f32 x, f32 y, f32 z) = 0;
	LGE_CUDA_FUNC_DECL virtual void setVec4(const std::string&, const lmm::vec4&) = 0;
	LGE_CUDA_FUNC_DECL virtual void setVec4(const std::string&, f32 x, f32 y, f32 z, f32 w) = 0;
	LGE_CUDA_FUNC_DECL virtual void setMat2(const std::string&, const lmm::mat2f&) = 0;
	LGE_CUDA_FUNC_DECL virtual void setMat3(const std::string&, const lmm::mat3f&) = 0;
	LGE_CUDA_FUNC_DECL virtual void setMat4(const std::string&, const lmm::mat4f&) = 0;
};

_LGE_END_NP_LGE_GFX

#endif
