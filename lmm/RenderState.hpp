#pragma once

#include "lmm_defs.h"
#include "types.h"

#define LMM_STATE_GL		0x0001
#define LMM_STATE_DX		0x0002
#define LMM_STATE_VK		0x0003

enum class _API {
	NONE = -1,
	GL = 1,
	DX = 2,
	VK = 3
};

class RenderState {
public:
	static _API api;

	LMM_FUNC_DECL static void changeState(int32);
};

const RenderState gState;