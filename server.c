#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/fcntl.h>
#include<netdb.h>
#define SERVER_PORT 2234
#define BUF_SIZE 4096
int main()
{
	int s,b,l,fd,sa,bytes,on=1;
	char buf[BUF_SIZE],fname[255];
	struct sockaddr_in channel;
	s=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(s<0){
		printf("Socket Failed\n");
		exit(0);
	}
	setsockopt(s,SOL_SOCKET,SO_REUSEADDR,(char*)&on,sizeof(on));
	memset(&channel,0,sizeof(channel));
	channel.sin_family=AF_INET;
	channel.sin_addr.s_addr=htonl(INADDR_ANY);
	channel.sin_port=htons(SERVER_PORT);
	b=bind(s,(struct sockaddr*)&channel,sizeof(channel));
	if(b<0){
		printf("Bind Failed\n");
		exit(0);
	}
	listen(s,5);
	while(1){
		printf("\n\nWaiting for Request:\n");
		sa=accept(s,0,0);
		if(sa<0)
		printf("Accept Failed\n");
		memset(fname,0,sizeof(fname));
		read(sa,fname,BUF_SIZE);
		printf("Requested Filename: %s",fname);
		fd=open(fname,O_RDONLY);
		if(fd<0){
			printf("\nError message sent to client\n");
			write(sa,"Could not open requested file",40);
		}
		else{
			while(1){
				bytes=read(fd,buf,BUF_SIZE);
				if(bytes<=0)
				break;
				write(sa,buf,bytes);
			}
			close(fd);
		}
		close(sa);
	}
}
