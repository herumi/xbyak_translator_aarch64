void translateMOVSS(xed_decoded_inst_t *p) {
  // unsigned int i, noperands, dstIdx, srcIdx;
  const xed_inst_t *xi = xed_decoded_inst_inst(p);

  const xed_operand_t *op1 =
      xed_inst_operand(xi, 0); // dstのオペランドのポインタを取得
  const xed_operand_t *op2 =
      xed_inst_operand(xi, 1); // dstのオペランドのポインタを取得
  xed_operand_enum_t isDst =
      xed_operand_name(op1); // dstのオペランドの名前を取得
  xed_operand_enum_t isSrc =
      xed_operand_name(op2); // srcのオペランドの名前を取得

  xed_uint_t isDstSize = xed_decoded_inst_operand_length_bits(p, 0);
  xed_uint_t isSrcSize = xed_decoded_inst_operand_length_bits(p, 1);

  const xed_reg_class_enum_t DstRegClass =
      xed_reg_class(xed_decoded_inst_get_reg(p, isDst));
  const xed_reg_class_enum_t SrcRegClass =
      xed_reg_class(xed_decoded_inst_get_reg(p, isSrc));

  unsigned int a64_dstIdx;
  unsigned int a64_srcIdx;

  if (false ||
      (isDstSize == 32 && isSrcSize == 32 && isDst == XED_OPERAND_REG0 &&
       isSrc == XED_OPERAND_REG1) ||
      (isDstSize == 128 && isSrcSize == 32 && isDst == XED_OPERAND_REG0 &&
       isSrc == XED_OPERAND_REG1)) {
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    not_(pTmp.b, p15 / Xbyak_aarch64::T_z, p14.b);
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_m,
          Xbyak_aarch64::ZReg(a64_srcIdx).s);
    xt_pop_preg();
  }
  if (false || (isDstSize == 128 && isSrcSize == 32 &&
                isDst == XED_OPERAND_REG0 && isSrc == XED_OPERAND_MEM0)) {
    fmov__(Xbyak_aarch64::VReg(a64_dstIdx).s4, 0);
    ld1__(Xbyak_aarch64::VReg(a64_dstIdx).s4[0],
          Xbyak_aarch64::ptr(X_TMP_ADDR));
  }
  if (false || (isDstSize == 32 && isSrcSize == 32 &&
                isDst == XED_OPERAND_MEM0 && isSrc == XED_OPERAND_REG0)) {
    st1__(Xbyak_aarch64::VReg(a64_srcIdx).s4[0],
          Xbyak_aarch64::ptr(X_TMP_ADDR));
  }
}