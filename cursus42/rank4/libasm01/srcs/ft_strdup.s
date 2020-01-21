extern _malloc
extern _ft_strcpy
extern _ft_strlen

section .text
	global	_ft_strdup

_ft_strdup:
	call _ft_strlen
	inc	rax
	push rdi
	mov rdi, rax
	call _malloc ;rax <- *ptr
	pop	rdi
	mov	rsi, rdi
	mov rdi, rax ;rdi <- *ptr
	call	_ft_strcpy
	ret