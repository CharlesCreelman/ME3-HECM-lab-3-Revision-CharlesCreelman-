#include <xc.h>
#include "timers.h"
#include "interrupts.h"
/************************************
 * Function to set up timer 0
************************************/
void Timer0_init(void)
{
    T0CON1bits.T0CS=0b010; // Fosc/4 selecting the clocks source for the timer
    T0CON1bits.T0ASYNC=1; // see datasheet errata - needed to ensure correct operation when Fosc/4 used as clock source
    T0CON0bits.T016BIT=1;	//16bit mode	
    T0CON1bits.T0CKPS=0b1000; // 1:256
    T0CON0bits.T0OUTPS=0b1111; //setting the output postscaler (divider) 1:1
	//This postscaler above doesn't seem to be making any difference whatsoever

    // it's a good idea to initialise the timer registers so we know we are at 0
    TMR0H=0b111111111;            //write High reg first, update happens when low reg is written to
    TMR0L=0b000000000;
    T0CON0bits.T0EN=1;	//start the timer
}

/************************************
 * Function to return the full 16bit timer value
 * Note TMR0L and TMR0H must be read in the correct order, or TMR0H will not contain the correct value
************************************/
unsigned int get16bitTMR0val(void)
{
    unsigned int count; // initialises the unsigned count that will receive the TMR0L/H values
    
    /*Takes the values stored in the 8 least significant bits and adds it with 
     * the 8 most significant bits(needs to be left shifted by 8 bits)*/  
    count = TMR0L + (TMR0H << 8);
    //NOT SURE WHY THIS WORK!!!
    return (count>>8);
	//right shift the count by 8 bits to return the 8 most significant bits
	//add your code to get the full 16 bit timer value here
}
