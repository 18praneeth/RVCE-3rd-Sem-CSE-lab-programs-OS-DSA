#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
char ch;
int i,shift;
shift=atoi(argv[2]);
//scanf("%s",m);
//scanf("%d",&shift);
for(i=0;argv[1][i]!='\0';i++)
{
ch=argv[1][i];
if(ch>='a'&&ch<='z')
{
ch=ch+ shift;
if(ch>'z')
ch=ch-'z'+'a'-1;
}
if(ch>='A'&&ch<='Z')
{
ch=ch+ shift;
if(ch>'Z')
ch=ch-'Z'+'A'-1;
}
argv[1][i]=ch;
}
printf("Encrypted message: %s\n",argv[1]);
return 0;
}

