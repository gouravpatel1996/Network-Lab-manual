#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/fcntl.h>
#include<netdb.h>
#define SERVER_PORT 2234
#define BUF_SIZE 4096
int main()
{
	int c,s,bytes;
	char buf[BUF_SIZE],fname[225];
	struct hostent *h;
	struct sockaddr_in channel;
	printf("Enter the filename:\n");
	gets(fname);
	h=gethostbyname("localhost");
	if(!h)
		printf("gethostbyname failed\n");
	memset(&channel,0,sizeof(channel));
	channel.sin_family=AF_INET;
	memcpy(&channel.sin_addr.s_addr,h->h_addr,h->h_length);
	channel.sin_port=htons(SERVER_PORT);
	s=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(s<0){	
		printf("Socket Creation failed\n");
		exit(0);
	}
	c=connect(s,(struct sockaddr*)&channel,sizeof(channel));
	if(c<0){
		printf("Connection Failed\n");
		exit(0);
	}
	write(s,fname,strlen(fname));
	while(1){
		bytes=read(s,buf,BUF_SIZE);
		if(bytes<=0)
		exit(0);
		write(1,buf,bytes);
	}
}
