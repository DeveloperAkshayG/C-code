/******************************************************************************

                    Difference using strlen and sizeof
                    
                sizeof gives me the length of string including null character
                strlen gives me the length of string exlucding null character    
                
            output is:the size using sizeof is 12
                      the size using strlen is 11    
*******************************************************************************/

#include <stdio.h>
#include<string.h>
int main()
{
    char str[]="hello world";
    int c=sizeof(str);
    int d=strlen(str);
    printf("the size using sizeof is %d\n",c); 
    printf("the size using strlen is %d",d);
    return 0;
}
