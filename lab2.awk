BEGIN{
#include<stdio.h>
tcp=0;
udp=0;
}
{
if($1=="r"&& $3=="2"&& $4=="3"&& $5=="cbr")
         tcp++;
if($1=="r"&& $3=="2"&& $4=="3"&& $5=="cbr")
         udp++;
}

END{
printf("\n total number of packets sent by tcp : %d\n",tcp);
printf("\n total number of packets sent by udp : %d\n",tcp);
}
