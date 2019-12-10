//
// Created by bibi on 12.11.2019.
//
#include "Header.h"

bool StackPush(Stack_t *stack, int new_elem)
{
    //if (StackOK)
    //    Dump(stack);
    stack->StackAssert();
    stack->AddMem();
    stack->data[stack->size - 1] = new_elem;
    stack->StackHashAdd();
    //if(StackOK)
    //    Dump(stack);
    stack->StackAssert();

    return SUCCESS;
}

int StackPop(Stack_t *stack)
{
    //if (StackOK(stack))
    //    Dump(stack);
    stack->StackAssert ();
    int top = stack->data[stack->size - 1];
    stack->DellMem();
    stack->StackHashDown();
    stack->error = TOP;
    //if (StackOK(stack))
    //    Dump(stack);
    stack->StackAssert ();

    return top;
}

void Stack_t :: AddMem()
{
    if (size == capacity)
        data = (int*)realloc(data, capacity + SLOT);//не эффективно уменьшить колво реалоков

    size++;
}

void Stack_t :: DellMem ()
{
    if (size * 3 == capacity)
        data = (int*)realloc(data, capacity / 3);
    size--;
}

bool Stack_t :: StackOK ()
{
    if (data == NULL)
    {
        error = NULLPTR;
        return FAIL;
    }

    if (size < MINSIZE - 1)
    {
        error = BOTTOM_EXIT;
        return FAIL;
    }

    if (size >= MAXSIZE )
    {
        error = TOP_EXIT;
        return FAIL;
    }
/*    if (hash != CheckHash())
    {
        //printf("CheckHash - %lld\n", CheckHash(stack));
        error = HACK_ERROR;
        return FAIL;
    }*/
    if (MINSIZE == 0)
    {
        error = MINSIZE_ERROR;
        return FAIL;
    }
    //if (error == TOP)
    //  return FAIL;
    if (status == DELETED)
    {
        error = STACK_DELETED;
        return FAIL;
    }

    // stack->error = SUCCESS;
    // printf("%d\n", stack->error);
    return SUCCESS;
}

void Stack_t :: Dump()
{
    //printf("Size: %d", stack->size);
    switch (error)
    {
        case BOTTOM_EXIT:
        {
            printf("Going beyond the bottom of the array\n");
            exit(BOTTOM_EXIT);// не использовать , возвращать в main
            //StackDestroy(stack);
            //stack->error = -1;
        }
        case TOP_EXIT:
        {
            printf("Exceeding the upper bound of the array\n");
            exit(TOP_EXIT);
            //StackDestroy(stack);
            //stack->error = -1;
        }
        case NULLPTR:
        {
            printf("Array error\n");
            exit(NULLPTR);
            //StackDestroy(stack);
            //stack->error = -1;
        }
        case HACK_ERROR:
        {
            printf( "HACK\n");
            exit(HACK_ERROR);
        }
            /*case SUCCESS:
            {
                printf("ELEM[%d] - %d\n",stack->size, stack->data[stack->size - 1]);
                break;
            }*/
        case STACK_DELETED:
        {
            printf("Stack has been removed");
            break;
        }
            /*case TOP:
            {
                printf("TOP - %d\n", stack->data[stack->size]);
                break;
            }*/


    }
}

void StackDestroy (Stack_t *stack)
{
    //stack->data = (char*)realloc(stack->data, MINSIZE);
    //stack->size = MINSIZE;
    free(stack->data);
    stack->status = DELETED;
    stack->data = nullptr;
    /// обнулить указатель, cделать статусную переменную
}

void Stack_t :: StackHashAdd()
{
    hash = hash + data[size - 1 ] * Degree(KEY, size - 1);// разделение на файлы, нельзя вызвать из мейн
}

void Stack_t :: StackHashDown()
{
    hash = hash - data[size] * Degree(KEY, size );
}

int Degree (int a, int n)
{
    for (int i = 0; i < n ; i++)
        a = a * KEY;
    return a;
}

long long Stack_t :: CheckHash ()
{
    int hash = 0;
    for (int i = 0; i < size; i++)
    {
        //printf("HASH in CheckHash after - %d, DIG - %d\n", hash, Degree(KEY, i));
        hash = hash + data[i] * Degree(KEY, i);
    }
    //printf("HASH in CheckHash - %d\n", hash);
    return hash;
}

void Stack_t :: StackAssert ()
{
    if (StackOK() || error == SUCCESS)
    {
        Dump();// исправть dump
        //printf("[]");
    }
}

void StackCreate(Stack_t *stack)
{
    stack->status = EXIST;
    stack->capacity = MINSIZE;
    stack->hash = 0;
    stack->error = 0;
    stack->size = 0;
    stack->data = (int*)calloc(stack->capacity, sizeof(int));//Тут я создаю calloc нулевого размера , может быть лажа в отдельную функцию
}

void StackPrint (Stack_t *stack)//полу dumb
{
    for (int i = 0; i < stack->size; i++)
        printf("Elem[%d] = %d\n", i, stack->data[i]);
    printf("\n");
}
