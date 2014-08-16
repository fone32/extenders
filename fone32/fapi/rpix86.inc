; f/One32 32-bit DOS Extender (c) ACP 2014
; rpix86.inc: detects rpix86 emulator thanks to Patrick Aalto for suggestions

check_rpix86:
	push es
	mov si,rpix86_sig
	mov cx,rpix86_sig_end - rpix86_sig
	mov di,0e000h
	mov ax,0f000h
	mov es,ax
	cld
	repe cmpsb
	pop es
	jcxz @f
	mov ax,1
	stc
	ret
@@:
	xor ax,ax
	clc
	ret


rpix86_sig	db 'Copyright 2013 Patrick Aalto'
rpix86_sig_end:
