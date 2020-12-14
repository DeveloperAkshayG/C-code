/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<string.h>
int main()
{
    char str[100]="hello sometimes suicide is best option";
    int count=0;
    int i=0;
    while(str[i]!='\0')
    {
        if (str[i]==' ')
        {
            count++;
        }
        i++;
    }
    printf("space count in string is %d",count);
    
    return 0;
}
