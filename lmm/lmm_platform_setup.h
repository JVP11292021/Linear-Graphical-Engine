#pragma once

// =====================================================================
// Built in platform support
// =====================================================================

#define LMM_PLATFORM_UNKNOWN		0x00000000
#define LMM_PLATFORM_WINDOWS		0x00010000
#define LMM_PLATFORM_LINUX			0x00020000
#define LMM_PLATFORM_APPLE			0x00040000
#define LMM_PLATFORM_IOS			0x00080000
#define LMM_PLATFORM_ANDROID		0x00100000
#define LMM_PLATFORM_CHROME_NACL	0x00200000
#define LMM_PLATFORM_UNIX			0x00400000
#define LMM_PLATFORM_QNXNTO			0x00800000
#define LMM_PLATFORM_WINCE			0x01000000
#define LMM_PLATFORM_CYGWIN			0x02000000

#ifdef LMM_FORCE_PLATFORM_UNKNOWN
#	define LMM_PLATFORM LMM_PLATFORM_UNKNOWN
#elif defined(__CYGWIN__)
#	define LMM_PLATFORM LMM_PLATFORM_CYGWIN
#elif defined(__QNXNTO__)
#	define LMM_PLATFORM LMM_PLATFORM_QNXNTO
#elif defined(__APPLE__)
#	define LMM_PLATFORM LMM_PLATFORM_APPLE
#elif defined(WINCE)
#	define LMM_PLATFORM LMM_PLATFORM_WINCE
#elif defined(_WIN32)
#	define LMM_PLATFORM LMM_PLATFORM_WINDOWS
#elif defined(__native_client__)
#	define LMM_PLATFORM LMM_PLATFORM_CHROME_NACL
#elif defined(__ANDROID__)
#	define LMM_PLATFORM LMM_PLATFORM_ANDROID
#elif defined(__linux)
#	define LMM_PLATFORM LMM_PLATFORM_LINUX
#elif defined(__unix)
#	define LMM_PLATFORM LMM_PLATFORM_UNIX
#else
#	define LMM_PLATFORM LMM_PLATFORM_UNKNOWN
#endif

#ifndef LMM_PLATFORM
#define LMM_PLATFORM_ERROR_FLAG
#	error "LMM_PLATFORM undefined, your platform may not be supported by LMM. Add #define LMM_PLATFORM 0 to ignore this message."
#endif