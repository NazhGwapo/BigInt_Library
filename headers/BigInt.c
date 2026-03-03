#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "BigInt.h"
#include <stdio.h>

#define MAX(a,b) a->noDigits >= b->noDigits ? a->noDigits : b->noDigits

BigInt* AllocateBigInt()
{
    BigInt *BigIntObj = malloc(sizeof(BigInt));
    if(BigIntObj == NULL)
    {
        printf("Allocation Failed");
    }
    BigIntObj->noDigits = 0;
    BigIntObj->Size = 0;
    return BigIntObj;
}

BigInt* createBigInt(char* Number)
{
    BigInt* allocated = AllocateBigInt();
    allocated->noDigits = strlen(Number);
    allocated->Size = strlen(Number);
    allocated->Number = Number;
    if(allocated->Number[0] == '-')
    {
    allocated->sign = -1;
    allocated->noDigits--;
    }
    else if(allocated->Number[0] > '0' && allocated->Number[0] <= '9')
    {
    allocated->sign = 1;
    }
    else
    {
        printf("Incorrect input of number\n");
        return NULL;
    }
    return allocated;

}

BigInt* MultiplyBigInt(BigInt *a,BigInt *b)
{
    BigInt* result = createBigInt("1");
    result->noDigits = a->noDigits + b->noDigits;
    result->Number = calloc(sizeof(char), result->noDigits);
    if(a->Number[0] == '0' || b->Number[0] == '0')
    {
        printf("MULTIPLICATION INVALID");
        return NULL;
    }
    int* ptr= calloc(result->noDigits,sizeof(int));
    int multiplied = 1;
    int carry = 0;
    int aSize = a->noDigits-1;
    int bSize = b->noDigits-1;
    int resultSize = result->noDigits - 1;
for (int i = bSize; i >= 0; i--)
{
    carry = 0;

    for (int j = aSize; j >= 0; j--)
    {
        int index = i + j + 1;

        int product =(a->Number[j] - '0') * (b->Number[i] - '0') + ptr[index] + carry;

        ptr[index] = product % 10;
        carry = product / 10;
    }

    ptr[i] += carry;

}
int front = 0;
    for(int i = 0; i < result->noDigits;i++)
    {
        if(ptr[0] == 0 &&!front)
        {
            front = 1;
            continue;
        }
        if(!front)
        {
            result->Number[i] = ptr[i] + '0';
        }
        else
        {
            result->Number[i-1] = ptr[i] + '0';
        }
    }
    result->Size = result->noDigits;
    result->sign = 0;
    free(ptr);
    return result;
}