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

#ifndef __LGE_CMD_LISTENERS__
#define __LGE_CMD_LISTENERS__

#include "engine_setup.h"
#include "lgeCodes.h"

#include <conio.h>
#include <tchar.h>
#include <stdio.h>
#include <Windows.h>

_LGE_BEGIN_NP_LGE_HID

const mINT key_event = LGE_KEY_EVENT;						// Event contains key event record 
const mINT mouse_event = LGE_MOUSE_EVENT;					// Event contains mouse event record
const mINT menu_event = LGE_MENU_EVENT;						// Event contains window change event record
const mINT focus_event = LGE_FOCUS_EVENT;					// Event contains menu event record
const mINT wbs_event = WINDOW_BUFFER_SIZE_EVENT;			// event contains focus change

LGE_API typedef enum {
	mmove,		// Mouse move event
	mwheel,		// Mouse wheel event
	mhwheel,	// Mouse wheel horizontal event
	mdclick,	// Mouse double click event
	munknown,	// Mouse event unknwon
	mrmbtn,		// Mouse rightmost button pressed event
	ml1btn,		// Mouse left first button pressed
}
mStates;

LGE_CUDA_FUNC_DECL LGE_API mDWORD& current_mouse_state();
LGE_CUDA_FUNC_DECL LGE_API mDWORD& g_counter();
LGE_CUDA_FUNC_DECL LGE_API mDWORD& c_numRead();
LGE_CUDA_FUNC_DECL LGE_API INPUT_RECORD* get_event_buffer();

LGE_CUDA_FUNC_DECL LGE_API mINT m_init();
LGE_CUDA_FUNC_DECL LGE_API LGE_VOID m_destruct();
LGE_CUDA_FUNC_DECL LGE_API LGE_INLINE mINT errorExit(LPCSTR);
LGE_CUDA_FUNC_DECL LGE_API mBOOL keyEventProc(KEY_EVENT_RECORD);
LGE_CUDA_FUNC_DECL LGE_API mWORD mouseEventProc(MOUSE_EVENT_RECORD);
LGE_CUDA_FUNC_DECL LGE_API LGE_VOID resizeEventProc(WINDOW_BUFFER_SIZE_RECORD);

class LGE_API MouseListener {
private:
	point					p;
	MOUSE_EVENT_RECORD	mer;

public:
	MouseListener();
	MouseListener(point);
	MouseListener(point, MOUSE_EVENT_RECORD);

	LGE_CUDA_FUNC_DECL mWORD record(MOUSE_EVENT_RECORD);
	LGE_CUDA_FUNC_DECL mWORD record();

	LGE_CUDA_FUNC_DECL mBOOL mouseWheeled();
	LGE_CUDA_FUNC_DECL mBOOL mouseHWheeled();
	LGE_CUDA_FUNC_DECL mBOOL mouseMoved();

	LGE_CUDA_FUNC_DECL mINT getX();
	LGE_CUDA_FUNC_DECL mINT getY();
};

class LGE_API KeyListener {
private:
	mCHAR				key;
	mWORD				ascii;
	mBOOL				isPressed;
	KEY_EVENT_RECORD	ker;

public:
	KeyListener();
	KeyListener(KEY_EVENT_RECORD);

	LGE_CUDA_FUNC_DECL mBOOL record();
	LGE_CUDA_FUNC_DECL mBOOL record(KEY_EVENT_RECORD);

	LGE_CUDA_FUNC_DECL mBOOL isKeyPressed(mCHAR);

	LGE_CUDA_FUNC_DECL mCHAR getKey();
	LGE_CUDA_FUNC_DECL mWORD getAscii();
	LGE_CUDA_FUNC_DECL mBOOL is_pressed();

};

_LGE_END_NP_LGE_HID

#endif