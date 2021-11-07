#include <xc.h>
#include "interrupts.h"

/************************************
 * Function to turn on interrupts and set if priority is used
 * Note you also need to enable peripheral interrupts in the INTCON register to use CM1IE.
************************************/
void Interrupts_init(void)
{
    PIE0bits.INT0IE=1; 	//enable interrupt source INT0
    INTCONbits.IPEN=1;  //enables priority levels on interrupts
    PIE2bits.C1IE=1;  //enables the comparator interrupt
    IPR0bits.INT0IP =1; //sets priority to high priority
    PIR2bits.C1IF =0; //makes sure the flag is set to 0 initially
    INTCONbits.GIE=1; 	//turn on interrupts globally (when this is off, all interrupts are deactivated)
    INTCONbits.PEIE=1;  // Enables all low-priority interrupts and cleared by hardware for low-priority interrupts only - only needed for low priority interrupt use
	// turn on global interrupts, peripheral interrupts and the interrupt source 
	// It's a good idea to turn on global interrupts last, once all other interrupt configuration is done.
}

/************************************
 * High priority interrupt service routine
 * Make sure all enabled interrupts are checked and flags cleared
************************************/
void __interrupt(high_priority) HighISR()
{
    if(PIR2bits.C1IF){ 					//check the interrupt source
        LATDbits.LATD7=!LATDbits.LATD7;     //this toggles the left LED;
        PIR2bits.C1IF=0; 					//clear the interrupt flag!
	}
	//add your ISR code here i.e. check the flag, do something (i.e. toggle an LED), clear the flag...
}

