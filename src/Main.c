#include <stdio.h>
#include <stdlib.h>
#include <BigInt.h>

/*
THE PURPOSE OF THIS Library IS TO 
TURN STRING AND REPRESENT THEM AS A
LARGE NUMBER, LARGER THAN MOST COMPUTER CAN HOLD
AND TO BE ABLE TO DO BASIC OPERATIONS
FOR RSA ENCRYPTION PURPOSES 
*/

//To COMPILE THE PROJECT USE mingw32-make -f Makefile.mak
//and use ./Main

int main()
{
BigInt *NumA = createBigInt("67676767676767676767676767676767676767");
BigInt *NumB = createBigInt("696969696969696969696969696969696969");

BigInt *Added = AddedBigInt(NumA,NumB);
BigInt *Modulus  = MultiplyBigInt(NumA,NumB); // MULTIPLIED NUM
printf("MULTIPLIED NUM: %s\n",Modulus->Number);
printf("ADDED NUM: %s\n",Added->Number);

free(NumA);
free(NumB);
// free(Added);
free(Modulus);


}