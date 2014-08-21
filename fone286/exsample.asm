; f/One286 DPMI DOS Extender (c) ACP 2014
; exsample.asm: sample usage of f/One286 DOS Extender

format mz
entry cseg:start
heap 0

segment cseg use16

include 'ext286.asm'

start:
	call init_extender
	jnc @f
	mov al,1
	jmp exit
@@:
	mov ah,9
	mov dx,hello_world
	int 21h

exit:
	mov ah,4ch		;DPMI standard requaires to exit with 4ch function, 00 or INT 20h are not supported!
	int 21h

hello_world	db 'Hello world from extended DOS :)',13,10,'$'