# ClumsyVM notes

## Instruction format



| Bits | Meaning |
| -: | :- |
| 0 | ? |
| 1-8 | next offset |
| 9 | add reg3 to nextoffset |
| 10 | branch if parity |
| 11 | branch if zero |
| 12-13 | ALU shift/rotate |
| 14-19 | ALU bit operation |
| 20-28 | Output registers |
| 29-31 | Read/write memory |
| 32-36 | Input register select |

Process:

- Read input register
- Perform ALU addition
- Perform ALU bit operation if selected
- Perform ALU shift/rotate
- Set output registers
- Perform Read/Write memory operations if selected.

## Bits 12-13


| Value | Meaning |
| -: | - |
| 00 | Nothing |
| 10 | Shift left by 8 |
| 01 | Rotate right by one |
| 11 | Nothing |

## Bits 14-19


| Bits | Meaning |
| -: | - |
| 14-15 | Operation AND, OR, NOT or id |
| 16 | If 1 Then A = reg "1" Else 0 |
| 17 | If 1 Then B = input reg Else 0 |
| 18 | If 1 Then flip bits of A |
| 19 | If 1 Then +1 Else +0 |

Output is determined by 14-15


| 14-15 | Meaning |
| -: | - |
| 00 | A & B |
| 01 | A |
| 10 | ¬B |
| 11 | addition result |

## Bits 20-28

Output registers

## Bits 29-31


| Bits | Meaning |
| -: | - |
| 29 | `mov dword [reg0], reg1` |
| 30 | `mov output0, dword [reg0]` |
| 31 | `mov output1, byte [reg2]` |

## Example:

```
0 00000001 0 00 00 000000 000000000 000 1001
```

input register 9 (= "1") = 0
no shift/rotate
AND ALU operation
no output registers
no memory operation

```
and r9, r9, r9
```

-

```
010111101000 00 111100 000000001 010 0110
```

input register 6
addition reg "1" and input reg, put in reg0
read from memory at address reg0

```
add r9, r6, r0
load dword [r0]
```

-

```
010111110000 00 110101 010000000 000 0001
```

input reg 2
no mem ops
store in reg 8
add 1 to input reg

```
add r2, 1, r8
```

## Initial registers

```
REG_0 = 0 (0x00000000) (0b00000000000000000000000000000000)
REG_1 = 0 (0x00000000) (0b00000000000000000000000000000000)
REG_2 = 0 (0x00000000) (0b00000000000000000000000000000000)
REG_3 = 0 (0x00000000) (0b00000000000000000000000000000000)
REG_4 = 257 (0x00000101) (0b00000000000000000000000100000001)
REG_5 = 256 (0x00000100) (0b00000000000000000000000100000000)
REG_6 = 128 (0x00000080) (0b00000000000000000000000010000000)
REG_7 = 0 (0x00000000) (0b00000000000000000000000000000000)
REG_8 = 0 (0x00000000) (0b00000000000000000000000000000000)
1 = 0 (0x00000000) (0b00000000000000000000000000000000)
```


## Registers

- r0: index (=address/4) read/write dword
- r1: data read/write dword
- r2: address read byte
- r3: data read byte
- r4: stack pointer?
-
