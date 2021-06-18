[BITS 32]
org 0x08048f47

    push eax
    lea  ebx, dword [rel format]
    push ebx
    call 0x08048970 

loop:
    jmp loop 
format: 
    db "%08x", 0x0a, 0x00