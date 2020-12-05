/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
int main()
{
    char str1[100]="chintamani";
    int i=0;
    int count=0;
    for(i=0;str1[i]!='\0';i++)
    {
        count++;
    }
    printf("the length of the string is %d",count);
    return 0;
}
