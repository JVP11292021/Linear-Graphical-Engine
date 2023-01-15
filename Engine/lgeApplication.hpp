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

#ifndef __LGE_APPLICATION__
#define __LGE_APPLICATION__

#include <glad/glad.h>

#include "engine_setup.h"

#include "lgeWindow.hpp"
#include "lgeLayer.hpp"
#include "lgeLayerStack.hpp"
#include "lgeImGuiLayer.hpp"
#include "lgeHID.h"

#include "lgeGFX.h"

_LGE_BEGIN_NP_LGE

class LGE_API Application {
private:
	LGE_CUDA_FUNC_DECL int8 onWindowClose(hid::WindowCloseEvent e);
	
	IWindow* win;
	ImGuiLayer* imguiLayer; 
	int8 running = LGE_TRUE;
	LayerStack layerStack;

	LGE_STATIC Application* instance;

	gfx::VertexArray* VAO;
	gfx::VertexBuffer* VBO;
	gfx::IndexBuffer* IBO;
	gfx::Shader* shader;

public:
	Application();
	virtual ~Application();

	LGE_CUDA_FUNC_DECL void run();

	LGE_CUDA_FUNC_DECL void onEvent(hid::Event& e);

	LGE_CUDA_FUNC_DECL void push_layer(ILayer*);
	LGE_CUDA_FUNC_DECL void push_overlay(ILayer*);

	LGE_CUDA_FUNC_DECL LGE_INLINE IWindow& getWindow() { return *this->win; }
	LGE_CUDA_FUNC_DECL LGE_STATIC LGE_INLINE Application& get() { return *instance; }

};

LGE_CUDA_FUNC_DECL Application* createApplication();

_LGE_END_NP_LGE

#endif