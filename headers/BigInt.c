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

BigInt* AddedBigInt(BigInt* a,BigInt*b)
{
    BigInt* result = createBigInt("1");
    int HighestDigit = MAX(a,b);
    HighestDigit++;
    result->noDigits = HighestDigit;
    result->Number = calloc(HighestDigit,sizeof(char));
    int* ptr = calloc(sizeof(int),HighestDigit);
    int Asize = a->noDigits-1;
    int Bsize = b->noDigits-1;
    int ResultSize = HighestDigit-1;
    int carry = 0;
    while (Asize > 0 || Bsize > 0)
    {
        int add = (a->Number[Asize] - '0' + b->Number[Bsize] - '0')+carry;
        carry = add/10;
        ptr[ResultSize] = add%10;  
        ResultSize--;
        Asize--;
        Bsize--;
    }
    if(Asize>Bsize)
    {
        while (Asize >= 0)
        {
            ptr[ResultSize] = a->Number[Asize] - '0';
            Asize--;
            ResultSize--;
        }
    }
    else if(Bsize > Asize)
    {

        while(Bsize >= 0)
        {
            ptr[ResultSize] = b->Number[Bsize] - '0';
            Bsize--;
            ResultSize--;
        }
    }
    else
    {
        ptr[ResultSize] = a->Number[Asize] - '0' + b->Number[Bsize] - '0';
        Asize--;
        ResultSize--;
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

    free(ptr);
    return result;
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
    int carry = 0;
    int aSize = a->noDigits-1;
    int bSize = b->noDigits-1;
    for (int i = bSize; i >= 0; i--)
    {
    carry = 0;

    for (int j = aSize; j >= 0; j--)
    {
        int index = i + j + 1;

        int multiplied =(a->Number[j] - '0') * (b->Number[i] - '0') + ptr[index] + carry; 
        // turns an ascii num from 0 to 9 to an integer
        ptr[index] = multiplied % 10;
        carry = multiplied/ 10;
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
    result->sign = 1;
    free(ptr);
    return result;
}