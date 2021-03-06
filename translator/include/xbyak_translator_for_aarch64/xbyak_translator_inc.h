/*******************************************************************************
 * Copyright 2020 FUJITSU LIMITED
 *
 * Licensed under the Apache License, Version 2.0 (the ""License"");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an ""AS IS"" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *******************************************************************************/
#include "instructions/adc.h"
#include "instructions/add.h"
#include "instructions/addps.h"
#include "instructions/addss.h"
#include "instructions/and.h"
#include "instructions/blendvps.h"
#include "instructions/cmovnle.h"
#include "instructions/cmp.h"
#include "instructions/cmpps.h"
#include "instructions/dec.h"
#include "instructions/imul.h"
#include "instructions/inc.h"
#include "instructions/kmovd.h"
#include "instructions/kmovq.h"
#include "instructions/kmovw.h"
#include "instructions/kortestw.h"
#include "instructions/ktestq.h"
#include "instructions/lea.h"
#include "instructions/mov.h"
#include "instructions/movaps.h"
#include "instructions/movd.h"
#include "instructions/movdqa.h"
#include "instructions/movdqu.h"
#include "instructions/movhlps.h"
#include "instructions/movq.h"
#include "instructions/movsd.h"
#include "instructions/movss.h"
#include "instructions/movups.h"
#include "instructions/mulps.h"
#include "instructions/mulss.h"
#include "instructions/not.h"
#include "instructions/or.h"
#include "instructions/paddd.h"
#include "instructions/pause.h"
#include "instructions/pextrd.h"
#include "instructions/phaddw.h"
#include "instructions/pinsrb.h"
#include "instructions/pinsrd.h"
#include "instructions/pinsrw.h"
#include "instructions/pmovsxbd.h"
#include "instructions/pmovsxbw.h"
#include "instructions/pmovsxwd.h"
#include "instructions/pmovzxbd.h"
#include "instructions/pmovzxbw.h"
#include "instructions/pmovzxwd.h"
#include "instructions/prefetcht0.h"
#include "instructions/prefetcht1.h"
#include "instructions/prefetcht2.h"
#include "instructions/prefetchw.h"
#include "instructions/pshufd.h"
#include "instructions/punpckhbw.h"
#include "instructions/punpckhdq.h"
#include "instructions/punpckhqdq.h"
#include "instructions/punpckhwd.h"
#include "instructions/punpcklbw.h"
#include "instructions/punpckldq.h"
#include "instructions/punpcklqdq.h"
#include "instructions/punpcklwd.h"
#include "instructions/pxor.h"
#include "instructions/ret.h"
#include "instructions/sar.h"
#include "instructions/shl.h"
#include "instructions/shlx.h"
#include "instructions/shr.h"
#include "instructions/shufps.h"
#include "instructions/sub.h"
#include "instructions/test.h"
#include "instructions/vaddps.h"
#include "instructions/vaddss.h"
#include "instructions/vandps.h"
#include "instructions/vblendmps.h"
#include "instructions/vblendvps.h"
#include "instructions/vbroadcastf32x4.h"
#include "instructions/vbroadcastf64x4.h"
#include "instructions/vbroadcasti32x4.h"
#include "instructions/vbroadcasti64x4.h"
#include "instructions/vbroadcastsd.h"
#include "instructions/vbroadcastss.h"
#include "instructions/vcmpps.h"
#include "instructions/vcvtdq2ps.h"
#include "instructions/vcvtps2dq.h"
#include "instructions/vdivps.h"
#include "instructions/vextractf64x4.h"
#include "instructions/vextracti32x8.h"
#include "instructions/vfixupimmps.h"
#include "instructions/vfmadd132ps.h"
#include "instructions/vfmadd213ps.h"
#include "instructions/vfmadd231ps.h"
#include "instructions/vfnmadd231ps.h"
#include "instructions/vgatherqps.h"
#include "instructions/vinsertf128.h"
#include "instructions/vinsertf64x4.h"
#include "instructions/vinserti32x4.h"
#include "instructions/vinserti64x4.h"
#include "instructions/vmaskmovps.h"
#include "instructions/vmaxps.h"
#include "instructions/vminps.h"
#include "instructions/vmovaps.h"
#include "instructions/vmovd.h"
#include "instructions/vmovdqu.h"
#include "instructions/vmovdqu16.h"
#include "instructions/vmovdqu32.h"
#include "instructions/vmovdqu8.h"
#include "instructions/vmovhlps.h"
#include "instructions/vmovhps.h"
#include "instructions/vmovlps.h"
#include "instructions/vmovmskps.h"
#include "instructions/vmovntps.h"
#include "instructions/vmovq.h"
#include "instructions/vmovsd.h"
#include "instructions/vmovss.h"
#include "instructions/vmovups.h"
#include "instructions/vmulps.h"
#include "instructions/vorps.h"
#include "instructions/vpaddb.h"
#include "instructions/vpaddd.h"
#include "instructions/vpaddq.h"
#include "instructions/vpandd.h"
#include "instructions/vpblendmb.h"
#include "instructions/vpblendmd.h"
#include "instructions/vpbroadcastb.h"
#include "instructions/vpbroadcastd.h"
#include "instructions/vpbroadcastq.h"
#include "instructions/vpbroadcastw.h"
#include "instructions/vpcmpb.h"
#include "instructions/vpcmpd.h"
#include "instructions/vpcmpeqb.h"
#include "instructions/vpcmpeqd.h"
#include "instructions/vpcmpub.h"
#include "instructions/vpdpbusd.h"
#include "instructions/vperm2f128.h"
#include "instructions/vperm2i128.h"
#include "instructions/vpermd.h"
#include "instructions/vpermilpd.h"
#include "instructions/vpermilps.h"
#include "instructions/vpermw.h"
#include "instructions/vpextrb.h"
#include "instructions/vphaddd.h"
#include "instructions/vphaddw.h"
#include "instructions/vpinsrb.h"
#include "instructions/vpinsrq.h"
#include "instructions/vpinsrw.h"
#include "instructions/vpmaddubsw.h"
#include "instructions/vpmaddwd.h"
#include "instructions/vpmaxsb.h"
#include "instructions/vpmaxsd.h"
#include "instructions/vpminub.h"
#include "instructions/vpmovdb.h"
#include "instructions/vpmovdw.h"
#include "instructions/vpmovsdb.h"
#include "instructions/vpmovsxbd.h"
#include "instructions/vpmovsxbw.h"
#include "instructions/vpmovsxwd.h"
#include "instructions/vpmovusdb.h"
#include "instructions/vpmovzxbd.h"
#include "instructions/vpmovzxwd.h"
#include "instructions/vpord.h"
#include "instructions/vpshufb.h"
#include "instructions/vpshufd.h"
#include "instructions/vpsignd.h"
#include "instructions/vpslld.h"
#include "instructions/vpsrad.h"
#include "instructions/vpsrld.h"
#include "instructions/vpsubb.h"
#include "instructions/vptestmd.h"
#include "instructions/vpunpckhbw.h"
#include "instructions/vpunpckhqdq.h"
#include "instructions/vpunpckhwd.h"
#include "instructions/vpunpcklbw.h"
#include "instructions/vpunpckldq.h"
#include "instructions/vpunpcklqdq.h"
#include "instructions/vpunpcklwd.h"
#include "instructions/vpxor.h"
#include "instructions/vpxord.h"
#include "instructions/vpxorq.h"
#include "instructions/vrndscaleps.h"
#include "instructions/vroundps.h"
#include "instructions/vshuff32x4.h"
#include "instructions/vshuff64x2.h"
#include "instructions/vshufi32x4.h"
#include "instructions/vshufpd.h"
#include "instructions/vshufps.h"
#include "instructions/vsqrtps.h"
#include "instructions/vsubps.h"
#include "instructions/vtestps.h"
#include "instructions/vucomiss.h"
#include "instructions/vunpckhpd.h"
#include "instructions/vunpckhps.h"
#include "instructions/vunpcklpd.h"
#include "instructions/vunpcklps.h"
#include "instructions/vxorps.h"
#include "instructions/vzeroupper.h"
#include "instructions/xadd_lock.h"
#include "instructions/xchg.h"
#include "instructions/xor.h"
#include "instructions/xorps.h"

#if 0
#include "instructions/kmovb.h"
#include "instructions/kortestb.h"
#include "instructions/kortestd.h"
#include "instructions/kortestq.h"
#endif
