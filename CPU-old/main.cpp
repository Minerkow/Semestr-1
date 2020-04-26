#include "CpuHeader.h"

Command* ByteCode = NULL;
int NumCommand = 0;
char* code = NULL;// код из файла

int main()
{
    FILE *programm = fopen(CODEINPUT, "rb");
    assert( programm );
    code = File_Read(programm);
    //printf("comand - %s, index - %d", pop.command, pop.index);
    Strtok_Analis();
    //Print_AllArr(code, 6);
    //printf ("\n%d %d %d", ByteCode[0].cmd, ByteCode[0].ind, ByteCode[0].val);
    //printf ("\n%d %d %d", ByteCode[1].cmd, ByteCode[1].ind, ByteCode[1].val);
    //printf ("\n%d %d %d", ByteCode[2].cmd, ByteCode[2].ind, ByteCode[2].val);
    //printf("%s", code);
    Create_OFile();
    free(code);
    free(ByteCode);
    return 0;
}
