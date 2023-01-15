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

#include "lgeCmdListeners.h"

#include "lgeCodes.h"
#include "lgeExceptions.hpp"

_LGE_BEGIN_NP_LGE_HID

// ------------------- Global mouse variables --------------------
LGE_STATIC mDWORD				cms;										// Current mouse state variable
LGE_STATIC mINT					dX, dY;										// Global mouse coordinates

// ------------------- Global variables --------------------
LGE_STATIC mHANDLE				hStdin;										// Standard input handle
LGE_STATIC mDWORD				fwdSaveOldMode;								// Old standard input save
LGE_STATIC mDWORD				fwdMode;									// Flag for enabling certain event inputs
LGE_STATIC mDWORD				cNumRead;									// Number of records to be read
LGE_STATIC INPUT_RECORD			event_buffer[LGE_EVENT_BUFFER_SIZE];		// The buffer which holds all the events over a period of time
LGE_STATIC mDWORD				gCounter;									// Global event loop counter variable

LGE_CUDA_FUNC_DECL LGE_API INPUT_RECORD* get_event_buffer() {
	return event_buffer;
}

LGE_CUDA_FUNC_DECL LGE_API mDWORD& current_mouse_state() {
	return cms;
}

LGE_CUDA_FUNC_DECL LGE_API mDWORD& g_counter() {
	return gCounter;
}

LGE_CUDA_FUNC_DECL LGE_API mDWORD& c_numRead() {
	return cNumRead;
}

LGE_CUDA_FUNC_DECL LGE_API mINT m_init() {
	gCounter = 0;
	dX = 0;
	dY = 0;

	mINT success;
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	if (hStdin == INVALID_HANDLE_VALUE)
		success = errorExit("Standard handle faulure\n");

	if (!GetConsoleMode(hStdin, &fwdSaveOldMode))
		success = errorExit("Wasn't able to save old input state!\n");

	lge::hid::fwdMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | ENABLE_INSERT_MODE | ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(hStdin, fwdMode))
		success = errorExit("Wasn't able to set the console!\n");

	success = LGE_MOUSE_INIT_SUCCESS;
	return success;
}

LGE_CUDA_FUNC_DECL LGE_INLINE LGE_API mINT errorExit(LPCSTR msg) {
	fprintf(stderr, "%s\n", msg);
	SetConsoleMode(hStdin, fwdSaveOldMode);
	ExitProcess(0);
	return LGE_MOUSE_INIT_FAILURE;
}

LGE_CUDA_FUNC_DECL LGE_API LGE_VOID m_destruct() {
	SetConsoleMode(hStdin, fwdSaveOldMode);
	cms = NULL;
	hStdin = NULL;
	fwdSaveOldMode = NULL;
	fwdMode = NULL;
	cNumRead = NULL;
	gCounter = 0;
	dX = 0;
	dY = 0;
}

LGE_CUDA_FUNC_DECL LGE_API mBOOL keyEventProc(KEY_EVENT_RECORD ker) {
	if (ker.bKeyDown)
		return LGE_TRUE;
	return LGE_FALSE;
}

LGE_CUDA_FUNC_DECL LGE_API mWORD mouseEventProc(MOUSE_EVENT_RECORD mer) {
	dX = mer.dwMousePosition.X;
	dY = mer.dwMousePosition.Y;

	switch (mer.dwEventFlags) {
	case LGE_MOUSE_NO_SPECIAL_STATE:
		if (mer.dwButtonState == LGE_MOUSE_LEFTMOST_BTN_PRESSED) {
			cms = mStates::ml1btn;
			return 0x0006;
		}
		else if (mer.dwButtonState == LGE_MOUSE_RIGHTMOST_BTN_PRESSED) {
			cms = mStates::mrmbtn;
			return 0x0005;
		}
		break;
	case LGE_DOUBLE_CLICK:
		cms = mStates::mdclick;
		return 0x0003;
		break;
	case LGE_MOUSE_WHEELED:
		cms = mStates::mwheel;
		return 0x0001;
		break;
	case LGE_MOUSE_MOVED:
		cms = mStates::mmove;
		return 0x0000;
		break;
	case LGE_MOUSE_HWHEELED:
		cms = mStates::mhwheel;
		return 0x0002;
		break;
	default:
		cms = mStates::munknown;
		return 0x0004;
		break;
	}

	return LGE_FALSE;
}

LGE_CUDA_FUNC_DECL LGE_API LGE_VOID resizeEventProc(WINDOW_BUFFER_SIZE_RECORD wbsr) {
	printf("Screen buffer is %d columns by %d rows.\n", wbsr.dwSize.X, wbsr.dwSize.Y);
}


MouseListener::MouseListener()
#ifdef LGE_HAS_INITIALIZER_LIST
	: p({ 0, 0 }), mer({})
#endif
{
#ifndef LGE_HAS_INITIALIZER_LIST
	this->p = { 0, 0 };
	this->mer = {};
#endif

	if (!ReadConsoleInput(hStdin, event_buffer, LGE_EVENT_BUFFER_SIZE, &cNumRead))
		throw Exception(const_cast<char*>("LGE::Exception\nCannot read console input with MouseListener\n"));

}

MouseListener::MouseListener(point p)
#ifdef LGE_HAS_INITIALIZER_LIST
	: p(p), mer({})
#endif
{
#ifndef LGE_HAS_INITIALIZER_LIST
	this->p = p;
	this->mer = {};
#endif

	if (!ReadConsoleInput(hStdin, event_buffer, LGE_EVENT_BUFFER_SIZE, &cNumRead))
		throw Exception(const_cast<char*>("LGE::Exception\nCannot read console input with MouseListener\n"));
}

MouseListener::MouseListener(point p, MOUSE_EVENT_RECORD mer)
#ifdef LGE_HAS_INITIALIZER_LIST
	: p(p), mer(mer)
#endif
{
#ifndef LGE_HAS_INITIALIZER_LIST
	this->p = p;
	this->mer = mer;
#endif

	if (!ReadConsoleInput(hStdin, event_buffer, LGE_EVENT_BUFFER_SIZE, &cNumRead))
		throw Exception(const_cast<char*>("LGE::Exception\nCannot read console input with MouseListener\n"));
}

LGE_CUDA_FUNC_DECL mWORD MouseListener::record(MOUSE_EVENT_RECORD mer) {
	this->mer = mer;
	this->p = { this->mer.dwMousePosition.X, this->mer.dwMousePosition.Y };
	return mouseEventProc(this->mer);
}

LGE_CUDA_FUNC_DECL mWORD MouseListener::record() {
	this->p = { this->mer.dwMousePosition.X, this->mer.dwMousePosition.Y };
	return mouseEventProc(this->mer);
}

LGE_CUDA_FUNC_DECL mBOOL MouseListener::mouseWheeled() {
	if (cms == mStates::mwheel)
		return LGE_TRUE;
	return LGE_FALSE;
}

LGE_CUDA_FUNC_DECL mBOOL MouseListener::mouseHWheeled() {
	if (cms == mStates::mhwheel)
		return LGE_TRUE;
	return LGE_FALSE;
}

LGE_CUDA_FUNC_DECL mBOOL MouseListener::mouseMoved() {
	if (cms == mStates::mmove) {
		this->p = { this->mer.dwMousePosition.X, this->mer.dwMousePosition.Y };
		return LGE_TRUE;
	}
	return LGE_FALSE;
}

LGE_CUDA_FUNC_DECL mINT MouseListener::getX() {
	return this->p.x;
}
LGE_CUDA_FUNC_DECL mINT MouseListener::getY() {
	return this->p.y;
}


KeyListener::KeyListener()
#ifdef LGE_HAS_INITIALIZER_LIST
	: key(0), ascii(0), isPressed(LGE_FALSE), ker({})
#endif
{
#ifndef LGE_HAS_INITIALIZER_LIST
	this->key = 0;
	this->ascii = 0;
	this->isPressed = LGE_FALSE;
	this->ker = {};
#endif

}

KeyListener::KeyListener(KEY_EVENT_RECORD ker)
#ifdef LGE_HAS_INITIALIZER_LIST
	: key(0), ascii(0), isPressed(LGE_FALSE), ker(ker)
#endif
{
#ifndef LGE_HAS_INITIALIZER_LIST
	this->key = 0;
	this->ascii = 0;
	this->isPressed = LGE_FALSE;
	this->ker = ker;
#endif
}

LGE_CUDA_FUNC_DECL mBOOL KeyListener::record() {
	this->key = this->ker.uChar.AsciiChar;
	this->ascii = mINT(this->key);
	this->isPressed = LGE_TRUE;
	return keyEventProc(this->ker);
}

LGE_CUDA_FUNC_DECL mBOOL KeyListener::record(KEY_EVENT_RECORD ker) {
	this->ker = ker;
	this->key = this->ker.uChar.AsciiChar;
	this->ascii = mINT(this->key);
	this->isPressed = LGE_TRUE;
	return keyEventProc(this->ker);
}

LGE_CUDA_FUNC_DECL mBOOL KeyListener::isKeyPressed(mCHAR ascii_code) {
	if (this->ascii == ascii_code)
		return LGE_TRUE;
	return LGE_FALSE;
}

LGE_CUDA_FUNC_DECL mCHAR KeyListener::getKey() {
	return this->key;
}

LGE_CUDA_FUNC_DECL mWORD KeyListener::getAscii() {
	return this->ascii;
}

LGE_CUDA_FUNC_DECL mBOOL KeyListener::is_pressed() {
	return this->isPressed;
}


_LGE_END_NP_LGE_HID