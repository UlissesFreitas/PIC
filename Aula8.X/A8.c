/*
 * File:   A8.c
 * Author: ulisses
 *
 * Created on 12 de Dezembro de 2019, 18:26
 * 
 * PARADOXUS 9
 */


#include <xc.h>
#include <PIC16f628A.h>

#define _XTAL_FREQ 4000000
#define S1 PORTAbits.RA0
#define S2 PORTAbits.RA1
#define D1 PORTAbits.RA2
#define D2 PORTAbits.RA3

#pragma config FOSC = INTOSCIO  // Oscillator Selection bits (INTOSC oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is digital input, MCLR internally tied to VDD)
#pragma config BOREN = ON       // Brown-out Detect Enable bit (BOD enabled)
#pragma config LVP = ON         // Low-Voltage Programming Enable bit (RB4/PGM pin has PGM function, low-voltage programming enabled)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)


void main(void) {
    CMCON = 7;
    TRISA = 3; // 0b00000011
    PORTA = 3;
    
    while(1){
        if(S1 ==0){
            while(1){
                D1 = 1;
                D2 = 0;
                __delay_ms(500);
                D1 = 0;
                D2 = 1;
                __delay_ms(500);
            }
        }
        if(S2 ==0){
            while(1){
                D1 = 1;
                D2 = 1;
                __delay_ms(500);
                D1 = 0;
                D2 = 0;
                __delay_ms(500);
            }        
        }
    }
    return;
}
