#include<stdio.h>
int add(int a,int b)
{
int c;
c=a+b;
printf("the result of addition using function pointer is %d\n",c);
}
int main()
{
int x,y;
printf("enter the value of x\n and y\n");
scanf("%d%d",&x,&y);
int (*ptr) (int,int) = &add;
(*ptr)(x,y);
return 0;
}
