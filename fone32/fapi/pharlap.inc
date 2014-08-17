; f/One32 32-bit DOS Extender (c) ACP 2014
; pharlap.inc: compatybility module for Phar Lap 386 and TNT extender plus other extenders

check_dosx_any:
	call check_dosx_generic
	jnc .dosxfound
	call check_dosx_pharlap
	jnc .dosxfound
	call check_dosx_ai
	jnc .dosxfound
	call check_dosx_dpmiload
	jnc .dosxfound
	call check_dosx_rtm
	jnc .dosxfound
	call check_dosx_dos16m
	jnc .dosxfound

.dosxfound:
	ret

check_dosx_generic:
	;this is generic check suppsedly supported by Pharl Ral, Rational, Ergo and IGC
	mov ax,0f100h
	int 2fh
	cmp al,0ffh
	jnz .notfound
	cmp si,444fh	;DO
	jne .notfound
	cmp di,5358h	;SX
	jne .notfound
	xor ax,ax
	clc
	ret
.notfound:
	mov ax,1
	stc
	ret


check_dosx_ai:
	mov ah,2bh
	mov cx,4149h	;AI
	mov dx,413fh	;A?
	int 21h
	cmp al,0ffh
	je .no
	xor ax,ax
	clc
	ret
.no:
	mov ax,1
	stc
	ret


check_dosx_dpmiload:
	mov ax,0fb42h
	mov bx,0014h
	mov cx,0001h
	int 2fh
	test bx,bx
	jz .found
	mov ax,1
	stc
	ret
.found:
	xor ax,ax
	clc
	ret

check_dosx_rtm:
	mov ax,0fb42h
	mov bx,1001h
	int 2fh
	test bx,bx
	jz .found
	mov ax,1
	stc
	ret
.found:
	xor ax,ax
	clc
	ret

check_dosx_dos16m:
	mov ax,0bf02h
	xor dx,dx
	int 15h
	test dx,dx
	jz .notfound
	xor ax,ax
	clc
	ret
.notfound:
	mov ax,1
	stc
	ret

PHARLAP_DOSX_ID_TABLE	db 01h
			db 02h
			db 03h
			db 04h
PHARLAP_DOSX_ID_TABLE_END:

check_dosx_pharlap:
	mov cx, PHARLAP_DOSX_ID_TABLE_END - PHARLAP_DOSX_ID_TABLE
	mov si,PHARLAP_DOSX_ID_TABLE
	cld
@@:
	push cx
	lodsb
	push si
	mov bl,al
	mov ax,0ed00h
	int 2fh
	cmp al,0ffh
	jz .found
	pop si
	pop cx
	loop @b
.notfound:
	mov ax,1
	stc
	ret

.found:

	pop ax		;This should be done with ret n
	pop ax
	cmp bx,5048h	;PH
	jne .notfound
	cmp bx,4152h	;AR
	jne .notfound
	xor ax,ax
	clc
	ret
