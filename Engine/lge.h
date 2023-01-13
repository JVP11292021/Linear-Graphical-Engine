/*
_________________________________________________________________________________________
| This source code is from the Github repo: Linear Graphical Engine (LGE)               |
|	Created by: JVP11292021 (J. van Polanen)                                            |
|	Started on: 06-01-2023                                                              |
|                                                                                       |
| Copyright (c) Jessy van Polanen                                                       |
|                                                                                       |
| NOTICE:                                                                               |
|	This notice must remain at the top of each file, any alterations to this notice     |
|	strictly breaks the license the user aggreed upon when using this software.         |
*****************************************************************************************
*/

/*  ------------- IMPORTANT! -------------
	This file is for use of LGE client applications only!
*/

#ifndef __LGE__
#define __LGE__

#include <../lmm/lmm.h>
namespace lmm { 
#include <../lmm/lmm_math.h> 
}

#include <imgui.h>

#include "engine_setup.h"
#include "lgeEntryPoint.h"

#include "lgeCollections.h"
#include "lgeApplication.hpp"

#include "lgeHID.h"
#include "lgeGFX.h"

#include "lgeManager.hpp"
#include "lgeRenderManager.hpp"
#include "lgeAnimationManager.hpp"
#include "lgeFileSystemManager.hpp"
#include "lgeMemoryManager.hpp"
#include "lgePhysicsManager.hpp"
#include "lgeTextureManager.hpp"
#include "lgeVideoManager.hpp"

#include "lgeLogging.hpp"
#include "lgeSmartPtr.hpp"
#include "lgeUniquePtr.hpp"
#include "lgeAllocaters.hpp"
#include "lgePtrMath.inl"
#include "lgeExceptions.hpp"
#include "lgeClock.hpp"
#include "lge_fsys.hpp" 
#include "lgeSingleton.hpp"

#include "lgeWindow.hpp"
#include "lgeWinWindow.hpp"

#include "lgeLayer.hpp"
#include "lgeLayerStack.hpp"
#include "lgeImGuiLayer.hpp"

#endif