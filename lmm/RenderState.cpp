#pragma once

#include "RenderState.hpp"

_API RenderState::api = _API::GL;

LMM_FUNC_DECL void RenderState::changeState(int32 state) {
	switch (state) {
		case 1: 
			RenderState::api = _API::GL; 
			break;
		case 2: 
			RenderState::api = _API::DX;
			break;
		case 3: 
			RenderState::api = _API::VK; 
			break;
		default: RenderState::api = _API::NONE;
	}
}
