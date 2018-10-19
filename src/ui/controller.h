// Copyright 2017-2018 VMware, Inc.
// SPDX-License-Identifier: BSD-2-Clause
//
// The BSD-2 license (the License) set forth below applies to all parts of the
// Cascade project.  You may not use this file except in compliance with the
// License.
//
// BSD-2 License
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this
// list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation
// and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS AS IS AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef CASCADE_SRC_UI_CONTROLLER_H
#define CASCADE_SRC_UI_CONTROLLER_H

#include "src/runtime/runtime.h"

namespace cascade {

class Runtime;

// At the top level, FPGA-JIT is organized according to the MVC design pattern.
// The user interacts with the program through the controller, observes the
// results of those interactions through the view, and all major state is
// stored in the runtime (ie the model). The controller is one of two major
// threads of control, the other being the runtime.

// Logically, nothing prevents a program from using multiple (n) controllers.
// In this case, rather than 2, there would be n+1 main threads of control.

class Controller : public Asynchronous {
  public:
    Controller(Runtime* rt);
    virtual ~Controller() = default;

  protected:
    Runtime* runtime();

  private:
    Runtime* rt_;
};

inline Controller::Controller(Runtime* rt) : Asynchronous() {
  rt_ = rt;
}

inline Runtime* Controller::runtime() {
  return rt_;
}

} // namespace cascade

#endif
