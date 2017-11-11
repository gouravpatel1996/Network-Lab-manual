#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#define FIFO1 "fifo1"
#define FIFO2 "fifo2"
#define PERMS 0666
char fname[256];
int main( ){
  	ssize_t n;
	char buff[512];
	int readfd,writefd;
	printf("Trying to Connect to Server..\n");
	writefd = open(FIFO1, O_WRONLY, 0);
	readfd  = open(FIFO2, O_RDONLY, 0);
	printf("Connected..\n");
	printf("Enter the filename to request from server: ");
	scanf("%s",fname);
	write(writefd, fname, strlen(fname));
	printf("Waiting for Server to reply..\n");
	while((n=read(readfd,buff,512))>0)	
	write(1,buff,n);
	close(readfd);
	close(writefd);
	return 0;
}
