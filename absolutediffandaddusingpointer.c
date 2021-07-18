/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
    int temp;
    temp=*a;
    *a=*a+*b;
    printf("%d\n",temp);
    if(temp>*b)
    {
        *b=temp-*b;
    }
    else
    {
      *b=*b-temp;    
    }
}

int main() 
{
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}