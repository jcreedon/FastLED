=New platform porting guide=

== Setting up the basic files/folders ==

* Create platform directory (e.g. platforms/arm/k26)
* Create configuration header led_sysdefs_arm_k26.h:
  * Define platform flags (like FASTLED_ARM/FASTLED_TEENSY)
  * Define configuration parameters re: interrupts, or clock doubling
  * Include extar system header files if needed
* Create main platform include, fastled_arm_k26.h
  * Include the various other header files as needed
* Modify led_sysdefs.h to conditionally include platform sysdefs header file
* Modify platforms.h to conditionally include platform fastled header

== Porting fastpin.h ==

The heart of the FastLED library is the fast pin accesss.  This is a templated class that provides 1-2 cycle pin access, bypassing digital write and other such things.  As such, this will usually be the first bit of the library that you will want to port when moving to a new platform.  Once you have FastPIN up and running then you can do some basic work like testing toggles or running bit-bang'd SPI output.

There's two low level FastPin classes.  There's the base FastPIN template class, and then there is FastPinBB which is for bit-banded access on those MCUs that support bitbanding.  Note that the bitband class is optional and primarily useful in the implementation of other functionality internal to the platform.  This file is also where you would do the pin to port/bit mapping defines.

Explaining how the macros work and should be used is currently beyond the scope of this document.

== Porting fastspi.h ==

This is where you define the low level interface to the hardware SPI system (including a writePixels method that does a bunch of housekeeping for writing led data)