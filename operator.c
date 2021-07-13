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
       printf("bye from danfoss\n"); 
    }
    if( a ^ b )
    {
     printf("a ^ b = %d\n",a^b);   
    }
    if( a || (++b) )
    {
        printf("a=%d\n",a);
        printf("b=%d",b);
    }
    return 0;
}
