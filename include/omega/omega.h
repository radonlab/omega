// Copyright (C) 2020, Skyler. All rights reserved.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef OMEGA_OMEGA_H_
#define OMEGA_OMEGA_H_

#include <stddef.h>

#include "omega/omgconf.h"

#ifndef OMG_EXPORT
#if defined(OMG_USE_SHARED)
#if defined(_WIN32)
#if defined(OMG_IMPLEMENTATION)
#define OMG_EXPORT __declspec(dllexport)
#else   // !defined(OMG_IMPLEMENTATION)
#define OMG_EXPORT __declspec(dllimport)
#endif  // OMG_IMPLEMENTATION
#else   // !defined(_WIN32)
#if defined(OMG_IMPLEMENTATION)
#define OMG_EXPORT __attribute__((visibility("default")))
#else   // !defined(OMG_IMPLEMENTATION)
#define OMG_EXPORT
#endif  // OMG_IMPLEMENTATION
#endif  // _WIN32
#else   // !defined(OMG_USE_SHARED)
#define OMG_EXPORT
#endif  // OMG_USE_SHARED
#endif  // OMG_EXPORT

typedef enum omega_err_code {
  OMG_OK = 0,
  OMG_INTERN_ERR,
  OMG_FILE_READ_ERR,
} omega_err_code;

OMG_EXPORT omega_err_code omega_compile_script(const char* src, const char* out);

OMG_EXPORT omega_err_code omega_execute(const char* src_entry);

#endif  // OMEGA_OMEGA_H_
