/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//To print binary representation of number
#include <stdio.h>
#include<stdint.h> //for uint8_t,uint16_t data types

void print(uint8_t num)
{
    for(int i=1<<7;i>0;i=i/2)
     (num&i)?printf("1"):printf("0");
}

int main()
{
    print(0xa5);

    return 0;
}
