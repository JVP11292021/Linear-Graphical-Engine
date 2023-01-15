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

#ifndef __LGE_LISTENER_XINPUT__
#define __LGE_LISTENER_XINPUT__

#include "engine_setup.h"

_LGE_BEGIN_NP_LGE_HID
// Built-in microsoft XBOX conf (OneCore)
#include <Xinput.h>
_LGE_END_NP_LGE_HID

// -------------- These constants have been borrowed from Xinput.h for user convenience ---------------
// constants for XBOX
#define LGE_XINPUT_GAMEPAD_DPAD_UP				XINPUT_GAMEPAD_DPAD_UP       
#define LGE_XINPUT_GAMEPAD_DPAD_DOWN			XINPUT_GAMEPAD_DPAD_DOWN     
#define LGE_XINPUT_GAMEPAD_DPAD_LEFT			XINPUT_GAMEPAD_DPAD_LEFT     
#define LGE_XINPUT_GAMEPAD_DPAD_RIGHT			XINPUT_GAMEPAD_DPAD_RIGHT    
#define LGE_XINPUT_GAMEPAD_START				XINPUT_GAMEPAD_START         
#define LGE_XINPUT_GAMEPAD_BACK					XINPUT_GAMEPAD_BACK          
#define LGE_XINPUT_GAMEPAD_LEFT_THUMB			XINPUT_GAMEPAD_LEFT_THUMB    
#define LGE_XINPUT_GAMEPAD_RIGHT_THUMB			XINPUT_GAMEPAD_RIGHT_THUMB   
#define LGE_XINPUT_GAMEPAD_LEFT_SHOULDER		XINPUT_GAMEPAD_LEFT_SHOULDER 
#define LGE_XINPUT_GAMEPAD_RIGHT_SHOULDER		XINPUT_GAMEPAD_RIGHT_SHOULDER
#define LGE_XINPUT_GAMEPAD_A					XINPUT_GAMEPAD_A             
#define LGE_XINPUT_GAMEPAD_B					XINPUT_GAMEPAD_B             
#define LGE_XINPUT_GAMEPAD_X					XINPUT_GAMEPAD_X             
#define LGE_XINPUT_GAMEPAD_Y					XINPUT_GAMEPAD_Y             

// Codes for the gamepad keystroke
#define LGE_VK_PAD_A							VK_PAD_A                
#define LGE_VK_PAD_B							VK_PAD_B                
#define LGE_VK_PAD_X							VK_PAD_X                
#define LGE_VK_PAD_Y							VK_PAD_Y                
#define LGE_VK_PAD_RSHOULDER					VK_PAD_RSHOULDER        
#define LGE_VK_PAD_LSHOULDER					VK_PAD_LSHOULDER        
#define LGE_VK_PAD_LTRIGGER						VK_PAD_LTRIGGER         
#define LGE_VK_PAD_RTRIGGER						VK_PAD_RTRIGGER         

#define LGE_VK_PAD_DPAD_UP						VK_PAD_DPAD_UP          
#define LGE_VK_PAD_DPAD_DOWN					VK_PAD_DPAD_DOWN        
#define LGE_VK_PAD_DPAD_LEFT					VK_PAD_DPAD_LEFT        
#define LGE_VK_PAD_DPAD_RIGHT					VK_PAD_DPAD_RIGHT       
#define LGE_VK_PAD_START						VK_PAD_START            
#define LGE_VK_PAD_BACK							VK_PAD_BACK             
#define LGE_VK_PAD_LTHUMB_PRESS					VK_PAD_LTHUMB_PRESS     
#define LGE_VK_PAD_RTHUMB_PRESS					VK_PAD_RTHUMB_PRESS     

#define LGE_VK_PAD_LTHUMB_UP					VK_PAD_LTHUMB_UP        
#define LGE_VK_PAD_LTHUMB_DOWN					VK_PAD_LTHUMB_DOWN      
#define LGE_VK_PAD_LTHUMB_RIGHT					VK_PAD_LTHUMB_RIGHT     
#define LGE_VK_PAD_LTHUMB_LEFT					VK_PAD_LTHUMB_LEFT      
#define LGE_VK_PAD_LTHUMB_UPLEFT				VK_PAD_LTHUMB_UPLEFT    
#define LGE_VK_PAD_LTHUMB_UPRIGHT				VK_PAD_LTHUMB_UPRIGHT   
#define LGE_VK_PAD_LTHUMB_DOWNRIGHT				VK_PAD_LTHUMB_DOWNRIGHT 
#define LGE_VK_PAD_LTHUMB_DOWNLEFT				VK_PAD_LTHUMB_DOWNLEFT  

#define LGE_VK_PAD_RTHUMB_UP					VK_PAD_RTHUMB_UP        
#define LGE_VK_PAD_RTHUMB_DOWN					VK_PAD_RTHUMB_DOWN      
#define LGE_VK_PAD_RTHUMB_RIGHT					VK_PAD_RTHUMB_RIGHT     
#define LGE_VK_PAD_RTHUMB_LEFT					VK_PAD_RTHUMB_LEFT      
#define LGE_VK_PAD_RTHUMB_UPLEFT				VK_PAD_RTHUMB_UPLEFT    
#define LGE_VK_PAD_RTHUMB_UPRIGHT				VK_PAD_RTHUMB_UPRIGHT   
#define LGE_VK_PAD_RTHUMB_DOWNRIGHT				VK_PAD_RTHUMB_DOWNRIGHT 
#define LGE_VK_PAD_RTHUMB_DOWNLEFT				VK_PAD_RTHUMB_DOWNLEFT  

// constants for _XINPUT_KEYSTROKE struct   
#define LGE_XINPUT_KEYSTROKE_KEYDOWN			XINPUT_KEYSTROKE_KEYDOWN
#define LGE_XINPUT_KEYSTROKE_KEYUP				XINPUT_KEYSTROKE_KEYUP  
#define LGE_XINPUT_KEYSTROKE_REPEAT				XINPUT_KEYSTROKE_REPEAT 

#endif