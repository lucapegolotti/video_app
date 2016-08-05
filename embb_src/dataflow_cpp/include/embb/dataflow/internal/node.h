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

#ifndef EMBB_DATAFLOW_INTERNAL_NODE_H_
#define EMBB_DATAFLOW_INTERNAL_NODE_H_

#include <cstddef>
#include <embb/base/exceptions.h>
#include <embb/mtapi/execution_policy.h>
#include <embb/dataflow/internal/scheduler.h>
#include <embb/dataflow/internal/clock_listener.h>

namespace embb {
namespace dataflow {
namespace internal {

class Node {
 public:
  Node() : sched_(NULL) {}
  virtual ~Node() {}
  virtual bool HasInputs() const { return false; }
  virtual bool HasOutputs() const { return false; }
  virtual void Run(int clock) = 0;
  virtual bool IsFullyConnected() = 0;
  virtual bool IsSequential() { return true; }
  virtual bool HasCycle() { return false; }
  virtual bool Start(int /*clock*/) {
    EMBB_THROW(embb::base::ErrorException,
      "Nodes are started implicitly.");
  }
  void SetScheduler(Scheduler * sched) {
    sched_ = sched;
    if (NULL != sched_) {
      SetSlices(sched_->GetSlices());
    } else {
      SetSlices(0);
    }
  }
  void SetPolicy(embb::mtapi::ExecutionPolicy const & policy) {
    policy_ = policy;
  }

 protected:
  Scheduler * sched_;
  static int next_process_id_;
  embb::mtapi::ExecutionPolicy policy_;

  static int GetNextProcessID() { return next_process_id_++; }
  virtual void SetSlices(int /*slices*/) {}
};

} // namespace internal
} // namespace dataflow
} // namespace embb

#endif // EMBB_DATAFLOW_INTERNAL_NODE_H_
