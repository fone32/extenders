; f/One286 DPMI DOS Extender (c) ACP 2014
; ext286.asm: main include file (stub) for 16-bit DPMI based extended DOS MZ exe

use16

include 'dpmi286c.inc'

init_extender:
	push cs
	pop ds
	;push cs
	;pop es
	call _extender
	jnc @f
	pop bx
	call ..extender_critical_error
.exterror_msg	 db 13,10, ' f/One286 DOS Extender Runtime failed to run.',13,10,'$'

@@:
	xor ax,ax
	ret

..extender_critical_error:
	push ax
	pop dx
	push bx
	mov ah,9
	int 21h
	pop ax
	cmp ax,6	;return code below 6 are from real mode
	jae @f
	stc
	ret
@@:			;since we failed after switch to PM we end up
			;according to DPMI spec with Int 21h 4c
	mov ah,4ch
	int 21h

