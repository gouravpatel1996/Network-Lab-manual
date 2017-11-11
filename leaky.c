#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define size 500
void bucket(int a,int b)
{
if(a>size)
printf("\nBUCKET OVERFLOW\n");
else
{
sleep(1);
while(a>b)
{
printf("\t\t\tnumber of bytes outputted is%d\n",b);
a-=b;
sleep(1);
}
if(a>0)
printf("\nLast bytes sent is%d\n",a);
printf("\nBUCKET OUTPUT IS SUCCESSFUL\n");
}
}
int main()
{
int op,pkt,i;
printf("\nenter the output rate\n");
scanf("%d",&op);
for(i=0;i<5;i++)
{
sleep(rand()%5);
pkt=rand()%1000;
printf("\npacket size:%d\n\npacket no:%d\n",pkt,i+1);
bucket(pkt,op);
}
}
