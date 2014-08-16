; f/One32 32-bit DOS Extender (c) ACP 2014
; macros.inc: general macros

macro IODELAY {
	jmp $+2
	jmp $+2
}

macro LONG_IODELAY {
       IODELAY
       IODELAY
}
