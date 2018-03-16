/*******************************************************
*                                                      *
*   Criado em: Sáb 11/Jun/2016,  13:48 hs              *
*   Instituicao: Universidade Federal do Ceará         *
*   Autor: Robert Cabral                               *
*   email: robertcabral@alu.ufc.br                     *
*                                                      *
********************************************************/
#include "gpioFunctions.h"
#include "gpioLED.h"
#include "LCD.h"
#define MSEG                           (0x3FFFFFF)

//static void Delay(volatile unsigned int count);

int main(){

	initLCD();
	setLine(5,1);
	writeLCD("Te amo");
	setLine(7,2);
	writeLCD("<3");

	return(0);

}

/*static void Delay(volatile unsigned int count){
    while(count--);
      asm("   nop");
}*/

