//
// Created by bibi on 09.12.2019.
//

#ifndef CPU_CPUHEADER_H
#define CPU_CPUHEADER_H

#include <iostream>
#include <assert.h>
#include <string.h>
#include <ctype.h>

const char CODEINPUT[] = "/home/bibi/CLionProject/CPU/code.txt";
const char CODEOUTPUT[] =  "/home/bibi/CLionProject/CPU/bytecode.txt";

/*const char POP = "POP";
const char PUSH = "PUSH";
const char ADD = "ADD";*/

struct Command
{
    int cmd = 0; // индекс команды
    int ind = 0; //0 - если значение не требуется, 1 - если число , 2 - если регистр
    int val = 0; //значение числа или номер регистра
};

int Txt_Length (FILE* programm);
char* File_Read (FILE *txtfile);
void Strtok_Analis();
void Print_AllArr(char* txt, int size);
void Analis (char* word);
int Char_to_Int (char *word);
void Create_OFile ();

Command* Update_ByteCode();

const int PUSH = 1;
const int POP = 2;
const int ADD = 3;
const int SUB = 4;
const int MULT = 5;
const int DIV = 6;
const int IN = 7;
const int OUT = 8;

const int NOTREQ = 0;
const int NUMBER = 1;
const int REG = 2;
const int AX = 0;
const int BX = 1;
const int CX = 2;
const int DX = 3;


#endif //CPU_CPUHEADER_H
