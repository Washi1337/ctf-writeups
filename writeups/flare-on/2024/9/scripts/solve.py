from z3 import *

key = [BitVec(f'input_{i}', 64) for i in range(0x20)]

s = Solver()

for k in key:
   s.add(k >= 0x20, k <= 0x7e)

block1 = key[4] * 0xef7a8c
block1 += 0x9d865d8d
block1 += key[24] * -0x45b53c
block1 += 0x18baee57
block1 += key[0] * -0xe4cf8b
block1 -= 0x913fbbde
block1 += key[8] * -0xf5c990
block1 += 0x6bfaa656
block1 ^= key[20] * 0x733178
block1 ^= 0x61e3db3b
block1 ^= key[16] * 0x9a17b8
block1 -= 0xca2804b1
block1 ^= key[12] * 0x773850
block1 ^= 0x5a6f68be
block1 ^= key[28] * 0xe21d3d
block1 ^= 0x5c911d23
block1 -= -0x7e9b8587
s.add(block1 & 0xffffffffffffffff == 0)

block2 = key[17] * 0x99aa81
block2 -= 0x74edea51
block2 ^= key[5] * 0x4aba22
block2 += 0x598015bf
block2 ^= key[21] * 0x91a68a
block2 ^= 0x6df18e52
block2 ^= key[1] * 0x942fde
block2 += 0x15c825ee
block2 += key[13] * -0xfe2fbe
block2 += 0xd5682b64
block2 += key[29] * -0xd7e52f
block2 += 0x798bd018
block2 ^= key[25] * 0xe44f6a
block2 -= 0xe66d523e
block2 += key[9] * 0xaf71d6
block2 += 0x921122d3
block2 -= 0xe1148bae
s.add(block2 & 0xffffffffffffffff == 0)

block3 = key[10] * 0x48c500
block3 -= 0x8fdaa1bc
block3 += key[30] * -0x152887
block3 += 0x65f04e48
block3 += key[14] * -0xaa4247
block3 ^= 0x3d63ec69
block3 ^= key[22] * 0x38d82d
block3 ^= 0x872eca8f
block3 ^= key[26] * 0xf120ac
block3 += 0x803dbdcf
block3 += key[2] * 0x254def
block3 ^= 0xee380db3
block3 ^= key[18] * 0x9ef3e7
block3 -= 0x6deaa90b
block3 += key[6] * 0x69c573
block3 -= 0xc9ac5c5d
block3 -= -0x20c45c0f3
s.add(block3 & 0xffffffffffffffff == 0)

block4 = key[11] * 0x67dda4
block4 += 0xf4753afc
block4 += key[31] * 0x5bb860
block4 ^= 0xc1d47fc9
block4 ^= key[23] * 0xab0ce5
block4 += 0x544ff977
block4 += key[7] * 0x148e94
block4 -= 0x9cb3e419
block4 += key[15] * -0x9e06ae
block4 -= 0xadc62064
block4 ^= key[3] * 0xfb9de1
block4 ^= 0x4e3633f7
block4 += key[27] * -0xa8a511
block4 ^= 0xa61f9208
block4 += key[19] * 0xd3468d
block4 += 0x4a5d7b48
block4 -= -0x109bed5e
s.add(block4 & 0xffffffffffffffff == 0)

# Dunno why these don't work (give unsat for some reason)...

# block5 = key[12] * 0x640ba9
# block5 += 0x516c7a5c
# block5 += key[0] * -0xf1d9e5
# block5 += 0x8b424d6b
# block5 += key[28] * 0xd3e2f8
# block5 += 0x3802be78
# block5 += key[24] * 0xb558ce
# block5 -= 0x33418c8e
# block5 += key[8] * -0x2f03a7
# block5 ^= 0xe050b170
# block5 += key[16] * 0xb8fa61
# block5 ^= 0x1fc22df6
# block5 += key[20] * -0xe0c507
# block5 ^= 0xd8376e57
# block5 += key[4] * 0x8e354e
# block5 -= 0xd2cb3108
# block5 -= 0x01e79080
# s.add(block & 0xffffffffffffffff == 0)
#
# block6 = key[17] * 0xa9b448
# block6 ^= 0x9f938499
# block6 += key[5] * 0x906550
# block6 += 0x407021af
# block6 ^= key[13] * 0xaa5ad2
# block6 ^= 0x77cf83a7
# block6 ^= key[29] * 0xc49349
# block6 ^= 0x3067f4e7
# block6 += key[9] * 0x314f8e
# block6 += 0xcd975f3b
# block6 ^= key[21] * 0x81968b
# block6 += 0x893d2e0b
# block6 += key[25] * -0x5ffbac
# block6 ^= 0xf3378e3a
# block6 += key[1] * -0xf63c8e
# block6 -= 0x1c1d882b
# block6 -= 0x8e5eb48d
# s.add(block & 0xffffffffffffffff == 0)

block7 = key[22] * 0xa6edf9
block7 ^= 0x77c58017
block7 += key[18] * -0xe87bf4
block7 -= 0x999bd740
block7 += key[2] * -0x19864d
block7 -= 0x41884bed
block7 += key[6] * 0x901524
block7 ^= 0x247bf095
block7 ^= key[10] * 0xc897cc
block7 ^= 0xeff7eea8
block7 ^= key[14] * 0x731197
block7 += 0x67a0d262
block7 += key[30] * 0x5f591c
block7 += 0x316661f9
block7 += key[26] * 0x579d0e
block7 -= 0x3427fa1c
block7 -= 0x900d744b
s.add(block7 & 0xffffffffffffffff == 0)

block8 = key[23] * 0x9afaf6
block8 ^= 0xdb895413
block8 += key[19] * 0x7d1a12
block8 -= 0xc679fc44
block8 += key[11] * 0x4d84b1
block8 += 0xa30387dc
block8 += key[15] * -0x552b78
block8 ^= 0xf54a725e
block8 ^= key[7] * 0xf372a1
block8 -= 0x4c5103ad
block8 += key[31] * 0xb40eb5
block8 ^= 0x16fa70d2
block8 ^= key[3] * 0x9e5c18
block8 += 0x38784353
block8 ^= key[27] * 0xf2513b
block8 += 0xa1fc09f0
block8 -= 0x101d6e408
s.add(block8 & 0xffffffffffffffff == 0)

block9 = key[28] * 0xac70b9
block9 += 0xdae0a932
block9 ^= key[4] * 0xc42b6f
block9 ^= 0xbc03104c
block9 += key[0] * -0x867193
block9 += 0xdc48c63a
block9 += key[12] * -0x6d31fe
block9 ^= 0x4baeb6d0
block9 += key[16] * -0xaaae58
block9 -= 0xcd7121f8
block9 += key[20] * 0x9faa7a
block9 += 0xbe0a2c9c
block9 += key[24] * 0x354ac6
block9 ^= 0xd8ad17f1
block9 += key[8] * -0x3f2acb
block9 -= 0x8b6b7d89
block9 -= 0x263c13793
s.add(block9 & 0xffffffffffffffff == 0)

# Dunno why this one doesn't work...

# block10 = key[29] * 0xe9d18a
# block10 ^= 0xcb5557ea
# block10 ^= key[25] * 0x8aa5b9
# block10 ^= 0x9125a906
# block10 += key[17] * -0x241997
# block10 += 0x6e46fcb8
# block10 += key[5] * 0xe3da0f
# block10 += 0x4428ec
# block10 += key[13] * 0xa5f9eb
# block10 += 0xbde8f9af
# block10 += key[21] * 0xd6e0fb
# block10 -= 0xc9d97243
# block10 += key[1] * 0x8dc36e
# block10 += 0xc54b7d21
# block10 ^= key[9] * 0xb072ee
# block10 -= 0x2a1ab0c1
# block10 -= 0x2bf2044db
# s.add(block10 & 0xffffffffffffffff == 0)

block11 = key[30] * 0xd14f3e
block11 ^= 0xa06c215b
block11 += key[26] * -0xc5ecbf
block11 += 0xb197c5c0
block11 ^= key[6] * 0x19ff9c
block11 ^= 0x66e7d06c
block11 += key[2] * 0xe3288b
block11 ^= 0x80af4325
block11 ^= key[10] * 0xcfb18c
block11 -= 0xe13c8393
block11 ^= key[18] * 0xd208e5
block11 += 0xf96d2b51
block11 += key[14] * 0x42240f
block11 -= 0x8732273d
block11 += key[22] * -0x1c6098
block11 -= 0xd3d45c5a
block11 -= 0xb3d7e5b
s.add(block11 & 0xffffffffffffffff == 0)

block12 = key[11] * 0x3768cc
block12 ^= 0x19f61419
block12 += key[3] * -0x43be16
block12 += 0x566cc6a8
block12 ^= key[15] * 0xb7cca5
block12 += 0x6db0599e
block12 += key[27] * 0xf6419f
block12 ^= 0xbd613538
block12 ^= key[19] * 0xae52fc
block12 += 0x717a44dd
block12 += key[23] * -0x5eeb81
block12 += 0xdd02182d
block12 ^= key[7] * 0xec1845
block12 ^= 0xef8e5416
block12 += key[31] * 0x61a3be
block12 ^= 0x9288d4fa
block12 -= 0x281bdbe05
s.add(block12 & 0xffffffffffffffff == 0)

block13 = key[16] * 0x336e91
block13 += 0xa1eb20e3
block13 += key[4] * -0xd45de9
block13 -= 0x381ac71a
block13 += key[8] * 0x76c8f8
block13 ^= 0xd8caa2cd
block13 += key[20] * -0x945339
block13 += 0x524d7efa
block13 += key[12] * 0x4474ec
block13 -= 0xe47e82cd
block13 ^= key[0] * 0x51054f
block13 ^= 0x3321c9b1
block13 += key[24] * -0xd7eb3b
block13 += 0x36f6829d
block13 += key[28] * -0xad52e1
block13 ^= 0x6ce2181a
block13 -= -0xc64bbbd
s.add(block13 & 0xffffffffffffffff == 0)

# Dunno why this one doesn't work...

# block14 = key[29] * 0x725059
# block14 ^= 0xa8b69f6b
# block14 += key[17] * 0x6dcfe7
# block14 ^= 0x653c249a
# block14 += key[4] * 0x8f4c44
# block14 ^= 0x68e87685
# block14 += key[9] * -0xd2f4ce
# block14 -= 0x87238dc5
# block14 ^= key[13] * 0xe99d3f
# block14 += 0xed16797a
# block14 += key[5] * 0xada536
# block14 -= 0x95a05aa9
# block14 += key[25] * -0xe0b352
# block14 ^= 0x43c020
# block14 += key[21] * 0x8675b6
# block14 += 0x34a29213
# block14 -= 0x20196a7e
# s.add(block14 & 0xffffffffffffffff == 0)

block15 = key[2] * 0x4a5e95
block15 += 0x5ed7a1f1
block15 += key[22] * 0x3a7b49
block15 ^= 0x87a91310
block15 += key[6] * -0xf27038
block15 ^= 0xf64a0f19
block15 += key[30] * 0xa187d0
block15 -= 0xbbcc735d
block15 += key[18] * -0xfc991a
block15 ^= 0xf9ddd08f
block15 += key[26] * -0x4e947a
block15 -= 0x59a9172e
block15 ^= key[14] * 0x324ead
block15 -= 0x969a7a64
block15 += key[10] * -0x656b1b
block15 += 0x8c112543
block15 -= -0x23e24ba39
s.add(block15 & 0xffffffffffffffff == 0)

block16 = key[11] * 0x251b86
block16 += 0xa751192c
block16 += key[7] * -0x743927
block16 ^= 0xf851da43
block16 ^= key[31] * 0x9a3479
block16 ^= 0x335087a5
block16 ^= key[3] * 0x778a0d
block16 ^= 0x4bfd30d3
block16 += key[27] * -0x7e04b5
block16 -= 0x5d540495
block16 ^= key[19] * 0xf1c3ee
block16 += 0x460c48a6
block16 += key[15] * 0x883b8a
block16 += 0x7b2ffbdc
block16 += key[23] * 0x993db1
block16 += 0xa98b28fa
block16 -= 0x222087cd4
s.add(block16 & 0xffffffffffffffff == 0)

block17 = key[16] * 0xbae081
block17 += 0x2359766f
block17 ^= key[24] * 0xc2483b
block17 += 0xea986a57
block17 += key[28] * -0x520ee2
block17 ^= 0xa6ff8114
block17 += key[8] * 0x9864ba
block17 += 0x42833507
block17 += key[0] * -0x7cd278
block17 ^= 0x360be811
block17 ^= key[4] * 0xbe6605
block17 -= 0x4c927a8d
block17 += key[20] * 0x3bd2e8
block17 += 0xb790cfd3
block17 += key[12] * -0x548c2b
block17 += 0x2a0e04cc
block17 -= 0x221328792
s.add(block17 & 0xffffffffffffffff == 0)

block18 = key[17] * 0xfb213b
block18 -= 0x6773d643
block18 ^= key[9] * 0xde6876
block18 ^= 0x8649fde3
block18 ^= key[29] * 0x629ff7
block18 ^= 0xa0eeb203
block18 += key[25] * -0xdbb107
block18 ^= 0x94aa6b62
block18 += key[1] * -0x262675
block18 -= 0xdfcf5488
block18 += key[5] * 0xd691c5
block18 -= 0x5b3ee746
block18 += key[13] * -0xcafc93
block18 -= 0x111bde22
block18 += key[21] * -0x81f945
block18 -= 0x90033b08
block18 -= -0x29cb62831
s.add(block18 & 0xffffffffffffffff == 0)

block19 = key[10] * 0x52f44d
block19 ^= 0x33b3d0e4
block19 ^= key[30] * 0xe6e66e
block19 -= 0x275d79b0
block19 += key[6] * -0xf98017
block19 ^= 0x456e6c1d
block19 += key[14] * -0x34fcb0
block19 ^= 0x28709cd8
block19 ^= key[2] * 0x4d8ba9
block19 += 0xb5482f53
block19 ^= key[18] * 0x6c7e92
block19 += 0x2af1d741
block19 += key[22] * 0xa4711e
block19 ^= 0x22e79af6
block19 += key[26] * 0x33d374
block19 -= 0x117efc0e
block19 -= 0x9379438e
s.add(block19 & 0xffffffffffffffff == 0)

block20 = key[27] * 0x65ac37
block20 += 0x15e586b0
block20 ^= key[31] * 0xc6dde0
block20 ^= 0x2354cad4
block20 ^= key[15] * 0x154abd
block20 ^= 0xfee57fd5
block20 ^= key[19] * 0xa5e467
block20 += 0x315624ef
block20 ^= key[23] * 0xb6bed6
block20 -= 0x5285b0a5
block20 += key[7] * -0x832ae7
block20 += 0xe961bedd
block20 += key[11] * 0xc46330
block20 -= 0x4a9e1d65
block20 ^= key[3] * 0x3f8467
block20 ^= 0x95a6a1c4
block20 -= 0x1110e3519
s.add(block20 & 0xffffffffffffffff == 0)

block21 = key[24] * 0xb74a52
block21 ^= 0x8354d4e8
block21 ^= key[4] * 0xf22ecd
block21 -= 0x34cbf23b
block21 += key[20] * 0xbef4be
block21 ^= 0x60a6c39a
block21 ^= key[8] * 0x7fe215
block21 += 0xb14a7317
block21 += key[16] * -0xdb9f48
block21 -= 0xbca905f2
block21 += key[28] * -0xbb4276
block21 -= 0x920e2248
block21 ^= key[0] * 0xa3fbef
block21 += 0x4c22d2d3
block21 ^= key[12] * 0xc5e883
block21 ^= 0x50a6e5c9
block21 -= -0x271a423a
s.add(block21 & 0xffffffffffffffff == 0)

block22 = key[13] * 0x4b2d02
block22 ^= 0x4b59b93a
block22 += key[9] * -0x84bb2c
block22 ^= 0x42d5652c
block22 ^= key[25] * 0x6f2d21
block22 += 0x1020133a
block22 += key[29] * 0x5fe38f
block22 -= 0x62807b20
block22 += key[21] * 0xea20a5
block22 ^= 0x60779ceb
block22 ^= key[17] * 0x5c17aa
block22 ^= 0x1aaf8a2d
block22 += key[5] * -0xb9feb0
block22 -= 0xadbe02fb
block22 += key[1] * -0x782f79
block22 -= 0xcfc12836
block22 -= -0x1b77294fa
s.add(block22 & 0xffffffffffffffff == 0)

block23 = key[6] * 0x608d19
block23 -= 0x2eee62ec
block23 += key[14] * -0xbe18f4
block23 ^= 0xb86f9b72
block23 ^= key[30] * 0x88dec9
block23 += 0xaf5cd797
block23 ^= key[18] * 0xb68150
block23 -= 0x3d073ba5
block23 += key[22] * 0x4d166c
block23 += 0xbb1e1039
block23 += key[2] * -0x495e3f
block23 += 0xe727b98e
block23 += key[10] * -0x5caba1
block23 -= 0x1a3cf6c1
block23 += key[26] * 0x183a4d
block23 -= 0xca0397e1
block23 -= 0x6684a31d
s.add(block23 & 0xffffffffffffffff == 0)

block24 = key[11] * 0xffd0ca
block24 -= 0x8f26cee8
block24 ^= key[7] * 0xbf2b59
block24 += 0xc76bad6e
block24 += key[23] * 0x29df01
block24 += 0xeef034a2
block24 ^= key[27] * 0xbbda1d
block24 += 0x5923194e
block24 += key[31] * -0x5d24a5
block24 -= 0x81100799
block24 += key[15] * 0x3dc505
block24 -= 0x69baee91
block24 ^= key[19] * 0x4e25a6
block24 += 0x2468b30a
block24 += key[3] * -0xae1920
block24 ^= 0xd3db6142
block24 -= 0x1bb7af00f
s.add(block24 & 0xffffffffffffffff == 0)

# Dunno why this one doesn't work...

# block25 = key[4] * 0xf56c62
# block25 ^= 0x6c7d1f41
# block25 += key[16] * 0x615605
# block25 += 0x5b52f6ee
# block25 += key[20] * 0x828456
# block25 ^= 0x6f059759
# block25 += key[28] * -0x50484b
# block25 += 0x84e222af
# block25 ^= key[8] * 0x89d640
# block25 += 0xfd21345b
# block25 += key[24] * -0xe4b191
# block25 += 0xfe15a789
# block25 ^= key[0] * 0x8c58c1
# block25 ^= 0x4c49099f
# block25 += key[12] * 0xa13c4c
# block25 ^= 0x27c5288e
# block25 -= 0x398db0b
# s.add(block25 & 0xffffffffffffffff == 0)

block26 = key[1] * 0x73aaf0
block26 ^= 0xa04e34f1
block26 += key[29] * 0xf61e43
block26 += 0xd09b66f3
block26 += key[25] * 0x8cb5f0
block26 += 0xc11c9b4b
block26 ^= key[17] * 0x4f53a8
block26 -= 0x6465672e
block26 += key[9] * 0xb2e1fa
block26 ^= 0x77c07fd8
block26 += key[21] * -0xb8b7b3
block26 -= 0x882c1521
block26 += key[13] * 0x13b807
block26 ^= 0x758dd142
block26 ^= key[5] * 0xdd40c4
block26 -= 0x449786e6
block26 -= 0x1b05dd93c
s.add(block26 & 0xffffffffffffffff == 0)

block27 = key[14] * 0xca894b
block27 += 0xa34fe406
block27 += key[18] * 0x11552b
block27 += 0x3764ecd4
block27 ^= key[22] * 0x7dc36b
block27 += 0xb45e777b
block27 ^= key[26] * 0xcec5a6
block27 ^= 0x2d59bc15
block27 += key[30] * 0xb6e30d
block27 ^= 0xfab9788c
block27 ^= key[10] * 0x859c14
block27 += 0x41868e54
block27 += key[6] * 0xd178d3
block27 += 0x958b0be3
block27 ^= key[2] * 0x61645c
block27 += 0x9dc814cf
block27 -= 0x47b801542
s.add(block27 & 0xffffffffffffffff == 0)

block28 = key[27] * 0x7239e9
block28 -= 0x760e5ada
block28 += key[3] * -0xf1c3d1
block28 -= 0xef28a068
block28 ^= key[11] * 0x1b1367
block28 ^= 0x31e00d5a
block28 ^= key[19] * 0x8038b3
block28 += 0xb5163447
block28 += key[31] * 0x65fac9
block28 += 0xe04a889a
block28 += key[23] * -0xd845ca
block28 -= 0xab7d1c58
block28 += key[15] * 0xb2bbbc
block28 ^= 0x3a017b92
block28 ^= key[7] * 0x33c8bd
block28 += 0x540376e3
block28 -= -0x4f17f36d
s.add(block28 & 0xffffffffffffffff == 0)

block29 = key[0] * 0x53a4e0
block29 -= 0x6061803e
block29 += key[16] * -0x9bbfda
block29 += 0x69b383f1
block29 += key[24] * -0x6b38aa
block29 -= 0x971317a0
block29 += key[20] * 0x5d266f
block29 += 0x5a4b0e60
block29 += key[8] * -0xedc3d3
block29 ^= 0x93e59af6
block29 += key[4] * -0xb1f16c
block29 ^= 0xe8d2b9a9
block29 += key[12] * 0x1c8e5b
block29 -= 0x68839283
block29 += key[28] * 0x78f67b
block29 -= 0xf53dd889
block29 -= -0x1b154dda3
s.add(block29 & 0xffffffffffffffff == 0)

block30 = key[17] * 0x87184c
block30 -= 0x72a15ad8
block30 ^= key[25] * 0xf6372e
block30 += 0x16ad4f89
block30 += key[21] * -0xd7355c
block30 -= 0xbb20fe35
block30 ^= key[5] * 0x471dc1
block30 ^= 0x572c95f4
block30 += key[1] * -0x8c4d98
block30 -= 0x94650c74
block30 += key[13] * -0x5ceea1
block30 ^= 0xf703dcc1
block30 += key[29] * -0xeb0863
block30 += 0xad3bc09d
block30 ^= key[9] * 0xb6227f
block30 -= 0x46ae6a17
block30 -= -0xcea17ee8
s.add(block30 & 0xffffffffffffffff == 0)

block31 = key[30] * 0x8c6412
block31 ^= 0xc08c361c
block31 ^= key[14] * 0xb253c4
block31 += 0x21bb1147
block31 += key[2] * 0x8f0579
block31 -= 0xfa691186
block31 += key[22] * -0x7ac48a
block31 += 0xbb787dd5
block31 += key[10] * 0x2737e6
block31 ^= 0xa2bb7683
block31 += key[18] * -0x4363b9
block31 ^= 0x88c45378
block31 ^= key[6] * 0xb38449
block31 -= 0x209dc078
block31 += key[26] * 0x6e1316
block31 += 0x1343dee9
block31 -= 0xe3699527
s.add(block31 & 0xffffffffffffffff == 0)

block32 = key[19] * 0x390b78
block32 += 0x7d5deea4
block32 += key[15] * -0x70e6c8
block32 -= 0x6ea339e2
block32 ^= key[27] * 0xd8a292
block32 -= 0x288d6ec5
block32 += key[23] * -0x978c71
block32 -= 0xe5d85ed8
block32 += key[31] * 0x9a14d4
block32 -= 0xb69670cc
block32 ^= key[7] * 0x995144
block32 -= 0xd2e77342
block32 ^= key[11] * 0x811c39
block32 -= 0x2dd03565
block32 ^= key[3] * 0x9953d7
block32 ^= 0x80877669
block32 -= -0x206bddb88
s.add(block32 & 0xffffffffffffffff == 0)

result = s.check()
print(result)
if result == sat:
    model = s.model()
    final_key = bytearray(len(key))
    for i, k in enumerate(key):
        final_key[i] = model[k].as_long()
    print(final_key)
