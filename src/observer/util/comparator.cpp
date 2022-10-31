/* Copyright (c) 2021 Xie Meiyi(xiemeiyi@hust.edu.cn) and OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by wangyunlai on 2021/6/11.
//

#include <string.h>
#include <algorithm>
#include <cmath>
#include "util/date.h"
#include "defs.h"
#include "util/util.h"

const double epsilon = 1E-6;

int compare_int(void *arg1, void *arg2, bool index = false)
{
  if(!index && (is_null((char *)arg1) || is_null((char *)arg2))) {
    return NULL_CONST;
  }
  int v1 = *(int *)arg1;
  int v2 = *(int *)arg2;
  return v1 - v2;
}

int compare_float(void *arg1, void *arg2, bool index = false)
{
  if(!index && (is_null((char *)arg1) || is_null((char *)arg2))) {
    return NULL_CONST;
  }
  float v1 = *(float *)arg1; 
  float v2 = *(float *)arg2; 
  if (std::isinf(v1) || std::isinf(v1)) {
    return NULL_CONST;
  }
  float cmp = v1 - v2;
  if (cmp > epsilon) {
    return 1;
  }
  if (cmp < -epsilon) {
    return -1;
  }
  return 0;
}

int compare_string(void *arg1, int arg1_max_length, void *arg2, int arg2_max_length, bool index = false)
{
  if(!index && (is_null((char *)arg1) || is_null((char *)arg2))) {
    return NULL_CONST;
  }
  const char *s1 = (const char *)arg1;
  const char *s2 = (const char *)arg2;
  int maxlen = std::min(arg1_max_length, arg2_max_length);
  int result =  strncmp(s1, s2, maxlen);
  if (0 != result) {
    return result;
  }

  if (arg1_max_length > maxlen) {
    return s1[maxlen] - 0;
  }

  if (arg2_max_length > maxlen) {
    return 0 - s2[maxlen];
  }
  return 0;
}

int compare_date(void *arg1, void *arg2, bool index = false) {
  if(!index && (is_null((char *)arg1) || is_null((char *)arg2))) {
    return NULL_CONST;
  }
  Date *d1 = (Date *)arg1;
  Date *d2 = (Date *)arg2;
  if (*d1 > *d2) {
    return 1;
  } else if (*d1 < *d2) {
    return -1;
  }
  return 0;
}