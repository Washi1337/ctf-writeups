---
title: 9 - 10000
layout: default
---

# 9 - 10000

**Time spent:** ~1.5 day

**Tools used:** Ghidra, GhidraScript, x64dbg, Python, Sagemath


- 10,000 resources
- Decompression/decryption algorithm -> Decompress all
- Notice construction:
  - Start with bunch of transforms (3 types)
    - perms
    - subs
    - cursed exponentiation
  - Moved into matrix after xor
  - Check det(A) == 0 (i.e., invertible)
  - Matrix exponentiation
- Extractor
- What happens after a DLL?
- Fixed buffer of sums based on index of invocation
- Order -> Coeffs Matrix -> sagemath -> win
- Get flag
