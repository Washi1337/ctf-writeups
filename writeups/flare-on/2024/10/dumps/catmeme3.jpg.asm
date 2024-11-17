L0000: push 0x0
L0003: push (input[0] | input[1] << 8)
L0006: store 
L0007: push 0x1
L000a: push (input[2] | input[3] << 8)
L000d: store 
L000e: push 0x2
L0011: push (input[4] | input[5] << 8)
L0014: store 
L0015: push 0x3
L0018: push (input[6] | input[7] << 8)
L001b: store 
L001c: push 0x4
L001f: push (input[8] | input[9] << 8)
L0022: store 
L0023: push 0x5
L0026: push (input[10] | input[11] << 8)
L0029: store 
L002a: push 0x6
L002d: push (input[12] | input[13] << 8)
L0030: store 
L0031: push 0x7
L0034: push (input[14] | input[15] << 8)
L0037: store 
L0038: push 0x8
L003b: push 0x3
L003e: load 
L003f: push 0x30
L0042: shift_left 
L0043: push 0x2
L0046: load 
L0047: push 0x20
L004a: shift_left 
L004b: or 
L004c: push 0x1
L004f: load 
L0050: push 0x10
L0053: shift_left 
L0054: or 
L0055: push 0x0
L0058: load 
L0059: or 
L005a: store 
L005b: push 0x9
L005e: push 0x7
L0061: load 
L0062: push 0x30
L0065: shift_left 
L0066: push 0x6
L0069: load 
L006a: push 0x20
L006d: shift_left 
L006e: or 
L006f: push 0x5
L0072: load 
L0073: push 0x10
L0076: shift_left 
L0077: or 
L0078: push 0x4
L007b: load 
L007c: or 
L007d: store 
L007e: push 0x1e
L0081: push 0xffff
L0084: store 
L0085: push 0x1d
L0088: push 0x1e
L008b: load 
L008c: store 
L008d: push 0x1e
L0090: push 0x1e
L0093: load 
L0094: push 0x10
L0097: shift_left 
L0098: push 0x1d
L009b: load 
L009c: or 
L009d: store 
L009e: push 0x1b
L00a1: push 0x0
L00a4: store 
L00a5: push 0x1f
L00a8: push 0x0
L00ab: store 
L00ac: push 0x20
L00af: push 0x0
L00b2: store 
L00b3: push 0x13
L00b6: push 0x1505
L00b9: store 
L00ba: push 0x1b
L00bd: load 
L00be: push 0x4
L00c1: lessthan 
L00c2: jumpfalse L010f
L00c5: push 0x1c
L00c8: push 0x8
L00cb: load 
L00cc: push 0x8
L00cf: push 0x1b
L00d2: load 
L00d3: mul 
L00d4: shift_right 
L00d5: store 
L00d6: push 0x1c
L00d9: push 0x1c
L00dc: load 
L00dd: push 0xff
L00e0: and 
L00e1: store 
L00e2: push 0x1d
L00e5: push 0x13
L00e8: load 
L00e9: store 
L00ea: push 0x13
L00ed: push 0x13
L00f0: load 
L00f1: push 0x5
L00f4: shift_left 
L00f5: push 0x1d
L00f8: load 
L00f9: add 
L00fa: push 0x1c
L00fd: load 
L00fe: add 
L00ff: store 
L0100: push 0x1b
L0103: push 0x1b
L0106: load 
L0107: push 0x1
L010a: add 
L010b: store 
L010c: jump L00ba
L010f: push 0x13
L0112: push 0x13
L0115: load 
L0116: push 0x1e
L0119: load 
L011a: and 
L011b: store 
L011c: push 0x14
L011f: push 0x7c8d
L0122: push 0x10
L0125: shift_left 
L0126: push 0xf4cb
L0129: or 
L012a: store 
L012b: push 0x14
L012e: load 
L012f: push 0x13
L0132: load 
L0133: equals 
L0134: jumpfalse L0143
L0137: push 0x1f
L013a: push 0x1f
L013d: load 
L013e: push 0x1
L0141: add 
L0142: store 
L0143: push 0x1f
L0146: load 
L0147: push 0x0
L014a: greaterthan 
L014b: jumpfalse L01d9
L014e: push 0x15
L0151: push 0x0
L0154: store 
L0155: push 0x1b
L0158: load 
L0159: push 0x8
L015c: lessthan 
L015d: jumpfalse L01a5
L0160: push 0x1c
L0163: push 0x8
L0166: load 
L0167: push 0x8
L016a: push 0x1b
L016d: load 
L016e: mul 
L016f: shift_right 
L0170: store 
L0171: push 0x1c
L0174: push 0x1c
L0177: load 
L0178: push 0xff
L017b: and 
L017c: store 
L017d: push 0x15
L0180: push 0x15
L0183: load 
L0184: push 0xd
L0187: rotate_uint32_right 
L0188: store 
L0189: push 0x15
L018c: push 0x15
L018f: load 
L0190: push 0x1c
L0193: load 
L0194: add 
L0195: store 
L0196: push 0x1b
L0199: push 0x1b
L019c: load 
L019d: push 0x1
L01a0: add 
L01a1: store 
L01a2: jump L0155
L01a5: push 0x15
L01a8: push 0x15
L01ab: load 
L01ac: push 0x1e
L01af: load 
L01b0: and 
L01b1: store 
L01b2: push 0x16
L01b5: push 0x8b68
L01b8: push 0x10
L01bb: shift_left 
L01bc: push 0x1d82
L01bf: or 
L01c0: store 
L01c1: push 0x16
L01c4: load 
L01c5: push 0x15
L01c8: load 
L01c9: equals 
L01ca: jumpfalse L01d9
L01cd: push 0x1f
L01d0: push 0x1f
L01d3: load 
L01d4: push 0x1
L01d7: add 
L01d8: store 
L01d9: push 0x1f
L01dc: load 
L01dd: push 0x1
L01e0: greaterthan 
L01e1: jumpfalse L029e
L01e4: push 0x11
L01e7: push 0x1
L01ea: store 
L01eb: push 0x12
L01ee: push 0x0
L01f1: store 
L01f2: push 0x17
L01f5: push 0x0
L01f8: store 
L01f9: push 0x1b
L01fc: push 0x0
L01ff: store 
L0200: push 0x1b
L0203: load 
L0204: push 0x8
L0207: lessthan 
L0208: jumpfalse L0259
L020b: push 0x1c
L020e: push 0x9
L0211: load 
L0212: push 0x8
L0215: push 0x1b
L0218: load 
L0219: mul 
L021a: shift_right 
L021b: store 
L021c: push 0x1c
L021f: push 0x1c
L0222: load 
L0223: push 0xff
L0226: and 
L0227: store 
L0228: push 0x11
L022b: push 0x11
L022e: load 
L022f: push 0x1c
L0232: load 
L0233: add 
L0234: push 0xfff1
L0237: rem 
L0238: store 
L0239: push 0x12
L023c: push 0x12
L023f: load 
L0240: push 0x11
L0243: load 
L0244: add 
L0245: push 0xfff1
L0248: rem 
L0249: store 
L024a: push 0x1b
L024d: push 0x1b
L0250: load 
L0251: push 0x1
L0254: add 
L0255: store 
L0256: jump L0200
L0259: push 0x17
L025c: push 0x12
L025f: load 
L0260: push 0x10
L0263: shift_left 
L0264: push 0x11
L0267: load 
L0268: or 
L0269: store 
L026a: push 0x17
L026d: push 0x17
L0270: load 
L0271: push 0x1e
L0274: load 
L0275: and 
L0276: store 
L0277: push 0x18
L027a: push 0xf91
L027d: push 0x10
L0280: shift_left 
L0281: push 0x374
L0284: or 
L0285: store 
L0286: push 0x18
L0289: load 
L028a: push 0x17
L028d: load 
L028e: equals 
L028f: jumpfalse L029e
L0292: push 0x1f
L0295: push 0x1f
L0298: load 
L0299: push 0x1
L029c: add 
L029d: store 
L029e: push 0x1f
L02a1: load 
L02a2: push 0x2
L02a5: greaterthan 
L02a6: jumpfalse L03b2
L02a9: push 0xa
L02ac: push 0x193
L02af: store 
L02b0: push 0xb
L02b3: push 0x100
L02b6: store 
L02b7: push 0xc
L02ba: push 0xb
L02bd: load 
L02be: push 0x10
L02c1: shift_left 
L02c2: push 0xa
L02c5: load 
L02c6: or 
L02c7: store 
L02c8: push 0xd
L02cb: push 0x9dc5
L02ce: store 
L02cf: push 0xe
L02d2: push 0x811c
L02d5: store 
L02d6: push 0xf
L02d9: push 0xe
L02dc: load 
L02dd: push 0x10
L02e0: shift_left 
L02e1: push 0xd
L02e4: load 
L02e5: or 
L02e6: store 
L02e7: push 0x10
L02ea: push 0x1
L02ed: push 0x20
L02f0: shift_left 
L02f1: store 
L02f2: push 0x19
L02f5: push 0xf
L02f8: load 
L02f9: store 
L02fa: push 0x1b
L02fd: push 0x0
L0300: store 
L0301: push 0x1b
L0304: load 
L0305: push 0x10
L0308: lessthan 
L0309: jumpfalse L037e
L030c: push 0x1b
L030f: load 
L0310: push 0x8
L0313: lessthan 
L0314: jumpfalse L0328
L0317: push 0x1c
L031a: push 0x8
L031d: load 
L031e: push 0x8
L0321: push 0x1b
L0324: load 
L0325: mul 
L0326: shift_right 
L0327: store 
L0328: push 0x1b
L032b: load 
L032c: push 0x7
L032f: greaterthan 
L0330: jumpfalse L0344
L0333: push 0x1c
L0336: push 0x9
L0339: load 
L033a: push 0x8
L033d: push 0x1b
L0340: load 
L0341: mul 
L0342: shift_right 
L0343: store 
L0344: push 0x1c
L0347: push 0x1c
L034a: load 
L034b: push 0xff
L034e: and 
L034f: store 
L0350: push 0x19
L0353: push 0x19
L0356: load 
L0357: push 0xc
L035a: load 
L035b: mul 
L035c: push 0x10
L035f: load 
L0360: rem 
L0361: store 
L0362: push 0x19
L0365: push 0x19
L0368: load 
L0369: push 0x1c
L036c: load 
L036d: xor 
L036e: store 
L036f: push 0x1b
L0372: push 0x1b
L0375: load 
L0376: push 0x1
L0379: add 
L037a: store 
L037b: jump L0301
L037e: push 0x19
L0381: push 0x19
L0384: load 
L0385: push 0x1e
L0388: load 
L0389: and 
L038a: store 
L038b: push 0x1a
L038e: push 0x31f0
L0391: push 0x10
L0394: shift_left 
L0395: push 0x9d2
L0398: or 
L0399: store 
L039a: push 0x1a
L039d: load 
L039e: push 0x19
L03a1: load 
L03a2: equals 
L03a3: jumpfalse L03b2
L03a6: push 0x1f
L03a9: push 0x1f
L03ac: load 
L03ad: push 0x1
L03b0: add 
L03b1: store 
L03b2: push 0x1f
L03b5: load 
L03b6: push 0x4
L03b9: equals 
L03ba: jumpfalse L03c4
L03bd: push 0x20
L03c0: push 0x1
L03c3: store 
L03c4: push 0x20
L03c7: load 
L03c8: set_output 
L03c9: exit 
