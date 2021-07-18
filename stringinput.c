#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    char c ;
    char str1[100];
    char str2[100]; 
    scanf("%c",&c);
    scanf("%s",str1);
    scanf("\n");
    scanf("%[^\n]",str2);

    printf("%c\n",c);
    printf("%s\n",str1);
    int f=strlen(str2);
   
  //  printf("%s\n",str2);
   for(int i=0;i<=strlen(str2);i++)
   {
       printf("%c",str2[i]);
   }  
    return 0;
}
