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

#ifndef __LGE_IMGUI_ABSTRACTION__
#define __LGE_IMGUI_ABSTRACTION__

#include "engine_setup.h"
#include "lgeLayer.hpp"
#include "lgeHID.h"

_LGE_BEGIN_NP_LGE

class LGE_API ImGuiLayer : public ILayer {
private:
	f32 time;

public:
	ImGuiLayer();
	~ImGuiLayer();

	LGE_CUDA_FUNC_DECL void onAttach() override;
	LGE_CUDA_FUNC_DECL void onDetach() override;
	LGE_CUDA_FUNC_DECL void onImGuiRender() override;

	LGE_CUDA_FUNC_DECL void begin();
	LGE_CUDA_FUNC_DECL void end();
	//LGE_CUDA_FUNC_DECL void onEvent(hid::Event&) override;
};

_LGE_END_NP_LGE

#endif