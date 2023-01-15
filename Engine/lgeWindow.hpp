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

#ifndef __LGE_WINDOW__
#define __LGE_WINDOW__

#include "engine_setup.h"
#include "lgeHID.h"

#include <string>
#include <functional>

_LGE_BEGIN_NP_LGE

struct LGE_API WindowProps {
	std::string title;
	uint32 width;
	uint32 height;

	WindowProps(const std::string& title = "Linear Graphical Engine", uint32 width = 1280, uint32 height = 720)
		: title(title), width(width), height(height)
	{}

};

class LGE_API IWindow {
public:
	using EventCallbackFn = std::function<void(hid::Event&)>;

	virtual ~IWindow() {}

	LGE_CUDA_FUNC_DECL virtual void onUpdate() = 0;

	LGE_CUDA_FUNC_DECL virtual uint32 getWidth() const = 0;
	LGE_CUDA_FUNC_DECL virtual uint32 getHeight() const = 0;

	LGE_CUDA_FUNC_DECL virtual void setEventCallback(const EventCallbackFn& callback) = 0;
	LGE_CUDA_FUNC_DECL virtual void setVSync(int8 enabled) = 0;
	LGE_CUDA_FUNC_DECL virtual int8 isVSync() const = 0;

	LGE_CUDA_FUNC_DECL virtual void* getNative() const = 0;

	/// <summary>
	/// This function will be implemented in each platform specific file
	/// </summary>
	/// <param name="prop"></param>
	/// <returns>IWindow*</returns>
	LGE_CUDA_FUNC_DECL LGE_STATIC IWindow* create(const WindowProps& props = WindowProps());

};

_LGE_END_NP_LGE

#endif