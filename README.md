Extenders
=========

This directory contains f/One family of DOS Extenders.

 * f/One286 is a 16-bit DPMI based DOS Extender for 286 CPU
 * f/One32  is a 32-bit DPMI based DOS Extender for 386+ CPU

The f/One32 direcotry contains "fapi" (f/One API) folder which is API for DOS Extender and extended applications. Some parts of API can be used directly - like macros.inc, nmi.inc, dosbox.inc - by even real mode 16 bit DOS applications.

Targets
=======

f/One extenders target mainly DOS emulators as well as original MS DOS and FreeDOS machines.
Current emulator support (and testing covers):

 * DosBOX http://www.dosbox.com/
 * rpix86 http://rpix86.patrickaalto.com/

Possible future support include vDosBox and DOSEMU. DOSEMU is providing own DPMI host (something that DosBOX has stopped doing long time ago). Further support for QEMU and Bochs is possible.

Target DPMI hosts include:

 * Windows 9x
 * Windows XP
 * Windows NT 4.0
 * Windows 2000
 * DPMIONE
 * HDPMI
 * QDPMI
 * CWSDPMI
 
 
 
 
