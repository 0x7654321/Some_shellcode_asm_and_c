SECTION .data
msg db 'Hello world!!', 0Ah

SECTION .text
global _start

_start:

    xor edx, edx
    xor ecx, ecx
    xor ebx, ebx
    xor eax, eax
    
    mov edx, 14
    mov ecx, msg
    mov ebx, 1
    mov eax, 4
    int 0x80
    
    mov ebx, 0
    mov eax, 1
    int 0x80
