section .text
	global	_ft_strcpy

_ft_strcpy:
    mov rbx, 0
while:
    cmp byte[rsi + rbx], 0
    je exit_while
    mov dl, byte[rsi + rbx]
    mov byte[rdi + rbx], dl
    add rbx, 1
    jmp while
exit_while:
    mov rax, rdi
    ret