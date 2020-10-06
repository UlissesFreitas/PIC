/*
 * File:   A9.c
 * Author: ulisses
 *
 * Created on 13 de Dezembro de 2019, 10:31
 */

#include <stdlib.h>
#include <xc.h>
#include <PIC16f628A.h>

#define _XTAL_FREQ 4000000

#define S1 PORTAbits.RA0
#define S2 PORTAbits.RA1
#define led1 PORTAbits.RA2
#define led2 PORTAbits.RA3

#pragma config FOSC = EXTRCCLK  
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config MCLRE = ON
#pragma config BOREN = ON
#pragma config LVP = ON
#pragma config CPD = OFF
#pragma config CP = OFF

int numbers;

void main(void) {
    CMCON = 7; // desabilitar os comparadores
    
    TRISA = 3; // S1 e S2 sao entrada digital 
    TRISB = 0;
    
    PORTA = 3;
    PORTB = 0;
    
    while(1){
        numbers = rand();  
        led1 = numbers;
        led2 = ~led2;
        
        while(led1){
            if(S1 == 0) 
                led1 = 0;
            
            __delay_ms(70);
            
        }
        
        while(led2){
            if(S2 == 0) 
                led2 = 0;
            
            __delay_ms(70);
            
        }        
        
        __delay_ms(500);
    }


    return;
}
