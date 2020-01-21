section .text
	global	_ft_strlen

_ft_strlen:
    mov rax, 0
while:
    cmp byte[rdi + rax], 0
    je  exit_while
    add rax, 1
    jmp while
exit_while:
    ret