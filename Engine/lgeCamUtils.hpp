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

#ifndef __LGE_CAMERA_UTILS__
#define __LGE_CAMERA_UTILS__

#include "engine_setup.h"

_LGE_BEGIN_NP_LGE_GFX

LGE_API typedef enum CamMovement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
}
Camera_Movement;

_LGE_END_NP_LGE_GFX

#endif