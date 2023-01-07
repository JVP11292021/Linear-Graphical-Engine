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

#ifndef __LGE_HID__
#define __LGE_HID__

#include "engine_setup.h"
#include "lgeLogging.hpp"

#include "lgeCodes.h"

#ifdef LGE_LISTENERS_GLFW
#	include "lgeEvents.h"
#	include "lgeMouseEvent.h"
#	include "lgeKeyEvent.h"
#	include "lgeApplicationEvent.h"
#	include "lgeInput.hpp"
#	include "lgeWindowsListener.hpp"
#elif defined(LGE_LISTENERS_CMD)
#	include "lgeCmdListeners.h"
#endif

#endif