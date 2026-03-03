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
    BigInt* result = createBigInt("");
    printf("%i",result->noDigits);
    result->noDigits = a->noDigits + b->noDigits;
    printf("HI");
    if(a->Number[0] == '0' || b->Number[0] == '0')
    {
        printf("MULTIPLICATION INVALID");
        return NULL;
    }
    int multiplied = 1;
    int carry = 0;
    int aSize = a->noDigits-1;
    int bSize = b->noDigits-1;
    int resultSize = result->Size - 1;
    for(int i = 0; i < b->noDigits;i++)
    {
        for(int j = 0; j< a->noDigits;j++)
        {
            multiplied = (b->Number[bSize]- '0') * (a->Number[aSize] - '0');
            printf("%i\n",multiplied);
            carry = (multiplied/ 10);
            result->Number[resultSize] = (multiplied% 10) + '0';
            resultSize--;
            aSize--;
            
        }
        aSize = a->noDigits-1; 
        bSize--;

    }


return NULL;
}