/*
 * File:   A6.c
 * Author: ulisses
 *
 * Created on 12 de Dezembro de 2019, 14:00
 */


#include <xc.h>
#include <PIC12f675.h>

#define _XTAL_FREQ 4000000
#define S1 GPIObits.GP0
#define S2 GPIObits.GP1
#define D1 GPIObits.GP4
#define D2 GPIObits.GP5

#pragma config FOSC = INTRCIO   // Oscillator Selection bits (INTOSC oscillator: I/O function on GP4/OSC2/CLKOUT pin, I/O function on GP5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-Up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // GP3/MCLR pin function select (GP3/MCLR pin function is digital I/O, MCLR internally tied to VDD)
#pragma config BOREN = OFF      // Brown-out Detect Enable bit (BOD disabled)
#pragma config CP = OFF         // Code Protection bit (Program Memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)


void main(void) {
    ANSEL = 0;
    CMCON = 7;

    TRISIObits.TRISIO0 = 1;
    TRISIObits.TRISIO1 = 1;
    TRISIObits.TRISIO4 = 0;
    TRISIObits.TRISIO5 = 0;
    
    S1 = 1;
    S2 = 1;
    D1 = 0;
    D2 = 0;
    
    while(1){
        if (S1 == 0){
            D1 = ~D1;
           __delay_ms(300);
        }
        if(S2 == 0){
            D2 = ~D2;
            __delay_ms(300);
        }
        
    }
    
    return;
}
