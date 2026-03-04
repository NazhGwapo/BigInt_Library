#ifndef BigInt_H
#define BigInt_H

typedef struct
{
    int sign;
    int noDigits;
    int Size;
    char* Number;

}BigInt;

BigInt* AllocateBigInt();

BigInt* createBigInt(char* Number);

BigInt* AddedBigInt(BigInt *a, BigInt *b);
    
BigInt* MultiplyBigInt(BigInt *a, BigInt *b);





#endif