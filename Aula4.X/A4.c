/*
 * File:   A4.c
 * Author: ulisses
 *
 * Created on 12 de Dezembro de 2019, 12:23
 */


#include <xc.h>
#include <PIC12f675.h>

#define _XTAL_FREQ 4000000


void main(void) {
    ANSEL = 0;  
    CMCON = 7;
  
    TRISIObits.TRISIO0 = 1;
    GPIObits.GP0  = 0;
    
    while(1){      //543210 
        if(GPIObits.GP0 == 1){
            //RB =   54321  nao config o RB0 pois é entrada
            GPIObits.GP1 = 1;
            __delay_ms(1000);
        }else{
                   //54321
            GPIObits.GP1 = 0;
            __delay_ms(1000);
        }
        
    }
    return;
}
