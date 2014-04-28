; nasm -f elf hello.asm -o hello.o
; ld -m elf_i386 -s -o hello hello.o
; g++ -m32 -c hello.cpp

;nasm -f elf hello.asm -o hello.o
;gcc -m32 elf_i386 -c choose.c -o choose.o
;ld -m elf_i386 -s hello.o choose.o -o foobar
extern choose
[section .data]
number1		dd 		2
number2		dd		4

[section .text]
global _start
global myprint

_start:
	push dword [number1]
	push dword [number2]
	call choose
	add esp, 8
	mov ebx, 0
	mov eax, 1
	int 0x80

; myprint(char* msg,int len)
myprint:
	mov edx, [esp + 8]
	mov ecx, [esp + 4]
	mov ebx, 1
	mov eax, 4
	int 0x80
	ret

