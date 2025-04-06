// Copyright (C) 2020, Skyler. All rights reserved.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef OMEGA_UTILITY_H_
#define OMEGA_UTILITY_H_

#ifndef MAX
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif  // MAX

#ifndef MIN
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif  // MIN

#define SIZE_OF_ARRAY(arr) (sizeof(arr) / sizeof((arr)[0]))

#endif  // OMEGA_UTILITY_H_
