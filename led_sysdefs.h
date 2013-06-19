#ifndef __INC_LED_SYSDEFS_H
#define __INC_LED_SYSDEFS_H

#ifndef __SAM3X8E__
#include <avr/io.h> 
#include <avr/interrupt.h> // for cli/se definitions

// Define the rgister types
#if defined(ARDUINO) && ARDUINO < 150
typedef volatile       uint8_t RoReg; /**< Read only 8-bit register (volatile const unsigned int) */
typedef volatile       uint8_t RwReg; /**< Read-Write 8-bit register (volatile unsigned int) */
#endif

#else
// reuseing/abusing cli/sei defs for due
#define cli()  __disable_irq()
#define sei() __enable_irq()

#endif

#if defined(__MK20DX128__) || defined(__SAM3X8E__) 
#define FASTLED_ARM
#else
#define FASTLED_AVR
#endif

// Arduino.h needed for convinience functions digitalPinToPort/BitMask/portOutputRegister and the pinMode methods.
#include<Arduino.h>

#endif