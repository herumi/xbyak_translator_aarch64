void translateVCMPPS(xed_decoded_inst_t *p) {
  // unsigned int i, noperands, dstIdx, srcIdx;
  const xed_inst_t *xi = xed_decoded_inst_inst(p);

  const xed_operand_t *op1 =
      xed_inst_operand(xi, 0); // dstのオペランドのポインタを取得
  const xed_operand_t *op2 =
      xed_inst_operand(xi, 1); // srcのオペランドのポインタを取得
  const xed_operand_t *op3 =
      xed_inst_operand(xi, 2); // src2のオペランドのポインタを取得
  xed_operand_enum_t isDst =
      xed_operand_name(op1); // dstのオペランドの名前を取得
  xed_operand_enum_t isSrc1 =
      xed_operand_name(op2); // src1のオペランドの名前を取得
  xed_operand_enum_t isSrc2 =
      xed_operand_name(op3); // srcのオペランドの名前を取得

  xed_uint_t dstWidth = xed_decoded_inst_operand_length_bits(p, 0);
  // xed_uint_t isSrcSize = xed_decoded_inst_operand_length_bits(p, 1);

  const xed_reg_class_enum_t DstRegClass =
      xed_reg_class(xed_decoded_inst_get_reg(p, isDst));
  const xed_reg_class_enum_t SrcRegClass1 =
      xed_reg_class(xed_decoded_inst_get_reg(p, isSrc1));

  unsigned int a64_dstIdx;
  unsigned int a64_src1Idx;
  unsigned int a64_src2Idx;
  unsigned int a64_maskIdx;

  bool isMasking;
  bool isMerging;
  bool isZeroing;

  unsigned int isIMM;

  if (false || (dstWidth == 128 && isMasking == 0 &&
                isMerging == XED_REG_CLASS_XMM && isSrc2 == XED_OPERAND_REG2)) {
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(pTmp.b, p15.b);
    switch (isIMM) {
    case 0:
      cmpeq(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 1:
      cmplt(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 2:
      cmple(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 3:
      cmpne(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 4:
      cmpne(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 5:
      cmpge(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 6:
      cmpgt(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 7:
      cmpeq(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 8:
      cmpeq(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 9:
      cmplt(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 10:
      cmple(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 11:
      cmpne(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 12:
      cmpne(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 13:
      cmpge(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 14:
      cmpge(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 15:
      cmpeq(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 16:
      cmpeq(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 17:
      cmplt(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 18:
      cmple(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 19:
      cmpne(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 20:
      cmpne(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 21:
      cmpge(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 22:
      cmpgt(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 23:
      cmpeq(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 24:
      cmpeq(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 25:
      cmplt(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 26:
      cmple(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 27:
      cmpne(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 28:
      cmpne(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 29:
      cmpge(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 30:
      cmpgt(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 31:
      cmpeq(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    default:
      std::cerr << "Unimplemented" << std::endl;
      break;
    }
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s, p8 / Xbyak_aarch64::T_m,
          0xFFFFFFFF);
    not_(pTmp.b, p15 / Xbyak_aarch64::T_z, p8.b);
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_m, 0);
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s, p14 / Xbyak_aarch64::T_m, 0);
    xt_pop_preg();
  }
  if (false || (dstWidth == 128 && isMasking == 0 &&
                isMerging == XED_REG_CLASS_XMM && isSrc2 == XED_OPERAND_MEM0)) {
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    Xbyak_aarch64::ZReg zTmp = xt_push_zreg();
    ld1b(zTmp.s, pTmp / Xbyak_aarch64::T_m, Xbyak_aarch64::ptr(X_TMP_ADDR));
    mov__(pTmp.b, p15.b);
    switch (isIMM) {
    case 0:
      cmpeq(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 1:
      cmplt(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 2:
      cmple(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 3:
      cmpne(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src2Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 4:
      cmpne(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 5:
      cmpge(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 6:
      cmpgt(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 7:
      cmpeq(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 8:
      cmpeq(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 9:
      cmplt(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 10:
      cmple(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 11:
      cmpne(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 12:
      cmpne(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 13:
      cmpge(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 14:
      cmpge(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 15:
      cmpeq(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 16:
      cmpeq(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 17:
      cmplt(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 18:
      cmple(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 19:
      cmpne(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 20:
      cmpne(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 21:
      cmpge(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 22:
      cmpgt(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 23:
      cmpeq(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 24:
      cmpeq(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 25:
      cmplt(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 26:
      cmple(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 27:
      cmpne(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 28:
      cmpne(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 29:
      cmpge(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 30:
      cmpgt(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 31:
      cmpeq(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    default:
      std::cerr << "Unimplemented" << std::endl;
      break;
    }
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s, p8 / Xbyak_aarch64::T_m,
          0xFFFFFFFF);
    not_(pTmp.b, p15 / Xbyak_aarch64::T_z, p8.b);
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_m, 0);
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s, p14 / Xbyak_aarch64::T_m, 0);
    xt_pop_preg();
    xt_pop_zreg();
  }
  if (false || (dstWidth == 256 && isMasking == 0 &&
                isMerging == XED_REG_CLASS_YMM && isSrc2 == XED_OPERAND_REG2)) {
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(pTmp.b, p15.b);
    switch (isIMM) {
    case 0:
      cmpeq(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 1:
      cmplt(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 2:
      cmple(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 3:
      cmpne(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 4:
      cmpne(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 5:
      cmpge(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 6:
      cmpgt(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 7:
      cmpeq(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 8:
      cmpeq(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 9:
      cmplt(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 10:
      cmple(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 11:
      cmpne(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 12:
      cmpne(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 13:
      cmpge(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 14:
      cmpge(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 15:
      cmpeq(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 16:
      cmpeq(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 17:
      cmplt(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 18:
      cmple(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 19:
      cmpne(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 20:
      cmpne(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 21:
      cmpge(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 22:
      cmpgt(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 23:
      cmpeq(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 24:
      cmpeq(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 25:
      cmplt(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 26:
      cmple(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 27:
      cmpne(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 28:
      cmpne(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 29:
      cmpge(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 30:
      cmpgt(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 31:
      cmpeq(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    default:
      std::cerr << "Unimplemented" << std::endl;
      break;
    }
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s, p8 / Xbyak_aarch64::T_m,
          0xFFFFFFFF);
    not_(pTmp.b, p15 / Xbyak_aarch64::T_z, p8.b);
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_m, 0);
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s, p13 / Xbyak_aarch64::T_m, 0);
    xt_pop_preg();
  }
  if (false || (dstWidth == 256 && isMasking == 0 &&
                isMerging == XED_REG_CLASS_YMM && isSrc2 == XED_OPERAND_MEM0)) {
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    Xbyak_aarch64::ZReg zTmp = xt_push_zreg();
    ld1b(zTmp.s, pTmp / Xbyak_aarch64::T_m, Xbyak_aarch64::ptr(X_TMP_ADDR));
    mov__(pTmp.b, p15.b);
    switch (isIMM) {
    case 0:
      cmpeq(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 1:
      cmplt(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 2:
      cmple(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 3:
      cmpne(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src2Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 4:
      cmpne(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 5:
      cmpge(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 6:
      cmpgt(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 7:
      cmpeq(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 8:
      cmpeq(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 9:
      cmplt(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 10:
      cmple(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 11:
      cmpne(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 12:
      cmpne(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 13:
      cmpge(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 14:
      cmpge(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 15:
      cmpeq(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 16:
      cmpeq(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 17:
      cmplt(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 18:
      cmple(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 19:
      cmpne(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 20:
      cmpne(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 21:
      cmpge(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 22:
      cmpgt(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 23:
      cmpeq(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 24:
      cmpeq(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 25:
      cmplt(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 26:
      cmple(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 27:
      cmpne(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 28:
      cmpne(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 29:
      cmpge(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 30:
      cmpgt(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            zTmp.s);
      break;
    case 31:
      cmpeq(p8.s, pTmp / Xbyak_aarch64::T_z, Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    default:
      std::cerr << "Unimplemented" << std::endl;
      break;
    }
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s, p8 / Xbyak_aarch64::T_m,
          0xFFFFFFFF);
    not_(pTmp.b, p15 / Xbyak_aarch64::T_z, p8.b);
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_m, 0);
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s, p13 / Xbyak_aarch64::T_m, 0);
    xt_pop_preg();
    xt_pop_zreg();
  }
  if (false ||
      (dstWidth == 128 && isMasking == 0 && isMerging == XED_REG_CLASS_MASK &&
       isSrc2 == XED_OPERAND_REG2)) {
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(pTmp.b, p15.b);
    switch (isIMM) {
    case 0:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 1:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 2:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 3:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 4:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 5:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 6:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 7:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 8:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 9:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 10:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 11:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 12:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 13:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 14:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 15:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 16:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 17:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 18:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 19:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 20:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 21:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 22:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 23:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 24:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 25:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 26:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 27:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 28:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 29:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 30:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 31:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    default:
      std::cerr << "Unimplemented" << std::endl;
      break;
    }
    mov__(pTmp.b, p12.b);
    mov__(Xbyak_aarch64::PReg(a64_dstIdx).b, pTmp / Xbyak_aarch64::T_z,
          Xbyak_aarch64::PReg(a64_dstIdx).b);
    xt_pop_preg();
  }
  if (false ||
      (dstWidth == 128 && isMasking == 0 && isMerging == XED_REG_CLASS_MASK &&
       isSrc2 == XED_OPERAND_MEM0)) {
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    Xbyak_aarch64::ZReg zTmp = xt_push_zreg();
    mov__(pTmp.b, p15.b);
    ld1b(zTmp.s, pTmp / Xbyak_aarch64::T_m, Xbyak_aarch64::ptr(X_TMP_ADDR));
    switch (isIMM) {
    case 0:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 1:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 2:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 3:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 4:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 5:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 6:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 7:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 8:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 9:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 10:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 11:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 12:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 13:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 14:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 15:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 16:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 17:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 18:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 19:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 20:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 21:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 22:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 23:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 24:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 25:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 26:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 27:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 28:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 29:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 30:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 31:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    default:
      std::cerr << "Unimplemented" << std::endl;
      break;
    }
    mov__(pTmp.b, p12.b);
    mov__(Xbyak_aarch64::PReg(a64_dstIdx).b, pTmp / Xbyak_aarch64::T_z,
          Xbyak_aarch64::PReg(a64_dstIdx).b);
    xt_pop_preg();
    xt_pop_zreg();
  }
  if (false ||
      (dstWidth == 128 && isMasking == 0 && isMerging == XED_REG_CLASS_MASK &&
       isSrc2 == XED_OPERAND_BCAST)) {
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    Xbyak_aarch64::ZReg zTmp = xt_push_zreg();
    mov__(pTmp.b, p15.b);
    ld1rw__(zTmp.s, Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ptr(X_TMP_ADDR));
    switch (isIMM) {
    case 0:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 1:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 2:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 3:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 4:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 5:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 6:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 7:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 8:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 9:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 10:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 11:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 12:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 13:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 14:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 15:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 16:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 17:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 18:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 19:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 20:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 21:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 22:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 23:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 24:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 25:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 26:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 27:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 28:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 29:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 30:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 31:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    default:
      std::cerr << "Unimplemented" << std::endl;
      break;
    }
    mov__(pTmp.b, p12.b);
    mov__(Xbyak_aarch64::PReg(a64_dstIdx).b, pTmp / Xbyak_aarch64::T_z,
          Xbyak_aarch64::PReg(a64_dstIdx).b);
    xt_pop_preg();
    xt_pop_zreg();
  }
  if (false ||
      (dstWidth == 128 && isMasking == 1 && isMerging == XED_REG_CLASS_MASK &&
       isSrc2 == XED_OPERAND_REG2)) {
    switch (isIMM) {
    case 0:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 1:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 2:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 3:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 4:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 5:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 6:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 7:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 8:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 9:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 10:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 11:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 12:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 13:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 14:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 15:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 16:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 17:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 18:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 19:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 20:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 21:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 22:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 23:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 24:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 25:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 26:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 27:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 28:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 29:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 30:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 31:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    default:
      std::cerr << "Unimplemented" << std::endl;
      break;
    }
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(pTmp.b, p12.b);
    mov__(Xbyak_aarch64::PReg(a64_dstIdx).b, pTmp / Xbyak_aarch64::T_z,
          Xbyak_aarch64::PReg(a64_dstIdx).b);
    xt_pop_preg();
  }
  if (false ||
      (dstWidth == 128 && isMasking == 1 && isMerging == XED_REG_CLASS_MASK &&
       isSrc2 == XED_OPERAND_MEM0)) {
    Xbyak_aarch64::ZReg zTmp = xt_push_zreg();
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(pTmp.b, p15.b);
    ld1b(zTmp.s, pTmp / Xbyak_aarch64::T_m, Xbyak_aarch64::ptr(X_TMP_ADDR));
    switch (isIMM) {
    case 0:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 1:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 2:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 3:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 4:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 5:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 6:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 7:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 8:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 9:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 10:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 11:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 12:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 13:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 14:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 15:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 16:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 17:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 18:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 19:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 20:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 21:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 22:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 23:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 24:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 25:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 26:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 27:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 28:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 29:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 30:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 31:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    default:
      std::cerr << "Unimplemented" << std::endl;
      break;
    }
    mov__(pTmp.b, p12.b);
    mov__(Xbyak_aarch64::PReg(a64_dstIdx).b, pTmp / Xbyak_aarch64::T_z,
          Xbyak_aarch64::PReg(a64_dstIdx).b);
    xt_pop_preg();
    xt_pop_zreg();
  }
  if (false ||
      (dstWidth == 128 && isMasking == 1 && isMerging == XED_REG_CLASS_MASK &&
       isSrc2 == XED_OPERAND_BCAST)) {
    Xbyak_aarch64::ZReg zTmp = xt_push_zreg();
    ld1rw__(zTmp.s, Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ptr(X_TMP_ADDR));
    switch (isIMM) {
    case 0:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 1:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 2:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 3:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 4:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 5:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 6:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 7:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 8:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 9:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 10:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 11:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 12:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 13:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 14:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 15:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 16:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 17:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 18:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 19:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 20:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 21:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 22:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 23:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 24:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 25:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 26:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 27:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 28:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 29:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 30:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 31:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    default:
      std::cerr << "Unimplemented" << std::endl;
      break;
    }
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(pTmp.b, p12.b);
    mov__(Xbyak_aarch64::PReg(a64_dstIdx).b, pTmp / Xbyak_aarch64::T_z,
          Xbyak_aarch64::PReg(a64_dstIdx).b);
    xt_pop_preg();
    xt_pop_zreg();
  }
  if (false ||
      (dstWidth == 256 && isMasking == 0 && isMerging == XED_REG_CLASS_MASK &&
       isSrc2 == XED_OPERAND_REG2)) {
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(pTmp.b, p15.b);
    switch (isIMM) {
    case 0:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 1:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 2:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 3:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 4:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 5:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 6:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 7:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 8:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 9:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 10:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 11:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 12:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 13:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 14:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 15:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 16:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 17:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 18:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 19:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 20:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 21:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 22:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 23:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 24:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 25:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 26:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 27:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 28:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 29:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 30:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 31:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    default:
      std::cerr << "Unimplemented" << std::endl;
      break;
    }
    mov__(pTmp.b, p11.b);
    mov__(Xbyak_aarch64::PReg(a64_dstIdx).b, pTmp / Xbyak_aarch64::T_z,
          Xbyak_aarch64::PReg(a64_dstIdx).b);
    xt_pop_preg();
  }
  if (false ||
      (dstWidth == 256 && isMasking == 0 && isMerging == XED_REG_CLASS_MASK &&
       isSrc2 == XED_OPERAND_MEM0)) {
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    Xbyak_aarch64::ZReg zTmp = xt_push_zreg();
    mov__(pTmp.b, p15.b);
    ld1b(zTmp.s, pTmp / Xbyak_aarch64::T_m, Xbyak_aarch64::ptr(X_TMP_ADDR));
    switch (isIMM) {
    case 0:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 1:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 2:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 3:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 4:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 5:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 6:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 7:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 8:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 9:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 10:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 11:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 12:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 13:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 14:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 15:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 16:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 17:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 18:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 19:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 20:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 21:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 22:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 23:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 24:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 25:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 26:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 27:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 28:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 29:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 30:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 31:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    default:
      std::cerr << "Unimplemented" << std::endl;
      break;
    }
    mov__(pTmp.b, p11.b);
    mov__(Xbyak_aarch64::PReg(a64_dstIdx).b, pTmp / Xbyak_aarch64::T_z,
          Xbyak_aarch64::PReg(a64_dstIdx).b);
    xt_pop_preg();
    xt_pop_zreg();
  }
  if (false ||
      (dstWidth == 256 && isMasking == 0 && isMerging == XED_REG_CLASS_MASK &&
       isSrc2 == XED_OPERAND_BCAST)) {
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    Xbyak_aarch64::ZReg zTmp = xt_push_zreg();
    mov__(pTmp.b, p15.b);
    ld1rw__(zTmp.s, Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ptr(X_TMP_ADDR));
    switch (isIMM) {
    case 0:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 1:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 2:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 3:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 4:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 5:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 6:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 7:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 8:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 9:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 10:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 11:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 12:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 13:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 14:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 15:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 16:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 17:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 18:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 19:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 20:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 21:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 22:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 23:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 24:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 25:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 26:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 27:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 28:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 29:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 30:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 31:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    default:
      std::cerr << "Unimplemented" << std::endl;
      break;
    }
    mov__(pTmp.b, p11.b);
    mov__(Xbyak_aarch64::PReg(a64_dstIdx).b, pTmp / Xbyak_aarch64::T_z,
          Xbyak_aarch64::PReg(a64_dstIdx).b);
    xt_pop_preg();
    xt_pop_zreg();
  }
  if (false ||
      (dstWidth == 256 && isMasking == 1 && isMerging == XED_REG_CLASS_MASK &&
       isSrc2 == XED_OPERAND_REG2)) {
    switch (isIMM) {
    case 0:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 1:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 2:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 3:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 4:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 5:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 6:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 7:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 8:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 9:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 10:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 11:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 12:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 13:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 14:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 15:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 16:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 17:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 18:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 19:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 20:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 21:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 22:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 23:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 24:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 25:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 26:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 27:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 28:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 29:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 30:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 31:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    default:
      std::cerr << "Unimplemented" << std::endl;
      break;
    }
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(pTmp.b, p11.b);
    mov__(Xbyak_aarch64::PReg(a64_dstIdx).b, pTmp / Xbyak_aarch64::T_z,
          Xbyak_aarch64::PReg(a64_dstIdx).b);
    xt_pop_preg();
  }
  if (false ||
      (dstWidth == 256 && isMasking == 1 && isMerging == XED_REG_CLASS_MASK &&
       isSrc2 == XED_OPERAND_MEM0)) {
    Xbyak_aarch64::ZReg zTmp = xt_push_zreg();
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(pTmp.b, p15.b);
    ld1b(zTmp.s, pTmp / Xbyak_aarch64::T_m, Xbyak_aarch64::ptr(X_TMP_ADDR));
    switch (isIMM) {
    case 0:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 1:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 2:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 3:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 4:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 5:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 6:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 7:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 8:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 9:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 10:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 11:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 12:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 13:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 14:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 15:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 16:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 17:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 18:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 19:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 20:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 21:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 22:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 23:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 24:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 25:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 26:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 27:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 28:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 29:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 30:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 31:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    default:
      std::cerr << "Unimplemented" << std::endl;
      break;
    }
    mov__(pTmp.b, p11.b);
    mov__(Xbyak_aarch64::PReg(a64_dstIdx).b, pTmp / Xbyak_aarch64::T_z,
          Xbyak_aarch64::PReg(a64_dstIdx).b);
    xt_pop_preg();
    xt_pop_zreg();
  }
  if (false ||
      (dstWidth == 256 && isMasking == 1 && isMerging == XED_REG_CLASS_MASK &&
       isSrc2 == XED_OPERAND_BCAST)) {
    Xbyak_aarch64::ZReg zTmp = xt_push_zreg();
    ld1rw__(zTmp.s, Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ptr(X_TMP_ADDR));
    switch (isIMM) {
    case 0:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 1:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 2:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 3:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 4:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 5:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 6:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 7:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 8:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 9:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 10:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 11:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 12:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 13:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 14:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 15:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 16:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 17:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 18:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 19:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 20:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 21:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 22:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 23:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 24:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 25:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 26:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 27:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 28:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 29:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 30:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 31:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    default:
      std::cerr << "Unimplemented" << std::endl;
      break;
    }
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(pTmp.b, p11.b);
    mov__(Xbyak_aarch64::PReg(a64_dstIdx).b, pTmp / Xbyak_aarch64::T_z,
          Xbyak_aarch64::PReg(a64_dstIdx).b);
    xt_pop_preg();
    xt_pop_zreg();
  }
  if (false ||
      (dstWidth == 512 && isMasking == 0 && isMerging == XED_REG_CLASS_MASK &&
       isSrc2 == XED_OPERAND_REG2)) {
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(pTmp.b, p15.b);
    switch (isIMM) {
    case 0:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 1:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 2:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 3:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 4:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 5:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 6:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 7:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 8:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 9:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 10:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 11:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 12:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 13:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 14:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 15:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 16:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 17:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 18:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 19:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 20:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 21:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 22:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 23:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 24:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 25:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 26:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 27:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 28:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 29:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 30:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 31:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    default:
      std::cerr << "Unimplemented" << std::endl;
      break;
    }
    xt_pop_preg();
  }
  if (false ||
      (dstWidth == 512 && isMasking == 0 && isMerging == XED_REG_CLASS_MASK &&
       isSrc2 == XED_OPERAND_MEM0)) {
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    Xbyak_aarch64::ZReg zTmp = xt_push_zreg();
    mov__(pTmp.b, p15.b);
    ld1b(zTmp.s, pTmp / Xbyak_aarch64::T_m, Xbyak_aarch64::ptr(X_TMP_ADDR));
    switch (isIMM) {
    case 0:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 1:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 2:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 3:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 4:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 5:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 6:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 7:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 8:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 9:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 10:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 11:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 12:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 13:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 14:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 15:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 16:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 17:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 18:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 19:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 20:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 21:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 22:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 23:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 24:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 25:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 26:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 27:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 28:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 29:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 30:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 31:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    default:
      std::cerr << "Unimplemented" << std::endl;
      break;
    }
    xt_pop_preg();
    xt_pop_zreg();
  }
  if (false ||
      (dstWidth == 512 && isMasking == 0 && isMerging == XED_REG_CLASS_MASK &&
       isSrc2 == XED_OPERAND_BCAST)) {
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    Xbyak_aarch64::ZReg zTmp = xt_push_zreg();
    mov__(pTmp.b, p15.b);
    ld1rw__(zTmp.s, Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ptr(X_TMP_ADDR));
    switch (isIMM) {
    case 0:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 1:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 2:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 3:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 4:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 5:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 6:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 7:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 8:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 9:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 10:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 11:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 12:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 13:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 14:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 15:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 16:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 17:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 18:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 19:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 20:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 21:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 22:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 23:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 24:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 25:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 26:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 27:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 28:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 29:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 30:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 31:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    default:
      std::cerr << "Unimplemented" << std::endl;
      break;
    }
    xt_pop_preg();
    xt_pop_zreg();
  }
  if (false ||
      (dstWidth == 512 && isMasking == 1 && isMerging == XED_REG_CLASS_MASK &&
       isSrc2 == XED_OPERAND_REG2)) {
    switch (isIMM) {
    case 0:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 1:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 2:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 3:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 4:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 5:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 6:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 7:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 8:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 9:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 10:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 11:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 12:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 13:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 14:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 15:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 16:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 17:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 18:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 19:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 20:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 21:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 22:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 23:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 24:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 25:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 26:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 27:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 28:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 29:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 30:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src2Idx).s);
      break;
    case 31:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    default:
      std::cerr << "Unimplemented" << std::endl;
      break;
    }
  }
  if (false ||
      (dstWidth == 512 && isMasking == 1 && isMerging == XED_REG_CLASS_MASK &&
       isSrc2 == XED_OPERAND_MEM0)) {
    Xbyak_aarch64::ZReg zTmp = xt_push_zreg();
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(pTmp.b, p15.b);
    ld1b(zTmp.s, pTmp / Xbyak_aarch64::T_m, Xbyak_aarch64::ptr(X_TMP_ADDR));
    switch (isIMM) {
    case 0:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 1:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 2:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 3:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 4:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 5:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 6:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 7:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 8:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 9:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 10:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 11:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 12:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 13:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 14:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 15:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 16:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 17:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 18:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 19:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 20:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 21:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 22:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 23:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 24:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 25:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 26:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 27:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 28:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 29:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 30:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 31:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    default:
      std::cerr << "Unimplemented" << std::endl;
      break;
    }
    xt_pop_zreg();
    xt_pop_preg();
  }
  if (false ||
      (dstWidth == 512 && isMasking == 1 && isMerging == XED_REG_CLASS_MASK &&
       isSrc2 == XED_OPERAND_BCAST)) {
    Xbyak_aarch64::ZReg zTmp = xt_push_zreg();
    ld1rw__(zTmp.s, Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ptr(X_TMP_ADDR));
    switch (isIMM) {
    case 0:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 1:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 2:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 3:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 4:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 5:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 6:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 7:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 8:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 9:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 10:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 11:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 12:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 13:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 14:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 15:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 16:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 17:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 18:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 19:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 20:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 21:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 22:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 23:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 24:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 25:
      cmplt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 26:
      cmple(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 27:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    case 28:
      cmpne(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 29:
      cmpge(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 30:
      cmpgt(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s, zTmp.s);
      break;
    case 31:
      cmpeq(Xbyak_aarch64::PReg(a64_dstIdx).s,
            Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_z,
            Xbyak_aarch64::ZReg(a64_src1Idx).s,
            Xbyak_aarch64::ZReg(a64_src1Idx).s);
      break;
    default:
      std::cerr << "Unimplemented" << std::endl;
      break;
    }
    xt_pop_zreg();
    xt_pop_preg();
  }
}