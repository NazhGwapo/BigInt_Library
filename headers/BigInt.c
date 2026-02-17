#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "BigInt.h"

BigInt* createBigInt(char* Number)
{
    int len = strlen(Number);
    BigInt *BigIntObj = malloc(sizeof(BigInt));
    BigIntObj->noDigits = len;
    BigIntObj->Size = len;
    BigIntObj->Number = Number;
    if(BigIntObj->Number[0] == '-')
    {
        BigIntObj->sign = -1;
        BigIntObj->noDigits--;
    }
    else
    {
        BigIntObj->sign = 1;
    }
    return BigIntObj;
}

char* AddBigInt(BigInt *a, BigInt *b)
{
    
}