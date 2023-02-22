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

#ifndef __LGE_INPUT__
#define __LGE_INPUT__

#include "engine_setup.h"
#include "lgeCodes.h"
#include "lgeCollections.h"

_LGE_BEGIN_NP_LGE_HID

class LGE_API Input {
protected:
	LGE_CUDA_FUNC_DECL virtual mBOOL isKeyPressedImpl(mINT) = 0;
	LGE_CUDA_FUNC_DECL virtual mBOOL isMouseButtonPressedImpl(mINT) = 0;
	LGE_CUDA_FUNC_DECL virtual mFLOAT getMouseXImpl() = 0;
	LGE_CUDA_FUNC_DECL virtual mFLOAT getMouseYImpl() = 0;
	LGE_CUDA_FUNC_DECL virtual core::Tuple<mFLOAT> getMousePosImpl() = 0;

private:
	LGE_STATIC Input* instance;

public:
	LGE_CUDA_FUNC_DECL LGE_INLINE LGE_STATIC mBOOL isKeyPressed(mINT keyCode) { return instance->isKeyPressedImpl(keyCode); }
	
	LGE_CUDA_FUNC_DECL LGE_INLINE LGE_STATIC mBOOL isMouseButtonPressed(mINT button) { return instance->isMouseButtonPressedImpl(button); }
	LGE_CUDA_FUNC_DECL LGE_INLINE LGE_STATIC mFLOAT getMouseX() { return instance->getMouseXImpl(); }
	LGE_CUDA_FUNC_DECL LGE_INLINE LGE_STATIC mFLOAT getMouseY() { return instance->getMouseYImpl(); }
	LGE_CUDA_FUNC_DECL LGE_INLINE LGE_STATIC core::Tuple<mFLOAT> getMousePos() { return instance->getMousePosImpl(); }
};

__declspec(selectany) mBOOL (*isMouseButtonPressed)(mINT) = &Input::isMouseButtonPressed;
__declspec(selectany) mBOOL (*isKeyPressed)(mINT) = &Input::isKeyPressed;
__declspec(selectany) mFLOAT(*mouseX)() = &Input::getMouseX;
__declspec(selectany) mFLOAT(*mouseY)() = &Input::getMouseY;
__declspec(selectany) core::Tuple<mFLOAT> (*mousePos)() = &Input::getMousePos;


_LGE_END_NP_LGE_HID

#endif