; f/One32 32-bit DOS Extender (c) ACP 2014
; xms.inc: handles XMS2.0 memory allocation (HIMEM.SYS)

check_xms:
	mov ax,4300h
	int 2fh
	cmp al,80h
	jne @f
	push es
	mov ax,4310h
	int 2fh
	mov word [himem_entry],bx
	mov word [himem_entry+2],es
	inc [ishimem]
	pop es
	xor ax,ax
	clc
	ret
@@:
	mov ax,1
	stc
	ret

