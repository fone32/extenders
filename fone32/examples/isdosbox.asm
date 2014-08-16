; Simple exmaple of detecting rpix86 emulator

format mz
entry cseg:start

segment cseg use16

include 'dosbox.inc'

start:
	mov ax,cs
	mov ds,ax

	call check_dosbox
	jnc @f
	mov dx,nodosbox_msg
	jmp finish
@@:
	mov dx,dosboxfound_msg
finish:
	mov ah,9
	int 21h
	mov ax,4c00h
	int 21h

dosboxfound_msg db 'Running in DosBOX emulator.',13,10,'$'
nodosbox_msg	db 'No DosBOX emulator found.',13,10,'$'
