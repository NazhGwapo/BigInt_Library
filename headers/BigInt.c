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
    BigIntObj->noDigits;
    BigIntObj->Size;
    BigIntObj->Number;
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
BigInt* AddBigInt(BigInt *a, BigInt *b)
{
    int numDig = MAX(a,b) + 1;
    char buffer[2];
    
    
    
 return NULL;   
}