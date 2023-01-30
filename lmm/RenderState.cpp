#pragma once

#include "RenderState.hpp"

uint32 RenderState::api = LMM_STATE_GL;


LMM_FUNC_DECL bool RenderState::isEqual(uint32 state) {
	if (RenderState::api == state)
		return true;
	return false;
}

LMM_FUNC_DECL void RenderState::changeState(uint32 state) {
	switch (state) {
		case LMM_STATE_GL: 
			RenderState::api = LMM_STATE_GL;
			break;
		case LMM_STATE_DX: 
			RenderState::api = LMM_STATE_DX;
			break;
		case LMM_STATE_VK: 
			RenderState::api = LMM_STATE_VK;
			break;
		default: RenderState::api = LMM_STATE_NA;
	}
}