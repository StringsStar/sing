#ifndef	_KERNEL_H
#define _KERNEL_H

#define GDT_SIZE 128
#define IDT_SIZE 256

//variables From start.c
EXTERN u8 gdt_ptr[6];
EXTERN DESCRIPTOR gdt[GDT_SIZE];
EXTERN u8 idt_ptr[6];
EXTERN GATE idt[IDT_SIZE];

#endif
