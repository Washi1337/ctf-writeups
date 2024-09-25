// --- VM start prologue / init registers ---
L1678f: pop64 r0    // rflags
L16794: pop64 r1    // rax
L16799: pop64 r2    // rbx
L1679e: pop64 r3    // rcx      <-- input
L167a3: pop64 r4    // rdx
L167a8: pop64 r5    // rsi
L167ad: pop64 r6    // rdi
L167b2: pop64 r7    // rbp      <-- base pointer
L167b7: pop64 r8    // r8
L167bc: pop64 r9    // r9
L167c1: pop64 r10   // r10
L167c6: pop64 r11   // r11
L167cb: pop64 r12   // r12
L167d0: pop64 r13   // r13
L167d5: pop64 r14   // r14
L167da: pop64 r15   // r15
L167df: pop64 r16   // return addr?

// --- Function prologue ---

// push bp
L167e4: push64 r7   

// mov bp, sp 
L167e9: push sp           
L167ed: pop64 r7

// sub sp, 0x10         // 0x10 bytes local space
L167f2: push sp     
L167f6: push64 0x10
L16802: sub64 
L16806: pop64 r0
L1680b: pop sp

// --- Actual code ---

// bp[0x10]  = r3       (input)
L1680f: push64 r7  
L16814: push64 0x0
L16820: push64 0x10
L1682c: add64 
L16830: pop64 r16
L16835: add64 
L16839: pop64 r16
L1683e: pop64 r16
L16843: push32 r3
L16848: push64 r16
L1684d: store32 

// bp[-0x8] = 0x77259243
L16851: push64 r7
L16856: push64 0x0
L16862: push64 0xfffffffffffffff8
L1686e: add64 
L16872: pop64 r16
L16877: add64 
L1687b: pop64 r16
L16880: pop64 r16
L16885: push32 0x77259243
L1688d: push64 r16
L16892: store32 

// bp[-0x8] = bp[-0x8] | 0x23
L16896: push64 r7
L1689b: push64 0x0
L168a7: push64 0xfffffffffffffff8
L168b3: add64 
L168b7: pop64 r16
L168bc: add64 
L168c0: pop64 r16
L168c5: push sp
L168c9: load64 
L168cd: pop64 r16
L168d2: load32 
L168d6: push32 0x23
L168de: or32 
L168e2: pop64 r0
L168e7: push64 r16
L168ec: store32 

// bp[-0x8] = bp[-0x8] & 0x23
L168f0: push64 r7
L168f5: push64 0x0
L16901: push64 0xfffffffffffffff8
L1690d: add64 
L16911: pop64 r16
L16916: add64 
L1691a: pop64 r16
L1691f: push sp
L16923: load64 
L16927: pop64 r16
L1692c: load32 
L16930: push32 0x23
L16938: and32 
L1693c: pop64 r0
L16941: push64 r16
L16946: store32 

// bp[-0x8] = bp[-0x8] + 0x843
L1694a: push64 r7
L1694f: push64 0x0
L1695b: push64 0xfffffffffffffff8
L16967: add64 
L1696b: pop64 r16
L16970: add64 
L16974: pop64 r16
L16979: push sp
L1697d: load64 
L16981: pop64 r16
L16986: load32 
L1698a: push32 0x843
L16992: add32 
L16996: pop64 r0
L1699b: push64 r16
L169a0: store32 

// bp[-0x8] = bp[-0x8] & 0x5466
L169a4: push64 r7
L169a9: push64 0x0
L169b5: push64 0xfffffffffffffff8
L169c1: add64 
L169c5: pop64 r16
L169ca: add64 
L169ce: pop64 r16
L169d3: push sp
L169d7: load64 
L169db: pop64 r16
L169e0: load32 
L169e4: push32 0x5466
L169ec: and32 
L169f0: pop64 r0
L169f5: push64 r16
L169fa: store32 

// bp[-0x8] = bp[-0x8] + 0x843
L169fe: push64 r7
L16a03: push64 0x0
L16a0f: push64 0xfffffffffffffff8
L16a1b: add64 
L16a1f: pop64 r16
L16a24: add64 
L16a28: pop64 r16
L16a2d: push sp
L16a31: load64 
L16a35: pop64 r16
L16a3a: load32 
L16a3e: push32 0x843
L16a46: add32 
L16a4a: pop64 r0
L16a4f: push64 r16
L16a54: store32 

// bp[-0x8] = bp[-0x8] | 0x234
L16a58: push64 r7
L16a5d: push64 0x0
L16a69: push64 0xfffffffffffffff8
L16a75: add64 
L16a79: pop64 r16
L16a7e: add64 
L16a82: pop64 r16
L16a87: push sp
L16a8b: load64 
L16a8f: pop64 r16
L16a94: load32 
L16a98: push32 0x234
L16aa0: or32 
L16aa4: pop64 r0
L16aa9: push64 r16
L16aae: store32 

// bp[-0x4] = 0
L16ab2: push64 r7
L16ab7: push64 0x0
L16ac3: push64 0xfffffffffffffffc
L16acf: add64 
L16ad3: pop64 r16
L16ad8: add64 
L16adc: pop64 r16
L16ae1: pop64 r16
L16ae6: push32 0x0
L16aee: push64 r16
L16af3: store32 

// bp[-0x8] = bp[-0x8] + 0x63654
L16af7: push64 r7
L16afc: push64 0x0
L16b08: push64 0xfffffffffffffff8
L16b14: add64 
L16b18: pop64 r16
L16b1d: add64 
L16b21: pop64 r16
L16b26: push sp
L16b2a: load64 
L16b2e: pop64 r16
L16b33: load32 
L16b37: push32 0x63654
L16b3f: add32 
L16b43: pop64 r0
L16b48: push64 r16
L16b4d: store32 

// bp[-0x8] = bp[-0x8] & 0x4545
L16b51: push64 r7
L16b56: push64 0x0
L16b62: push64 0xfffffffffffffff8
L16b6e: add64 
L16b72: pop64 r16
L16b77: add64 
L16b7b: pop64 r16
L16b80: push sp
L16b84: load64 
L16b88: pop64 r16
L16b8d: load32 
L16b91: push32 0x4545
L16b99: and32 
L16b9d: pop64 r0
L16ba2: push64 r16
L16ba7: store32 

// bp[-0x8] = bp[-0x8] | 0x65466
L16bab: push64 r7
L16bb0: push64 0x0
L16bbc: push64 0xfffffffffffffff8
L16bc8: add64 
L16bcc: pop64 r16
L16bd1: add64 
L16bd5: pop64 r16
L16bda: push sp
L16bde: load64 
L16be2: pop64 r16
L16be7: load32 
L16beb: push32 0x65466
L16bf3: or32 
L16bf7: pop64 r0
L16bfc: push64 r16
L16c01: store32 

// bp[-0x8] = bp[-0x8] - 0x5234
L16c05: push64 r7
L16c0a: push64 0x0
L16c16: push64 0xfffffffffffffff8
L16c22: add64 
L16c26: pop64 r16
L16c2b: add64 
L16c2f: pop64 r16
L16c34: push sp
L16c38: load64 
L16c3c: pop64 r16
L16c41: load32 
L16c45: push32 0x5234
L16c4d: sub32 
L16c51: pop64 r0
L16c56: push64 r16
L16c5b: store32 

// bp[-0x8] = bp[-0x8] - 0x863
L16c5f: push64 r7
L16c64: push64 0x0
L16c70: push64 0xfffffffffffffff8
L16c7c: add64 
L16c80: pop64 r16
L16c85: add64 
L16c89: pop64 r16
L16c8e: push sp
L16c92: load64 
L16c96: pop64 r16
L16c9b: load32 
L16c9f: push32 0x863
L16ca7: sub32 
L16cab: pop64 r0
L16cb0: push64 r16
L16cb5: store32 

// bp[-0x8] = bp[-0x8] ^ 0x7
L16cb9: push64 r7
L16cbe: push64 0x0
L16cca: push64 0xfffffffffffffff8
L16cd6: add64 
L16cda: pop64 r16
L16cdf: add64 
L16ce3: pop64 r16
L16ce8: push sp
L16cec: load64 
L16cf0: pop64 r16
L16cf5: load32 
L16cf9: push32 0x7
L16d01: xor32 
L16d05: pop64 r0
L16d0a: push64 r16
L16d0f: store32 

// if (bp[0x10] != 0x743) goto L16dbb
L16d13: push64 r7
L16d18: push64 0x0
L16d24: push64 0x10
L16d30: add64 
L16d34: pop64 r16
L16d39: add64 
L16d3d: pop64 r16
L16d42: push sp
L16d46: load64 
L16d4a: pop64 r16
L16d4f: load32 
L16d53: push32 0x743
L16d5b: sub32 
L16d5f: pop64 r0
L16d64: pop32 r16
L16d69: push64 r0
L16d6e: jnz L16dbb

// {
// bp[-0x4] = 1
L16d76: push64 r7
L16d7b: push64 0x0
L16d87: push64 0xfffffffffffffffc
L16d93: add64 
L16d97: pop64 r16
L16d9c: add64 
L16da0: pop64 r16
L16da5: pop64 r16
L16daa: push32 0x1
L16db2: push64 r16
L16db7: store32 

// } 
// L16dbb:
// bp[-0x8] = bp[-0x8] + 0x65363
L16dbb: push64 r7
L16dc0: push64 0x0
L16dcc: push64 0xfffffffffffffff8
L16dd8: add64 
L16ddc: pop64 r16
L16de1: add64 
L16de5: pop64 r16
L16dea: push sp
L16dee: load64 
L16df2: pop64 r16
L16df7: load32 
L16dfb: push32 0x65363
L16e03: add32 
L16e07: pop64 r0
L16e0c: push64 r16
L16e11: store32 

// bp[-0x8] = bp[-0x8] & 0x75454
L16e15: push64 r7
L16e1a: push64 0x0
L16e26: push64 0xfffffffffffffff8
L16e32: add64 
L16e36: pop64 r16
L16e3b: add64 
L16e3f: pop64 r16
L16e44: push sp
L16e48: load64 
L16e4c: pop64 r16
L16e51: load32 
L16e55: push32 0x75454
L16e5d: and32 
L16e61: pop64 r0
L16e66: push64 r16
L16e6b: store32 

// bp[-0x8] = bp[-0x8] | 0x754
L16e6f: push64 r7
L16e74: push64 0x0
L16e80: push64 0xfffffffffffffff8
L16e8c: add64 
L16e90: pop64 r16
L16e95: add64 
L16e99: pop64 r16
L16e9e: push sp
L16ea2: load64 
L16ea6: pop64 r16
L16eab: load32 
L16eaf: push32 0x754
L16eb7: or32 
L16ebb: pop64 r0
L16ec0: push64 r16
L16ec5: store32 

// bp[-0x8] = bp[-0x8] + 1
L16ec9: push64 r7
L16ece: push64 0x0
L16eda: push64 0xfffffffffffffff8
L16ee6: add64 
L16eea: pop64 r16
L16eef: add64 
L16ef3: pop64 r16
L16ef8: push sp
L16efc: load64 
L16f00: pop64 r16
L16f05: load32 
L16f09: push32 0x1
L16f11: add32 
L16f15: pop64 r0
L16f1a: push64 r16
L16f1f: store32 

// bp[-0x8] = bp[-0x8] - 1
L16f23: push64 r7
L16f28: push64 0x0
L16f34: push64 0xfffffffffffffff8
L16f40: add64 
L16f44: pop64 r16
L16f49: add64 
L16f4d: pop64 r16
L16f52: push sp
L16f56: load64 
L16f5a: pop64 r16
L16f5f: load32 
L16f63: push32 0x1
L16f6b: sub32 
L16f6f: pop64 r0
L16f74: push64 r16
L16f79: store32 

// bp[-0x8] = bp[-0x8] + 0x711
L16f7d: push64 r7
L16f82: push64 0x0
L16f8e: push64 0xfffffffffffffff8
L16f9a: add64 
L16f9e: pop64 r16
L16fa3: add64 
L16fa7: pop64 r16
L16fac: push sp
L16fb0: load64 
L16fb4: pop64 r16
L16fb9: load32 
L16fbd: push32 0x711
L16fc5: add32 
L16fc9: pop64 r0
L16fce: push64 r16
L16fd3: store32 

// if (bp[0x10] != 0x972) goto L1707f
L16fd7: push64 r7
L16fdc: push64 0x0
L16fe8: push64 0x10
L16ff4: add64 
L16ff8: pop64 r16
L16ffd: add64 
L17001: pop64 r16
L17006: push sp
L1700a: load64 
L1700e: pop64 r16
L17013: load32 
L17017: push32 0x972
L1701f: sub32 
L17023: pop64 r0
L17028: pop32 r16
L1702d: push64 r0
L17032: jnz L1707f

// {
// bp[-0x4] = 1
L1703a: push64 r7
L1703f: push64 0x0
L1704b: push64 0xfffffffffffffffc
L17057: add64 
L1705b: pop64 r16
L17060: add64 
L17064: pop64 r16
L17069: pop64 r16
L1706e: push32 0x1
L17076: push64 r16
L1707b: store32 

// }
// L1707f:
// bp[-0x8] = bp[-0x8] + 0x3643
L1707f: push64 r7
L17084: push64 0x0
L17090: push64 0xfffffffffffffff8
L1709c: add64 
L170a0: pop64 r16
L170a5: add64 
L170a9: pop64 r16
L170ae: push sp
L170b2: load64 
L170b6: pop64 r16
L170bb: load32 
L170bf: push32 0x3643
L170c7: add32 
L170cb: pop64 r0
L170d0: push64 r16
L170d5: store32 

// bp[-0x8] = bp[-0x8] + 0x54
L170d9: push64 r7
L170de: push64 0x0
L170ea: push64 0xfffffffffffffff8
L170f6: add64 
L170fa: pop64 r16
L170ff: add64 
L17103: pop64 r16
L17108: push sp
L1710c: load64 
L17110: pop64 r16
L17115: load32 
L17119: push32 0x54
L17121: add32 
L17125: pop64 r0
L1712a: push64 r16
L1712f: store32 

// bp[-0x8] = bp[-0x8] | 0x54
L17133: push64 r7
L17138: push64 0x0
L17144: push64 0xfffffffffffffff8
L17150: add64 
L17154: pop64 r16
L17159: add64 
L1715d: pop64 r16
L17162: push sp
L17166: load64 
L1716a: pop64 r16
L1716f: load32 
L17173: push32 0x54
L1717b: or32 
L1717f: pop64 r0
L17184: push64 r16
L17189: store32 

// bp[-0x8] = bp[-0x8] | 0x331
L1718d: push64 r7
L17192: push64 0x0
L1719e: push64 0xfffffffffffffff8
L171aa: add64 
L171ae: pop64 r16
L171b3: add64 
L171b7: pop64 r16
L171bc: push sp
L171c0: load64 
L171c4: pop64 r16
L171c9: load32 
L171cd: push32 0x331
L171d5: or32 
L171d9: pop64 r0
L171de: push64 r16
L171e3: store32 

// bp[-0x8] = bp[-0x8] | 0x12
L171e7: push64 r7
L171ec: push64 0x0
L171f8: push64 0xfffffffffffffff8
L17204: add64 
L17208: pop64 r16
L1720d: add64 
L17211: pop64 r16
L17216: push sp
L1721a: load64 
L1721e: pop64 r16
L17223: load32 
L17227: push32 0x12
L1722f: or32 
L17233: pop64 r0
L17238: push64 r16
L1723d: store32 

// bp[-0x8] = bp[-0x8] + 0x321
L17241: push64 r7
L17246: push64 0x0
L17252: push64 0xfffffffffffffff8
L1725e: add64 
L17262: pop64 r16
L17267: add64 
L1726b: pop64 r16
L17270: push sp
L17274: load64 
L17278: pop64 r16
L1727d: load32 
L17281: push32 0x321
L17289: add32 
L1728d: pop64 r0
L17292: push64 r16
L17297: store32 

// if (bp[0x10] != 0x666) goto L17343
L1729b: push64 r7
L172a0: push64 0x0
L172ac: push64 0x10
L172b8: add64 
L172bc: pop64 r16
L172c1: add64 
L172c5: pop64 r16
L172ca: push sp
L172ce: load64 
L172d2: pop64 r16
L172d7: load32 
L172db: push32 0x666
L172e3: sub32 
L172e7: pop64 r0
L172ec: pop32 r16
L172f1: push64 r0
L172f6: jnz L17343

// {
// bp[-0x4] = 1
L172fe: push64 r7
L17303: push64 0x0
L1730f: push64 0xfffffffffffffffc
L1731b: add64 
L1731f: pop64 r16
L17324: add64 
L17328: pop64 r16
L1732d: pop64 r16
L17332: push32 0x1
L1733a: push64 r16
L1733f: store32 
// }
// L17343:
// bp[-0x8] = bp[-0x8] - 0x97
L17343: push64 r7
L17348: push64 0x0
L17354: push64 0xfffffffffffffff8
L17360: add64 
L17364: pop64 r16
L17369: add64 
L1736d: pop64 r16
L17372: push sp
L17376: load64 
L1737a: pop64 r16
L1737f: load32 
L17383: push32 0x97
L1738b: sub32 
L1738f: pop64 r0
L17394: push64 r16
L17399: store32 

// bp[-0x8] = bp[-0x8] + 0x744
L1739d: push64 r7
L173a2: push64 0x0
L173ae: push64 0xfffffffffffffff8
L173ba: add64 
L173be: pop64 r16
L173c3: add64 
L173c7: pop64 r16
L173cc: push sp
L173d0: load64 
L173d4: pop64 r16
L173d9: load32 
L173dd: push32 0x744
L173e5: add32 
L173e9: pop64 r0
L173ee: push64 r16
L173f3: store32 

// bp[-0x8] = bp[-0x8] | 0x54
L173f7: push64 r7
L173fc: push64 0x0
L17408: push64 0xfffffffffffffff8
L17414: add64 
L17418: pop64 r16
L1741d: add64 
L17421: pop64 r16
L17426: push sp
L1742a: load64 
L1742e: pop64 r16
L17433: load32 
L17437: push32 0x54
L1743f: or32 
L17443: pop64 r0
L17448: push64 r16
L1744d: store32 

// bp[-0x8] = bp[-0x8] - 0x82
L17451: push64 r7
L17456: push64 0x0
L17462: push64 0xfffffffffffffff8
L1746e: add64 
L17472: pop64 r16
L17477: add64 
L1747b: pop64 r16
L17480: push sp
L17484: load64 
L17488: pop64 r16
L1748d: load32 
L17491: push32 0x82
L17499: sub32 
L1749d: pop64 r0
L174a2: push64 r16
L174a7: store32 

// bp[-0x8] = bp[-0x8] | 0x12
L174ab: push64 r7
L174b0: push64 0x0
L174bc: push64 0xfffffffffffffff8
L174c8: add64 
L174cc: pop64 r16
L174d1: add64 
L174d5: pop64 r16
L174da: push sp
L174de: load64 
L174e2: pop64 r16
L174e7: load32 
L174eb: push32 0x12
L174f3: or32 
L174f7: pop64 r0
L174fc: push64 r16
L17501: store32 

// bp[-0x8] = bp[-0x8] + 0x223
L17505: push64 r7
L1750a: push64 0x0
L17516: push64 0xfffffffffffffff8
L17522: add64 
L17526: pop64 r16
L1752b: add64 
L1752f: pop64 r16
L17534: push sp
L17538: load64 
L1753c: pop64 r16
L17541: load32 
L17545: push32 0x223
L1754d: add32 
L17551: pop64 r0
L17556: push64 r16
L1755b: store32 

// if (bp[0x10] != bp[-0x8]) goto L17640;
L1755f: push64 r7
L17564: push64 0x0
L17570: push64 0x10
L1757c: add64 
L17580: pop64 r16
L17585: add64 
L17589: pop64 r16
L1758e: push64 0x0
L1759a: pop64 r1
L1759f: load32 
L175a3: pop32 r1
L175a8: push64 r7
L175ad: push64 0x0
L175b9: push64 0xfffffffffffffff8
L175c5: add64 
L175c9: pop64 r16
L175ce: add64 
L175d2: pop64 r16
L175d7: load32 
L175db: push32 r1
L175e0: sub32 
L175e4: pop64 r0
L175e9: pop32 r16
L175ee: push64 r0
L175f3: jnz L17640

// {
// bp[-0x4] = 1
L175fb: push64 r7
L17600: push64 0x0
L1760c: push64 0xfffffffffffffffc
L17618: add64 
L1761c: pop64 r16
L17621: add64 
L17625: pop64 r16
L1762a: pop64 r16
L1762f: push32 0x1
L17637: push64 r16
L1763c: store32 

// }
// L17640:
// bp[-0x8] = bp[-0x8] + 0x7342
L17640: push64 r7
L17645: push64 0x0
L17651: push64 0xfffffffffffffff8
L1765d: add64 
L17661: pop64 r16
L17666: add64 
L1766a: pop64 r16
L1766f: push sp
L17673: load64 
L17677: pop64 r16
L1767c: load32 
L17680: push32 0x7342
L17688: add32 
L1768c: pop64 r0
L17691: push64 r16
L17696: store32 

// bp[-0x8] = bp[-0x8] ^ 0x42
L1769a: push64 r7
L1769f: push64 0x0
L176ab: push64 0xfffffffffffffff8
L176b7: add64 
L176bb: pop64 r16
L176c0: add64 
L176c4: pop64 r16
L176c9: push sp
L176cd: load64 
L176d1: pop64 r16
L176d6: load32 
L176da: push32 0x42
L176e2: xor32 
L176e6: pop64 r0
L176eb: push64 r16
L176f0: store32 

// bp[-0x8] = bp[-0x8] ^ 0x744
L176f4: push64 r7
L176f9: push64 0x0
L17705: push64 0xfffffffffffffff8
L17711: add64 
L17715: pop64 r16
L1771a: add64 
L1771e: pop64 r16
L17723: push sp
L17727: load64 
L1772b: pop64 r16
L17730: load32 
L17734: push32 0x744
L1773c: xor32 
L17740: pop64 r0
L17745: push64 r16
L1774a: store32 

// bp[-0xc] = 0x7443
L1774e: push64 r7
L17753: push64 0x0
L1775f: push64 0xfffffffffffffff4
L1776b: add64 
L1776f: pop64 r16
L17774: add64 
L17778: pop64 r16
L1777d: pop64 r16
L17782: push32 0x7443
L1778a: push64 r16
L1778f: store32 

// bp[-0x8] = bp[-0x8] ^ 0x33
L17793: push64 r7
L17798: push64 0x0
L177a4: push64 0xfffffffffffffff8
L177b0: add64 
L177b4: pop64 r16
L177b9: add64 
L177bd: pop64 r16
L177c2: push sp
L177c6: load64 
L177ca: pop64 r16
L177cf: load32 
L177d3: push32 0x33
L177db: xor32 
L177df: pop64 r0
L177e4: push64 r16
L177e9: store32 

// bp[-0x8] = bp[-0x8] | 0x88
L177ed: push64 r7
L177f2: push64 0x0
L177fe: push64 0xfffffffffffffff8
L1780a: add64 
L1780e: pop64 r16
L17813: add64 
L17817: pop64 r16
L1781c: push sp
L17820: load64 
L17824: pop64 r16
L17829: load32 
L1782d: push32 0x88
L17835: or32 
L17839: pop64 r0
L1783e: push64 r16
L17843: store32 

// bp[-0x8] = bp[-0x8] + 0x764
L17847: push64 r7
L1784c: push64 0x0
L17858: push64 0xfffffffffffffff8
L17864: add64 
L17868: pop64 r16
L1786d: add64 
L17871: pop64 r16
L17876: push sp
L1787a: load64 
L1787e: pop64 r16
L17883: load32 
L17887: push32 0x764
L1788f: add32 
L17893: pop64 r0
L17898: push64 r16
L1789d: store32 

// if (bp[0x10] != bp[-0xc]) goto L17982
L178a1: push64 r7
L178a6: push64 0x0
L178b2: push64 0x10
L178be: add64 
L178c2: pop64 r16
L178c7: add64 
L178cb: pop64 r16
L178d0: push64 0x0
L178dc: pop64 r1
L178e1: load32 
L178e5: pop32 r1
L178ea: push64 r7
L178ef: push64 0x0
L178fb: push64 0xfffffffffffffff4
L17907: add64 
L1790b: pop64 r16
L17910: add64 
L17914: pop64 r16
L17919: load32 
L1791d: push32 r1
L17922: sub32 
L17926: pop64 r0
L1792b: pop32 r16
L17930: push64 r0
L17935: jnz L17982

// {
// bp[-0x4] = 1
L1793d: push64 r7
L17942: push64 0x0
L1794e: push64 0xfffffffffffffffc
L1795a: add64 
L1795e: pop64 r16
L17963: add64 
L17967: pop64 r16
L1796c: pop64 r16
L17971: push32 0x1
L17979: push64 r16
L1797e: store32 

// }
// L17982:
// r1 = bp[-0x4] 
L17982: push64 r7
L17987: push64 0x0
L17993: push64 0xfffffffffffffffc
L1799f: add64 
L179a3: pop64 r16
L179a8: add64 
L179ac: pop64 r16
L179b1: push64 0x0
L179bd: pop64 r1
L179c2: load32 
L179c6: pop32 r1

// --- Function epilogue ---
L179cb: push sp         // add sp, 0x10     (free local space)
L179cf: push64 0x10
L179db: add64 
L179df: pop64 r0
L179e4: pop sp
L179e8: pop64 r7        // pop bp

// --- VM exit ---
L179ed: push64 r15
L179f2: push64 r14
L179f7: push64 r13
L179fc: push64 r12
L17a01: push64 r11
L17a06: push64 r10
L17a0b: push64 r9
L17a10: push64 r8
L17a15: push64 r7
L17a1a: push64 r6
L17a1f: push64 r5
L17a24: push64 r4
L17a29: push64 r3
L17a2e: push64 r2
L17a33: push64 r1
L17a38: push64 r0
L17a3d: vmexit 
