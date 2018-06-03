/*
 * File:   main.c
 * Author: ivan-
 *
 * Created on 28 de mayo de 2018, 12:36 AM
 */


#include "config.h"
void setup(){
    TRISD = 0x00;
    TRISC = 0b00111100;
    ADCON0 = 0b00000001;
    ADCON1 = 0b00001110;
    ADCON2 = 0b00111111; 
    LATC = 0x7F;
}
void main(void) {
    setup();
    unsigned char var;
    for(;;){
        ADCON0bits.GO = 1;
        while(!ADCON0bits.GO);
        var = ADRESH;
        if(var< 51)
            LATD = 0xC0;
        else if(var< 102)
            LATD = 0xF9;
        else if(var< 153)
            LATD = 0xA4;
        else if(var< 204)
            LATD = 0xB0;
        else if(var< 250)
            LATD = 0x99;
        else
            LATD = 0x92; 
    }   
}