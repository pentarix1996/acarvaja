section .text
	global	_ft_strcmp

_ft_strcmp:
    mov rbx, 0
while:
    cmp byte[rdi + rbx], 0
    je exit_while
    cmp byte[rsi + rbx], 0
    je exit_while
    mov dl, byte[rsi + rbx]
    cmp byte[rdi + rbx], dl
    jne exit_while
    add rbx, 1
    jmp while
exit_while:
    mov al, byte[rdi + rbx]
    sub al, byte[rsi + rbx]
    ret