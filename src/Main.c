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

int main()
{
BigInt *obj1 = createBigInt("25");
BigInt *obj2 = createBigInt("2");


BigInt *Mod = MultiplyBigInt(obj1,obj2);
}