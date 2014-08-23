f/One286 README
===============

f/One286 is a 16-bit DPMI based DOS Extender for application developed using flat assembler (FASM). 

Why another extender?
=====================

Besides most famous ones like DOS16M, DOS4G, Phar Lap 386 and TNT, WDOSX, D3X, DOS32A, PMODE, Dos32Win – not to mention still supported and developed HX - there are endless number of DOS extenders available. Why write another one?
f/One286 contrary to most mentioned above is 16 not 32 bit extender. Secondly it targets modern DOS emulation environments like DosBOX. Last but not least f/One286 has been developed as aid for writing 16 bit protected mode DOS programs using FASM. To make this task as easy as possible f/One286 has been developed entirely using FASM. As a advantage to using assembly language f/One286 is small and can be bided at source level with you FASM 16 bit protected mode DOS project.

f/One286 requirements
=====================

f/One286 requires:
 * 286 or higher CPU, 
 * DPMI host supporting 16-bit protected mode (CSWDPMI does not support it but HXDPMI does for example) 
 * XMS memory (in DosBOX set xms=true)

Using f/One286
==============

Simply include **‘ext286.asm’** at the begging of your code segment in your FASM application source. For reference take a look at **exsample.asm** example. 
Your extended EXE file have to meet few requirements:
 * format MZ
 * use16 (for code segment, internally f/One286 uses use16 keyword as well)
 * heap 0  (if you forget to use it, DOS allocation for DPMI host private data will fail and extender won’t run) 
 * include 'ext286.asm' after you code segment definition (e.g segment cseg use16)

