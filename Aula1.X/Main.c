/* 
 * File:   Main.c
 * Author: ulisses
 *
 * Created on 10 de Dezembro de 2019, 19:17
 */

#include <stdio.h>
#include <stdlib.h>
#include <PIC16f84A.h>
#include <xc.h>

#define _XTAL_FREQ 4000000

int main(int argc, char** argv) {
    TRISB = 0b00000000;
    PORTB = 0b00000000;
    
    while(1){       
        // Liga o Led
        PORTB = 0b00000001;
        __delay_ms(1000);
        // Desliga o Led
         PORTB = 0b00000000;
        __delay_ms(1000);
    }

    return (EXIT_SUCCESS);
}

