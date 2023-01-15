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

#ifndef __LGE_ORTHO_CAM__
#define __LGE_ORTHO_CAM__

#include "engine_setup.h"
#include <../lmm/lmm.h>

_LGE_BEGIN_NP_LGE_GFX

class LGE_API OrthoCam {
private:
	LGE_CUDA_FUNC_DECL void updateCameraMatrices();

private:
	lmm::mat4 projection;
	lmm::mat4 view;
	lmm::mat4 viewProjection;

	lmm::vec3 pos;
	float rotation;

public:
	OrthoCam(f32, f32, f32, f32);

	LGE_CUDA_FUNC_DECL LGE_INLINE const lmm::mat4& getViewProjection() { return this->viewProjection; }
	LGE_CUDA_FUNC_DECL LGE_INLINE const lmm::mat4& getView() { return this->view; }
	LGE_CUDA_FUNC_DECL LGE_INLINE const lmm::mat4& getProjection() { return this->projection; }

	LGE_CUDA_FUNC_DECL LGE_INLINE lmm::vec3 getPos() const { return this->pos; }
	LGE_CUDA_FUNC_DECL LGE_INLINE f32 getRotation() const { return this->rotation; }

	LGE_CUDA_FUNC_DECL LGE_INLINE void setPos(const lmm::vec3& pos) { this->pos = pos; }
	LGE_CUDA_FUNC_DECL LGE_INLINE void setRotation(f32 rotation) { this->rotation = rotation; }

};

_LGE_END_NP_LGE_GFX

#endif