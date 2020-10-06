/*
 * File:   Main.c
 * Author: ulisses
 *
 * Created on 12 de Dezembro de 2019, 10:59
 */

#include <PIC16f84A.h>
#include <xc.h>

#define _XTAL_FREQ 8000000

void main(void) {
    // RB     76543210;
    TRISB = 0b00000000;
    PORTB = 0b00000000;
    
    while(1){
        PORTB++;
        __delay_ms(200);
    }
    
    return;
}
