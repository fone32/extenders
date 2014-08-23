; f/One286 and f/One32 DPMI DOS Extender (c) ACP 2014
; dpmiregs.inc: contains data structure for storing registers when simulating real mode int

label dpmiregs word
label dpmireg_di
dpmireg_edi	   dd 0  ;00h
label dpmireg_si
dpmireg_esi	   dd 0  ;04h
label dpmireg_bp
dpmireg_ebp	   dd 0  ;08h
dpmireg_reseved    dd 0  ;0ch
label dpmireg_bx
dpmireg_ebx	   dd 0  ;10h
label dpmireg_dx
dpmireg_edx	   dd 0  ;14h
label dpmireg_cx
dpmireg_ecx	   dd 0  ;18h
label dpmireg_ax
dpmireg_eax	   dd 0  ;1ch
dpmireg_flags	   dw 0  ;20h
dpmireg_es	   dw 0  ;22h
dpmireg_ds	   dw 0  ;24h
dpmireg_fs	   dw 0  ;26h
dpmireg_gs	   dw 0  ;28h
dpmireg_ip	   dw 0  ;2ah
dpmireg_cs	   dw 0  ;2ch
dpmireg_sp	   dw 0  ;2eh
dpmireg_ss	   dw 0  ;30h