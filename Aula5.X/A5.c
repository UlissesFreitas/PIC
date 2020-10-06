/*
 * File:   A5.c
 * Author: ulisses
 *
 * Created on 12 de Dezembro de 2019, 13:37
 */


#include <xc.h>
#include <PIC12f675.h>

#define _XTAL_FREQ 16000000


void main(void) {
    ANSEL = 0;
    CMCON = 7;
    
    TRISIObits.TRISIO0 = 0;
    TRISIObits.TRISIO1 = 0;
    
    
    while(1){
        GPIObits.GP0 = 1;
        __delay_ms(10);
        GPIObits.GP0 = 0;
        __delay_ms(10);
        
        GPIObits.GP1 = 1;
        __delay_ms(1);
        GPIObits.GP1 = 0;
        __delay_ms(1);
        
    }
    return;
}
