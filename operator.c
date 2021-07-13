/******************************************************************************

            Understanding bitwise and logical operator

*******************************************************************************/

#include <stdio.h>

int main()
{
    int a=6;
    int b=9;
    if( a & b )
    {
       printf("hello from danfoss\n"); 
    }
    if( a && b )
    {
       printf("bye from danfoss\n");  //op:bye from danfoss; 
    }
    if( a ^ b )
    {
     printf("a ^ b = %d\n",a^b);   //op:15
    }
    if( a || (++b) )
    {
        printf("a=%d\n",a); //op:6
        printf("b=%d",b);//op:9
    }
    return 0;
}
