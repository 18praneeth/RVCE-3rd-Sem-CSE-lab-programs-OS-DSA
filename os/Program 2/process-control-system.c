#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char*argv[])
{
    char message[100],ch,ch1;
    int i,key;
    strcpy(message,argv[1]);
    key=atoi(argv[2]);
    printf("Hello    %s\n",message);
    for(i=0;message[i]!='\0';i++)
    {
        ch=message[i];
        if(ch!='_')
        {ch1=ch+key;

        if(ch1>'z')
        {
          ch1=ch1-'z'+'a';
        }
        ch=ch1;
        }
        if(ch=='_')
        ch='_';

        message[i]=ch;
    }
    printf("Encrypted message: %s\n",message);
}

