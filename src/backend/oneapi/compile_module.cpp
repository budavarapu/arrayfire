/*******************************************************
 * Copyright (c) 2022, ArrayFire
 * All rights reserved.
 *
 * This file is distributed under 3-clause BSD license.
 * The complete license agreement can be obtained at:
 * http://arrayfire.com/licenses/BSD-3-Clause
 ********************************************************/

#include <common/compile_module.hpp>  //compileModule & loadModuleFromDisk
#include <common/kernel_cache.hpp>    //getKernel(Module&, ...)

#include <CL/sycl.hpp>
#include <common/Logger.hpp>
#include <common/defines.hpp>
#include <common/util.hpp>
//#include <debug_opencl.hpp> TODO: remove?
#include <err_oneapi.hpp>
//#include <kernel_headers/KParam.hpp>
#include <platform.hpp>
#include <traits.hpp>

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using common::loggerFactory;
using fmt::format;
// using oneapi::getActiveDeviceId;
// using oneapi::getDevice;
using oneapi::Kernel;
using oneapi::Module;
using spdlog::logger;
using sycl::bundle_state;
using sycl::kernel_bundle;

using std::begin;
using std::end;
using std::ofstream;
using std::ostringstream;
using std::shared_ptr;
using std::string;
using std::to_string;
using std::transform;
using std::vector;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;

logger *getLogger() {
    static shared_ptr<logger> logger(loggerFactory("jit"));
    return logger.get();
}

string getProgramBuildLog(const kernel_bundle<bundle_state::executable> &prog) {
    ONEAPI_NOT_SUPPORTED("");
    return "";
}

//#define THROW_BUILD_LOG_EXCEPTION(PROG)                              \
//    do {                                                             \
//        string build_error = getProgramBuildLog(PROG);               \
//        string info        = getEnvVar("AF_OPENCL_SHOW_BUILD_INFO"); \
//        if (!info.empty() && info != "0") puts(build_error.c_str()); \
//        AF_ERROR(build_error, AF_ERR_INTERNAL);                      \
//    } while (0)

namespace oneapi {

// const static string DEFAULT_MACROS_STR(
//"\n\
                                           //#ifdef USE_DOUBLE\n\
                                           //#pragma OPENCL EXTENSION cl_khr_fp64 : enable\n\
                                           //#endif\n                     \
                                           //#ifdef USE_HALF\n\
                                           //#pragma OPENCL EXTENSION cl_khr_fp16 : enable\n\
                                           //#else\n                     \
                                           //#define half short\n          \
                                           //#endif\n                      \
                                           //#ifndef M_PI\n               \
                                           //#define
// M_PI 3.1415926535897932384626433832795028841971693993751058209749445923078164\n
//\
                                           //#endif\n                     \
                                           //");

/*
get_kernel_bundle<>() needs sycl::context
kernel_bundle<bundle_state::executable> buildProgram(const vector<string>
&kernelSources, const vector<string> &compileOpts) { ONEAPI_NOT_SUPPORTED("");
    kernel_bundle<bundle_state::executable> bb;
    return bb;
}
*/

}  // namespace oneapi

string getKernelCacheFilename(const int device, const string &key) {
    ONEAPI_NOT_SUPPORTED("");
    return "";
}

namespace common {

/*
Module compileModule(const string &moduleKey, const vector<string> &sources,
                     const vector<string> &options,
                     const vector<string> &kInstances, const bool isJIT) {
    ONEAPI_NOT_SUPPORTED("");
    Module m{}
    return m;
}

Module loadModuleFromDisk(const int device, const string &moduleKey,
                          const bool isJIT) {
    ONEAPI_NOT_SUPPORTED("");
    Module m{}
    return m;
}

Kernel getKernel(const Module &mod, const string &nameExpr,
                 const bool sourceWasJIT) {
    ONEAPI_NOT_SUPPORTED("");
    return {nameExpr, &mod.get(), sycl::Kernel()};
}
*/

}  // namespace common
