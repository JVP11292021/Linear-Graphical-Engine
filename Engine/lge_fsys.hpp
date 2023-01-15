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

#ifndef __LGE_FSYS__
#define __LGE_FSYS__

#include "lgeExceptions.hpp"
#include "engine_setup.h"

#define lgeFile  __FILE__
#define lgeDate __DATE__
#define lgeLine __LINE__
#define lgeTime __TIME__

_LGE_BEGIN_NP_LGE

//typedef LGE_API struct __AIOCB__ {

//} AsyncCB;

LGE_CUDA_FUNC_DECL LGE_API bool sync_read(const char*, uint8*, size_t, size_t&);	
LGE_CUDA_FUNC_DECL LGE_API bool async_read(const char*, uint8*, size_t);

_LGE_END_NP_LGE

#endif