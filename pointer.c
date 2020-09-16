/*normal demonstration of working of pointer*/
#include<stdio.h>
int main()
{
int a=5;
int *p;
p=&a;
printf("Address of p is %p \n",&a);
printf("value of p is %d \n",*p);
return 0;
}
