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
L003b: push 0xa059
L003e: store 
L003f: push 0xb
L0042: push 0x6a4d
L0045: store 
L0046: push 0xc
L0049: push 0xde23
L004c: store 
L004d: push 0xd
L0050: push 0x24c0
L0053: store 
L0054: push 0xe
L0057: push 0x64e2
L005a: store 
L005b: push 0xf
L005e: push 0x59b1
L0061: store 
L0062: push 0x10
L0065: push 0x7207
L0068: store 
L0069: push 0x11
L006c: push 0x7f5c
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
L0103: push 0x15
L0106: push 0x1
L0109: store 
L010a: push 0x16
L010d: push 0x0
L0110: store 
L0111: push 0x17
L0114: push 0x0
L0117: store 
L0118: push 0x1c
L011b: push 0x43fd
L011e: push 0x3
L0121: push 0x10
L0124: shift_left 
L0125: or 
L0126: store 
L0127: push 0x1d
L012a: push 0x9ec3
L012d: push 0x26
L0130: push 0x10
L0133: shift_left 
L0134: or 
L0135: store 
L0136: push 0x1b
L0139: push 0x1
L013c: push 0x1f
L013f: shift_left 
L0140: store 
L0141: push 0x1e
L0144: push 0x1337
L0147: store 
L0148: push 0x15
L014b: load 
L014c: push 0x1
L014f: equals 
L0150: jumpfalse L0262
L0153: push 0x14
L0156: load 
L0157: push 0x8
L015a: lessthan 
L015b: jumpfalse L0180
L015e: push 0x18
L0161: push 0x8
L0164: load 
L0165: push 0x8
L0168: push 0x14
L016b: load 
L016c: mul 
L016d: shift_right 
L016e: store 
L016f: push 0x19
L0172: push 0x12
L0175: load 
L0176: push 0x8
L0179: push 0x14
L017c: load 
L017d: mul 
L017e: shift_right 
L017f: store 
L0180: push 0x14
L0183: load 
L0184: push 0x7
L0187: greaterthan 
L0188: jumpfalse L01ad
L018b: push 0x18
L018e: push 0x9
L0191: load 
L0192: push 0x8
L0195: push 0x14
L0198: load 
L0199: mul 
L019a: shift_right 
L019b: store 
L019c: push 0x19
L019f: push 0x13
L01a2: load 
L01a3: push 0x8
L01a6: push 0x14
L01a9: load 
L01aa: mul 
L01ab: shift_right 
L01ac: store 
L01ad: push 0x18
L01b0: push 0x18
L01b3: load 
L01b4: push 0xff
L01b7: and 
L01b8: store 
L01b9: push 0x19
L01bc: push 0x19
L01bf: load 
L01c0: push 0xff
L01c3: and 
L01c4: store 
L01c5: push 0x1e
L01c8: push 0x1c
L01cb: load 
L01cc: push 0x1e
L01cf: load 
L01d0: mul 
L01d1: push 0x1d
L01d4: load 
L01d5: add 
L01d6: push 0x1b
L01d9: load 
L01da: rem 
L01db: store 
L01dc: push 0x1a
L01df: push 0x1e
L01e2: load 
L01e3: store 
L01e4: push 0x1a
L01e7: push 0x1e
L01ea: load 
L01eb: push 0x8
L01ee: push 0x14
L01f1: load 
L01f2: push 0x4
L01f5: rem 
L01f6: mul 
L01f7: shift_right 
L01f8: store 
L01f9: push 0x1f
L01fc: push 0x1a
L01ff: load 
L0200: push 0xff
L0203: and 
L0204: store 
L0205: push 0x20
L0208: push 0x18
L020b: load 
L020c: push 0x1f
L020f: load 
L0210: xor 
L0211: store 
L0212: push 0x20
L0215: load 
L0216: push 0x19
L0219: load 
L021a: equals 
L021b: push 0x0
L021e: equals 
L021f: jumpfalse L0229
L0222: push 0x15
L0225: push 0x0
L0228: store 
L0229: push 0x20
L022c: load 
L022d: push 0x19
L0230: load 
L0231: equals 
L0232: jumpfalse L0241
L0235: push 0x16
L0238: push 0x16
L023b: load 
L023c: push 0x1
L023f: add 
L0240: store 
L0241: push 0x14
L0244: push 0x14
L0247: load 
L0248: push 0x1
L024b: add 
L024c: store 
L024d: push 0x14
L0250: load 
L0251: push 0xf
L0254: greaterthan 
L0255: jumpfalse L025f
L0258: push 0x15
L025b: push 0x0
L025e: store 
L025f: jump L0148
L0262: push 0x16
L0265: load 
L0266: push 0x10
L0269: equals 
L026a: jumpfalse L0274
L026d: push 0x17
L0270: push 0x1
L0273: store 
L0274: push 0x16
L0277: load 
L0278: push 0x10
L027b: equals 
L027c: push 0x0
L027f: equals 
L0280: jumpfalse L028a
L0283: push 0x17
L0286: push 0x0
L0289: store 
L028a: push 0x17
L028d: load 
L028e: set_output 
L028f: exit 
