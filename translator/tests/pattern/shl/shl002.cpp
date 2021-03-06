/*******************************************************************************
 * Copyright 2020 FUJITSU LIMITED
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *******************************************************************************/
#include "test_generator2.h"

class TestPtnGenerator : public TestGenerator {
public:
  void setInitialRegValue() {
    /* Here modify arrays of inputGenReg, inputPredReg, inputZReg */
    // setInputZregAllRandomHex();
    inputGenReg[0] = 0x0001020304050607;
    inputGenReg[1] = 0x08090A0B0C0D0E0F;
    inputGenReg[2] = 0x0001020304050607;
    inputGenReg[3] = 0x08090A0B0C0D0E0F;
    // inputGenReg[4] = 0; // rsp
    inputGenReg[5] = 0x1;

    inputGenReg[8] = 0x0001020304050607;
    inputGenReg[9] = 0x08090A0B0C0D0E0F;
    inputGenReg[10] = 0x0001020304050607;
    inputGenReg[11] = 0x08090A0B0C0D0E0F;
    inputGenReg[12] = 0x1;
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    /* rax, rcx, rdx, rbx, rsp, rbp, rsi, rdi, r8, r9, r10, r11, r12, r13, r14,
     * r15 */
    shl(eax, 1);
    shl(ecx, 13);
    shl(edx, 31);
    shl(ebx, 41);
    shl(ebp, 31);

    sal(r8d, 1);
    sal(r9d, 13);
    sal(r10d, 31);
    sal(r11d, 41);
    sal(r12d, 31);
  }
};

int main(int argc, char *argv[]) {
  /* Initializing arrays of inputData, inputGenReg, inputPredReg, inputZReg,
   * checkGenRegMode, checkPredRegMode,checkZRegMode */
  TestPtnGenerator gen;

  /* Set bool output_jit_on_, bool exec_jit_on_ = 0; */
  gen.parseArgs(argc, argv);

  /* Generate JIT code and get function pointer */
  void (*f)();
  if (gen.isOutputJitOn()) {
    f = (void (*)())gen.gen();
  }

  /* Dump generated JIT code to a binary file */
  gen.dumpJitCode();

  /* 1:Execute JIT code, 2:dump all register values, 3:dump register values to
   * be checked */
  if (gen.isExecJitOn()) {
    /* Before executing JIT code, dump inputData, inputGenReg, inputPredReg,
     * inputZReg. */
    gen.dumpInputReg();
    f();                 /* Execute JIT code */
    gen.dumpOutputReg(); /* Dump all register values */
    gen.dumpCheckReg();  /* Dump register values to be checked */
  }

  return 0;
}
