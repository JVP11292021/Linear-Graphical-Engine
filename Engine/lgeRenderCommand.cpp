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

#include "lgeRenderCommand.hpp" 
#include "GL_API.h"

_LGE_BEGIN_NP_LGE_GFX

RenderAPI* RenderCommand::R_API = new GlRenderAPI();

_LGE_END_NP_LGE_GFX