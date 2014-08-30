f/One286 README
===============

f/One286 is a 16-bit DPMI based DOS Extender for application developed using [flat assembler](http://flatassembler.net) ([FASM](http://flatassembler.net)). 

Why another extender?
=====================

Besides most famous ones like DOS16M, DOS4G, Phar Lap 386 and TNT, WDOSX, D3X, DOS32A, PMODE, DosWin32 – not to mention still supported and developed HX - there are endless number of DOS extenders available. Why write another one?
f/One286 contrary to most mentioned above is 16 not 32 bit extender. Secondly it targets modern DOS emulation environments like DosBOX. Last but not least f/One286 has been developed as aid for writing 16 bit protected mode DOS programs using FASM. To make this task as easy as possible f/One286 has been developed entirely using FASM. As a advantage to using assembly language f/One286 is small and can be bided at source level with you FASM 16 bit protected mode DOS project.

FASM comes without own DOS extender so developers must rely on 3rd party products.  It is known that FASM applications can be extended successfully with [HX](http://www.japheth.de/HX.html), [WDOSX](http://tippach.business.t-online.de/wdosx/), [PMODE](http://www.sid6581.net/pmodew/) extenders for example. There are some DOS extenders that are trying to target FASM like [D3XX](http://board.flatassembler.net/topic.php?t=14416) but I could not find a DOS extender that has been implemented in FASM and target applications developed using FASM. f/One extenders tries to fill this gap.    


Why FASM?
=========

Flat assembler ([FASM](http://flatassembler.net)) is great x86/x64 freeware, open source assembler written in assembly language, one of few constantly being developed and supported. FASM has been designed in writing own operating system in mind and has great flexibility plus set of features enabling quick programming, especially for simple platforms like DOS. By default FASM supports both DOS COM and EXE file formats and enables usage of 32 bit instruction. Segment management is quite flexible. It supports most of features that can be find in MASM and TASM assemblers but is using syntax based, but not entirely compatible with TASM Ideal mode.

From perspective of 16-bit DOS extended applications the only possible drawback is lack of NE and LE file format support by default. Nevertheless using binary option it is possible to produce legal files of those formats. 

Besides Windows and Linux FASM is also available under DOS which makes it even better tool for creating DOS applications. 

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

