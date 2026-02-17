#ifndef BigInt_H
#define BigInt_H

typedef struct
{
    int sign;
    int noDigits;
    int Size;
    char* Number;

} BigInt;

BigInt* createBigInt(char* Number);





#endif