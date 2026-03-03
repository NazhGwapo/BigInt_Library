#include <stdio.h>
#include <stdlib.h>
#include <BigInt.h>

/*
THE PURPOSE OF THIS PROGRAM IS TO 
TURN STRING AND REPRESENT THEM AS A
LARGE NUMBER, LARGER THAN MOST COMPUTER CAN HOLD
AND TO BE ABLE TO DO BASIC OPERATIONS
FOR RSA ENCRYPTION PURPOSES 
*/

//To COMPILE THE PROJECT USE mingw32-make -f Makefile.mak
//and use ./Main

int main()
{
BigInt *NumA = createBigInt("10000000000000000000000000000000000000");
BigInt *NumB = createBigInt("10000000000000000000000000000000000000");

BigInt *Modulus  = MultiplyBigInt(NumA,NumB); // MULTIPLIED NUM
printf("%s",Modulus->Number);
}