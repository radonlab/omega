// Copyright (C) 2020, Skyler. All rights reserved.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "omega/omega.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pgetopt.h"
#include "levenshtein.h"

#define SIMILARITY_FLOOR 7
#define MAX_PROMPT_COUNT 3

#define OPTIONS_SIZE(options) (sizeof(options) / sizeof((options)[0]) - 1)

typedef struct candidate_flag {
  const char* long_name;
  int distance;
} candidate_flag;

static char* short_options = "c:e:vh";

static struct option long_options[] = {
    {
        .name = "eval",
        .has_arg = required_argument,
        .flag = NULL,
        .val = 'e',
    },
    {
        .name = "version",
        .has_arg = no_argument,
        .flag = NULL,
        .val = 'v',
    },
    {
        .name = "help",
        .has_arg = no_argument,
        .flag = NULL,
        .val = 'h',
    },
    {NULL, 0, NULL, 0},
};

static inline void print_help(void) {
  printf("Usage: omega [options] ... [script.omg] [arguments]\n\nOptions:\n");
}

static void str_trim_flag(const char* flag, size_t* bgn, size_t* end) {
  const char* pbgn;
  const char* pend;
  pbgn = flag;
  while (*pbgn == '-') {
    pbgn++;
  }
  pend = pbgn;
  while (*pend != '=' && *pend != '\0') {
    pend++;
  }
  *bgn = pbgn - flag;
  *end = pend - flag;
}

static int compare_candidate_flags(const void* p1, const void* p2) {
  const candidate_flag* f1 = p1;
  const candidate_flag* f2 = p2;
  int diff = f1->distance - f2->distance;
  return diff != 0 ? diff : strcmp(f1->long_name, f2->long_name);
}

static int prepare_candidate_flags(candidate_flag* flag_buf, const char* current_flag) {
  // purge flag
  size_t bgn, end;
  str_trim_flag(current_flag, &bgn, &end);
  // measure similarity
  int flag_cnt = 0;
  for (int i = 0; i < OPTIONS_SIZE(long_options); i++) {
    const char* long_name = long_options[i].name;
    if (long_name) {
      flag_buf[flag_cnt].long_name = long_name;
      flag_buf[flag_cnt].distance =
          levenshtein_n(current_flag + bgn, end - bgn, long_name, strlen(long_name), 0, 2, 1, 3);
      flag_cnt++;
    }
  }
  // sort by similarity
  qsort(flag_buf, flag_cnt, sizeof(candidate_flag), compare_candidate_flags);
  return flag_cnt;
}

static void print_candidates(const char* current_flag) {
  candidate_flag flag_buf[OPTIONS_SIZE(long_options)];
  int flag_cnt = prepare_candidate_flags(flag_buf, current_flag);
  // print candidates
  int prompt_cnt = 0;
  for (int i = 0; i < flag_cnt; i++) {
    if (flag_buf[i].distance < SIMILARITY_FLOOR && prompt_cnt <= MAX_PROMPT_COUNT) {
      prompt_cnt++;
      if (prompt_cnt == 1) {
        printf("\nthe most similar options:\n");
      }
      printf("  --%s\n", flag_buf[i].long_name);
    }
  }
  if (prompt_cnt > 0) {
    printf("\n");
  }
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
      if (!optopt) {
        const char* current_flag = argv[optind - 1];
        print_candidates(current_flag);
      }
      return EXIT_FAILURE;
    }
  }
  return EXIT_SUCCESS;
}
