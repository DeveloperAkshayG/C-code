/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<string.h>
int main()
{
     char inString[] = "+CIFSR:STAIP,\"192.168.1.117\"";
     char ip[20];
     char buff[50];
     int k=0;
     for(int i=0;inString[i] !='\0';i++)
     {
        if(inString[i] == '"')
        do
        {
            i++;
            if(inString[i] == '"')
            {
                ip[k]='\0';
                k++;
                break;
            }
            ip[k] = inString[i];
            k++;
            printf("instring[%d]- %c\n",i,inString[i]);
        //    printf("ip[%d]- %c\n",k,ip[k]);
        }while(inString[i]!= '"');
     }
     printf("the length of ip is %zu\n",strlen(ip));
     printf("ip is %s\n",ip);
 //    strncpy(buff,ip,25);
 //    printf("%s",buff);
     return 0;
}