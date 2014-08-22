; f/One286 and f/One32 DPMI DOS Extender (c) ACP 2014
; dpmiregs.inc: contains data structure for storing registers when simulating real mode int

label dpmi_regs word
label dpmi_di
dpmi_edi	dd 0  ;00h
label dpmi_si
dpmi_esi	dd 0  ;04h
label dpmi_bp
dpmi_ebp	dd 0  ;08h
dpmi_reseved	dd 0  ;0ch
label dpmi_bx
dpmi_ebx	dd 0  ;10h
label dpmi_dx
dpmi_edx	dd 0  ;14h
label dpmi_cx
dpmi_ecx	dd 0  ;18h
label dpmi_ax
dpmi_eax	dd 0  ;1ch
dpmi_flags	dw 0  ;20h
dpmi_es 	dw 0  ;22h
dpmi_ds 	dw 0  ;24h
dpmi_fs 	dw 0  ;26h
dpmi_gs 	dw 0  ;28h
dpmi_ip 	dw 0  ;2ah
dpmi_cs 	dw 0  ;2ch
dpmi_sp 	dw 0  ;2eh
dpmi_ss 	dw 0  ;30h