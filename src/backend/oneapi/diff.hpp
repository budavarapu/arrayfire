/*******************************************************
 * Copyright (c) 2022, ArrayFire
 * All rights reserved.
 *
 * This file is distributed under 3-clause BSD license.
 * The complete license agreement can be obtained at:
 * http://arrayfire.com/licenses/BSD-3-Clause
 ********************************************************/

#include <Array.hpp>

namespace oneapi {
template<typename T>
Array<T> diff1(const Array<T> &in, const int dim);

template<typename T>
Array<T> diff2(const Array<T> &in, const int dim);
}  // namespace oneapi
