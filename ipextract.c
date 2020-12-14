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
     printf("%s\n",inString);
     char IP[16];
     char* firstQuote;
     char* secondQuote;
     firstQuote = strstr(inString,"\"");
     secondQuote = strstr(firstQuote+1,"\"");
     char lengthOfIP = secondQuote - firstQuote - 1;
     strncpy(IP,firstQuote+1,lengthOfIP);
     IP[lengthOfIP] = '\0';
     printf("IP=%s",IP);
}
