// Copyright (C) 2020, Skyler. All rights reserved.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "omega/omega.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "getopt.h"
static const char* short_options = "c:e:vh";

static GETOPT_LONG_OPTION_T long_options[] = {
    {
        .name = "eval",
        .has_arg = REQUIRED_ARG,
        .flag = NULL,
        .val = 'e',
    },
    {
        .name = "version",
        .has_arg = NO_ARG,
        .flag = NULL,
        .val = 'v',
    },
    {
        .name = "help",
        .has_arg = NO_ARG,
        .flag = NULL,
        .val = 'h',
    },
    {
        NULL,
        0,
        NULL,
        0,
    },
};

static inline void print_help(void) {
  printf("Usage: omega [options] ... [script.omg] [arguments]\n\nOptions:\n");
}

int main(int argc, char* argv[]) {
  int opt;
  int opt_index;
  while ((opt = getopt_long(argc, argv, short_options, long_options, &opt_index)) != -1) {
    switch (opt) {
    case 'v':
      printf("v%s\n", OMG_VERSION);
      return EXIT_SUCCESS;
    case 'h':
      print_help();
      return EXIT_SUCCESS;
    default:
    }
  }
  return EXIT_SUCCESS;
}
