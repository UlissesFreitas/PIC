/*
 * File:   A7.c
 * Author: ulisses
 *
 * Created on 12 de Dezembro de 2019, 17:59
 */


#include <xc.h>
#include <PIC16f628A.h>

#define _XTAL_FREQ 4000000

int cont = 0xFF;

void main(void) {
    
    
    TRISB = 0;
    PORTB = 0xFF;
    
    while(1){
        PORTB = cont;
        __delay_ms(300);
        cont = cont << 1;
        
        if(cont == 0) cont = 0xFF;
        
    }
    return;
}
