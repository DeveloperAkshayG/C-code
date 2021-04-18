//this code illustrates the concept of union that only one member is allocated a memory at a time in union
#include <stdio.h>
union
{
    int rollno;
    int cell;
}u;

int main()
{
    printf("enter student rollno");
    scanf("%d",&u.rollno);
    printf("roll no is %d\n",u.rollno);
    printf("cell is %d",u.cell);

    return 0;
}
