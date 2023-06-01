section .data
    format db 'Hello, Holberton', 0

section .text
    global main
    extern printf

main:
    mov edi, format
    xor eax, eax
    call printf
    xor eax, eax  ; Set return value to 0
    ret
