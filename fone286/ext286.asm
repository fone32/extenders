; f/One286 DPMI DOS Extender (c) ACP 2014
; ext286.asm: main include file (stub) for 16-bit DPMI based extended DOS MZ exe

use16


init_extender:
	push cs
	pop ds
	push cs
	pop es
	call _extender
	jnc @f
	pop bx
	call ..critical_error
error_msg    db 'f/One286 DOS Extender Runtime failed to run.',13,10,'$'

@@:
	xor ax,ax
	ret

..critical_error:
	pop dx
	push bx
	mov ah,9
	int 21h
	ret

