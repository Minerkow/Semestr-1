//
// Created by bibi on 09.12.2019.
//

#include "Header.h"


extern int *ByteCode;
extern int NumCMD;
extern int RegArr[4];
extern Stack_t StackCPU;

int* Read_ByteCode (FILE *txtfile)
{
    fscanf(txtfile, "%d", &NumCMD);
    ByteCode = (int*)calloc(NumCMD*3, sizeof(int));
    for (int i = 0;i < NumCMD * 3; ++i)
    {
        fscanf(txtfile, " %d", &ByteCode[i]);
        //printf("%d ", ByteCode[i]);
    }
    return ByteCode;
}

void Start_Programm (Stack_t *stack)
{
    for (int index = 0; index < NumCMD * 3; index = index + 3)
    {

        if (ByteCode[index] == PUSH)
        {
            if (ByteCode[index + 1] == NUMBER)
            {
                StackPush(stack, ByteCode[index + 2]);
            }
            if (ByteCode[index + 1] == REG)
            {
                RegArr[ByteCode[index + 2]] = stack->data[stack->size - 1];
                StackPop(stack);
            }
        }
        if (ByteCode[index] == POP)
        {
            if (ByteCode[index + 1] == NOTREQ)
            {
                StackPop(stack);
            }
            if (ByteCode[index + 1] == REG)
            {
                StackPush(stack, RegArr[ByteCode[index + 2]]);
            }
        }
        if (ByteCode[index] == ADD)
        {
            stack->data[stack->size - 2] = stack->data[stack->size - 2] + stack->data[stack->size - 1];
            StackPop(stack);
        }
        if (ByteCode[index] == SUB)
        {
            stack->data[stack->size - 2] = stack->data[stack->size - 2] - stack->data[stack->size - 1];
            StackPop(stack);
        }
        if (ByteCode[index] == MULT)
        {
            stack->data[stack->size - 2] = stack->data[stack->size - 2] * stack->data[stack->size - 1];
            StackPop(stack);
        }
        if (ByteCode[index] == DIV)
        {
            stack->data[stack->size - 2] = stack->data[stack->size - 2] / stack->data[stack->size - 1];
            StackPop(stack);
        }
        if (ByteCode[index] == IN)
        {
            int input = 0;
            scanf("%d", &input);
            StackPush(stack, input);
        }
        if (ByteCode[index] == OUT)
        {
            int output = 0;
            output = stack->data[stack->size - 1];
            printf("%d ", output);
        }


    }
}