#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d",&n);
    int *arr = (int*)malloc(n * sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",(arr+i));
    }
    for(int j=0;j<n;j++)
    {
        printf("%d\n",(arr[j]));
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}