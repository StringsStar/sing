SEL_KERNEL_INIT		equ		8

extern gdt_ptr	;存储loader里的gdt值
extern idt_ptr
extern start
extern exception_handler
extern spurious_irq

[section .bss]
stackspace	resb	4 * 1024
stacktop:

[section .text]
global _start
global idt_divide_error
global idt_debug
global idt_nmi
global idt_breakpoint
global idt_overflow
global idt_bounds
global idt_inval_opcode
global idt_copr_invalid
global idt_double_fault
global idt_seg_overrun
global idt_inval_tss
global idt_seg_present
global idt_stack
global idt_gp
global idt_page_fault
global idt_copr_err
global hwint0
global hwint1
global hwint2
global hwint3
global hwint4
global hwint5
global hwint6
global hwint7
global hwint8
global hwint9
global hwint10
global hwint11
global hwint12
global hwint13
global hwint14
global hwint15

_start:
	mov esp, stacktop
	sgdt [gdt_ptr]
	call start

	lgdt [gdt_ptr]
	lidt [idt_ptr]

	jmp SEL_KERNEL_INIT:init

init:
	;int 3 ;是陷阱,会弹出下一条指令地址
	;jmp $
	;sti
	;ud2
	;push 0
	;popfd
	sti
	hlt
	hlt
	hlt

%macro	hwint_master 1
	push %1
	call spurious_irq
	add esp, 4
	iret
	hlt
%endmacro

%macro hwint_slave 1
	push %1
	call spurious_irq
	add esp, 4
	hlt
%endmacro

ALIGN 16
hwint0:
	hwint_master 0

ALIGN 16
hwint1:
	hwint_master 1

ALIGN 16
hwint2:
	hwint_master 2

ALIGN 16
hwint3:
	hwint_master 3

ALIGN 16
hwint4:
	hwint_master 4

ALIGN 16
hwint5:
	hwint_master 5

ALIGN 16
hwint6:
	hwint_master 6

ALIGN 16
hwint7:
	hwint_master 7

ALIGN 16
hwint8:
	hwint_master 8

ALIGN 16
hwint9:
	hwint_master 9

ALIGN 16
hwint10:
	hwint_master 10

ALIGN 16
hwint11:
	hwint_master 11

ALIGN 16
hwint12:
	hwint_master 12

ALIGN 16
hwint13:
	hwint_master 13

ALIGN 16
hwint14:
	hwint_master 14

ALIGN 16
hwint15:
	hwint_master 15

idt_divide_error:
	push	0xFFFFFFFF
	push 	0
	jmp exception
idt_debug:
	push	0xFFFFFFFF
	push	1
	jmp exception
idt_nmi:
	push 	0xFFFFFFFF
	push	2
	jmp exception
idt_breakpoint:
	push	0xFFFFFFFF
	push	3
	jmp exception
idt_overflow:
	push	0xFFFFFFFF
	push 	4
	jmp exception
idt_bounds:
	push	0xFFFFFFFF
	push	5
	jmp exception
idt_inval_opcode:
	push	0xFFFFFFFF
	push	6
	jmp exception
idt_copr_invalid:
	push	0xFFFFFFFF
	push 	7
	jmp exception
idt_double_fault:	;vector=8
	push 	8	
	jmp		exception
idt_seg_overrun:
	push	0xFFFFFFFF
	push	9
	jmp exception
idt_inval_tss:
	push	10
	jmp exception
idt_seg_present:
	push	11
	jmp exception
idt_stack:
	push	12
	jmp exception
idt_gp:
	push	13
	jmp exception
idt_page_fault:
	push	14
	jmp exception
idt_copr_err:
	push	0xFFFFFFFF
	push	16
	jmp	exception
exception:
	call exception_handler
	add esp, 8
	mov ebx, 1
	iret
	hlt


