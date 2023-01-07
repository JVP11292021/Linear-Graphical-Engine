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

#ifndef __LGE_CLOCKING__
#define __LGE_CLOCKING__

#include "engine_setup.h"

#include <chrono>
#include <iostream>

#define lgeHz2kHz 1/(10*10*10)
#define lgeHz2mHz 1/(10*10*10*10*10*10)
#define lgeHz2gHz 1/(10*10*10*10*10*10*10*10*10)

_LGE_BEGIN_NP_LGE

class LGE_API Clock {
private:
	uint64 timeCycles;
	f32 timeScale;
	bool v_isPaused;
	LGE_STATIC f32 s_cyclesPerSecond;

	LGE_CUDA_FUNC_DECL LGE_STATIC_INLINE uint64 secondsToCycles(f32 timeSeconds);

	/// <summary>
	/// WARNING: Dangerous -- only use to convert small
	/// durations into seconds.
	/// </summary>
	/// <param name="timeCycles"></param>
	/// <returns>Float32</returns>
	LGE_CUDA_FUNC_DECL LGE_STATIC_INLINE f32 cyclesToSeconds(uint64 timeCycles);


public:
	/// <summary>
	/// Call this when the game first starts up.
	/// </summary>
	/// <returns></returns>
	LGE_CUDA_FUNC_DECL LGE_STATIC void init();
	
	/// <summary>
	/// Constructs a clock object. (Notice the use of 'explicit' to
	/// prevent automatic conversion from F32 to Clock.)
	/// </summary>
	/// <param name="startTimeSeconds"></param>
	Clock(f32 startTimeSeconds = 0.0f);

	/// <summary>
	///	Return the current time in cycles. NOTE that we do 
	///	not return absolute time measurements in floating- 
	///	point seconds, because a 32-bit float doesn't have 
	///	enough precision. See calcDeltaSeconds(). 
	/// </summary>
	/// <returns>Unsigned int 64</returns>
	LGE_CUDA_FUNC_DECL uint64 getTimeCycles() const;

	/// <summary>
	/// Determine the difference between this clock's
	/// absolute time and that of another clock, in
	/// seconds. We only return time deltas as floating-
	/// point seconds, due to the precision limitations of Float32
	/// </summary>
	/// <param name="other"></param>
	/// <returns>Float32</returns>
	LGE_CUDA_FUNC_DECL f32 calcDeltaSeconds(const Clock&);

	/// <summary>
	/// This function should be called once per frame,
	/// with the real measured frame time delta in seconds.
	/// </summary>
	/// <param name="dtRealSeconds"></param>
	/// <returns></returns>
	LGE_CUDA_FUNC_DECL void update(f32);
	LGE_CUDA_FUNC_DECL void setPaused(bool);
	LGE_CUDA_FUNC_DECL bool isPaused() const;
	LGE_CUDA_FUNC_DECL void setTimeScale(f32 scale);
	LGE_CUDA_FUNC_DECL f32 getTimeScale() const;
	LGE_CUDA_FUNC_DECL void singleStep();
};

typedef LGE_API class mbmstmr {
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> startTimepoint;
	f64 multiplier = 1.0;

	LGE_CUDA_FUNC_DECL void stop();
	LGE_CUDA_FUNC_DECL void log(f64);

public:
	mbmstmr();
	mbmstmr(f64 multiplier);
	~mbmstmr();

	LGE_CUDA_FUNC_DECL LGE_INLINE void setMultiplier(f64);
}
bTimer;

#ifdef LGE_PLATFORM == LGE_WINDOWS
LGE_CUDA_FUNC_DECL LGE_INLINE LGE_API uint64 rdtsc();

#else
LGE_CUDA_FUNC_DECL LGE_INLINE uint64 rdtsc();
#endif

/// <summary>
/// WARNING! This function is vulnerable to cyber attacks, don't use this function inside meaningfull tasks.
/// This function is for informational purposes only, all other uses are the user's own responsibility.
/// </summary>
/// <returns>Float64</returns>
LGE_CUDA_FUNC_DECL LGE_API f64 currentCpuFreq();

_LGE_END_NP_LGE
#endif