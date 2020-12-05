/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<string.h>
int main()
{
    char str1[100]="hello";
    char str2[100];
    int i=0;
    for(i=0;str1[i]!='\0';i++)
    {
        printf("%c\n",str1[i]);
    }
    return 0;
}
