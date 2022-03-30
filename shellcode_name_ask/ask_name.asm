%include 'add_func.asm'

SECTION .bss
inputName: RESW 1

SECTION .data
msg1 db "Saisissez votre prenom: ", 0h
msg2 db "Bonjour: ", 0h

SECTION .text
global _start

_start:

    mov eax, msg1
    call sprint

    mov edx, 255
    mov ecx, inputName
    mov ebx, 0
    mov eax, 3
    int 80h

    mov eax, msg2
    call sprint

    mov eax, inputName
    call sprint

    call quit