
#include <stdio.h>
#include <string.h>
typedef unsigned long long uint64_t;

uint64_t rotate_byte_left(uint64_t a, uint64_t b) { return (a << b | a >> (8 - b)) & 0xFF; } 
uint64_t rotate_uint32_left(uint64_t a, uint64_t b) { return (a << b | a >> (32 - b)) & 0xFFFFFFFF; } 
uint64_t rotate_byte_right(uint64_t a, uint64_t b) { return (a >> b | a << (8 - b)) & 0xFF; } 
uint64_t rotate_uint32_right(uint64_t a, uint64_t b) { return (a >> b | a << (32 - b)) & 0xFFFFFFFF; }

uint64_t get(char* input) {
	uint64_t mem[0x100] = { 0 };
	uint64_t output = 0;

L0000:	mem[(uint64_t) (0x0)] = (uint64_t) ((input[0] | input[1] << 8));
L0007:	mem[(uint64_t) (0x1)] = (uint64_t) ((input[2] | input[3] << 8));
L000e:	mem[(uint64_t) (0x2)] = (uint64_t) ((input[4] | input[5] << 8));
L0015:	mem[(uint64_t) (0x3)] = (uint64_t) ((input[6] | input[7] << 8));
L001c:	mem[(uint64_t) (0x4)] = (uint64_t) ((input[8] | input[9] << 8));
L0023:	mem[(uint64_t) (0x5)] = (uint64_t) ((input[10] | input[11] << 8));
L002a:	mem[(uint64_t) (0x6)] = (uint64_t) ((input[12] | input[13] << 8));
L0031:	mem[(uint64_t) (0x7)] = (uint64_t) ((input[14] | input[15] << 8));
L0038:	mem[(uint64_t) (0x8)] = ((((mem[(uint64_t) (0x3)] << (uint64_t) (0x30)) | (mem[(uint64_t) (0x2)] << (uint64_t) (0x20))) | (mem[(uint64_t) (0x1)] << (uint64_t) (0x10))) | mem[(uint64_t) (0x0)]);
L005b:	mem[(uint64_t) (0x9)] = ((((mem[(uint64_t) (0x7)] << (uint64_t) (0x30)) | (mem[(uint64_t) (0x6)] << (uint64_t) (0x20))) | (mem[(uint64_t) (0x5)] << (uint64_t) (0x10))) | mem[(uint64_t) (0x4)]);
L007e:	mem[(uint64_t) (0x1e)] = (uint64_t) (0xffff);
L0085:	mem[(uint64_t) (0x1d)] = mem[(uint64_t) (0x1e)];
L008d:	mem[(uint64_t) (0x1e)] = ((mem[(uint64_t) (0x1e)] << (uint64_t) (0x10)) | mem[(uint64_t) (0x1d)]);
L009e:	mem[(uint64_t) (0x1b)] = (uint64_t) (0x0);
L00a5:	mem[(uint64_t) (0x1f)] = (uint64_t) (0x0);
L00ac:	mem[(uint64_t) (0x20)] = (uint64_t) (0x0);
L00b3:	mem[(uint64_t) (0x13)] = (uint64_t) (0x1505);
L00ba:	if (!(mem[(uint64_t) (0x1b)] < (uint64_t) (0x4))) goto L010f;
L00c5:	mem[(uint64_t) (0x1c)] = (mem[(uint64_t) (0x8)] >> ((uint64_t) (0x8) * mem[(uint64_t) (0x1b)]));
L00d6:	mem[(uint64_t) (0x1c)] = (mem[(uint64_t) (0x1c)] & (uint64_t) (0xff));
L00e2:	mem[(uint64_t) (0x1d)] = mem[(uint64_t) (0x13)];
L00ea:	mem[(uint64_t) (0x13)] = (((mem[(uint64_t) (0x13)] << (uint64_t) (0x5)) + mem[(uint64_t) (0x1d)]) + mem[(uint64_t) (0x1c)]);
L0100:	mem[(uint64_t) (0x1b)] = (mem[(uint64_t) (0x1b)] + (uint64_t) (0x1));
L010c:	goto L00ba;
L010f:	mem[(uint64_t) (0x13)] = (mem[(uint64_t) (0x13)] & mem[(uint64_t) (0x1e)]);
L011c:	mem[(uint64_t) (0x14)] = (((uint64_t) (0x7c8d) << (uint64_t) (0x10)) | (uint64_t) (0xf4cb));
L012b:	if (!(mem[(uint64_t) (0x14)] == mem[(uint64_t) (0x13)])) goto L0143;
L0137:	mem[(uint64_t) (0x1f)] = (mem[(uint64_t) (0x1f)] + (uint64_t) (0x1));
L0143:	if (!(mem[(uint64_t) (0x1f)] > (uint64_t) (0x0))) goto L01d9;
L014e:	mem[(uint64_t) (0x15)] = (uint64_t) (0x0);
L0155:	if (!(mem[(uint64_t) (0x1b)] < (uint64_t) (0x8))) goto L01a5;
L0160:	mem[(uint64_t) (0x1c)] = (mem[(uint64_t) (0x8)] >> ((uint64_t) (0x8) * mem[(uint64_t) (0x1b)]));
L0171:	mem[(uint64_t) (0x1c)] = (mem[(uint64_t) (0x1c)] & (uint64_t) (0xff));
L017d:	mem[(uint64_t) (0x15)] = rotate_uint32_right(mem[(uint64_t) (0x15)], (uint64_t) (0xd));
L0189:	mem[(uint64_t) (0x15)] = (mem[(uint64_t) (0x15)] + mem[(uint64_t) (0x1c)]);
L0196:	mem[(uint64_t) (0x1b)] = (mem[(uint64_t) (0x1b)] + (uint64_t) (0x1));
L01a2:	goto L0155;
L01a5:	mem[(uint64_t) (0x15)] = (mem[(uint64_t) (0x15)] & mem[(uint64_t) (0x1e)]);
L01b2:	mem[(uint64_t) (0x16)] = (((uint64_t) (0x8b68) << (uint64_t) (0x10)) | (uint64_t) (0x1d82));
L01c1:	if (!(mem[(uint64_t) (0x16)] == mem[(uint64_t) (0x15)])) goto L01d9;
L01cd:	mem[(uint64_t) (0x1f)] = (mem[(uint64_t) (0x1f)] + (uint64_t) (0x1));
L01d9:	if (!(mem[(uint64_t) (0x1f)] > (uint64_t) (0x1))) goto L029e;
L01e4:	mem[(uint64_t) (0x11)] = (uint64_t) (0x1);
L01eb:	mem[(uint64_t) (0x12)] = (uint64_t) (0x0);
L01f2:	mem[(uint64_t) (0x17)] = (uint64_t) (0x0);
L01f9:	mem[(uint64_t) (0x1b)] = (uint64_t) (0x0);
L0200:	if (!(mem[(uint64_t) (0x1b)] < (uint64_t) (0x8))) goto L0259;
L020b:	mem[(uint64_t) (0x1c)] = (mem[(uint64_t) (0x9)] >> ((uint64_t) (0x8) * mem[(uint64_t) (0x1b)]));
L021c:	mem[(uint64_t) (0x1c)] = (mem[(uint64_t) (0x1c)] & (uint64_t) (0xff));
L0228:	mem[(uint64_t) (0x11)] = ((mem[(uint64_t) (0x11)] + mem[(uint64_t) (0x1c)]) % (uint64_t) (0xfff1));
L0239:	mem[(uint64_t) (0x12)] = ((mem[(uint64_t) (0x12)] + mem[(uint64_t) (0x11)]) % (uint64_t) (0xfff1));
L024a:	mem[(uint64_t) (0x1b)] = (mem[(uint64_t) (0x1b)] + (uint64_t) (0x1));
L0256:	goto L0200;
L0259:	mem[(uint64_t) (0x17)] = ((mem[(uint64_t) (0x12)] << (uint64_t) (0x10)) | mem[(uint64_t) (0x11)]);
L026a:	mem[(uint64_t) (0x17)] = (mem[(uint64_t) (0x17)] & mem[(uint64_t) (0x1e)]);
L0277:	mem[(uint64_t) (0x18)] = (((uint64_t) (0xf91) << (uint64_t) (0x10)) | (uint64_t) (0x374));
L0286:	if (!(mem[(uint64_t) (0x18)] == mem[(uint64_t) (0x17)])) goto L029e;
L0292:	mem[(uint64_t) (0x1f)] = (mem[(uint64_t) (0x1f)] + (uint64_t) (0x1));
L029e:	if (!(mem[(uint64_t) (0x1f)] > (uint64_t) (0x2))) goto L03b2;
L02a9:	mem[(uint64_t) (0xa)] = (uint64_t) (0x193);
L02b0:	mem[(uint64_t) (0xb)] = (uint64_t) (0x100);
L02b7:	mem[(uint64_t) (0xc)] = ((mem[(uint64_t) (0xb)] << (uint64_t) (0x10)) | mem[(uint64_t) (0xa)]);
L02c8:	mem[(uint64_t) (0xd)] = (uint64_t) (0x9dc5);
L02cf:	mem[(uint64_t) (0xe)] = (uint64_t) (0x811c);
L02d6:	mem[(uint64_t) (0xf)] = ((mem[(uint64_t) (0xe)] << (uint64_t) (0x10)) | mem[(uint64_t) (0xd)]);
L02e7:	mem[(uint64_t) (0x10)] = ((uint64_t) (0x1) << (uint64_t) (0x20));
L02f2:	mem[(uint64_t) (0x19)] = mem[(uint64_t) (0xf)];
L02fa:	mem[(uint64_t) (0x1b)] = (uint64_t) (0x0);
L0301:	if (!(mem[(uint64_t) (0x1b)] < (uint64_t) (0x10))) goto L037e;
L030c:	if (!(mem[(uint64_t) (0x1b)] < (uint64_t) (0x8))) goto L0328;
L0317:	mem[(uint64_t) (0x1c)] = (mem[(uint64_t) (0x8)] >> ((uint64_t) (0x8) * mem[(uint64_t) (0x1b)]));
L0328:	if (!(mem[(uint64_t) (0x1b)] > (uint64_t) (0x7))) goto L0344;
L0333:	mem[(uint64_t) (0x1c)] = (mem[(uint64_t) (0x9)] >> ((uint64_t) (0x8) * mem[(uint64_t) (0x1b)]));
L0344:	mem[(uint64_t) (0x1c)] = (mem[(uint64_t) (0x1c)] & (uint64_t) (0xff));
L0350:	mem[(uint64_t) (0x19)] = ((mem[(uint64_t) (0x19)] * mem[(uint64_t) (0xc)]) % mem[(uint64_t) (0x10)]);
L0362:	mem[(uint64_t) (0x19)] = (mem[(uint64_t) (0x19)] ^ mem[(uint64_t) (0x1c)]);
L036f:	mem[(uint64_t) (0x1b)] = (mem[(uint64_t) (0x1b)] + (uint64_t) (0x1));
L037b:	goto L0301;
L037e:	mem[(uint64_t) (0x19)] = (mem[(uint64_t) (0x19)] & mem[(uint64_t) (0x1e)]);
L038b:	mem[(uint64_t) (0x1a)] = (((uint64_t) (0x31f0) << (uint64_t) (0x10)) | (uint64_t) (0x9d2));
L039a:	if (!(mem[(uint64_t) (0x1a)] == mem[(uint64_t) (0x19)])) goto L03b2;
L03a6:	mem[(uint64_t) (0x1f)] = (mem[(uint64_t) (0x1f)] + (uint64_t) (0x1));
L03b2:	if (!(mem[(uint64_t) (0x1f)] == (uint64_t) (0x4))) goto L03c4;
L03bd:	mem[(uint64_t) (0x20)] = (uint64_t) (0x1);
L03c4:	output = mem[(uint64_t) (0x20)];
L03c9:	return output;

}

int main() {
	char input[16] = {0};

	printf("%s\n", input);
	printf("%llx\n", get(input));
}
