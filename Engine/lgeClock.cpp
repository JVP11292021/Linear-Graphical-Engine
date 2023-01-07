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

#include "lgeClock.hpp"
#include <time.h>

#ifdef LGE_PLATFORM == LGE_WINDOWS
#	include <intrin.h>
#else
#	include <x86intrin.h>
#endif

_LGE_BEGIN_NP_LGE

f32 Clock::s_cyclesPerSecond = 0.0F;

LGE_CUDA_FUNC_DECL uint64 Clock::secondsToCycles(f32 timeSeconds) {
	return ((uint64)timeSeconds * (uint64)Clock::s_cyclesPerSecond);
}

LGE_CUDA_FUNC_DECL f32 Clock::cyclesToSeconds(uint64 timeCycles) {
	return (f32)timeCycles / Clock::s_cyclesPerSecond;
}

LGE_CUDA_FUNC_DECL void Clock::init() {
	Clock::s_cyclesPerSecond = (f32)rdtsc();
}

Clock::Clock(f32 startTimeSeconds) 
#ifdef LGE_HAS_INITIALIZER_LIST
	:
		timeCycles(this->secondsToCycles(startTimeSeconds)),
		timeScale(1.0F), // default to unscaled
		v_isPaused(false) // default to running
#endif
{
#ifndef LGE_HAS_INITIALIZER_LIST
	this->m_timeCycles = this->secondsToCycles(startTimeSeconds);
	this->m_timeScale = 1.0F;
	this->m_isPaused = false;
#endif	
}

LGE_CUDA_FUNC_DECL uint64 Clock::getTimeCycles() const {
	return this->timeCycles;
}

LGE_CUDA_FUNC_DECL f32 Clock::calcDeltaSeconds(const Clock& other) {
	uint64 dt = this->timeCycles - other.timeCycles;
	return this->cyclesToSeconds(dt);
}

LGE_CUDA_FUNC_DECL void Clock::update(f32 dtRealSeconds) {
	if (!this->v_isPaused) {
		uint64 dtScaledCycles = secondsToCycles(dtRealSeconds * this->timeScale);
		this->timeCycles += dtScaledCycles;
	}
}

LGE_CUDA_FUNC_DECL void Clock::setPaused(bool wantPaused) {
	this->v_isPaused = wantPaused;
}

LGE_CUDA_FUNC_DECL bool Clock::isPaused() const {
	return this->v_isPaused;
}

LGE_CUDA_FUNC_DECL void Clock::setTimeScale(f32 scale) {
	timeScale = scale;
}

LGE_CUDA_FUNC_DECL f32 Clock::getTimeScale() const {
	return this->timeScale;
}

LGE_CUDA_FUNC_DECL void Clock::singleStep() {
	if (this->v_isPaused) {
		uint64 dtScaledCycles = secondsToCycles((1.0f / 30.0f) * this->timeScale);
		this->timeCycles += dtScaledCycles;
	}
}


LGE_CUDA_FUNC_DECL void mbmstmr::stop() {
	LGE_AUTO endTimepoint = std::chrono::high_resolution_clock::now();

	LGE_AUTO start = std::chrono::time_point_cast<std::chrono::microseconds>(this->startTimepoint).time_since_epoch().count();
	LGE_AUTO end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

	LGE_AUTO tDurr = end - start;

	f64 fTime = (f64)tDurr * this->multiplier;

	this->log(fTime);
}

LGE_CUDA_FUNC_DECL void mbmstmr::log(f64 totTime) {
	if (this->multiplier == 1.0)
		std::cout << "Program was executed in " << totTime << " us" << "\n";
	else if (this->multiplier == 0.001)
		std::cout << "Program was executed in " << totTime << " ms" << "\n";
	else if (this->multiplier == 0.000001)
		std::cout << "Program was executed in " << totTime << " s" << "\n";
}

mbmstmr::mbmstmr()
#ifdef LGE_HAS_INITIALIZER_LIST
	: startTimepoint(std::chrono::high_resolution_clock::now())
#endif
{
#ifndef LGE_HAS_INITIALIZER_LIST
	this->startTimepoint = std::chrono::high_resolution_clock::now();
#endif
}

mbmstmr::mbmstmr(f64 multiplier)
#ifdef LGE_HAS_INITIALIZER_LIST
	: startTimepoint(std::chrono::high_resolution_clock::now()), multiplier(multiplier)
#endif
{
#ifndef LGE_HAS_INITIALIZER_LIST
	this->startTimepoint = std::chrono::high_resolution_clock::now();
	this->multiplier = multiplier;
#endif
}

mbmstmr::~mbmstmr() {
	this->stop();
}

LGE_CUDA_FUNC_DECL LGE_INLINE void mbmstmr::setMultiplier(f64 multiplier) {
	this->multiplier = multiplier;
}


#ifdef LGE_PLATFORM == LGE_WINDOWS
LGE_CUDA_FUNC_DECL LGE_INLINE LGE_API uint64 rdtsc() {
	return __rdtsc();
}
#else
LGE_CUDA_FUNC_DECL LGE_INLINE uint64 rdtsc() {
	uint64 lo, hi;
	__asm__ __volatile__("rdtsc" : "=a" (lo), "=d" (hi));
	return ((uint64)hi << 32) | lo;
}
#endif

LGE_CUDA_FUNC_DECL LGE_API f64 currentCpuFreq() {
	int64 basetime = time(NULL);

	while (time(NULL) == basetime);
	uint64 stclk = rdtsc();

	basetime = time(NULL);
	uint64 endclk = 0;
	while (time(NULL) == basetime)
		endclk = rdtsc();

	return (f64)endclk - stclk;
}
_LGE_END_NP_LGE