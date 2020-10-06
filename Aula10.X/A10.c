/*
 * File:   A10.c
 * Author: ulisses
 *
 * Created on 18 de Dezembro de 2019, 09:52
 */


#include <stdlib.h>
#include <xc.h>
#include <PIC16f628A.h>

#define _XTAL_FREQ 4000000

#define S1 PORTAbits.RA0
#define S2 PORTAbits.RA1
#define led1 PORTAbits.RA2
#define led2 PORTAbits.RA3
#define servo1 PORTBbits.RB0

#pragma config FOSC = EXTRCCLK  
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config MCLRE = ON
#pragma config BOREN = ON
#pragma config LVP = ON
#pragma config CPD = OFF
#pragma config CP = OFF

void servo1_horario();
void servo1_centro();
void servo1_antihorario();

void main(void) {
    CMCON = 7;
    
    TRISA = 0x03;
    TRISB = 0x00;
    
    PORTA = 0x03;
    PORTB = 0x00;
    
    while(1){
        
        if(S1 == 0 && S2 ==1) 
            servo1_horario();
        else if(S1 == 1 && S2 == 0) 
            servo1_antihorario();
        else 
            servo1_centro();
         
    }
    
    return;
}

void servo1_horario(){
    servo1 = 0x00;
    __delay_us(18000);
    servo1 = 0x01;
    __delay_us(2000);
}

void servo1_centro(){
    servo1 = 0x00;
    __delay_us(18500);
    servo1 = 0x01;
    __delay_us(1500);
}

void servo1_antihorario(){
    servo1 = 0x00;
    __delay_us(19000);
    servo1 = 0x01;
    __delay_us(1000);
}
