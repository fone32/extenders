The f/One API
=============

The f/One API (FAPI) architecture is quite simple. It has been designed to allow easy use of f/One32 extender by the programmer, enable its further development and produce clean and short output code.
The f/One API is implemented only in f/One32 extender. f/One286 uses only certain constants for conditional assembly but it does not provide FAPI due to 286 CPU and 16 bit DPMI constrains.  

The architecture
----------------

FAPI is built around 3 blocks:
 * FAPI constants that controls conditional assembly of extender code, all of those constants are defined in FAPICTRL.INC file 
 * FAPI procedures that can be used either from f/One32 extender environment or directly by the programmer by including whole or certain part of FAPI in his own project
 * FAPI Interface handler available on INT 2Fh

FAPICTRL.INC
------------

FAPICTRL.INC controls assembly process of f/One32 extender  therefore it controls its behavior and functionality. If FAPICTRL.INC is missing from your f/One32 extender project than f/One32 assumes default values for all FAPI constants.  Therefore it is not obligatory to include FAPICTRL.INC file in your project to be able to compile f/One32 extender successfully.
Remember: FAPICTRL.INC must be included before you include FAPI.INC in your project.

FAPI.INC
--------

FAPI.INC is main include file to enable FAPI.INC usage in your dos extender application. 

FAPI constants and FAPICTRL
---------------------------

Alphabetic list of FAPICTRL constants 
 * FC_DESQVIEWCOMPAT
 * FC_EMULDOSBOX
 * FC_EMULRPIX86
 * FC_ENABLE_SSE
 * FC_FAST_A20
 * FC_FASTCPUDETECTION
 * FC_INT2FINTERFACE
 * FC_LINUX
 * FC_OS2COMPAT
 * FC_VCPIFIRST
 * FC_WIN30COMPAT
 * FC_WIN32
 * FC_WIN32COMPAT
 * FC_WIN9xCOMPAT
 * FC_WINNTCOMPAT
