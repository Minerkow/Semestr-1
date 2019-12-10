//
// Created by bibi on 10.12.2019.
//

#ifndef PROCESSOR_HEADER_H
#define PROCESSOR_HEADER_H
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <assert.h>

//STACK CONST BEGIN

class Stack_t
{
public:
    int* data;
    size_t size;
    int error;
    long long hash;
    int capacity;
    int status;

    friend bool StackPush(Stack_t *stack, char new_elem);//сделать методами
    friend int StackPop(Stack_t *stack);
    friend void StackCreate (Stack_t *stack);
    friend void StackDestroy (Stack_t *stack);
    friend void StackPrint (Stack_t *stack);

    void StackHashAdd();
    void StackHashDown();
    bool StackOK ();
    void Dump ();
    long long CheckHash ();
    void StackAssert ();
    void AddMem();
    void DellMem ();
};

bool StackPush(Stack_t *stack, int new_elem);
int StackPop(Stack_t *stack);
void StackPrint (Stack_t *stack);

void StackCreate (Stack_t *stack);
void StackDestroy (Stack_t *stack);

int Degree (int a, int n);


const int MAXSIZE  = 100;// прочитать про enum
const int MINSIZE = 1;

const int NULLPTR = 228;
const int BOTTOM_EXIT = 69;
const int TOP_EXIT = 1337;
const int HACK_ERROR = 1001;
const int MINSIZE_ERROR = 123321;
const int STACK_DELETED = 300;

const int FAIL = 1;
const int SUCCESS = 0;

const int SLOT = 10;
const int TOP = -5;

const long long KEY = -2;

const int  EXIST = 1;
const int DELETED = 0;


//STACK CONST END

//CPU CONST BEGIN

const char BYTECODE[] = "/home/bibi/CLionProject/CPU/bytecode.txt";//
int *Read_ByteCode (FILE *txtfile);
void Start_Programm (Stack_t *stack);

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

#endif //STACKPOFILE_HEADER_H
