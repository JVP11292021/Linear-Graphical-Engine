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

#include "lge_fsys.hpp"
#include <thread> 

#pragma warning(disable : 4996)

_LGE_BEGIN_NP_LGE

LGE_CUDA_FUNC_DECL LGE_API bool sync_read(const char* path, uint8* buffer, size_t bufferSize, size_t& bytesRead) {
	FILE* handle = fopen(path, "rb");
	if (handle) {
		size_t fBytesRead = fread(buffer, 1, bufferSize, handle); 

		int err = ferror(handle);

		fclose(handle);

		if (0 == err) {
			bytesRead = fBytesRead;
			return true;
		} 
		else
			throw FileSystemException(const_cast<char*>("LGE::FileSystemException\n An error has ocurred opening one of your files.\n"));
	} 

	bytesRead = 0;
	return false;
}


LGE_CUDA_FUNC_DECL LGE_API bool async_read(const char* path, uint8* buffer, size_t bufferSize) {
	return false;
}


_LGE_END_NP_LGE