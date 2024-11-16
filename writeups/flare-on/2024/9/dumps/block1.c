#include <stdio.h>
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;
typedef unsigned long long uint64_t;


int get(); 
int main() {
printf("%d", get());
};

int get() {
uint64_t RAX_old = 0;
uint64_t RCX_old = 0;
uint64_t RDX_old = 0;
uint64_t RBX_old = 0;
uint64_t RSP_old = 0;
uint64_t RBP_old = 0;
uint64_t RSI_old = 0;
uint64_t RDI_old = 0;
uint64_t R8_old = 0;
uint64_t R9_old = 0;
uint64_t R10_old = 0;
uint64_t R11_old = 0;
uint64_t R12_old = 0;
uint64_t R13_old = 0;
uint64_t R14_old = 0;
uint64_t R15_old = 0;
uint64_t MXCSR_old = 0;
uint64_t RAX = 0;
uint64_t RCX = 0;
uint64_t RDX = 0;
uint64_t RBX = 0;
uint64_t RSP = 0;
uint64_t RBP = 0;
uint64_t RSI = 0;
uint64_t RDI = 0;
uint64_t R8 = 0;
uint64_t R9 = 0;
uint64_t R10 = 0;
uint64_t R11 = 0;
uint64_t R12 = 0;
uint64_t R13 = 0;
uint64_t R14 = 0;
uint64_t R15 = 0;
uint64_t MXCSR = 0;
uint64_t ZF = 0;



// 13370000: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack0[0x10000];
RSP = (uint64_t) &stack0[0x10000 - 8];


// 13370098: MOV R11,0x10add7f49
R11 = 0x10add7f49;

// 133700a2: PUSH R11
RSP -= 8;
*(uint64_t*) (RSP) = R11;

// 133700a4: PUSH 0x73775436
RSP -= 8;
*(uint64_t*) (RSP) = 0x73775436;

// 133700a9: PUSH 0x68a04c43
RSP -= 8;
*(uint64_t*) (RSP) = 0x68a04c43;

// 133700ae: PUSH 0x12917ff9
RSP -= 8;
*(uint64_t*) (RSP) = 0x12917ff9;

// 133700b3: ADD qword ptr [RSP + 0x18],0x35ac399f
*((uint64_t*) (RSP + 0x18)) += 0x35ac399f;

// 133700bc: JMP 0x13654e21

// 13654e21: JMP 0x13370107

// 13370107: HLT
// ----------------

// 0x00: PushMachframe 0
RSP = *(uint64_t*) (RSP + 0x18);

// 0x00: AllocLarge 4
RSP += 4;

// 0x00: PushNonVol 13
R13 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack1[0x10000];
RSP = (uint64_t) &stack1[0x10000 - 8];


// 133701a7: MOV RBP,qword ptr [R9 + 0x28]
// switch to context pointer RBP

// 133701ab: MOV RDI,qword ptr [RBP + 0xe0]
RDI = *((uint64_t*) (&R13_old));

// 133701b2: MOVZX RDI,DIL
RDI = (*((uint8_t*) &RDI)) & 0xFF;

// 133701b6: JMP 0x13654ef2

// 13654ef2: JMP 0x1337020a

// 1337020a: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack2[0x10000];
RSP = (uint64_t) &stack2[0x10000 - 8];


// 133702a2: MOV R8,qword ptr [R9 + 0x28]
// switch to context pointer R8

// 133702a6: MOV RAX,qword ptr [R8 + 0xb0]
RAX = *((uint64_t*) (&RDI_old));

// 133702ad: MOV R10,-0x46c88b59
R10 = -0x46c88b59;

// 133702b4: ADD R10,0x47b805e5
R10 += 0x47b805e5;

// 133702bb: PUSH R10
RSP -= 8;
*(uint64_t*) (RSP) = R10;

// 133702bd: MUL qword ptr [RSP]
RAX *= *((uint64_t*) (RSP));

// 133702c1: MOV RBP,RAX
RBP = RAX;

// 133702c4: JMP 0x13655099

// 13655099: JMP 0x13370315

// 13370315: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack3[0x10000];
RSP = (uint64_t) &stack3[0x10000 - 8];


// 133703a8: MOV RDX,qword ptr [R9 + 0x28]
// switch to context pointer RDX

// 133703ac: MOV R15,qword ptr [RDX + 0xa0]
R15 = *((uint64_t*) (&RBP_old));

// 133703b3: PUSH R15
RSP -= 8;
*(uint64_t*) (RSP) = R15;

// 133703b5: MOV R12,RSP
R12 = RSP;

// 133703b8: MOV RSI,qword ptr [RDX + 0xa0]
RSI = *((uint64_t*) (&RBP_old));

// 133703bf: JMP 0x136551d3

// 136551d3: JMP 0x13370407

// 13370407: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack4[0x10000];
RSP = (uint64_t) &stack4[0x10000 - 8];


// 133704a9: MOV R10,qword ptr [R9 + 0x28]
// switch to context pointer R10

// 133704ad: MOV R9,qword ptr [R10 + 0xd8]
R9 = *((uint64_t*) (&R12_old));

// 133704b4: MOV RBP,qword ptr [R10 + 0xa8]
RBP = *((uint64_t*) (&RSI_old));

// 133704bb: PUSH R9
RSP -= 8;
*(uint64_t*) (RSP) = R9;

// 133704bd: PUSH 0x58ae3544
RSP -= 8;
*(uint64_t*) (RSP) = 0x58ae3544;

// 133704c2: PUSH 0x7ee52fe1
RSP -= 8;
*(uint64_t*) (RSP) = 0x7ee52fe1;

// 133704c7: PUSH 0x649b0936
RSP -= 8;
*(uint64_t*) (RSP) = 0x649b0936;

// 133704cc: JMP 0x13655307

// 13655307: JMP 0x13370510

// 13370510: HLT
// ----------------

// 0x00: PushMachframe 0
RSP = *(uint64_t*) (RSP + 0x18);

// 0x00: PushNonVol 0
RAX = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack5[0x10000];
RSP = (uint64_t) &stack5[0x10000 - 8];


// 1337059f: MOV RDI,qword ptr [R9 + 0x28]
// switch to context pointer RDI

// 133705a3: MOV RBX,qword ptr [RDI + 0x78]
RBX = *((uint64_t*) (&RAX_old));

// 133705a7: MOV R15,qword ptr [RDI + 0xa0]
R15 = *((uint64_t*) (&RBP_old));

// 133705ae: MOVZX RBX,BL
RBX = (*((uint8_t*) &RBX)) & 0xFF;

// 133705b2: JMP 0x136553d6

// 136553d6: JMP 0x133705fc

// 133705fc: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack6[0x10000];
RSP = (uint64_t) &stack6[0x10000 - 8];


// 13370691: MOV R15,qword ptr [R9 + 0x28]
// switch to context pointer R15

// 13370695: LDMXCSR dword ptr [R15 + 0x90]
MXCSR = *((uint32_t*) (&RBX_old));

// 1337069d: MOV R14,0xd4431f4b
R14 = 0xd4431f4b;

// 133706a7: ADD R14,0x6bc64375
R14 += 0x6bc64375;

// 133706ae: MOV R14,qword ptr [R14 + 0x468]
R14 = *((uint64_t*) (R14 + 0x468));

// 133706b5: ADD R14,qword ptr [R15 + 0x90]
R14 += *((uint64_t*) (&RBX_old));

// 133706bc: MOV SIL,byte ptr [R14]
*((uint8_t*) &RSI) = *((uint8_t*) (R14));

// 133706bf: MOVZX RSI,SIL
RSI = (*((uint8_t*) &RSI)) & 0xFF;

// 133706c3: SHL RSI,0x8
RSI <<= 0x8;

// 133706c7: ADD qword ptr [R15 + 0xf0],RSI
*((uint64_t*) (&R15_old)) += RSI;

// 133706ce: MOV RAX,qword ptr [R9 + 0x28]
// switch to context pointer RAX

// 133706d2: MOV R13,qword ptr [RAX + 0xf0]
R13 = *((uint64_t*) (&R15_old));

// 133706d9: MOV RBX,0x133e82be3
RBX = 0x133e82be3;

// 133706e3: ADD RBX,0xc212edd
RBX += 0xc212edd;

// 133706ea: JMP 0x13655801

// 13655801: JMP 0x13370737

// 13370737: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = RBX - 0;

// 0x00: AllocLarge 1128
RSP += 1128;

// 0x00: PushNonVol 15
R15 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack7[0x10000];
RSP = (uint64_t) &stack7[0x10000 - 8];


// 133707de: MOV RDX,qword ptr [R9 + 0x28]
// switch to context pointer RDX

// 133707e2: LDMXCSR dword ptr [RDX + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 133707e6: MOV R13,qword ptr [RDX + 0xf0]
R13 = *((uint64_t*) (&R15_old));

// 133707ed: MOV RDI,qword ptr [RDX + 0xe0]
RDI = *((uint64_t*) (&R13_old));

// 133707f4: JMP 0x13655937

// 13655937: JMP 0x1337083f

// 1337083f: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack8[0x10000];
RSP = (uint64_t) &stack8[0x10000 - 8];


// 133708e0: MOV RBX,qword ptr [R9 + 0x28]
// switch to context pointer RBX

// 133708e4: MOV RDI,qword ptr [RBX + 0xb0]
RDI = *((uint64_t*) (&RDI_old));

// 133708eb: MOV R11D,dword ptr [RBX + 0x34]
*((uint32_t*) &R11) = *((uint32_t*) (&MXCSR_old));

// 133708ef: ADD R11,qword ptr [RBX + 0xe0]
R11 += *((uint64_t*) (&R13_old));

// 133708f6: MOV BPL,byte ptr [R11]
*((uint8_t*) &RBP) = *((uint8_t*) (R11));

// 133708f9: MOV DIL,BPL
*((uint8_t*) &RDI) = *((uint8_t*) &RBP);

// 133708fc: JMP 0x13655a6b

// 13655a6b: JMP 0x1337094d

// 1337094d: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack9[0x10000];
RSP = (uint64_t) &stack9[0x10000 - 8];


// 133709eb: MOV RSI,qword ptr [R9 + 0x28]
// switch to context pointer RSI

// 133709ef: MOV RDI,qword ptr [RSI + 0xb0]
RDI = *((uint64_t*) (&RDI_old));

// 133709f6: PUSH RDI
RSP -= 8;
*(uint64_t*) (RSP) = RDI;

// 133709f7: MOV RDI,RSP
RDI = RSP;

// 133709fa: MOV R12,qword ptr [RSI + 0xb0]
R12 = *((uint64_t*) (&RDI_old));

// 13370a01: JMP 0x13655b9a

// 13655b9a: JMP 0x13370a4e

// 13370a4e: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack10[0x10000];
RSP = (uint64_t) &stack10[0x10000 - 8];


// 13370af1: MOV R13,qword ptr [R9 + 0x28]
// switch to context pointer R13

// 13370af5: MOV RDI,qword ptr [R13 + 0xb0]
RDI = *((uint64_t*) (&RDI_old));

// 13370afc: MOV R15,qword ptr [R13 + 0xd8]
R15 = *((uint64_t*) (&R12_old));

// 13370b03: PUSH RDI
RSP -= 8;
*(uint64_t*) (RSP) = RDI;

// 13370b04: PUSH 0x7a055875
RSP -= 8;
*(uint64_t*) (RSP) = 0x7a055875;

// 13370b09: PUSH 0x17a8586b
RSP -= 8;
*(uint64_t*) (RSP) = 0x17a8586b;

// 13370b0e: PUSH 0x782d1f90
RSP -= 8;
*(uint64_t*) (RSP) = 0x782d1f90;

// 13370b13: JMP 0x13655cd2

// 13655cd2: JMP 0x13370b58

// 13370b58: HLT
// ----------------

// 0x00: PushMachframe 0
RSP = *(uint64_t*) (RSP + 0x18);

// 0x00: AllocLarge 1
RSP += 1;

// 0x00: PushNonVol 11
R11 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack11[0x10000];
RSP = (uint64_t) &stack11[0x10000 - 8];


// 13370bfb: MOV RDI,qword ptr [R9 + 0x28]
// switch to context pointer RDI

// 13370bff: MOV RBX,qword ptr [RDI + 0xd0]
RBX = *((uint64_t*) (&R11_old));

// 13370c06: MOV RDI,qword ptr [RDI + 0xf0]
RDI = *((uint64_t*) (&R15_old));

// 13370c0d: MOVZX RBX,BL
RBX = (*((uint8_t*) &RBX)) & 0xFF;

// 13370c11: JMP 0x13655e10

// 13655e10: JMP 0x13370c62

// 13370c62: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack12[0x10000];
RSP = (uint64_t) &stack12[0x10000 - 8];


// 13370cfb: MOV R14,qword ptr [R9 + 0x28]
// switch to context pointer R14

// 13370cff: LDMXCSR dword ptr [R14 + 0x90]
MXCSR = *((uint32_t*) (&RBX_old));

// 13370d07: MOV RSI,0x11126ebff
RSI = 0x11126ebff;

// 13370d11: ADD RSI,0x2ee276c1
RSI += 0x2ee276c1;

// 13370d18: MOV RSI,qword ptr [RSI + 0x2e8]
RSI = *((uint64_t*) (RSI + 0x2e8));

// 13370d1f: ADD RSI,qword ptr [R14 + 0x90]
RSI += *((uint64_t*) (&RBX_old));

// 13370d26: MOV BPL,byte ptr [RSI]
*((uint8_t*) &RBP) = *((uint8_t*) (RSI));

// 13370d29: MOVZX RBP,BPL
RBP = (*((uint8_t*) &RBP)) & 0xFF;

// 13370d2d: SHL RBP,0x10
RBP <<= 0x10;

// 13370d31: ADD qword ptr [R14 + 0xb0],RBP
*((uint64_t*) (&RDI_old)) += RBP;

// 13370d38: MOV RCX,qword ptr [R9 + 0x28]
// switch to context pointer RCX

// 13370d3c: MOV R14,qword ptr [RCX + 0xb0]
R14 = *((uint64_t*) (&RDI_old));

// 13370d43: MOV RBP,0xe7d5ee55
RBP = 0xe7d5ee55;

// 13370d4d: ADD RBP,0x58336c6b
RBP += 0x58336c6b;

// 13370d54: JMP 0x13656231

// 13656231: JMP 0x13370d99

// 13370d99: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = RBP - 0;

// 0x00: AllocLarge 744
RSP += 744;

// 0x00: PushNonVol 5
RBP = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack13[0x10000];
RSP = (uint64_t) &stack13[0x10000 - 8];


// 13370e3a: MOV R9,qword ptr [R9 + 0x28]
// switch to context pointer R9

// 13370e3e: LDMXCSR dword ptr [R9 + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 13370e43: MOV R13,qword ptr [R9 + 0xa0]
R13 = *((uint64_t*) (&RBP_old));

// 13370e4a: MOV R15,qword ptr [R9 + 0xe8]
R15 = *((uint64_t*) (&R14_old));

// 13370e51: JMP 0x1365636f

// 1365636f: JMP 0x13370e9c

// 13370e9c: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack14[0x10000];
RSP = (uint64_t) &stack14[0x10000 - 8];


// 13370f2d: MOV R13,qword ptr [R9 + 0x28]
// switch to context pointer R13

// 13370f31: MOV RBP,qword ptr [R13 + 0xf0]
RBP = *((uint64_t*) (&R15_old));

// 13370f38: MOV EAX,dword ptr [R13 + 0x34]
*((uint32_t*) &RAX) = *((uint32_t*) (&MXCSR_old));

// 13370f3c: ADD RAX,qword ptr [R13 + 0xe0]
RAX += *((uint64_t*) (&R13_old));

// 13370f43: MOV R15B,byte ptr [RAX]
*((uint8_t*) &R15) = *((uint8_t*) (RAX));

// 13370f46: MOV R14,0xff
R14 = 0xff;

// 13370f4d: SHL R14,0x8
R14 <<= 0x8;

// 13370f51: NOT R14
R14 = ~R14;

// 13370f54: AND RBP,R14
RBP &= R14;

// 13370f57: MOVZX R14,R15B
R14 = (*((uint8_t*) &R15)) & 0xFF;

// 13370f5b: SHL R14,0x8
R14 <<= 0x8;

// 13370f5f: OR RBP,R14
RBP |= R14;

// 13370f62: JMP 0x13656513

// 13656513: JMP 0x13370fb0

// 13370fb0: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack15[0x10000];
RSP = (uint64_t) &stack15[0x10000 - 8];


// 13371048: MOV RBP,qword ptr [R9 + 0x28]
// switch to context pointer RBP

// 1337104c: MOV R8,qword ptr [RBP + 0xa0]
R8 = *((uint64_t*) (&RBP_old));

// 13371053: PUSH R8
RSP -= 8;
*(uint64_t*) (RSP) = R8;

// 13371055: MOV R14,RSP
R14 = RSP;

// 13371058: MOV R12,qword ptr [RBP + 0xa0]
R12 = *((uint64_t*) (&RBP_old));

// 1337105f: JMP 0x1365664d

// 1365664d: JMP 0x133710aa

// 133710aa: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = R14 - 0;

// 0x00: AllocLarge 2
RSP += 2;

// 0x00: PushNonVol 1
RCX = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack16[0x10000];
RSP = (uint64_t) &stack16[0x10000 - 8];


// 13371140: MOV RSI,qword ptr [R9 + 0x28]
// switch to context pointer RSI

// 13371144: MOV R15,qword ptr [RSI + 0x80]
R15 = *((uint64_t*) (&RCX_old));

// 1337114b: MOV RDI,qword ptr [RSI + 0xd8]
RDI = *((uint64_t*) (&R12_old));

// 13371152: MOVZX R15,R15B
R15 = (*((uint8_t*) &R15)) & 0xFF;

// 13371156: JMP 0x13656787

// 13656787: JMP 0x13371197

// 13371197: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack17[0x10000];
RSP = (uint64_t) &stack17[0x10000 - 8];


// 13371236: MOV R15,qword ptr [R9 + 0x28]
// switch to context pointer R15

// 1337123a: LDMXCSR dword ptr [R15 + 0xf0]
MXCSR = *((uint32_t*) (&R15_old));

// 13371242: MOV RBP,0xffe2ea7c
RBP = 0xffe2ea7c;

// 1337124c: ADD RBP,0x40267844
RBP += 0x40267844;

// 13371253: MOV RBP,qword ptr [RBP + 0x430]
RBP = *((uint64_t*) (RBP + 0x430));

// 1337125a: ADD RBP,qword ptr [R15 + 0xf0]
RBP += *((uint64_t*) (&R15_old));

// 13371261: MOV CL,byte ptr [RBP]
*((uint8_t*) &RCX) = *((uint8_t*) (RBP));

// 13371264: MOVZX RCX,CL
RCX = (*((uint8_t*) &RCX)) & 0xFF;

// 13371268: SHL RCX,0x18
RCX <<= 0x18;

// 1337126c: ADD qword ptr [R15 + 0xb0],RCX
*((uint64_t*) (&RDI_old)) += RCX;

// 13371273: MOV R9,qword ptr [R9 + 0x28]
// switch to context pointer R9

// 13371277: MOV RBX,qword ptr [R9 + 0xb0]
RBX = *((uint64_t*) (&RDI_old));

// 1337127e: MOV R14,0x10e284137
R14 = 0x10e284137;

// 13371288: ADD R14,0x31e11989
R14 += 0x31e11989;

// 1337128f: JMP 0x13656ba0

// 13656ba0: JMP 0x133712d3

// 133712d3: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = R14 - 0;

// 0x00: AllocLarge 1072
RSP += 1072;

// 0x00: PushNonVol 7
RDI = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack18[0x10000];
RSP = (uint64_t) &stack18[0x10000 - 8];


// 1337137d: MOV RSI,qword ptr [R9 + 0x28]
// switch to context pointer RSI

// 13371381: LDMXCSR dword ptr [RSI + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 13371385: MOV R13,qword ptr [RSI + 0xb0]
R13 = *((uint64_t*) (&RDI_old));

// 1337138c: MOV RBP,qword ptr [RSI + 0x90]
RBP = *((uint64_t*) (&RBX_old));

// 13371393: JMP 0x13656cde

// 13656cde: JMP 0x133713d4

// 133713d4: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack19[0x10000];
RSP = (uint64_t) &stack19[0x10000 - 8];


// 13371466: MOV RSI,qword ptr [R9 + 0x28]
// switch to context pointer RSI

// 1337146a: MOV RBP,qword ptr [RSI + 0xa0]
RBP = *((uint64_t*) (&RBP_old));

// 13371471: MOV R10D,dword ptr [RSI + 0x34]
*((uint32_t*) &R10) = *((uint32_t*) (&MXCSR_old));

// 13371475: ADD R10,qword ptr [RSI + 0xe0]
R10 += *((uint64_t*) (&R13_old));

// 1337147c: MOV R12B,byte ptr [R10]
*((uint8_t*) &R12) = *((uint8_t*) (R10));

// 1337147f: MOV RBX,0xff
RBX = 0xff;

// 13371486: SHL RBX,0x10
RBX <<= 0x10;

// 1337148a: NOT RBX
RBX = ~RBX;

// 1337148d: AND RBP,RBX
RBP &= RBX;

// 13371490: MOVZX RBX,R12B
RBX = (*((uint8_t*) &R12)) & 0xFF;

// 13371494: SHL RBX,0x10
RBX <<= 0x10;

// 13371498: OR RBP,RBX
RBP |= RBX;

// 1337149b: JMP 0x13656e88

// 13656e88: JMP 0x133714dc

// 133714dc: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack20[0x10000];
RSP = (uint64_t) &stack20[0x10000 - 8];


// 13371574: MOV RDI,qword ptr [R9 + 0x28]
// switch to context pointer RDI

// 13371578: MOV RBP,qword ptr [RDI + 0xa0]
RBP = *((uint64_t*) (&RBP_old));

// 1337157f: PUSH RBP
RSP -= 8;
*(uint64_t*) (RSP) = RBP;

// 13371580: MOV R13,RSP
R13 = RSP;

// 13371583: MOV RDI,qword ptr [RDI + 0xa0]
RDI = *((uint64_t*) (&RBP_old));

// 1337158a: JMP 0x13656fc0

// 13656fc0: JMP 0x133715de

// 133715de: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack21[0x10000];
RSP = (uint64_t) &stack21[0x10000 - 8];


// 13371677: MOV RDX,qword ptr [R9 + 0x28]
// switch to context pointer RDX

// 1337167b: MOV RBX,qword ptr [RDX + 0xe0]
RBX = *((uint64_t*) (&R13_old));

// 13371682: MOV R14,qword ptr [RDX + 0xb0]
R14 = *((uint64_t*) (&RDI_old));

// 13371689: PUSH RBX
RSP -= 8;
*(uint64_t*) (RSP) = RBX;

// 1337168a: PUSH 0x72801f50
RSP -= 8;
*(uint64_t*) (RSP) = 0x72801f50;

// 1337168f: PUSH 0x5d09280a
RSP -= 8;
*(uint64_t*) (RSP) = 0x5d09280a;

// 13371694: PUSH 0x25a65468
RSP -= 8;
*(uint64_t*) (RSP) = 0x25a65468;

// 13371699: PUSH 0x755b0605
RSP -= 8;
*(uint64_t*) (RSP) = 0x755b0605;

// 1337169e: JMP 0x13657100

// 13657100: JMP 0x133716e5

// 133716e5: HLT
// ----------------

// 0x00: PushMachframe 1
RSP = *(uint64_t*) (RSP + 0x20);

// 0x00: AllocLarge 3
RSP += 3;

// 0x00: PushNonVol 12
R12 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack22[0x10000];
RSP = (uint64_t) &stack22[0x10000 - 8];


// 13371786: MOV R10,qword ptr [R9 + 0x28]
// switch to context pointer R10

// 1337178a: MOV RBP,qword ptr [R10 + 0xd8]
RBP = *((uint64_t*) (&R12_old));

// 13371791: MOV R12,qword ptr [R10 + 0xe8]
R12 = *((uint64_t*) (&R14_old));

// 13371798: MOVZX RBP,BPL
RBP = (*((uint8_t*) &RBP)) & 0xFF;

// 1337179c: JMP 0x1365723c

// 1365723c: JMP 0x133717df

// 133717df: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack23[0x10000];
RSP = (uint64_t) &stack23[0x10000 - 8];


// 13371884: MOV RDX,qword ptr [R9 + 0x28]
// switch to context pointer RDX

// 13371888: LDMXCSR dword ptr [RDX + 0xa0]
MXCSR = *((uint32_t*) (&RBP_old));

// 1337188f: MOV R11,0xcaca37f7
R11 = 0xcaca37f7;

// 13371899: ADD R11,0x753f2ac9
R11 += 0x753f2ac9;

// 133718a0: MOV R11,qword ptr [R11 + 0x4e8]
R11 = *((uint64_t*) (R11 + 0x4e8));

// 133718a7: ADD R11,qword ptr [RDX + 0xa0]
R11 += *((uint64_t*) (&RBP_old));

// 133718ae: MOV DIL,byte ptr [R11]
*((uint8_t*) &RDI) = *((uint8_t*) (R11));

// 133718b1: MOVZX RDI,DIL
RDI = (*((uint8_t*) &RDI)) & 0xFF;

// 133718b5: SHL RDI,0x20
RDI <<= 0x20;

// 133718b9: ADD qword ptr [RDX + 0xd8],RDI
*((uint64_t*) (&R12_old)) += RDI;

// 133718c0: MOV RDI,0x119814b1a
RDI = 0x119814b1a;

// 133718ca: PUSH RDI
RSP -= 8;
*(uint64_t*) (RSP) = RDI;

// 133718cb: PUSH 0x10d66e12
RSP -= 8;
*(uint64_t*) (RSP) = 0x10d66e12;

// 133718d0: PUSH 0xcc8228e
RSP -= 8;
*(uint64_t*) (RSP) = 0xcc8228e;

// 133718d5: PUSH 0x636107a5
RSP -= 8;
*(uint64_t*) (RSP) = 0x636107a5;

// 133718da: PUSH 0x3e021931
RSP -= 8;
*(uint64_t*) (RSP) = 0x3e021931;

// 133718df: ADD qword ptr [RSP + 0x20],0x26880fa6
*((uint64_t*) (RSP + 0x20)) += 0x26880fa6;

// 133718e8: MOV RAX,qword ptr [R9 + 0x28]
// switch to context pointer RAX

// 133718ec: MOV R15,qword ptr [RAX + 0xd8]
R15 = *((uint64_t*) (&R12_old));

// 133718f3: JMP 0x1365766e

// 1365766e: JMP 0x13371938

// 13371938: HLT
// ----------------

// 0x00: PushMachframe 1
RSP = *(uint64_t*) (RSP + 0x20);

// 0x00: AllocLarge 1256
RSP += 1256;

// 0x00: PushNonVol 9
R9 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack24[0x10000];
RSP = (uint64_t) &stack24[0x10000 - 8];


// 133719da: MOV RDX,qword ptr [R9 + 0x28]
// switch to context pointer RDX

// 133719de: LDMXCSR dword ptr [RDX + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 133719e2: MOV RDI,qword ptr [RDX + 0xc0]
RDI = *((uint64_t*) (&R9_old));

// 133719e9: MOV RBX,qword ptr [RDX + 0xf0]
RBX = *((uint64_t*) (&R15_old));

// 133719f0: JMP 0x136577a5

// 136577a5: JMP 0x13371a3d

// 13371a3d: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack25[0x10000];
RSP = (uint64_t) &stack25[0x10000 - 8];


// 13371acf: MOV R8,qword ptr [R9 + 0x28]
// switch to context pointer R8

// 13371ad3: MOV R15,qword ptr [R8 + 0x90]
R15 = *((uint64_t*) (&RBX_old));

// 13371ada: MOV ECX,dword ptr [R8 + 0x34]
*((uint32_t*) &RCX) = *((uint32_t*) (&MXCSR_old));

// 13371ade: ADD RCX,qword ptr [R8 + 0xb0]
RCX += *((uint64_t*) (&RDI_old));

// 13371ae5: MOV R8B,byte ptr [RCX]
*((uint8_t*) &R8) = *((uint8_t*) (RCX));

// 13371ae8: MOV R12,0xff
R12 = 0xff;

// 13371aef: SHL R12,0x18
R12 <<= 0x18;

// 13371af3: NOT R12
R12 = ~R12;

// 13371af6: AND R15,R12
R15 &= R12;

// 13371af9: MOVZX R12,R8B
R12 = (*((uint8_t*) &R8)) & 0xFF;

// 13371afd: SHL R12,0x18
R12 <<= 0x18;

// 13371b01: OR R15,R12
R15 |= R12;

// 13371b04: JMP 0x1365794d

// 1365794d: JMP 0x13371b46

// 13371b46: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack26[0x10000];
RSP = (uint64_t) &stack26[0x10000 - 8];


// 13371bd9: MOV R8,qword ptr [R9 + 0x28]
// switch to context pointer R8

// 13371bdd: MOV RSI,qword ptr [R8 + 0xf0]
RSI = *((uint64_t*) (&R15_old));

// 13371be4: PUSH RSI
RSP -= 8;
*(uint64_t*) (RSP) = RSI;

// 13371be5: MOV R14,RSP
R14 = RSP;

// 13371be8: MOV R15,qword ptr [R8 + 0xf0]
R15 = *((uint64_t*) (&R15_old));

// 13371bef: JMP 0x13657a8e

// 13657a8e: JMP 0x13371c3a

// 13371c3a: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack27[0x10000];
RSP = (uint64_t) &stack27[0x10000 - 8];


// 13371cd3: MOV R13,qword ptr [R9 + 0x28]
// switch to context pointer R13

// 13371cd7: MOV RCX,qword ptr [R13 + 0xe8]
RCX = *((uint64_t*) (&R14_old));

// 13371cde: MOV RDI,qword ptr [R13 + 0xf0]
RDI = *((uint64_t*) (&R15_old));

// 13371ce5: PUSH RCX
RSP -= 8;
*(uint64_t*) (RSP) = RCX;

// 13371ce6: PUSH 0x2da4599d
RSP -= 8;
*(uint64_t*) (RSP) = 0x2da4599d;

// 13371ceb: PUSH 0x14955dfd
RSP -= 8;
*(uint64_t*) (RSP) = 0x14955dfd;

// 13371cf0: PUSH 0x5477311
RSP -= 8;
*(uint64_t*) (RSP) = 0x5477311;

// 13371cf5: JMP 0x13657bc2

// 13657bc2: JMP 0x13371d40

// 13371d40: HLT
// ----------------

// 0x00: PushMachframe 0
RSP = *(uint64_t*) (RSP + 0x18);

// 0x00: AllocLarge 4
RSP += 4;

// 0x00: PushNonVol 2
RDX = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack28[0x10000];
RSP = (uint64_t) &stack28[0x10000 - 8];


// 13371dee: MOV RAX,qword ptr [R9 + 0x28]
// switch to context pointer RAX

// 13371df2: MOV R13,qword ptr [RAX + 0x88]
R13 = *((uint64_t*) (&RDX_old));

// 13371df9: MOV RSI,qword ptr [RAX + 0xb0]
RSI = *((uint64_t*) (&RDI_old));

// 13371e00: MOVZX R13,R13B
R13 = (*((uint8_t*) &R13)) & 0xFF;

// 13371e04: JMP 0x13657d00

// 13657d00: JMP 0x13371e55

// 13371e55: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack29[0x10000];
RSP = (uint64_t) &stack29[0x10000 - 8];


// 13371ef4: MOV RBP,qword ptr [R9 + 0x28]
// switch to context pointer RBP

// 13371ef8: LDMXCSR dword ptr [RBP + 0xe0]
MXCSR = *((uint32_t*) (&R13_old));

// 13371eff: MOV RSI,0xfc120b3f
RSI = 0xfc120b3f;

// 13371f09: ADD RSI,0x43f75781
RSI += 0x43f75781;

// 13371f10: MOV RSI,qword ptr [RSI]
RSI = *((uint64_t*) (RSI));

// 13371f13: ADD RSI,qword ptr [RBP + 0xe0]
RSI += *((uint64_t*) (&R13_old));

// 13371f1a: MOV BL,byte ptr [RSI]
*((uint8_t*) &RBX) = *((uint8_t*) (RSI));

// 13371f1c: MOVZX RBX,BL
RBX = (*((uint8_t*) &RBX)) & 0xFF;

// 13371f20: SHL RBX,0x28
RBX <<= 0x28;

// 13371f24: ADD qword ptr [RBP + 0xa8],RBX
*((uint64_t*) (&RSI_old)) += RBX;

// 13371f2b: MOV RCX,qword ptr [R9 + 0x28]
// switch to context pointer RCX

// 13371f2f: MOV R15,qword ptr [RCX + 0xa8]
R15 = *((uint64_t*) (&RSI_old));

// 13371f36: MOV RSI,0xc40449ee
RSI = 0xc40449ee;

// 13371f40: ADD RSI,0x7c0510d2
RSI += 0x7c0510d2;

// 13371f47: JMP 0x136580b8

// 136580b8: JMP 0x13371f99

// 13371f99: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = RSI - 0;

// 0x00: PushNonVol 10
R10 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack30[0x10000];
RSP = (uint64_t) &stack30[0x10000 - 8];


// 13372027: MOV R12,qword ptr [R9 + 0x28]
// switch to context pointer R12

// 1337202b: LDMXCSR dword ptr [R12 + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 13372031: MOV R13,qword ptr [R12 + 0xc8]
R13 = *((uint64_t*) (&R10_old));

// 13372039: MOV RSI,qword ptr [R12 + 0xf0]
RSI = *((uint64_t*) (&R15_old));

// 13372041: JMP 0x13658259

// 13658259: JMP 0x13372088

// 13372088: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack31[0x10000];
RSP = (uint64_t) &stack31[0x10000 - 8];


// 13372120: MOV R8,qword ptr [R9 + 0x28]
// switch to context pointer R8

// 13372124: MOV R13,qword ptr [R8 + 0xa8]
R13 = *((uint64_t*) (&RSI_old));

// 1337212b: MOV R14D,dword ptr [R8 + 0x34]
*((uint32_t*) &R14) = *((uint32_t*) (&MXCSR_old));

// 1337212f: ADD R14,qword ptr [R8 + 0xe0]
R14 += *((uint64_t*) (&R13_old));

// 13372136: MOV R12B,byte ptr [R14]
*((uint8_t*) &R12) = *((uint8_t*) (R14));

// 13372139: MOV RCX,0xff
RCX = 0xff;

// 13372140: SHL RCX,0x20
RCX <<= 0x20;

// 13372144: NOT RCX
RCX = ~RCX;

// 13372147: AND R13,RCX
R13 &= RCX;

// 1337214a: MOVZX RCX,R12B
RCX = (*((uint8_t*) &R12)) & 0xFF;

// 1337214e: SHL RCX,0x20
RCX <<= 0x20;

// 13372152: OR R13,RCX
R13 |= RCX;

// 13372155: JMP 0x136583fd

// 136583fd: JMP 0x1337219c

// 1337219c: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack32[0x10000];
RSP = (uint64_t) &stack32[0x10000 - 8];


// 1337222f: MOV R13,qword ptr [R9 + 0x28]
// switch to context pointer R13

// 13372233: MOV R8,qword ptr [R13 + 0xe0]
R8 = *((uint64_t*) (&R13_old));

// 1337223a: PUSH R8
RSP -= 8;
*(uint64_t*) (RSP) = R8;

// 1337223c: MOV RBX,RSP
RBX = RSP;

// 1337223f: MOV R13,qword ptr [R13 + 0xe0]
R13 = *((uint64_t*) (&R13_old));

// 13372246: JMP 0x1365853c

// 1365853c: JMP 0x13372299

// 13372299: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack33[0x10000];
RSP = (uint64_t) &stack33[0x10000 - 8];


// 13372333: MOV R10,qword ptr [R9 + 0x28]
// switch to context pointer R10

// 13372337: MOV R8,qword ptr [R10 + 0x90]
R8 = *((uint64_t*) (&RBX_old));

// 1337233e: MOV RSI,qword ptr [R10 + 0xe0]
RSI = *((uint64_t*) (&R13_old));

// 13372345: PUSH R8
RSP -= 8;
*(uint64_t*) (RSP) = R8;

// 13372347: PUSH 0xa166a36
RSP -= 8;
*(uint64_t*) (RSP) = 0xa166a36;

// 1337234c: PUSH 0x187d4f51
RSP -= 8;
*(uint64_t*) (RSP) = 0x187d4f51;

// 13372351: PUSH 0x37141c0c
RSP -= 8;
*(uint64_t*) (RSP) = 0x37141c0c;

// 13372356: JMP 0x13658676

// 13658676: JMP 0x1337239f

// 1337239f: HLT
// ----------------

// 0x00: PushMachframe 0
RSP = *(uint64_t*) (RSP + 0x18);

// 0x00: AllocLarge 6
RSP += 6;

// 0x00: PushNonVol 8
R8 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack34[0x10000];
RSP = (uint64_t) &stack34[0x10000 - 8];


// 13372443: MOV RAX,qword ptr [R9 + 0x28]
// switch to context pointer RAX

// 13372447: MOV R15,qword ptr [RAX + 0xb8]
R15 = *((uint64_t*) (&R8_old));

// 1337244e: MOV RSI,qword ptr [RAX + 0xa8]
RSI = *((uint64_t*) (&RSI_old));

// 13372455: MOVZX R15,R15B
R15 = (*((uint8_t*) &R15)) & 0xFF;

// 13372459: JMP 0x136587b5

// 136587b5: JMP 0x133724a4

// 133724a4: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack35[0x10000];
RSP = (uint64_t) &stack35[0x10000 - 8];


// 13372534: MOV RDI,qword ptr [R9 + 0x28]
// switch to context pointer RDI

// 13372538: LDMXCSR dword ptr [RDI + 0xf0]
MXCSR = *((uint32_t*) (&R15_old));

// 1337253f: MOV RAX,0x13d2109c5
RAX = 0x13d2109c5;

// 13372549: ADD RAX,0x2e858fb
RAX += 0x2e858fb;

// 1337254f: MOV RAX,qword ptr [RAX]
RAX = *((uint64_t*) (RAX));

// 13372552: ADD RAX,qword ptr [RDI + 0xf0]
RAX += *((uint64_t*) (&R15_old));

// 13372559: MOV R10B,byte ptr [RAX]
*((uint8_t*) &R10) = *((uint8_t*) (RAX));

// 1337255c: MOVZX R10,R10B
R10 = (*((uint8_t*) &R10)) & 0xFF;

// 13372560: SHL R10,0x38
R10 <<= 0x38;

// 13372564: ADD qword ptr [RDI + 0xa8],R10
*((uint64_t*) (&RSI_old)) += R10;

// 1337256b: MOV R8,0x12f63e30b
R8 = 0x12f63e30b;

// 13372575: PUSH R8
RSP -= 8;
*(uint64_t*) (RSP) = R8;

// 13372577: PUSH 0x733b102d
RSP -= 8;
*(uint64_t*) (RSP) = 0x733b102d;

// 1337257c: PUSH 0x4ed1230e
RSP -= 8;
*(uint64_t*) (RSP) = 0x4ed1230e;

// 13372581: PUSH 0x22730741
RSP -= 8;
*(uint64_t*) (RSP) = 0x22730741;

// 13372586: PUSH 0x791941b5
RSP -= 8;
*(uint64_t*) (RSP) = 0x791941b5;

// 1337258b: ADD qword ptr [RSP + 0x20],0x10a577b5
*((uint64_t*) (RSP + 0x20)) += 0x10a577b5;

// 13372594: MOV RSI,qword ptr [R9 + 0x28]
// switch to context pointer RSI

// 13372598: MOV R14,qword ptr [RSI + 0xa8]
R14 = *((uint64_t*) (&RSI_old));

// 1337259f: JMP 0x13658b71

// 13658b71: JMP 0x133725f1

// 133725f1: HLT
// ----------------

// 0x00: PushMachframe 1
RSP = *(uint64_t*) (RSP + 0x20);

// 0x00: PushNonVol 1
RCX = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack36[0x10000];
RSP = (uint64_t) &stack36[0x10000 - 8];


// 1337268e: MOV RBX,qword ptr [R9 + 0x28]
// switch to context pointer RBX

// 13372692: LDMXCSR dword ptr [RBX + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 13372696: MOV RDI,qword ptr [RBX + 0x80]
RDI = *((uint64_t*) (&RCX_old));

// 1337269d: MOV R13,qword ptr [RBX + 0xe8]
R13 = *((uint64_t*) (&R14_old));

// 133726a4: JMP 0x13658ca9

// 13658ca9: JMP 0x133726f2

// 133726f2: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack37[0x10000];
RSP = (uint64_t) &stack37[0x10000 - 8];


// 1337278a: MOV R8,qword ptr [R9 + 0x28]
// switch to context pointer R8

// 1337278e: MOV R15,qword ptr [R8 + 0xe0]
R15 = *((uint64_t*) (&R13_old));

// 13372795: MOV ECX,dword ptr [R8 + 0x34]
*((uint32_t*) &RCX) = *((uint32_t*) (&MXCSR_old));

// 13372799: ADD RCX,qword ptr [R8 + 0xb0]
RCX += *((uint64_t*) (&RDI_old));

// 133727a0: MOV R14B,byte ptr [RCX]
*((uint8_t*) &R14) = *((uint8_t*) (RCX));

// 133727a3: MOV RBP,0xff
RBP = 0xff;

// 133727aa: SHL RBP,0x30
RBP <<= 0x30;

// 133727ae: NOT RBP
RBP = ~RBP;

// 133727b1: AND R15,RBP
R15 &= RBP;

// 133727b4: MOVZX RBP,R14B
RBP = (*((uint8_t*) &R14)) & 0xFF;

// 133727b8: SHL RBP,0x30
RBP <<= 0x30;

// 133727bc: OR R15,RBP
R15 |= RBP;

// 133727bf: JMP 0x13658e52

// 13658e52: JMP 0x13372802

// 13372802: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack38[0x10000];
RSP = (uint64_t) &stack38[0x10000 - 8];


// 13372892: MOV R10,qword ptr [R9 + 0x28]
// switch to context pointer R10

// 13372896: MOV R12,qword ptr [R10 + 0xf0]
R12 = *((uint64_t*) (&R15_old));

// 1337289d: MOV R14,0x129f4a1d2
R14 = 0x129f4a1d2;

// 133728a7: ADD R14,0x16951716
R14 += 0x16951716;

// 133728ae: JMP 0x13658fee

// 13658fee: JMP 0x133728f6

// 133728f6: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = R14 - 0;

// 0x00: AllocLarge 24
RSP += 24;

// 0x00: PushNonVol 7
RDI = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack39[0x10000];
RSP = (uint64_t) &stack39[0x10000 - 8];


// 13372988: MOV RSI,qword ptr [R9 + 0x28]
// switch to context pointer RSI

// 1337298c: MOV RBP,qword ptr [RSI + 0xb0]
RBP = *((uint64_t*) (&RDI_old));

// 13372993: MOV R12,qword ptr [RSI + 0xd8]
R12 = *((uint64_t*) (&R12_old));

// 1337299a: MOVZX RBP,BPL
RBP = (*((uint8_t*) &RBP)) & 0xFF;

// 1337299e: JMP 0x1365912d

// 1365912d: JMP 0x133729e9

// 133729e9: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack40[0x10000];
RSP = (uint64_t) &stack40[0x10000 - 8];


// 13372a86: MOV RDI,qword ptr [R9 + 0x28]
// switch to context pointer RDI

// 13372a8a: MOV RAX,qword ptr [RDI + 0xa0]
RAX = *((uint64_t*) (&RBP_old));

// 13372a91: MOV R12,-0x659b81e9
R12 = -0x659b81e9;

// 13372a98: ADD R12,0x65e13725
R12 += 0x65e13725;

// 13372a9f: PUSH R12
RSP -= 8;
*(uint64_t*) (RSP) = R12;

// 13372aa1: MOV RBP,qword ptr [RDI + 0xd8]
RBP = *((uint64_t*) (&R12_old));

// 13372aa8: MUL qword ptr [RSP]
RAX *= *((uint64_t*) (RSP));

// 13372aac: MOV RDI,RAX
RDI = RAX;

// 13372aaf: JMP 0x13659331

// 13659331: JMP 0x13372afa

// 13372afa: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack41[0x10000];
RSP = (uint64_t) &stack41[0x10000 - 8];


// 13372b88: MOV RSI,qword ptr [R9 + 0x28]
// switch to context pointer RSI

// 13372b8c: MOV RDI,qword ptr [RSI + 0xa0]
RDI = *((uint64_t*) (&RBP_old));

// 13372b93: SUB RDI,qword ptr [RSI + 0xb0]
RDI -= *((uint64_t*) (&RDI_old));

// 13372b9a: JMP 0x13659464

// 13659464: JMP 0x13372be5

// 13372be5: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack42[0x10000];
RSP = (uint64_t) &stack42[0x10000 - 8];


// 13372c79: MOV RAX,qword ptr [R9 + 0x28]
// switch to context pointer RAX

// 13372c7d: MOV RCX,qword ptr [RAX + 0xb0]
RCX = *((uint64_t*) (&RDI_old));

// 13372c84: PUSH RCX
RSP -= 8;
*(uint64_t*) (RSP) = RCX;

// 13372c85: MOV R15,RSP
R15 = RSP;

// 13372c88: MOV R13,qword ptr [RAX + 0xb0]
R13 = *((uint64_t*) (&RDI_old));

// 13372c8f: JMP 0x136595a1

// 136595a1: JMP 0x13372cd3

// 13372cd3: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack43[0x10000];
RSP = (uint64_t) &stack43[0x10000 - 8];


// 13372d6b: MOV R8,qword ptr [R9 + 0x28]
// switch to context pointer R8

// 13372d6f: MOV RSI,qword ptr [R8 + 0xf0]
RSI = *((uint64_t*) (&R15_old));

// 13372d76: MOV RBX,qword ptr [R8 + 0xe0]
RBX = *((uint64_t*) (&R13_old));

// 13372d7d: PUSH RSI
RSP -= 8;
*(uint64_t*) (RSP) = RSI;

// 13372d7e: PUSH 0x192e780d
RSP -= 8;
*(uint64_t*) (RSP) = 0x192e780d;

// 13372d83: PUSH 0x5027aab
RSP -= 8;
*(uint64_t*) (RSP) = 0x5027aab;

// 13372d88: PUSH 0x39f2143
RSP -= 8;
*(uint64_t*) (RSP) = 0x39f2143;

// 13372d8d: PUSH 0x6a98231e
RSP -= 8;
*(uint64_t*) (RSP) = 0x6a98231e;

// 13372d92: JMP 0x136596d9

// 136596d9: JMP 0x13372dde

// 13372dde: HLT
// ----------------

// 0x00: PushMachframe 1
RSP = *(uint64_t*) (RSP + 0x20);

// 0x00: PushNonVol 10
R10 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack44[0x10000];
RSP = (uint64_t) &stack44[0x10000 - 8];


// 13372e67: MOV R9,qword ptr [R9 + 0x28]
// switch to context pointer R9

// 13372e6b: MOV RBX,qword ptr [R9 + 0xc8]
RBX = *((uint64_t*) (&R10_old));

// 13372e72: MOV RSI,qword ptr [R9 + 0x90]
RSI = *((uint64_t*) (&RBX_old));

// 13372e79: MOVZX RBX,BL
RBX = (*((uint8_t*) &RBX)) & 0xFF;

// 13372e7d: JMP 0x1365981e

// 1365981e: JMP 0x13372eca

// 13372eca: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack45[0x10000];
RSP = (uint64_t) &stack45[0x10000 - 8];


// 13372f5c: MOV R15,qword ptr [R9 + 0x28]
// switch to context pointer R15

// 13372f60: LDMXCSR dword ptr [R15 + 0x90]
MXCSR = *((uint32_t*) (&RBX_old));

// 13372f68: MOV RBX,0x105deec3c
RBX = 0x105deec3c;

// 13372f72: ADD RBX,0x3a2a7684
RBX += 0x3a2a7684;

// 13372f79: MOV RBX,qword ptr [RBX + 0x2b8]
RBX = *((uint64_t*) (RBX + 0x2b8));

// 13372f80: ADD RBX,qword ptr [R15 + 0x90]
RBX += *((uint64_t*) (&RBX_old));

// 13372f87: MOV CL,byte ptr [RBX]
*((uint8_t*) &RCX) = *((uint8_t*) (RBX));

// 13372f89: MOVZX RCX,CL
RCX = (*((uint8_t*) &RCX)) & 0xFF;

// 13372f8d: SHL RCX,0x8
RCX <<= 0x8;

// 13372f91: ADD qword ptr [R15 + 0xa8],RCX
*((uint64_t*) (&RSI_old)) += RCX;

// 13372f98: MOV RCX,qword ptr [R9 + 0x28]
// switch to context pointer RCX

// 13372f9c: MOV RSI,qword ptr [RCX + 0xa8]
RSI = *((uint64_t*) (&RSI_old));

// 13372fa3: MOV R12,0x108c7fb93
R12 = 0x108c7fb93;

// 13372fad: ADD R12,0x37415f2d
R12 += 0x37415f2d;

// 13372fb4: JMP 0x13659c49

// 13659c49: JMP 0x13373003

// 13373003: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = R12 - 0;

// 0x00: AllocLarge 696
RSP += 696;

// 0x00: PushNonVol 12
R12 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack46[0x10000];
RSP = (uint64_t) &stack46[0x10000 - 8];


// 133730b1: MOV R12,qword ptr [R9 + 0x28]
// switch to context pointer R12

// 133730b5: LDMXCSR dword ptr [R12 + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 133730bb: MOV RBX,qword ptr [R12 + 0xd8]
RBX = *((uint64_t*) (&R12_old));

// 133730c3: MOV R14,qword ptr [R12 + 0xa8]
R14 = *((uint64_t*) (&RSI_old));

// 133730cb: JMP 0x13659dec

// 13659dec: JMP 0x1337311c

// 1337311c: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack47[0x10000];
RSP = (uint64_t) &stack47[0x10000 - 8];


// 133731af: MOV R9,qword ptr [R9 + 0x28]
// switch to context pointer R9

// 133731b3: MOV R13,qword ptr [R9 + 0xe8]
R13 = *((uint64_t*) (&R14_old));

// 133731ba: MOV R8D,dword ptr [R9 + 0x34]
*((uint32_t*) &R8) = *((uint32_t*) (&MXCSR_old));

// 133731be: ADD R8,qword ptr [R9 + 0x90]
R8 += *((uint64_t*) (&RBX_old));

// 133731c5: MOV BL,byte ptr [R8]
*((uint8_t*) &RBX) = *((uint8_t*) (R8));

// 133731c8: MOV R13B,BL
*((uint8_t*) &R13) = *((uint8_t*) &RBX);

// 133731cb: JMP 0x13659f28

// 13659f28: JMP 0x1337320e

// 1337320e: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack48[0x10000];
RSP = (uint64_t) &stack48[0x10000 - 8];


// 13373295: MOV R8,qword ptr [R9 + 0x28]
// switch to context pointer R8

// 13373299: MOV RCX,qword ptr [R8 + 0xe0]
RCX = *((uint64_t*) (&R13_old));

// 133732a0: PUSH RCX
RSP -= 8;
*(uint64_t*) (RSP) = RCX;

// 133732a1: MOV R14,RSP
R14 = RSP;

// 133732a4: MOV RSI,qword ptr [R8 + 0xe0]
RSI = *((uint64_t*) (&R13_old));

// 133732ab: JMP 0x1365a063

// 1365a063: JMP 0x133732ed

// 133732ed: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = R14 - 0;

// 0x00: AllocLarge 1
RSP += 1;

// 0x00: PushNonVol 8
R8 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack49[0x10000];
RSP = (uint64_t) &stack49[0x10000 - 8];


// 13373389: MOV R12,qword ptr [R9 + 0x28]
// switch to context pointer R12

// 1337338d: MOV RSI,qword ptr [R12 + 0xb8]
RSI = *((uint64_t*) (&R8_old));

// 13373395: MOV R15,qword ptr [R12 + 0xa8]
R15 = *((uint64_t*) (&RSI_old));

// 1337339d: MOVZX RSI,SIL
RSI = (*((uint8_t*) &RSI)) & 0xFF;

// 133733a1: JMP 0x1365a1a0

// 1365a1a0: JMP 0x133733e5

// 133733e5: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack50[0x10000];
RSP = (uint64_t) &stack50[0x10000 - 8];


// 1337347e: MOV R13,qword ptr [R9 + 0x28]
// switch to context pointer R13

// 13373482: LDMXCSR dword ptr [R13 + 0xa8]
MXCSR = *((uint32_t*) (&RSI_old));

// 1337348a: MOV RBX,0x119e43dea
RBX = 0x119e43dea;

// 13373494: ADD RBX,0x262524d6
RBX += 0x262524d6;

// 1337349b: MOV RBX,qword ptr [RBX + 0x770]
RBX = *((uint64_t*) (RBX + 0x770));

// 133734a2: ADD RBX,qword ptr [R13 + 0xa8]
RBX += *((uint64_t*) (&RSI_old));

// 133734a9: MOV R14B,byte ptr [RBX]
*((uint8_t*) &R14) = *((uint8_t*) (RBX));

// 133734ac: MOVZX R14,R14B
R14 = (*((uint8_t*) &R14)) & 0xFF;

// 133734b0: SHL R14,0x10
R14 <<= 0x10;

// 133734b4: ADD qword ptr [R13 + 0xf0],R14
*((uint64_t*) (&R15_old)) += R14;

// 133734bb: MOV R11,0x11e571db2
R11 = 0x11e571db2;

// 133734c5: PUSH R11
RSP -= 8;
*(uint64_t*) (RSP) = R11;

// 133734c7: PUSH 0x38ad6fef
RSP -= 8;
*(uint64_t*) (RSP) = 0x38ad6fef;

// 133734cc: PUSH 0x6f700c46
RSP -= 8;
*(uint64_t*) (RSP) = 0x6f700c46;

// 133734d1: PUSH 0x365b35c0
RSP -= 8;
*(uint64_t*) (RSP) = 0x365b35c0;

// 133734d6: PUSH 0xa3125af
RSP -= 8;
*(uint64_t*) (RSP) = 0xa3125af;

// 133734db: ADD qword ptr [RSP + 0x20],0x21b23d0e
*((uint64_t*) (RSP + 0x20)) += 0x21b23d0e;

// 133734e4: MOV R11,qword ptr [R9 + 0x28]
// switch to context pointer R11

// 133734e8: MOV R14,qword ptr [R11 + 0xf0]
R14 = *((uint64_t*) (&R15_old));

// 133734ef: JMP 0x1365a5c4

// 1365a5c4: JMP 0x1337353c

// 1337353c: HLT
// ----------------

// 0x00: PushMachframe 1
RSP = *(uint64_t*) (RSP + 0x20);

// 0x00: AllocLarge 1904
RSP += 1904;

// 0x00: PushNonVol 3
RBX = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack51[0x10000];
RSP = (uint64_t) &stack51[0x10000 - 8];


// 133735e1: MOV RBP,qword ptr [R9 + 0x28]
// switch to context pointer RBP

// 133735e5: LDMXCSR dword ptr [RBP + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 133735e9: MOV R13,qword ptr [RBP + 0x90]
R13 = *((uint64_t*) (&RBX_old));

// 133735f0: MOV R12,qword ptr [RBP + 0xe8]
R12 = *((uint64_t*) (&R14_old));

// 133735f7: JMP 0x1365a6fe

// 1365a6fe: JMP 0x13373643

// 13373643: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack52[0x10000];
RSP = (uint64_t) &stack52[0x10000 - 8];


// 133736e0: MOV R9,qword ptr [R9 + 0x28]
// switch to context pointer R9

// 133736e4: MOV R15,qword ptr [R9 + 0xd8]
R15 = *((uint64_t*) (&R12_old));

// 133736eb: MOV R10D,dword ptr [R9 + 0x34]
*((uint32_t*) &R10) = *((uint32_t*) (&MXCSR_old));

// 133736ef: ADD R10,qword ptr [R9 + 0xe0]
R10 += *((uint64_t*) (&R13_old));

// 133736f6: MOV CL,byte ptr [R10]
*((uint8_t*) &RCX) = *((uint8_t*) (R10));

// 133736f9: MOV R11,0xff
R11 = 0xff;

// 13373700: SHL R11,0x8
R11 <<= 0x8;

// 13373704: NOT R11
R11 = ~R11;

// 13373707: AND R15,R11
R15 &= R11;

// 1337370a: MOVZX R11,CL
R11 = (*((uint8_t*) &RCX)) & 0xFF;

// 1337370e: SHL R11,0x8
R11 <<= 0x8;

// 13373712: OR R15,R11
R15 |= R11;

// 13373715: JMP 0x1365a8aa

// 1365a8aa: JMP 0x1337375d

// 1337375d: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack53[0x10000];
RSP = (uint64_t) &stack53[0x10000 - 8];


// 133737fc: MOV RAX,qword ptr [R9 + 0x28]
// switch to context pointer RAX

// 13373800: MOV R14,qword ptr [RAX + 0xf0]
R14 = *((uint64_t*) (&R15_old));

// 13373807: PUSH R14
RSP -= 8;
*(uint64_t*) (RSP) = R14;

// 13373809: MOV RBP,RSP
RBP = RSP;

// 1337380c: MOV R12,qword ptr [RAX + 0xf0]
R12 = *((uint64_t*) (&R15_old));

// 13373813: JMP 0x1365a9e3

// 1365a9e3: JMP 0x13373864

// 13373864: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack54[0x10000];
RSP = (uint64_t) &stack54[0x10000 - 8];


// 133738f4: MOV RCX,qword ptr [R9 + 0x28]
// switch to context pointer RCX

// 133738f8: MOV RBP,qword ptr [RCX + 0xa0]
RBP = *((uint64_t*) (&RBP_old));

// 133738ff: MOV R14,qword ptr [RCX + 0xd8]
R14 = *((uint64_t*) (&R12_old));

// 13373906: PUSH RBP
RSP -= 8;
*(uint64_t*) (RSP) = RBP;

// 13373907: PUSH 0x3b8f54d7
RSP -= 8;
*(uint64_t*) (RSP) = 0x3b8f54d7;

// 1337390c: PUSH 0x7b264c7d
RSP -= 8;
*(uint64_t*) (RSP) = 0x7b264c7d;

// 13373911: PUSH 0x195578c2
RSP -= 8;
*(uint64_t*) (RSP) = 0x195578c2;

// 13373916: PUSH 0x6a762e66
RSP -= 8;
*(uint64_t*) (RSP) = 0x6a762e66;

// 1337391b: JMP 0x1365ab1c

// 1365ab1c: JMP 0x13373962

// 13373962: HLT
// ----------------

// 0x00: PushMachframe 1
RSP = *(uint64_t*) (RSP + 0x20);

// 0x00: AllocLarge 2
RSP += 2;

// 0x00: PushNonVol 0
RAX = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack55[0x10000];
RSP = (uint64_t) &stack55[0x10000 - 8];


// 13373a02: MOV R13,qword ptr [R9 + 0x28]
// switch to context pointer R13

// 13373a06: MOV RDI,qword ptr [R13 + 0x78]
RDI = *((uint64_t*) (&RAX_old));

// 13373a0a: MOV R14,qword ptr [R13 + 0xe8]
R14 = *((uint64_t*) (&R14_old));

// 13373a11: MOVZX RDI,DIL
RDI = (*((uint8_t*) &RDI)) & 0xFF;

// 13373a15: JMP 0x1365abec

// 1365abec: JMP 0x13373a66

// 13373a66: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack56[0x10000];
RSP = (uint64_t) &stack56[0x10000 - 8];


// 13373afa: MOV R11,qword ptr [R9 + 0x28]
// switch to context pointer R11

// 13373afe: LDMXCSR dword ptr [R11 + 0xb0]
MXCSR = *((uint32_t*) (&RDI_old));

// 13373b06: MOV RDX,0x103c05e72
RDX = 0x103c05e72;

// 13373b10: ADD RDX,0x3c49044e
RDX += 0x3c49044e;

// 13373b17: MOV RDX,qword ptr [RDX + 0x5d0]
RDX = *((uint64_t*) (RDX + 0x5d0));

// 13373b1e: ADD RDX,qword ptr [R11 + 0xb0]
RDX += *((uint64_t*) (&RDI_old));

// 13373b25: MOV DIL,byte ptr [RDX]
*((uint8_t*) &RDI) = *((uint8_t*) (RDX));

// 13373b28: MOVZX RDI,DIL
RDI = (*((uint8_t*) &RDI)) & 0xFF;

// 13373b2c: SHL RDI,0x18
RDI <<= 0x18;

// 13373b30: ADD qword ptr [R11 + 0xe8],RDI
*((uint64_t*) (&R14_old)) += RDI;

// 13373b37: MOV RDX,0xf30ae909
RDX = 0xf30ae909;

// 13373b41: PUSH RDX
RSP -= 8;
*(uint64_t*) (RSP) = RDX;

// 13373b42: PUSH 0x2b135190
RSP -= 8;
*(uint64_t*) (RSP) = 0x2b135190;

// 13373b47: PUSH 0xaf52991
RSP -= 8;
*(uint64_t*) (RSP) = 0xaf52991;

// 13373b4c: PUSH 0x52b21664
RSP -= 8;
*(uint64_t*) (RSP) = 0x52b21664;

// 13373b51: PUSH 0x3e294a10
RSP -= 8;
*(uint64_t*) (RSP) = 0x3e294a10;

// 13373b56: ADD qword ptr [RSP + 0x20],0x4cfe71b7
*((uint64_t*) (RSP + 0x20)) += 0x4cfe71b7;

// 13373b5f: MOV RSI,qword ptr [R9 + 0x28]
// switch to context pointer RSI

// 13373b63: MOV R14,qword ptr [RSI + 0xe8]
R14 = *((uint64_t*) (&R14_old));

// 13373b6a: JMP 0x1365b016

// 1365b016: JMP 0x13373bb9

// 13373bb9: HLT
// ----------------

// 0x00: PushMachframe 1
RSP = *(uint64_t*) (RSP + 0x20);

// 0x00: AllocLarge 1488
RSP += 1488;

// 0x00: PushNonVol 13
R13 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack57[0x10000];
RSP = (uint64_t) &stack57[0x10000 - 8];


// 13373c69: MOV R11,qword ptr [R9 + 0x28]
// switch to context pointer R11

// 13373c6d: LDMXCSR dword ptr [R11 + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 13373c72: MOV RBP,qword ptr [R11 + 0xe0]
RBP = *((uint64_t*) (&R13_old));

// 13373c79: MOV R14,qword ptr [R11 + 0xe8]
R14 = *((uint64_t*) (&R14_old));

// 13373c80: JMP 0x1365b150

// 1365b150: JMP 0x13373ccc

// 13373ccc: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack58[0x10000];
RSP = (uint64_t) &stack58[0x10000 - 8];


// 13373d5f: MOV R15,qword ptr [R9 + 0x28]
// switch to context pointer R15

// 13373d63: MOV R12,qword ptr [R15 + 0xe8]
R12 = *((uint64_t*) (&R14_old));

// 13373d6a: MOV EBX,dword ptr [R15 + 0x34]
*((uint32_t*) &RBX) = *((uint32_t*) (&MXCSR_old));

// 13373d6e: ADD RBX,qword ptr [R15 + 0xa0]
RBX += *((uint64_t*) (&RBP_old));

// 13373d75: MOV R9B,byte ptr [RBX]
*((uint8_t*) &R9) = *((uint8_t*) (RBX));

// 13373d78: MOV R13,0xff
R13 = 0xff;

// 13373d7f: SHL R13,0x10
R13 <<= 0x10;

// 13373d83: NOT R13
R13 = ~R13;

// 13373d86: AND R12,R13
R12 &= R13;

// 13373d89: MOVZX R13,R9B
R13 = (*((uint8_t*) &R9)) & 0xFF;

// 13373d8d: SHL R13,0x10
R13 <<= 0x10;

// 13373d91: OR R12,R13
R12 |= R13;

// 13373d94: JMP 0x1365b2f3

// 1365b2f3: JMP 0x13373de3

// 13373de3: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack59[0x10000];
RSP = (uint64_t) &stack59[0x10000 - 8];


// 13373e70: MOV R13,qword ptr [R9 + 0x28]
// switch to context pointer R13

// 13373e74: MOV RSI,qword ptr [R13 + 0xd8]
RSI = *((uint64_t*) (&R12_old));

// 13373e7b: PUSH RSI
RSP -= 8;
*(uint64_t*) (RSP) = RSI;

// 13373e7c: MOV RSI,RSP
RSI = RSP;

// 13373e7f: MOV R15,qword ptr [R13 + 0xd8]
R15 = *((uint64_t*) (&R12_old));

// 13373e86: JMP 0x1365b42c

// 1365b42c: JMP 0x13373ecb

// 13373ecb: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack60[0x10000];
RSP = (uint64_t) &stack60[0x10000 - 8];


// 13373f70: MOV R14,qword ptr [R9 + 0x28]
// switch to context pointer R14

// 13373f74: MOV R13,qword ptr [R14 + 0xa8]
R13 = *((uint64_t*) (&RSI_old));

// 13373f7b: MOV R15,qword ptr [R14 + 0xf0]
R15 = *((uint64_t*) (&R15_old));

// 13373f82: PUSH R13
RSP -= 8;
*(uint64_t*) (RSP) = R13;

// 13373f84: PUSH 0x20d6587a
RSP -= 8;
*(uint64_t*) (RSP) = 0x20d6587a;

// 13373f89: PUSH 0x70436f65
RSP -= 8;
*(uint64_t*) (RSP) = 0x70436f65;

// 13373f8e: PUSH 0x640c3dba
RSP -= 8;
*(uint64_t*) (RSP) = 0x640c3dba;

// 13373f93: PUSH 0x46d24d2c
RSP -= 8;
*(uint64_t*) (RSP) = 0x46d24d2c;

// 13373f98: JMP 0x1365b564

// 1365b564: JMP 0x13373fdf

// 13373fdf: HLT
// ----------------

// 0x00: PushMachframe 1
RSP = *(uint64_t*) (RSP + 0x20);

// 0x00: AllocLarge 3
RSP += 3;

// 0x00: PushNonVol 5
RBP = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack61[0x10000];
RSP = (uint64_t) &stack61[0x10000 - 8];


// 13374080: MOV R9,qword ptr [R9 + 0x28]
// switch to context pointer R9

// 13374084: MOV RBP,qword ptr [R9 + 0xa0]
RBP = *((uint64_t*) (&RBP_old));

// 1337408b: MOV R14,qword ptr [R9 + 0xf0]
R14 = *((uint64_t*) (&R15_old));

// 13374092: MOVZX RBP,BPL
RBP = (*((uint8_t*) &RBP)) & 0xFF;

// 13374096: JMP 0x1365b69d

// 1365b69d: JMP 0x133740e5

// 133740e5: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack62[0x10000];
RSP = (uint64_t) &stack62[0x10000 - 8];


// 13374182: MOV R15,qword ptr [R9 + 0x28]
// switch to context pointer R15

// 13374186: LDMXCSR dword ptr [R15 + 0xa0]
MXCSR = *((uint32_t*) (&RBP_old));

// 1337418e: MOV RAX,0x1161b4d4a
RAX = 0x1161b4d4a;

// 13374198: ADD RAX,0x29ee1576
RAX += 0x29ee1576;

// 1337419e: MOV RAX,qword ptr [RAX + 0xc0]
RAX = *((uint64_t*) (RAX + 0xc0));

// 133741a5: ADD RAX,qword ptr [R15 + 0xa0]
RAX += *((uint64_t*) (&RBP_old));

// 133741ac: MOV R13B,byte ptr [RAX]
*((uint8_t*) &R13) = *((uint8_t*) (RAX));

// 133741af: MOVZX R13,R13B
R13 = (*((uint8_t*) &R13)) & 0xFF;

// 133741b3: SHL R13,0x20
R13 <<= 0x20;

// 133741b7: ADD qword ptr [R15 + 0xe8],R13
*((uint64_t*) (&R14_old)) += R13;

// 133741be: MOV R11,qword ptr [R9 + 0x28]
// switch to context pointer R11

// 133741c2: MOV R12,qword ptr [R11 + 0xe8]
R12 = *((uint64_t*) (&R14_old));

// 133741c9: MOV R14,0xf3640df6
R14 = 0xf3640df6;

// 133741d3: ADD R14,0x4ca54cca
R14 += 0x4ca54cca;

// 133741da: JMP 0x1365babd

// 1365babd: JMP 0x13374223

// 13374223: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = R14 - 0;

// 0x00: AllocLarge 192
RSP += 192;

// 0x00: PushNonVol 13
R13 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack63[0x10000];
RSP = (uint64_t) &stack63[0x10000 - 8];


// 133742b2: MOV RDI,qword ptr [R9 + 0x28]
// switch to context pointer RDI

// 133742b6: LDMXCSR dword ptr [RDI + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 133742ba: MOV R12,qword ptr [RDI + 0xe0]
R12 = *((uint64_t*) (&R13_old));

// 133742c1: MOV R13,qword ptr [RDI + 0xd8]
R13 = *((uint64_t*) (&R12_old));

// 133742c8: JMP 0x1365bbfb

// 1365bbfb: JMP 0x13374315

// 13374315: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack64[0x10000];
RSP = (uint64_t) &stack64[0x10000 - 8];


// 133743a8: MOV R9,qword ptr [R9 + 0x28]
// switch to context pointer R9

// 133743ac: MOV R13,qword ptr [R9 + 0xe0]
R13 = *((uint64_t*) (&R13_old));

// 133743b3: MOV R15D,dword ptr [R9 + 0x34]
*((uint32_t*) &R15) = *((uint32_t*) (&MXCSR_old));

// 133743b7: ADD R15,qword ptr [R9 + 0xd8]
R15 += *((uint64_t*) (&R12_old));

// 133743be: MOV R8B,byte ptr [R15]
*((uint8_t*) &R8) = *((uint8_t*) (R15));

// 133743c1: MOV R11,0xff
R11 = 0xff;

// 133743c8: SHL R11,0x18
R11 <<= 0x18;

// 133743cc: NOT R11
R11 = ~R11;

// 133743cf: AND R13,R11
R13 &= R11;

// 133743d2: MOVZX R11,R8B
R11 = (*((uint8_t*) &R8)) & 0xFF;

// 133743d6: SHL R11,0x18
R11 <<= 0x18;

// 133743da: OR R13,R11
R13 |= R11;

// 133743dd: JMP 0x1365bd93

// 1365bd93: JMP 0x13374431

// 13374431: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack65[0x10000];
RSP = (uint64_t) &stack65[0x10000 - 8];


// 133744cb: MOV RCX,qword ptr [R9 + 0x28]
// switch to context pointer RCX

// 133744cf: MOV RBP,qword ptr [RCX + 0xe0]
RBP = *((uint64_t*) (&R13_old));

// 133744d6: PUSH RBP
RSP -= 8;
*(uint64_t*) (RSP) = RBP;

// 133744d7: MOV RBX,RSP
RBX = RSP;

// 133744da: MOV RSI,qword ptr [RCX + 0xe0]
RSI = *((uint64_t*) (&R13_old));

// 133744e1: JMP 0x1365bed6

// 1365bed6: JMP 0x1337452e

// 1337452e: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack66[0x10000];
RSP = (uint64_t) &stack66[0x10000 - 8];


// 133745cc: MOV R8,qword ptr [R9 + 0x28]
// switch to context pointer R8

// 133745d0: MOV RBX,qword ptr [R8 + 0x90]
RBX = *((uint64_t*) (&RBX_old));

// 133745d7: MOV RDI,qword ptr [R8 + 0xa8]
RDI = *((uint64_t*) (&RSI_old));

// 133745de: PUSH RBX
RSP -= 8;
*(uint64_t*) (RSP) = RBX;

// 133745df: PUSH 0x2c671b1f
RSP -= 8;
*(uint64_t*) (RSP) = 0x2c671b1f;

// 133745e4: PUSH 0x78e35209
RSP -= 8;
*(uint64_t*) (RSP) = 0x78e35209;

// 133745e9: PUSH 0x6aa51089
RSP -= 8;
*(uint64_t*) (RSP) = 0x6aa51089;

// 133745ee: JMP 0x1365c00a

// 1365c00a: JMP 0x13374633

// 13374633: HLT
// ----------------

// 0x00: PushMachframe 0
RSP = *(uint64_t*) (RSP + 0x18);

// 0x00: AllocLarge 4
RSP += 4;

// 0x00: PushNonVol 3
RBX = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack67[0x10000];
RSP = (uint64_t) &stack67[0x10000 - 8];


// 133746cf: MOV RDX,qword ptr [R9 + 0x28]
// switch to context pointer RDX

// 133746d3: MOV RSI,qword ptr [RDX + 0x90]
RSI = *((uint64_t*) (&RBX_old));

// 133746da: MOV RBP,qword ptr [RDX + 0xb0]
RBP = *((uint64_t*) (&RDI_old));

// 133746e1: MOVZX RSI,SIL
RSI = (*((uint8_t*) &RSI)) & 0xFF;

// 133746e5: JMP 0x1365c13e

// 1365c13e: JMP 0x1337472a

// 1337472a: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack68[0x10000];
RSP = (uint64_t) &stack68[0x10000 - 8];


// 133747b2: MOV RBX,qword ptr [R9 + 0x28]
// switch to context pointer RBX

// 133747b6: LDMXCSR dword ptr [RBX + 0xa8]
MXCSR = *((uint32_t*) (&RSI_old));

// 133747bd: MOV R8,0xf4e5f84c
R8 = 0xf4e5f84c;

// 133747c7: ADD R8,0x4b236a74
R8 += 0x4b236a74;

// 133747ce: MOV R8,qword ptr [R8]
R8 = *((uint64_t*) (R8));

// 133747d1: ADD R8,qword ptr [RBX + 0xa8]
R8 += *((uint64_t*) (&RSI_old));

// 133747d8: MOV AL,byte ptr [R8]
*((uint8_t*) &RAX) = *((uint8_t*) (R8));

// 133747db: MOVZX RAX,AL
RAX = (*((uint8_t*) &RAX)) & 0xFF;

// 133747df: SHL RAX,0x28
RAX <<= 0x28;

// 133747e3: ADD qword ptr [RBX + 0xa0],RAX
*((uint64_t*) (&RBP_old)) += RAX;

// 133747ea: MOV R10,0x1351eeaca
R10 = 0x1351eeaca;

// 133747f4: PUSH R10
RSP -= 8;
*(uint64_t*) (RSP) = R10;

// 133747f6: PUSH 0x1e704207
RSP -= 8;
*(uint64_t*) (RSP) = 0x1e704207;

// 133747fb: PUSH 0xba476e6
RSP -= 8;
*(uint64_t*) (RSP) = 0xba476e6;

// 13374800: PUSH 0x38767d7a
RSP -= 8;
*(uint64_t*) (RSP) = 0x38767d7a;

// 13374805: ADD qword ptr [RSP + 0x18],0xaea6ff6
*((uint64_t*) (RSP + 0x18)) += 0xaea6ff6;

// 1337480e: MOV R12,qword ptr [R9 + 0x28]
// switch to context pointer R12

// 13374812: MOV R12,qword ptr [R12 + 0xa0]
R12 = *((uint64_t*) (&RBP_old));

// 1337481a: JMP 0x1365c4ff

// 1365c4ff: JMP 0x1337485f

// 1337485f: HLT
// ----------------

// 0x00: PushMachframe 0
RSP = *(uint64_t*) (RSP + 0x18);

// 0x00: PushNonVol 3
RBX = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack69[0x10000];
RSP = (uint64_t) &stack69[0x10000 - 8];


// 133748fe: MOV R11,qword ptr [R9 + 0x28]
// switch to context pointer R11

// 13374902: LDMXCSR dword ptr [R11 + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 13374907: MOV R15,qword ptr [R11 + 0x90]
R15 = *((uint64_t*) (&RBX_old));

// 1337490e: MOV RBX,qword ptr [R11 + 0xd8]
RBX = *((uint64_t*) (&R12_old));

// 13374915: JMP 0x1365c637

// 1365c637: JMP 0x1337495c

// 1337495c: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack70[0x10000];
RSP = (uint64_t) &stack70[0x10000 - 8];


// 133749e5: MOV R10,qword ptr [R9 + 0x28]
// switch to context pointer R10

// 133749e9: MOV R15,qword ptr [R10 + 0x90]
R15 = *((uint64_t*) (&RBX_old));

// 133749f0: MOV ESI,dword ptr [R10 + 0x34]
*((uint32_t*) &RSI) = *((uint32_t*) (&MXCSR_old));

// 133749f4: ADD RSI,qword ptr [R10 + 0xf0]
RSI += *((uint64_t*) (&R15_old));

// 133749fb: MOV BPL,byte ptr [RSI]
*((uint8_t*) &RBP) = *((uint8_t*) (RSI));

// 133749fe: MOV RDX,0xff
RDX = 0xff;

// 13374a05: SHL RDX,0x20
RDX <<= 0x20;

// 13374a09: NOT RDX
RDX = ~RDX;

// 13374a0c: AND R15,RDX
R15 &= RDX;

// 13374a0f: MOVZX RDX,BPL
RDX = (*((uint8_t*) &RBP)) & 0xFF;

// 13374a13: SHL RDX,0x20
RDX <<= 0x20;

// 13374a17: OR R15,RDX
R15 |= RDX;

// 13374a1a: JMP 0x1365c7dc

// 1365c7dc: JMP 0x13374a6a

// 13374a6a: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack71[0x10000];
RSP = (uint64_t) &stack71[0x10000 - 8];


// 13374afe: MOV R8,qword ptr [R9 + 0x28]
// switch to context pointer R8

// 13374b02: MOV RAX,qword ptr [R8 + 0xf0]
RAX = *((uint64_t*) (&R15_old));

// 13374b09: PUSH RAX
RSP -= 8;
*(uint64_t*) (RSP) = RAX;

// 13374b0a: MOV RBP,RSP
RBP = RSP;

// 13374b0d: MOV RDI,qword ptr [R8 + 0xf0]
RDI = *((uint64_t*) (&R15_old));

// 13374b14: JMP 0x1365c919

// 1365c919: JMP 0x13374b65

// 13374b65: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = RBP - 0;

// 0x00: AllocLarge 5
RSP += 5;

// 0x00: PushNonVol 1
RCX = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack72[0x10000];
RSP = (uint64_t) &stack72[0x10000 - 8];


// 13374c0a: MOV R14,qword ptr [R9 + 0x28]
// switch to context pointer R14

// 13374c0e: MOV R12,qword ptr [R14 + 0x80]
R12 = *((uint64_t*) (&RCX_old));

// 13374c15: MOV R14,qword ptr [R14 + 0xb0]
R14 = *((uint64_t*) (&RDI_old));

// 13374c1c: MOVZX R12,R12B
R12 = (*((uint8_t*) &R12)) & 0xFF;

// 13374c20: JMP 0x1365ca59

// 1365ca59: JMP 0x13374c6f

// 13374c6f: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack73[0x10000];
RSP = (uint64_t) &stack73[0x10000 - 8];


// 13374d05: MOV RDI,qword ptr [R9 + 0x28]
// switch to context pointer RDI

// 13374d09: LDMXCSR dword ptr [RDI + 0xd8]
MXCSR = *((uint32_t*) (&R12_old));

// 13374d10: MOV R10,0xdb5e5ea3
R10 = 0xdb5e5ea3;

// 13374d1a: ADD R10,0x64ab041d
R10 += 0x64ab041d;

// 13374d21: MOV R10,qword ptr [R10]
R10 = *((uint64_t*) (R10));

// 13374d24: ADD R10,qword ptr [RDI + 0xd8]
R10 += *((uint64_t*) (&R12_old));

// 13374d2b: MOV R14B,byte ptr [R10]
*((uint8_t*) &R14) = *((uint8_t*) (R10));

// 13374d2e: MOVZX R14,R14B
R14 = (*((uint8_t*) &R14)) & 0xFF;

// 13374d32: SHL R14,0x30
R14 <<= 0x30;

// 13374d36: ADD qword ptr [RDI + 0xe8],R14
*((uint64_t*) (&R14_old)) += R14;

// 13374d3d: MOV RDX,0xc6e8437a
RDX = 0xc6e8437a;

// 13374d47: PUSH RDX
RSP -= 8;
*(uint64_t*) (RSP) = RDX;

// 13374d48: PUSH 0x3af6700f
RSP -= 8;
*(uint64_t*) (RSP) = 0x3af6700f;

// 13374d4d: PUSH 0x4447b9d
RSP -= 8;
*(uint64_t*) (RSP) = 0x4447b9d;

// 13374d52: PUSH 0x37d43e6b
RSP -= 8;
*(uint64_t*) (RSP) = 0x37d43e6b;

// 13374d57: PUSH 0x39040ad3
RSP -= 8;
*(uint64_t*) (RSP) = 0x39040ad3;

// 13374d5c: ADD qword ptr [RSP + 0x20],0x79211746
*((uint64_t*) (RSP + 0x20)) += 0x79211746;

// 13374d65: MOV RSI,qword ptr [R9 + 0x28]
// switch to context pointer RSI

// 13374d69: MOV R12,qword ptr [RSI + 0xe8]
R12 = *((uint64_t*) (&R14_old));

// 13374d70: JMP 0x1365ce1b

// 1365ce1b: JMP 0x13374dc3

// 13374dc3: HLT
// ----------------

// 0x00: PushMachframe 1
RSP = *(uint64_t*) (RSP + 0x20);

// 0x00: PushNonVol 9
R9 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack74[0x10000];
RSP = (uint64_t) &stack74[0x10000 - 8];


// 13374e5b: MOV RBP,qword ptr [R9 + 0x28]
// switch to context pointer RBP

// 13374e5f: LDMXCSR dword ptr [RBP + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 13374e63: MOV R12,qword ptr [RBP + 0xc0]
R12 = *((uint64_t*) (&R9_old));

// 13374e6a: MOV RBP,qword ptr [RBP + 0xd8]
RBP = *((uint64_t*) (&R12_old));

// 13374e71: JMP 0x1365cf51

// 1365cf51: JMP 0x13374ebf

// 13374ebf: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack75[0x10000];
RSP = (uint64_t) &stack75[0x10000 - 8];


// 13374f63: MOV R10,qword ptr [R9 + 0x28]
// switch to context pointer R10

// 13374f67: MOV R14,qword ptr [R10 + 0xa0]
R14 = *((uint64_t*) (&RBP_old));

// 13374f6e: MOV R8D,dword ptr [R10 + 0x34]
*((uint32_t*) &R8) = *((uint32_t*) (&MXCSR_old));

// 13374f72: ADD R8,qword ptr [R10 + 0xd8]
R8 += *((uint64_t*) (&R12_old));

// 13374f79: MOV DIL,byte ptr [R8]
*((uint8_t*) &RDI) = *((uint8_t*) (R8));

// 13374f7c: MOV R9,0xff
R9 = 0xff;

// 13374f83: SHL R9,0x28
R9 <<= 0x28;

// 13374f87: NOT R9
R9 = ~R9;

// 13374f8a: AND R14,R9
R14 &= R9;

// 13374f8d: MOVZX R9,DIL
R9 = (*((uint8_t*) &RDI)) & 0xFF;

// 13374f91: SHL R9,0x28
R9 <<= 0x28;

// 13374f95: OR R14,R9
R14 |= R9;

// 13374f98: JMP 0x1365d0ef

// 1365d0ef: JMP 0x13374fe5

// 13374fe5: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack76[0x10000];
RSP = (uint64_t) &stack76[0x10000 - 8];


// 1337507b: MOV R10,0x128536e24
R10 = 0x128536e24;

// 13375085: PUSH R10
RSP -= 8;
*(uint64_t*) (RSP) = R10;

// 13375087: PUSH 0x4b4e3da1
RSP -= 8;
*(uint64_t*) (RSP) = 0x4b4e3da1;

// 1337508c: PUSH 0x6aea72e8
RSP -= 8;
*(uint64_t*) (RSP) = 0x6aea72e8;

// 13375091: PUSH 0x9935467
RSP -= 8;
*(uint64_t*) (RSP) = 0x9935467;

// 13375096: PUSH 0xaa745c1
RSP -= 8;
*(uint64_t*) (RSP) = 0xaa745c1;

// 1337509b: ADD qword ptr [RSP + 0x20],0x18364ac4
*((uint64_t*) (RSP + 0x20)) += 0x18364ac4;

// 133750a4: MOV R9,qword ptr [R9 + 0x28]
// switch to context pointer R9

// 133750a8: MOV RSI,qword ptr [R9 + 0xe8]
RSI = *((uint64_t*) (&R14_old));

// 133750af: JMP 0x1365d2a1

// 1365d2a1: JMP 0x13375103

// 13375103: HLT
// ----------------

// 0x00: PushMachframe 1
RSP = *(uint64_t*) (RSP + 0x20);

// 0x00: PushNonVol 2
RDX = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack77[0x10000];
RSP = (uint64_t) &stack77[0x10000 - 8];


// 133751a1: MOV RDI,qword ptr [R9 + 0x28]
// switch to context pointer RDI

// 133751a5: MOV RSI,qword ptr [RDI + 0x88]
RSI = *((uint64_t*) (&RDX_old));

// 133751ac: MOV RBX,qword ptr [RDI + 0xa8]
RBX = *((uint64_t*) (&RSI_old));

// 133751b3: MOVZX RSI,SIL
RSI = (*((uint8_t*) &RSI)) & 0xFF;

// 133751b7: JMP 0x1365d3da

// 1365d3da: JMP 0x133751fe

// 133751fe: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack78[0x10000];
RSP = (uint64_t) &stack78[0x10000 - 8];


// 1337528c: MOV R10,qword ptr [R9 + 0x28]
// switch to context pointer R10

// 13375290: MOV RAX,qword ptr [R10 + 0xa8]
RAX = *((uint64_t*) (&RSI_old));

// 13375297: MOV RBP,-0x1b21a273
RBP = -0x1b21a273;

// 1337529e: ADD RBP,0x1c0671fe
RBP += 0x1c0671fe;

// 133752a5: PUSH RBP
RSP -= 8;
*(uint64_t*) (RSP) = RBP;

// 133752a6: MOV R12,qword ptr [R10 + 0x90]
R12 = *((uint64_t*) (&RBX_old));

// 133752ad: MUL qword ptr [RSP]
RAX *= *((uint64_t*) (RSP));

// 133752b1: MOV R15,RAX
R15 = RAX;

// 133752b4: JMP 0x1365d5e0

// 1365d5e0: JMP 0x13375306

// 13375306: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack79[0x10000];
RSP = (uint64_t) &stack79[0x10000 - 8];


// 133753a9: MOV RSI,qword ptr [R9 + 0x28]
// switch to context pointer RSI

// 133753ad: MOV RDI,qword ptr [RSI + 0xd8]
RDI = *((uint64_t*) (&R12_old));

// 133753b4: SUB RDI,qword ptr [RSI + 0xf0]
RDI -= *((uint64_t*) (&R15_old));

// 133753bb: JMP 0x1365d71a

// 1365d71a: JMP 0x1337540b

// 1337540b: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack80[0x10000];
RSP = (uint64_t) &stack80[0x10000 - 8];


// 133754ac: MOV RCX,qword ptr [R9 + 0x28]
// switch to context pointer RCX

// 133754b0: MOV RAX,qword ptr [RCX + 0xb0]
RAX = *((uint64_t*) (&RDI_old));

// 133754b7: PUSH RAX
RSP -= 8;
*(uint64_t*) (RSP) = RAX;

// 133754b8: MOV R15,RSP
R15 = RSP;

// 133754bb: MOV R12,qword ptr [RCX + 0xb0]
R12 = *((uint64_t*) (&RDI_old));

// 133754c2: JMP 0x1365d854

// 1365d854: JMP 0x13375507

// 13375507: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = R15 - 0;

// 0x00: PushNonVol 13
R13 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack81[0x10000];
RSP = (uint64_t) &stack81[0x10000 - 8];


// 133755a0: MOV RBP,qword ptr [R9 + 0x28]
// switch to context pointer RBP

// 133755a4: MOV RBX,qword ptr [RBP + 0xe0]
RBX = *((uint64_t*) (&R13_old));

// 133755ab: MOV R12,qword ptr [RBP + 0xd8]
R12 = *((uint64_t*) (&R12_old));

// 133755b2: MOVZX RBX,BL
RBX = (*((uint8_t*) &RBX)) & 0xFF;

// 133755b6: JMP 0x1365d98e

// 1365d98e: JMP 0x13375603

// 13375603: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack82[0x10000];
RSP = (uint64_t) &stack82[0x10000 - 8];


// 133756a8: MOV RBP,qword ptr [R9 + 0x28]
// switch to context pointer RBP

// 133756ac: LDMXCSR dword ptr [RBP + 0x90]
MXCSR = *((uint32_t*) (&RBX_old));

// 133756b3: MOV R12,0x1093b017b
R12 = 0x1093b017b;

// 133756bd: ADD R12,0x36ce7145
R12 += 0x36ce7145;

// 133756c4: MOV R12,qword ptr [R12 + 0x6f0]
R12 = *((uint64_t*) (R12 + 0x6f0));

// 133756cc: ADD R12,qword ptr [RBP + 0x90]
R12 += *((uint64_t*) (&RBX_old));

// 133756d3: MOV R14B,byte ptr [R12]
*((uint8_t*) &R14) = *((uint8_t*) (R12));

// 133756d7: MOVZX R14,R14B
R14 = (*((uint8_t*) &R14)) & 0xFF;

// 133756db: SHL R14,0x8
R14 <<= 0x8;

// 133756df: SUB qword ptr [RBP + 0xd8],R14
*((uint64_t*) (&R12_old)) -= R14;

// 133756e6: MOV RBX,qword ptr [R9 + 0x28]
// switch to context pointer RBX

// 133756ea: MOV RBP,qword ptr [RBX + 0xd8]
RBP = *((uint64_t*) (&R12_old));

// 133756f1: MOV R14,0xde6f21d0
R14 = 0xde6f21d0;

// 133756fb: ADD R14,0x619a48f0
R14 += 0x619a48f0;

// 13375702: JMP 0x1365dda1

// 1365dda1: JMP 0x13375749

// 13375749: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = R14 - 0;

// 0x00: AllocLarge 1776
RSP += 1776;

// 0x00: PushNonVol 14
R14 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack83[0x10000];
RSP = (uint64_t) &stack83[0x10000 - 8];


// 133757f6: MOV R9,qword ptr [R9 + 0x28]
// switch to context pointer R9

// 133757fa: LDMXCSR dword ptr [R9 + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 133757ff: MOV R12,qword ptr [R9 + 0xe8]
R12 = *((uint64_t*) (&R14_old));

// 13375806: MOV RDI,qword ptr [R9 + 0xa0]
RDI = *((uint64_t*) (&RBP_old));

// 1337580d: JMP 0x1365ded5

// 1365ded5: JMP 0x1337585b

// 1337585b: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack84[0x10000];
RSP = (uint64_t) &stack84[0x10000 - 8];


// 133758ed: MOV RDI,qword ptr [R9 + 0x28]
// switch to context pointer RDI

// 133758f1: MOV RBX,qword ptr [RDI + 0xb0]
RBX = *((uint64_t*) (&RDI_old));

// 133758f8: MOV EDX,dword ptr [RDI + 0x34]
*((uint32_t*) &RDX) = *((uint32_t*) (&MXCSR_old));

// 133758fb: ADD RDX,qword ptr [RDI + 0xd8]
RDX += *((uint64_t*) (&R12_old));

// 13375902: MOV BPL,byte ptr [RDX]
*((uint8_t*) &RBP) = *((uint8_t*) (RDX));

// 13375905: MOV BL,BPL
*((uint8_t*) &RBX) = *((uint8_t*) &RBP);

// 13375908: JMP 0x1365e010

// 1365e010: JMP 0x13375950

// 13375950: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack85[0x10000];
RSP = (uint64_t) &stack85[0x10000 - 8];


// 133759ed: MOV RBP,qword ptr [R9 + 0x28]
// switch to context pointer RBP

// 133759f1: MOV R11,qword ptr [RBP + 0x90]
R11 = *((uint64_t*) (&RBX_old));

// 133759f8: PUSH R11
RSP -= 8;
*(uint64_t*) (RSP) = R11;

// 133759fa: MOV RDI,RSP
RDI = RSP;

// 133759fd: MOV RSI,qword ptr [RBP + 0x90]
RSI = *((uint64_t*) (&RBX_old));

// 13375a04: JMP 0x1365e146

// 1365e146: JMP 0x13375a55

// 13375a55: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack86[0x10000];
RSP = (uint64_t) &stack86[0x10000 - 8];


// 13375ae2: MOV R11,qword ptr [R9 + 0x28]
// switch to context pointer R11

// 13375ae6: MOV RDI,qword ptr [R11 + 0xb0]
RDI = *((uint64_t*) (&RDI_old));

// 13375aed: MOV R13,qword ptr [R11 + 0xa8]
R13 = *((uint64_t*) (&RSI_old));

// 13375af4: PUSH RDI
RSP -= 8;
*(uint64_t*) (RSP) = RDI;

// 13375af5: PUSH 0x5b5153d
RSP -= 8;
*(uint64_t*) (RSP) = 0x5b5153d;

// 13375afa: PUSH 0x50ba4e00
RSP -= 8;
*(uint64_t*) (RSP) = 0x50ba4e00;

// 13375aff: PUSH 0x4f897bb1
RSP -= 8;
*(uint64_t*) (RSP) = 0x4f897bb1;

// 13375b04: PUSH 0x6fcc5245
RSP -= 8;
*(uint64_t*) (RSP) = 0x6fcc5245;

// 13375b09: JMP 0x1365e27c

// 1365e27c: JMP 0x13375b54

// 13375b54: HLT
// ----------------

// 0x00: PushMachframe 1
RSP = *(uint64_t*) (RSP + 0x20);

// 0x00: AllocLarge 1
RSP += 1;

// 0x00: PushNonVol 10
R10 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack87[0x10000];
RSP = (uint64_t) &stack87[0x10000 - 8];


// 13375bf6: MOV R10,qword ptr [R9 + 0x28]
// switch to context pointer R10

// 13375bfa: MOV R12,qword ptr [R10 + 0xc8]
R12 = *((uint64_t*) (&R10_old));

// 13375c01: MOV RBX,qword ptr [R10 + 0xe0]
RBX = *((uint64_t*) (&R13_old));

// 13375c08: MOVZX R12,R12B
R12 = (*((uint8_t*) &R12)) & 0xFF;

// 13375c0c: JMP 0x1365e3c0

// 1365e3c0: JMP 0x13375c59

// 13375c59: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack88[0x10000];
RSP = (uint64_t) &stack88[0x10000 - 8];


// 13375ce6: MOV RSI,qword ptr [R9 + 0x28]
// switch to context pointer RSI

// 13375cea: LDMXCSR dword ptr [RSI + 0xd8]
MXCSR = *((uint32_t*) (&R12_old));

// 13375cf1: MOV R10,0xd4dd17dd
R10 = 0xd4dd17dd;

// 13375cfb: ADD R10,0x6b2c5ae3
R10 += 0x6b2c5ae3;

// 13375d02: MOV R10,qword ptr [R10 + 0x5d8]
R10 = *((uint64_t*) (R10 + 0x5d8));

// 13375d09: ADD R10,qword ptr [RSI + 0xd8]
R10 += *((uint64_t*) (&R12_old));

// 13375d10: MOV R14B,byte ptr [R10]
*((uint8_t*) &R14) = *((uint8_t*) (R10));

// 13375d13: MOVZX R14,R14B
R14 = (*((uint8_t*) &R14)) & 0xFF;

// 13375d17: SHL R14,0x10
R14 <<= 0x10;

// 13375d1b: SUB qword ptr [RSI + 0x90],R14
*((uint64_t*) (&RBX_old)) -= R14;

// 13375d22: MOV RSI,qword ptr [R9 + 0x28]
// switch to context pointer RSI

// 13375d26: MOV RSI,qword ptr [RSI + 0x90]
RSI = *((uint64_t*) (&RBX_old));

// 13375d2d: MOV R15,0x1212500bb
R15 = 0x1212500bb;

// 13375d37: ADD R15,0x1ee46a05
R15 += 0x1ee46a05;

// 13375d3e: JMP 0x1365e7dc

// 1365e7dc: JMP 0x13375d7f

// 13375d7f: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = R15 - 0;

// 0x00: AllocLarge 1496
RSP += 1496;

// 0x00: PushNonVol 13
R13 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack89[0x10000];
RSP = (uint64_t) &stack89[0x10000 - 8];


// 13375e20: MOV R14,qword ptr [R9 + 0x28]
// switch to context pointer R14

// 13375e24: LDMXCSR dword ptr [R14 + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 13375e29: MOV RBX,qword ptr [R14 + 0xe0]
RBX = *((uint64_t*) (&R13_old));

// 13375e30: MOV R12,qword ptr [R14 + 0xa8]
R12 = *((uint64_t*) (&RSI_old));

// 13375e37: JMP 0x1365e90b

// 1365e90b: JMP 0x13375e7d

// 13375e7d: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack90[0x10000];
RSP = (uint64_t) &stack90[0x10000 - 8];


// 13375f15: MOV R8,qword ptr [R9 + 0x28]
// switch to context pointer R8

// 13375f19: MOV R15,qword ptr [R8 + 0xd8]
R15 = *((uint64_t*) (&R12_old));

// 13375f20: MOV EDI,dword ptr [R8 + 0x34]
*((uint32_t*) &RDI) = *((uint32_t*) (&MXCSR_old));

// 13375f24: ADD RDI,qword ptr [R8 + 0x90]
RDI += *((uint64_t*) (&RBX_old));

// 13375f2b: MOV DL,byte ptr [RDI]
*((uint8_t*) &RDX) = *((uint8_t*) (RDI));

// 13375f2d: MOV R13,0xff
R13 = 0xff;

// 13375f34: SHL R13,0x8
R13 <<= 0x8;

// 13375f38: NOT R13
R13 = ~R13;

// 13375f3b: AND R15,R13
R15 &= R13;

// 13375f3e: MOVZX R13,DL
R13 = (*((uint8_t*) &RDX)) & 0xFF;

// 13375f42: SHL R13,0x8
R13 <<= 0x8;

// 13375f46: OR R15,R13
R15 |= R13;

// 13375f49: JMP 0x1365eaa7

// 1365eaa7: JMP 0x13375f91

// 13375f91: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack91[0x10000];
RSP = (uint64_t) &stack91[0x10000 - 8];


// 13376038: MOV RCX,qword ptr [R9 + 0x28]
// switch to context pointer RCX

// 1337603c: MOV R13,qword ptr [RCX + 0xf0]
R13 = *((uint64_t*) (&R15_old));

// 13376043: PUSH R13
RSP -= 8;
*(uint64_t*) (RSP) = R13;

// 13376045: MOV R12,RSP
R12 = RSP;

// 13376048: MOV RDI,qword ptr [RCX + 0xf0]
RDI = *((uint64_t*) (&R15_old));

// 1337604f: JMP 0x1365ebdf

// 1365ebdf: JMP 0x13376094

// 13376094: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack92[0x10000];
RSP = (uint64_t) &stack92[0x10000 - 8];


// 1337613c: MOV RBP,qword ptr [R9 + 0x28]
// switch to context pointer RBP

// 13376140: MOV RSI,qword ptr [RBP + 0xd8]
RSI = *((uint64_t*) (&R12_old));

// 13376147: MOV R12,qword ptr [RBP + 0xb0]
R12 = *((uint64_t*) (&RDI_old));

// 1337614e: PUSH RSI
RSP -= 8;
*(uint64_t*) (RSP) = RSI;

// 1337614f: PUSH 0x54db672a
RSP -= 8;
*(uint64_t*) (RSP) = 0x54db672a;

// 13376154: PUSH 0x6c05691
RSP -= 8;
*(uint64_t*) (RSP) = 0x6c05691;

// 13376159: PUSH 0x1033552c
RSP -= 8;
*(uint64_t*) (RSP) = 0x1033552c;

// 1337615e: PUSH 0x61753d3f
RSP -= 8;
*(uint64_t*) (RSP) = 0x61753d3f;

// 13376163: JMP 0x1365ed1a

// 1365ed1a: JMP 0x133761a6

// 133761a6: HLT
// ----------------

// 0x00: PushMachframe 1
RSP = *(uint64_t*) (RSP + 0x20);

// 0x00: AllocLarge 2
RSP += 2;

// 0x00: PushNonVol 0
RAX = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack93[0x10000];
RSP = (uint64_t) &stack93[0x10000 - 8];


// 13376249: MOV RBX,qword ptr [R9 + 0x28]
// switch to context pointer RBX

// 1337624d: MOV R13,qword ptr [RBX + 0x78]
R13 = *((uint64_t*) (&RAX_old));

// 13376251: MOV RDI,qword ptr [RBX + 0xd8]
RDI = *((uint64_t*) (&R12_old));

// 13376258: MOVZX R13,R13B
R13 = (*((uint8_t*) &R13)) & 0xFF;

// 1337625c: JMP 0x1365ede7

// 1365ede7: JMP 0x133762a4

// 133762a4: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack94[0x10000];
RSP = (uint64_t) &stack94[0x10000 - 8];


// 13376332: MOV R15,qword ptr [R9 + 0x28]
// switch to context pointer R15

// 13376336: LDMXCSR dword ptr [R15 + 0xe0]
MXCSR = *((uint32_t*) (&R13_old));

// 1337633e: MOV RCX,0x10e2147d5
RCX = 0x10e2147d5;

// 13376348: ADD RCX,0x31e82aeb
RCX += 0x31e82aeb;

// 1337634f: MOV RCX,qword ptr [RCX + 0x1f8]
RCX = *((uint64_t*) (RCX + 0x1f8));

// 13376356: ADD RCX,qword ptr [R15 + 0xe0]
RCX += *((uint64_t*) (&R13_old));

// 1337635d: MOV R12B,byte ptr [RCX]
*((uint8_t*) &R12) = *((uint8_t*) (RCX));

// 13376360: MOVZX R12,R12B
R12 = (*((uint8_t*) &R12)) & 0xFF;

// 13376364: SHL R12,0x18
R12 <<= 0x18;

// 13376368: SUB qword ptr [R15 + 0xb0],R12
*((uint64_t*) (&RDI_old)) -= R12;

// 1337636f: MOV R8,0x1048763eb
R8 = 0x1048763eb;

// 13376379: PUSH R8
RSP -= 8;
*(uint64_t*) (RSP) = R8;

// 1337637b: PUSH 0x349c620f
RSP -= 8;
*(uint64_t*) (RSP) = 0x349c620f;

// 13376380: PUSH 0x5f716e89
RSP -= 8;
*(uint64_t*) (RSP) = 0x5f716e89;

// 13376385: PUSH 0x638d5660
RSP -= 8;
*(uint64_t*) (RSP) = 0x638d5660;

// 1337638a: PUSH 0x1ec006d2
RSP -= 8;
*(uint64_t*) (RSP) = 0x1ec006d2;

// 1337638f: ADD qword ptr [RSP + 0x20],0x3b8206d5
*((uint64_t*) (RSP + 0x20)) += 0x3b8206d5;

// 13376398: MOV RBP,qword ptr [R9 + 0x28]
// switch to context pointer RBP

// 1337639c: MOV RBX,qword ptr [RBP + 0xb0]
RBX = *((uint64_t*) (&RDI_old));

// 133763a3: JMP 0x1365f207

// 1365f207: JMP 0x133763ee

// 133763ee: HLT
// ----------------

// 0x00: PushMachframe 1
RSP = *(uint64_t*) (RSP + 0x20);

// 0x00: AllocLarge 504
RSP += 504;

// 0x00: PushNonVol 5
RBP = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack95[0x10000];
RSP = (uint64_t) &stack95[0x10000 - 8];


// 13376487: MOV RBX,qword ptr [R9 + 0x28]
// switch to context pointer RBX

// 1337648b: LDMXCSR dword ptr [RBX + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 1337648f: MOV RDI,qword ptr [RBX + 0xa0]
RDI = *((uint64_t*) (&RBP_old));

// 13376496: MOV RBP,qword ptr [RBX + 0x90]
RBP = *((uint64_t*) (&RBX_old));

// 1337649d: JMP 0x1365f34c

// 1365f34c: JMP 0x133764e0

// 133764e0: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack96[0x10000];
RSP = (uint64_t) &stack96[0x10000 - 8];


// 13376573: MOV RCX,qword ptr [R9 + 0x28]
// switch to context pointer RCX

// 13376577: MOV R12,qword ptr [RCX + 0xa0]
R12 = *((uint64_t*) (&RBP_old));

// 1337657e: MOV EAX,dword ptr [RCX + 0x34]
*((uint32_t*) &RAX) = *((uint32_t*) (&MXCSR_old));

// 13376581: ADD RAX,qword ptr [RCX + 0xb0]
RAX += *((uint64_t*) (&RDI_old));

// 13376588: MOV R14B,byte ptr [RAX]
*((uint8_t*) &R14) = *((uint8_t*) (RAX));

// 1337658b: MOV RCX,0xff
RCX = 0xff;

// 13376592: SHL RCX,0x10
RCX <<= 0x10;

// 13376596: NOT RCX
RCX = ~RCX;

// 13376599: AND R12,RCX
R12 &= RCX;

// 1337659c: MOVZX RCX,R14B
RCX = (*((uint8_t*) &R14)) & 0xFF;

// 133765a0: SHL RCX,0x10
RCX <<= 0x10;

// 133765a4: OR R12,RCX
R12 |= RCX;

// 133765a7: JMP 0x1365f4eb

// 1365f4eb: JMP 0x133765f7

// 133765f7: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack97[0x10000];
RSP = (uint64_t) &stack97[0x10000 - 8];


// 13376697: MOV RSI,qword ptr [R9 + 0x28]
// switch to context pointer RSI

// 1337669b: MOV R12,qword ptr [RSI + 0xd8]
R12 = *((uint64_t*) (&R12_old));

// 133766a2: PUSH R12
RSP -= 8;
*(uint64_t*) (RSP) = R12;

// 133766a4: MOV RBP,RSP
RBP = RSP;

// 133766a7: MOV R13,qword ptr [RSI + 0xd8]
R13 = *((uint64_t*) (&R12_old));

// 133766ae: JMP 0x1365f629

// 1365f629: JMP 0x13376702

// 13376702: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack98[0x10000];
RSP = (uint64_t) &stack98[0x10000 - 8];


// 13376795: MOV R12,qword ptr [R9 + 0x28]
// switch to context pointer R12

// 13376799: MOV RCX,qword ptr [R12 + 0xa0]
RCX = *((uint64_t*) (&RBP_old));

// 133767a1: MOV RSI,qword ptr [R12 + 0xe0]
RSI = *((uint64_t*) (&R13_old));

// 133767a9: PUSH RCX
RSP -= 8;
*(uint64_t*) (RSP) = RCX;

// 133767aa: PUSH 0x6ecd7abf
RSP -= 8;
*(uint64_t*) (RSP) = 0x6ecd7abf;

// 133767af: PUSH 0x3fb70ec1
RSP -= 8;
*(uint64_t*) (RSP) = 0x3fb70ec1;

// 133767b4: PUSH 0x1e3d2ad2
RSP -= 8;
*(uint64_t*) (RSP) = 0x1e3d2ad2;

// 133767b9: JMP 0x1365f762

// 1365f762: JMP 0x13376807

// 13376807: HLT
// ----------------

// 0x00: PushMachframe 0
RSP = *(uint64_t*) (RSP + 0x18);

// 0x00: AllocLarge 3
RSP += 3;

// 0x00: PushNonVol 10
R10 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack99[0x10000];
RSP = (uint64_t) &stack99[0x10000 - 8];


// 133768a6: MOV R11,qword ptr [R9 + 0x28]
// switch to context pointer R11

// 133768aa: MOV RBX,qword ptr [R11 + 0xc8]
RBX = *((uint64_t*) (&R10_old));

// 133768b1: MOV R13,qword ptr [R11 + 0xa8]
R13 = *((uint64_t*) (&RSI_old));

// 133768b8: MOVZX RBX,BL
RBX = (*((uint8_t*) &RBX)) & 0xFF;

// 133768bc: JMP 0x1365f89d

// 1365f89d: JMP 0x13376905

// 13376905: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack100[0x10000];
RSP = (uint64_t) &stack100[0x10000 - 8];


// 1337699c: MOV RBP,qword ptr [R9 + 0x28]
// switch to context pointer RBP

// 133769a0: LDMXCSR dword ptr [RBP + 0x90]
MXCSR = *((uint32_t*) (&RBX_old));

// 133769a7: MOV R8,0x133c7214c
R8 = 0x133c7214c;

// 133769b1: ADD R8,0xc425174
R8 += 0xc425174;

// 133769b8: MOV R8,qword ptr [R8 + 0x488]
R8 = *((uint64_t*) (R8 + 0x488));

// 133769bf: ADD R8,qword ptr [RBP + 0x90]
R8 += *((uint64_t*) (&RBX_old));

// 133769c6: MOV R12B,byte ptr [R8]
*((uint8_t*) &R12) = *((uint8_t*) (R8));

// 133769c9: MOVZX R12,R12B
R12 = (*((uint8_t*) &R12)) & 0xFF;

// 133769cd: SHL R12,0x20
R12 <<= 0x20;

// 133769d1: SUB qword ptr [RBP + 0xe0],R12
*((uint64_t*) (&R13_old)) -= R12;

// 133769d8: MOV R14,qword ptr [R9 + 0x28]
// switch to context pointer R14

// 133769dc: MOV RDI,qword ptr [R14 + 0xe0]
RDI = *((uint64_t*) (&R13_old));

// 133769e3: MOV RBX,0xd9d33b57
RBX = 0xd9d33b57;

// 133769ed: ADD RBX,0x66362f69
RBX += 0x66362f69;

// 133769f4: JMP 0x1365fccc

// 1365fccc: JMP 0x13376a3d

// 13376a3d: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = RBX - 0;

// 0x00: AllocLarge 1160
RSP += 1160;

// 0x00: PushNonVol 0
RAX = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack101[0x10000];
RSP = (uint64_t) &stack101[0x10000 - 8];


// 13376ae3: MOV RBX,qword ptr [R9 + 0x28]
// switch to context pointer RBX

// 13376ae7: LDMXCSR dword ptr [RBX + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 13376aeb: MOV R12,qword ptr [RBX + 0x78]
R12 = *((uint64_t*) (&RAX_old));

// 13376aef: MOV R14,qword ptr [RBX + 0xb0]
R14 = *((uint64_t*) (&RDI_old));

// 13376af6: JMP 0x1365fd9d

// 1365fd9d: JMP 0x13376b3a

// 13376b3a: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack102[0x10000];
RSP = (uint64_t) &stack102[0x10000 - 8];


// 13376bcd: MOV RSI,qword ptr [R9 + 0x28]
// switch to context pointer RSI

// 13376bd1: MOV R13,qword ptr [RSI + 0xe8]
R13 = *((uint64_t*) (&R14_old));

// 13376bd8: MOV R8D,dword ptr [RSI + 0x34]
*((uint32_t*) &R8) = *((uint32_t*) (&MXCSR_old));

// 13376bdc: ADD R8,qword ptr [RSI + 0xd8]
R8 += *((uint64_t*) (&R12_old));

// 13376be3: MOV R12B,byte ptr [R8]
*((uint8_t*) &R12) = *((uint8_t*) (R8));

// 13376be6: MOV R8,0xff
R8 = 0xff;

// 13376bed: SHL R8,0x18
R8 <<= 0x18;

// 13376bf1: NOT R8
R8 = ~R8;

// 13376bf4: AND R13,R8
R13 &= R8;

// 13376bf7: MOVZX R8,R12B
R8 = (*((uint8_t*) &R12)) & 0xFF;

// 13376bfb: SHL R8,0x18
R8 <<= 0x18;

// 13376bff: OR R13,R8
R13 |= R8;

// 13376c02: JMP 0x1365ff3d

// 1365ff3d: JMP 0x13376c47

// 13376c47: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack103[0x10000];
RSP = (uint64_t) &stack103[0x10000 - 8];


// 13376ce8: MOV RBX,qword ptr [R9 + 0x28]
// switch to context pointer RBX

// 13376cec: MOV RAX,qword ptr [RBX + 0xe0]
RAX = *((uint64_t*) (&R13_old));

// 13376cf3: PUSH RAX
RSP -= 8;
*(uint64_t*) (RSP) = RAX;

// 13376cf4: MOV RSI,RSP
RSI = RSP;

// 13376cf7: MOV R15,qword ptr [RBX + 0xe0]
R15 = *((uint64_t*) (&R13_old));

// 13376cfe: JMP 0x13660073

// 13660073: JMP 0x13376d51

// 13376d51: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack104[0x10000];
RSP = (uint64_t) &stack104[0x10000 - 8];


// 13376dde: MOV R9,qword ptr [R9 + 0x28]
// switch to context pointer R9

// 13376de2: MOV RAX,qword ptr [R9 + 0xa8]
RAX = *((uint64_t*) (&RSI_old));

// 13376de9: MOV R15,qword ptr [R9 + 0xf0]
R15 = *((uint64_t*) (&R15_old));

// 13376df0: PUSH RAX
RSP -= 8;
*(uint64_t*) (RSP) = RAX;

// 13376df1: PUSH 0x568b41c0
RSP -= 8;
*(uint64_t*) (RSP) = 0x568b41c0;

// 13376df6: PUSH 0x1521557c
RSP -= 8;
*(uint64_t*) (RSP) = 0x1521557c;

// 13376dfb: PUSH 0x489a0375
RSP -= 8;
*(uint64_t*) (RSP) = 0x489a0375;

// 13376e00: JMP 0x136601b0

// 136601b0: JMP 0x13376e48

// 13376e48: HLT
// ----------------

// 0x00: PushMachframe 0
RSP = *(uint64_t*) (RSP + 0x18);

// 0x00: AllocLarge 5
RSP += 5;

// 0x00: PushNonVol 2
RDX = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack105[0x10000];
RSP = (uint64_t) &stack105[0x10000 - 8];


// 13376eed: MOV R9,qword ptr [R9 + 0x28]
// switch to context pointer R9

// 13376ef1: MOV RBX,qword ptr [R9 + 0x88]
RBX = *((uint64_t*) (&RDX_old));

// 13376ef8: MOV RDI,qword ptr [R9 + 0xf0]
RDI = *((uint64_t*) (&R15_old));

// 13376eff: MOVZX RBX,BL
RBX = (*((uint8_t*) &RBX)) & 0xFF;

// 13376f03: JMP 0x136602e2

// 136602e2: JMP 0x13376f4c

// 13376f4c: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack106[0x10000];
RSP = (uint64_t) &stack106[0x10000 - 8];


// 13376fe0: MOV RBP,qword ptr [R9 + 0x28]
// switch to context pointer RBP

// 13376fe4: LDMXCSR dword ptr [RBP + 0x90]
MXCSR = *((uint32_t*) (&RBX_old));

// 13376feb: MOV RCX,0xf4914bcf
RCX = 0xf4914bcf;

// 13376ff5: ADD RCX,0x4b7826f1
RCX += 0x4b7826f1;

// 13376ffc: MOV RCX,qword ptr [RCX]
RCX = *((uint64_t*) (RCX));

// 13376fff: ADD RCX,qword ptr [RBP + 0x90]
RCX += *((uint64_t*) (&RBX_old));

// 13377006: MOV R15B,byte ptr [RCX]
*((uint8_t*) &R15) = *((uint8_t*) (RCX));

// 13377009: MOVZX R15,R15B
R15 = (*((uint8_t*) &R15)) & 0xFF;

// 1337700d: SHL R15,0x30
R15 <<= 0x30;

// 13377011: SUB qword ptr [RBP + 0xb0],R15
*((uint64_t*) (&RDI_old)) -= R15;

// 13377018: MOV R14,qword ptr [R9 + 0x28]
// switch to context pointer R14

// 1337701c: MOV R13,qword ptr [R14 + 0xb0]
R13 = *((uint64_t*) (&RDI_old));

// 13377023: MOV RSI,0x1142d2306
RSI = 0x1142d2306;

// 1337702d: ADD RSI,0x2bdc47ba
RSI += 0x2bdc47ba;

// 13377034: JMP 0x1366069c

// 1366069c: JMP 0x13377086

// 13377086: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = RSI - 0;

// 0x00: PushNonVol 1
RCX = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack107[0x10000];
RSP = (uint64_t) &stack107[0x10000 - 8];


// 13377113: MOV RSI,qword ptr [R9 + 0x28]
// switch to context pointer RSI

// 13377117: LDMXCSR dword ptr [RSI + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 1337711b: MOV R14,qword ptr [RSI + 0x80]
R14 = *((uint64_t*) (&RCX_old));

// 13377122: MOV R15,qword ptr [RSI + 0xe0]
R15 = *((uint64_t*) (&R13_old));

// 13377129: JMP 0x136607cf

// 136607cf: JMP 0x1337717c

// 1337717c: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack108[0x10000];
RSP = (uint64_t) &stack108[0x10000 - 8];


// 1337720d: MOV R10,qword ptr [R9 + 0x28]
// switch to context pointer R10

// 13377211: MOV RBP,qword ptr [R10 + 0xf0]
RBP = *((uint64_t*) (&R15_old));

// 13377218: MOV R8D,dword ptr [R10 + 0x34]
*((uint32_t*) &R8) = *((uint32_t*) (&MXCSR_old));

// 1337721c: ADD R8,qword ptr [R10 + 0xe8]
R8 += *((uint64_t*) (&R14_old));

// 13377223: MOV SIL,byte ptr [R8]
*((uint8_t*) &RSI) = *((uint8_t*) (R8));

// 13377226: MOV R14,0xff
R14 = 0xff;

// 1337722d: SHL R14,0x28
R14 <<= 0x28;

// 13377231: NOT R14
R14 = ~R14;

// 13377234: AND RBP,R14
RBP &= R14;

// 13377237: MOVZX R14,SIL
R14 = (*((uint8_t*) &RSI)) & 0xFF;

// 1337723b: SHL R14,0x28
R14 <<= 0x28;

// 1337723f: OR RBP,R14
RBP |= R14;

// 13377242: JMP 0x13660972

// 13660972: JMP 0x13377291

// 13377291: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack109[0x10000];
RSP = (uint64_t) &stack109[0x10000 - 8];


// 1337732c: MOV RDX,qword ptr [R9 + 0x28]
// switch to context pointer RDX

// 13377330: MOV R11,qword ptr [RDX + 0xa0]
R11 = *((uint64_t*) (&RBP_old));

// 13377337: PUSH R11
RSP -= 8;
*(uint64_t*) (RSP) = R11;

// 13377339: MOV RSI,RSP
RSI = RSP;

// 1337733c: MOV R13,qword ptr [RDX + 0xa0]
R13 = *((uint64_t*) (&RBP_old));

// 13377343: JMP 0x13660aad

// 13660aad: JMP 0x13377393

// 13377393: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = RSI - 0;

// 0x00: AllocLarge 6
RSP += 6;

// 0x00: PushNonVol 7
RDI = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack110[0x10000];
RSP = (uint64_t) &stack110[0x10000 - 8];


// 1337743f: MOV R14,qword ptr [R9 + 0x28]
// switch to context pointer R14

// 13377443: MOV R15,qword ptr [R14 + 0xb0]
R15 = *((uint64_t*) (&RDI_old));

// 1337744a: MOV RSI,qword ptr [R14 + 0xe0]
RSI = *((uint64_t*) (&R13_old));

// 13377451: MOVZX R15,R15B
R15 = (*((uint8_t*) &R15)) & 0xFF;

// 13377455: JMP 0x13660be5

// 13660be5: JMP 0x133774a0

// 133774a0: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack111[0x10000];
RSP = (uint64_t) &stack111[0x10000 - 8];


// 13377534: MOV R11,qword ptr [R9 + 0x28]
// switch to context pointer R11

// 13377538: LDMXCSR dword ptr [R11 + 0xf0]
MXCSR = *((uint32_t*) (&R15_old));

// 13377540: MOV RSI,0x103cd6d9f
RSI = 0x103cd6d9f;

// 1337754a: ADD RSI,0x3c3c0521
RSI += 0x3c3c0521;

// 13377551: MOV RSI,qword ptr [RSI]
RSI = *((uint64_t*) (RSI));

// 13377554: ADD RSI,qword ptr [R11 + 0xf0]
RSI += *((uint64_t*) (&R15_old));

// 1337755b: MOV DL,byte ptr [RSI]
*((uint8_t*) &RDX) = *((uint8_t*) (RSI));

// 1337755d: MOVZX RDX,DL
RDX = (*((uint8_t*) &RDX)) & 0xFF;

// 13377561: SHL RDX,0x38
RDX <<= 0x38;

// 13377565: SUB qword ptr [R11 + 0xa8],RDX
*((uint64_t*) (&RSI_old)) -= RDX;

// 1337756c: MOV RCX,0xd3df260f
RCX = 0xd3df260f;

// 13377576: PUSH RCX
RSP -= 8;
*(uint64_t*) (RSP) = RCX;

// 13377577: PUSH 0x48fb4d23
RSP -= 8;
*(uint64_t*) (RSP) = 0x48fb4d23;

// 1337757c: PUSH 0x33f14a5b
RSP -= 8;
*(uint64_t*) (RSP) = 0x33f14a5b;

// 13377581: PUSH 0x5ae08ba
RSP -= 8;
*(uint64_t*) (RSP) = 0x5ae08ba;

// 13377586: PUSH 0x642a6b77
RSP -= 8;
*(uint64_t*) (RSP) = 0x642a6b77;

// 1337758b: ADD qword ptr [RSP + 0x20],0x6c2a44b1
*((uint64_t*) (RSP + 0x20)) += 0x6c2a44b1;

// 13377594: MOV RDI,qword ptr [R9 + 0x28]
// switch to context pointer RDI

// 13377598: MOV R15,qword ptr [RDI + 0xa8]
R15 = *((uint64_t*) (&RSI_old));

// 1337759f: JMP 0x13660fa2

// 13660fa2: JMP 0x133775e4

// 133775e4: HLT
// ----------------

// 0x00: PushMachframe 1
RSP = *(uint64_t*) (RSP + 0x20);

// 0x00: PushNonVol 6
RSI = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack112[0x10000];
RSP = (uint64_t) &stack112[0x10000 - 8];


// 1337767e: MOV R11,qword ptr [R9 + 0x28]
// switch to context pointer R11

// 13377682: LDMXCSR dword ptr [R11 + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 13377687: MOV RBX,qword ptr [R11 + 0xa8]
RBX = *((uint64_t*) (&RSI_old));

// 1337768e: MOV R14,qword ptr [R11 + 0xf0]
R14 = *((uint64_t*) (&R15_old));

// 13377695: JMP 0x136610dd

// 136610dd: JMP 0x133776e4

// 133776e4: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack113[0x10000];
RSP = (uint64_t) &stack113[0x10000 - 8];


// 1337776b: MOV RCX,qword ptr [R9 + 0x28]
// switch to context pointer RCX

// 1337776f: MOV R15,qword ptr [RCX + 0xe8]
R15 = *((uint64_t*) (&R14_old));

// 13377776: MOV EAX,dword ptr [RCX + 0x34]
*((uint32_t*) &RAX) = *((uint32_t*) (&MXCSR_old));

// 13377779: ADD RAX,qword ptr [RCX + 0x90]
RAX += *((uint64_t*) (&RBX_old));

// 13377780: MOV CL,byte ptr [RAX]
*((uint8_t*) &RCX) = *((uint8_t*) (RAX));

// 13377782: MOV R10,0xff
R10 = 0xff;

// 13377789: SHL R10,0x30
R10 <<= 0x30;

// 1337778d: NOT R10
R10 = ~R10;

// 13377790: AND R15,R10
R15 &= R10;

// 13377793: MOVZX R10,CL
R10 = (*((uint8_t*) &RCX)) & 0xFF;

// 13377797: SHL R10,0x30
R10 <<= 0x30;

// 1337779b: OR R15,R10
R15 |= R10;

// 1337779e: JMP 0x13661282

// 13661282: JMP 0x133777ea

// 133777ea: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack114[0x10000];
RSP = (uint64_t) &stack114[0x10000 - 8];


// 13377883: MOV RBP,0xe32ea997
RBP = 0xe32ea997;

// 1337788d: PUSH RBP
RSP -= 8;
*(uint64_t*) (RSP) = RBP;

// 1337788e: PUSH 0xd131220
RSP -= 8;
*(uint64_t*) (RSP) = 0xd131220;

// 13377893: PUSH 0x38202ea5
RSP -= 8;
*(uint64_t*) (RSP) = 0x38202ea5;

// 13377898: PUSH 0x285720cd
RSP -= 8;
*(uint64_t*) (RSP) = 0x285720cd;

// 1337789d: PUSH 0x41230399
RSP -= 8;
*(uint64_t*) (RSP) = 0x41230399;

// 133778a2: ADD qword ptr [RSP + 0x20],0x5d5b0f51
*((uint64_t*) (RSP + 0x20)) += 0x5d5b0f51;

// 133778ab: MOV RBX,qword ptr [R9 + 0x28]
// switch to context pointer RBX

// 133778af: MOV R12,qword ptr [RBX + 0xf0]
R12 = *((uint64_t*) (&R15_old));

// 133778b6: JMP 0x1366142e

// 1366142e: JMP 0x133778fa

// 133778fa: HLT
// ----------------

// 0x00: PushMachframe 1
RSP = *(uint64_t*) (RSP + 0x20);

// 0x00: AllocLarge 8
RSP += 8;

// 0x00: PushNonVol 2
RDX = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack115[0x10000];
RSP = (uint64_t) &stack115[0x10000 - 8];


// 133779a2: MOV RDI,qword ptr [R9 + 0x28]
// switch to context pointer RDI

// 133779a6: MOV RBP,qword ptr [RDI + 0x88]
RBP = *((uint64_t*) (&RDX_old));

// 133779ad: MOV R14,qword ptr [RDI + 0xd8]
R14 = *((uint64_t*) (&R12_old));

// 133779b4: MOVZX RBP,BPL
RBP = (*((uint8_t*) &RBP)) & 0xFF;

// 133779b8: JMP 0x1366156d

// 1366156d: JMP 0x13377a06

// 13377a06: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack116[0x10000];
RSP = (uint64_t) &stack116[0x10000 - 8];


// 13377a9c: MOV RSI,qword ptr [R9 + 0x28]
// switch to context pointer RSI

// 13377aa0: MOV RAX,qword ptr [RSI + 0xa0]
RAX = *((uint64_t*) (&RBP_old));

// 13377aa7: MOV R11,-0x5f558abe
R11 = -0x5f558abe;

// 13377aae: ADD R11,0x604b544e
R11 += 0x604b544e;

// 13377ab5: PUSH R11
RSP -= 8;
*(uint64_t*) (RSP) = R11;

// 13377ab7: MOV R14,qword ptr [RSI + 0xe8]
R14 = *((uint64_t*) (&R14_old));

// 13377abe: MUL qword ptr [RSP]
RAX *= *((uint64_t*) (RSP));

// 13377ac2: MOV RBP,RAX
RBP = RAX;

// 13377ac5: JMP 0x1366177d

// 1366177d: JMP 0x13377b0f

// 13377b0f: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack117[0x10000];
RSP = (uint64_t) &stack117[0x10000 - 8];


// 13377ba4: MOV RDX,qword ptr [R9 + 0x28]
// switch to context pointer RDX

// 13377ba8: MOV RSI,qword ptr [RDX + 0xe8]
RSI = *((uint64_t*) (&R14_old));

// 13377baf: SUB RSI,qword ptr [RDX + 0xa0]
RSI -= *((uint64_t*) (&RBP_old));

// 13377bb6: JMP 0x136618b0

// 136618b0: JMP 0x13377c04

// 13377c04: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack118[0x10000];
RSP = (uint64_t) &stack118[0x10000 - 8];


// 13377c8f: MOV R15,qword ptr [R9 + 0x28]
// switch to context pointer R15

// 13377c93: MOV R12,qword ptr [R15 + 0xa8]
R12 = *((uint64_t*) (&RSI_old));

// 13377c9a: PUSH R12
RSP -= 8;
*(uint64_t*) (RSP) = R12;

// 13377c9c: MOV RBP,RSP
RBP = RSP;

// 13377c9f: MOV RSI,qword ptr [R15 + 0xa8]
RSI = *((uint64_t*) (&RSI_old));

// 13377ca6: JMP 0x136619e8

// 136619e8: JMP 0x13377cf5

// 13377cf5: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = RBP - 0;

// 0x00: PushNonVol 2
RDX = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack119[0x10000];
RSP = (uint64_t) &stack119[0x10000 - 8];


// 13377d8c: MOV R10,qword ptr [R9 + 0x28]
// switch to context pointer R10

// 13377d90: MOV R15,qword ptr [R10 + 0x88]
R15 = *((uint64_t*) (&RDX_old));

// 13377d97: MOV RBX,qword ptr [R10 + 0xa8]
RBX = *((uint64_t*) (&RSI_old));

// 13377d9e: MOVZX R15,R15B
R15 = (*((uint8_t*) &R15)) & 0xFF;

// 13377da2: JMP 0x13661b25

// 13661b25: JMP 0x13377df6

// 13377df6: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack120[0x10000];
RSP = (uint64_t) &stack120[0x10000 - 8];


// 13377e88: MOV R15,qword ptr [R9 + 0x28]
// switch to context pointer R15

// 13377e8c: LDMXCSR dword ptr [R15 + 0xf0]
MXCSR = *((uint32_t*) (&R15_old));

// 13377e94: MOV RBP,0x12bd73891
RBP = 0x12bd73891;

// 13377e9e: ADD RBP,0x14322a2f
RBP += 0x14322a2f;

// 13377ea5: MOV RBP,qword ptr [RBP + 0x2b0]
RBP = *((uint64_t*) (RBP + 0x2b0));

// 13377eac: ADD RBP,qword ptr [R15 + 0xf0]
RBP += *((uint64_t*) (&R15_old));

// 13377eb3: MOV SIL,byte ptr [RBP]
*((uint8_t*) &RSI) = *((uint8_t*) (RBP));

// 13377eb7: MOVZX RSI,SIL
RSI = (*((uint8_t*) &RSI)) & 0xFF;

// 13377ebb: SHL RSI,0x8
RSI <<= 0x8;

// 13377ebf: ADD qword ptr [R15 + 0x90],RSI
*((uint64_t*) (&RBX_old)) += RSI;

// 13377ec6: MOV R11,qword ptr [R9 + 0x28]
// switch to context pointer R11

// 13377eca: MOV RDI,qword ptr [R11 + 0x90]
RDI = *((uint64_t*) (&RBX_old));

// 13377ed1: MOV R13,0x118d31e6b
R13 = 0x118d31e6b;

// 13377edb: ADD R13,0x27363c55
R13 += 0x27363c55;

// 13377ee2: JMP 0x13661f57

// 13661f57: JMP 0x13377f2c

// 13377f2c: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = R13 - 0;

// 0x00: AllocLarge 688
RSP += 688;

// 0x00: PushNonVol 1
RCX = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack121[0x10000];
RSP = (uint64_t) &stack121[0x10000 - 8];


// 13377fd2: MOV R12,qword ptr [R9 + 0x28]
// switch to context pointer R12

// 13377fd6: LDMXCSR dword ptr [R12 + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 13377fdc: MOV RSI,qword ptr [R12 + 0x80]
RSI = *((uint64_t*) (&RCX_old));

// 13377fe4: MOV R15,qword ptr [R12 + 0xb0]
R15 = *((uint64_t*) (&RDI_old));

// 13377fec: JMP 0x136620f3

// 136620f3: JMP 0x1337803e

// 1337803e: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack122[0x10000];
RSP = (uint64_t) &stack122[0x10000 - 8];


// 133780e4: MOV RSI,qword ptr [R9 + 0x28]
// switch to context pointer RSI

// 133780e8: MOV R13,qword ptr [RSI + 0xf0]
R13 = *((uint64_t*) (&R15_old));

// 133780ef: MOV EBP,dword ptr [RSI + 0x34]
*((uint32_t*) &RBP) = *((uint32_t*) (&MXCSR_old));

// 133780f2: ADD RBP,qword ptr [RSI + 0xa8]
RBP += *((uint64_t*) (&RSI_old));

// 133780f9: MOV R10B,byte ptr [RBP]
*((uint8_t*) &R10) = *((uint8_t*) (RBP));

// 133780fd: MOV R13B,R10B
*((uint8_t*) &R13) = *((uint8_t*) &R10);

// 13378100: JMP 0x1366222c

// 1366222c: JMP 0x13378152

// 13378152: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack123[0x10000];
RSP = (uint64_t) &stack123[0x10000 - 8];


// 133781f3: MOV RAX,qword ptr [R9 + 0x28]
// switch to context pointer RAX

// 133781f7: MOV RDX,qword ptr [RAX + 0xe0]
RDX = *((uint64_t*) (&R13_old));

// 133781fe: PUSH RDX
RSP -= 8;
*(uint64_t*) (RSP) = RDX;

// 133781ff: MOV RBX,RSP
RBX = RSP;

// 13378202: MOV R14,qword ptr [RAX + 0xe0]
R14 = *((uint64_t*) (&R13_old));

// 13378209: JMP 0x13662372

// 13662372: JMP 0x13378258

// 13378258: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = RBX - 0;

// 0x00: AllocLarge 1
RSP += 1;

// 0x00: PushNonVol 10
R10 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack124[0x10000];
RSP = (uint64_t) &stack124[0x10000 - 8];


// 133782ff: MOV RDX,qword ptr [R9 + 0x28]
// switch to context pointer RDX

// 13378303: MOV R15,qword ptr [RDX + 0xc8]
R15 = *((uint64_t*) (&R10_old));

// 1337830a: MOV RDI,qword ptr [RDX + 0xe8]
RDI = *((uint64_t*) (&R14_old));

// 13378311: MOVZX R15,R15B
R15 = (*((uint8_t*) &R15)) & 0xFF;

// 13378315: JMP 0x136624b2

// 136624b2: JMP 0x1337835f

// 1337835f: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack125[0x10000];
RSP = (uint64_t) &stack125[0x10000 - 8];


// 13378405: MOV RAX,qword ptr [R9 + 0x28]
// switch to context pointer RAX

// 13378409: LDMXCSR dword ptr [RAX + 0xf0]
MXCSR = *((uint32_t*) (&R15_old));

// 13378410: MOV RDI,0xfbf613a1
RDI = 0xfbf613a1;

// 1337841a: ADD RDI,0x44134f1f
RDI += 0x44134f1f;

// 13378421: MOV RDI,qword ptr [RDI + 0x530]
RDI = *((uint64_t*) (RDI + 0x530));

// 13378428: ADD RDI,qword ptr [RAX + 0xf0]
RDI += *((uint64_t*) (&R15_old));

// 1337842f: MOV R12B,byte ptr [RDI]
*((uint8_t*) &R12) = *((uint8_t*) (RDI));

// 13378432: MOVZX R12,R12B
R12 = (*((uint8_t*) &R12)) & 0xFF;

// 13378436: SHL R12,0x10
R12 <<= 0x10;

// 1337843a: ADD qword ptr [RAX + 0xb0],R12
*((uint64_t*) (&RDI_old)) += R12;

// 13378441: MOV R10,0xe25825f9
R10 = 0xe25825f9;

// 1337844b: PUSH R10
RSP -= 8;
*(uint64_t*) (RSP) = R10;

// 1337844d: PUSH 0x71406aed
RSP -= 8;
*(uint64_t*) (RSP) = 0x71406aed;

// 13378452: PUSH 0x180f4263
RSP -= 8;
*(uint64_t*) (RSP) = 0x180f4263;

// 13378457: PUSH 0x24c01b81
RSP -= 8;
*(uint64_t*) (RSP) = 0x24c01b81;

// 1337845c: ADD qword ptr [RSP + 0x18],0x5db134c7
*((uint64_t*) (RSP + 0x18)) += 0x5db134c7;

// 13378465: MOV RDX,qword ptr [R9 + 0x28]
// switch to context pointer RDX

// 13378469: MOV RBX,qword ptr [RDX + 0xb0]
RBX = *((uint64_t*) (&RDI_old));

// 13378470: JMP 0x136628e1

// 136628e1: JMP 0x133784bf

// 133784bf: HLT
// ----------------

// 0x00: PushMachframe 0
RSP = *(uint64_t*) (RSP + 0x18);

// 0x00: AllocLarge 1328
RSP += 1328;

// 0x00: PushNonVol 7
RDI = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack126[0x10000];
RSP = (uint64_t) &stack126[0x10000 - 8];


// 1337855a: MOV RDX,qword ptr [R9 + 0x28]
// switch to context pointer RDX

// 1337855e: LDMXCSR dword ptr [RDX + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 13378562: MOV RSI,qword ptr [RDX + 0xb0]
RSI = *((uint64_t*) (&RDI_old));

// 13378569: MOV RBX,qword ptr [RDX + 0x90]
RBX = *((uint64_t*) (&RBX_old));

// 13378570: JMP 0x13662a1e

// 13662a1e: JMP 0x133785bf

// 133785bf: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack127[0x10000];
RSP = (uint64_t) &stack127[0x10000 - 8];


// 13378646: MOV RDX,qword ptr [R9 + 0x28]
// switch to context pointer RDX

// 1337864a: MOV RBX,qword ptr [RDX + 0x90]
RBX = *((uint64_t*) (&RBX_old));

// 13378651: MOV ECX,dword ptr [RDX + 0x34]
*((uint32_t*) &RCX) = *((uint32_t*) (&MXCSR_old));

// 13378654: ADD RCX,qword ptr [RDX + 0xa8]
RCX += *((uint64_t*) (&RSI_old));

// 1337865b: MOV R10B,byte ptr [RCX]
*((uint8_t*) &R10) = *((uint8_t*) (RCX));

// 1337865e: MOV RSI,0xff
RSI = 0xff;

// 13378665: SHL RSI,0x8
RSI <<= 0x8;

// 13378669: NOT RSI
RSI = ~RSI;

// 1337866c: AND RBX,RSI
RBX &= RSI;

// 1337866f: MOVZX RSI,R10B
RSI = (*((uint8_t*) &R10)) & 0xFF;

// 13378673: SHL RSI,0x8
RSI <<= 0x8;

// 13378677: OR RBX,RSI
RBX |= RSI;

// 1337867a: JMP 0x13662bc4

// 13662bc4: JMP 0x133786cc

// 133786cc: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack128[0x10000];
RSP = (uint64_t) &stack128[0x10000 - 8];


// 1337875f: MOV R11,qword ptr [R9 + 0x28]
// switch to context pointer R11

// 13378763: MOV R13,qword ptr [R11 + 0x90]
R13 = *((uint64_t*) (&RBX_old));

// 1337876a: PUSH R13
RSP -= 8;
*(uint64_t*) (RSP) = R13;

// 1337876c: MOV RSI,RSP
RSI = RSP;

// 1337876f: MOV RBX,qword ptr [R11 + 0x90]
RBX = *((uint64_t*) (&RBX_old));

// 13378776: JMP 0x13662d00

// 13662d00: JMP 0x133787bd

// 133787bd: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = RSI - 0;

// 0x00: AllocLarge 2
RSP += 2;

// 0x00: PushNonVol 15
R15 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack129[0x10000];
RSP = (uint64_t) &stack129[0x10000 - 8];


// 13378855: MOV R11,qword ptr [R9 + 0x28]
// switch to context pointer R11

// 13378859: MOV RBP,qword ptr [R11 + 0xf0]
RBP = *((uint64_t*) (&R15_old));

// 13378860: MOV R12,qword ptr [R11 + 0x90]
R12 = *((uint64_t*) (&RBX_old));

// 13378867: MOVZX RBP,BPL
RBP = (*((uint8_t*) &RBP)) & 0xFF;

// 1337886b: JMP 0x13662e32

// 13662e32: JMP 0x133788be

// 133788be: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack130[0x10000];
RSP = (uint64_t) &stack130[0x10000 - 8];


// 13378956: MOV R10,qword ptr [R9 + 0x28]
// switch to context pointer R10

// 1337895a: LDMXCSR dword ptr [R10 + 0xa0]
MXCSR = *((uint32_t*) (&RBP_old));

// 13378962: MOV RBX,0x132c061b6
RBX = 0x132c061b6;

// 1337896c: ADD RBX,0xd49010a
RBX += 0xd49010a;

// 13378973: MOV RBX,qword ptr [RBX + 0x7d0]
RBX = *((uint64_t*) (RBX + 0x7d0));

// 1337897a: ADD RBX,qword ptr [R10 + 0xa0]
RBX += *((uint64_t*) (&RBP_old));

// 13378981: MOV R14B,byte ptr [RBX]
*((uint8_t*) &R14) = *((uint8_t*) (RBX));

// 13378984: MOVZX R14,R14B
R14 = (*((uint8_t*) &R14)) & 0xFF;

// 13378988: SHL R14,0x18
R14 <<= 0x18;

// 1337898c: ADD qword ptr [R10 + 0xd8],R14
*((uint64_t*) (&R12_old)) += R14;

// 13378993: MOV R11,0x123e64bad
R11 = 0x123e64bad;

// 1337899d: PUSH R11
RSP -= 8;
*(uint64_t*) (RSP) = R11;

// 1337899f: PUSH 0x684e3707
RSP -= 8;
*(uint64_t*) (RSP) = 0x684e3707;

// 133789a4: PUSH 0x31b23612
RSP -= 8;
*(uint64_t*) (RSP) = 0x31b23612;

// 133789a9: PUSH 0x29c632fd
RSP -= 8;
*(uint64_t*) (RSP) = 0x29c632fd;

// 133789ae: ADD qword ptr [RSP + 0x18],0x1c230f13
*((uint64_t*) (RSP + 0x18)) += 0x1c230f13;

// 133789b7: MOV R14,qword ptr [R9 + 0x28]
// switch to context pointer R14

// 133789bb: MOV RDI,qword ptr [R14 + 0xd8]
RDI = *((uint64_t*) (&R12_old));

// 133789c2: JMP 0x1366325a

// 1366325a: JMP 0x13378a15

// 13378a15: HLT
// ----------------

// 0x00: PushMachframe 0
RSP = *(uint64_t*) (RSP + 0x18);

// 0x00: AllocLarge 2000
RSP += 2000;

// 0x00: PushNonVol 5
RBP = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack131[0x10000];
RSP = (uint64_t) &stack131[0x10000 - 8];


// 13378aae: MOV R13,qword ptr [R9 + 0x28]
// switch to context pointer R13

// 13378ab2: LDMXCSR dword ptr [R13 + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 13378ab7: MOV RDI,qword ptr [R13 + 0xa0]
RDI = *((uint64_t*) (&RBP_old));

// 13378abe: MOV R15,qword ptr [R13 + 0xb0]
R15 = *((uint64_t*) (&RDI_old));

// 13378ac5: JMP 0x13663396

// 13663396: JMP 0x13378b0f

// 13378b0f: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack132[0x10000];
RSP = (uint64_t) &stack132[0x10000 - 8];


// 13378b9d: MOV R11,qword ptr [R9 + 0x28]
// switch to context pointer R11

// 13378ba1: MOV R13,qword ptr [R11 + 0xf0]
R13 = *((uint64_t*) (&R15_old));

// 13378ba8: MOV EBP,dword ptr [R11 + 0x34]
*((uint32_t*) &RBP) = *((uint32_t*) (&MXCSR_old));

// 13378bac: ADD RBP,qword ptr [R11 + 0xb0]
RBP += *((uint64_t*) (&RDI_old));

// 13378bb3: MOV AL,byte ptr [RBP]
*((uint8_t*) &RAX) = *((uint8_t*) (RBP));

// 13378bb6: MOV R14,0xff
R14 = 0xff;

// 13378bbd: SHL R14,0x10
R14 <<= 0x10;

// 13378bc1: NOT R14
R14 = ~R14;

// 13378bc4: AND R13,R14
R13 &= R14;

// 13378bc7: MOVZX R14,AL
R14 = (*((uint8_t*) &RAX)) & 0xFF;

// 13378bcb: SHL R14,0x10
R14 <<= 0x10;

// 13378bcf: OR R13,R14
R13 |= R14;

// 13378bd2: JMP 0x13663542

// 13663542: JMP 0x13378c20

// 13378c20: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack133[0x10000];
RSP = (uint64_t) &stack133[0x10000 - 8];


// 13378cbf: MOV RCX,qword ptr [R9 + 0x28]
// switch to context pointer RCX

// 13378cc3: MOV RBX,qword ptr [RCX + 0xe0]
RBX = *((uint64_t*) (&R13_old));

// 13378cca: PUSH RBX
RSP -= 8;
*(uint64_t*) (RSP) = RBX;

// 13378ccb: MOV R12,RSP
R12 = RSP;

// 13378cce: MOV RSI,qword ptr [RCX + 0xe0]
RSI = *((uint64_t*) (&R13_old));

// 13378cd5: JMP 0x13663674

// 13663674: JMP 0x13378d22

// 13378d22: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = R12 - 0;

// 0x00: AllocLarge 3
RSP += 3;

// 0x00: PushNonVol 15
R15 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack134[0x10000];
RSP = (uint64_t) &stack134[0x10000 - 8];


// 13378dc6: MOV RBX,qword ptr [R9 + 0x28]
// switch to context pointer RBX

// 13378dca: MOV R12,qword ptr [RBX + 0xf0]
R12 = *((uint64_t*) (&R15_old));

// 13378dd1: MOV RBX,qword ptr [RBX + 0xa8]
RBX = *((uint64_t*) (&RSI_old));

// 13378dd8: MOVZX R12,R12B
R12 = (*((uint8_t*) &R12)) & 0xFF;

// 13378ddc: JMP 0x136637b4

// 136637b4: JMP 0x13378e30

// 13378e30: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack135[0x10000];
RSP = (uint64_t) &stack135[0x10000 - 8];


// 13378ebb: MOV RDI,qword ptr [R9 + 0x28]
// switch to context pointer RDI

// 13378ebf: LDMXCSR dword ptr [RDI + 0xd8]
MXCSR = *((uint32_t*) (&R12_old));

// 13378ec6: MOV R14,0xe7e82b7f
R14 = 0xe7e82b7f;

// 13378ed0: ADD R14,0x58213741
R14 += 0x58213741;

// 13378ed7: MOV R14,qword ptr [R14 + 0x358]
R14 = *((uint64_t*) (R14 + 0x358));

// 13378ede: ADD R14,qword ptr [RDI + 0xd8]
R14 += *((uint64_t*) (&R12_old));

// 13378ee5: MOV R14B,byte ptr [R14]
*((uint8_t*) &R14) = *((uint8_t*) (R14));

// 13378ee8: MOVZX R14,R14B
R14 = (*((uint8_t*) &R14)) & 0xFF;

// 13378eec: SHL R14,0x20
R14 <<= 0x20;

// 13378ef0: ADD qword ptr [RDI + 0x90],R14
*((uint64_t*) (&RBX_old)) += R14;

// 13378ef7: MOV R13,qword ptr [R9 + 0x28]
// switch to context pointer R13

// 13378efb: MOV RSI,qword ptr [R13 + 0x90]
RSI = *((uint64_t*) (&RBX_old));

// 13378f02: MOV R13,0x122d82878
R13 = 0x122d82878;

// 13378f0c: ADD R13,0x1d313248
R13 += 0x1d313248;

// 13378f13: JMP 0x13663beb

// 13663beb: JMP 0x13378f58

// 13378f58: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = R13 - 0;

// 0x00: AllocLarge 856
RSP += 856;

// 0x00: PushNonVol 1
RCX = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack136[0x10000];
RSP = (uint64_t) &stack136[0x10000 - 8];


// 13378fef: MOV RBX,qword ptr [R9 + 0x28]
// switch to context pointer RBX

// 13378ff3: LDMXCSR dword ptr [RBX + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 13378ff7: MOV RDI,qword ptr [RBX + 0x80]
RDI = *((uint64_t*) (&RCX_old));

// 13378ffe: MOV RBP,qword ptr [RBX + 0xa8]
RBP = *((uint64_t*) (&RSI_old));

// 13379005: JMP 0x13663d24

// 13663d24: JMP 0x13379051

// 13379051: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack137[0x10000];
RSP = (uint64_t) &stack137[0x10000 - 8];


// 133790ea: MOV RCX,qword ptr [R9 + 0x28]
// switch to context pointer RCX

// 133790ee: MOV R13,qword ptr [RCX + 0xa0]
R13 = *((uint64_t*) (&RBP_old));

// 133790f5: MOV EAX,dword ptr [RCX + 0x34]
*((uint32_t*) &RAX) = *((uint32_t*) (&MXCSR_old));

// 133790f8: ADD RAX,qword ptr [RCX + 0xb0]
RAX += *((uint64_t*) (&RDI_old));

// 133790ff: MOV R10B,byte ptr [RAX]
*((uint8_t*) &R10) = *((uint8_t*) (RAX));

// 13379102: MOV RSI,0xff
RSI = 0xff;

// 13379109: SHL RSI,0x18
RSI <<= 0x18;

// 1337910d: NOT RSI
RSI = ~RSI;

// 13379110: AND R13,RSI
R13 &= RSI;

// 13379113: MOVZX RSI,R10B
RSI = (*((uint8_t*) &R10)) & 0xFF;

// 13379117: SHL RSI,0x18
RSI <<= 0x18;

// 1337911b: OR R13,RSI
R13 |= RSI;

// 1337911e: JMP 0x13663ec7

// 13663ec7: JMP 0x13379170

// 13379170: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack138[0x10000];
RSP = (uint64_t) &stack138[0x10000 - 8];


// 13379201: MOV R8,qword ptr [R9 + 0x28]
// switch to context pointer R8

// 13379205: MOV RBP,qword ptr [R8 + 0xe0]
RBP = *((uint64_t*) (&R13_old));

// 1337920c: PUSH RBP
RSP -= 8;
*(uint64_t*) (RSP) = RBP;

// 1337920d: MOV RDI,RSP
RDI = RSP;

// 13379210: MOV RBX,qword ptr [R8 + 0xe0]
RBX = *((uint64_t*) (&R13_old));

// 13379217: JMP 0x13664002

// 13664002: JMP 0x13379258

// 13379258: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = RDI - 0;

// 0x00: AllocLarge 4
RSP += 4;

// 0x00: PushNonVol 5
RBP = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack139[0x10000];
RSP = (uint64_t) &stack139[0x10000 - 8];


// 133792f2: MOV RBP,qword ptr [R9 + 0x28]
// switch to context pointer RBP

// 133792f6: MOV R15,qword ptr [RBP + 0xa0]
R15 = *((uint64_t*) (&RBP_old));

// 133792fd: MOV RSI,qword ptr [RBP + 0x90]
RSI = *((uint64_t*) (&RBX_old));

// 13379304: MOVZX R15,R15B
R15 = (*((uint8_t*) &R15)) & 0xFF;

// 13379308: JMP 0x1366413a

// 1366413a: JMP 0x1337934a

// 1337934a: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack140[0x10000];
RSP = (uint64_t) &stack140[0x10000 - 8];


// 133793e4: MOV R13,qword ptr [R9 + 0x28]
// switch to context pointer R13

// 133793e8: LDMXCSR dword ptr [R13 + 0xf0]
MXCSR = *((uint32_t*) (&R15_old));

// 133793f0: MOV RAX,0xe88a61bf
RAX = 0xe88a61bf;

// 133793fa: ADD RAX,0x577f0101
RAX += 0x577f0101;

// 13379400: MOV RAX,qword ptr [RAX]
RAX = *((uint64_t*) (RAX));

// 13379403: ADD RAX,qword ptr [R13 + 0xf0]
RAX += *((uint64_t*) (&R15_old));

// 1337940a: MOV R14B,byte ptr [RAX]
*((uint8_t*) &R14) = *((uint8_t*) (RAX));

// 1337940d: MOVZX R14,R14B
R14 = (*((uint8_t*) &R14)) & 0xFF;

// 13379411: SHL R14,0x28
R14 <<= 0x28;

// 13379415: ADD qword ptr [R13 + 0xa8],R14
*((uint64_t*) (&RSI_old)) += R14;

// 1337941c: MOV RBX,qword ptr [R9 + 0x28]
// switch to context pointer RBX

// 13379420: MOV R13,qword ptr [RBX + 0xa8]
R13 = *((uint64_t*) (&RSI_old));

// 13379427: MOV RSI,0x1161aff10
RSI = 0x1161aff10;

// 13379431: ADD RSI,0x29ee5bb0
RSI += 0x29ee5bb0;

// 13379438: JMP 0x136644e8

// 136644e8: JMP 0x1337948b

// 1337948b: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = RSI - 0;

// 0x00: PushNonVol 14
R14 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack141[0x10000];
RSP = (uint64_t) &stack141[0x10000 - 8];


// 1337951c: MOV R14,qword ptr [R9 + 0x28]
// switch to context pointer R14

// 13379520: LDMXCSR dword ptr [R14 + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 13379525: MOV RSI,qword ptr [R14 + 0xe8]
RSI = *((uint64_t*) (&R14_old));

// 1337952c: MOV RDI,qword ptr [R14 + 0xe0]
RDI = *((uint64_t*) (&R13_old));

// 13379533: JMP 0x13664624

// 13664624: JMP 0x1337957e

// 1337957e: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack142[0x10000];
RSP = (uint64_t) &stack142[0x10000 - 8];


// 1337961e: MOV R14,qword ptr [R9 + 0x28]
// switch to context pointer R14

// 13379622: MOV RBP,qword ptr [R14 + 0xb0]
RBP = *((uint64_t*) (&RDI_old));

// 13379629: MOV ECX,dword ptr [R14 + 0x34]
*((uint32_t*) &RCX) = *((uint32_t*) (&MXCSR_old));

// 1337962d: ADD RCX,qword ptr [R14 + 0xa8]
RCX += *((uint64_t*) (&RSI_old));

// 13379634: MOV DL,byte ptr [RCX]
*((uint8_t*) &RDX) = *((uint8_t*) (RCX));

// 13379636: MOV R13,0xff
R13 = 0xff;

// 1337963d: SHL R13,0x20
R13 <<= 0x20;

// 13379641: NOT R13
R13 = ~R13;

// 13379644: AND RBP,R13
RBP &= R13;

// 13379647: MOVZX R13,DL
R13 = (*((uint8_t*) &RDX)) & 0xFF;

// 1337964b: SHL R13,0x20
R13 <<= 0x20;

// 1337964f: OR RBP,R13
RBP |= R13;

// 13379652: JMP 0x136647c5

// 136647c5: JMP 0x1337969c

// 1337969c: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack143[0x10000];
RSP = (uint64_t) &stack143[0x10000 - 8];


// 13379739: MOV RDX,qword ptr [R9 + 0x28]
// switch to context pointer RDX

// 1337973d: MOV RDI,qword ptr [RDX + 0xa0]
RDI = *((uint64_t*) (&RBP_old));

// 13379744: PUSH RDI
RSP -= 8;
*(uint64_t*) (RSP) = RDI;

// 13379745: MOV R15,RSP
R15 = RSP;

// 13379748: MOV RDI,qword ptr [RDX + 0xa0]
RDI = *((uint64_t*) (&RBP_old));

// 1337974f: JMP 0x13664900

// 13664900: JMP 0x1337979c

// 1337979c: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack144[0x10000];
RSP = (uint64_t) &stack144[0x10000 - 8];


// 1337983c: MOV RCX,qword ptr [R9 + 0x28]
// switch to context pointer RCX

// 13379840: MOV RDX,qword ptr [RCX + 0xf0]
RDX = *((uint64_t*) (&R15_old));

// 13379847: MOV R12,qword ptr [RCX + 0xb0]
R12 = *((uint64_t*) (&RDI_old));

// 1337984e: PUSH RDX
RSP -= 8;
*(uint64_t*) (RSP) = RDX;

// 1337984f: PUSH 0x6e5a333c
RSP -= 8;
*(uint64_t*) (RSP) = 0x6e5a333c;

// 13379854: PUSH 0xef324f5
RSP -= 8;
*(uint64_t*) (RSP) = 0xef324f5;

// 13379859: PUSH 0x228b167b
RSP -= 8;
*(uint64_t*) (RSP) = 0x228b167b;

// 1337985e: PUSH 0x5e487f36
RSP -= 8;
*(uint64_t*) (RSP) = 0x5e487f36;

// 13379863: JMP 0x13664a3f

// 13664a3f: JMP 0x133798b6

// 133798b6: HLT
// ----------------

// 0x00: PushMachframe 1
RSP = *(uint64_t*) (RSP + 0x20);

// 0x00: AllocLarge 6
RSP += 6;

// 0x00: PushNonVol 10
R10 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack145[0x10000];
RSP = (uint64_t) &stack145[0x10000 - 8];


// 13379948: MOV RSI,qword ptr [R9 + 0x28]
// switch to context pointer RSI

// 1337994c: MOV RBP,qword ptr [RSI + 0xc8]
RBP = *((uint64_t*) (&R10_old));

// 13379953: MOV R15,qword ptr [RSI + 0xd8]
R15 = *((uint64_t*) (&R12_old));

// 1337995a: MOVZX RBP,BPL
RBP = (*((uint8_t*) &RBP)) & 0xFF;

// 1337995e: JMP 0x13664b72

// 13664b72: JMP 0x133799ad

// 133799ad: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack146[0x10000];
RSP = (uint64_t) &stack146[0x10000 - 8];


// 13379a39: MOV R14,qword ptr [R9 + 0x28]
// switch to context pointer R14

// 13379a3d: LDMXCSR dword ptr [R14 + 0xa0]
MXCSR = *((uint32_t*) (&RBP_old));

// 13379a45: MOV RDX,0x10b1b0c34
RDX = 0x10b1b0c34;

// 13379a4f: ADD RDX,0x34ee568c
RDX += 0x34ee568c;

// 13379a56: MOV RDX,qword ptr [RDX]
RDX = *((uint64_t*) (RDX));

// 13379a59: ADD RDX,qword ptr [R14 + 0xa0]
RDX += *((uint64_t*) (&RBP_old));

// 13379a60: MOV DL,byte ptr [RDX]
*((uint8_t*) &RDX) = *((uint8_t*) (RDX));

// 13379a62: MOVZX RDX,DL
RDX = (*((uint8_t*) &RDX)) & 0xFF;

// 13379a66: SHL RDX,0x38
RDX <<= 0x38;

// 13379a6a: ADD qword ptr [R14 + 0xf0],RDX
*((uint64_t*) (&R15_old)) += RDX;

// 13379a71: MOV R12,qword ptr [R9 + 0x28]
// switch to context pointer R12

// 13379a75: MOV R15,qword ptr [R12 + 0xf0]
R15 = *((uint64_t*) (&R15_old));

// 13379a7d: MOV R14,0xf788f090
R14 = 0xf788f090;

// 13379a87: ADD R14,0x48806a30
R14 += 0x48806a30;

// 13379a8e: JMP 0x13664f39

// 13664f39: JMP 0x13379ad8

// 13379ad8: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = R14 - 0;

// 0x00: PushNonVol 0
RAX = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack147[0x10000];
RSP = (uint64_t) &stack147[0x10000 - 8];


// 13379b6d: MOV RBX,qword ptr [R9 + 0x28]
// switch to context pointer RBX

// 13379b71: LDMXCSR dword ptr [RBX + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 13379b75: MOV RBP,qword ptr [RBX + 0x78]
RBP = *((uint64_t*) (&RAX_old));

// 13379b79: MOV RSI,qword ptr [RBX + 0xf0]
RSI = *((uint64_t*) (&R15_old));

// 13379b80: JMP 0x1366500a

// 1366500a: JMP 0x13379bca

// 13379bca: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack148[0x10000];
RSP = (uint64_t) &stack148[0x10000 - 8];


// 13379c51: MOV R9,qword ptr [R9 + 0x28]
// switch to context pointer R9

// 13379c55: MOV RSI,qword ptr [R9 + 0xa8]
RSI = *((uint64_t*) (&RSI_old));

// 13379c5c: MOV R13D,dword ptr [R9 + 0x34]
*((uint32_t*) &R13) = *((uint32_t*) (&MXCSR_old));

// 13379c60: ADD R13,qword ptr [R9 + 0xa0]
R13 += *((uint64_t*) (&RBP_old));

// 13379c67: MOV R13B,byte ptr [R13]
*((uint8_t*) &R13) = *((uint8_t*) (R13));

// 13379c6b: MOV R14,0xff
R14 = 0xff;

// 13379c72: SHL R14,0x30
R14 <<= 0x30;

// 13379c76: NOT R14
R14 = ~R14;

// 13379c79: AND RSI,R14
RSI &= R14;

// 13379c7c: MOVZX R14,R13B
R14 = (*((uint8_t*) &R13)) & 0xFF;

// 13379c80: SHL R14,0x30
R14 <<= 0x30;

// 13379c84: OR RSI,R14
RSI |= R14;

// 13379c87: JMP 0x136651b2

// 136651b2: JMP 0x13379ccb

// 13379ccb: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack149[0x10000];
RSP = (uint64_t) &stack149[0x10000 - 8];


// 13379d51: MOV RBP,qword ptr [R9 + 0x28]
// switch to context pointer RBP

// 13379d55: MOV RSI,qword ptr [RBP + 0xa8]
RSI = *((uint64_t*) (&RSI_old));

// 13379d5c: MOV R14,0x1138e7fb4
R14 = 0x1138e7fb4;

// 13379d66: ADD R14,0x2cfb3934
R14 += 0x2cfb3934;

// 13379d6d: JMP 0x13665361

// 13665361: JMP 0x13379db1

// 13379db1: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = R14 - 0;

// 0x00: AllocLarge 20
RSP += 20;

// 0x00: PushNonVol 12
R12 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack150[0x10000];
RSP = (uint64_t) &stack150[0x10000 - 8];


// 13379e60: MOV RSI,qword ptr [R9 + 0x28]
// switch to context pointer RSI

// 13379e64: MOV R14,qword ptr [RSI + 0xd8]
R14 = *((uint64_t*) (&R12_old));

// 13379e6b: MOV RDI,qword ptr [RSI + 0xa8]
RDI = *((uint64_t*) (&RSI_old));

// 13379e72: MOVZX R14,R14B
R14 = (*((uint8_t*) &R14)) & 0xFF;

// 13379e76: JMP 0x136654a4

// 136654a4: JMP 0x13379ec5

// 13379ec5: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack151[0x10000];
RSP = (uint64_t) &stack151[0x10000 - 8];


// 13379f5e: MOV R13,qword ptr [R9 + 0x28]
// switch to context pointer R13

// 13379f62: MOV RAX,qword ptr [R13 + 0xe8]
RAX = *((uint64_t*) (&R14_old));

// 13379f69: MOV R9,-0x4606ef4e
R9 = -0x4606ef4e;

// 13379f70: ADD R9,0x467a20c6
R9 += 0x467a20c6;

// 13379f77: PUSH R9
RSP -= 8;
*(uint64_t*) (RSP) = R9;

// 13379f79: MOV RBP,qword ptr [R13 + 0xb0]
RBP = *((uint64_t*) (&RDI_old));

// 13379f80: MUL qword ptr [RSP]
RAX *= *((uint64_t*) (RSP));

// 13379f84: MOV R13,RAX
R13 = RAX;

// 13379f87: JMP 0x136656b3

// 136656b3: JMP 0x13379fdb

// 13379fdb: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack152[0x10000];
RSP = (uint64_t) &stack152[0x10000 - 8];


// 1337a064: MOV RCX,qword ptr [R9 + 0x28]
// switch to context pointer RCX

// 1337a068: MOV R13,qword ptr [RCX + 0xa0]
R13 = *((uint64_t*) (&RBP_old));

// 1337a06f: XOR R13,qword ptr [RCX + 0xe0]
R13 ^= *((uint64_t*) (&R13_old));

// 1337a076: JMP 0x136657f3

// 136657f3: JMP 0x1337a0bd

// 1337a0bd: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack153[0x10000];
RSP = (uint64_t) &stack153[0x10000 - 8];


// 1337a153: MOV R8,qword ptr [R9 + 0x28]
// switch to context pointer R8

// 1337a157: MOV RSI,qword ptr [R8 + 0xe0]
RSI = *((uint64_t*) (&R13_old));

// 1337a15e: PUSH RSI
RSP -= 8;
*(uint64_t*) (RSP) = RSI;

// 1337a15f: MOV R12,RSP
R12 = RSP;

// 1337a162: MOV R15,qword ptr [R8 + 0xe0]
R15 = *((uint64_t*) (&R13_old));

// 1337a169: JMP 0x13665934

// 13665934: JMP 0x1337a1b7

// 1337a1b7: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = R12 - 0;

// 0x00: PushNonVol 5
RBP = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack154[0x10000];
RSP = (uint64_t) &stack154[0x10000 - 8];


// 1337a256: MOV RSI,qword ptr [R9 + 0x28]
// switch to context pointer RSI

// 1337a25a: MOV R14,qword ptr [RSI + 0xa0]
R14 = *((uint64_t*) (&RBP_old));

// 1337a261: MOV R13,qword ptr [RSI + 0xf0]
R13 = *((uint64_t*) (&R15_old));

// 1337a268: MOVZX R14,R14B
R14 = (*((uint8_t*) &R14)) & 0xFF;

// 1337a26c: JMP 0x13665a73

// 13665a73: JMP 0x1337a2b7

// 1337a2b7: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack155[0x10000];
RSP = (uint64_t) &stack155[0x10000 - 8];


// 1337a350: MOV RSI,qword ptr [R9 + 0x28]
// switch to context pointer RSI

// 1337a354: LDMXCSR dword ptr [RSI + 0xe8]
MXCSR = *((uint32_t*) (&R14_old));

// 1337a35b: MOV RDI,qword ptr [R9 + 0x28]
// switch to context pointer RDI

// 1337a35f: MOV R14,qword ptr [RDI + 0xe0]
R14 = *((uint64_t*) (&R13_old));

// 1337a366: MOV R13,0x12d6b0349
R13 = 0x12d6b0349;

// 1337a370: ADD R13,0x129e4777
R13 += 0x129e4777;

// 1337a377: JMP 0x13665c84

// 13665c84: JMP 0x1337a3c1

// 1337a3c1: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = R13 - 0;

// 0x00: AllocLarge 472
RSP += 472;

// 0x00: PushNonVol 11
R11 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack156[0x10000];
RSP = (uint64_t) &stack156[0x10000 - 8];


// 1337a46f: MOV RAX,qword ptr [R9 + 0x28]
// switch to context pointer RAX

// 1337a473: LDMXCSR dword ptr [RAX + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 1337a477: MOV R13,qword ptr [RAX + 0xd0]
R13 = *((uint64_t*) (&R11_old));

// 1337a47e: MOV R14,qword ptr [RAX + 0xe8]
R14 = *((uint64_t*) (&R14_old));

// 1337a485: JMP 0x13665dc9

// 13665dc9: JMP 0x1337a4d3

// 1337a4d3: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack157[0x10000];
RSP = (uint64_t) &stack157[0x10000 - 8];


// 1337a56f: MOV R12,qword ptr [R9 + 0x28]
// switch to context pointer R12

// 1337a573: MOV R15,qword ptr [R12 + 0xe8]
R15 = *((uint64_t*) (&R14_old));

// 1337a57b: MOV R8D,dword ptr [R12 + 0x34]
*((uint32_t*) &R8) = *((uint32_t*) (&MXCSR_old));

// 1337a580: ADD R8,qword ptr [R12 + 0xe0]
R8 += *((uint64_t*) (&R13_old));

// 1337a588: MOV BPL,byte ptr [R8]
*((uint8_t*) &RBP) = *((uint8_t*) (R8));

// 1337a58b: MOV R15B,BPL
*((uint8_t*) &R15) = *((uint8_t*) &RBP);

// 1337a58e: JMP 0x13665f04

// 13665f04: JMP 0x1337a5d0

// 1337a5d0: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack158[0x10000];
RSP = (uint64_t) &stack158[0x10000 - 8];


// 1337a658: MOV R8,qword ptr [R9 + 0x28]
// switch to context pointer R8

// 1337a65c: MOV RBX,qword ptr [R8 + 0xf0]
RBX = *((uint64_t*) (&R15_old));

// 1337a663: PUSH RBX
RSP -= 8;
*(uint64_t*) (RSP) = RBX;

// 1337a664: MOV R14,RSP
R14 = RSP;

// 1337a667: MOV R13,qword ptr [R8 + 0xf0]
R13 = *((uint64_t*) (&R15_old));

// 1337a66e: JMP 0x1366603b

// 1366603b: JMP 0x1337a6b2

// 1337a6b2: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack159[0x10000];
RSP = (uint64_t) &stack159[0x10000 - 8];


// 1337a738: MOV RAX,qword ptr [R9 + 0x28]
// switch to context pointer RAX

// 1337a73c: MOV R13,qword ptr [RAX + 0xe8]
R13 = *((uint64_t*) (&R14_old));

// 1337a743: MOV R12,qword ptr [RAX + 0xe0]
R12 = *((uint64_t*) (&R13_old));

// 1337a74a: PUSH R13
RSP -= 8;
*(uint64_t*) (RSP) = R13;

// 1337a74c: PUSH 0x68d22ae7
RSP -= 8;
*(uint64_t*) (RSP) = 0x68d22ae7;

// 1337a751: PUSH 0x3c184267
RSP -= 8;
*(uint64_t*) (RSP) = 0x3c184267;

// 1337a756: PUSH 0x414a3a67
RSP -= 8;
*(uint64_t*) (RSP) = 0x414a3a67;

// 1337a75b: JMP 0x13666178

// 13666178: JMP 0x1337a7a6

// 1337a7a6: HLT
// ----------------

// 0x00: PushMachframe 0
RSP = *(uint64_t*) (RSP + 0x18);

// 0x00: AllocLarge 1
RSP += 1;

// 0x00: PushNonVol 15
R15 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack160[0x10000];
RSP = (uint64_t) &stack160[0x10000 - 8];


// 1337a836: MOV R8,qword ptr [R9 + 0x28]
// switch to context pointer R8

// 1337a83a: MOV RSI,qword ptr [R8 + 0xf0]
RSI = *((uint64_t*) (&R15_old));

// 1337a841: MOV R15,qword ptr [R8 + 0xd8]
R15 = *((uint64_t*) (&R12_old));

// 1337a848: MOVZX RSI,SIL
RSI = (*((uint8_t*) &RSI)) & 0xFF;

// 1337a84c: JMP 0x136662b2

// 136662b2: JMP 0x1337a89c

// 1337a89c: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack161[0x10000];
RSP = (uint64_t) &stack161[0x10000 - 8];


// 1337a937: MOV R10,qword ptr [R9 + 0x28]
// switch to context pointer R10

// 1337a93b: LDMXCSR dword ptr [R10 + 0xa8]
MXCSR = *((uint32_t*) (&RSI_old));

// 1337a943: MOV RDX,0xf9edcae2
RDX = 0xf9edcae2;

// 1337a94d: PUSH RDX
RSP -= 8;
*(uint64_t*) (RSP) = RDX;

// 1337a94e: PUSH 0x7b190f51
RSP -= 8;
*(uint64_t*) (RSP) = 0x7b190f51;

// 1337a953: PUSH 0x7d6d4ff7
RSP -= 8;
*(uint64_t*) (RSP) = 0x7d6d4ff7;

// 1337a958: PUSH 0x539d52cc
RSP -= 8;
*(uint64_t*) (RSP) = 0x539d52cc;

// 1337a95d: ADD qword ptr [RSP + 0x18],0x461b7fde
*((uint64_t*) (RSP + 0x18)) += 0x461b7fde;

// 1337a966: MOV RCX,qword ptr [R9 + 0x28]
// switch to context pointer RCX

// 1337a96a: MOV RBX,qword ptr [RCX + 0xf0]
RBX = *((uint64_t*) (&R15_old));

// 1337a971: JMP 0x136664c4

// 136664c4: JMP 0x1337a9b8

// 1337a9b8: HLT
// ----------------

// 0x00: PushMachframe 0
RSP = *(uint64_t*) (RSP + 0x18);

// 0x00: AllocLarge 1752
RSP += 1752;

// 0x00: PushNonVol 6
RSI = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack162[0x10000];
RSP = (uint64_t) &stack162[0x10000 - 8];


// 1337aa62: MOV RDI,qword ptr [R9 + 0x28]
// switch to context pointer RDI

// 1337aa66: LDMXCSR dword ptr [RDI + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 1337aa6a: MOV R15,qword ptr [RDI + 0xa8]
R15 = *((uint64_t*) (&RSI_old));

// 1337aa71: MOV RDI,qword ptr [RDI + 0x90]
RDI = *((uint64_t*) (&RBX_old));

// 1337aa78: JMP 0x13666604

// 13666604: JMP 0x1337aab9

// 1337aab9: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack163[0x10000];
RSP = (uint64_t) &stack163[0x10000 - 8];


// 1337ab4e: MOV R14,qword ptr [R9 + 0x28]
// switch to context pointer R14

// 1337ab52: MOV RBP,qword ptr [R14 + 0xb0]
RBP = *((uint64_t*) (&RDI_old));

// 1337ab59: MOV ESI,dword ptr [R14 + 0x34]
*((uint32_t*) &RSI) = *((uint32_t*) (&MXCSR_old));

// 1337ab5d: ADD RSI,qword ptr [R14 + 0xf0]
RSI += *((uint64_t*) (&R15_old));

// 1337ab64: MOV DL,byte ptr [RSI]
*((uint8_t*) &RDX) = *((uint8_t*) (RSI));

// 1337ab66: MOV RCX,0xff
RCX = 0xff;

// 1337ab6d: SHL RCX,0x8
RCX <<= 0x8;

// 1337ab71: NOT RCX
RCX = ~RCX;

// 1337ab74: AND RBP,RCX
RBP &= RCX;

// 1337ab77: MOVZX RCX,DL
RCX = (*((uint8_t*) &RDX)) & 0xFF;

// 1337ab7b: SHL RCX,0x8
RCX <<= 0x8;

// 1337ab7f: OR RBP,RCX
RBP |= RCX;

// 1337ab82: JMP 0x136667a7

// 136667a7: JMP 0x1337abc7

// 1337abc7: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack164[0x10000];
RSP = (uint64_t) &stack164[0x10000 - 8];


// 1337ac52: MOV RBX,qword ptr [R9 + 0x28]
// switch to context pointer RBX

// 1337ac56: MOV RBP,qword ptr [RBX + 0xa0]
RBP = *((uint64_t*) (&RBP_old));

// 1337ac5d: PUSH RBP
RSP -= 8;
*(uint64_t*) (RSP) = RBP;

// 1337ac5e: MOV R12,RSP
R12 = RSP;

// 1337ac61: MOV RSI,qword ptr [RBX + 0xa0]
RSI = *((uint64_t*) (&RBP_old));

// 1337ac68: JMP 0x136668e4

// 136668e4: JMP 0x1337acb2

// 1337acb2: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = R12 - 0;

// 0x00: AllocLarge 2
RSP += 2;

// 0x00: PushNonVol 2
RDX = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack165[0x10000];
RSP = (uint64_t) &stack165[0x10000 - 8];


// 1337ad52: MOV RBP,qword ptr [R9 + 0x28]
// switch to context pointer RBP

// 1337ad56: MOV R14,qword ptr [RBP + 0x88]
R14 = *((uint64_t*) (&RDX_old));

// 1337ad5d: MOV R12,qword ptr [RBP + 0xa8]
R12 = *((uint64_t*) (&RSI_old));

// 1337ad64: MOVZX R14,R14B
R14 = (*((uint8_t*) &R14)) & 0xFF;

// 1337ad68: JMP 0x13666a1a

// 13666a1a: JMP 0x1337adb6

// 1337adb6: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack166[0x10000];
RSP = (uint64_t) &stack166[0x10000 - 8];


// 1337ae44: MOV RBX,qword ptr [R9 + 0x28]
// switch to context pointer RBX

// 1337ae48: LDMXCSR dword ptr [RBX + 0xe8]
MXCSR = *((uint32_t*) (&R14_old));

// 1337ae4f: MOV R14,0xf3f01d0a
R14 = 0xf3f01d0a;

// 1337ae59: PUSH R14
RSP -= 8;
*(uint64_t*) (RSP) = R14;

// 1337ae5b: PUSH 0x620e130c
RSP -= 8;
*(uint64_t*) (RSP) = 0x620e130c;

// 1337ae60: PUSH 0xa592aeb
RSP -= 8;
*(uint64_t*) (RSP) = 0xa592aeb;

// 1337ae65: PUSH 0x5cf6aec
RSP -= 8;
*(uint64_t*) (RSP) = 0x5cf6aec;

// 1337ae6a: PUSH 0x1d7a50af
RSP -= 8;
*(uint64_t*) (RSP) = 0x1d7a50af;

// 1337ae6f: ADD qword ptr [RSP + 0x20],0x4c192db6
*((uint64_t*) (RSP + 0x20)) += 0x4c192db6;

// 1337ae78: MOV RCX,qword ptr [R9 + 0x28]
// switch to context pointer RCX

// 1337ae7c: MOV RBX,qword ptr [RCX + 0xd8]
RBX = *((uint64_t*) (&R12_old));

// 1337ae83: JMP 0x13666c32

// 13666c32: JMP 0x1337aed1

// 1337aed1: HLT
// ----------------

// 0x00: PushMachframe 1
RSP = *(uint64_t*) (RSP + 0x20);

// 0x00: AllocLarge 1816
RSP += 1816;

// 0x00: PushNonVol 7
RDI = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack167[0x10000];
RSP = (uint64_t) &stack167[0x10000 - 8];


// 1337af67: MOV R13,qword ptr [R9 + 0x28]
// switch to context pointer R13

// 1337af6b: LDMXCSR dword ptr [R13 + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 1337af70: MOV RBX,qword ptr [R13 + 0xb0]
RBX = *((uint64_t*) (&RDI_old));

// 1337af77: MOV R15,qword ptr [R13 + 0x90]
R15 = *((uint64_t*) (&RBX_old));

// 1337af7e: JMP 0x13666d6c

// 13666d6c: JMP 0x1337afcd

// 1337afcd: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack168[0x10000];
RSP = (uint64_t) &stack168[0x10000 - 8];


// 1337b064: MOV R13,qword ptr [R9 + 0x28]
// switch to context pointer R13

// 1337b068: MOV RBX,qword ptr [R13 + 0xf0]
RBX = *((uint64_t*) (&R15_old));

// 1337b06f: MOV R14D,dword ptr [R13 + 0x34]
*((uint32_t*) &R14) = *((uint32_t*) (&MXCSR_old));

// 1337b073: ADD R14,qword ptr [R13 + 0x90]
R14 += *((uint64_t*) (&RBX_old));

// 1337b07a: MOV BPL,byte ptr [R14]
*((uint8_t*) &RBP) = *((uint8_t*) (R14));

// 1337b07d: MOV R15,0xff
R15 = 0xff;

// 1337b084: SHL R15,0x10
R15 <<= 0x10;

// 1337b088: NOT R15
R15 = ~R15;

// 1337b08b: AND RBX,R15
RBX &= R15;

// 1337b08e: MOVZX R15,BPL
R15 = (*((uint8_t*) &RBP)) & 0xFF;

// 1337b092: SHL R15,0x10
R15 <<= 0x10;

// 1337b096: OR RBX,R15
RBX |= R15;

// 1337b099: JMP 0x13666f11

// 13666f11: JMP 0x1337b0e3

// 1337b0e3: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack169[0x10000];
RSP = (uint64_t) &stack169[0x10000 - 8];


// 1337b16e: MOV R14,qword ptr [R9 + 0x28]
// switch to context pointer R14

// 1337b172: MOV R10,qword ptr [R14 + 0x90]
R10 = *((uint64_t*) (&RBX_old));

// 1337b179: PUSH R10
RSP -= 8;
*(uint64_t*) (RSP) = R10;

// 1337b17b: MOV RDI,RSP
RDI = RSP;

// 1337b17e: MOV RSI,qword ptr [R14 + 0x90]
RSI = *((uint64_t*) (&RBX_old));

// 1337b185: JMP 0x13667048

// 13667048: JMP 0x1337b1d5

// 1337b1d5: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack170[0x10000];
RSP = (uint64_t) &stack170[0x10000 - 8];


// 1337b26b: MOV R9,qword ptr [R9 + 0x28]
// switch to context pointer R9

// 1337b26f: MOV RCX,qword ptr [R9 + 0xb0]
RCX = *((uint64_t*) (&RDI_old));

// 1337b276: MOV R12,qword ptr [R9 + 0xa8]
R12 = *((uint64_t*) (&RSI_old));

// 1337b27d: PUSH RCX
RSP -= 8;
*(uint64_t*) (RSP) = RCX;

// 1337b27e: PUSH 0x76a65077
RSP -= 8;
*(uint64_t*) (RSP) = 0x76a65077;

// 1337b283: PUSH 0x4c9e49f6
RSP -= 8;
*(uint64_t*) (RSP) = 0x4c9e49f6;

// 1337b288: PUSH 0x3ddf2452
RSP -= 8;
*(uint64_t*) (RSP) = 0x3ddf2452;

// 1337b28d: JMP 0x1366717d

// 1366717d: JMP 0x1337b2de

// 1337b2de: HLT
// ----------------

// 0x00: PushMachframe 0
RSP = *(uint64_t*) (RSP + 0x18);

// 0x00: AllocLarge 3
RSP += 3;

// 0x00: PushNonVol 10
R10 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack171[0x10000];
RSP = (uint64_t) &stack171[0x10000 - 8];


// 1337b380: MOV RBX,qword ptr [R9 + 0x28]
// switch to context pointer RBX

// 1337b384: MOV RSI,qword ptr [RBX + 0xc8]
RSI = *((uint64_t*) (&R10_old));

// 1337b38b: MOV R13,qword ptr [RBX + 0xd8]
R13 = *((uint64_t*) (&R12_old));

// 1337b392: MOVZX RSI,SIL
RSI = (*((uint8_t*) &RSI)) & 0xFF;

// 1337b396: JMP 0x136672af

// 136672af: JMP 0x1337b3ea

// 1337b3ea: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack172[0x10000];
RSP = (uint64_t) &stack172[0x10000 - 8];


// 1337b477: MOV RAX,qword ptr [R9 + 0x28]
// switch to context pointer RAX

// 1337b47b: LDMXCSR dword ptr [RAX + 0xa8]
MXCSR = *((uint32_t*) (&RSI_old));

// 1337b482: MOV R11,qword ptr [R9 + 0x28]
// switch to context pointer R11

// 1337b486: MOV R15,qword ptr [R11 + 0xe0]
R15 = *((uint64_t*) (&R13_old));

// 1337b48d: MOV R13,0x137fe2c48
R13 = 0x137fe2c48;

// 1337b497: ADD R13,0x80b1e78
R13 += 0x80b1e78;

// 1337b49e: JMP 0x136674c4

// 136674c4: JMP 0x1337b4ed

// 1337b4ed: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = R13 - 0;

// 0x00: AllocLarge 776
RSP += 776;

// 0x00: PushNonVol 6
RSI = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack173[0x10000];
RSP = (uint64_t) &stack173[0x10000 - 8];


// 1337b58a: MOV RSI,qword ptr [R9 + 0x28]
// switch to context pointer RSI

// 1337b58e: LDMXCSR dword ptr [RSI + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 1337b592: MOV R15,qword ptr [RSI + 0xa8]
R15 = *((uint64_t*) (&RSI_old));

// 1337b599: MOV R13,qword ptr [RSI + 0xf0]
R13 = *((uint64_t*) (&R15_old));

// 1337b5a0: JMP 0x13667604

// 13667604: JMP 0x1337b5e9

// 1337b5e9: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack174[0x10000];
RSP = (uint64_t) &stack174[0x10000 - 8];


// 1337b68d: MOV R8,qword ptr [R9 + 0x28]
// switch to context pointer R8

// 1337b691: MOV RSI,qword ptr [R8 + 0xe0]
RSI = *((uint64_t*) (&R13_old));

// 1337b698: MOV EBP,dword ptr [R8 + 0x34]
*((uint32_t*) &RBP) = *((uint32_t*) (&MXCSR_old));

// 1337b69c: ADD RBP,qword ptr [R8 + 0xf0]
RBP += *((uint64_t*) (&R15_old));

// 1337b6a3: MOV CL,byte ptr [RBP]
*((uint8_t*) &RCX) = *((uint8_t*) (RBP));

// 1337b6a6: MOV R14,0xff
R14 = 0xff;

// 1337b6ad: SHL R14,0x18
R14 <<= 0x18;

// 1337b6b1: NOT R14
R14 = ~R14;

// 1337b6b4: AND RSI,R14
RSI &= R14;

// 1337b6b7: MOVZX R14,CL
R14 = (*((uint8_t*) &RCX)) & 0xFF;

// 1337b6bb: SHL R14,0x18
R14 <<= 0x18;

// 1337b6bf: OR RSI,R14
RSI |= R14;

// 1337b6c2: JMP 0x136677b1

// 136677b1: JMP 0x1337b70c

// 1337b70c: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack175[0x10000];
RSP = (uint64_t) &stack175[0x10000 - 8];


// 1337b79c: MOV R8,qword ptr [R9 + 0x28]
// switch to context pointer R8

// 1337b7a0: MOV R14,qword ptr [R8 + 0xa8]
R14 = *((uint64_t*) (&RSI_old));

// 1337b7a7: PUSH R14
RSP -= 8;
*(uint64_t*) (RSP) = R14;

// 1337b7a9: MOV RSI,RSP
RSI = RSP;

// 1337b7ac: MOV RBX,qword ptr [R8 + 0xa8]
RBX = *((uint64_t*) (&RSI_old));

// 1337b7b3: JMP 0x136678e7

// 136678e7: JMP 0x1337b7f7

// 1337b7f7: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = RSI - 0;

// 0x00: AllocLarge 4
RSP += 4;

// 0x00: PushNonVol 14
R14 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack176[0x10000];
RSP = (uint64_t) &stack176[0x10000 - 8];


// 1337b898: MOV RSI,qword ptr [R9 + 0x28]
// switch to context pointer RSI

// 1337b89c: MOV R15,qword ptr [RSI + 0xe8]
R15 = *((uint64_t*) (&R14_old));

// 1337b8a3: MOV RBP,qword ptr [RSI + 0x90]
RBP = *((uint64_t*) (&RBX_old));

// 1337b8aa: MOVZX R15,R15B
R15 = (*((uint8_t*) &R15)) & 0xFF;

// 1337b8ae: JMP 0x13667a21

// 13667a21: JMP 0x1337b8f4

// 1337b8f4: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack177[0x10000];
RSP = (uint64_t) &stack177[0x10000 - 8];


// 1337b98c: MOV R13,qword ptr [R9 + 0x28]
// switch to context pointer R13

// 1337b990: LDMXCSR dword ptr [R13 + 0xf0]
MXCSR = *((uint32_t*) (&R15_old));

// 1337b998: MOV R11,qword ptr [R9 + 0x28]
// switch to context pointer R11

// 1337b99c: MOV RBP,qword ptr [R11 + 0xa0]
RBP = *((uint64_t*) (&RBP_old));

// 1337b9a3: MOV R15,0x13a700b34
R15 = 0x13a700b34;

// 1337b9ad: ADD R15,0x5993f8c
R15 += 0x5993f8c;

// 1337b9b4: JMP 0x13667c33

// 13667c33: JMP 0x1337ba04

// 1337ba04: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = R15 - 0;

// 0x00: PushNonVol 8
R8 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack178[0x10000];
RSP = (uint64_t) &stack178[0x10000 - 8];


// 1337ba9e: MOV R9,qword ptr [R9 + 0x28]
// switch to context pointer R9

// 1337baa2: LDMXCSR dword ptr [R9 + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 1337baa7: MOV R15,qword ptr [R9 + 0xb8]
R15 = *((uint64_t*) (&R8_old));

// 1337baae: MOV R14,qword ptr [R9 + 0xa0]
R14 = *((uint64_t*) (&RBP_old));

// 1337bab5: JMP 0x13667d69

// 13667d69: JMP 0x1337bb01

// 1337bb01: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack179[0x10000];
RSP = (uint64_t) &stack179[0x10000 - 8];


// 1337bb8b: MOV RCX,qword ptr [R9 + 0x28]
// switch to context pointer RCX

// 1337bb8f: MOV RSI,qword ptr [RCX + 0xe8]
RSI = *((uint64_t*) (&R14_old));

// 1337bb96: MOV EBP,dword ptr [RCX + 0x34]
*((uint32_t*) &RBP) = *((uint32_t*) (&MXCSR_old));

// 1337bb99: ADD RBP,qword ptr [RCX + 0xf0]
RBP += *((uint64_t*) (&R15_old));

// 1337bba0: MOV R11B,byte ptr [RBP]
*((uint8_t*) &R11) = *((uint8_t*) (RBP));

// 1337bba4: MOV R14,0xff
R14 = 0xff;

// 1337bbab: SHL R14,0x20
R14 <<= 0x20;

// 1337bbaf: NOT R14
R14 = ~R14;

// 1337bbb2: AND RSI,R14
RSI &= R14;

// 1337bbb5: MOVZX R14,R11B
R14 = (*((uint8_t*) &R11)) & 0xFF;

// 1337bbb9: SHL R14,0x20
R14 <<= 0x20;

// 1337bbbd: OR RSI,R14
RSI |= R14;

// 1337bbc0: JMP 0x13667f08

// 13667f08: JMP 0x1337bc02

// 1337bc02: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack180[0x10000];
RSP = (uint64_t) &stack180[0x10000 - 8];


// 1337bc92: MOV RSI,qword ptr [R9 + 0x28]
// switch to context pointer RSI

// 1337bc96: MOV R13,qword ptr [RSI + 0xa8]
R13 = *((uint64_t*) (&RSI_old));

// 1337bc9d: PUSH R13
RSP -= 8;
*(uint64_t*) (RSP) = R13;

// 1337bc9f: MOV RBX,RSP
RBX = RSP;

// 1337bca2: MOV RSI,qword ptr [RSI + 0xa8]
RSI = *((uint64_t*) (&RSI_old));

// 1337bca9: JMP 0x1366804c

// 1366804c: JMP 0x1337bcf7

// 1337bcf7: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = RBX - 0;

// 0x00: AllocLarge 7
RSP += 7;

// 0x00: PushNonVol 1
RCX = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack181[0x10000];
RSP = (uint64_t) &stack181[0x10000 - 8];


// 1337bd9d: MOV R10,qword ptr [R9 + 0x28]
// switch to context pointer R10

// 1337bda1: MOV R15,qword ptr [R10 + 0x80]
R15 = *((uint64_t*) (&RCX_old));

// 1337bda8: MOV R13,qword ptr [R10 + 0xa8]
R13 = *((uint64_t*) (&RSI_old));

// 1337bdaf: MOVZX R15,R15B
R15 = (*((uint8_t*) &R15)) & 0xFF;

// 1337bdb3: JMP 0x13668183

// 13668183: JMP 0x1337bdfe

// 1337bdfe: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack182[0x10000];
RSP = (uint64_t) &stack182[0x10000 - 8];


// 1337be93: MOV R15,qword ptr [R9 + 0x28]
// switch to context pointer R15

// 1337be97: LDMXCSR dword ptr [R15 + 0xf0]
MXCSR = *((uint32_t*) (&R15_old));

// 1337be9f: MOV R10,0xf1bff88a
R10 = 0xf1bff88a;

// 1337bea9: PUSH R10
RSP -= 8;
*(uint64_t*) (RSP) = R10;

// 1337beab: PUSH 0x657a1780
RSP -= 8;
*(uint64_t*) (RSP) = 0x657a1780;

// 1337beb0: PUSH 0x184518d9
RSP -= 8;
*(uint64_t*) (RSP) = 0x184518d9;

// 1337beb5: PUSH 0x7636391c
RSP -= 8;
*(uint64_t*) (RSP) = 0x7636391c;

// 1337beba: ADD qword ptr [RSP + 0x18],0x4e495236
*((uint64_t*) (RSP + 0x18)) += 0x4e495236;

// 1337bec3: MOV R11,qword ptr [R9 + 0x28]
// switch to context pointer R11

// 1337bec7: MOV R13,qword ptr [R11 + 0xe0]
R13 = *((uint64_t*) (&R13_old));

// 1337bece: JMP 0x1366838a

// 1366838a: JMP 0x1337bf13

// 1337bf13: HLT
// ----------------

// 0x00: PushMachframe 0
RSP = *(uint64_t*) (RSP + 0x18);

// 0x00: PushNonVol 8
R8 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack183[0x10000];
RSP = (uint64_t) &stack183[0x10000 - 8];


// 1337bfb1: MOV R14,qword ptr [R9 + 0x28]
// switch to context pointer R14

// 1337bfb5: LDMXCSR dword ptr [R14 + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 1337bfba: MOV RBX,qword ptr [R14 + 0xb8]
RBX = *((uint64_t*) (&R8_old));

// 1337bfc1: MOV R13,qword ptr [R14 + 0xe0]
R13 = *((uint64_t*) (&R13_old));

// 1337bfc8: JMP 0x136684c1

// 136684c1: JMP 0x1337c010

// 1337c010: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack184[0x10000];
RSP = (uint64_t) &stack184[0x10000 - 8];


// 1337c09e: MOV R8,qword ptr [R9 + 0x28]
// switch to context pointer R8

// 1337c0a2: MOV RBX,qword ptr [R8 + 0xe0]
RBX = *((uint64_t*) (&R13_old));

// 1337c0a9: MOV R11D,dword ptr [R8 + 0x34]
*((uint32_t*) &R11) = *((uint32_t*) (&MXCSR_old));

// 1337c0ad: ADD R11,qword ptr [R8 + 0x90]
R11 += *((uint64_t*) (&RBX_old));

// 1337c0b4: MOV R12B,byte ptr [R11]
*((uint8_t*) &R12) = *((uint8_t*) (R11));

// 1337c0b7: MOV R14,0xff
R14 = 0xff;

// 1337c0be: SHL R14,0x38
R14 <<= 0x38;

// 1337c0c2: NOT R14
R14 = ~R14;

// 1337c0c5: AND RBX,R14
RBX &= R14;

// 1337c0c8: MOVZX R14,R12B
R14 = (*((uint8_t*) &R12)) & 0xFF;

// 1337c0cc: SHL R14,0x38
R14 <<= 0x38;

// 1337c0d0: OR RBX,R14
RBX |= R14;

// 1337c0d3: JMP 0x13668660

// 13668660: JMP 0x1337c11b

// 1337c11b: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack185[0x10000];
RSP = (uint64_t) &stack185[0x10000 - 8];


// 1337c1b2: MOV RDI,qword ptr [R9 + 0x28]
// switch to context pointer RDI

// 1337c1b6: MOV RSI,qword ptr [RDI + 0x90]
RSI = *((uint64_t*) (&RBX_old));

// 1337c1bd: MOV R12,0x11350491d
R12 = 0x11350491d;

// 1337c1c7: ADD R12,0x2d396fcb
R12 += 0x2d396fcb;

// 1337c1ce: JMP 0x13668804

// 13668804: JMP 0x1337c213

// 1337c213: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = R12 - 0;

// 0x00: AllocSmall 16
RSP += 16;

// 0x00: PushNonVol 3
RBX = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack186[0x10000];
RSP = (uint64_t) &stack186[0x10000 - 8];


// 1337c2b0: MOV R9,qword ptr [R9 + 0x28]
// switch to context pointer R9

// 1337c2b4: MOV RDI,qword ptr [R9 + 0x90]
RDI = *((uint64_t*) (&RBX_old));

// 1337c2bb: MOV R13,qword ptr [R9 + 0xa8]
R13 = *((uint64_t*) (&RSI_old));

// 1337c2c2: MOVZX RDI,DIL
RDI = (*((uint8_t*) &RDI)) & 0xFF;

// 1337c2c6: JMP 0x13668938

// 13668938: JMP 0x1337c30f

// 1337c30f: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack187[0x10000];
RSP = (uint64_t) &stack187[0x10000 - 8];


// 1337c3a6: MOV R10,qword ptr [R9 + 0x28]
// switch to context pointer R10

// 1337c3aa: MOV RAX,qword ptr [R10 + 0xb0]
RAX = *((uint64_t*) (&RDI_old));

// 1337c3b1: MOV RBX,-0x4d8b5d4a
RBX = -0x4d8b5d4a;

// 1337c3b8: ADD RBX,0x4e257502
RBX += 0x4e257502;

// 1337c3bf: PUSH RBX
RSP -= 8;
*(uint64_t*) (RSP) = RBX;

// 1337c3c0: MOV RDI,qword ptr [R10 + 0xe0]
RDI = *((uint64_t*) (&R13_old));

// 1337c3c7: MUL qword ptr [RSP]
RAX *= *((uint64_t*) (RSP));

// 1337c3cb: MOV RSI,RAX
RSI = RAX;

// 1337c3ce: JMP 0x13668b42

// 13668b42: JMP 0x1337c410

// 1337c410: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack188[0x10000];
RSP = (uint64_t) &stack188[0x10000 - 8];


// 1337c4b4: MOV R11,qword ptr [R9 + 0x28]
// switch to context pointer R11

// 1337c4b8: MOV R12,qword ptr [R11 + 0xb0]
R12 = *((uint64_t*) (&RDI_old));

// 1337c4bf: XOR R12,qword ptr [R11 + 0xa8]
R12 ^= *((uint64_t*) (&RSI_old));

// 1337c4c6: JMP 0x13668c80

// 13668c80: JMP 0x1337c517

// 1337c517: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack189[0x10000];
RSP = (uint64_t) &stack189[0x10000 - 8];


// 1337c5b9: MOV R13,qword ptr [R9 + 0x28]
// switch to context pointer R13

// 1337c5bd: MOV RAX,qword ptr [R13 + 0xd8]
RAX = *((uint64_t*) (&R12_old));

// 1337c5c4: PUSH RAX
RSP -= 8;
*(uint64_t*) (RSP) = RAX;

// 1337c5c5: MOV R15,RSP
R15 = RSP;

// 1337c5c8: MOV R13,qword ptr [R13 + 0xd8]
R13 = *((uint64_t*) (&R12_old));

// 1337c5cf: JMP 0x13668dbf

// 13668dbf: JMP 0x1337c616

// 1337c616: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack190[0x10000];
RSP = (uint64_t) &stack190[0x10000 - 8];


// 1337c6a5: MOV R8,qword ptr [R9 + 0x28]
// switch to context pointer R8

// 1337c6a9: MOV R10,qword ptr [R8 + 0xf0]
R10 = *((uint64_t*) (&R15_old));

// 1337c6b0: MOV R13,qword ptr [R8 + 0xe0]
R13 = *((uint64_t*) (&R13_old));

// 1337c6b7: PUSH R10
RSP -= 8;
*(uint64_t*) (RSP) = R10;

// 1337c6b9: PUSH 0x1c279de
RSP -= 8;
*(uint64_t*) (RSP) = 0x1c279de;

// 1337c6be: PUSH 0x75ef360f
RSP -= 8;
*(uint64_t*) (RSP) = 0x75ef360f;

// 1337c6c3: PUSH 0x35591de9
RSP -= 8;
*(uint64_t*) (RSP) = 0x35591de9;

// 1337c6c8: PUSH 0x3d6c7ce5
RSP -= 8;
*(uint64_t*) (RSP) = 0x3d6c7ce5;

// 1337c6cd: JMP 0x13668ef4

// 13668ef4: JMP 0x1337c71c

// 1337c71c: HLT
// ----------------

// 0x00: PushMachframe 1
RSP = *(uint64_t*) (RSP + 0x20);

// 0x00: PushNonVol 3
RBX = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack191[0x10000];
RSP = (uint64_t) &stack191[0x10000 - 8];


// 1337c7bc: MOV RDI,qword ptr [R9 + 0x28]
// switch to context pointer RDI

// 1337c7c0: MOV R12,qword ptr [RDI + 0x90]
R12 = *((uint64_t*) (&RBX_old));

// 1337c7c7: MOV RBP,qword ptr [RDI + 0xe0]
RBP = *((uint64_t*) (&R13_old));

// 1337c7ce: MOVZX R12,R12B
R12 = (*((uint8_t*) &R12)) & 0xFF;

// 1337c7d2: JMP 0x13669032

// 13669032: JMP 0x1337c81f

// 1337c81f: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack192[0x10000];
RSP = (uint64_t) &stack192[0x10000 - 8];


// 1337c8ac: MOV RSI,qword ptr [R9 + 0x28]
// switch to context pointer RSI

// 1337c8b0: LDMXCSR dword ptr [RSI + 0xd8]
MXCSR = *((uint32_t*) (&R12_old));

// 1337c8b7: MOV RDI,0x11d243c38
RDI = 0x11d243c38;

// 1337c8c1: ADD RDI,0x22e53688
RDI += 0x22e53688;

// 1337c8c8: MOV RDI,qword ptr [RDI + 0x588]
RDI = *((uint64_t*) (RDI + 0x588));

// 1337c8cf: ADD RDI,qword ptr [RSI + 0xd8]
RDI += *((uint64_t*) (&R12_old));

// 1337c8d6: MOV DIL,byte ptr [RDI]
*((uint8_t*) &RDI) = *((uint8_t*) (RDI));

// 1337c8d9: MOVZX RDI,DIL
RDI = (*((uint8_t*) &RDI)) & 0xFF;

// 1337c8dd: SHL RDI,0x8
RDI <<= 0x8;

// 1337c8e1: SUB qword ptr [RSI + 0xa0],RDI
*((uint64_t*) (&RBP_old)) -= RDI;

// 1337c8e8: MOV R11,0x110b601db
R11 = 0x110b601db;

// 1337c8f2: PUSH R11
RSP -= 8;
*(uint64_t*) (RSP) = R11;

// 1337c8f4: PUSH 0x19ef38b8
RSP -= 8;
*(uint64_t*) (RSP) = 0x19ef38b8;

// 1337c8f9: PUSH 0x4cae03c9
RSP -= 8;
*(uint64_t*) (RSP) = 0x4cae03c9;

// 1337c8fe: PUSH 0x94911d6
RSP -= 8;
*(uint64_t*) (RSP) = 0x94911d6;

// 1337c903: PUSH 0x7bc25848
RSP -= 8;
*(uint64_t*) (RSP) = 0x7bc25848;

// 1337c908: ADD qword ptr [RSP + 0x20],0x2f5368e5
*((uint64_t*) (RSP + 0x20)) += 0x2f5368e5;

// 1337c911: MOV RCX,qword ptr [R9 + 0x28]
// switch to context pointer RCX

// 1337c915: MOV R14,qword ptr [RCX + 0xa0]
R14 = *((uint64_t*) (&RBP_old));

// 1337c91c: JMP 0x13669457

// 13669457: JMP 0x1337c96d

// 1337c96d: HLT
// ----------------

// 0x00: PushMachframe 1
RSP = *(uint64_t*) (RSP + 0x20);

// 0x00: AllocLarge 1416
RSP += 1416;

// 0x00: PushNonVol 7
RDI = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack193[0x10000];
RSP = (uint64_t) &stack193[0x10000 - 8];


// 1337ca16: MOV RSI,qword ptr [R9 + 0x28]
// switch to context pointer RSI

// 1337ca1a: LDMXCSR dword ptr [RSI + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 1337ca1e: MOV RDI,qword ptr [RSI + 0xb0]
RDI = *((uint64_t*) (&RDI_old));

// 1337ca25: MOV R15,qword ptr [RSI + 0xe8]
R15 = *((uint64_t*) (&R14_old));

// 1337ca2c: JMP 0x1366958f

// 1366958f: JMP 0x1337ca74

// 1337ca74: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack194[0x10000];
RSP = (uint64_t) &stack194[0x10000 - 8];


// 1337cb00: MOV RBP,qword ptr [R9 + 0x28]
// switch to context pointer RBP

// 1337cb04: MOV R13,qword ptr [RBP + 0xf0]
R13 = *((uint64_t*) (&R15_old));

// 1337cb0b: MOV R12D,dword ptr [RBP + 0x34]
*((uint32_t*) &R12) = *((uint32_t*) (&MXCSR_old));

// 1337cb0f: ADD R12,qword ptr [RBP + 0xb0]
R12 += *((uint64_t*) (&RDI_old));

// 1337cb16: MOV DL,byte ptr [R12]
*((uint8_t*) &RDX) = *((uint8_t*) (R12));

// 1337cb1a: MOV R13B,DL
*((uint8_t*) &R13) = *((uint8_t*) &RDX);

// 1337cb1d: JMP 0x136696c7

// 136696c7: JMP 0x1337cb71

// 1337cb71: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack195[0x10000];
RSP = (uint64_t) &stack195[0x10000 - 8];


// 1337cbf7: MOV RDX,qword ptr [R9 + 0x28]
// switch to context pointer RDX

// 1337cbfb: MOV R10,qword ptr [RDX + 0xe0]
R10 = *((uint64_t*) (&R13_old));

// 1337cc02: PUSH R10
RSP -= 8;
*(uint64_t*) (RSP) = R10;

// 1337cc04: MOV R13,RSP
R13 = RSP;

// 1337cc07: MOV RBX,qword ptr [RDX + 0xe0]
RBX = *((uint64_t*) (&R13_old));

// 1337cc0e: JMP 0x13669803

// 13669803: JMP 0x1337cc58

// 1337cc58: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack196[0x10000];
RSP = (uint64_t) &stack196[0x10000 - 8];


// 1337ccf4: MOV RAX,qword ptr [R9 + 0x28]
// switch to context pointer RAX

// 1337ccf8: MOV R9,qword ptr [RAX + 0xe0]
R9 = *((uint64_t*) (&R13_old));

// 1337ccff: MOV RBP,qword ptr [RAX + 0x90]
RBP = *((uint64_t*) (&RBX_old));

// 1337cd06: PUSH R9
RSP -= 8;
*(uint64_t*) (RSP) = R9;

// 1337cd08: PUSH 0x5d0a5bfb
RSP -= 8;
*(uint64_t*) (RSP) = 0x5d0a5bfb;

// 1337cd0d: PUSH 0x47dc6da8
RSP -= 8;
*(uint64_t*) (RSP) = 0x47dc6da8;

// 1337cd12: PUSH 0xc6b7ec6
RSP -= 8;
*(uint64_t*) (RSP) = 0xc6b7ec6;

// 1337cd17: JMP 0x13669937

// 13669937: JMP 0x1337cd5c

// 1337cd5c: HLT
// ----------------

// 0x00: PushMachframe 0
RSP = *(uint64_t*) (RSP + 0x18);

// 0x00: AllocLarge 1
RSP += 1;

// 0x00: PushNonVol 15
R15 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack197[0x10000];
RSP = (uint64_t) &stack197[0x10000 - 8];


// 1337cdf5: MOV R11,qword ptr [R9 + 0x28]
// switch to context pointer R11

// 1337cdf9: MOV RBX,qword ptr [R11 + 0xf0]
RBX = *((uint64_t*) (&R15_old));

// 1337ce00: MOV R12,qword ptr [R11 + 0xa0]
R12 = *((uint64_t*) (&RBP_old));

// 1337ce07: MOVZX RBX,BL
RBX = (*((uint8_t*) &RBX)) & 0xFF;

// 1337ce0b: JMP 0x13669a67

// 13669a67: JMP 0x1337ce56

// 1337ce56: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack198[0x10000];
RSP = (uint64_t) &stack198[0x10000 - 8];


// 1337cede: MOV RDI,qword ptr [R9 + 0x28]
// switch to context pointer RDI

// 1337cee2: LDMXCSR dword ptr [RDI + 0x90]
MXCSR = *((uint32_t*) (&RBX_old));

// 1337cee9: MOV R14,0xe0d462dd
R14 = 0xe0d462dd;

// 1337cef3: ADD R14,0x5f350fe3
R14 += 0x5f350fe3;

// 1337cefa: MOV R14,qword ptr [R14 + 0x20]
R14 = *((uint64_t*) (R14 + 0x20));

// 1337cefe: ADD R14,qword ptr [RDI + 0x90]
R14 += *((uint64_t*) (&RBX_old));

// 1337cf05: MOV DL,byte ptr [R14]
*((uint8_t*) &RDX) = *((uint8_t*) (R14));

// 1337cf08: MOVZX RDX,DL
RDX = (*((uint8_t*) &RDX)) & 0xFF;

// 1337cf0c: SHL RDX,0x10
RDX <<= 0x10;

// 1337cf10: SUB qword ptr [RDI + 0xd8],RDX
*((uint64_t*) (&R12_old)) -= RDX;

// 1337cf17: MOV RAX,qword ptr [R9 + 0x28]
// switch to context pointer RAX

// 1337cf1b: MOV RDI,qword ptr [RAX + 0xd8]
RDI = *((uint64_t*) (&R12_old));

// 1337cf22: MOV R15,0x124f905ae
R15 = 0x124f905ae;

// 1337cf2c: ADD R15,0x1b106512
R15 += 0x1b106512;

// 1337cf33: JMP 0x13669e1f

// 13669e1f: JMP 0x1337cf75

// 1337cf75: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = R15 - 0;

// 0x00: AllocLarge 32
RSP += 32;

// 0x00: PushNonVol 13
R13 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack199[0x10000];
RSP = (uint64_t) &stack199[0x10000 - 8];


// 1337d01e: MOV R10,qword ptr [R9 + 0x28]
// switch to context pointer R10

// 1337d022: LDMXCSR dword ptr [R10 + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 1337d027: MOV R14,qword ptr [R10 + 0xe0]
R14 = *((uint64_t*) (&R13_old));

// 1337d02e: MOV RBX,qword ptr [R10 + 0xb0]
RBX = *((uint64_t*) (&RDI_old));

// 1337d035: JMP 0x13669f5c

// 13669f5c: JMP 0x1337d07b

// 1337d07b: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack200[0x10000];
RSP = (uint64_t) &stack200[0x10000 - 8];


// 1337d11b: MOV RDI,qword ptr [R9 + 0x28]
// switch to context pointer RDI

// 1337d11f: MOV R13,qword ptr [RDI + 0x90]
R13 = *((uint64_t*) (&RBX_old));

// 1337d126: MOV R9D,dword ptr [RDI + 0x34]
*((uint32_t*) &R9) = *((uint32_t*) (&MXCSR_old));

// 1337d12a: ADD R9,qword ptr [RDI + 0xe8]
R9 += *((uint64_t*) (&R14_old));

// 1337d131: MOV DL,byte ptr [R9]
*((uint8_t*) &RDX) = *((uint8_t*) (R9));

// 1337d134: MOV R9,0xff
R9 = 0xff;

// 1337d13b: SHL R9,0x8
R9 <<= 0x8;

// 1337d13f: NOT R9
R9 = ~R9;

// 1337d142: AND R13,R9
R13 &= R9;

// 1337d145: MOVZX R9,DL
R9 = (*((uint8_t*) &RDX)) & 0xFF;

// 1337d149: SHL R9,0x8
R9 <<= 0x8;

// 1337d14d: OR R13,R9
R13 |= R9;

// 1337d150: JMP 0x1366a0fe

// 1366a0fe: JMP 0x1337d19a

// 1337d19a: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack201[0x10000];
RSP = (uint64_t) &stack201[0x10000 - 8];


// 1337d236: MOV R13,qword ptr [R9 + 0x28]
// switch to context pointer R13

// 1337d23a: MOV R10,qword ptr [R13 + 0xe0]
R10 = *((uint64_t*) (&R13_old));

// 1337d241: PUSH R10
RSP -= 8;
*(uint64_t*) (RSP) = R10;

// 1337d243: MOV RDI,RSP
RDI = RSP;

// 1337d246: MOV RSI,qword ptr [R13 + 0xe0]
RSI = *((uint64_t*) (&R13_old));

// 1337d24d: JMP 0x1366a238

// 1366a238: JMP 0x1337d295

// 1337d295: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack202[0x10000];
RSP = (uint64_t) &stack202[0x10000 - 8];


// 1337d329: MOV R9,qword ptr [R9 + 0x28]
// switch to context pointer R9

// 1337d32d: MOV RSI,qword ptr [R9 + 0xb0]
RSI = *((uint64_t*) (&RDI_old));

// 1337d334: MOV RBX,qword ptr [R9 + 0xa8]
RBX = *((uint64_t*) (&RSI_old));

// 1337d33b: PUSH RSI
RSP -= 8;
*(uint64_t*) (RSP) = RSI;

// 1337d33c: PUSH 0x47933421
RSP -= 8;
*(uint64_t*) (RSP) = 0x47933421;

// 1337d341: PUSH 0x5396644e
RSP -= 8;
*(uint64_t*) (RSP) = 0x5396644e;

// 1337d346: PUSH 0x41c81546
RSP -= 8;
*(uint64_t*) (RSP) = 0x41c81546;

// 1337d34b: JMP 0x1366a375

// 1366a375: JMP 0x1337d393

// 1337d393: HLT
// ----------------

// 0x00: PushMachframe 0
RSP = *(uint64_t*) (RSP + 0x18);

// 0x00: AllocLarge 2
RSP += 2;

// 0x00: PushNonVol 10
R10 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack203[0x10000];
RSP = (uint64_t) &stack203[0x10000 - 8];


// 1337d42a: MOV RBX,qword ptr [R9 + 0x28]
// switch to context pointer RBX

// 1337d42e: MOV RBP,qword ptr [RBX + 0xc8]
RBP = *((uint64_t*) (&R10_old));

// 1337d435: MOV R13,qword ptr [RBX + 0x90]
R13 = *((uint64_t*) (&RBX_old));

// 1337d43c: MOVZX RBP,BPL
RBP = (*((uint8_t*) &RBP)) & 0xFF;

// 1337d440: JMP 0x1366a4b2

// 1366a4b2: JMP 0x1337d490

// 1337d490: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack204[0x10000];
RSP = (uint64_t) &stack204[0x10000 - 8];


// 1337d52b: MOV RDI,qword ptr [R9 + 0x28]
// switch to context pointer RDI

// 1337d52f: LDMXCSR dword ptr [RDI + 0xa0]
MXCSR = *((uint32_t*) (&RBP_old));

// 1337d536: MOV R11,0xc823f319
R11 = 0xc823f319;

// 1337d540: ADD R11,0x77e57fa7
R11 += 0x77e57fa7;

// 1337d547: MOV R11,qword ptr [R11 + 0x140]
R11 = *((uint64_t*) (R11 + 0x140));

// 1337d54e: ADD R11,qword ptr [RDI + 0xa0]
R11 += *((uint64_t*) (&RBP_old));

// 1337d555: MOV R8B,byte ptr [R11]
*((uint8_t*) &R8) = *((uint8_t*) (R11));

// 1337d558: MOVZX R8,R8B
R8 = (*((uint8_t*) &R8)) & 0xFF;

// 1337d55c: SHL R8,0x18
R8 <<= 0x18;

// 1337d560: SUB qword ptr [RDI + 0xe0],R8
*((uint64_t*) (&R13_old)) -= R8;

// 1337d567: MOV RCX,0x13508eccd
RCX = 0x13508eccd;

// 1337d571: PUSH RCX
RSP -= 8;
*(uint64_t*) (RSP) = RCX;

// 1337d572: PUSH 0x2db1adf
RSP -= 8;
*(uint64_t*) (RSP) = 0x2db1adf;

// 1337d577: PUSH 0x45450e0a
RSP -= 8;
*(uint64_t*) (RSP) = 0x45450e0a;

// 1337d57c: PUSH 0x38d76eae
RSP -= 8;
*(uint64_t*) (RSP) = 0x38d76eae;

// 1337d581: PUSH 0x60a62e34
RSP -= 8;
*(uint64_t*) (RSP) = 0x60a62e34;

// 1337d586: ADD qword ptr [RSP + 0x20],0xb007df3
*((uint64_t*) (RSP + 0x20)) += 0xb007df3;

// 1337d58f: MOV R12,qword ptr [R9 + 0x28]
// switch to context pointer R12

// 1337d593: MOV RBP,qword ptr [R12 + 0xe0]
RBP = *((uint64_t*) (&R13_old));

// 1337d59b: JMP 0x1366a8c0

// 1366a8c0: JMP 0x1337d5e5

// 1337d5e5: HLT
// ----------------

// 0x00: PushMachframe 1
RSP = *(uint64_t*) (RSP + 0x20);

// 0x00: AllocLarge 320
RSP += 320;

// 0x00: PushNonVol 13
R13 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack205[0x10000];
RSP = (uint64_t) &stack205[0x10000 - 8];


// 1337d681: MOV RSI,qword ptr [R9 + 0x28]
// switch to context pointer RSI

// 1337d685: LDMXCSR dword ptr [RSI + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 1337d689: MOV R15,qword ptr [RSI + 0xe0]
R15 = *((uint64_t*) (&R13_old));

// 1337d690: MOV RSI,qword ptr [RSI + 0xa0]
RSI = *((uint64_t*) (&RBP_old));

// 1337d697: JMP 0x1366a9f7

// 1366a9f7: JMP 0x1337d6e9

// 1337d6e9: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack206[0x10000];
RSP = (uint64_t) &stack206[0x10000 - 8];


// 1337d788: MOV R10,qword ptr [R9 + 0x28]
// switch to context pointer R10

// 1337d78c: MOV RDI,qword ptr [R10 + 0xa8]
RDI = *((uint64_t*) (&RSI_old));

// 1337d793: MOV EAX,dword ptr [R10 + 0x34]
*((uint32_t*) &RAX) = *((uint32_t*) (&MXCSR_old));

// 1337d797: ADD RAX,qword ptr [R10 + 0xf0]
RAX += *((uint64_t*) (&R15_old));

// 1337d79e: MOV R13B,byte ptr [RAX]
*((uint8_t*) &R13) = *((uint8_t*) (RAX));

// 1337d7a1: MOV RBX,0xff
RBX = 0xff;

// 1337d7a8: SHL RBX,0x10
RBX <<= 0x10;

// 1337d7ac: NOT RBX
RBX = ~RBX;

// 1337d7af: AND RDI,RBX
RDI &= RBX;

// 1337d7b2: MOVZX RBX,R13B
RBX = (*((uint8_t*) &R13)) & 0xFF;

// 1337d7b6: SHL RBX,0x10
RBX <<= 0x10;

// 1337d7ba: OR RDI,RBX
RDI |= RBX;

// 1337d7bd: JMP 0x1366aba3

// 1366aba3: JMP 0x1337d809

// 1337d809: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack207[0x10000];
RSP = (uint64_t) &stack207[0x10000 - 8];


// 1337d89d: MOV RBX,qword ptr [R9 + 0x28]
// switch to context pointer RBX

// 1337d8a1: MOV RDI,qword ptr [RBX + 0xb0]
RDI = *((uint64_t*) (&RDI_old));

// 1337d8a8: PUSH RDI
RSP -= 8;
*(uint64_t*) (RSP) = RDI;

// 1337d8a9: MOV R14,RSP
R14 = RSP;

// 1337d8ac: MOV R13,qword ptr [RBX + 0xb0]
R13 = *((uint64_t*) (&RDI_old));

// 1337d8b3: JMP 0x1366acd8

// 1366acd8: JMP 0x1337d8fa

// 1337d8fa: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = R14 - 0;

// 0x00: AllocLarge 3
RSP += 3;

// 0x00: PushNonVol 3
RBX = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack208[0x10000];
RSP = (uint64_t) &stack208[0x10000 - 8];


// 1337d995: MOV R9,qword ptr [R9 + 0x28]
// switch to context pointer R9

// 1337d999: MOV RDI,qword ptr [R9 + 0x90]
RDI = *((uint64_t*) (&RBX_old));

// 1337d9a0: MOV RBX,qword ptr [R9 + 0xe0]
RBX = *((uint64_t*) (&R13_old));

// 1337d9a7: MOVZX RDI,DIL
RDI = (*((uint8_t*) &RDI)) & 0xFF;

// 1337d9ab: JMP 0x1366ae0f

// 1366ae0f: JMP 0x1337d9f0

// 1337d9f0: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack209[0x10000];
RSP = (uint64_t) &stack209[0x10000 - 8];


// 1337da95: MOV RBP,qword ptr [R9 + 0x28]
// switch to context pointer RBP

// 1337da99: LDMXCSR dword ptr [RBP + 0xb0]
MXCSR = *((uint32_t*) (&RDI_old));

// 1337daa0: MOV R11,0x1158c3c33
R11 = 0x1158c3c33;

// 1337daaa: ADD R11,0x2a7d368d
R11 += 0x2a7d368d;

// 1337dab1: MOV R11,qword ptr [R11 + 0x650]
R11 = *((uint64_t*) (R11 + 0x650));

// 1337dab8: ADD R11,qword ptr [RBP + 0xb0]
R11 += *((uint64_t*) (&RDI_old));

// 1337dabf: MOV DL,byte ptr [R11]
*((uint8_t*) &RDX) = *((uint8_t*) (R11));

// 1337dac2: MOVZX RDX,DL
RDX = (*((uint8_t*) &RDX)) & 0xFF;

// 1337dac6: SHL RDX,0x20
RDX <<= 0x20;

// 1337daca: SUB qword ptr [RBP + 0x90],RDX
*((uint64_t*) (&RBX_old)) -= RDX;

// 1337dad1: MOV RCX,qword ptr [R9 + 0x28]
// switch to context pointer RCX

// 1337dad5: MOV RSI,qword ptr [RCX + 0x90]
RSI = *((uint64_t*) (&RBX_old));

// 1337dadc: MOV RBP,0xf5dff1de
RBP = 0xf5dff1de;

// 1337dae6: ADD RBP,0x4a2978e2
RBP += 0x4a2978e2;

// 1337daed: JMP 0x1366b230

// 1366b230: JMP 0x1337db40

// 1337db40: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = RBP - 0;

// 0x00: AllocLarge 1616
RSP += 1616;

// 0x00: PushNonVol 2
RDX = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack210[0x10000];
RSP = (uint64_t) &stack210[0x10000 - 8];


// 1337dbdc: MOV R13,qword ptr [R9 + 0x28]
// switch to context pointer R13

// 1337dbe0: LDMXCSR dword ptr [R13 + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 1337dbe5: MOV RBP,qword ptr [R13 + 0x88]
RBP = *((uint64_t*) (&RDX_old));

// 1337dbec: MOV R12,qword ptr [R13 + 0xa8]
R12 = *((uint64_t*) (&RSI_old));

// 1337dbf3: JMP 0x1366b368

// 1366b368: JMP 0x1337dc3c

// 1337dc3c: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack211[0x10000];
RSP = (uint64_t) &stack211[0x10000 - 8];


// 1337dcc8: MOV RSI,qword ptr [R9 + 0x28]
// switch to context pointer RSI

// 1337dccc: MOV R15,qword ptr [RSI + 0xd8]
R15 = *((uint64_t*) (&R12_old));

// 1337dcd3: MOV R9D,dword ptr [RSI + 0x34]
*((uint32_t*) &R9) = *((uint32_t*) (&MXCSR_old));

// 1337dcd7: ADD R9,qword ptr [RSI + 0xa0]
R9 += *((uint64_t*) (&RBP_old));

// 1337dcde: MOV AL,byte ptr [R9]
*((uint8_t*) &RAX) = *((uint8_t*) (R9));

// 1337dce1: MOV RDX,0xff
RDX = 0xff;

// 1337dce8: SHL RDX,0x18
RDX <<= 0x18;

// 1337dcec: NOT RDX
RDX = ~RDX;

// 1337dcef: AND R15,RDX
R15 &= RDX;

// 1337dcf2: MOVZX RDX,AL
RDX = (*((uint8_t*) &RAX)) & 0xFF;

// 1337dcf6: SHL RDX,0x18
RDX <<= 0x18;

// 1337dcfa: OR R15,RDX
R15 |= RDX;

// 1337dcfd: JMP 0x1366b50b

// 1366b50b: JMP 0x1337dd45

// 1337dd45: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack212[0x10000];
RSP = (uint64_t) &stack212[0x10000 - 8];


// 1337dddc: MOV RBX,qword ptr [R9 + 0x28]
// switch to context pointer RBX

// 1337dde0: MOV R10,qword ptr [RBX + 0xf0]
R10 = *((uint64_t*) (&R15_old));

// 1337dde7: PUSH R10
RSP -= 8;
*(uint64_t*) (RSP) = R10;

// 1337dde9: MOV RSI,RSP
RSI = RSP;

// 1337ddec: MOV RDI,qword ptr [RBX + 0xf0]
RDI = *((uint64_t*) (&R15_old));

// 1337ddf3: JMP 0x1366b644

// 1366b644: JMP 0x1337de35

// 1337de35: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = RSI - 0;

// 0x00: AllocLarge 4
RSP += 4;

// 0x00: PushNonVol 13
R13 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack213[0x10000];
RSP = (uint64_t) &stack213[0x10000 - 8];


// 1337dee4: MOV RSI,qword ptr [R9 + 0x28]
// switch to context pointer RSI

// 1337dee8: MOV RBP,qword ptr [RSI + 0xe0]
RBP = *((uint64_t*) (&R13_old));

// 1337deef: MOV R13,qword ptr [RSI + 0xb0]
R13 = *((uint64_t*) (&RDI_old));

// 1337def6: MOVZX RBP,BPL
RBP = (*((uint8_t*) &RBP)) & 0xFF;

// 1337defa: JMP 0x1366b782

// 1366b782: JMP 0x1337df3d

// 1337df3d: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack214[0x10000];
RSP = (uint64_t) &stack214[0x10000 - 8];


// 1337dfd0: MOV R8,qword ptr [R9 + 0x28]
// switch to context pointer R8

// 1337dfd4: LDMXCSR dword ptr [R8 + 0xa0]
MXCSR = *((uint32_t*) (&RBP_old));

// 1337dfdc: MOV R13,0x12d365faa
R13 = 0x12d365faa;

// 1337dfe6: ADD R13,0x12d31316
R13 += 0x12d31316;

// 1337dfed: MOV R13,qword ptr [R13]
R13 = *((uint64_t*) (R13));

// 1337dff1: ADD R13,qword ptr [R8 + 0xa0]
R13 += *((uint64_t*) (&RBP_old));

// 1337dff8: MOV AL,byte ptr [R13]
*((uint8_t*) &RAX) = *((uint8_t*) (R13));

// 1337dffc: MOVZX RAX,AL
RAX = (*((uint8_t*) &RAX)) & 0xFF;

// 1337e000: SHL RAX,0x28
RAX <<= 0x28;

// 1337e004: SUB qword ptr [R8 + 0xe0],RAX
*((uint64_t*) (&R13_old)) -= RAX;

// 1337e00b: MOV RBX,0x10db62f6f
RBX = 0x10db62f6f;

// 1337e015: PUSH RBX
RSP -= 8;
*(uint64_t*) (RSP) = RBX;

// 1337e016: PUSH 0x76e158ca
RSP -= 8;
*(uint64_t*) (RSP) = 0x76e158ca;

// 1337e01b: PUSH 0x50260c59
RSP -= 8;
*(uint64_t*) (RSP) = 0x50260c59;

// 1337e020: PUSH 0x38973dcf
RSP -= 8;
*(uint64_t*) (RSP) = 0x38973dcf;

// 1337e025: PUSH 0x208c3833
RSP -= 8;
*(uint64_t*) (RSP) = 0x208c3833;

// 1337e02a: ADD qword ptr [RSP + 0x20],0x32533b51
*((uint64_t*) (RSP + 0x20)) += 0x32533b51;

// 1337e033: MOV RDI,qword ptr [R9 + 0x28]
// switch to context pointer RDI

// 1337e037: MOV RBP,qword ptr [RDI + 0xe0]
RBP = *((uint64_t*) (&R13_old));

// 1337e03e: JMP 0x1366bb41

// 1366bb41: JMP 0x1337e082

// 1337e082: HLT
// ----------------

// 0x00: PushMachframe 1
RSP = *(uint64_t*) (RSP + 0x20);

// 0x00: PushNonVol 6
RSI = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack215[0x10000];
RSP = (uint64_t) &stack215[0x10000 - 8];


// 1337e122: MOV R10,qword ptr [R9 + 0x28]
// switch to context pointer R10

// 1337e126: LDMXCSR dword ptr [R10 + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 1337e12b: MOV RSI,qword ptr [R10 + 0xa8]
RSI = *((uint64_t*) (&RSI_old));

// 1337e132: MOV R15,qword ptr [R10 + 0xa0]
R15 = *((uint64_t*) (&RBP_old));

// 1337e139: JMP 0x1366bc80

// 1366bc80: JMP 0x1337e188

// 1337e188: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack216[0x10000];
RSP = (uint64_t) &stack216[0x10000 - 8];


// 1337e223: MOV RDX,qword ptr [R9 + 0x28]
// switch to context pointer RDX

// 1337e227: MOV R15,qword ptr [RDX + 0xf0]
R15 = *((uint64_t*) (&R15_old));

// 1337e22e: MOV R9D,dword ptr [RDX + 0x34]
*((uint32_t*) &R9) = *((uint32_t*) (&MXCSR_old));

// 1337e232: ADD R9,qword ptr [RDX + 0xa8]
R9 += *((uint64_t*) (&RSI_old));

// 1337e239: MOV R14B,byte ptr [R9]
*((uint8_t*) &R14) = *((uint8_t*) (R9));

// 1337e23c: MOV RDX,0xff
RDX = 0xff;

// 1337e243: SHL RDX,0x20
RDX <<= 0x20;

// 1337e247: NOT RDX
RDX = ~RDX;

// 1337e24a: AND R15,RDX
R15 &= RDX;

// 1337e24d: MOVZX RDX,R14B
RDX = (*((uint8_t*) &R14)) & 0xFF;

// 1337e251: SHL RDX,0x20
RDX <<= 0x20;

// 1337e255: OR R15,RDX
R15 |= RDX;

// 1337e258: JMP 0x1366be2a

// 1366be2a: JMP 0x1337e2a7

// 1337e2a7: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack217[0x10000];
RSP = (uint64_t) &stack217[0x10000 - 8];


// 1337e339: MOV RBX,qword ptr [R9 + 0x28]
// switch to context pointer RBX

// 1337e33d: MOV R10,qword ptr [RBX + 0xf0]
R10 = *((uint64_t*) (&R15_old));

// 1337e344: PUSH R10
RSP -= 8;
*(uint64_t*) (RSP) = R10;

// 1337e346: MOV R15,RSP
R15 = RSP;

// 1337e349: MOV R13,qword ptr [RBX + 0xf0]
R13 = *((uint64_t*) (&R15_old));

// 1337e350: JMP 0x1366bf5f

// 1366bf5f: JMP 0x1337e391

// 1337e391: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = R15 - 0;

// 0x00: AllocLarge 5
RSP += 5;

// 0x00: PushNonVol 9
R9 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack218[0x10000];
RSP = (uint64_t) &stack218[0x10000 - 8];


// 1337e442: MOV R9,qword ptr [R9 + 0x28]
// switch to context pointer R9

// 1337e446: MOV R12,qword ptr [R9 + 0xc0]
R12 = *((uint64_t*) (&R9_old));

// 1337e44d: MOV RBX,qword ptr [R9 + 0xe0]
RBX = *((uint64_t*) (&R13_old));

// 1337e454: MOVZX R12,R12B
R12 = (*((uint8_t*) &R12)) & 0xFF;

// 1337e458: JMP 0x1366c09a

// 1366c09a: JMP 0x1337e49c

// 1337e49c: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack219[0x10000];
RSP = (uint64_t) &stack219[0x10000 - 8];


// 1337e542: MOV R10,qword ptr [R9 + 0x28]
// switch to context pointer R10

// 1337e546: LDMXCSR dword ptr [R10 + 0xd8]
MXCSR = *((uint32_t*) (&R12_old));

// 1337e54e: MOV RBP,0x1074603d5
RBP = 0x1074603d5;

// 1337e558: ADD RBP,0x38c36eeb
RBP += 0x38c36eeb;

// 1337e55f: MOV RBP,qword ptr [RBP]
RBP = *((uint64_t*) (RBP));

// 1337e563: ADD RBP,qword ptr [R10 + 0xd8]
RBP += *((uint64_t*) (&R12_old));

// 1337e56a: MOV DIL,byte ptr [RBP]
*((uint8_t*) &RDI) = *((uint8_t*) (RBP));

// 1337e56e: MOVZX RDI,DIL
RDI = (*((uint8_t*) &RDI)) & 0xFF;

// 1337e572: SHL RDI,0x30
RDI <<= 0x30;

// 1337e576: SUB qword ptr [R10 + 0x90],RDI
*((uint64_t*) (&RBX_old)) -= RDI;

// 1337e57d: MOV RDX,0x13cf315a8
RDX = 0x13cf315a8;

// 1337e587: PUSH RDX
RSP -= 8;
*(uint64_t*) (RSP) = RDX;

// 1337e588: PUSH 0x721a0b7b
RSP -= 8;
*(uint64_t*) (RSP) = 0x721a0b7b;

// 1337e58d: PUSH 0x3d5a5a05
RSP -= 8;
*(uint64_t*) (RSP) = 0x3d5a5a05;

// 1337e592: PUSH 0x421536cd
RSP -= 8;
*(uint64_t*) (RSP) = 0x421536cd;

// 1337e597: PUSH 0x725b76b0
RSP -= 8;
*(uint64_t*) (RSP) = 0x725b76b0;

// 1337e59c: ADD qword ptr [RSP + 0x20],0x3165518
*((uint64_t*) (RSP + 0x20)) += 0x3165518;

// 1337e5a5: MOV R10,qword ptr [R9 + 0x28]
// switch to context pointer R10

// 1337e5a9: MOV RSI,qword ptr [R10 + 0x90]
RSI = *((uint64_t*) (&RBX_old));

// 1337e5b0: JMP 0x1366c462

// 1366c462: JMP 0x1337e5fb

// 1337e5fb: HLT
// ----------------

// 0x00: PushMachframe 1
RSP = *(uint64_t*) (RSP + 0x20);

// 0x00: PushNonVol 12
R12 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack220[0x10000];
RSP = (uint64_t) &stack220[0x10000 - 8];


// 1337e6a0: MOV RDI,qword ptr [R9 + 0x28]
// switch to context pointer RDI

// 1337e6a4: LDMXCSR dword ptr [RDI + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 1337e6a8: MOV RBX,qword ptr [RDI + 0xd8]
RBX = *((uint64_t*) (&R12_old));

// 1337e6af: MOV R12,qword ptr [RDI + 0xa8]
R12 = *((uint64_t*) (&RSI_old));

// 1337e6b6: JMP 0x1366c59e

// 1366c59e: JMP 0x1337e706

// 1337e706: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack221[0x10000];
RSP = (uint64_t) &stack221[0x10000 - 8];


// 1337e790: MOV RBX,qword ptr [R9 + 0x28]
// switch to context pointer RBX

// 1337e794: MOV RSI,qword ptr [RBX + 0xd8]
RSI = *((uint64_t*) (&R12_old));

// 1337e79b: MOV R9D,dword ptr [RBX + 0x34]
*((uint32_t*) &R9) = *((uint32_t*) (&MXCSR_old));

// 1337e79f: ADD R9,qword ptr [RBX + 0x90]
R9 += *((uint64_t*) (&RBX_old));

// 1337e7a6: MOV BL,byte ptr [R9]
*((uint8_t*) &RBX) = *((uint8_t*) (R9));

// 1337e7a9: MOV RBP,0xff
RBP = 0xff;

// 1337e7b0: SHL RBP,0x28
RBP <<= 0x28;

// 1337e7b4: NOT RBP
RBP = ~RBP;

// 1337e7b7: AND RSI,RBP
RSI &= RBP;

// 1337e7ba: MOVZX RBP,BL
RBP = (*((uint8_t*) &RBX)) & 0xFF;

// 1337e7be: SHL RBP,0x28
RBP <<= 0x28;

// 1337e7c2: OR RSI,RBP
RSI |= RBP;

// 1337e7c5: JMP 0x1366c748

// 1366c748: JMP 0x1337e80c

// 1337e80c: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack222[0x10000];
RSP = (uint64_t) &stack222[0x10000 - 8];


// 1337e89d: MOV R11,0x1003190ab
R11 = 0x1003190ab;

// 1337e8a7: PUSH R11
RSP -= 8;
*(uint64_t*) (RSP) = R11;

// 1337e8a9: PUSH 0x4cd433bf
RSP -= 8;
*(uint64_t*) (RSP) = 0x4cd433bf;

// 1337e8ae: PUSH 0x7f3a7464
RSP -= 8;
*(uint64_t*) (RSP) = 0x7f3a7464;

// 1337e8b3: PUSH 0x5a50c54
RSP -= 8;
*(uint64_t*) (RSP) = 0x5a50c54;

// 1337e8b8: ADD qword ptr [RSP + 0x18],0x4058283d
*((uint64_t*) (RSP + 0x18)) += 0x4058283d;

// 1337e8c1: MOV RDX,qword ptr [R9 + 0x28]
// switch to context pointer RDX

// 1337e8c5: MOV R13,qword ptr [RDX + 0xa8]
R13 = *((uint64_t*) (&RSI_old));

// 1337e8cc: JMP 0x1366c8e8

// 1366c8e8: JMP 0x1337e91e

// 1337e91e: HLT
// ----------------

// 0x00: PushMachframe 0
RSP = *(uint64_t*) (RSP + 0x18);

// 0x00: AllocLarge 12
RSP += 12;

// 0x00: PushNonVol 7
RDI = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack223[0x10000];
RSP = (uint64_t) &stack223[0x10000 - 8];


// 1337e9be: MOV R13,qword ptr [R9 + 0x28]
// switch to context pointer R13

// 1337e9c2: MOV RSI,qword ptr [R13 + 0xb0]
RSI = *((uint64_t*) (&RDI_old));

// 1337e9c9: MOV R12,qword ptr [R13 + 0xe0]
R12 = *((uint64_t*) (&R13_old));

// 1337e9d0: MOVZX RSI,SIL
RSI = (*((uint8_t*) &RSI)) & 0xFF;

// 1337e9d4: JMP 0x1366ca29

// 1366ca29: JMP 0x1337ea28

// 1337ea28: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack224[0x10000];
RSP = (uint64_t) &stack224[0x10000 - 8];


// 1337eabb: MOV R8,qword ptr [R9 + 0x28]
// switch to context pointer R8

// 1337eabf: MOV RAX,qword ptr [R8 + 0xa8]
RAX = *((uint64_t*) (&RSI_old));

// 1337eac6: MOV RBX,-0x33c8da87
RBX = -0x33c8da87;

// 1337eacd: ADD RBX,0x344012d7
RBX += 0x344012d7;

// 1337ead4: PUSH RBX
RSP -= 8;
*(uint64_t*) (RSP) = RBX;

// 1337ead5: MOV R12,qword ptr [R8 + 0xd8]
R12 = *((uint64_t*) (&R12_old));

// 1337eadc: MUL qword ptr [RSP]
RAX *= *((uint64_t*) (RSP));

// 1337eae0: MOV R14,RAX
R14 = RAX;

// 1337eae3: JMP 0x1366cc39

// 1366cc39: JMP 0x1337eb30

// 1337eb30: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack225[0x10000];
RSP = (uint64_t) &stack225[0x10000 - 8];


// 1337ebc4: MOV R12,qword ptr [R9 + 0x28]
// switch to context pointer R12

// 1337ebc8: MOV RDI,qword ptr [R12 + 0xd8]
RDI = *((uint64_t*) (&R12_old));

// 1337ebd0: XOR RDI,qword ptr [R12 + 0xe8]
RDI ^= *((uint64_t*) (&R14_old));

// 1337ebd8: JMP 0x1366cd7c

// 1366cd7c: JMP 0x1337ec26

// 1337ec26: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack226[0x10000];
RSP = (uint64_t) &stack226[0x10000 - 8];


// 1337ecb0: MOV R11,qword ptr [R9 + 0x28]
// switch to context pointer R11

// 1337ecb4: MOV R14,qword ptr [R11 + 0xb0]
R14 = *((uint64_t*) (&RDI_old));

// 1337ecbb: PUSH R14
RSP -= 8;
*(uint64_t*) (RSP) = R14;

// 1337ecbd: MOV R12,RSP
R12 = RSP;

// 1337ecc0: MOV RBP,qword ptr [R11 + 0xb0]
RBP = *((uint64_t*) (&RDI_old));

// 1337ecc7: JMP 0x1366cebb

// 1366cebb: JMP 0x1337ed0e

// 1337ed0e: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack227[0x10000];
RSP = (uint64_t) &stack227[0x10000 - 8];


// 1337eda4: MOV RDI,qword ptr [R9 + 0x28]
// switch to context pointer RDI

// 1337eda8: MOV RBP,qword ptr [RDI + 0xd8]
RBP = *((uint64_t*) (&R12_old));

// 1337edaf: MOV R15,qword ptr [RDI + 0xa0]
R15 = *((uint64_t*) (&RBP_old));

// 1337edb6: PUSH RBP
RSP -= 8;
*(uint64_t*) (RSP) = RBP;

// 1337edb7: PUSH 0x7232422e
RSP -= 8;
*(uint64_t*) (RSP) = 0x7232422e;

// 1337edbc: PUSH 0x6f354c8d
RSP -= 8;
*(uint64_t*) (RSP) = 0x6f354c8d;

// 1337edc1: PUSH 0x7f855f40
RSP -= 8;
*(uint64_t*) (RSP) = 0x7f855f40;

// 1337edc6: JMP 0x1366cffc

// 1366cffc: JMP 0x1337ee19

// 1337ee19: HLT
// ----------------

// 0x00: PushMachframe 0
RSP = *(uint64_t*) (RSP + 0x18);

// 0x00: PushNonVol 2
RDX = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack228[0x10000];
RSP = (uint64_t) &stack228[0x10000 - 8];


// 1337eea3: MOV RAX,qword ptr [R9 + 0x28]
// switch to context pointer RAX

// 1337eea7: MOV R14,qword ptr [RAX + 0x88]
R14 = *((uint64_t*) (&RDX_old));

// 1337eeae: MOV R12,qword ptr [RAX + 0xf0]
R12 = *((uint64_t*) (&R15_old));

// 1337eeb5: MOVZX R14,R14B
R14 = (*((uint8_t*) &R14)) & 0xFF;

// 1337eeb9: JMP 0x1366d13b

// 1366d13b: JMP 0x1337ef0a

// 1337ef0a: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack229[0x10000];
RSP = (uint64_t) &stack229[0x10000 - 8];


// 1337efa9: MOV R14,qword ptr [R9 + 0x28]
// switch to context pointer R14

// 1337efad: LDMXCSR dword ptr [R14 + 0xe8]
MXCSR = *((uint32_t*) (&R14_old));

// 1337efb5: MOV R14,qword ptr [R9 + 0x28]
// switch to context pointer R14

// 1337efb9: MOV R14,qword ptr [R14 + 0xd8]
R14 = *((uint64_t*) (&R12_old));

// 1337efc0: MOV RDI,0xee51e968
RDI = 0xee51e968;

// 1337efca: ADD RDI,0x51b76158
RDI += 0x51b76158;

// 1337efd1: JMP 0x1366d348

// 1366d348: JMP 0x1337f014

// 1337f014: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = RDI - 0;

// 0x00: AllocLarge 1520
RSP += 1520;

// 0x00: PushNonVol 8
R8 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack230[0x10000];
RSP = (uint64_t) &stack230[0x10000 - 8];


// 1337f0ad: MOV RAX,qword ptr [R9 + 0x28]
// switch to context pointer RAX

// 1337f0b1: LDMXCSR dword ptr [RAX + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 1337f0b5: MOV RBP,qword ptr [RAX + 0xb8]
RBP = *((uint64_t*) (&R8_old));

// 1337f0bc: MOV R12,qword ptr [RAX + 0xe8]
R12 = *((uint64_t*) (&R14_old));

// 1337f0c3: JMP 0x1366d482

// 1366d482: JMP 0x1337f117

// 1337f117: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack231[0x10000];
RSP = (uint64_t) &stack231[0x10000 - 8];


// 1337f1a2: MOV RAX,qword ptr [R9 + 0x28]
// switch to context pointer RAX

// 1337f1a6: MOV R12,qword ptr [RAX + 0xd8]
R12 = *((uint64_t*) (&R12_old));

// 1337f1ad: MOV ECX,dword ptr [RAX + 0x34]
*((uint32_t*) &RCX) = *((uint32_t*) (&MXCSR_old));

// 1337f1b0: ADD RCX,qword ptr [RAX + 0xa0]
RCX += *((uint64_t*) (&RBP_old));

// 1337f1b7: MOV DL,byte ptr [RCX]
*((uint8_t*) &RDX) = *((uint8_t*) (RCX));

// 1337f1b9: MOV R12B,DL
*((uint8_t*) &R12) = *((uint8_t*) &RDX);

// 1337f1bc: JMP 0x1366d5bb

// 1366d5bb: JMP 0x1337f209

// 1337f209: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack232[0x10000];
RSP = (uint64_t) &stack232[0x10000 - 8];


// 1337f2a0: MOV R11,qword ptr [R9 + 0x28]
// switch to context pointer R11

// 1337f2a4: MOV R14,qword ptr [R11 + 0xd8]
R14 = *((uint64_t*) (&R12_old));

// 1337f2ab: PUSH R14
RSP -= 8;
*(uint64_t*) (RSP) = R14;

// 1337f2ad: MOV R13,RSP
R13 = RSP;

// 1337f2b0: MOV R15,qword ptr [R11 + 0xd8]
R15 = *((uint64_t*) (&R12_old));

// 1337f2b7: JMP 0x1366d6fa

// 1366d6fa: JMP 0x1337f306

// 1337f306: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = R13 - 0;

// 0x00: AllocLarge 1
RSP += 1;

// 0x00: PushNonVol 8
R8 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack233[0x10000];
RSP = (uint64_t) &stack233[0x10000 - 8];


// 1337f3ab: MOV R8,qword ptr [R9 + 0x28]
// switch to context pointer R8

// 1337f3af: MOV R14,qword ptr [R8 + 0xb8]
R14 = *((uint64_t*) (&R8_old));

// 1337f3b6: MOV RDI,qword ptr [R8 + 0xf0]
RDI = *((uint64_t*) (&R15_old));

// 1337f3bd: MOVZX R14,R14B
R14 = (*((uint8_t*) &R14)) & 0xFF;

// 1337f3c1: JMP 0x1366d838

// 1366d838: JMP 0x1337f40e

// 1337f40e: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack234[0x10000];
RSP = (uint64_t) &stack234[0x10000 - 8];


// 1337f4a3: MOV R13,qword ptr [R9 + 0x28]
// switch to context pointer R13

// 1337f4a7: LDMXCSR dword ptr [R13 + 0xe8]
MXCSR = *((uint32_t*) (&R14_old));

// 1337f4af: MOV R10,qword ptr [R9 + 0x28]
// switch to context pointer R10

// 1337f4b3: MOV R15,qword ptr [R10 + 0xb0]
R15 = *((uint64_t*) (&RDI_old));

// 1337f4ba: MOV R13,0x11d79e929
R13 = 0x11d79e929;

// 1337f4c4: ADD R13,0x228f6197
R13 += 0x228f6197;

// 1337f4cb: JMP 0x1366da56

// 1366da56: JMP 0x1337f517

// 1337f517: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = R13 - 0;

// 0x00: AllocLarge 832
RSP += 832;

// 0x00: PushNonVol 8
R8 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack235[0x10000];
RSP = (uint64_t) &stack235[0x10000 - 8];


// 1337f5b6: MOV R14,qword ptr [R9 + 0x28]
// switch to context pointer R14

// 1337f5ba: LDMXCSR dword ptr [R14 + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 1337f5bf: MOV R15,qword ptr [R14 + 0xb8]
R15 = *((uint64_t*) (&R8_old));

// 1337f5c6: MOV RBP,qword ptr [R14 + 0xf0]
RBP = *((uint64_t*) (&R15_old));

// 1337f5cd: JMP 0x1366db95

// 1366db95: JMP 0x1337f610

// 1337f610: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack236[0x10000];
RSP = (uint64_t) &stack236[0x10000 - 8];


// 1337f6b3: MOV RDX,qword ptr [R9 + 0x28]
// switch to context pointer RDX

// 1337f6b7: MOV RDI,qword ptr [RDX + 0xa0]
RDI = *((uint64_t*) (&RBP_old));

// 1337f6be: MOV R10D,dword ptr [RDX + 0x34]
*((uint32_t*) &R10) = *((uint32_t*) (&MXCSR_old));

// 1337f6c2: ADD R10,qword ptr [RDX + 0xf0]
R10 += *((uint64_t*) (&R15_old));

// 1337f6c9: MOV SIL,byte ptr [R10]
*((uint8_t*) &RSI) = *((uint8_t*) (R10));

// 1337f6cc: MOV R11,0xff
R11 = 0xff;

// 1337f6d3: SHL R11,0x8
R11 <<= 0x8;

// 1337f6d7: NOT R11
R11 = ~R11;

// 1337f6da: AND RDI,R11
RDI &= R11;

// 1337f6dd: MOVZX R11,SIL
R11 = (*((uint8_t*) &RSI)) & 0xFF;

// 1337f6e1: SHL R11,0x8
R11 <<= 0x8;

// 1337f6e5: OR RDI,R11
RDI |= R11;

// 1337f6e8: JMP 0x1366dd40

// 1366dd40: JMP 0x1337f735

// 1337f735: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack237[0x10000];
RSP = (uint64_t) &stack237[0x10000 - 8];


// 1337f7c9: MOV RBP,qword ptr [R9 + 0x28]
// switch to context pointer RBP

// 1337f7cd: MOV RAX,qword ptr [RBP + 0xb0]
RAX = *((uint64_t*) (&RDI_old));

// 1337f7d4: PUSH RAX
RSP -= 8;
*(uint64_t*) (RSP) = RAX;

// 1337f7d5: MOV R15,RSP
R15 = RSP;

// 1337f7d8: MOV R14,qword ptr [RBP + 0xb0]
R14 = *((uint64_t*) (&RDI_old));

// 1337f7df: JMP 0x1366de6f

// 1366de6f: JMP 0x1337f824

// 1337f824: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack238[0x10000];
RSP = (uint64_t) &stack238[0x10000 - 8];


// 1337f8c2: MOV R8,qword ptr [R9 + 0x28]
// switch to context pointer R8

// 1337f8c6: MOV RBX,qword ptr [R8 + 0xf0]
RBX = *((uint64_t*) (&R15_old));

// 1337f8cd: MOV RBP,qword ptr [R8 + 0xe8]
RBP = *((uint64_t*) (&R14_old));

// 1337f8d4: PUSH RBX
RSP -= 8;
*(uint64_t*) (RSP) = RBX;

// 1337f8d5: PUSH 0x1e0b6973
RSP -= 8;
*(uint64_t*) (RSP) = 0x1e0b6973;

// 1337f8da: PUSH 0x470b57aa
RSP -= 8;
*(uint64_t*) (RSP) = 0x470b57aa;

// 1337f8df: PUSH 0x5777cde
RSP -= 8;
*(uint64_t*) (RSP) = 0x5777cde;

// 1337f8e4: JMP 0x1366dfb1

// 1366dfb1: JMP 0x1337f92e

// 1337f92e: HLT
// ----------------

// 0x00: PushMachframe 0
RSP = *(uint64_t*) (RSP + 0x18);

// 0x00: AllocLarge 2
RSP += 2;

// 0x00: PushNonVol 10
R10 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack239[0x10000];
RSP = (uint64_t) &stack239[0x10000 - 8];


// 1337f9d4: MOV RDI,qword ptr [R9 + 0x28]
// switch to context pointer RDI

// 1337f9d8: MOV RBX,qword ptr [RDI + 0xc8]
RBX = *((uint64_t*) (&R10_old));

// 1337f9df: MOV R13,qword ptr [RDI + 0xa0]
R13 = *((uint64_t*) (&RBP_old));

// 1337f9e6: MOVZX RBX,BL
RBX = (*((uint8_t*) &RBX)) & 0xFF;

// 1337f9ea: JMP 0x1366e0f1

// 1366e0f1: JMP 0x1337fa2f

// 1337fa2f: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack240[0x10000];
RSP = (uint64_t) &stack240[0x10000 - 8];


// 1337facf: MOV RDX,qword ptr [R9 + 0x28]
// switch to context pointer RDX

// 1337fad3: LDMXCSR dword ptr [RDX + 0x90]
MXCSR = *((uint32_t*) (&RBX_old));

// 1337fada: MOV RBX,0x12368cfce
RBX = 0x12368cfce;

// 1337fae4: PUSH RBX
RSP -= 8;
*(uint64_t*) (RSP) = RBX;

// 1337fae5: PUSH 0x4e2c1f87
RSP -= 8;
*(uint64_t*) (RSP) = 0x4e2c1f87;

// 1337faea: PUSH 0x50ce0e9f
RSP -= 8;
*(uint64_t*) (RSP) = 0x50ce0e9f;

// 1337faef: PUSH 0x23670599
RSP -= 8;
*(uint64_t*) (RSP) = 0x23670599;

// 1337faf4: PUSH 0x78e717b
RSP -= 8;
*(uint64_t*) (RSP) = 0x78e717b;

// 1337faf9: ADD qword ptr [RSP + 0x20],0x1ca07af2
*((uint64_t*) (RSP + 0x20)) += 0x1ca07af2;

// 1337fb02: MOV RDX,qword ptr [R9 + 0x28]
// switch to context pointer RDX

// 1337fb06: MOV RBX,qword ptr [RDX + 0xe0]
RBX = *((uint64_t*) (&R13_old));

// 1337fb0d: JMP 0x1366e30b

// 1366e30b: JMP 0x1337fb54

// 1337fb54: HLT
// ----------------

// 0x00: PushMachframe 1
RSP = *(uint64_t*) (RSP + 0x20);

// 0x00: AllocLarge 888
RSP += 888;

// 0x00: PushNonVol 10
R10 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack241[0x10000];
RSP = (uint64_t) &stack241[0x10000 - 8];


// 1337fbf8: MOV RBP,qword ptr [R9 + 0x28]
// switch to context pointer RBP

// 1337fbfc: LDMXCSR dword ptr [RBP + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 1337fc00: MOV RDI,qword ptr [RBP + 0xc8]
RDI = *((uint64_t*) (&R10_old));

// 1337fc07: MOV RBP,qword ptr [RBP + 0x90]
RBP = *((uint64_t*) (&RBX_old));

// 1337fc0e: JMP 0x1366e44f

// 1366e44f: JMP 0x1337fc59

// 1337fc59: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack242[0x10000];
RSP = (uint64_t) &stack242[0x10000 - 8];


// 1337fcf4: MOV R10,qword ptr [R9 + 0x28]
// switch to context pointer R10

// 1337fcf8: MOV RDI,qword ptr [R10 + 0xa0]
RDI = *((uint64_t*) (&RBP_old));

// 1337fcff: MOV R15D,dword ptr [R10 + 0x34]
*((uint32_t*) &R15) = *((uint32_t*) (&MXCSR_old));

// 1337fd03: ADD R15,qword ptr [R10 + 0xb0]
R15 += *((uint64_t*) (&RDI_old));

// 1337fd0a: MOV R9B,byte ptr [R15]
*((uint8_t*) &R9) = *((uint8_t*) (R15));

// 1337fd0d: MOV RBP,0xff
RBP = 0xff;

// 1337fd14: SHL RBP,0x10
RBP <<= 0x10;

// 1337fd18: NOT RBP
RBP = ~RBP;

// 1337fd1b: AND RDI,RBP
RDI &= RBP;

// 1337fd1e: MOVZX RBP,R9B
RBP = (*((uint8_t*) &R9)) & 0xFF;

// 1337fd22: SHL RBP,0x10
RBP <<= 0x10;

// 1337fd26: OR RDI,RBP
RDI |= RBP;

// 1337fd29: JMP 0x1366e5ef

// 1366e5ef: JMP 0x1337fd6d

// 1337fd6d: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack243[0x10000];
RSP = (uint64_t) &stack243[0x10000 - 8];


// 1337fe02: MOV R12,qword ptr [R9 + 0x28]
// switch to context pointer R12

// 1337fe06: MOV RDI,qword ptr [R12 + 0xb0]
RDI = *((uint64_t*) (&RDI_old));

// 1337fe0e: PUSH RDI
RSP -= 8;
*(uint64_t*) (RSP) = RDI;

// 1337fe0f: MOV R14,RSP
R14 = RSP;

// 1337fe12: MOV RDI,qword ptr [R12 + 0xb0]
RDI = *((uint64_t*) (&RDI_old));

// 1337fe1a: JMP 0x1366e724

// 1366e724: JMP 0x1337fe68

// 1337fe68: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack244[0x10000];
RSP = (uint64_t) &stack244[0x10000 - 8];


// 1337ff04: MOV R9,qword ptr [R9 + 0x28]
// switch to context pointer R9

// 1337ff08: MOV RDI,qword ptr [R9 + 0xe8]
RDI = *((uint64_t*) (&R14_old));

// 1337ff0f: MOV R15,qword ptr [R9 + 0xb0]
R15 = *((uint64_t*) (&RDI_old));

// 1337ff16: PUSH RDI
RSP -= 8;
*(uint64_t*) (RSP) = RDI;

// 1337ff17: PUSH 0x251b7c31
RSP -= 8;
*(uint64_t*) (RSP) = 0x251b7c31;

// 1337ff1c: PUSH 0xfef7b09
RSP -= 8;
*(uint64_t*) (RSP) = 0xfef7b09;

// 1337ff21: PUSH 0x7231331a
RSP -= 8;
*(uint64_t*) (RSP) = 0x7231331a;

// 1337ff26: PUSH 0x689e620d
RSP -= 8;
*(uint64_t*) (RSP) = 0x689e620d;

// 1337ff2b: JMP 0x1366e85f

// 1366e85f: JMP 0x1337ff76

// 1337ff76: HLT
// ----------------

// 0x00: PushMachframe 1
RSP = *(uint64_t*) (RSP + 0x20);

// 0x00: AllocLarge 3
RSP += 3;

// 0x00: PushNonVol 6
RSI = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack245[0x10000];
RSP = (uint64_t) &stack245[0x10000 - 8];


// 1338000a: MOV R12,qword ptr [R9 + 0x28]
// switch to context pointer R12

// 1338000e: MOV R13,qword ptr [R12 + 0xa8]
R13 = *((uint64_t*) (&RSI_old));

// 13380016: MOV R15,qword ptr [R12 + 0xf0]
R15 = *((uint64_t*) (&R15_old));

// 1338001e: MOVZX R13,R13B
R13 = (*((uint8_t*) &R13)) & 0xFF;

// 13380022: JMP 0x1366e9a2

// 1366e9a2: JMP 0x1338006c

// 1338006c: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack246[0x10000];
RSP = (uint64_t) &stack246[0x10000 - 8];


// 13380100: MOV RDX,qword ptr [R9 + 0x28]
// switch to context pointer RDX

// 13380104: LDMXCSR dword ptr [RDX + 0xe0]
MXCSR = *((uint32_t*) (&R13_old));

// 1338010b: MOV R10,qword ptr [R9 + 0x28]
// switch to context pointer R10

// 1338010f: MOV RSI,qword ptr [R10 + 0xf0]
RSI = *((uint64_t*) (&R15_old));

// 13380116: MOV RBX,0xf40acb51
RBX = 0xf40acb51;

// 13380120: ADD RBX,0x4bfe7f6f
RBX += 0x4bfe7f6f;

// 13380127: JMP 0x1366ebb3

// 1366ebb3: JMP 0x1338016d

// 1338016d: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = RBX - 0;

// 0x00: AllocLarge 720
RSP += 720;

// 0x00: PushNonVol 11
R11 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack247[0x10000];
RSP = (uint64_t) &stack247[0x10000 - 8];


// 13380205: MOV R14,qword ptr [R9 + 0x28]
// switch to context pointer R14

// 13380209: LDMXCSR dword ptr [R14 + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 1338020e: MOV RDI,qword ptr [R14 + 0xd0]
RDI = *((uint64_t*) (&R11_old));

// 13380215: MOV R14,qword ptr [R14 + 0xa8]
R14 = *((uint64_t*) (&RSI_old));

// 1338021c: JMP 0x1366ecfb

// 1366ecfb: JMP 0x13380263

// 13380263: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack248[0x10000];
RSP = (uint64_t) &stack248[0x10000 - 8];


// 133802ef: MOV R13,qword ptr [R9 + 0x28]
// switch to context pointer R13

// 133802f3: MOV RSI,qword ptr [R13 + 0xe8]
RSI = *((uint64_t*) (&R14_old));

// 133802fa: MOV R9D,dword ptr [R13 + 0x34]
*((uint32_t*) &R9) = *((uint32_t*) (&MXCSR_old));

// 133802fe: ADD R9,qword ptr [R13 + 0xb0]
R9 += *((uint64_t*) (&RDI_old));

// 13380305: MOV BL,byte ptr [R9]
*((uint8_t*) &RBX) = *((uint8_t*) (R9));

// 13380308: MOV RDI,0xff
RDI = 0xff;

// 1338030f: SHL RDI,0x18
RDI <<= 0x18;

// 13380313: NOT RDI
RDI = ~RDI;

// 13380316: AND RSI,RDI
RSI &= RDI;

// 13380319: MOVZX RDI,BL
RDI = (*((uint8_t*) &RBX)) & 0xFF;

// 1338031d: SHL RDI,0x18
RDI <<= 0x18;

// 13380321: OR RSI,RDI
RSI |= RDI;

// 13380324: JMP 0x1366eea5

// 1366eea5: JMP 0x13380376

// 13380376: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack249[0x10000];
RSP = (uint64_t) &stack249[0x10000 - 8];


// 13380411: MOV R15,qword ptr [R9 + 0x28]
// switch to context pointer R15

// 13380415: MOV RBP,qword ptr [R15 + 0xa8]
RBP = *((uint64_t*) (&RSI_old));

// 1338041c: PUSH RBP
RSP -= 8;
*(uint64_t*) (RSP) = RBP;

// 1338041d: MOV RDI,RSP
RDI = RSP;

// 13380420: MOV R12,qword ptr [R15 + 0xa8]
R12 = *((uint64_t*) (&RSI_old));

// 13380427: JMP 0x1366efdc

// 1366efdc: JMP 0x1338046d

// 1338046d: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = RDI - 0;

// 0x00: AllocLarge 4
RSP += 4;

// 0x00: PushNonVol 7
RDI = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack250[0x10000];
RSP = (uint64_t) &stack250[0x10000 - 8];


// 13380506: MOV RDX,qword ptr [R9 + 0x28]
// switch to context pointer RDX

// 1338050a: MOV R13,qword ptr [RDX + 0xb0]
R13 = *((uint64_t*) (&RDI_old));

// 13380511: MOV R14,qword ptr [RDX + 0xd8]
R14 = *((uint64_t*) (&R12_old));

// 13380518: MOVZX R13,R13B
R13 = (*((uint8_t*) &R13)) & 0xFF;

// 1338051c: JMP 0x1366f111

// 1366f111: JMP 0x13380561

// 13380561: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack251[0x10000];
RSP = (uint64_t) &stack251[0x10000 - 8];


// 133805f3: MOV R12,qword ptr [R9 + 0x28]
// switch to context pointer R12

// 133805f7: LDMXCSR dword ptr [R12 + 0xe0]
MXCSR = *((uint32_t*) (&R13_old));

// 13380600: MOV RBP,qword ptr [R9 + 0x28]
// switch to context pointer RBP

// 13380604: MOV R12,qword ptr [RBP + 0xe8]
R12 = *((uint64_t*) (&R14_old));

// 1338060b: MOV RDI,0xd59ed561
RDI = 0xd59ed561;

// 13380615: ADD RDI,0x6a6a755f
RDI += 0x6a6a755f;

// 1338061c: JMP 0x1366f323

// 1366f323: JMP 0x13380667

// 13380667: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = RDI - 0;

// 0x00: PushNonVol 2
RDX = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack252[0x10000];
RSP = (uint64_t) &stack252[0x10000 - 8];


// 133806fb: MOV R8,qword ptr [R9 + 0x28]
// switch to context pointer R8

// 133806ff: LDMXCSR dword ptr [R8 + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 13380704: MOV RBX,qword ptr [R8 + 0x88]
RBX = *((uint64_t*) (&RDX_old));

// 1338070b: MOV R12,qword ptr [R8 + 0xd8]
R12 = *((uint64_t*) (&R12_old));

// 13380712: JMP 0x1366f465

// 1366f465: JMP 0x13380760

// 13380760: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack253[0x10000];
RSP = (uint64_t) &stack253[0x10000 - 8];


// 13380801: MOV R11,qword ptr [R9 + 0x28]
// switch to context pointer R11

// 13380805: MOV RBP,qword ptr [R11 + 0xd8]
RBP = *((uint64_t*) (&R12_old));

// 1338080c: MOV R15D,dword ptr [R11 + 0x34]
*((uint32_t*) &R15) = *((uint32_t*) (&MXCSR_old));

// 13380810: ADD R15,qword ptr [R11 + 0x90]
R15 += *((uint64_t*) (&RBX_old));

// 13380817: MOV R10B,byte ptr [R15]
*((uint8_t*) &R10) = *((uint8_t*) (R15));

// 1338081a: MOV RSI,0xff
RSI = 0xff;

// 13380821: SHL RSI,0x20
RSI <<= 0x20;

// 13380825: NOT RSI
RSI = ~RSI;

// 13380828: AND RBP,RSI
RBP &= RSI;

// 1338082b: MOVZX RSI,R10B
RSI = (*((uint8_t*) &R10)) & 0xFF;

// 1338082f: SHL RSI,0x20
RSI <<= 0x20;

// 13380833: OR RBP,RSI
RBP |= RSI;

// 13380836: JMP 0x1366f601

// 1366f601: JMP 0x13380888

// 13380888: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack254[0x10000];
RSP = (uint64_t) &stack254[0x10000 - 8];


// 1338092f: MOV R12,qword ptr [R9 + 0x28]
// switch to context pointer R12

// 13380933: MOV R15,qword ptr [R12 + 0xa0]
R15 = *((uint64_t*) (&RBP_old));

// 1338093b: PUSH R15
RSP -= 8;
*(uint64_t*) (RSP) = R15;

// 1338093d: MOV R15,RSP
R15 = RSP;

// 13380940: MOV RSI,qword ptr [R12 + 0xa0]
RSI = *((uint64_t*) (&RBP_old));

// 13380948: JMP 0x1366f73f

// 1366f73f: JMP 0x13380999

// 13380999: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack255[0x10000];
RSP = (uint64_t) &stack255[0x10000 - 8];


// 13380a2e: MOV R13,qword ptr [R9 + 0x28]
// switch to context pointer R13

// 13380a32: MOV R8,qword ptr [R13 + 0xf0]
R8 = *((uint64_t*) (&R15_old));

// 13380a39: MOV RBP,qword ptr [R13 + 0xa8]
RBP = *((uint64_t*) (&RSI_old));

// 13380a40: PUSH R8
RSP -= 8;
*(uint64_t*) (RSP) = R8;

// 13380a42: PUSH 0x7fda2456
RSP -= 8;
*(uint64_t*) (RSP) = 0x7fda2456;

// 13380a47: PUSH 0x38a474f4
RSP -= 8;
*(uint64_t*) (RSP) = 0x38a474f4;

// 13380a4c: PUSH 0xa3316c8
RSP -= 8;
*(uint64_t*) (RSP) = 0xa3316c8;

// 13380a51: PUSH 0x2b0d30b5
RSP -= 8;
*(uint64_t*) (RSP) = 0x2b0d30b5;

// 13380a56: JMP 0x1366f87b

// 1366f87b: JMP 0x13380aa9

// 13380aa9: HLT
// ----------------

// 0x00: PushMachframe 1
RSP = *(uint64_t*) (RSP + 0x20);

// 0x00: AllocLarge 5
RSP += 5;

// 0x00: PushNonVol 9
R9 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack256[0x10000];
RSP = (uint64_t) &stack256[0x10000 - 8];


// 13380b48: MOV R14,qword ptr [R9 + 0x28]
// switch to context pointer R14

// 13380b4c: MOV R13,qword ptr [R14 + 0xc0]
R13 = *((uint64_t*) (&R9_old));

// 13380b53: MOV R14,qword ptr [R14 + 0xa0]
R14 = *((uint64_t*) (&RBP_old));

// 13380b5a: MOVZX R13,R13B
R13 = (*((uint8_t*) &R13)) & 0xFF;

// 13380b5e: JMP 0x1366f9bc

// 1366f9bc: JMP 0x13380ba5

// 13380ba5: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack257[0x10000];
RSP = (uint64_t) &stack257[0x10000 - 8];


// 13380c3b: MOV R11,qword ptr [R9 + 0x28]
// switch to context pointer R11

// 13380c3f: LDMXCSR dword ptr [R11 + 0xe0]
MXCSR = *((uint32_t*) (&R13_old));

// 13380c47: MOV R11,qword ptr [R9 + 0x28]
// switch to context pointer R11

// 13380c4b: MOV RSI,qword ptr [R11 + 0xe8]
RSI = *((uint64_t*) (&R14_old));

// 13380c52: MOV RDI,0xf561e1e5
RDI = 0xf561e1e5;

// 13380c5c: ADD RDI,0x4aa768db
RDI += 0x4aa768db;

// 13380c63: JMP 0x1366fbd7

// 1366fbd7: JMP 0x13380caf

// 13380caf: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = RDI - 0;

// 0x00: PushNonVol 1
RCX = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack258[0x10000];
RSP = (uint64_t) &stack258[0x10000 - 8];


// 13380d4d: MOV RBP,qword ptr [R9 + 0x28]
// switch to context pointer RBP

// 13380d51: LDMXCSR dword ptr [RBP + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 13380d55: MOV R13,qword ptr [RBP + 0x80]
R13 = *((uint64_t*) (&RCX_old));

// 13380d5c: MOV RBX,qword ptr [RBP + 0xa8]
RBX = *((uint64_t*) (&RSI_old));

// 13380d63: JMP 0x1366fd14

// 1366fd14: JMP 0x13380db7

// 13380db7: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack259[0x10000];
RSP = (uint64_t) &stack259[0x10000 - 8];


// 13380e49: MOV RDX,qword ptr [R9 + 0x28]
// switch to context pointer RDX

// 13380e4d: MOV RBX,qword ptr [RDX + 0x90]
RBX = *((uint64_t*) (&RBX_old));

// 13380e54: MOV R8D,dword ptr [RDX + 0x34]
*((uint32_t*) &R8) = *((uint32_t*) (&MXCSR_old));

// 13380e58: ADD R8,qword ptr [RDX + 0xe0]
R8 += *((uint64_t*) (&R13_old));

// 13380e5f: MOV R15B,byte ptr [R8]
*((uint8_t*) &R15) = *((uint8_t*) (R8));

// 13380e62: MOV RBP,0xff
RBP = 0xff;

// 13380e69: SHL RBP,0x28
RBP <<= 0x28;

// 13380e6d: NOT RBP
RBP = ~RBP;

// 13380e70: AND RBX,RBP
RBX &= RBP;

// 13380e73: MOVZX RBP,R15B
RBP = (*((uint8_t*) &R15)) & 0xFF;

// 13380e77: SHL RBP,0x28
RBP <<= 0x28;

// 13380e7b: OR RBX,RBP
RBX |= RBP;

// 13380e7e: JMP 0x1366fec3

// 1366fec3: JMP 0x13380ece

// 13380ece: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack260[0x10000];
RSP = (uint64_t) &stack260[0x10000 - 8];


// 13380f59: MOV RSI,qword ptr [R9 + 0x28]
// switch to context pointer RSI

// 13380f5d: MOV RCX,qword ptr [RSI + 0x90]
RCX = *((uint64_t*) (&RBX_old));

// 13380f64: PUSH RCX
RSP -= 8;
*(uint64_t*) (RSP) = RCX;

// 13380f65: MOV R14,RSP
R14 = RSP;

// 13380f68: MOV R13,qword ptr [RSI + 0x90]
R13 = *((uint64_t*) (&RBX_old));

// 13380f6f: JMP 0x1366fffe

// 1366fffe: JMP 0x13380fb9

// 13380fb9: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = R14 - 0;

// 0x00: AllocLarge 6
RSP += 6;

// 0x00: PushNonVol 10
R10 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack261[0x10000];
RSP = (uint64_t) &stack261[0x10000 - 8];


// 13381064: MOV RBP,qword ptr [R9 + 0x28]
// switch to context pointer RBP

// 13381068: MOV RSI,qword ptr [RBP + 0xc8]
RSI = *((uint64_t*) (&R10_old));

// 1338106f: MOV RDI,qword ptr [RBP + 0xe0]
RDI = *((uint64_t*) (&R13_old));

// 13381076: MOVZX RSI,SIL
RSI = (*((uint8_t*) &RSI)) & 0xFF;

// 1338107a: JMP 0x13670135

// 13670135: JMP 0x133810bc

// 133810bc: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack262[0x10000];
RSP = (uint64_t) &stack262[0x10000 - 8];


// 13381159: MOV RSI,qword ptr [R9 + 0x28]
// switch to context pointer RSI

// 1338115d: LDMXCSR dword ptr [RSI + 0xa8]
MXCSR = *((uint32_t*) (&RSI_old));

// 13381164: MOV RCX,0xf37531bf
RCX = 0xf37531bf;

// 1338116e: PUSH RCX
RSP -= 8;
*(uint64_t*) (RSP) = RCX;

// 1338116f: PUSH 0x1df4514
RSP -= 8;
*(uint64_t*) (RSP) = 0x1df4514;

// 13381174: PUSH 0x6b7f78ce
RSP -= 8;
*(uint64_t*) (RSP) = 0x6b7f78ce;

// 13381179: PUSH 0x6e742ea5
RSP -= 8;
*(uint64_t*) (RSP) = 0x6e742ea5;

// 1338117e: ADD qword ptr [RSP + 0x18],0x4c941901
*((uint64_t*) (RSP + 0x18)) += 0x4c941901;

// 13381187: MOV R11,qword ptr [R9 + 0x28]
// switch to context pointer R11

// 1338118b: MOV RBX,qword ptr [R11 + 0xb0]
RBX = *((uint64_t*) (&RDI_old));

// 13381192: JMP 0x13670349

// 13670349: JMP 0x133811db

// 133811db: HLT
// ----------------

// 0x00: PushMachframe 0
RSP = *(uint64_t*) (RSP + 0x18);

// 0x00: PushNonVol 6
RSI = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack263[0x10000];
RSP = (uint64_t) &stack263[0x10000 - 8];


// 1338127e: MOV R14,qword ptr [R9 + 0x28]
// switch to context pointer R14

// 13381282: LDMXCSR dword ptr [R14 + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 13381287: MOV R12,qword ptr [R14 + 0xa8]
R12 = *((uint64_t*) (&RSI_old));

// 1338128e: MOV RDI,qword ptr [R14 + 0x90]
RDI = *((uint64_t*) (&RBX_old));

// 13381295: JMP 0x13670483

// 13670483: JMP 0x133812e8

// 133812e8: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack264[0x10000];
RSP = (uint64_t) &stack264[0x10000 - 8];


// 13381382: MOV RCX,qword ptr [R9 + 0x28]
// switch to context pointer RCX

// 13381386: MOV R12,qword ptr [RCX + 0xb0]
R12 = *((uint64_t*) (&RDI_old));

// 1338138d: MOV EDX,dword ptr [RCX + 0x34]
*((uint32_t*) &RDX) = *((uint32_t*) (&MXCSR_old));

// 13381390: ADD RDX,qword ptr [RCX + 0xd8]
RDX += *((uint64_t*) (&R12_old));

// 13381397: MOV R14B,byte ptr [RDX]
*((uint8_t*) &R14) = *((uint8_t*) (RDX));

// 1338139a: MOV R15,0xff
R15 = 0xff;

// 133813a1: SHL R15,0x30
R15 <<= 0x30;

// 133813a5: NOT R15
R15 = ~R15;

// 133813a8: AND R12,R15
R12 &= R15;

// 133813ab: MOVZX R15,R14B
R15 = (*((uint8_t*) &R14)) & 0xFF;

// 133813af: SHL R15,0x30
R15 <<= 0x30;

// 133813b3: OR R12,R15
R12 |= R15;

// 133813b6: JMP 0x13670628

// 13670628: JMP 0x133813fe

// 133813fe: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack265[0x10000];
RSP = (uint64_t) &stack265[0x10000 - 8];


// 1338149a: MOV RBP,qword ptr [R9 + 0x28]
// switch to context pointer RBP

// 1338149e: MOV R14,qword ptr [RBP + 0xd8]
R14 = *((uint64_t*) (&R12_old));

// 133814a5: MOV RBP,0xfa865a01
RBP = 0xfa865a01;

// 133814af: ADD RBP,0x46035ee7
RBP += 0x46035ee7;

// 133814b6: JMP 0x136707ca

// 136707ca: JMP 0x13381504

// 13381504: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = RBP - 0;

// 0x00: AllocLarge 28
RSP += 28;

// 0x00: PushNonVol 11
R11 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack266[0x10000];
RSP = (uint64_t) &stack266[0x10000 - 8];


// 133815a9: MOV RBX,qword ptr [R9 + 0x28]
// switch to context pointer RBX

// 133815ad: MOV R15,qword ptr [RBX + 0xd0]
R15 = *((uint64_t*) (&R11_old));

// 133815b4: MOV R13,qword ptr [RBX + 0xe8]
R13 = *((uint64_t*) (&R14_old));

// 133815bb: MOVZX R15,R15B
R15 = (*((uint8_t*) &R15)) & 0xFF;

// 133815bf: JMP 0x13670908

// 13670908: JMP 0x13381600

// 13381600: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack267[0x10000];
RSP = (uint64_t) &stack267[0x10000 - 8];


// 1338169f: MOV R10,qword ptr [R9 + 0x28]
// switch to context pointer R10

// 133816a3: MOV RAX,qword ptr [R10 + 0xf0]
RAX = *((uint64_t*) (&R15_old));

// 133816aa: MOV R13,-0xf7b55ad
R13 = -0xf7b55ad;

// 133816b1: ADD R13,0x105d72ea
R13 += 0x105d72ea;

// 133816b8: PUSH R13
RSP -= 8;
*(uint64_t*) (RSP) = R13;

// 133816ba: MOV RBP,qword ptr [R10 + 0xe0]
RBP = *((uint64_t*) (&R13_old));

// 133816c1: MUL qword ptr [RSP]
RAX *= *((uint64_t*) (RSP));

// 133816c5: MOV R12,RAX
R12 = RAX;

// 133816c8: JMP 0x13670b16

// 13670b16: JMP 0x13381716

// 13381716: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack268[0x10000];
RSP = (uint64_t) &stack268[0x10000 - 8];


// 133817b6: MOV RDI,qword ptr [R9 + 0x28]
// switch to context pointer RDI

// 133817ba: MOV R12,qword ptr [RDI + 0xa0]
R12 = *((uint64_t*) (&RBP_old));

// 133817c1: XOR R12,qword ptr [RDI + 0xd8]
R12 ^= *((uint64_t*) (&R12_old));

// 133817c8: JMP 0x13670c51

// 13670c51: JMP 0x13381815

// 13381815: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack269[0x10000];
RSP = (uint64_t) &stack269[0x10000 - 8];


// 133818a7: MOV RAX,qword ptr [R9 + 0x28]
// switch to context pointer RAX

// 133818ab: MOV RDI,qword ptr [RAX + 0xd8]
RDI = *((uint64_t*) (&R12_old));

// 133818b2: PUSH RDI
RSP -= 8;
*(uint64_t*) (RSP) = RDI;

// 133818b3: MOV RSI,RSP
RSI = RSP;

// 133818b6: MOV R12,qword ptr [RAX + 0xd8]
R12 = *((uint64_t*) (&R12_old));

// 133818bd: JMP 0x13670d92

// 13670d92: JMP 0x13381901

// 13381901: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack270[0x10000];
RSP = (uint64_t) &stack270[0x10000 - 8];


// 13381995: MOV R11,qword ptr [R9 + 0x28]
// switch to context pointer R11

// 13381999: MOV RDI,qword ptr [R11 + 0xa8]
RDI = *((uint64_t*) (&RSI_old));

// 133819a0: MOV RBX,qword ptr [R11 + 0xd8]
RBX = *((uint64_t*) (&R12_old));

// 133819a7: PUSH RDI
RSP -= 8;
*(uint64_t*) (RSP) = RDI;

// 133819a8: PUSH 0x726b2089
RSP -= 8;
*(uint64_t*) (RSP) = 0x726b2089;

// 133819ad: PUSH 0x94c3c24
RSP -= 8;
*(uint64_t*) (RSP) = 0x94c3c24;

// 133819b2: PUSH 0x5d87298e
RSP -= 8;
*(uint64_t*) (RSP) = 0x5d87298e;

// 133819b7: PUSH 0x50e62b31
RSP -= 8;
*(uint64_t*) (RSP) = 0x50e62b31;

// 133819bc: JMP 0x13670ec6

// 13670ec6: JMP 0x13381a0a

// 13381a0a: HLT
// ----------------

// 0x00: PushMachframe 1
RSP = *(uint64_t*) (RSP + 0x20);

// 0x00: PushNonVol 0
RAX = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack271[0x10000];
RSP = (uint64_t) &stack271[0x10000 - 8];


// 13381a92: MOV R13,qword ptr [R9 + 0x28]
// switch to context pointer R13

// 13381a96: MOV RBP,qword ptr [R13 + 0x78]
RBP = *((uint64_t*) (&RAX_old));

// 13381a9a: MOV RSI,qword ptr [R13 + 0x90]
RSI = *((uint64_t*) (&RBX_old));

// 13381aa1: MOVZX RBP,BPL
RBP = (*((uint8_t*) &RBP)) & 0xFF;

// 13381aa5: JMP 0x13670f9e

// 13670f9e: JMP 0x13381af8

// 13381af8: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack272[0x10000];
RSP = (uint64_t) &stack272[0x10000 - 8];


// 13381b9a: MOV R15,qword ptr [R9 + 0x28]
// switch to context pointer R15

// 13381b9e: LDMXCSR dword ptr [R15 + 0xa0]
MXCSR = *((uint32_t*) (&RBP_old));

// 13381ba6: MOV R15,qword ptr [R9 + 0x28]
// switch to context pointer R15

// 13381baa: MOV R14,qword ptr [R15 + 0xa8]
R14 = *((uint64_t*) (&RSI_old));

// 13381bb1: MOV RBX,0x103582166
RBX = 0x103582166;

// 13381bbb: ADD RBX,0x3cb1295a
RBX += 0x3cb1295a;

// 13381bc2: JMP 0x136711af

// 136711af: JMP 0x13381c0e

// 13381c0e: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = RBX - 0;

// 0x00: AllocLarge 280
RSP += 280;

// 0x00: PushNonVol 9
R9 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack273[0x10000];
RSP = (uint64_t) &stack273[0x10000 - 8];


// 13381cb0: MOV RBX,qword ptr [R9 + 0x28]
// switch to context pointer RBX

// 13381cb4: LDMXCSR dword ptr [RBX + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 13381cb8: MOV R15,qword ptr [RBX + 0xc0]
R15 = *((uint64_t*) (&R9_old));

// 13381cbf: MOV RSI,qword ptr [RBX + 0xe8]
RSI = *((uint64_t*) (&R14_old));

// 13381cc6: JMP 0x136712e2

// 136712e2: JMP 0x13381d11

// 13381d11: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack274[0x10000];
RSP = (uint64_t) &stack274[0x10000 - 8];


// 13381da1: MOV R12,qword ptr [R9 + 0x28]
// switch to context pointer R12

// 13381da5: MOV R14,qword ptr [R12 + 0xa8]
R14 = *((uint64_t*) (&RSI_old));

// 13381dad: MOV R8D,dword ptr [R12 + 0x34]
*((uint32_t*) &R8) = *((uint32_t*) (&MXCSR_old));

// 13381db2: ADD R8,qword ptr [R12 + 0xf0]
R8 += *((uint64_t*) (&R15_old));

// 13381dba: MOV DIL,byte ptr [R8]
*((uint8_t*) &RDI) = *((uint8_t*) (R8));

// 13381dbd: MOV R14B,DIL
*((uint8_t*) &R14) = *((uint8_t*) &RDI);

// 13381dc0: JMP 0x13671420

// 13671420: JMP 0x13381e07

// 13381e07: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack275[0x10000];
RSP = (uint64_t) &stack275[0x10000 - 8];


// 13381e9e: MOV R10,qword ptr [R9 + 0x28]
// switch to context pointer R10

// 13381ea2: MOV R12,qword ptr [R10 + 0xe8]
R12 = *((uint64_t*) (&R14_old));

// 13381ea9: PUSH R12
RSP -= 8;
*(uint64_t*) (RSP) = R12;

// 13381eab: MOV RSI,RSP
RSI = RSP;

// 13381eae: MOV R15,qword ptr [R10 + 0xe8]
R15 = *((uint64_t*) (&R14_old));

// 13381eb5: JMP 0x13671560

// 13671560: JMP 0x13381ef8

// 13381ef8: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = RSI - 0;

// 0x00: AllocLarge 1
RSP += 1;

// 0x00: PushNonVol 14
R14 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack276[0x10000];
RSP = (uint64_t) &stack276[0x10000 - 8];


// 13381f8a: MOV R13,qword ptr [R9 + 0x28]
// switch to context pointer R13

// 13381f8e: MOV RBX,qword ptr [R13 + 0xe8]
RBX = *((uint64_t*) (&R14_old));

// 13381f95: MOV R14,qword ptr [R13 + 0xf0]
R14 = *((uint64_t*) (&R15_old));

// 13381f9c: MOVZX RBX,BL
RBX = (*((uint8_t*) &RBX)) & 0xFF;

// 13381fa0: JMP 0x13671692

// 13671692: JMP 0x13381fe4

// 13381fe4: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack277[0x10000];
RSP = (uint64_t) &stack277[0x10000 - 8];


// 13382075: MOV R14,qword ptr [R9 + 0x28]
// switch to context pointer R14

// 13382079: LDMXCSR dword ptr [R14 + 0x90]
MXCSR = *((uint32_t*) (&RBX_old));

// 13382081: MOV R15,0xc9eceb05
R15 = 0xc9eceb05;

// 1338208b: PUSH R15
RSP -= 8;
*(uint64_t*) (RSP) = R15;

// 1338208d: PUSH 0x4ff3564c
RSP -= 8;
*(uint64_t*) (RSP) = 0x4ff3564c;

// 13382092: PUSH 0x578d47ca
RSP -= 8;
*(uint64_t*) (RSP) = 0x578d47ca;

// 13382097: PUSH 0x7bc51160
RSP -= 8;
*(uint64_t*) (RSP) = 0x7bc51160;

// 1338209c: ADD qword ptr [RSP + 0x18],0x761c5fbb
*((uint64_t*) (RSP + 0x18)) += 0x761c5fbb;

// 133820a5: MOV RCX,qword ptr [R9 + 0x28]
// switch to context pointer RCX

// 133820a9: MOV RBP,qword ptr [RCX + 0xe8]
RBP = *((uint64_t*) (&R14_old));

// 133820b0: JMP 0x136718af

// 136718af: JMP 0x13382102

// 13382102: HLT
// ----------------

// 0x00: PushMachframe 0
RSP = *(uint64_t*) (RSP + 0x18);

// 0x00: AllocLarge 232
RSP += 232;

// 0x00: PushNonVol 13
R13 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack278[0x10000];
RSP = (uint64_t) &stack278[0x10000 - 8];


// 133821a0: MOV R10,qword ptr [R9 + 0x28]
// switch to context pointer R10

// 133821a4: LDMXCSR dword ptr [R10 + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 133821a9: MOV R15,qword ptr [R10 + 0xe0]
R15 = *((uint64_t*) (&R13_old));

// 133821b0: MOV RBP,qword ptr [R10 + 0xa0]
RBP = *((uint64_t*) (&RBP_old));

// 133821b7: JMP 0x136719e6

// 136719e6: JMP 0x13382203

// 13382203: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack279[0x10000];
RSP = (uint64_t) &stack279[0x10000 - 8];


// 13382295: MOV R14,qword ptr [R9 + 0x28]
// switch to context pointer R14

// 13382299: MOV RBX,qword ptr [R14 + 0xa0]
RBX = *((uint64_t*) (&RBP_old));

// 133822a0: MOV EDI,dword ptr [R14 + 0x34]
*((uint32_t*) &RDI) = *((uint32_t*) (&MXCSR_old));

// 133822a4: ADD RDI,qword ptr [R14 + 0xf0]
RDI += *((uint64_t*) (&R15_old));

// 133822ab: MOV DIL,byte ptr [RDI]
*((uint8_t*) &RDI) = *((uint8_t*) (RDI));

// 133822ae: MOV R14,0xff
R14 = 0xff;

// 133822b5: SHL R14,0x8
R14 <<= 0x8;

// 133822b9: NOT R14
R14 = ~R14;

// 133822bc: AND RBX,R14
RBX &= R14;

// 133822bf: MOVZX R14,DIL
R14 = (*((uint8_t*) &RDI)) & 0xFF;

// 133822c3: SHL R14,0x8
R14 <<= 0x8;

// 133822c7: OR RBX,R14
RBX |= R14;

// 133822ca: JMP 0x13671b83

// 13671b83: JMP 0x1338230c

// 1338230c: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack280[0x10000];
RSP = (uint64_t) &stack280[0x10000 - 8];


// 1338239c: MOV RCX,qword ptr [R9 + 0x28]
// switch to context pointer RCX

// 133823a0: MOV R12,qword ptr [RCX + 0x90]
R12 = *((uint64_t*) (&RBX_old));

// 133823a7: PUSH R12
RSP -= 8;
*(uint64_t*) (RSP) = R12;

// 133823a9: MOV R14,RSP
R14 = RSP;

// 133823ac: MOV R13,qword ptr [RCX + 0x90]
R13 = *((uint64_t*) (&RBX_old));

// 133823b3: JMP 0x13671cbd

// 13671cbd: JMP 0x133823f6

// 133823f6: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack281[0x10000];
RSP = (uint64_t) &stack281[0x10000 - 8];


// 1338248b: MOV R14,qword ptr [R9 + 0x28]
// switch to context pointer R14

// 1338248f: MOV R9,qword ptr [R14 + 0xe8]
R9 = *((uint64_t*) (&R14_old));

// 13382496: MOV RBP,qword ptr [R14 + 0xe0]
RBP = *((uint64_t*) (&R13_old));

// 1338249d: PUSH R9
RSP -= 8;
*(uint64_t*) (RSP) = R9;

// 1338249f: PUSH 0x355222e3
RSP -= 8;
*(uint64_t*) (RSP) = 0x355222e3;

// 133824a4: PUSH 0x4c092c15
RSP -= 8;
*(uint64_t*) (RSP) = 0x4c092c15;

// 133824a9: PUSH 0x65d97425
RSP -= 8;
*(uint64_t*) (RSP) = 0x65d97425;

// 133824ae: JMP 0x13671df5

// 13671df5: JMP 0x133824fc

// 133824fc: HLT
// ----------------

// 0x00: PushMachframe 0
RSP = *(uint64_t*) (RSP + 0x18);

// 0x00: AllocLarge 2
RSP += 2;

// 0x00: PushNonVol 13
R13 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack282[0x10000];
RSP = (uint64_t) &stack282[0x10000 - 8];


// 13382594: MOV R14,qword ptr [R9 + 0x28]
// switch to context pointer R14

// 13382598: MOV RDI,qword ptr [R14 + 0xe0]
RDI = *((uint64_t*) (&R13_old));

// 1338259f: MOV R14,qword ptr [R14 + 0xa0]
R14 = *((uint64_t*) (&RBP_old));

// 133825a6: MOVZX RDI,DIL
RDI = (*((uint8_t*) &RDI)) & 0xFF;

// 133825aa: JMP 0x13671f2b

// 13671f2b: JMP 0x133825fb

// 133825fb: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack283[0x10000];
RSP = (uint64_t) &stack283[0x10000 - 8];


// 1338268c: MOV R8,qword ptr [R9 + 0x28]
// switch to context pointer R8

// 13382690: LDMXCSR dword ptr [R8 + 0xb0]
MXCSR = *((uint32_t*) (&RDI_old));

// 13382698: MOV R12,qword ptr [R9 + 0x28]
// switch to context pointer R12

// 1338269c: MOV R12,qword ptr [R12 + 0xe8]
R12 = *((uint64_t*) (&R14_old));

// 133826a4: MOV RSI,0x1215941af
RSI = 0x1215941af;

// 133826ae: ADD RSI,0x1eb00911
RSI += 0x1eb00911;

// 133826b5: JMP 0x13672146

// 13672146: JMP 0x133826ff

// 133826ff: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = RSI - 0;

// 0x00: AllocLarge 1160
RSP += 1160;

// 0x00: PushNonVol 14
R14 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack284[0x10000];
RSP = (uint64_t) &stack284[0x10000 - 8];


// 13382793: MOV RDX,qword ptr [R9 + 0x28]
// switch to context pointer RDX

// 13382797: LDMXCSR dword ptr [RDX + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 1338279b: MOV R12,qword ptr [RDX + 0xe8]
R12 = *((uint64_t*) (&R14_old));

// 133827a2: MOV RBP,qword ptr [RDX + 0xd8]
RBP = *((uint64_t*) (&R12_old));

// 133827a9: JMP 0x13672282

// 13672282: JMP 0x133827ec

// 133827ec: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack285[0x10000];
RSP = (uint64_t) &stack285[0x10000 - 8];


// 13382890: MOV R11,qword ptr [R9 + 0x28]
// switch to context pointer R11

// 13382894: MOV RBX,qword ptr [R11 + 0xa0]
RBX = *((uint64_t*) (&RBP_old));

// 1338289b: MOV EDX,dword ptr [R11 + 0x34]
*((uint32_t*) &RDX) = *((uint32_t*) (&MXCSR_old));

// 1338289f: ADD RDX,qword ptr [R11 + 0xd8]
RDX += *((uint64_t*) (&R12_old));

// 133828a6: MOV DIL,byte ptr [RDX]
*((uint8_t*) &RDI) = *((uint8_t*) (RDX));

// 133828a9: MOV R11,0xff
R11 = 0xff;

// 133828b0: SHL R11,0x10
R11 <<= 0x10;

// 133828b4: NOT R11
R11 = ~R11;

// 133828b7: AND RBX,R11
RBX &= R11;

// 133828ba: MOVZX R11,DIL
R11 = (*((uint8_t*) &RDI)) & 0xFF;

// 133828be: SHL R11,0x10
R11 <<= 0x10;

// 133828c2: OR RBX,R11
RBX |= R11;

// 133828c5: JMP 0x13672421

// 13672421: JMP 0x1338290b

// 1338290b: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack286[0x10000];
RSP = (uint64_t) &stack286[0x10000 - 8];


// 1338299b: MOV RDX,qword ptr [R9 + 0x28]
// switch to context pointer RDX

// 1338299f: MOV RBP,qword ptr [RDX + 0x90]
RBP = *((uint64_t*) (&RBX_old));

// 133829a6: PUSH RBP
RSP -= 8;
*(uint64_t*) (RSP) = RBP;

// 133829a7: MOV R13,RSP
R13 = RSP;

// 133829aa: MOV R15,qword ptr [RDX + 0x90]
R15 = *((uint64_t*) (&RBX_old));

// 133829b1: JMP 0x13672559

// 13672559: JMP 0x13382a05

// 13382a05: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = R13 - 0;

// 0x00: AllocLarge 3
RSP += 3;

// 0x00: PushNonVol 8
R8 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack287[0x10000];
RSP = (uint64_t) &stack287[0x10000 - 8];


// 13382a9d: MOV R9,qword ptr [R9 + 0x28]
// switch to context pointer R9

// 13382aa1: MOV R12,qword ptr [R9 + 0xb8]
R12 = *((uint64_t*) (&R8_old));

// 13382aa8: MOV RBP,qword ptr [R9 + 0xf0]
RBP = *((uint64_t*) (&R15_old));

// 13382aaf: MOVZX R12,R12B
R12 = (*((uint8_t*) &R12)) & 0xFF;

// 13382ab3: JMP 0x13672694

// 13672694: JMP 0x13382af4

// 13382af4: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack288[0x10000];
RSP = (uint64_t) &stack288[0x10000 - 8];


// 13382b84: MOV R10,qword ptr [R9 + 0x28]
// switch to context pointer R10

// 13382b88: LDMXCSR dword ptr [R10 + 0xd8]
MXCSR = *((uint32_t*) (&R12_old));

// 13382b90: MOV RBX,qword ptr [R9 + 0x28]
// switch to context pointer RBX

// 13382b94: MOV R14,qword ptr [RBX + 0xa0]
R14 = *((uint64_t*) (&RBP_old));

// 13382b9b: MOV RDI,0xfaf425e9
RDI = 0xfaf425e9;

// 13382ba5: ADD RDI,0x451524d7
RDI += 0x451524d7;

// 13382bac: JMP 0x136728aa

// 136728aa: JMP 0x13382bf7

// 13382bf7: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = RDI - 0;

// 0x00: AllocLarge 736
RSP += 736;

// 0x00: PushNonVol 5
RBP = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack289[0x10000];
RSP = (uint64_t) &stack289[0x10000 - 8];


// 13382c8d: MOV R9,qword ptr [R9 + 0x28]
// switch to context pointer R9

// 13382c91: LDMXCSR dword ptr [R9 + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 13382c96: MOV RSI,qword ptr [R9 + 0xa0]
RSI = *((uint64_t*) (&RBP_old));

// 13382c9d: MOV RBP,qword ptr [R9 + 0xe8]
RBP = *((uint64_t*) (&R14_old));

// 13382ca4: JMP 0x136729ed

// 136729ed: JMP 0x13382cea

// 13382cea: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack290[0x10000];
RSP = (uint64_t) &stack290[0x10000 - 8];


// 13382d83: MOV R15,qword ptr [R9 + 0x28]
// switch to context pointer R15

// 13382d87: MOV R14,qword ptr [R15 + 0xa0]
R14 = *((uint64_t*) (&RBP_old));

// 13382d8e: MOV R12D,dword ptr [R15 + 0x34]
*((uint32_t*) &R12) = *((uint32_t*) (&MXCSR_old));

// 13382d92: ADD R12,qword ptr [R15 + 0xa8]
R12 += *((uint64_t*) (&RSI_old));

// 13382d99: MOV R10B,byte ptr [R12]
*((uint8_t*) &R10) = *((uint8_t*) (R12));

// 13382d9d: MOV RDI,0xff
RDI = 0xff;

// 13382da4: SHL RDI,0x18
RDI <<= 0x18;

// 13382da8: NOT RDI
RDI = ~RDI;

// 13382dab: AND R14,RDI
R14 &= RDI;

// 13382dae: MOVZX RDI,R10B
RDI = (*((uint8_t*) &R10)) & 0xFF;

// 13382db2: SHL RDI,0x18
RDI <<= 0x18;

// 13382db6: OR R14,RDI
R14 |= RDI;

// 13382db9: JMP 0x13672b92

// 13672b92: JMP 0x13382e08

// 13382e08: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack291[0x10000];
RSP = (uint64_t) &stack291[0x10000 - 8];


// 13382ea6: MOV R12,qword ptr [R9 + 0x28]
// switch to context pointer R12

// 13382eaa: MOV R10,qword ptr [R12 + 0xe8]
R10 = *((uint64_t*) (&R14_old));

// 13382eb2: PUSH R10
RSP -= 8;
*(uint64_t*) (RSP) = R10;

// 13382eb4: MOV RBX,RSP
RBX = RSP;

// 13382eb7: MOV RDI,qword ptr [R12 + 0xe8]
RDI = *((uint64_t*) (&R14_old));

// 13382ebf: JMP 0x13672cd6

// 13672cd6: JMP 0x13382f05

// 13382f05: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = RBX - 0;

// 0x00: AllocLarge 4
RSP += 4;

// 0x00: PushNonVol 11
R11 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack292[0x10000];
RSP = (uint64_t) &stack292[0x10000 - 8];


// 13382fa7: MOV R11,qword ptr [R9 + 0x28]
// switch to context pointer R11

// 13382fab: MOV RSI,qword ptr [R11 + 0xd0]
RSI = *((uint64_t*) (&R11_old));

// 13382fb2: MOV R15,qword ptr [R11 + 0xb0]
R15 = *((uint64_t*) (&RDI_old));

// 13382fb9: MOVZX RSI,SIL
RSI = (*((uint8_t*) &RSI)) & 0xFF;

// 13382fbd: JMP 0x13672e0b

// 13672e0b: JMP 0x13382fff

// 13382fff: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack293[0x10000];
RSP = (uint64_t) &stack293[0x10000 - 8];


// 13383092: MOV R12,qword ptr [R9 + 0x28]
// switch to context pointer R12

// 13383096: LDMXCSR dword ptr [R12 + 0xa8]
MXCSR = *((uint32_t*) (&RSI_old));

// 1338309f: MOV RBP,0x131b2ef8d
RBP = 0x131b2ef8d;

// 133830a9: PUSH RBP
RSP -= 8;
*(uint64_t*) (RSP) = RBP;

// 133830aa: PUSH 0x65780a9a
RSP -= 8;
*(uint64_t*) (RSP) = 0x65780a9a;

// 133830af: PUSH 0x23073cd
RSP -= 8;
*(uint64_t*) (RSP) = 0x23073cd;

// 133830b4: PUSH 0x9b02853
RSP -= 8;
*(uint64_t*) (RSP) = 0x9b02853;

// 133830b9: PUSH 0xf4732f0
RSP -= 8;
*(uint64_t*) (RSP) = 0xf4732f0;

// 133830be: ADD qword ptr [RSP + 0x20],0xe565b33
*((uint64_t*) (RSP + 0x20)) += 0xe565b33;

// 133830c7: MOV R14,qword ptr [R9 + 0x28]
// switch to context pointer R14

// 133830cb: MOV R12,qword ptr [R14 + 0xf0]
R12 = *((uint64_t*) (&R15_old));

// 133830d2: JMP 0x1367301b

// 1367301b: JMP 0x13383126

// 13383126: HLT
// ----------------

// 0x00: PushMachframe 1
RSP = *(uint64_t*) (RSP + 0x20);

// 0x00: PushNonVol 10
R10 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack294[0x10000];
RSP = (uint64_t) &stack294[0x10000 - 8];


// 133831bb: MOV R13,qword ptr [R9 + 0x28]
// switch to context pointer R13

// 133831bf: LDMXCSR dword ptr [R13 + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 133831c4: MOV R12,qword ptr [R13 + 0xc8]
R12 = *((uint64_t*) (&R10_old));

// 133831cb: MOV R14,qword ptr [R13 + 0xd8]
R14 = *((uint64_t*) (&R12_old));

// 133831d2: JMP 0x1367315c

// 1367315c: JMP 0x1338321f

// 1338321f: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack295[0x10000];
RSP = (uint64_t) &stack295[0x10000 - 8];


// 133832bd: MOV RBP,qword ptr [R9 + 0x28]
// switch to context pointer RBP

// 133832c1: MOV R14,qword ptr [RBP + 0xe8]
R14 = *((uint64_t*) (&R14_old));

// 133832c8: MOV R12D,dword ptr [RBP + 0x34]
*((uint32_t*) &R12) = *((uint32_t*) (&MXCSR_old));

// 133832cc: ADD R12,qword ptr [RBP + 0xd8]
R12 += *((uint64_t*) (&R12_old));

// 133832d3: MOV R11B,byte ptr [R12]
*((uint8_t*) &R11) = *((uint8_t*) (R12));

// 133832d7: MOV RSI,0xff
RSI = 0xff;

// 133832de: SHL RSI,0x20
RSI <<= 0x20;

// 133832e2: NOT RSI
RSI = ~RSI;

// 133832e5: AND R14,RSI
R14 &= RSI;

// 133832e8: MOVZX RSI,R11B
RSI = (*((uint8_t*) &R11)) & 0xFF;

// 133832ec: SHL RSI,0x20
RSI <<= 0x20;

// 133832f0: OR R14,RSI
R14 |= RSI;

// 133832f3: JMP 0x136732fb

// 136732fb: JMP 0x13383339

// 13383339: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack296[0x10000];
RSP = (uint64_t) &stack296[0x10000 - 8];


// 133833d0: MOV R8,qword ptr [R9 + 0x28]
// switch to context pointer R8

// 133833d4: MOV R10,qword ptr [R8 + 0xe8]
R10 = *((uint64_t*) (&R14_old));

// 133833db: PUSH R10
RSP -= 8;
*(uint64_t*) (RSP) = R10;

// 133833dd: MOV RBX,RSP
RBX = RSP;

// 133833e0: MOV R12,qword ptr [R8 + 0xe8]
R12 = *((uint64_t*) (&R14_old));

// 133833e7: JMP 0x13673438

// 13673438: JMP 0x13383428

// 13383428: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack297[0x10000];
RSP = (uint64_t) &stack297[0x10000 - 8];


// 133834bb: MOV R10,qword ptr [R9 + 0x28]
// switch to context pointer R10

// 133834bf: MOV R9,qword ptr [R10 + 0x90]
R9 = *((uint64_t*) (&RBX_old));

// 133834c6: MOV RBX,qword ptr [R10 + 0xd8]
RBX = *((uint64_t*) (&R12_old));

// 133834cd: PUSH R9
RSP -= 8;
*(uint64_t*) (RSP) = R9;

// 133834cf: PUSH 0x6b716383
RSP -= 8;
*(uint64_t*) (RSP) = 0x6b716383;

// 133834d4: PUSH 0x56cf6315
RSP -= 8;
*(uint64_t*) (RSP) = 0x56cf6315;

// 133834d9: PUSH 0x737c10db
RSP -= 8;
*(uint64_t*) (RSP) = 0x737c10db;

// 133834de: PUSH 0x6d65093c
RSP -= 8;
*(uint64_t*) (RSP) = 0x6d65093c;

// 133834e3: JMP 0x13673579

// 13673579: JMP 0x13383526

// 13383526: HLT
// ----------------

// 0x00: PushMachframe 1
RSP = *(uint64_t*) (RSP + 0x20);

// 0x00: AllocLarge 5
RSP += 5;

// 0x00: PushNonVol 13
R13 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack298[0x10000];
RSP = (uint64_t) &stack298[0x10000 - 8];


// 133835bd: MOV R11,qword ptr [R9 + 0x28]
// switch to context pointer R11

// 133835c1: MOV R13,qword ptr [R11 + 0xe0]
R13 = *((uint64_t*) (&R13_old));

// 133835c8: MOV RBX,qword ptr [R11 + 0x90]
RBX = *((uint64_t*) (&RBX_old));

// 133835cf: MOVZX R13,R13B
R13 = (*((uint8_t*) &R13)) & 0xFF;

// 133835d3: JMP 0x136736b1

// 136736b1: JMP 0x13383621

// 13383621: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack299[0x10000];
RSP = (uint64_t) &stack299[0x10000 - 8];


// 133836b9: MOV RSI,qword ptr [R9 + 0x28]
// switch to context pointer RSI

// 133836bd: LDMXCSR dword ptr [RSI + 0xe0]
MXCSR = *((uint32_t*) (&R13_old));

// 133836c4: MOV R11,qword ptr [R9 + 0x28]
// switch to context pointer R11

// 133836c8: MOV RDI,qword ptr [R11 + 0x90]
RDI = *((uint64_t*) (&RBX_old));

// 133836cf: MOV RBP,0xea68eafa
RBP = 0xea68eafa;

// 133836d9: ADD RBP,0x55a05fc6
RBP += 0x55a05fc6;

// 133836e0: JMP 0x136738cb

// 136738cb: JMP 0x13383730

// 13383730: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = RBP - 0;

// 0x00: PushNonVol 5
RBP = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack300[0x10000];
RSP = (uint64_t) &stack300[0x10000 - 8];


// 133837d3: MOV RDI,qword ptr [R9 + 0x28]
// switch to context pointer RDI

// 133837d7: LDMXCSR dword ptr [RDI + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 133837db: MOV R14,qword ptr [RDI + 0xa0]
R14 = *((uint64_t*) (&RBP_old));

// 133837e2: MOV RBP,qword ptr [RDI + 0xb0]
RBP = *((uint64_t*) (&RDI_old));

// 133837e9: JMP 0x13673a06

// 13673a06: JMP 0x13383832

// 13383832: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack301[0x10000];
RSP = (uint64_t) &stack301[0x10000 - 8];


// 133838d0: MOV R14,qword ptr [R9 + 0x28]
// switch to context pointer R14

// 133838d4: MOV RDI,qword ptr [R14 + 0xa0]
RDI = *((uint64_t*) (&RBP_old));

// 133838db: MOV EDX,dword ptr [R14 + 0x34]
*((uint32_t*) &RDX) = *((uint32_t*) (&MXCSR_old));

// 133838df: ADD RDX,qword ptr [R14 + 0xe8]
RDX += *((uint64_t*) (&R14_old));

// 133838e6: MOV R14B,byte ptr [RDX]
*((uint8_t*) &R14) = *((uint8_t*) (RDX));

// 133838e9: MOV RBX,0xff
RBX = 0xff;

// 133838f0: SHL RBX,0x28
RBX <<= 0x28;

// 133838f4: NOT RBX
RBX = ~RBX;

// 133838f7: AND RDI,RBX
RDI &= RBX;

// 133838fa: MOVZX RBX,R14B
RBX = (*((uint8_t*) &R14)) & 0xFF;

// 133838fe: SHL RBX,0x28
RBX <<= 0x28;

// 13383902: OR RDI,RBX
RDI |= RBX;

// 13383905: JMP 0x13673ba8

// 13673ba8: JMP 0x1338394c

// 1338394c: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack302[0x10000];
RSP = (uint64_t) &stack302[0x10000 - 8];


// 133839de: MOV R14,qword ptr [R9 + 0x28]
// switch to context pointer R14

// 133839e2: MOV RBP,qword ptr [R14 + 0xb0]
RBP = *((uint64_t*) (&RDI_old));

// 133839e9: PUSH RBP
RSP -= 8;
*(uint64_t*) (RSP) = RBP;

// 133839ea: MOV R13,RSP
R13 = RSP;

// 133839ed: MOV R15,qword ptr [R14 + 0xb0]
R15 = *((uint64_t*) (&RDI_old));

// 133839f4: JMP 0x13673ce2

// 13673ce2: JMP 0x13383a38

// 13383a38: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = R13 - 0;

// 0x00: PushNonVol 5
RBP = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack303[0x10000];
RSP = (uint64_t) &stack303[0x10000 - 8];


// 13383ac7: MOV R15,qword ptr [R9 + 0x28]
// switch to context pointer R15

// 13383acb: MOV RBX,qword ptr [R15 + 0xa0]
RBX = *((uint64_t*) (&RBP_old));

// 13383ad2: MOV R15,qword ptr [R15 + 0xf0]
R15 = *((uint64_t*) (&R15_old));

// 13383ad9: MOVZX RBX,BL
RBX = (*((uint8_t*) &RBX)) & 0xFF;

// 13383add: JMP 0x13673e1f

// 13673e1f: JMP 0x13383b22

// 13383b22: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack304[0x10000];
RSP = (uint64_t) &stack304[0x10000 - 8];


// 13383bba: MOV RBP,qword ptr [R9 + 0x28]
// switch to context pointer RBP

// 13383bbe: LDMXCSR dword ptr [RBP + 0x90]
MXCSR = *((uint32_t*) (&RBX_old));

// 13383bc5: MOV RBX,0xc6bb648b
RBX = 0xc6bb648b;

// 13383bcf: ADD RBX,0x794e0e35
RBX += 0x794e0e35;

// 13383bd6: MOV RBX,qword ptr [RBX + 0x3c8]
RBX = *((uint64_t*) (RBX + 0x3c8));

// 13383bdd: ADD RBX,qword ptr [RBP + 0x90]
RBX += *((uint64_t*) (&RBX_old));

// 13383be4: MOV BL,byte ptr [RBX]
*((uint8_t*) &RBX) = *((uint8_t*) (RBX));

// 13383be6: MOVZX RBX,BL
RBX = (*((uint8_t*) &RBX)) & 0xFF;

// 13383bea: SHL RBX,0x8
RBX <<= 0x8;

// 13383bee: SUB qword ptr [RBP + 0xf0],RBX
*((uint64_t*) (&R15_old)) -= RBX;

// 13383bf5: MOV R14,0x113055d2c
R14 = 0x113055d2c;

// 13383bff: PUSH R14
RSP -= 8;
*(uint64_t*) (RSP) = R14;

// 13383c01: PUSH 0x7e9d3831
RSP -= 8;
*(uint64_t*) (RSP) = 0x7e9d3831;

// 13383c06: PUSH 0x66fd462b
RSP -= 8;
*(uint64_t*) (RSP) = 0x66fd462b;

// 13383c0b: PUSH 0x2aaf0643
RSP -= 8;
*(uint64_t*) (RSP) = 0x2aaf0643;

// 13383c10: ADD qword ptr [RSP + 0x18],0x2d040d94
*((uint64_t*) (RSP + 0x18)) += 0x2d040d94;

// 13383c19: MOV RDX,qword ptr [R9 + 0x28]
// switch to context pointer RDX

// 13383c1d: MOV R14,qword ptr [RDX + 0xf0]
R14 = *((uint64_t*) (&R15_old));

// 13383c24: JMP 0x1367424c

// 1367424c: JMP 0x13383c68

// 13383c68: HLT
// ----------------

// 0x00: PushMachframe 0
RSP = *(uint64_t*) (RSP + 0x18);

// 0x00: AllocLarge 968
RSP += 968;

// 0x00: PushNonVol 11
R11 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack305[0x10000];
RSP = (uint64_t) &stack305[0x10000 - 8];


// 13383d13: MOV RSI,qword ptr [R9 + 0x28]
// switch to context pointer RSI

// 13383d17: LDMXCSR dword ptr [RSI + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 13383d1b: MOV R14,qword ptr [RSI + 0xd0]
R14 = *((uint64_t*) (&R11_old));

// 13383d22: MOV R12,qword ptr [RSI + 0xe8]
R12 = *((uint64_t*) (&R14_old));

// 13383d29: JMP 0x1367437e

// 1367437e: JMP 0x13383d72

// 13383d72: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack306[0x10000];
RSP = (uint64_t) &stack306[0x10000 - 8];


// 13383e0a: MOV RAX,qword ptr [R9 + 0x28]
// switch to context pointer RAX

// 13383e0e: MOV R12,qword ptr [RAX + 0xd8]
R12 = *((uint64_t*) (&R12_old));

// 13383e15: MOV ECX,dword ptr [RAX + 0x34]
*((uint32_t*) &RCX) = *((uint32_t*) (&MXCSR_old));

// 13383e18: ADD RCX,qword ptr [RAX + 0xe8]
RCX += *((uint64_t*) (&R14_old));

// 13383e1f: MOV CL,byte ptr [RCX]
*((uint8_t*) &RCX) = *((uint8_t*) (RCX));

// 13383e21: MOV R12B,CL
*((uint8_t*) &R12) = *((uint8_t*) &RCX);

// 13383e24: JMP 0x136744bb

// 136744bb: JMP 0x13383e6f

// 13383e6f: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack307[0x10000];
RSP = (uint64_t) &stack307[0x10000 - 8];


// 13383eff: MOV RDI,qword ptr [R9 + 0x28]
// switch to context pointer RDI

// 13383f03: MOV R8,qword ptr [RDI + 0xd8]
R8 = *((uint64_t*) (&R12_old));

// 13383f0a: PUSH R8
RSP -= 8;
*(uint64_t*) (RSP) = R8;

// 13383f0c: MOV RBX,RSP
RBX = RSP;

// 13383f0f: MOV RSI,qword ptr [RDI + 0xd8]
RSI = *((uint64_t*) (&R12_old));

// 13383f16: JMP 0x136745fa

// 136745fa: JMP 0x13383f69

// 13383f69: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack308[0x10000];
RSP = (uint64_t) &stack308[0x10000 - 8];


// 13383ff6: MOV R10,qword ptr [R9 + 0x28]
// switch to context pointer R10

// 13383ffa: MOV RBX,qword ptr [R10 + 0x90]
RBX = *((uint64_t*) (&RBX_old));

// 13384001: MOV R15,qword ptr [R10 + 0xa8]
R15 = *((uint64_t*) (&RSI_old));

// 13384008: PUSH RBX
RSP -= 8;
*(uint64_t*) (RSP) = RBX;

// 13384009: PUSH 0x537d1443
RSP -= 8;
*(uint64_t*) (RSP) = 0x537d1443;

// 1338400e: PUSH 0x34e92aae
RSP -= 8;
*(uint64_t*) (RSP) = 0x34e92aae;

// 13384013: PUSH 0x79d33b80
RSP -= 8;
*(uint64_t*) (RSP) = 0x79d33b80;

// 13384018: JMP 0x1367472a

// 1367472a: JMP 0x13384059

// 13384059: HLT
// ----------------

// 0x00: PushMachframe 0
RSP = *(uint64_t*) (RSP + 0x18);

// 0x00: AllocLarge 1
RSP += 1;

// 0x00: PushNonVol 7
RDI = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack309[0x10000];
RSP = (uint64_t) &stack309[0x10000 - 8];


// 133840fd: MOV R14,qword ptr [R9 + 0x28]
// switch to context pointer R14

// 13384101: MOV RSI,qword ptr [R14 + 0xb0]
RSI = *((uint64_t*) (&RDI_old));

// 13384108: MOV R15,qword ptr [R14 + 0xf0]
R15 = *((uint64_t*) (&R15_old));

// 1338410f: MOVZX RSI,SIL
RSI = (*((uint8_t*) &RSI)) & 0xFF;

// 13384113: JMP 0x13674869

// 13674869: JMP 0x13384165

// 13384165: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack310[0x10000];
RSP = (uint64_t) &stack310[0x10000 - 8];


// 133841f6: MOV RBX,qword ptr [R9 + 0x28]
// switch to context pointer RBX

// 133841fa: LDMXCSR dword ptr [RBX + 0xa8]
MXCSR = *((uint32_t*) (&RSI_old));

// 13384201: MOV R13,0x11c025838
R13 = 0x11c025838;

// 1338420b: ADD R13,0x24071a88
R13 += 0x24071a88;

// 13384212: MOV R13,qword ptr [R13 + 0x3d0]
R13 = *((uint64_t*) (R13 + 0x3d0));

// 13384219: ADD R13,qword ptr [RBX + 0xa8]
R13 += *((uint64_t*) (&RSI_old));

// 13384220: MOV DIL,byte ptr [R13]
*((uint8_t*) &RDI) = *((uint8_t*) (R13));

// 13384224: MOVZX RDI,DIL
RDI = (*((uint8_t*) &RDI)) & 0xFF;

// 13384228: SHL RDI,0x10
RDI <<= 0x10;

// 1338422c: SUB qword ptr [RBX + 0xf0],RDI
*((uint64_t*) (&R15_old)) -= RDI;

// 13384233: MOV R10,0x126124b57
R10 = 0x126124b57;

// 1338423d: PUSH R10
RSP -= 8;
*(uint64_t*) (RSP) = R10;

// 1338423f: PUSH 0x54fa795a
RSP -= 8;
*(uint64_t*) (RSP) = 0x54fa795a;

// 13384244: PUSH 0x4045fee
RSP -= 8;
*(uint64_t*) (RSP) = 0x4045fee;

// 13384249: PUSH 0x12d2d9e
RSP -= 8;
*(uint64_t*) (RSP) = 0x12d2d9e;

// 1338424e: ADD qword ptr [RSP + 0x18],0x19f71f69
*((uint64_t*) (RSP + 0x18)) += 0x19f71f69;

// 13384257: MOV RSI,qword ptr [R9 + 0x28]
// switch to context pointer RSI

// 1338425b: MOV RBX,qword ptr [RSI + 0xf0]
RBX = *((uint64_t*) (&R15_old));

// 13384262: JMP 0x13674c91

// 13674c91: JMP 0x133842b0

// 133842b0: HLT
// ----------------

// 0x00: PushMachframe 0
RSP = *(uint64_t*) (RSP + 0x18);

// 0x00: AllocLarge 976
RSP += 976;

// 0x00: PushNonVol 9
R9 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack311[0x10000];
RSP = (uint64_t) &stack311[0x10000 - 8];


// 13384351: MOV RCX,qword ptr [R9 + 0x28]
// switch to context pointer RCX

// 13384355: LDMXCSR dword ptr [RCX + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 13384359: MOV RBX,qword ptr [RCX + 0xc0]
RBX = *((uint64_t*) (&R9_old));

// 13384360: MOV RBP,qword ptr [RCX + 0x90]
RBP = *((uint64_t*) (&RBX_old));

// 13384367: JMP 0x13674dd7

// 13674dd7: JMP 0x133843aa

// 133843aa: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack312[0x10000];
RSP = (uint64_t) &stack312[0x10000 - 8];


// 1338443d: MOV RAX,qword ptr [R9 + 0x28]
// switch to context pointer RAX

// 13384441: MOV RSI,qword ptr [RAX + 0xa0]
RSI = *((uint64_t*) (&RBP_old));

// 13384448: MOV R11D,dword ptr [RAX + 0x34]
*((uint32_t*) &R11) = *((uint32_t*) (&MXCSR_old));

// 1338444c: ADD R11,qword ptr [RAX + 0x90]
R11 += *((uint64_t*) (&RBX_old));

// 13384453: MOV R15B,byte ptr [R11]
*((uint8_t*) &R15) = *((uint8_t*) (R11));

// 13384456: MOV R8,0xff
R8 = 0xff;

// 1338445d: SHL R8,0x8
R8 <<= 0x8;

// 13384461: NOT R8
R8 = ~R8;

// 13384464: AND RSI,R8
RSI &= R8;

// 13384467: MOVZX R8,R15B
R8 = (*((uint8_t*) &R15)) & 0xFF;

// 1338446b: SHL R8,0x8
R8 <<= 0x8;

// 1338446f: OR RSI,R8
RSI |= R8;

// 13384472: JMP 0x13674f77

// 13674f77: JMP 0x133844b3

// 133844b3: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack313[0x10000];
RSP = (uint64_t) &stack313[0x10000 - 8];


// 1338454e: MOV R13,qword ptr [R9 + 0x28]
// switch to context pointer R13

// 13384552: MOV R11,qword ptr [R13 + 0xa8]
R11 = *((uint64_t*) (&RSI_old));

// 13384559: PUSH R11
RSP -= 8;
*(uint64_t*) (RSP) = R11;

// 1338455b: MOV RBX,RSP
RBX = RSP;

// 1338455e: MOV RDI,qword ptr [R13 + 0xa8]
RDI = *((uint64_t*) (&RSI_old));

// 13384565: JMP 0x136750b6

// 136750b6: JMP 0x133845aa

// 133845aa: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack314[0x10000];
RSP = (uint64_t) &stack314[0x10000 - 8];


// 13384641: MOV RCX,qword ptr [R9 + 0x28]
// switch to context pointer RCX

// 13384645: MOV RAX,qword ptr [RCX + 0x90]
RAX = *((uint64_t*) (&RBX_old));

// 1338464c: MOV R14,qword ptr [RCX + 0xb0]
R14 = *((uint64_t*) (&RDI_old));

// 13384653: PUSH RAX
RSP -= 8;
*(uint64_t*) (RSP) = RAX;

// 13384654: PUSH 0x63cc2bc3
RSP -= 8;
*(uint64_t*) (RSP) = 0x63cc2bc3;

// 13384659: PUSH 0x2c6010a8
RSP -= 8;
*(uint64_t*) (RSP) = 0x2c6010a8;

// 1338465e: PUSH 0x31aa4ec2
RSP -= 8;
*(uint64_t*) (RSP) = 0x31aa4ec2;

// 13384663: JMP 0x136751ef

// 136751ef: JMP 0x133846b0

// 133846b0: HLT
// ----------------

// 0x00: PushMachframe 0
RSP = *(uint64_t*) (RSP + 0x18);

// 0x00: AllocLarge 2
RSP += 2;

// 0x00: PushNonVol 12
R12 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack315[0x10000];
RSP = (uint64_t) &stack315[0x10000 - 8];


// 13384754: MOV RSI,qword ptr [R9 + 0x28]
// switch to context pointer RSI

// 13384758: MOV R12,qword ptr [RSI + 0xd8]
R12 = *((uint64_t*) (&R12_old));

// 1338475f: MOV RBP,qword ptr [RSI + 0xe8]
RBP = *((uint64_t*) (&R14_old));

// 13384766: MOVZX R12,R12B
R12 = (*((uint8_t*) &R12)) & 0xFF;

// 1338476a: JMP 0x13675334

// 13675334: JMP 0x133847b4

// 133847b4: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack316[0x10000];
RSP = (uint64_t) &stack316[0x10000 - 8];


// 1338484e: MOV RDX,qword ptr [R9 + 0x28]
// switch to context pointer RDX

// 13384852: LDMXCSR dword ptr [RDX + 0xd8]
MXCSR = *((uint32_t*) (&R12_old));

// 13384859: MOV R13,0xf2ad37d8
R13 = 0xf2ad37d8;

// 13384863: ADD R13,0x4d5c3ae8
R13 += 0x4d5c3ae8;

// 1338486a: MOV R13,qword ptr [R13 + 0x320]
R13 = *((uint64_t*) (R13 + 0x320));

// 13384871: ADD R13,qword ptr [RDX + 0xd8]
R13 += *((uint64_t*) (&R12_old));

// 13384878: MOV CL,byte ptr [R13]
*((uint8_t*) &RCX) = *((uint8_t*) (R13));

// 1338487c: MOVZX RCX,CL
RCX = (*((uint8_t*) &RCX)) & 0xFF;

// 13384880: SHL RCX,0x18
RCX <<= 0x18;

// 13384884: SUB qword ptr [RDX + 0xa0],RCX
*((uint64_t*) (&RBP_old)) -= RCX;

// 1338488b: MOV RDI,qword ptr [R9 + 0x28]
// switch to context pointer RDI

// 1338488f: MOV R14,qword ptr [RDI + 0xa0]
R14 = *((uint64_t*) (&RBP_old));

// 13384896: MOV R12,0xf37ffd0a
R12 = 0xf37ffd0a;

// 133848a0: ADD R12,0x4c896db6
R12 += 0x4c896db6;

// 133848a7: JMP 0x1367575e

// 1367575e: JMP 0x133848f2

// 133848f2: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = R12 - 0;

// 0x00: AllocLarge 800
RSP += 800;

// 0x00: PushNonVol 1
RCX = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack317[0x10000];
RSP = (uint64_t) &stack317[0x10000 - 8];


// 13384998: MOV R11,qword ptr [R9 + 0x28]
// switch to context pointer R11

// 1338499c: LDMXCSR dword ptr [R11 + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 133849a1: MOV RBX,qword ptr [R11 + 0x80]
RBX = *((uint64_t*) (&RCX_old));

// 133849a8: MOV RBP,qword ptr [R11 + 0xe8]
RBP = *((uint64_t*) (&R14_old));

// 133849af: JMP 0x13675890

// 13675890: JMP 0x133849fc

// 133849fc: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack318[0x10000];
RSP = (uint64_t) &stack318[0x10000 - 8];


// 13384a98: MOV R14,qword ptr [R9 + 0x28]
// switch to context pointer R14

// 13384a9c: MOV RBP,qword ptr [R14 + 0xa0]
RBP = *((uint64_t*) (&RBP_old));

// 13384aa3: MOV EDI,dword ptr [R14 + 0x34]
*((uint32_t*) &RDI) = *((uint32_t*) (&MXCSR_old));

// 13384aa7: ADD RDI,qword ptr [R14 + 0x90]
RDI += *((uint64_t*) (&RBX_old));

// 13384aae: MOV SIL,byte ptr [RDI]
*((uint8_t*) &RSI) = *((uint8_t*) (RDI));

// 13384ab1: MOV R15,0xff
R15 = 0xff;

// 13384ab8: SHL R15,0x10
R15 <<= 0x10;

// 13384abc: NOT R15
R15 = ~R15;

// 13384abf: AND RBP,R15
RBP &= R15;

// 13384ac2: MOVZX R15,SIL
R15 = (*((uint8_t*) &RSI)) & 0xFF;

// 13384ac6: SHL R15,0x10
R15 <<= 0x10;

// 13384aca: OR RBP,R15
RBP |= R15;

// 13384acd: JMP 0x13675a30

// 13675a30: JMP 0x13384b13

// 13384b13: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack319[0x10000];
RSP = (uint64_t) &stack319[0x10000 - 8];


// 13384ba8: MOV R12,qword ptr [R9 + 0x28]
// switch to context pointer R12

// 13384bac: MOV RAX,qword ptr [R12 + 0xa0]
RAX = *((uint64_t*) (&RBP_old));

// 13384bb4: PUSH RAX
RSP -= 8;
*(uint64_t*) (RSP) = RAX;

// 13384bb5: MOV R14,RSP
R14 = RSP;

// 13384bb8: MOV RBP,qword ptr [R12 + 0xa0]
RBP = *((uint64_t*) (&RBP_old));

// 13384bc0: JMP 0x13675b68

// 13675b68: JMP 0x13384c0c

// 13384c0c: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack320[0x10000];
RSP = (uint64_t) &stack320[0x10000 - 8];


// 13384ca9: MOV R14,qword ptr [R9 + 0x28]
// switch to context pointer R14

// 13384cad: MOV RBX,qword ptr [R14 + 0xe8]
RBX = *((uint64_t*) (&R14_old));

// 13384cb4: MOV RBP,qword ptr [R14 + 0xa0]
RBP = *((uint64_t*) (&RBP_old));

// 13384cbb: PUSH RBX
RSP -= 8;
*(uint64_t*) (RSP) = RBX;

// 13384cbc: PUSH 0x28a45e28
RSP -= 8;
*(uint64_t*) (RSP) = 0x28a45e28;

// 13384cc1: PUSH 0x31e67fa8
RSP -= 8;
*(uint64_t*) (RSP) = 0x31e67fa8;

// 13384cc6: PUSH 0x5d41253b
RSP -= 8;
*(uint64_t*) (RSP) = 0x5d41253b;

// 13384ccb: JMP 0x13675c9e

// 13675c9e: JMP 0x13384d11

// 13384d11: HLT
// ----------------

// 0x00: PushMachframe 0
RSP = *(uint64_t*) (RSP + 0x18);

// 0x00: AllocLarge 3
RSP += 3;

// 0x00: PushNonVol 2
RDX = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack321[0x10000];
RSP = (uint64_t) &stack321[0x10000 - 8];


// 13384da9: MOV R12,qword ptr [R9 + 0x28]
// switch to context pointer R12

// 13384dad: MOV RBP,qword ptr [R12 + 0x88]
RBP = *((uint64_t*) (&RDX_old));

// 13384db5: MOV R13,qword ptr [R12 + 0xa0]
R13 = *((uint64_t*) (&RBP_old));

// 13384dbd: MOVZX RBP,BPL
RBP = (*((uint8_t*) &RBP)) & 0xFF;

// 13384dc1: JMP 0x13675dd9

// 13675dd9: JMP 0x13384e05

// 13384e05: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack322[0x10000];
RSP = (uint64_t) &stack322[0x10000 - 8];


// 13384e8d: MOV RBP,qword ptr [R9 + 0x28]
// switch to context pointer RBP

// 13384e91: LDMXCSR dword ptr [RBP + 0xa0]
MXCSR = *((uint32_t*) (&RBP_old));

// 13384e98: MOV R10,0x12d99fe94
R10 = 0x12d99fe94;

// 13384ea2: ADD R10,0x126f742c
R10 += 0x126f742c;

// 13384ea9: MOV R10,qword ptr [R10 + 0x408]
R10 = *((uint64_t*) (R10 + 0x408));

// 13384eb0: ADD R10,qword ptr [RBP + 0xa0]
R10 += *((uint64_t*) (&RBP_old));

// 13384eb7: MOV R10B,byte ptr [R10]
*((uint8_t*) &R10) = *((uint8_t*) (R10));

// 13384eba: MOVZX R10,R10B
R10 = (*((uint8_t*) &R10)) & 0xFF;

// 13384ebe: SHL R10,0x20
R10 <<= 0x20;

// 13384ec2: SUB qword ptr [RBP + 0xe0],R10
*((uint64_t*) (&R13_old)) -= R10;

// 13384ec9: MOV RCX,qword ptr [R9 + 0x28]
// switch to context pointer RCX

// 13384ecd: MOV R15,qword ptr [RCX + 0xe0]
R15 = *((uint64_t*) (&R13_old));

// 13384ed4: MOV RBP,0xfe1a5468
RBP = 0xfe1a5468;

// 13384ede: ADD RBP,0x41ef1658
RBP += 0x41ef1658;

// 13384ee5: JMP 0x136761f5

// 136761f5: JMP 0x13384f2b

// 13384f2b: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = RBP - 0;

// 0x00: AllocLarge 1032
RSP += 1032;

// 0x00: PushNonVol 7
RDI = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack323[0x10000];
RSP = (uint64_t) &stack323[0x10000 - 8];


// 13384fd3: MOV RBP,qword ptr [R9 + 0x28]
// switch to context pointer RBP

// 13384fd7: LDMXCSR dword ptr [RBP + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 13384fdb: MOV R12,qword ptr [RBP + 0xb0]
R12 = *((uint64_t*) (&RDI_old));

// 13384fe2: MOV R13,qword ptr [RBP + 0xf0]
R13 = *((uint64_t*) (&R15_old));

// 13384fe9: JMP 0x1367632a

// 1367632a: JMP 0x13385039

// 13385039: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack324[0x10000];
RSP = (uint64_t) &stack324[0x10000 - 8];


// 133850d2: MOV R10,qword ptr [R9 + 0x28]
// switch to context pointer R10

// 133850d6: MOV RDI,qword ptr [R10 + 0xe0]
RDI = *((uint64_t*) (&R13_old));

// 133850dd: MOV EBP,dword ptr [R10 + 0x34]
*((uint32_t*) &RBP) = *((uint32_t*) (&MXCSR_old));

// 133850e1: ADD RBP,qword ptr [R10 + 0xd8]
RBP += *((uint64_t*) (&R12_old));

// 133850e8: MOV DL,byte ptr [RBP]
*((uint8_t*) &RDX) = *((uint8_t*) (RBP));

// 133850eb: MOV R11,0xff
R11 = 0xff;

// 133850f2: SHL R11,0x18
R11 <<= 0x18;

// 133850f6: NOT R11
R11 = ~R11;

// 133850f9: AND RDI,R11
RDI &= R11;

// 133850fc: MOVZX R11,DL
R11 = (*((uint8_t*) &RDX)) & 0xFF;

// 13385100: SHL R11,0x18
R11 <<= 0x18;

// 13385104: OR RDI,R11
RDI |= R11;

// 13385107: JMP 0x136764cc

// 136764cc: JMP 0x13385155

// 13385155: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack325[0x10000];
RSP = (uint64_t) &stack325[0x10000 - 8];


// 133851e4: MOV R10,qword ptr [R9 + 0x28]
// switch to context pointer R10

// 133851e8: MOV RAX,qword ptr [R10 + 0xb0]
RAX = *((uint64_t*) (&RDI_old));

// 133851ef: PUSH RAX
RSP -= 8;
*(uint64_t*) (RSP) = RAX;

// 133851f0: MOV RBX,RSP
RBX = RSP;

// 133851f3: MOV R14,qword ptr [R10 + 0xb0]
R14 = *((uint64_t*) (&RDI_old));

// 133851fa: JMP 0x13676606

// 13676606: JMP 0x1338524a

// 1338524a: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = RBX - 0;

// 0x00: AllocLarge 4
RSP += 4;

// 0x00: PushNonVol 9
R9 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack326[0x10000];
RSP = (uint64_t) &stack326[0x10000 - 8];


// 133852fe: MOV RAX,qword ptr [R9 + 0x28]
// switch to context pointer RAX

// 13385302: MOV RBP,qword ptr [RAX + 0xc0]
RBP = *((uint64_t*) (&R9_old));

// 13385309: MOV R12,qword ptr [RAX + 0xe8]
R12 = *((uint64_t*) (&R14_old));

// 13385310: MOVZX RBP,BPL
RBP = (*((uint8_t*) &RBP)) & 0xFF;

// 13385314: JMP 0x1367673b

// 1367673b: JMP 0x1338535a

// 1338535a: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack327[0x10000];
RSP = (uint64_t) &stack327[0x10000 - 8];


// 133853f1: MOV R8,qword ptr [R9 + 0x28]
// switch to context pointer R8

// 133853f5: LDMXCSR dword ptr [R8 + 0xa0]
MXCSR = *((uint32_t*) (&RBP_old));

// 133853fd: MOV RDX,0x13e65655e
RDX = 0x13e65655e;

// 13385407: ADD RDX,0x1a40d62
RDX += 0x1a40d62;

// 1338540e: MOV RDX,qword ptr [RDX + 0x7f8]
RDX = *((uint64_t*) (RDX + 0x7f8));

// 13385415: ADD RDX,qword ptr [R8 + 0xa0]
RDX += *((uint64_t*) (&RBP_old));

// 1338541c: MOV SIL,byte ptr [RDX]
*((uint8_t*) &RSI) = *((uint8_t*) (RDX));

// 1338541f: MOVZX RSI,SIL
RSI = (*((uint8_t*) &RSI)) & 0xFF;

// 13385423: SHL RSI,0x28
RSI <<= 0x28;

// 13385427: SUB qword ptr [R8 + 0xd8],RSI
*((uint64_t*) (&R12_old)) -= RSI;

// 1338542e: MOV RDI,0x129e044ca
RDI = 0x129e044ca;

// 13385438: PUSH RDI
RSP -= 8;
*(uint64_t*) (RSP) = RDI;

// 13385439: PUSH 0x48e8643d
RSP -= 8;
*(uint64_t*) (RSP) = 0x48e8643d;

// 1338543e: PUSH 0xae76d64
RSP -= 8;
*(uint64_t*) (RSP) = 0xae76d64;

// 13385443: PUSH 0x5aee4a29
RSP -= 8;
*(uint64_t*) (RSP) = 0x5aee4a29;

// 13385448: ADD qword ptr [RSP + 0x18],0x162925f6
*((uint64_t*) (RSP + 0x18)) += 0x162925f6;

// 13385451: MOV R14,qword ptr [R9 + 0x28]
// switch to context pointer R14

// 13385455: MOV RBX,qword ptr [R14 + 0xd8]
RBX = *((uint64_t*) (&R12_old));

// 1338545c: JMP 0x13676b60

// 13676b60: JMP 0x133854ae

// 133854ae: HLT
// ----------------

// 0x00: PushMachframe 0
RSP = *(uint64_t*) (RSP + 0x18);

// 0x00: AllocLarge 2040
RSP += 2040;

// 0x00: PushNonVol 6
RSI = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack328[0x10000];
RSP = (uint64_t) &stack328[0x10000 - 8];


// 1338554f: MOV R13,qword ptr [R9 + 0x28]
// switch to context pointer R13

// 13385553: LDMXCSR dword ptr [R13 + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 13385558: MOV RDI,qword ptr [R13 + 0xa8]
RDI = *((uint64_t*) (&RSI_old));

// 1338555f: MOV R15,qword ptr [R13 + 0x90]
R15 = *((uint64_t*) (&RBX_old));

// 13385566: JMP 0x13676c96

// 13676c96: JMP 0x133855b8

// 133855b8: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack329[0x10000];
RSP = (uint64_t) &stack329[0x10000 - 8];


// 13385656: MOV R10,qword ptr [R9 + 0x28]
// switch to context pointer R10

// 1338565a: MOV RSI,qword ptr [R10 + 0xf0]
RSI = *((uint64_t*) (&R15_old));

// 13385661: MOV R15D,dword ptr [R10 + 0x34]
*((uint32_t*) &R15) = *((uint32_t*) (&MXCSR_old));

// 13385665: ADD R15,qword ptr [R10 + 0xb0]
R15 += *((uint64_t*) (&RDI_old));

// 1338566c: MOV BPL,byte ptr [R15]
*((uint8_t*) &RBP) = *((uint8_t*) (R15));

// 1338566f: MOV RBX,0xff
RBX = 0xff;

// 13385676: SHL RBX,0x20
RBX <<= 0x20;

// 1338567a: NOT RBX
RBX = ~RBX;

// 1338567d: AND RSI,RBX
RSI &= RBX;

// 13385680: MOVZX RBX,BPL
RBX = (*((uint8_t*) &RBP)) & 0xFF;

// 13385684: SHL RBX,0x20
RBX <<= 0x20;

// 13385688: OR RSI,RBX
RSI |= RBX;

// 1338568b: JMP 0x13676e3a

// 13676e3a: JMP 0x133856ce

// 133856ce: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack330[0x10000];
RSP = (uint64_t) &stack330[0x10000 - 8];


// 13385767: MOV RBP,qword ptr [R9 + 0x28]
// switch to context pointer RBP

// 1338576b: MOV R8,qword ptr [RBP + 0xa8]
R8 = *((uint64_t*) (&RSI_old));

// 13385772: PUSH R8
RSP -= 8;
*(uint64_t*) (RSP) = R8;

// 13385774: MOV RDI,RSP
RDI = RSP;

// 13385777: MOV R13,qword ptr [RBP + 0xa8]
R13 = *((uint64_t*) (&RSI_old));

// 1338577e: JMP 0x13676f6e

// 13676f6e: JMP 0x133857ca

// 133857ca: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack331[0x10000];
RSP = (uint64_t) &stack331[0x10000 - 8];


// 13385861: MOV R14,qword ptr [R9 + 0x28]
// switch to context pointer R14

// 13385865: MOV RDI,qword ptr [R14 + 0xb0]
RDI = *((uint64_t*) (&RDI_old));

// 1338586c: MOV RSI,qword ptr [R14 + 0xe0]
RSI = *((uint64_t*) (&R13_old));

// 13385873: PUSH RDI
RSP -= 8;
*(uint64_t*) (RSP) = RDI;

// 13385874: PUSH 0x3f9d57cf
RSP -= 8;
*(uint64_t*) (RSP) = 0x3f9d57cf;

// 13385879: PUSH 0x22e94f71
RSP -= 8;
*(uint64_t*) (RSP) = 0x22e94f71;

// 1338587e: PUSH 0x548e5594
RSP -= 8;
*(uint64_t*) (RSP) = 0x548e5594;

// 13385883: JMP 0x136770a4

// 136770a4: JMP 0x133858cc

// 133858cc: HLT
// ----------------

// 0x00: PushMachframe 0
RSP = *(uint64_t*) (RSP + 0x18);

// 0x00: AllocLarge 5
RSP += 5;

// 0x00: PushNonVol 10
R10 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack332[0x10000];
RSP = (uint64_t) &stack332[0x10000 - 8];


// 1338595e: MOV R13,qword ptr [R9 + 0x28]
// switch to context pointer R13

// 13385962: MOV R14,qword ptr [R13 + 0xc8]
R14 = *((uint64_t*) (&R10_old));

// 13385969: MOV RBX,qword ptr [R13 + 0xa8]
RBX = *((uint64_t*) (&RSI_old));

// 13385970: MOVZX R14,R14B
R14 = (*((uint8_t*) &R14)) & 0xFF;

// 13385974: JMP 0x136771e7

// 136771e7: JMP 0x133859c5

// 133859c5: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack333[0x10000];
RSP = (uint64_t) &stack333[0x10000 - 8];


// 13385a5b: MOV RCX,qword ptr [R9 + 0x28]
// switch to context pointer RCX

// 13385a5f: LDMXCSR dword ptr [RCX + 0xe8]
MXCSR = *((uint32_t*) (&R14_old));

// 13385a66: MOV R13,0x1266c5ebb
R13 = 0x1266c5ebb;

// 13385a70: ADD R13,0x199d1405
R13 += 0x199d1405;

// 13385a77: MOV R13,qword ptr [R13 + 0x7f8]
R13 = *((uint64_t*) (R13 + 0x7f8));

// 13385a7e: ADD R13,qword ptr [RCX + 0xe8]
R13 += *((uint64_t*) (&R14_old));

// 13385a85: MOV AL,byte ptr [R13]
*((uint8_t*) &RAX) = *((uint8_t*) (R13));

// 13385a89: MOVZX RAX,AL
RAX = (*((uint8_t*) &RAX)) & 0xFF;

// 13385a8d: SHL RAX,0x30
RAX <<= 0x30;

// 13385a91: SUB qword ptr [RCX + 0x90],RAX
*((uint64_t*) (&RBX_old)) -= RAX;

// 13385a98: MOV R11,0xdc400c04
R11 = 0xdc400c04;

// 13385aa2: PUSH R11
RSP -= 8;
*(uint64_t*) (RSP) = R11;

// 13385aa4: PUSH 0x77314be7
RSP -= 8;
*(uint64_t*) (RSP) = 0x77314be7;

// 13385aa9: PUSH 0x741a2e14
RSP -= 8;
*(uint64_t*) (RSP) = 0x741a2e14;

// 13385aae: PUSH 0xef7632c
RSP -= 8;
*(uint64_t*) (RSP) = 0xef7632c;

// 13385ab3: ADD qword ptr [RSP + 0x18],0x63c95ebc
*((uint64_t*) (RSP + 0x18)) += 0x63c95ebc;

// 13385abc: MOV RCX,qword ptr [R9 + 0x28]
// switch to context pointer RCX

// 13385ac0: MOV RBX,qword ptr [RCX + 0x90]
RBX = *((uint64_t*) (&RBX_old));

// 13385ac7: JMP 0x13677624

// 13677624: JMP 0x13385b0b

// 13385b0b: HLT
// ----------------

// 0x00: PushMachframe 0
RSP = *(uint64_t*) (RSP + 0x18);

// 0x00: AllocLarge 2040
RSP += 2040;

// 0x00: PushNonVol 6
RSI = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack334[0x10000];
RSP = (uint64_t) &stack334[0x10000 - 8];


// 13385bac: MOV RCX,qword ptr [R9 + 0x28]
// switch to context pointer RCX

// 13385bb0: LDMXCSR dword ptr [RCX + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 13385bb4: MOV R13,qword ptr [RCX + 0xa8]
R13 = *((uint64_t*) (&RSI_old));

// 13385bbb: MOV R14,qword ptr [RCX + 0x90]
R14 = *((uint64_t*) (&RBX_old));

// 13385bc2: JMP 0x13677752

// 13677752: JMP 0x13385c05

// 13385c05: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack335[0x10000];
RSP = (uint64_t) &stack335[0x10000 - 8];


// 13385c93: MOV R11,qword ptr [R9 + 0x28]
// switch to context pointer R11

// 13385c97: MOV RBX,qword ptr [R11 + 0xe8]
RBX = *((uint64_t*) (&R14_old));

// 13385c9e: MOV EDI,dword ptr [R11 + 0x34]
*((uint32_t*) &RDI) = *((uint32_t*) (&MXCSR_old));

// 13385ca2: ADD RDI,qword ptr [R11 + 0xe0]
RDI += *((uint64_t*) (&R13_old));

// 13385ca9: MOV DIL,byte ptr [RDI]
*((uint8_t*) &RDI) = *((uint8_t*) (RDI));

// 13385cac: MOV R15,0xff
R15 = 0xff;

// 13385cb3: SHL R15,0x28
R15 <<= 0x28;

// 13385cb7: NOT R15
R15 = ~R15;

// 13385cba: AND RBX,R15
RBX &= R15;

// 13385cbd: MOVZX R15,DIL
R15 = (*((uint8_t*) &RDI)) & 0xFF;

// 13385cc1: SHL R15,0x28
R15 <<= 0x28;

// 13385cc5: OR RBX,R15
RBX |= R15;

// 13385cc8: JMP 0x136778f7

// 136778f7: JMP 0x13385d13

// 13385d13: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack336[0x10000];
RSP = (uint64_t) &stack336[0x10000 - 8];


// 13385da6: MOV RCX,qword ptr [R9 + 0x28]
// switch to context pointer RCX

// 13385daa: MOV R15,qword ptr [RCX + 0x90]
R15 = *((uint64_t*) (&RBX_old));

// 13385db1: PUSH R15
RSP -= 8;
*(uint64_t*) (RSP) = R15;

// 13385db3: MOV RBX,RSP
RBX = RSP;

// 13385db6: MOV R14,qword ptr [RCX + 0x90]
R14 = *((uint64_t*) (&RBX_old));

// 13385dbd: JMP 0x13677a31

// 13677a31: JMP 0x13385dfe

// 13385dfe: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = RBX - 0;

// 0x00: AllocLarge 6
RSP += 6;

// 0x00: PushNonVol 0
RAX = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack337[0x10000];
RSP = (uint64_t) &stack337[0x10000 - 8];


// 13385e99: MOV R11,qword ptr [R9 + 0x28]
// switch to context pointer R11

// 13385e9d: MOV RBX,qword ptr [R11 + 0x78]
RBX = *((uint64_t*) (&RAX_old));

// 13385ea1: MOV R15,qword ptr [R11 + 0xe8]
R15 = *((uint64_t*) (&R14_old));

// 13385ea8: MOVZX RBX,BL
RBX = (*((uint8_t*) &RBX)) & 0xFF;

// 13385eac: JMP 0x13677b05

// 13677b05: JMP 0x13385ef6

// 13385ef6: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack338[0x10000];
RSP = (uint64_t) &stack338[0x10000 - 8];


// 13385f8d: MOV R11,qword ptr [R9 + 0x28]
// switch to context pointer R11

// 13385f91: LDMXCSR dword ptr [R11 + 0x90]
MXCSR = *((uint32_t*) (&RBX_old));

// 13385f99: MOV R13,0xc3063dcf
R13 = 0xc3063dcf;

// 13385fa3: ADD R13,0x7d0334f1
R13 += 0x7d0334f1;

// 13385faa: MOV R13,qword ptr [R13 + 0x7f8]
R13 = *((uint64_t*) (R13 + 0x7f8));

// 13385fb1: ADD R13,qword ptr [R11 + 0x90]
R13 += *((uint64_t*) (&RBX_old));

// 13385fb8: MOV R12B,byte ptr [R13]
*((uint8_t*) &R12) = *((uint8_t*) (R13));

// 13385fbc: MOVZX R12,R12B
R12 = (*((uint8_t*) &R12)) & 0xFF;

// 13385fc0: SHL R12,0x38
R12 <<= 0x38;

// 13385fc4: SUB qword ptr [R11 + 0xf0],R12
*((uint64_t*) (&R15_old)) -= R12;

// 13385fcb: MOV RBX,0xec0f56a7
RBX = 0xec0f56a7;

// 13385fd5: PUSH RBX
RSP -= 8;
*(uint64_t*) (RSP) = RBX;

// 13385fd6: PUSH 0x6fe01c0d
RSP -= 8;
*(uint64_t*) (RSP) = 0x6fe01c0d;

// 13385fdb: PUSH 0x7f966b5
RSP -= 8;
*(uint64_t*) (RSP) = 0x7f966b5;

// 13385fe0: PUSH 0x16693cd8
RSP -= 8;
*(uint64_t*) (RSP) = 0x16693cd8;

// 13385fe5: ADD qword ptr [RSP + 0x18],0x53fa1419
*((uint64_t*) (RSP + 0x18)) += 0x53fa1419;

// 13385fee: MOV RSI,qword ptr [R9 + 0x28]
// switch to context pointer RSI

// 13385ff2: MOV R15,qword ptr [RSI + 0xf0]
R15 = *((uint64_t*) (&R15_old));

// 13385ff9: JMP 0x13677f26

// 13677f26: JMP 0x13386040

// 13386040: HLT
// ----------------

// 0x00: PushMachframe 0
RSP = *(uint64_t*) (RSP + 0x18);

// 0x00: AllocLarge 2040
RSP += 2040;

// 0x00: PushNonVol 10
R10 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack339[0x10000];
RSP = (uint64_t) &stack339[0x10000 - 8];


// 133860db: MOV R9,qword ptr [R9 + 0x28]
// switch to context pointer R9

// 133860df: LDMXCSR dword ptr [R9 + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 133860e4: MOV RBP,qword ptr [R9 + 0xc8]
RBP = *((uint64_t*) (&R10_old));

// 133860eb: MOV RDI,qword ptr [R9 + 0xf0]
RDI = *((uint64_t*) (&R15_old));

// 133860f2: JMP 0x13678069

// 13678069: JMP 0x1338613c

// 1338613c: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack340[0x10000];
RSP = (uint64_t) &stack340[0x10000 - 8];


// 133861dc: MOV R14,qword ptr [R9 + 0x28]
// switch to context pointer R14

// 133861e0: MOV R13,qword ptr [R14 + 0xb0]
R13 = *((uint64_t*) (&RDI_old));

// 133861e7: MOV R12D,dword ptr [R14 + 0x34]
*((uint32_t*) &R12) = *((uint32_t*) (&MXCSR_old));

// 133861eb: ADD R12,qword ptr [R14 + 0xa0]
R12 += *((uint64_t*) (&RBP_old));

// 133861f2: MOV R8B,byte ptr [R12]
*((uint8_t*) &R8) = *((uint8_t*) (R12));

// 133861f6: MOV R9,0xff
R9 = 0xff;

// 133861fd: SHL R9,0x30
R9 <<= 0x30;

// 13386201: NOT R9
R9 = ~R9;

// 13386204: AND R13,R9
R13 &= R9;

// 13386207: MOVZX R9,R8B
R9 = (*((uint8_t*) &R8)) & 0xFF;

// 1338620b: SHL R9,0x30
R9 <<= 0x30;

// 1338620f: OR R13,R9
R13 |= R9;

// 13386212: JMP 0x13678211

// 13678211: JMP 0x1338625d

// 1338625d: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack341[0x10000];
RSP = (uint64_t) &stack341[0x10000 - 8];


// 133862f5: MOV RDI,qword ptr [R9 + 0x28]
// switch to context pointer RDI

// 133862f9: MOV R15,qword ptr [RDI + 0xe0]
R15 = *((uint64_t*) (&R13_old));

// 13386300: PUSH R15
RSP -= 8;
*(uint64_t*) (RSP) = R15;

// 13386302: MOV RBP,RSP
RBP = RSP;

// 13386305: MOV RBX,qword ptr [RDI + 0xe0]
RBX = *((uint64_t*) (&R13_old));

// 1338630c: JMP 0x13678345

// 13678345: JMP 0x1338635e

// 1338635e: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack342[0x10000];
RSP = (uint64_t) &stack342[0x10000 - 8];


// 133863f8: MOV R9,qword ptr [R9 + 0x28]
// switch to context pointer R9

// 133863fc: MOV RBX,qword ptr [R9 + 0xa0]
RBX = *((uint64_t*) (&RBP_old));

// 13386403: MOV R15,qword ptr [R9 + 0x90]
R15 = *((uint64_t*) (&RBX_old));

// 1338640a: PUSH RBX
RSP -= 8;
*(uint64_t*) (RSP) = RBX;

// 1338640b: PUSH 0x55175ff3
RSP -= 8;
*(uint64_t*) (RSP) = 0x55175ff3;

// 13386410: PUSH 0x62962f86
RSP -= 8;
*(uint64_t*) (RSP) = 0x62962f86;

// 13386415: PUSH 0x36fa727c
RSP -= 8;
*(uint64_t*) (RSP) = 0x36fa727c;

// 1338641a: PUSH 0x51b1534a
RSP -= 8;
*(uint64_t*) (RSP) = 0x51b1534a;

// 1338641f: JMP 0x13678482

// 13678482: JMP 0x13386473

// 13386473: HLT
// ----------------

// 0x00: PushMachframe 1
RSP = *(uint64_t*) (RSP + 0x20);

// 0x00: AllocLarge 7
RSP += 7;

// 0x00: PushNonVol 14
R14 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack343[0x10000];
RSP = (uint64_t) &stack343[0x10000 - 8];


// 13386511: MOV RDI,qword ptr [R9 + 0x28]
// switch to context pointer RDI

// 13386515: MOV R14,qword ptr [RDI + 0xe8]
R14 = *((uint64_t*) (&R14_old));

// 1338651c: MOV RDI,qword ptr [RDI + 0xf0]
RDI = *((uint64_t*) (&R15_old));

// 13386523: MOVZX R14,R14B
R14 = (*((uint8_t*) &R14)) & 0xFF;

// 13386527: JMP 0x136785bc

// 136785bc: JMP 0x13386573

// 13386573: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack344[0x10000];
RSP = (uint64_t) &stack344[0x10000 - 8];


// 13386613: MOV RAX,qword ptr [R9 + 0x28]
// switch to context pointer RAX

// 13386617: LDMXCSR dword ptr [RAX + 0xe8]
MXCSR = *((uint32_t*) (&R14_old));

// 1338661e: MOV R15,qword ptr [R9 + 0x28]
// switch to context pointer R15

// 13386622: MOV RBP,qword ptr [R15 + 0xb0]
RBP = *((uint64_t*) (&RDI_old));

// 13386629: MOV RDI,0xe2d7279a
RDI = 0xe2d7279a;

// 13386633: ADD RDI,0x5d324326
RDI += 0x5d324326;

// 1338663a: JMP 0x136787d1

// 136787d1: JMP 0x13386688

// 13386688: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = RDI - 0;

// 0x00: AllocLarge 2040
RSP += 2040;

// 0x00: PushNonVol 7
RDI = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack345[0x10000];
RSP = (uint64_t) &stack345[0x10000 - 8];


// 13386730: MOV RSI,qword ptr [R9 + 0x28]
// switch to context pointer RSI

// 13386734: LDMXCSR dword ptr [RSI + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 13386738: MOV RBP,qword ptr [RSI + 0xb0]
RBP = *((uint64_t*) (&RDI_old));

// 1338673f: MOV RDI,qword ptr [RSI + 0xa0]
RDI = *((uint64_t*) (&RBP_old));

// 13386746: JMP 0x1367890e

// 1367890e: JMP 0x13386789

// 13386789: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack346[0x10000];
RSP = (uint64_t) &stack346[0x10000 - 8];


// 1338681c: MOV RAX,qword ptr [R9 + 0x28]
// switch to context pointer RAX

// 13386820: MOV R12,qword ptr [RAX + 0xb0]
R12 = *((uint64_t*) (&RDI_old));

// 13386827: MOV R9D,dword ptr [RAX + 0x34]
*((uint32_t*) &R9) = *((uint32_t*) (&MXCSR_old));

// 1338682b: ADD R9,qword ptr [RAX + 0xa0]
R9 += *((uint64_t*) (&RBP_old));

// 13386832: MOV R9B,byte ptr [R9]
*((uint8_t*) &R9) = *((uint8_t*) (R9));

// 13386835: MOV R11,0xff
R11 = 0xff;

// 1338683c: SHL R11,0x38
R11 <<= 0x38;

// 13386840: NOT R11
R11 = ~R11;

// 13386843: AND R12,R11
R12 &= R11;

// 13386846: MOVZX R11,R9B
R11 = (*((uint8_t*) &R9)) & 0xFF;

// 1338684a: SHL R11,0x38
R11 <<= 0x38;

// 1338684e: OR R12,R11
R12 |= R11;

// 13386851: JMP 0x13678ab7

// 13678ab7: JMP 0x1338689e

// 1338689e: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack347[0x10000];
RSP = (uint64_t) &stack347[0x10000 - 8];


// 1338693f: MOV R13,qword ptr [R9 + 0x28]
// switch to context pointer R13

// 13386943: MOV RBX,qword ptr [R13 + 0xd8]
RBX = *((uint64_t*) (&R12_old));

// 1338694a: PUSH RBX
RSP -= 8;
*(uint64_t*) (RSP) = RBX;

// 1338694b: MOV R15,RSP
R15 = RSP;

// 1338694e: MOV RBP,qword ptr [R13 + 0xd8]
RBP = *((uint64_t*) (&R12_old));

// 13386955: JMP 0x13678bf6

// 13678bf6: JMP 0x133869a6

// 133869a6: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = R15 - 0;

// 0x00: AllocLarge 1
RSP += 1;

// 0x00: PushNonVol 6
RSI = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack348[0x10000];
RSP = (uint64_t) &stack348[0x10000 - 8];


// 13386a56: MOV RCX,qword ptr [R9 + 0x28]
// switch to context pointer RCX

// 13386a5a: MOV R12,qword ptr [RCX + 0xa8]
R12 = *((uint64_t*) (&RSI_old));

// 13386a61: MOV R14,qword ptr [RCX + 0xa0]
R14 = *((uint64_t*) (&RBP_old));

// 13386a68: MOVZX R12,R12B
R12 = (*((uint8_t*) &R12)) & 0xFF;

// 13386a6c: JMP 0x13678d2e

// 13678d2e: JMP 0x13386ab2

// 13386ab2: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack349[0x10000];
RSP = (uint64_t) &stack349[0x10000 - 8];


// 13386b4a: MOV RDX,qword ptr [R9 + 0x28]
// switch to context pointer RDX

// 13386b4e: LDMXCSR dword ptr [RDX + 0xd8]
MXCSR = *((uint32_t*) (&R12_old));

// 13386b55: MOV R14,0x13849ee23
R14 = 0x13849ee23;

// 13386b5f: PUSH R14
RSP -= 8;
*(uint64_t*) (RSP) = R14;

// 13386b61: PUSH 0x1f8b1f3c
RSP -= 8;
*(uint64_t*) (RSP) = 0x1f8b1f3c;

// 13386b66: PUSH 0x69722dfe
RSP -= 8;
*(uint64_t*) (RSP) = 0x69722dfe;

// 13386b6b: PUSH 0xac603da
RSP -= 8;
*(uint64_t*) (RSP) = 0xac603da;

// 13386b70: ADD qword ptr [RSP + 0x18],0x7bf649d
*((uint64_t*) (RSP + 0x18)) += 0x7bf649d;

// 13386b79: MOV R14,qword ptr [R9 + 0x28]
// switch to context pointer R14

// 13386b7d: MOV R14,qword ptr [R14 + 0xe8]
R14 = *((uint64_t*) (&R14_old));

// 13386b84: JMP 0x13678f45

// 13678f45: JMP 0x13386bc6

// 13386bc6: HLT
// ----------------

// 0x00: PushMachframe 0
RSP = *(uint64_t*) (RSP + 0x18);

// 0x00: PushNonVol 8
R8 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack350[0x10000];
RSP = (uint64_t) &stack350[0x10000 - 8];


// 13386c50: MOV R9,qword ptr [R9 + 0x28]
// switch to context pointer R9

// 13386c54: LDMXCSR dword ptr [R9 + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 13386c59: MOV R12,qword ptr [R9 + 0xb8]
R12 = *((uint64_t*) (&R8_old));

// 13386c60: MOV R13,qword ptr [R9 + 0xe8]
R13 = *((uint64_t*) (&R14_old));

// 13386c67: JMP 0x1367907f

// 1367907f: JMP 0x13386cad

// 13386cad: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack351[0x10000];
RSP = (uint64_t) &stack351[0x10000 - 8];


// 13386d4b: MOV R9,qword ptr [R9 + 0x28]
// switch to context pointer R9

// 13386d4f: MOV RDI,qword ptr [R9 + 0xe0]
RDI = *((uint64_t*) (&R13_old));

// 13386d56: MOV R8D,dword ptr [R9 + 0x34]
*((uint32_t*) &R8) = *((uint32_t*) (&MXCSR_old));

// 13386d5a: ADD R8,qword ptr [R9 + 0xd8]
R8 += *((uint64_t*) (&R12_old));

// 13386d61: MOV BPL,byte ptr [R8]
*((uint8_t*) &RBP) = *((uint8_t*) (R8));

// 13386d64: MOV R9,0xff
R9 = 0xff;

// 13386d6b: SHL R9,0x8
R9 <<= 0x8;

// 13386d6f: NOT R9
R9 = ~R9;

// 13386d72: AND RDI,R9
RDI &= R9;

// 13386d75: MOVZX R9,BPL
R9 = (*((uint8_t*) &RBP)) & 0xFF;

// 13386d79: SHL R9,0x8
R9 <<= 0x8;

// 13386d7d: OR RDI,R9
RDI |= R9;

// 13386d80: JMP 0x1367921a

// 1367921a: JMP 0x13386dca

// 13386dca: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack352[0x10000];
RSP = (uint64_t) &stack352[0x10000 - 8];


// 13386e55: MOV R15,qword ptr [R9 + 0x28]
// switch to context pointer R15

// 13386e59: MOV R12,qword ptr [R15 + 0xb0]
R12 = *((uint64_t*) (&RDI_old));

// 13386e60: PUSH R12
RSP -= 8;
*(uint64_t*) (RSP) = R12;

// 13386e62: MOV R12,RSP
R12 = RSP;

// 13386e65: MOV RDI,qword ptr [R15 + 0xb0]
RDI = *((uint64_t*) (&RDI_old));

// 13386e6c: JMP 0x13679353

// 13679353: JMP 0x13386ebb

// 13386ebb: HLT
// ----------------

// 0x00: SetFpreg 0
RSP = R12 - 0;

// 0x00: AllocLarge 4
RSP += 4;

// 0x00: PushNonVol 11
R11 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack353[0x10000];
RSP = (uint64_t) &stack353[0x10000 - 8];


// 13386f5c: MOV RDX,qword ptr [R9 + 0x28]
// switch to context pointer RDX

// 13386f60: MOV RDI,qword ptr [RDX + 0xd0]
RDI = *((uint64_t*) (&R11_old));

// 13386f67: MOV R14,qword ptr [RDX + 0xb0]
R14 = *((uint64_t*) (&RDI_old));

// 13386f6e: MOVZX RDI,DIL
RDI = (*((uint8_t*) &RDI)) & 0xFF;

// 13386f72: JMP 0x1367948a

// 1367948a: JMP 0x13386fc5

// 13386fc5: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack354[0x10000];
RSP = (uint64_t) &stack354[0x10000 - 8];


// 1338705a: MOV RSI,qword ptr [R9 + 0x28]
// switch to context pointer RSI

// 1338705e: LDMXCSR dword ptr [RSI + 0xb0]
MXCSR = *((uint32_t*) (&RDI_old));

// 13387065: MOV RBP,0x13369510b
RBP = 0x13369510b;

// 1338706f: PUSH RBP
RSP -= 8;
*(uint64_t*) (RSP) = RBP;

// 13387070: PUSH 0x21a7074d
RSP -= 8;
*(uint64_t*) (RSP) = 0x21a7074d;

// 13387075: PUSH 0x4bfc5d65
RSP -= 8;
*(uint64_t*) (RSP) = 0x4bfc5d65;

// 1338707a: PUSH 0x532f1438
RSP -= 8;
*(uint64_t*) (RSP) = 0x532f1438;

// 1338707f: ADD qword ptr [RSP + 0x18],0xca001b5
*((uint64_t*) (RSP + 0x18)) += 0xca001b5;

// 13387088: MOV RCX,qword ptr [R9 + 0x28]
// switch to context pointer RCX

// 1338708c: MOV R14,qword ptr [RCX + 0xe8]
R14 = *((uint64_t*) (&R14_old));

// 13387093: JMP 0x1367969c

// 1367969c: JMP 0x133870e6

// 133870e6: HLT
// ----------------

// 0x00: PushMachframe 0
RSP = *(uint64_t*) (RSP + 0x18);

// 0x00: PushNonVol 13
R13 = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack355[0x10000];
RSP = (uint64_t) &stack355[0x10000 - 8];


// 13387181: MOV R15,qword ptr [R9 + 0x28]
// switch to context pointer R15

// 13387185: LDMXCSR dword ptr [R15 + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 1338718a: MOV R12,qword ptr [R15 + 0xe0]
R12 = *((uint64_t*) (&R13_old));

// 13387191: MOV R14,qword ptr [R15 + 0xe8]
R14 = *((uint64_t*) (&R14_old));

// 13387198: JMP 0x136797d5

// 136797d5: JMP 0x133871eb

// 133871eb: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack356[0x10000];
RSP = (uint64_t) &stack356[0x10000 - 8];


// 13387285: MOV RDI,qword ptr [R9 + 0x28]
// switch to context pointer RDI

// 13387289: MOV RBX,qword ptr [RDI + 0xe8]
RBX = *((uint64_t*) (&R14_old));

// 13387290: MOV R10D,dword ptr [RDI + 0x34]
*((uint32_t*) &R10) = *((uint32_t*) (&MXCSR_old));

// 13387294: ADD R10,qword ptr [RDI + 0xd8]
R10 += *((uint64_t*) (&R12_old));

// 1338729b: MOV R15B,byte ptr [R10]
*((uint8_t*) &R15) = *((uint8_t*) (R10));

// 1338729e: MOV RCX,0xff
RCX = 0xff;

// 133872a5: SHL RCX,0x20
RCX <<= 0x20;

// 133872a9: NOT RCX
RCX = ~RCX;

// 133872ac: AND RBX,RCX
RBX &= RCX;

// 133872af: MOVZX RCX,R15B
RCX = (*((uint8_t*) &R15)) & 0xFF;

// 133872b3: SHL RCX,0x20
RCX <<= 0x20;

// 133872b7: OR RBX,RCX
RBX |= RCX;

// 133872ba: JMP 0x1367996f

// 1367996f: JMP 0x13387300

// 13387300: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack357[0x10000];
RSP = (uint64_t) &stack357[0x10000 - 8];


// 133873a6: MOV RSI,qword ptr [R9 + 0x28]
// switch to context pointer RSI

// 133873aa: MOV RBX,qword ptr [RSI + 0x90]
RBX = *((uint64_t*) (&RBX_old));

// 133873b1: PUSH RBX
RSP -= 8;
*(uint64_t*) (RSP) = RBX;

// 133873b2: MOV R15,RSP
R15 = RSP;

// 133873b5: MOV RBX,qword ptr [RSI + 0x90]
RBX = *((uint64_t*) (&RBX_old));

// 133873bc: JMP 0x13679aae

// 13679aae: JMP 0x1338740c

// 1338740c: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack358[0x10000];
RSP = (uint64_t) &stack358[0x10000 - 8];


// 133874aa: MOV RBP,qword ptr [R9 + 0x28]
// switch to context pointer RBP

// 133874ae: MOV RDI,qword ptr [RBP + 0xf0]
RDI = *((uint64_t*) (&R15_old));

// 133874b5: MOV R15,qword ptr [RBP + 0x90]
R15 = *((uint64_t*) (&RBX_old));

// 133874bc: PUSH RDI
RSP -= 8;
*(uint64_t*) (RSP) = RDI;

// 133874bd: PUSH 0xe212764
RSP -= 8;
*(uint64_t*) (RSP) = 0xe212764;

// 133874c2: PUSH 0x4a7d5b6b
RSP -= 8;
*(uint64_t*) (RSP) = 0x4a7d5b6b;

// 133874c7: PUSH 0x4f772627
RSP -= 8;
*(uint64_t*) (RSP) = 0x4f772627;

// 133874cc: JMP 0x13679be9

// 13679be9: JMP 0x13387520

// 13387520: HLT
// ----------------

// 0x00: PushMachframe 0
RSP = *(uint64_t*) (RSP + 0x18);

// 0x00: AllocLarge 6
RSP += 6;

// 0x00: PushNonVol 1
RCX = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack359[0x10000];
RSP = (uint64_t) &stack359[0x10000 - 8];


// 133875c7: MOV RDI,qword ptr [R9 + 0x28]
// switch to context pointer RDI

// 133875cb: MOV R13,qword ptr [RDI + 0x80]
R13 = *((uint64_t*) (&RCX_old));

// 133875d2: MOV RDI,qword ptr [RDI + 0xf0]
RDI = *((uint64_t*) (&R15_old));

// 133875d9: MOVZX R13,R13B
R13 = (*((uint8_t*) &R13)) & 0xFF;

// 133875dd: JMP 0x13679d2b

// 13679d2b: JMP 0x1338762e

// 1338762e: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack360[0x10000];
RSP = (uint64_t) &stack360[0x10000 - 8];


// 133876c7: MOV RCX,qword ptr [R9 + 0x28]
// switch to context pointer RCX

// 133876cb: LDMXCSR dword ptr [RCX + 0xe0]
MXCSR = *((uint32_t*) (&R13_old));

// 133876d2: MOV RBX,0xc8c72136
RBX = 0xc8c72136;

// 133876dc: PUSH RBX
RSP -= 8;
*(uint64_t*) (RSP) = RBX;

// 133876dd: PUSH 0x64742242
RSP -= 8;
*(uint64_t*) (RSP) = 0x64742242;

// 133876e2: PUSH 0x5a086d39
RSP -= 8;
*(uint64_t*) (RSP) = 0x5a086d39;

// 133876e7: PUSH 0xe155eb5
RSP -= 8;
*(uint64_t*) (RSP) = 0xe155eb5;

// 133876ec: ADD qword ptr [RSP + 0x18],0x7742318a
*((uint64_t*) (RSP + 0x18)) += 0x7742318a;

// 133876f5: MOV RCX,qword ptr [R9 + 0x28]
// switch to context pointer RCX

// 133876f9: MOV R12,qword ptr [RCX + 0xb0]
R12 = *((uint64_t*) (&RDI_old));

// 13387700: JMP 0x13679f32

// 13679f32: JMP 0x1338774d

// 1338774d: HLT
// ----------------

// 0x00: PushMachframe 0
RSP = *(uint64_t*) (RSP + 0x18);

// 0x00: PushNonVol 6
RSI = *(uint64_t*) (RSP);
RSP += 8;
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack361[0x10000];
RSP = (uint64_t) &stack361[0x10000 - 8];


// 133877de: MOV RBP,qword ptr [R9 + 0x28]
// switch to context pointer RBP

// 133877e2: LDMXCSR dword ptr [RBP + 0x34]
MXCSR = *((uint32_t*) (&MXCSR_old));

// 133877e6: MOV R13,qword ptr [RBP + 0xa8]
R13 = *((uint64_t*) (&RSI_old));

// 133877ed: MOV R12,qword ptr [RBP + 0xd8]
R12 = *((uint64_t*) (&R12_old));

// 133877f4: JMP 0x1367a068

// 1367a068: JMP 0x1338783c

// 1338783c: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack362[0x10000];
RSP = (uint64_t) &stack362[0x10000 - 8];


// 133878df: MOV RDX,qword ptr [R9 + 0x28]
// switch to context pointer RDX

// 133878e3: MOV R12,qword ptr [RDX + 0xd8]
R12 = *((uint64_t*) (&R12_old));

// 133878ea: MOV R10D,dword ptr [RDX + 0x34]
*((uint32_t*) &R10) = *((uint32_t*) (&MXCSR_old));

// 133878ee: ADD R10,qword ptr [RDX + 0xe0]
R10 += *((uint64_t*) (&R13_old));

// 133878f5: MOV R13B,byte ptr [R10]
*((uint8_t*) &R13) = *((uint8_t*) (R10));

// 133878f8: MOV R15,0xff
R15 = 0xff;

// 133878ff: SHL R15,0x30
R15 <<= 0x30;

// 13387903: NOT R15
R15 = ~R15;

// 13387906: AND R12,R15
R12 &= R15;

// 13387909: MOVZX R15,R13B
R15 = (*((uint8_t*) &R13)) & 0xFF;

// 1338790d: SHL R15,0x30
R15 <<= 0x30;

// 13387911: OR R12,R15
R12 |= R15;

// 13387914: JMP 0x1367a203

// 1367a203: JMP 0x1338795a

// 1338795a: HLT
// ----------------
// save current state
RAX_old = RAX;
RCX_old = RCX;
RDX_old = RDX;
RBX_old = RBX;
RSP_old = RSP;
RBP_old = RBP;
RSI_old = RSI;
RDI_old = RDI;
R8_old = R8;
R9_old = R9;
R10_old = R10;
R11_old = R11;
R12_old = R12;
R13_old = R13;
R14_old = R14;
R15_old = R15;
MXCSR_old = MXCSR;
char stack363[0x10000];
RSP = (uint64_t) &stack363[0x10000 - 8];


// 133879e1: MOV RBX,qword ptr [R9 + 0x28]
// switch to context pointer RBX

// 133879e5: MOV R14,qword ptr [RBX + 0xd8]
R14 = *((uint64_t*) (&R12_old));

// 133879ec: MOV R15,0x10bf5d1a1
R15 = 0x10bf5d1a1;

// 133879f6: ADD R15,0x340a404f
R15 += 0x340a404f;

// 133879fd: TEST R14,R14
ZF = (R14 & R14) == 0;

// 13387a00: LEA R12,[0x1309505f]
R12 = 0x1309505f;

// 13387a07: CMOVNZ R12,R15
if (ZF) R12 = R15;
return R12;

}
