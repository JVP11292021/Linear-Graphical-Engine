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

#ifndef __LGE_ENTRY_POINT__
#define __LGE_ENTRY_POINT__

#include "engine_setup.h"
#include "lgeApplication.hpp"
#include "lgeCollections.h"

#if LGE_PLATFORM == LGE_PLATFORM_WINDOWS

extern lge::Application* lge::createApplication();

int main(int argc, char** argv) {
	LGE_AUTO app = lge::createApplication();
	app->run();
	delete app;

	return 1;
}

#endif

#endif 