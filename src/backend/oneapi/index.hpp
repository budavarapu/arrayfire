/*******************************************************
 * Copyright (c) 2022, ArrayFire
 * All rights reserved.
 *
 * This file is distributed under 3-clause BSD license.
 * The complete license agreement can be obtained at:
 * http://arrayfire.com/licenses/BSD-3-Clause
 ********************************************************/

#include <Array.hpp>
#include <af/index.h>

namespace oneapi {

template<typename T>
Array<T> index(const Array<T>& in, const af_index_t idxrs[]);

}
