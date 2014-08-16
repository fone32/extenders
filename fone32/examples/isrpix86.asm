; Simple exmaple of detecting rpix86 emulator

format mz
entry cseg:start

segment cseg use16

include 'rpix86.inc'

start:
	mov ax,cs
	mov ds,ax

	call check_rpix86
	jnc @f
	mov dx,norpix86_msg
	jmp finish
@@:
	mov dx,rpix86found_msg
finish:
	mov ah,9
	int 21h
	mov ax,4c00h
	int 21h

rpix86found_msg db 'Running in rpix86 emulator.',13,10,'$'
norpix86_msg	db 'No rpix86 emulator found.',13,10,'$'
