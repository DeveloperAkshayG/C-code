/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<string.h>
int main()
{
    printf("Hello World\n");
    char str1[100]="akshay";
    char str2[100];
    strcpy(str2,str1);
    printf("%s\n",str2);
    printf("%s\n",str1);
    return 0;
}
