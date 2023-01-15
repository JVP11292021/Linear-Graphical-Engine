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

#include "lgeLogging.hpp"

_LGE_BEGIN_NP_LGE

std::shared_ptr<spdlog::logger> Log::coreLogger;
std::shared_ptr<spdlog::logger> Log::clientLogger;

void Log::init() {
	spdlog::set_pattern("%^[%T] %n: %v%$"); // Color, timestamp, name, log message

	coreLogger = spdlog::stdout_color_mt("LGE");
	coreLogger->set_level(spdlog::level::trace);

	clientLogger = spdlog::stdout_color_mt("APP");
	clientLogger->set_level(spdlog::level::trace);

}

_LGE_END_NP_LGE