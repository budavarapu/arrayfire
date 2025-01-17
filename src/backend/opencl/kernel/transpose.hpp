/*******************************************************
 * Copyright (c) 2014, ArrayFire
 * All rights reserved.
 *
 * This file is distributed under 3-clause BSD license.
 * The complete license agreement can be obtained at:
 * http://arrayfire.com/licenses/BSD-3-Clause
 ********************************************************/

#pragma once

#include <Param.hpp>
#include <common/dispatch.hpp>
#include <common/kernel_cache.hpp>
#include <debug_opencl.hpp>
#include <kernel_headers/transpose.hpp>
#include <traits.hpp>

#include <string>
#include <vector>

namespace opencl {
namespace kernel {

constexpr int TILE_DIM  = 32;
constexpr int THREADS_X = TILE_DIM;
constexpr int THREADS_Y = 256 / TILE_DIM;

template<typename T>
void transpose(Param out, const Param in, cl::CommandQueue queue,
               const bool conjugate, const bool IS32MULTIPLE) {
    using cl::EnqueueArgs;
    using cl::NDRange;
    using std::string;
    using std::vector;

    vector<TemplateArg> tmpltArgs = {
        TemplateTypename<T>(),
        TemplateArg(conjugate),
        TemplateArg(IS32MULTIPLE),
    };
    vector<string> compileOpts = {
        DefineValue(TILE_DIM),
        DefineValue(THREADS_Y),
        DefineValue(IS32MULTIPLE),
        DefineKeyValue(DOCONJUGATE, (conjugate && af::iscplx<T>())),
        DefineKeyValue(T, dtype_traits<T>::getName()),
    };
    compileOpts.emplace_back(getTypeBuildDefinition<T>());

    auto transpose = common::getKernel(
        "transpose", std::array{transpose_cl_src}, tmpltArgs, compileOpts);

    NDRange local(THREADS_X, THREADS_Y);

    const int blk_x = divup(in.info.dims[0], TILE_DIM);
    const int blk_y = divup(in.info.dims[1], TILE_DIM);

    NDRange global(blk_x * local[0] * in.info.dims[2],
                   blk_y * local[1] * in.info.dims[3]);

    transpose(EnqueueArgs(queue, global, local), *out.data, out.info, *in.data,
              in.info, blk_x, blk_y);
    CL_DEBUG_FINISH(queue);
}

}  // namespace kernel
}  // namespace opencl
