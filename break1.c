/******************************************************************************

            USING 'break' KEYWORD in for loop before printf statement

*******************************************************************************/

#include <stdio.h>

int main()
{
    int i,n;
    printf("enter value of n\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        if(i==5)
        {
            break;
        }
        printf("i=%d,engineering world\n",i);
    }

    return 0;
}
