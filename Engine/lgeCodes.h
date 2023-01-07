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

#ifndef __LGE_CODES__
#define __LGE_CODES__

#include "engine_setup.h"

// Windows API event type flags
#define LGE_KEY_EVENT							0x0001							// Event contains key event record
#define LGE_MOUSE_EVENT							0x0002							// Event contains mouse event record
#define LGE_WINDOW_BUFFER_SIZE_EVENT			0x0004							// Event contains window change event record
#define LGE_MENU_EVENT							0x0008							// Event contains menu event record
#define LGE_FOCUS_EVENT							0x0010							// event contains focus change

// Mouse states
#define LGE_MOUSE_NO_SPECIAL_STATE				0x0000
#define LGE_MOUSE_MOVED							0x0001
#define LGE_MOUSE_WHEELED						0x0004
#define LGE_DOUBLE_CLICK						0x0002
#define LGE_MOUSE_HWHEELED						0x0008
#define LGE_MOUSE_RIGHTMOST_BTN_PRESSED			0x0002
#define LGE_MOUSE_LEFTMOST_BTN_PRESSED			0x0001

#define LGE_MOUSE_INIT_FAILURE					0x8A20
#define LGE_MOUSE_INIT_SUCCESS					0x0001

#define LGE_EVENT_BUFFER_SIZE					128

// ----------- MOUSE CODES ----------------

#define LGE_MOUSE_BUTTON_1         0
#define LGE_MOUSE_BUTTON_2         1
#define LGE_MOUSE_BUTTON_3         2
#define LGE_MOUSE_BUTTON_4         3
#define LGE_MOUSE_BUTTON_5         4
#define LGE_MOUSE_BUTTON_6         5
#define LGE_MOUSE_BUTTON_7         6
#define LGE_MOUSE_BUTTON_8         7
#define LGE_MOUSE_BUTTON_LAST      LGE_MOUSE_BUTTON_8
#define LGE_MOUSE_BUTTON_LEFT      LGE_MOUSE_BUTTON_1
#define LGE_MOUSE_BUTTON_RIGHT     LGE_MOUSE_BUTTON_2
#define LGE_MOUSE_BUTTON_MIDDLE    LGE_MOUSE_BUTTON_3

// ----------- KEY CODES -------------
#define LGE_KEY_SPACE							32
#define LGE_KEY_APOSTROPHE						39  /* ' */
#define LGE_KEY_COMMA							44  /* , */
#define LGE_KEY_MINUS							45  /* - */
#define LGE_KEY_PERIOD							46  /* . */
#define LGE_KEY_FRONT_SLASH						47  /* / */
#define LGE_KEY_0								48
#define LGE_KEY_1								49
#define LGE_KEY_2								50
#define LGE_KEY_3								51
#define LGE_KEY_4								52
#define LGE_KEY_5								53
#define LGE_KEY_6								54
#define LGE_KEY_7								55
#define LGE_KEY_8								56
#define LGE_KEY_9								57
#define LGE_KEY_SEMICOLON						59  /* ; */
#define LGE_KEY_EQUAL							61  /* = */
#define LGE_KEY_A								65
#define LGE_KEY_B								66
#define LGE_KEY_C								67
#define LGE_KEY_D								68
#define LGE_KEY_E								69
#define LGE_KEY_F								70
#define LGE_KEY_G								71
#define LGE_KEY_H								72
#define LGE_KEY_I								73
#define LGE_KEY_J								74
#define LGE_KEY_K								75
#define LGE_KEY_L								76
#define LGE_KEY_M								77
#define LGE_KEY_N								78
#define LGE_KEY_O								79
#define LGE_KEY_P								80
#define LGE_KEY_Q								81
#define LGE_KEY_R								82
#define LGE_KEY_S								83
#define LGE_KEY_T								84
#define LGE_KEY_U								85
#define LGE_KEY_V								86
#define LGE_KEY_W								87
#define LGE_KEY_X								88
#define LGE_KEY_Y								89
#define LGE_KEY_Z								90
#define LGE_KEY_LEFT_BRACKET					91  
#define LGE_KEY_BACKSLASH						92  
#define LGE_KEY_RIGHT_BRACKET					93  
#define LGE_KEY_GRAVE_ACCENT					96 
#define LGE_KEY_a								97
#define LGE_KEY_b								98
#define LGE_KEY_c								99
#define LGE_KEY_d								100
#define LGE_KEY_e								101
#define LGE_KEY_f								102
#define LGE_KEY_g								103
#define LGE_KEY_h								104
#define LGE_KEY_i								105
#define LGE_KEY_j								106
#define LGE_KEY_k								107
#define LGE_KEY_l								108
#define LGE_KEY_m								109
#define LGE_KEY_n								110
#define LGE_KEY_o								111
#define LGE_KEY_p								112
#define LGE_KEY_q								113
#define LGE_KEY_r								114
#define LGE_KEY_s								115
#define LGE_KEY_t								116
#define LGE_KEY_u								117
#define LGE_KEY_v								118
#define LGE_KEY_w								119
#define LGE_KEY_x								120
#define LGE_KEY_y								121
#define LGE_KEY_z								122
#define LGE_KEY_WORLD_1							161 
#define LGE_KEY_WORLD_2							162 

// special Function keys 
#define LGE_KEY_ESCAPE							256
#define LGE_KEY_ENTER							257
#define LGE_KEY_TAB								258
#define LGE_KEY_BACKSPACE						259
#define LGE_KEY_INSERT							260
#define LGE_KEY_DELETE							261
#define LGE_KEY_RIGHT							262
#define LGE_KEY_LEFT							263
#define LGE_KEY_DOWN							264
#define LGE_KEY_UP								265
#define LGE_KEY_PAGE_UP							266
#define LGE_KEY_PAGE_DOWN						267
#define LGE_KEY_HOME							268
#define LGE_KEY_END								269
#define LGE_KEY_CAPS_LOCK						280
#define LGE_KEY_SCROLL_LOCK						281
#define LGE_KEY_NUM_LOCK						282
#define LGE_KEY_PRINT_SCREEN					283
#define LGE_KEY_PAUSE							284
#define LGE_KEY_F1								290
#define LGE_KEY_F2								291
#define LGE_KEY_F3								292
#define LGE_KEY_F4								293
#define LGE_KEY_F5								294
#define LGE_KEY_F6								295
#define LGE_KEY_F7								296
#define LGE_KEY_F8								297
#define LGE_KEY_F9								298
#define LGE_KEY_F10								299
#define LGE_KEY_F11								300
#define LGE_KEY_F12								301
#define LGE_KEY_F13								302
#define LGE_KEY_F14								303
#define LGE_KEY_F15								304
#define LGE_KEY_F16								305
#define LGE_KEY_F17								306
#define LGE_KEY_F18								307
#define LGE_KEY_F19								308
#define LGE_KEY_F20								309
#define LGE_KEY_F21								310
#define LGE_KEY_F22								311
#define LGE_KEY_F23								312
#define LGE_KEY_F24								313
#define LGE_KEY_F25								314
#define LGE_KEY_KP_0							320
#define LGE_KEY_KP_1							321
#define LGE_KEY_KP_2							322
#define LGE_KEY_KP_3							323
#define LGE_KEY_KP_4							324
#define LGE_KEY_KP_5							325
#define LGE_KEY_KP_6							326
#define LGE_KEY_KP_7							327
#define LGE_KEY_KP_8							328
#define LGE_KEY_KP_9							329
#define LGE_KEY_KP_DECIMAL						330
#define LGE_KEY_KP_DIVIDE						331
#define LGE_KEY_KP_MULTIPLY						332
#define LGE_KEY_KP_SUBTRACT						333
#define LGE_KEY_KP_ADD							334
#define LGE_KEY_KP_ENTER						335
#define LGE_KEY_KP_EQUAL						336
#define LGE_KEY_LEFT_SHIFT						340
#define LGE_KEY_LEFT_CONTROL					341
#define LGE_KEY_LEFT_ALT						342
#define LGE_KEY_LEFT_SUPER						343
#define LGE_KEY_RIGHT_SHIFT						344
#define LGE_KEY_RIGHT_CONTROL					345
#define LGE_KEY_RIGHT_ALT						346
#define LGE_KEY_RIGHT_SUPER						347
#define LGE_KEY_MENU							348

_LGE_BEGIN_NP_LGE_HID

typedef void*						mHANDLE;
typedef unsigned short				mWORD;
typedef unsigned long				mDWORD;
typedef unsigned char				mBYTE;
typedef int							mBOOL;
typedef float						mFLOAT;
typedef double						mREAL;
typedef int							mINT;
typedef long long					mDINT;
typedef char*						mSTR;
typedef char						mCHAR;

/// <summary>
/// Simple structure containing x, y, z variables.
/// </summary>
template <typename T>
struct __POINT__ {
	union {
		T x;
		T w;
	};

	union {
		T y;
		T h;
	};

	union {
		T z;
		T d;
	};
};

typedef __POINT__<mFLOAT> pos;
typedef __POINT__<mINT> point;
typedef __POINT__<mDWORD> dim;

_LGE_END_NP_LGE_HID

#endif