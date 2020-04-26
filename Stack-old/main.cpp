#include "Header.h"

int main()
{
    Stack_t stack;
    Stack_t stack2;
    StackCreate(&stack);
    StackCreate(&stack2);

    //НАЧАЛО ВВОДА
    //StackPush (&stack, 28);
    //StackPop (&stack);
    //StackPrint(&stack);
    StackPush(&stack2, 23);
    StackPush(&stack2, 69);
    StackPush(&stack, 69);
    StackPush(&stack, 69);
    StackPush(&stack, 69);
    StackPush(&stack2, 69);
    StackPush(&stack, 69);
    StackPrint(&stack2);
    StackPrint(&stack);
    //КОНЕЦ ВВОДА
    return 0;
}