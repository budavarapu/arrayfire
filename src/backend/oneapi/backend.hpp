/*******************************************************
 * Copyright (c) 2022, ArrayFire
 * All rights reserved.
 *
 * This file is distributed under 3-clause BSD license.
 * The complete license agreement can be obtained at:
 * http://arrayfire.com/licenses/BSD-3-Clause
 ********************************************************/

#include "types.hpp"
#ifdef __DH__
#undef __DH__
#endif

#ifdef __CUDACC__
#include <opencl_runtime.h>
#define __DH__ __device__ __host__
#else
#define __DH__
#endif

namespace detail = oneapi;
