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
//
//void main(void) {
//	//call your initialisation functions to set up the hardware modules
//    Comp1_init(); //initialises the comparator
//    Interrupts_init();
//    //LEDarray_init();
//    TRISDbits.TRISD7 = 0;//Sets the pin to be an output pin
//    LATDbits.LATD7 = 1; //Sets the initial output
//    while (1) {
//		Sleep();
//            
//        }
//}

//Exercise 2

void main(void){
    Timer0_init(); //initialises the timer module
    LEDarray_init(); //initialises the LED array
    while(1){
        //int time = TMR0L;
        LEDarray_disp_bin(get16bitTMR0val());
    }
}