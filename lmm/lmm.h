#ifndef LMM
#define LMM

#include "lmm_defs.h"

#include "cmat.h"
#include "cvalue_ptr.h"
#include "cvec.h"

#ifdef LMM_CPP
namespace lmm {
#endif

#	include "types.h"
#	include "trigonometry.h"
//#	include "../lmm/lmm_math.h"
#	include "carr.h"
#	include "value_ptr.h"

#	ifdef LMM_CPP
#		include "RenderState.hpp"
#		include "manipulations.hpp"

#		include "clip_space.hpp"

#		include "cppmat.hpp"
#		include "cppvec.hpp"
#		include "cppquat.hpp"
#	endif

#ifdef LMM_CPP
}
#endif
#endif