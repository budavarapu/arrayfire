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
void lu(Array<T> &lower, Array<T> &upper, Array<int> &pivot,
        const Array<T> &in);

template<typename T>
Array<int> lu_inplace(Array<T> &in, const bool convert_pivot = true);

bool isLAPACKAvailable();
}  // namespace oneapi
