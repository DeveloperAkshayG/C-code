/******************************************************************************

            USING 'sizeof' to calculate size of variable
            for 64 bit architecture
*******************************************************************************/

#include <stdio.h>

int main()
{
    int p;
    int *q;
    char *r;
    printf("size is %ld\n",sizeof(p)); //4
    printf("size is %ld\n",sizeof(q)); //8
    printf("size is %ld\n",sizeof(r)); //8
    return 0;
}
