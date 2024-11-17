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
L0038: push 0xa
L003b: push 0x6144
L003e: store 
L003f: push 0xb
L0042: push 0x7534
L0045: store 
L0046: push 0xc
L0049: push 0x6962
L004c: store 
L004d: push 0xd
L0050: push 0x6c63
L0053: store 
L0054: push 0xe
L0057: push 0x3165
L005a: store 
L005b: push 0xf
L005e: push 0x6669
L0061: store 
L0062: push 0x10
L0065: push 0x6265
L0068: store 
L0069: push 0x11
L006c: push 0x6230
L006f: store 
L0070: push 0x8
L0073: push 0x3
L0076: load 
L0077: push 0x30
L007a: shift_left 
L007b: push 0x2
L007e: load 
L007f: push 0x20
L0082: shift_left 
L0083: or 
L0084: push 0x1
L0087: load 
L0088: push 0x10
L008b: shift_left 
L008c: or 
L008d: push 0x0
L0090: load 
L0091: or 
L0092: store 
L0093: push 0x9
L0096: push 0x7
L0099: load 
L009a: push 0x30
L009d: shift_left 
L009e: push 0x6
L00a1: load 
L00a2: push 0x20
L00a5: shift_left 
L00a6: or 
L00a7: push 0x5
L00aa: load 
L00ab: push 0x10
L00ae: shift_left 
L00af: or 
L00b0: push 0x4
L00b3: load 
L00b4: or 
L00b5: store 
L00b6: push 0x12
L00b9: push 0xd
L00bc: load 
L00bd: push 0x30
L00c0: shift_left 
L00c1: push 0xc
L00c4: load 
L00c5: push 0x20
L00c8: shift_left 
L00c9: or 
L00ca: push 0xb
L00cd: load 
L00ce: push 0x10
L00d1: shift_left 
L00d2: or 
L00d3: push 0xa
L00d6: load 
L00d7: or 
L00d8: store 
L00d9: push 0x13
L00dc: push 0x11
L00df: load 
L00e0: push 0x30
L00e3: shift_left 
L00e4: push 0x10
L00e7: load 
L00e8: push 0x20
L00eb: shift_left 
L00ec: or 
L00ed: push 0xf
L00f0: load 
L00f1: push 0x10
L00f4: shift_left 
L00f5: or 
L00f6: push 0xe
L00f9: load 
L00fa: or 
L00fb: store 
L00fc: push 0x14
L00ff: push 0x0
L0102: store 
L0103: push 0x18
L0106: push 0x1
L0109: store 
L010a: push 0x17
L010d: push 0x0
L0110: store 
L0111: push 0x19
L0114: push 0x0
L0117: store 
L0118: push 0x18
L011b: load 
L011c: push 0x1
L011f: equals 
L0120: jumpfalse L0241
L0123: push 0x14
L0126: load 
L0127: push 0x8
L012a: lessthan 
L012b: jumpfalse L0150
L012e: push 0x15
L0131: push 0x8
L0134: load 
L0135: push 0x8
L0138: push 0x14
L013b: load 
L013c: mul 
L013d: shift_right 
L013e: store 
L013f: push 0x16
L0142: push 0x12
L0145: load 
L0146: push 0x8
L0149: push 0x14
L014c: load 
L014d: mul 
L014e: shift_right 
L014f: store 
L0150: push 0x14
L0153: load 
L0154: push 0x7
L0157: greaterthan 
L0158: jumpfalse L017d
L015b: push 0x15
L015e: push 0x9
L0161: load 
L0162: push 0x8
L0165: push 0x14
L0168: load 
L0169: mul 
L016a: shift_right 
L016b: store 
L016c: push 0x16
L016f: push 0x13
L0172: load 
L0173: push 0x8
L0176: push 0x14
L0179: load 
L017a: mul 
L017b: shift_right 
L017c: store 
L017d: push 0x15
L0180: push 0x15
L0183: load 
L0184: push 0xff
L0187: and 
L0188: store 
L0189: push 0x16
L018c: push 0x16
L018f: load 
L0190: push 0xff
L0193: and 
L0194: store 
L0195: push 0x14
L0198: load 
L0199: push 0x2
L019c: equals 
L019d: jumpfalse L01ac
L01a0: push 0x16
L01a3: push 0x16
L01a6: load 
L01a7: push 0x4
L01aa: rotate_byte_left? 
L01ab: store 
L01ac: push 0x14
L01af: load 
L01b0: push 0x9
L01b3: equals 
L01b4: jumpfalse L01c3
L01b7: push 0x16
L01ba: push 0x16
L01bd: load 
L01be: push 0x2
L01c1: rotate_byte_right? 
L01c2: store 
L01c3: push 0x14
L01c6: load 
L01c7: push 0xd
L01ca: equals 
L01cb: jumpfalse L01da
L01ce: push 0x16
L01d1: push 0x16
L01d4: load 
L01d5: push 0x7
L01d8: rotate_byte_left? 
L01d9: store 
L01da: push 0x14
L01dd: load 
L01de: push 0xf
L01e1: equals 
L01e2: jumpfalse L01f1
L01e5: push 0x16
L01e8: push 0x16
L01eb: load 
L01ec: push 0x7
L01ef: rotate_byte_left? 
L01f0: store 
L01f1: push 0x15
L01f4: load 
L01f5: push 0x16
L01f8: load 
L01f9: equals 
L01fa: push 0x0
L01fd: equals 
L01fe: jumpfalse L0208
L0201: push 0x18
L0204: push 0x0
L0207: store 
L0208: push 0x15
L020b: load 
L020c: push 0x16
L020f: load 
L0210: equals 
L0211: jumpfalse L0220
L0214: push 0x17
L0217: push 0x17
L021a: load 
L021b: push 0x1
L021e: add 
L021f: store 
L0220: push 0x14
L0223: push 0x14
L0226: load 
L0227: push 0x1
L022a: add 
L022b: store 
L022c: push 0x14
L022f: load 
L0230: push 0xf
L0233: greaterthan 
L0234: jumpfalse L023e
L0237: push 0x18
L023a: push 0x0
L023d: store 
L023e: jump L0118
L0241: push 0x17
L0244: load 
L0245: push 0x10
L0248: equals 
L0249: jumpfalse L0253
L024c: push 0x19
L024f: push 0x1
L0252: store 
L0253: push 0x19
L0256: load 
L0257: set_output 
L0258: exit 
