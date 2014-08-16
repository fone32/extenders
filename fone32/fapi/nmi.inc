; f/One32 32-bit DOS Extender (c) ACP 2014
; nmi.inc: handles NMI enabling & disabling operation from real mode

NMI_DISABLE macro {
	    in al,70h
	    or al,80h
	    out 70h,al
}

NMI_ENABLE macro {
	   in al,70h
	   and al,7fh
	   out 70h,al
}
