#pragma once

#include "lmm_defs.h"
#include "types.h"

#define LMM_STATE_GL		0x0001
#define LMM_STATE_DX		0x0002
#define LMM_STATE_VK		0x0003
#define LMM_STATE_NA		0x0004

enum class _API {
	NONE = -1,
	GL = 1,
	DX = 2,
	VK = 3
};

class RenderState {
public:
	static uint32 api;

	LMM_FUNC_DECL static void changeState(uint32);
	LMM_FUNC_DECL static bool isEqual(uint32);
	LMM_FUNC_DECL static LMM_INLINE uint32 getApi() { return RenderState::api; }
};
