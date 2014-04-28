SEL_KERNEL_INIT		equ		8
extern gdt_ptr	;存储loader里的gdt值
extern start

[section .bss]
stackspace	resb	4 * 1024
stacktop:

[section .text]
global _start
_start:
	mov esp, stacktop
	sgdt [gdt_ptr]
	call start

	jmp SEL_KERNEL_INIT:init

init:
	push 0
	popfd
	hlt
