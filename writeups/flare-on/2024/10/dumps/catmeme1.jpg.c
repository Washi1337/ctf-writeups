
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
L0038:	mem[(uint64_t) (0xa)] = (uint64_t) (0x6144);
L003f:	mem[(uint64_t) (0xb)] = (uint64_t) (0x7534);
L0046:	mem[(uint64_t) (0xc)] = (uint64_t) (0x6962);
L004d:	mem[(uint64_t) (0xd)] = (uint64_t) (0x6c63);
L0054:	mem[(uint64_t) (0xe)] = (uint64_t) (0x3165);
L005b:	mem[(uint64_t) (0xf)] = (uint64_t) (0x6669);
L0062:	mem[(uint64_t) (0x10)] = (uint64_t) (0x6265);
L0069:	mem[(uint64_t) (0x11)] = (uint64_t) (0x6230);
L0070:	mem[(uint64_t) (0x8)] = ((((mem[(uint64_t) (0x3)] << (uint64_t) (0x30)) | (mem[(uint64_t) (0x2)] << (uint64_t) (0x20))) | (mem[(uint64_t) (0x1)] << (uint64_t) (0x10))) | mem[(uint64_t) (0x0)]);
L0093:	mem[(uint64_t) (0x9)] = ((((mem[(uint64_t) (0x7)] << (uint64_t) (0x30)) | (mem[(uint64_t) (0x6)] << (uint64_t) (0x20))) | (mem[(uint64_t) (0x5)] << (uint64_t) (0x10))) | mem[(uint64_t) (0x4)]);
L00b6:	mem[(uint64_t) (0x12)] = ((((mem[(uint64_t) (0xd)] << (uint64_t) (0x30)) | (mem[(uint64_t) (0xc)] << (uint64_t) (0x20))) | (mem[(uint64_t) (0xb)] << (uint64_t) (0x10))) | mem[(uint64_t) (0xa)]);
L00d9:	mem[(uint64_t) (0x13)] = ((((mem[(uint64_t) (0x11)] << (uint64_t) (0x30)) | (mem[(uint64_t) (0x10)] << (uint64_t) (0x20))) | (mem[(uint64_t) (0xf)] << (uint64_t) (0x10))) | mem[(uint64_t) (0xe)]);
L00fc:	mem[(uint64_t) (0x14)] = (uint64_t) (0x0);
L0103:	mem[(uint64_t) (0x18)] = (uint64_t) (0x1);
L010a:	mem[(uint64_t) (0x17)] = (uint64_t) (0x0);
L0111:	mem[(uint64_t) (0x19)] = (uint64_t) (0x0);
L0118:	if (!(mem[(uint64_t) (0x18)] == (uint64_t) (0x1))) goto L0241;
L0123:	if (!(mem[(uint64_t) (0x14)] < (uint64_t) (0x8))) goto L0150;
L012e:	mem[(uint64_t) (0x15)] = (mem[(uint64_t) (0x8)] >> ((uint64_t) (0x8) * mem[(uint64_t) (0x14)]));
L013f:	mem[(uint64_t) (0x16)] = (mem[(uint64_t) (0x12)] >> ((uint64_t) (0x8) * mem[(uint64_t) (0x14)]));
L0150:	if (!(mem[(uint64_t) (0x14)] > (uint64_t) (0x7))) goto L017d;
L015b:	mem[(uint64_t) (0x15)] = (mem[(uint64_t) (0x9)] >> ((uint64_t) (0x8) * mem[(uint64_t) (0x14)]));
L016c:	mem[(uint64_t) (0x16)] = (mem[(uint64_t) (0x13)] >> ((uint64_t) (0x8) * mem[(uint64_t) (0x14)]));
L017d:	mem[(uint64_t) (0x15)] = (mem[(uint64_t) (0x15)] & (uint64_t) (0xff));
L0189:	mem[(uint64_t) (0x16)] = (mem[(uint64_t) (0x16)] & (uint64_t) (0xff));
L0195:	if (!(mem[(uint64_t) (0x14)] == (uint64_t) (0x2))) goto L01ac;
L01a0:	mem[(uint64_t) (0x16)] = rotate_byte_left(mem[(uint64_t) (0x16)], (uint64_t) (0x4));
L01ac:	if (!(mem[(uint64_t) (0x14)] == (uint64_t) (0x9))) goto L01c3;
L01b7:	mem[(uint64_t) (0x16)] = rotate_byte_right(mem[(uint64_t) (0x16)], (uint64_t) (0x2));
L01c3:	if (!(mem[(uint64_t) (0x14)] == (uint64_t) (0xd))) goto L01da;
L01ce:	mem[(uint64_t) (0x16)] = rotate_byte_left(mem[(uint64_t) (0x16)], (uint64_t) (0x7));
L01da:	if (!(mem[(uint64_t) (0x14)] == (uint64_t) (0xf))) goto L01f1;
L01e5:	mem[(uint64_t) (0x16)] = rotate_byte_left(mem[(uint64_t) (0x16)], (uint64_t) (0x7));
L01f1:	if (!((mem[(uint64_t) (0x15)] == mem[(uint64_t) (0x16)]) == (uint64_t) (0x0))) goto L0208;
L0201:	mem[(uint64_t) (0x18)] = (uint64_t) (0x0);
L0208:	if (!(mem[(uint64_t) (0x15)] == mem[(uint64_t) (0x16)])) goto L0220;
L0214:	mem[(uint64_t) (0x17)] = (mem[(uint64_t) (0x17)] + (uint64_t) (0x1));
L0220:	mem[(uint64_t) (0x14)] = (mem[(uint64_t) (0x14)] + (uint64_t) (0x1));
L022c:	if (!(mem[(uint64_t) (0x14)] > (uint64_t) (0xf))) goto L023e;
L0237:	mem[(uint64_t) (0x18)] = (uint64_t) (0x0);
L023e:	goto L0118;
L0241:	if (!(mem[(uint64_t) (0x17)] == (uint64_t) (0x10))) goto L0253;
L024c:	mem[(uint64_t) (0x19)] = (uint64_t) (0x1);
L0253:	output = mem[(uint64_t) (0x19)];
L0258:	return output;

}

int main() {
	char input[16] = {0};

	printf("%s\n", input);
	printf("%llx\n", get(input));
}
