void translateKMOVQ(xed_decoded_inst_t *p) {

  const xed_inst_t *xi = xed_decoded_inst_inst(p);

  const xed_operand_t *op1 =
      xed_inst_operand(xi, 0); //オペランド1のポインタを取得
  const xed_operand_t *op2 =
      xed_inst_operand(xi, 1); //オペランド2のポインタを取得

  xed_operand_enum_t op1_name =
      xed_operand_name(op1); //オペランド1の名前を取得？;
  const xed_reg_class_enum_t isDst = xed_reg_class(
      xed_decoded_inst_get_reg(p, op1_name)); // operand1のregの種類を取得
  xed_operand_enum_t op2_name =
      xed_operand_name(op2); // operand2のオペランドの名前を取得？;
  const xed_reg_class_enum_t isSrc = xed_reg_class(
      xed_decoded_inst_get_reg(p, op2_name)); // operand2のregの種類を取得

  xed_uint_t isDstSize = xed_decoded_inst_operand_length_bits(p, 0);
  xed_uint_t isSrcSize = xed_decoded_inst_operand_length_bits(p, 1);

  unsigned int a64_dstIdx;
  unsigned int a64_srcIdx;

  if (false || (isDstSize == 64 && isSrcSize == 64 &&
                isDst == XED_REG_CLASS_MASK && isSrc == XED_REG_CLASS_MASK)) {
    mov__(Xbyak_aarch64::PReg(a64_dstIdx).b, Xbyak_aarch64::PReg(a64_srcIdx).b);
  }
  if (false ||
      (isDstSize == 64 && isSrcSize == 64 && isDst == XED_REG_CLASS_MASK &&
       isSrc == XED_REG_CLASS_INVALID)) {
    ldr(Xbyak_aarch64::PReg(a64_dstIdx), Xbyak_aarch64::ptr(X_TMP_ADDR));
  }
  if (false ||
      (isDstSize == 64 && isSrcSize == 64 && isDst == XED_REG_CLASS_INVALID &&
       isSrc == XED_REG_CLASS_MASK)) {
    str(Xbyak_aarch64::PReg(a64_srcIdx), Xbyak_aarch64::ptr(X_TMP_ADDR));
  }
  if (false || (isDstSize == 64 && isSrcSize == 64 &&
                isDst == XED_REG_CLASS_MASK && isSrc == XED_REG_CLASS_GPR)) {
    str(Xbyak_aarch64::XReg(a64_srcIdx),
        pre_ptr(sp_, -(static_cast<int64_t>(isSrcSize))));
    Xbyak_aarch64::XReg addrTmp(25);
    mov__(addrTmp, sp_);
    ldr(Xbyak_aarch64::PReg(a64_dstIdx), Xbyak_aarch64::ptr(addrTmp));
    add__(addrTmp, addrTmp, isSrcSize);
    mov__(sp_, addrTmp);
  }
  if (false || (isDstSize == 64 && isSrcSize == 64 &&
                isDst == XED_REG_CLASS_GPR && isSrc == XED_REG_CLASS_MASK)) {
    Xbyak_aarch64::XReg addrTmp(25);
    mov__(addrTmp, sp_);
    str(Xbyak_aarch64::PReg(a64_srcIdx), Xbyak_aarch64::ptr(addrTmp));
    sub__(addrTmp, addrTmp, isSrcSize);
    mov__(sp_, addrTmp);
    ldr(Xbyak_aarch64::XReg(a64_dstIdx),
        post_ptr(sp_, static_cast<int64_t>(isSrcSize)));
  }
}