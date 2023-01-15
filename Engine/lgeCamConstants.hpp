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

#ifndef __LGE_CAMERA_CONSTANTS__
#define __LGE_CAMERA_CONSTANTS__

#include "engine_setup.h"

_LGE_BEGIN_NP_LGE_GFX

// Default Camera values
LGE_API enum CAMERA_CONSTANTS {
	YAW = -90,
	PITCH = 0,
	SPEED = 3,
	SENSITIVITY = 1,
	FOV = 45,
};

_LGE_END_NP_LGE_GFX

#endif