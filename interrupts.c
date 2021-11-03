#include <xc.h>
#include "interrupts.h"

/************************************
 * Function to turn on interrupts and set if priority is used
 * Note you also need to enable peripheral interrupts in the INTCON register to use CM1IE.
************************************/
void Interrupts_init(void)
{
    
    PIE0bits.INT0IE=1; 	//enable interrupt source INT0
    PIE2bits.C1IE=1;    // enables comparator interrupt
    INTCONbits.GIE=1; 	//turn on interrupts globally (when this is off, all interrupts are deactivated)
    INTCONbits.IPEN=1;  //enables interrupt priority feature
    PIE0bits.TMR0IE =1; //enable the timer interrupt
    IPR0bits.TMR0IP=1;
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
	LATDbits.LATD7 = 1;
	PIR2bits.C1IF=0; 						//clear the interrupt flag!
	__delay_ms(500);
    LATDbits.LATD7 = 0;
    }	
    //add your ISR code here i.e. check the flag, do something (i.e. toggle an LED), clear the flag...
    if(PIR0bits.TMR0IF){
        LATHbits.LATH3 = !LATHbits.LATH3;//changes the value of the right LED
        PIR0bits.TMR0IF=0; //Resets the flag
    }
    
    //HOW DO I GET THE INTERRUPT TO WORK ABOVE
}



