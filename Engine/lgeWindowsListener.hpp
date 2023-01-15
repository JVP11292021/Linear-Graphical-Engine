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

#ifndef __LGE_WINDOWS_LISTENER__
#define __LGE_WINDOWS_LISTENER__

#include "engine_setup.h"
#include "lgeInput.hpp"

_LGE_BEGIN_NP_LGE_HID

class LGE_API WinListener : public Input {
public:
	LGE_CUDA_FUNC_DECL mBOOL isKeyPressedImpl(mINT) override;

	LGE_CUDA_FUNC_DECL mBOOL isMouseButtonPressedImpl(mINT) override;
	LGE_CUDA_FUNC_DECL mFLOAT getMouseXImpl() override;
	LGE_CUDA_FUNC_DECL mFLOAT getMouseYImpl() override;
	LGE_CUDA_FUNC_DECL core::Tuple<mFLOAT> getMousePosImpl() override;

};

_LGE_END_NP_LGE_HID

#endif