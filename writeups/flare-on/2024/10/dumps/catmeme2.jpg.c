
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
L0038:	mem[(uint64_t) (0xa)] = (uint64_t) (0xa059);
L003f:	mem[(uint64_t) (0xb)] = (uint64_t) (0x6a4d);
L0046:	mem[(uint64_t) (0xc)] = (uint64_t) (0xde23);
L004d:	mem[(uint64_t) (0xd)] = (uint64_t) (0x24c0);
L0054:	mem[(uint64_t) (0xe)] = (uint64_t) (0x64e2);
L005b:	mem[(uint64_t) (0xf)] = (uint64_t) (0x59b1);
L0062:	mem[(uint64_t) (0x10)] = (uint64_t) (0x7207);
L0069:	mem[(uint64_t) (0x11)] = (uint64_t) (0x7f5c);
L0070:	mem[(uint64_t) (0x8)] = ((((mem[(uint64_t) (0x3)] << (uint64_t) (0x30)) | (mem[(uint64_t) (0x2)] << (uint64_t) (0x20))) | (mem[(uint64_t) (0x1)] << (uint64_t) (0x10))) | mem[(uint64_t) (0x0)]);
L0093:	mem[(uint64_t) (0x9)] = ((((mem[(uint64_t) (0x7)] << (uint64_t) (0x30)) | (mem[(uint64_t) (0x6)] << (uint64_t) (0x20))) | (mem[(uint64_t) (0x5)] << (uint64_t) (0x10))) | mem[(uint64_t) (0x4)]);
L00b6:	mem[(uint64_t) (0x12)] = ((((mem[(uint64_t) (0xd)] << (uint64_t) (0x30)) | (mem[(uint64_t) (0xc)] << (uint64_t) (0x20))) | (mem[(uint64_t) (0xb)] << (uint64_t) (0x10))) | mem[(uint64_t) (0xa)]);
L00d9:	mem[(uint64_t) (0x13)] = ((((mem[(uint64_t) (0x11)] << (uint64_t) (0x30)) | (mem[(uint64_t) (0x10)] << (uint64_t) (0x20))) | (mem[(uint64_t) (0xf)] << (uint64_t) (0x10))) | mem[(uint64_t) (0xe)]);
L00fc:	mem[(uint64_t) (0x14)] = (uint64_t) (0x0);
L0103:	mem[(uint64_t) (0x15)] = (uint64_t) (0x1);
L010a:	mem[(uint64_t) (0x16)] = (uint64_t) (0x0);
L0111:	mem[(uint64_t) (0x17)] = (uint64_t) (0x0);
L0118:	mem[(uint64_t) (0x1c)] = ((uint64_t) (0x43fd) | ((uint64_t) (0x3) << (uint64_t) (0x10)));
L0127:	mem[(uint64_t) (0x1d)] = ((uint64_t) (0x9ec3) | ((uint64_t) (0x26) << (uint64_t) (0x10)));
L0136:	mem[(uint64_t) (0x1b)] = ((uint64_t) (0x1) << (uint64_t) (0x1f));
L0141:	mem[(uint64_t) (0x1e)] = (uint64_t) (0x1337);
L0148:	if (!(mem[(uint64_t) (0x15)] == (uint64_t) (0x1))) goto L0262;
L0153:	if (!(mem[(uint64_t) (0x14)] < (uint64_t) (0x8))) goto L0180;
L015e:	mem[(uint64_t) (0x18)] = (mem[(uint64_t) (0x8)] >> ((uint64_t) (0x8) * mem[(uint64_t) (0x14)]));
L016f:	mem[(uint64_t) (0x19)] = (mem[(uint64_t) (0x12)] >> ((uint64_t) (0x8) * mem[(uint64_t) (0x14)]));
L0180:	if (!(mem[(uint64_t) (0x14)] > (uint64_t) (0x7))) goto L01ad;
L018b:	mem[(uint64_t) (0x18)] = (mem[(uint64_t) (0x9)] >> ((uint64_t) (0x8) * mem[(uint64_t) (0x14)]));
L019c:	mem[(uint64_t) (0x19)] = (mem[(uint64_t) (0x13)] >> ((uint64_t) (0x8) * mem[(uint64_t) (0x14)]));
L01ad:	mem[(uint64_t) (0x18)] = (mem[(uint64_t) (0x18)] & (uint64_t) (0xff));
L01b9:	mem[(uint64_t) (0x19)] = (mem[(uint64_t) (0x19)] & (uint64_t) (0xff));
L01c5:	mem[(uint64_t) (0x1e)] = (((mem[(uint64_t) (0x1c)] * mem[(uint64_t) (0x1e)]) + mem[(uint64_t) (0x1d)]) % mem[(uint64_t) (0x1b)]);
L01dc:	mem[(uint64_t) (0x1a)] = mem[(uint64_t) (0x1e)];
L01e4:	mem[(uint64_t) (0x1a)] = (mem[(uint64_t) (0x1e)] >> ((uint64_t) (0x8) * (mem[(uint64_t) (0x14)] % (uint64_t) (0x4))));
L01f9:	mem[(uint64_t) (0x1f)] = (mem[(uint64_t) (0x1a)] & (uint64_t) (0xff));
L0205:	mem[(uint64_t) (0x20)] = (mem[(uint64_t) (0x18)] ^ mem[(uint64_t) (0x1f)]);
L0212:	if (!((mem[(uint64_t) (0x20)] == mem[(uint64_t) (0x19)]) == (uint64_t) (0x0))) goto L0229;
L0222:	mem[(uint64_t) (0x15)] = (uint64_t) (0x0);
L0229:	if (!(mem[(uint64_t) (0x20)] == mem[(uint64_t) (0x19)])) goto L0241;
L0235:	mem[(uint64_t) (0x16)] = (mem[(uint64_t) (0x16)] + (uint64_t) (0x1));
L0241:	mem[(uint64_t) (0x14)] = (mem[(uint64_t) (0x14)] + (uint64_t) (0x1));
L024d:	if (!(mem[(uint64_t) (0x14)] > (uint64_t) (0xf))) goto L025f;
L0258:	mem[(uint64_t) (0x15)] = (uint64_t) (0x0);
L025f:	goto L0148;
L0262:	if (!(mem[(uint64_t) (0x16)] == (uint64_t) (0x10))) goto L0274;
L026d:	mem[(uint64_t) (0x17)] = (uint64_t) (0x1);
L0274:	if (!((mem[(uint64_t) (0x16)] == (uint64_t) (0x10)) == (uint64_t) (0x0))) goto L028a;
L0283:	mem[(uint64_t) (0x17)] = (uint64_t) (0x0);
L028a:	output = mem[(uint64_t) (0x17)];
L028f:	return output;

}

int main() {
	char input[16] = {0};

	printf("%s\n", input);
	printf("%llx\n", get(input));
}
