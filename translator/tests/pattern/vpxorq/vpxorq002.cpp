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
    setInputZregAllRandomHex();
#if 0
    for (int i = 0; i < 8; i++) {
      inputZReg[0].ud_dt[i] = ~uint64_t(0);
      inputZReg[3].ud_dt[i] = ~uint64_t(0);
      inputZReg[6].ud_dt[i] = ~uint64_t(0);
    }
    for (int i = 0; i < 8; i++) {
      inputZReg[1].ud_dt[i] = uint32_t(0xFF00FF00AA55AA55);
      inputZReg[4].ud_dt[i] = uint32_t(0xFF00FF00AA55AA55);
      inputZReg[7].ud_dt[i] = uint32_t(0xFF00FF00AA55AA55);
    }
#endif
    inputPredReg[1] = 0x5555;
    inputPredReg[2] = 0xaaaa;
    inputPredReg[3] = 0xffff;
    inputPredReg[4] = 0x5a5a;
    inputPredReg[7] = 0xa5a5;
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    vpxorq(Xmm(2) | k1 | T_z, Xmm(0), Xmm(1));
    vpxorq(Ymm(5) | k1 | T_z, Ymm(3), Ymm(4));
    vpxorq(Zmm(8) | k1 | T_z, Zmm(6), Zmm(7));

    vpxorq(Xmm(6) | k2 | T_z, Xmm(7), Xmm(7));
    vpxorq(Xmm(8) | k3 | T_z, Xmm(9), Xmm(8));
    vpxorq(Xmm(10) | k4 | T_z, Xmm(10), Xmm(11));

    vpxorq(Ymm(13) | k2 | T_z, Ymm(14), Ymm(14));
    vpxorq(Ymm(15) | k3 | T_z, Ymm(16), Ymm(15));
    vpxorq(Ymm(17) | k4 | T_z, Ymm(17), Ymm(18));

    vpxorq(Zmm(21) | k2 | T_z, Zmm(22), Zmm(22));
    vpxorq(Zmm(23) | k3 | T_z, Zmm(24), Zmm(23));
    vpxorq(Zmm(25) | k4 | T_z, Zmm(25), Zmm(26));

    vpxorq(Xmm(29) | k1 | T_z, Xmm(29), Xmm(29));
    vpxorq(Ymm(30) | k1 | T_z, Ymm(30), Ymm(30));
    vpxorq(Zmm(31) | k1 | T_z, Zmm(31), Zmm(31));
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
