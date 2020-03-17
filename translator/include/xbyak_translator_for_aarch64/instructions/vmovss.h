void translateVMOVSS(xed_decoded_inst_t *p) {
  // unsigned int i, noperands, dstIdx, srcIdx;
  const xed_inst_t *xi = xed_decoded_inst_inst(p);

  const xed_operand_t *op1 = xed_inst_operand(xi, 0);
  const xed_operand_t *op2 = xed_inst_operand(xi, 1);
  xed_operand_enum_t isDst = xed_operand_name(op1);
  xed_operand_enum_t isSrc1 = xed_operand_name(op2);

  xed_uint_t dstWidth = xed_decoded_inst_operand_length_bits(p, 0);
  // xed_uint_t isSrcSize = xed_decoded_inst_operand_length_bits(p, 1);

  const xed_reg_class_enum_t DstRegClass =
      xed_reg_class(xed_decoded_inst_get_reg(p, isDst));
  const xed_reg_class_enum_t SrcRegClass =
      xed_reg_class(xed_decoded_inst_get_reg(p, isSrc1));

  unsigned int a64_dstIdx;
  unsigned int a64_src1Idx;
  unsigned int a64_maskIdx;

  bool isMasking;
  bool isMerging;
  bool isZeroing;

  if (false ||
      (dstWidth == 128 && isMasking == 0 && isMerging == 0 && isZeroing == 0 &&
       isDst == XED_OPERAND_REG0 && isSrc1 == XED_OPERAND_MEM0) ||
      (dstWidth == 128 && isMasking == 0 && isMerging == 0 && isZeroing == 0 &&
       isDst == XED_OPERAND_REG0 && isSrc1 == XED_OPERAND_MEM0)) {
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s, p15 / Xbyak_aarch64::T_m, 0);
    ld1__(Xbyak_aarch64::VReg(a64_dstIdx).s4[0],
          Xbyak_aarch64::ptr(X_TMP_ADDR));
  }
  if (false ||
      (dstWidth == 32 && isMasking == 0 && isMerging == 0 && isZeroing == 0 &&
       isDst == XED_OPERAND_REG0 && isSrc1 == XED_OPERAND_MEM0)) {
    st1__(Xbyak_aarch64::VReg(a64_src1Idx).s4[0],
          Xbyak_aarch64::ptr(X_TMP_ADDR));
  }
  if (false ||
      (dstWidth == 128 && isMasking == 0 && isMerging == 0 && isZeroing == 0 &&
       isDst == XED_OPERAND_REG0 && isSrc1 == XED_OPERAND_REG1) ||
      (dstWidth == 128 && isMasking == 0 && isMerging == 0 && isZeroing == 0 &&
       isDst == XED_OPERAND_REG0 && isSrc1 == XED_OPERAND_REG1) ||
      (dstWidth == 128 && isMasking == 0 && isMerging == 0 && isZeroing == 0 &&
       isDst == XED_OPERAND_REG0 && isSrc1 == XED_OPERAND_REG1) ||
      (dstWidth == 128 && isMasking == 1 && isMerging == 0 && isZeroing == 1 &&
       isDst == XED_OPERAND_REG0 && isSrc1 == XED_OPERAND_REG1) ||
      (dstWidth == 128 && isMasking == 1 && isMerging == 1 && isZeroing == 0 &&
       isDst == XED_OPERAND_REG0 && isSrc1 == XED_OPERAND_REG1) ||
      (dstWidth == 128 && isMasking == 1 && isMerging == 0 && isZeroing == 1 &&
       isDst == XED_OPERAND_REG0 && isSrc1 == XED_OPERAND_MEM0) ||
      (dstWidth == 128 && isMasking == 1 && isMerging == 1 && isZeroing == 0 &&
       isDst == XED_OPERAND_REG0 && isSrc1 == XED_OPERAND_MEM0) ||
      (dstWidth == 128 && isMasking == 0 && isMerging == 0 && isZeroing == 0 &&
       isDst == XED_OPERAND_REG0 && isSrc1 == XED_OPERAND_REG1) ||
      (dstWidth == 128 && isMasking == 1 && isMerging == 0 && isZeroing == 1 &&
       isDst == XED_OPERAND_REG0 && isSrc1 == XED_OPERAND_REG1) ||
      (dstWidth == 128 && isMasking == 1 && isMerging == 1 && isZeroing == 0 &&
       isDst == XED_OPERAND_REG0 && isSrc1 == XED_OPERAND_REG1) ||
      (dstWidth == 32 && isMasking == 1 && isMerging == 1 && isZeroing == 0 &&
       isDst == XED_OPERAND_REG0 && isSrc1 == XED_OPERAND_MEM0)) {
    std::cerr << " Unimplemented " << std::endl;
    assert(NULL);
  }
}
