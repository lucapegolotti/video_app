/*
 * Copyright (c) 2014-2016, Siemens AG. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef EMBB_BASE_C_INTERNAL_ATOMIC_ATOMIC_VARIABLES_H_
#define EMBB_BASE_C_INTERNAL_ATOMIC_ATOMIC_VARIABLES_H_

#include <stddef.h>
#include <embb/base/c/internal/macro_helper.h>

#ifdef EMBB_PLATFORM_COMPILER_MSVC
#include <intrin.h>
#endif

#define EMBB_ATOMIC_INTERNAL_DEFINE_VARIABLE( \
  EMBB_ATOMIC_PARAMETER_TYPE_NATIVE, \
  EMBB_ATOMIC_PARAMETER_ATOMIC_TYPE_SUFFIX) \
  typedef struct \
{ \
  volatile EMBB_ATOMIC_PARAMETER_TYPE_NATIVE internal_variable; \
} EMBB_CAT2(embb_atomic_, EMBB_ATOMIC_PARAMETER_ATOMIC_TYPE_SUFFIX);

EMBB_ATOMIC_INTERNAL_DEFINE_VARIABLE(char, char)
EMBB_ATOMIC_INTERNAL_DEFINE_VARIABLE(short, short)
EMBB_ATOMIC_INTERNAL_DEFINE_VARIABLE(unsigned short, unsigned_short)
EMBB_ATOMIC_INTERNAL_DEFINE_VARIABLE(int, int)
EMBB_ATOMIC_INTERNAL_DEFINE_VARIABLE(unsigned int, unsigned_int)
EMBB_ATOMIC_INTERNAL_DEFINE_VARIABLE(long, long)
EMBB_ATOMIC_INTERNAL_DEFINE_VARIABLE(unsigned long, unsigned_long)
EMBB_ATOMIC_INTERNAL_DEFINE_VARIABLE(long long, long_long)
EMBB_ATOMIC_INTERNAL_DEFINE_VARIABLE(unsigned long long, unsigned_long_long)
EMBB_ATOMIC_INTERNAL_DEFINE_VARIABLE(intptr_t, intptr_t)
EMBB_ATOMIC_INTERNAL_DEFINE_VARIABLE(uintptr_t, uintptr_t)
EMBB_ATOMIC_INTERNAL_DEFINE_VARIABLE(size_t, size_t)
EMBB_ATOMIC_INTERNAL_DEFINE_VARIABLE(ptrdiff_t, ptrdiff_t)
EMBB_ATOMIC_INTERNAL_DEFINE_VARIABLE(uintmax_t, uintmax_t)

#endif //EMBB_BASE_C_INTERNAL_ATOMIC_ATOMIC_VARIABLES_H_
