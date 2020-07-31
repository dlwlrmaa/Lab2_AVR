/*	Author: jjuan002
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */

    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
 
    unsigned char PAZero = 0x00; //garage door sensor
    unsigned char PAOne = 0x00; //light sensor
    unsigned char PBZero = 0x00; //LED

    while(1){
        PAZero = PINA & 0x01;
        PAOne = PINA & 0x02;
        if(PAZero && !PAOne){
            PBZero = 0x01;
        }
        else{
            PBZero = 0x00;
        }
        PORTB = PBZero;
        PBZero = 0x00; 
    }
    return 1; 

    /* Insert your solution below */
}
