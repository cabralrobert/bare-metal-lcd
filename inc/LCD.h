/*******************************************************
*                                                      *
*   Criado em: qui 23/mar/2017,  11:01 hs              *
*   Instituicao: Universidade Federal do Ceará         *
*   Autor: Robert Cabral                               *
*   email: robertcabral@alu.ufc.br                     *
*                                                      *
********************************************************/
#ifndef LCD_H
#define LCD_H

void setaBit(int GPIOModule, int nGpio);
void baixaBit(int GPIOModule, int nGpio);
void toggleE();
void baixaTudo();
void initPins();
void sendData(int *dados);
int pins[8], i;
void sendCMD(int cmd);
void writeChar(char a);
void writeLCD(char *a);
void setLine(int a, int b);
 void initLCD();

#endif
