/*******************************************************
 * Copyright (c) 2022, ArrayFire
 * All rights reserved.
 *
 * This file is distributed under 3-clause BSD license.
 * The complete license agreement can be obtained at:
 * http://arrayfire.com/licenses/BSD-3-Clause
 ********************************************************/

#include <Array.hpp>
#include <af/features.h>

using af::features;

namespace oneapi {

template<typename T, typename convAccT>
unsigned sift(Array<float>& x, Array<float>& y, Array<float>& score,
              Array<float>& ori, Array<float>& size, Array<float>& desc,
              const Array<T>& in, const unsigned n_layers,
              const float contrast_thr, const float edge_thr,
              const float init_sigma, const bool double_input,
              const float img_scale, const float feature_ratio,
              const bool compute_GLOH);

}
