%include "cpu.inc"

org 0x100
	jmp L_BEGIN

[SECTION .gdt]
L_GDT:				Descriptor	0,	0,				0
L_DST_NORMAL:		Descriptor	0,	0ffffh,			DA_DRW
L_DST_CODE32:		Descriptor	0,	SegCode32Len-1,	DA_C+DA_32				
L_DST_16GATE:		Descriptor	0,	0ffffh,			DA_C
L_DST_DATA:			Descriptor	0,	SegDateLen-1,	DA_DRW
L_DST_VIDEO:		Descriptor	0xB8000,	0xffff,	DA_DRW + DA_DPL3
L_DST_CALL_CODE:	Descriptor	0,	SegCallCodeLen-1, DA_C+DA_32
L_DST_LDT:			Descriptor	0,	LdtLen-1,		DA_LDT
L_DST_RING3:		Descriptor	0,	SegCodeRing3Len-1, DA_C+DA_32+DA_DPL3
L_DST_STACK3:		Descriptor	0,	TopOfStack3,	DA_DRWA+DA_32+DA_DPL3
L_DST_TSS:			Descriptor	0,	TSSLen-1,		DA_386TSS
L_DST_STACK:		Descriptor	0,	TopOfStack,		DA_DRWA+DA_32
L_CALL_CODE:	Gate	SelCallCode,	0,	0,	DA_386CGate+DA_DPL3

GdtLen	equ	$-L_GDT
GdtPtr	dw	GdtLen-1
		dd	0

; GDT Selector
SelNormal		equ L_DST_NORMAL - L_GDT
SelCode32		equ	L_DST_CODE32 - L_GDT
Sel16Gate		equ L_DST_16GATE - L_GDT
SelVideo		equ	L_DST_VIDEO - L_GDT
SelData			equ	L_DST_DATA - L_GDT
SelCallCode		equ	L_DST_CALL_CODE- L_GDT + SA_RPL3
SelLdt			equ	L_DST_LDT - L_GDT
SelCodeRing3	equ	L_DST_RING3 - L_GDT + SA_RPL3
SelStack3		equ L_DST_STACK3 - L_GDT + SA_RPL3
SelTss			equ	L_DST_TSS - L_GDT
SelStack		equ L_DST_STACK - L_GDT

[SECTION .data]
L_SEG_DATA:
SPValueInRealMode	dw	0
dwDispPos			dd	1920
SegDateLen	equ $ - L_SEG_DATA

[SECTION .stack]
L_STACK:
	times 1024 db 0
TopOfStack equ $-L_STACK-1

[SECTION .s16]
[BITS 16]
L_BEGIN:
	mov	ax, cs
	mov ds, ax
	mov es, ax
	mov ss, ax
	mov sp, 0x100
	
	mov ax, cs
	mov [L_GO_TO_REAL +3],ax
	mov [SPValueInRealMode], sp
	;
	push L_STACK
	push L_DST_STACK
	call FUNC_SGDT
	add sp,4

	push L_STACK3
	push L_DST_STACK3
	call FUNC_SGDT
	add sp,4

	call LABEL_TSS
	push L_DST_TSS
	call FUNC_SGDT
	add sp,4
	;Ring 3
	push L_CODE_RING3
	push L_DST_RING3
	call FUNC_SGDT
	add sp,4

	push L_STACK3
	push L_DST_STACK3
	call FUNC_SGDT
	add sp,4

	;Load LDT
	push LDT_START	
	push L_DST_LDT
	call FUNC_SGDT
	add sp, 4

	push L_CODE_A 
	push LDT_DST_CODEA
	call FUNC_SGDT
	add sp, 4

	;Data
	push L_SEG_DATA
	push L_DST_DATA
	call FUNC_SGDT
	add sp, 4

	;Code 32
	push L_SEG_CODE32
	push L_DST_CODE32
	call FUNC_SGDT
	add sp, 4

	;Code Call
	push L_SEG_CALLCODE
	push L_DST_CALL_CODE
	call FUNC_SGDT
	add sp, 4

	;16Gate
	push L_SEG_16GATE
	push L_DST_16GATE
	call FUNC_SGDT
	add sp, 4

	;Prepare Gdt
	mov ax, cs
	movzx eax, ax
	shl eax, 4
	add eax, L_GDT
	mov dword [GdtPtr+2],eax

	;Load Gdt
	lgdt [GdtPtr]

	cli

	in al, 92h
	or al, 10b
	out 92h, al

	mov eax, cr0
	or eax, 1
	mov cr0, eax

	;;;;;;;;;;;;;;;;;;
	jmp dword SelCode32:0

;;;;;;;;;;;;;;;;;;;;;
;从保护模式跳转回这里
L_REAL_ENTRY:
	mov ax, cs
	mov ds, ax
	mov es, ax
	mov ss, ax
	
	mov sp , [SPValueInRealMode]

	in al, 92h
	and al, 11111101b
	out 92h, al

	sti
	mov ax, 4c00h
	int 21h

;sp+2地址 sp+4要设置的
FUNC_SGDT:
	push bp
	mov bp, sp
	push eax
	push ebx
	xor eax, eax
	mov ax, [bp+4]
	movzx eax, ax

	mov bx, cs
	movzx ebx,bx
	shl ebx, 4
	add bx, word [bp+6]

	mov word [eax+2], bx
	shr ebx, 16	
	mov byte [eax+4], bl
	mov byte [eax+7], bh

	pop ebx
	pop eax
	mov sp, bp
	pop bp
	ret

;跳转回16位模式的中间门
[SECTION .s16gate]
[BITs 16]
L_SEG_16GATE:
	mov ax, SelNormal
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax

	mov eax, cr0
	and al, 11111110b
	mov cr0, eax

L_GO_TO_REAL:
	jmp 0:L_REAL_ENTRY

Code16GateLen	equ	$ - L_SEG_16GATE

;32位保护模式
[SECTION .s32]
[BITS 32]
L_SEG_CODE32:
	mov	ax, SelVideo
	mov	gs, ax			; 视频段选择子(目的)

	mov	ah, 0Ch			; 0000: 黑底    1100: 红字
	mov	al, 'P'
	mov	[gs:(80*10+0)*2], ax


	mov ax, SelTss
	ltr ax
	;Test Jump To Ring3 here
	push SelStack3
	push TopOfStack3
	push SelCodeRing3
	push 0
	retf 
	;Test end here ..............

	call SelCallCode:0

	mov ax, SelLdt
	lldt ax
	call SelLdtCodeA:0
	jmp	Sel16Gate:0
SegCode32Len	equ	$ - L_SEG_CODE32

[SECTION .stest]
[BITS 32]
L_SEG_CALLCODE:
	mov ax, SelVideo
	mov gs, ax
	mov ah, 0Ch
	mov al, 'S'
	mov [gs:(80*11+0)*2], ax
	retf		;retf=pop cs ip   ret=pop ip
SegCallCodeLen	equ $ - L_SEG_CALLCODE

[SECTION .ldt]
LDT_START:
LDT_DST_CODEA:	Descriptor	0,	CodeALen-1,	DA_C+DA_32

LdtLen	equ	$-LDT_DST_CODEA
SelLdtCodeA	equ	LDT_DST_CODEA-LDT_START + SA_TIL

[SECTION .ca]
[BITS 32]
L_CODE_A:
	mov ax, SelVideo
	mov gs, ax
	mov ah, 0Ch
	mov al, 'L'
	mov [gs:(80*12+0)*2], ax
	retf
	jmp Sel16Gate:0
CodeALen	equ $-L_CODE_A

;;;test For Ring3
[SECTION .ring3]
L_CODE_RING3:
	mov ax, SelVideo
	mov gs, ax
	mov ah, 0Ch
	mov al, '3'
	mov [gs:(80*13+0)*2], ax
	jmp $
	;Test Call Gate
	call SelCallCode:0
	jmp $
SegCodeRing3Len	equ	$-L_CODE_RING3	

[SECTION .sp3]
L_STACK3:
	times 1024 db 0
TopOfStack3	equ	$-L_STACK3 -1

[SECTION .tss]
LABEL_TSS:
		DD	0			; Back
		DD	TopOfStack		; 0 级堆栈
		DD	SelStack			; 
		DD	0			; 1 级堆栈
		DD	0			; 
		DD	0			; 2 级堆栈
		DD	0			; 
		DD	0			; CR3
		DD	0			; EIP
		DD	0			; EFLAGS
		DD	0			; EAX
		DD	0			; ECX
		DD	0			; EDX
		DD	0			; EBX
		DD	0			; ESP
		DD	0			; EBP
		DD	0			; ESI
		DD	0			; EDI
		DD	0			; ES
		DD	0			; CS
		DD	0			; SS
		DD	0			; DS
		DD	0			; FS
		DD	0			; GS
		DD	0			; LDT
		DW	0			; 调试陷阱标志
		DW	$ - LABEL_TSS + 2	; I/O位图基址
		DB	0ffh			; I/O位图结束标志
TSSLen		equ	$ - LABEL_TSS

