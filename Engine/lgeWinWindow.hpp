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

#ifndef __LGE_WIN_WINDOW__
#define __LGE_WIN_WINDOW__

#include "engine_setup.h"
#include "lgeWindow.hpp"
#include "lgeContext.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

_LGE_BEGIN_NP_LGE

class LGE_API WinWindow : public IWindow {
private:
	GLFWwindow* window;
	gfx::IContext* context;

	typedef struct {
		std::string title;
		uint32 width, height;
		int8 VSync;

		EventCallbackFn eventCallback;
	}
	wData;

	wData data;

	LGE_CUDA_FUNC_DECL void init(const WindowProps& props);
	LGE_CUDA_FUNC_DECL void shutdown();

	LGE_CUDA_FUNC_DECL void onUpdate() override;

public:
	WinWindow(const WindowProps& props);
	virtual ~WinWindow();

	LGE_CUDA_FUNC_DECL LGE_INLINE uint32 getWidth() const override { return this->data.width; }
	LGE_CUDA_FUNC_DECL LGE_INLINE uint32 getHeight() const override  { return this->data.height; }
	LGE_CUDA_FUNC_DECL LGE_INLINE void* getNative() const override { return this->window; }


	LGE_CUDA_FUNC_DECL void setEventCallback(const EventCallbackFn& callback) override { this->data.eventCallback = callback; }
	LGE_CUDA_FUNC_DECL void setVSync(int8 enabled) override;
	LGE_CUDA_FUNC_DECL int8 isVSync() const override;

};

_LGE_END_NP_LGE

#endif