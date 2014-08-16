; f/One32 32-bit DOS Extender (c) ACP 2014
; dosbox.inc: DosBOX compatybility functions

check_dosbox:
	call check_dosbox1
	jc @f
	ret
@@:
	call check_dosbox2
	ret

check_dosbox1:
	push es
	mov si,dosbox_sig
	mov cx,dosbox_sig_end - dosbox_sig
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

check_dosbox2:
	push es
	mov si,dosbox_sig2
	mov cx,dosbox_sig2_end - dosbox_sig
	mov di,0e061h
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



dosbox_sig	db 14 dup(0)
		db 'IBM COMPATIBLE 486 BIOS COPYRIGHT The DOSBox Team'

dosbox_sig_end:

dosbox_sig2	db 'DOSBox FakeBIOSv'
dosbox_sig2_end:
