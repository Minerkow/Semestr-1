#include "Header.h"

int *ByteCode = nullptr;
int NumCMD = 0;
int RegArr[4] = {0};
Stack_t StackCPU = {nullptr, 0, 0, 0, 0, 0};


int main()
{
    FILE *ByteCodeTxt = fopen(BYTECODE, "rb");
    Read_ByteCode(ByteCodeTxt);
    StackCreate(&StackCPU);
    Start_Programm(&StackCPU);
    StackPrint(&StackCPU);
    return 0;
}

