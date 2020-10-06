/*
 * File:   A3.c
 * Author: ulisses
 *
 * Created on 12 de Dezembro de 2019, 11:27
 */


#include <xc.h>
#include <PIC12f675.h>

#define _XTAL_FREQ 4000000


/* codigo nao funciona pois precisa
 * "desabilitar os fuses" 
 * master clear
 * e colocar o oscilator
 * para internal RC CLOCKOUT
 * 
 * funcionou pq coloquei o
 * circuito master clear
 * no proprio PIC
 */
void main(void) {
    ANSEL = 0;
    CMCON = 7;
    TRISIO = 0b000000;
    GPIO  =  0b000000;
    
    while(1){
        GPIO = 0b000001;
        //GPIO = 0b000011;
        __delay_ms(100);
        GPIO = 0b000010;
        //GPIO = 0b000000;
        __delay_ms(100);
    }
    return;
}
