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

#ifndef __LGE_LOGGER__
#define __LGE_LOGGER__

#include <memory>

#include "engine_setup.h"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/fmt/ostr.h>

_LGE_BEGIN_NP_LGE

class LGE_API Log {
private:
	static std::shared_ptr<spdlog::logger> coreLogger;
	static std::shared_ptr<spdlog::logger> clientLogger;

public:
	static void init();

	static inline std::shared_ptr<spdlog::logger>& getCoreLogger() { return coreLogger; }
	static inline std::shared_ptr<spdlog::logger>& getClientLogger() { return clientLogger; }
};

_LGE_END_NP_LGE



#endif