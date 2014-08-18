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
 * FC_DPMICPUDETECT
 * FC_EMULDOSBOX
 * FC_EMULRPIX86
 * FC_ENABLE_SSE
 * FC_FAST_A20
 * FC_FASTCPUDETECTION
 * FC_INT2FINTERFACE
 * FC_LINUX
 * FC_DOSBOXCOMPAT
 * FC_OS2COMPAT
 * FC_RPIX86COMPAT
 * FC_VCPIFIRST
 * FC_WIN30COMPAT
 * FC_WIN32
 * FC_WIN32COMPAT
 * FC_WIN9xCOMPAT
 * FC_WINNTCOMPAT

While all above constants are reserved and cannot be used inside your own code, not all options are implemented.

### General options

#### FC_DPMICPUDETECT

By default f/One32 tries to detect CPU on which is running and based on this test certian features like enabling SSE can be accessible to extender and extender applications. However DPMI also provides it's own detection routine during DPMI host startup and CPU type is being return as part of DPMI check function (INT 2Fh AX=1687h). If you enable this option f/One32 will not try to detect CPU but will relay on CPU type returned by DPMI host.

Default setting: disabled

#### FC_FASTCPUDETECTION
 
f/One32 provides 2 different methods beside DPMI check for detecting CPU type. The main one is quite extenstive and detects CPU from 8086/8088 up to CPUID enabled CPUs. Under some targets - like emulators for example - such extensive check makes no sense. Therefor FC_FASTCPUDETECTION can force f/One32 to run a short detection routine which checks only for 386 CPU. The drawback is that features like SSE will not be enabled during runtime. However most emulators have problems with SSE anyway but hypervisors can provide those features to Virtual Machine under wchich f/One32 is running. 

Default setting: disabled unless FC_EMULRPIX86 has been enabled
