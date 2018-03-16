/*******************************************************
*                                                      *
*   Criado em: qui 23/mar/2017,  10:59 hs              *
*   Instituicao: Universidade Federal do Ceará         *
*   Autor: Robert Cabral                               *
*   email: robertcabral@alu.ufc.br                     *
*                                                      *
********************************************************/
#include "LCD.h"
#include "gpioLED.h"
#include "gpioFunctions.h"

void writeLCD(char *a){

	int i = 0;
	for(;a[i] != '\0';i++)
		writeChar(a[i]);

}

void initLCD(){

	initPins();
	sendCMD(0x80);
	sendCMD(0x30); 
	sendCMD(0x38);
	sendCMD(0xf); 
	
}

void setLine(int a, int b){

	if(b == 2)
		sendCMD(0xC0 + a);
	else
		sendCMD(0x80 + a);

}

void sendCMD(int cmd){

	for(i = 0;i < 8;i++){
		pins[i] = cmd & 0x1;
		cmd = cmd >> 1;
	}	

	sendData(pins);
}

void writeChar(char a){

	setaBit(MODULE1, GPIO12); //RS 

	for(i = 0;i < 8;i++){
		pins[i] = a & 0x1;
		a = a >> 1;
	}	

	sendData(pins);

}

void sendData(int *dados){
	if(dados[D0])setaBit(MODULE1, GPIO14);
	else baixaBit(MODULE1, GPIO14);

	if(dados[D1])setaBit(MODULE2, GPIO1);
	else baixaBit(MODULE2, GPIO1);

	if(dados[D2])setaBit(MODULE1, GPIO29);
	else baixaBit(MODULE1, GPIO29);

	if(dados[D3])setaBit(MODULE1, GPIO13);
	else baixaBit(MODULE1, GPIO13);

	if(dados[D4])setaBit(MODULE1, GPIO15);
	else baixaBit(MODULE1, GPIO15);

	if(dados[D5])setaBit(MODULE0, GPIO27);
	else baixaBit(MODULE0, GPIO27);

	if(dados[D6])setaBit(MODULE3, GPIO21);
	else baixaBit(MODULE3, GPIO21);

	if(dados[D7])setaBit(MODULE3, GPIO19);
	else baixaBit(MODULE3, GPIO19);

	toggleE();
}

void initPins(){

	ledInit(GPIO12, MODULE1);	//RS
	ledInit(GPIO26, MODULE0);	//E
	ledInit(GPIO14, MODULE1);	//D0
	ledInit(GPIO1,  MODULE2);	//D1
	ledInit(GPIO29, MODULE1);	//D2
	ledInit(GPIO13, MODULE1);	//D3
	ledInit(GPIO15, MODULE1);	//D4
	ledInit(GPIO27, MODULE0);	//D5
	ledInit(GPIO21, MODULE3);	//D6
	ledInit(GPIO19, MODULE3);	//D7

}

void baixaTudo(){

	baixaBit(MODULE1, GPIO12);
	baixaBit(MODULE0, GPIO26);
	baixaBit(MODULE1, GPIO14);
	baixaBit(MODULE2, GPIO1);
	baixaBit(MODULE1, GPIO29);
	baixaBit(MODULE1, GPIO13);
	baixaBit(MODULE1, GPIO15);
	baixaBit(MODULE0, GPIO27);
	baixaBit(MODULE3, GPIO21);
	baixaBit(MODULE3, GPIO19);

}

void setaBit(int GPIOModule, int nGpio){
     GPIOPinWrite(GPIO_INSTANCE_ADDRESS(GPIOModule),
           GPIO_INSTANCE_PIN_NUMBER(nGpio),
           PIN_HIGH);	
}

void baixaBit(int GPIOModule, int nGpio){
     GPIOPinWrite(GPIO_INSTANCE_ADDRESS(GPIOModule),
           GPIO_INSTANCE_PIN_NUMBER(nGpio),
           PIN_LOW);	
}

void toggleE(){
	ledToggle(GPIO26, MODULE0);
	ledToggle(GPIO26, MODULE0);
	baixaTudo();
}


