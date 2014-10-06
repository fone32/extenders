Extenders
=========

This directory contains f/One family of DOS Extenders.

 * f/One286 is a 16-bit DPMI based DOS Extender for 286 CPU
 * f/One32  is a 32-bit DPMI based DOS Extender for 386+ CPU

The f/One32 direcotry besides the extender contains also "[fapi](fone32/doc/fapi.md)"  folder which is API for the DOS Extender and extended applications. Some parts of API can be used directly - like macros.inc, nmi.inc, dosbox.inc - by even real mode 16 bit DOS applications.

Targets
=======

f/One extenders target mainly DOS emulators as well as original MS DOS and FreeDOS machines.
Current emulator support (and testing covers):

 * DosBOX http://www.dosbox.com/
 * rpix86 http://rpix86.patrickaalto.com/

Possible future support include vDosBox and DOSEMU. DOSEMU is providing own DPMI host (something that DosBOX has stopped doing long time ago). Further support for QEMU and Bochs is possible in future.

Target DPMI hosts include:

 * Windows 9x
 * Windows XP
 * Windows NT 4.0
 * Windows 2000
 * DPMIONE
 * HDPMI
 * QDPMI
 * CWSDPMI
 
DPMI v0.9 Specification
=======================
The DOS Protected Mode Interface (DPMI) specification version 0.9 can be found in doc folder for particular extender. Currently DPMI 1.0 is not being used. Please note that for 16-bit extender DPMI server must provide 16-bit DPMI service, some DPMI servers provide only 32-bit interface. Some of mentioned DPMI servers support only 32-bit interface resulting in f/One286 being not able to start. 

  
 
 
