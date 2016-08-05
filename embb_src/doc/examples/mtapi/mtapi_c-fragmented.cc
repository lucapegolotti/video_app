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

#include <stdio.h>
#include <embb/mtapi/c/mtapi.h>

#include "mtapi/mtapi_check_status-snippet.h"
#include "mtapi/mtapi_c_domain_node_id-snippet.h"

static
#include "mtapi/mtapi_c_action_signature-snippet.h"
#include "mtapi/mtapi_c_validate_arguments-snippet.h"
#include "mtapi/mtapi_c_validate_result_buffer-snippet.h"
  /* calculate */
#include "mtapi/mtapi_terminating_condition-snippet.h"
    /* first recursive call spawned as task (x = fib(n - 1);) */
#include "mtapi/mtapi_c_calc_task-snippet.h"
    /* second recursive call can be called directly (y = fib(n - 2);) */
#include "mtapi/mtapi_c_calc_direct-snippet.h"
    /* wait for completion */
#include "mtapi/mtapi_c_wait_task-snippet.h"
    /* add the two preceeding numbers */
#include "mtapi/mtapi_write_back-snippet.h"

static int fibonacci(int n) {
#include "mtapi/mtapi_c_initialize-snippet.h"
#include "mtapi/mtapi_c_register_action-snippet.h"
#include "mtapi/mtapi_c_start_task-snippet.h"
  /* wait for task completion */
  mtapi_task_wait(task, MTAPI_INFINITE, &status);
  MTAPI_CHECK_STATUS(status);
#include "mtapi/mtapi_c_finalize-snippet.h"
  return result;
}

void RunMTAPI_C() {
  /* run calculation */
  int result;
  result = fibonacci(6);

  /* print result */
  printf("result: %i\n", result);
}
