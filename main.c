// CONFIG1L
#pragma config FEXTOSC = HS     // External Oscillator mode Selection bits (HS (crystal oscillator) above 8 MHz; PFM set to high power)
#pragma config RSTOSC = EXTOSC_4PLL// Power-up default value for COSC bits (EXTOSC with 4x PLL, with EXTOSC operating per FEXTOSC bits)

// CONFIG3L
#pragma config WDTE = OFF        // WDT operating mode (WDT enabled regardless of sleep)

#include <xc.h>
#include "LEDarray.h"
#include "interrupts.h"
#include "comparator.h"
#include "timers.h"

#define _XTAL_FREQ 64000000 //note intrinsic _delay function is 62.5ns at 64,000,000Hz  

// Exercise 1

//void main(void) {
//	//call your initialisation functions to set up the hardware modules
//    Interrupts_init();
//    Comp1_init();
//    TRISDbits.TRISD7=0; // This sets the pin to be an output
//    while (1) {
//        
//		Sleep();
//    }
//}

void main(void) {
    Timer0_init();
    LEDarray_init();
    Interrupt_init();
    while(1) {
        //unsigned int counter = T0CON0bits.T0OUT;
        LEDarray_disp_bin(get16bitTMR0val());
    }
}