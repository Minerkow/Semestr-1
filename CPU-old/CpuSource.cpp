//
// Created by bibi on 09.12.2019.
//

#include "CpuHeader.h"

extern Command* ByteCode;
extern int NumCommand;
extern char* code;// код из файла


char* File_Read (FILE *txtfile)
{
    int sizecode = Txt_Length(txtfile);
    char* code = (char*)calloc(sizecode + 1, sizeof(char));
    assert(code);
    int errcheck = fread(code, sizeof(char), sizecode, txtfile);
    if (errcheck == 0)
        perror("fread");
    return code;
}

int Txt_Length (FILE* txtfile)
{
    fseek(txtfile, 0 , SEEK_END);
    int length = ftell(txtfile);
    fseek(txtfile, 0, SEEK_SET);

    return length;
}

void Strtok_Analis()
{
    char* wordptr = NULL;
    if (NumCommand == 0)
    {
        wordptr = strtok(code, " \n");
        Analis(wordptr);
    }

    while (wordptr = strtok(NULL, " \n"))
    {
        Analis(wordptr);
    }
}

void Print_AllArr(char* txt, int size)
{
    for (int i = 0; i < size ;i++)
        printf("%c",txt[i]);
}

void Analis (char* word)
{
    if (!strcmp("PUSH", word))
    {
        Update_ByteCode();
        ByteCode[NumCommand - 1].cmd = PUSH;
        Analis(strtok(NULL, " \n"));
    }
    if (!strcmp("POP", word))
    {
        Update_ByteCode();
        ByteCode[NumCommand - 1].cmd = POP;
        Analis(strtok(NULL, " \n"));
    }
    if (!strcmp("ADD", word))
    {
        Update_ByteCode();
        ByteCode[NumCommand - 1].cmd = ADD;
        ByteCode[NumCommand - 1].ind = NOTREQ;

    }
    if (!strcmp("SUB", word))
    {
        Update_ByteCode();
        ByteCode[NumCommand - 1].cmd = SUB;
        ByteCode[NumCommand - 1].ind = NOTREQ;

    }
    if (!strcmp("MULT", word))
    {
        Update_ByteCode();
        ByteCode[NumCommand - 1].cmd = MULT;
        ByteCode[NumCommand - 1].ind = NOTREQ;
    }
    if (!strcmp("DIV", word))
    {
        Update_ByteCode();
        ByteCode[NumCommand - 1].cmd = DIV;
        ByteCode[NumCommand - 1].ind = NOTREQ;
    }
    if (!strcmp("IN", word))
    {
        Update_ByteCode();
        ByteCode[NumCommand - 1].cmd = IN;
        ByteCode[NumCommand - 1].ind = NOTREQ;
    }
    if (!strcmp("OUT", word))
    {
        Update_ByteCode();
        ByteCode[NumCommand - 1].cmd = OUT;
        ByteCode[NumCommand - 1].ind = NOTREQ;
    }
    if (!strcmp("ax", word))
    {
        ByteCode[NumCommand - 1].ind = REG;
        ByteCode[NumCommand - 1].val = AX;
    }
    if (!strcmp("bx", word))
    {
        ByteCode[NumCommand - 1].ind = REG;
        ByteCode[NumCommand - 1].val = BX;
    }
    if (!strcmp("cx", word))
    {
        ByteCode[NumCommand - 1].ind = REG;
        ByteCode[NumCommand - 1].val = CX;
    }
    if (!strcmp("dx", word))
    {
        ByteCode[NumCommand - 1].ind = REG;
        ByteCode[NumCommand - 1].val = DX;
    }
    if (isdigit(word[0]) || word[0] == '-')
    {
        ByteCode[NumCommand - 1].ind = NUMBER;
        if (word[0] == '-')
        {
            ByteCode[NumCommand - 1].val = -Char_to_Int(word + 1);
        }
        else
        {
            ByteCode[NumCommand - 1].val = Char_to_Int(word);
        }

    }
}

Command* Update_ByteCode()
{
    if (NumCommand == 0)
    {
        ByteCode = (Command *) calloc(1, sizeof(Command));
        assert(ByteCode);
        NumCommand++;
    }
    else
    {
        NumCommand++;
        ByteCode = (Command *) realloc(ByteCode, (NumCommand + 1) * sizeof(Command));
        assert(ByteCode);
    }
    return ByteCode;
}

int Char_to_Int (char *word)
{
    int degree = 1;
    int intnumber = 0;
    int len = strlen(word);
    for (int sym = len - 1; sym >=0; --sym)
    {
           intnumber = intnumber + (word[sym] - 48)*degree;
           degree = degree * 10;
    }
    return intnumber;
}

void Create_OFile ()
{
    FILE *ofile = fopen(CODEOUTPUT, "w");
    fprintf(ofile, "%d ", NumCommand);
    for (int numcmd = 0; numcmd < NumCommand; ++numcmd)
    {
        fprintf(ofile, "%d %d %d ", ByteCode[numcmd].cmd, ByteCode[numcmd].ind, ByteCode[numcmd].val);
    }
}
