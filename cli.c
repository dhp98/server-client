#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<fcntl.h>
#include<sys/stat.h>


int main(){
	int po;
	printf("Enter port : ");
	scanf("%d",&po);
	
	struct sockaddr_in server,client;
	int s,snd,rcv;
	char buff[50];
	
	server.sin_family=AF_INET;
	server.sin_port=htons(po);
	server.sin_addr.s_addr=inet_addr("127.0.0.1");
	
	s=socket(AF_INET,SOCK_STREAM,0);
	if(s==-1){exit(0);}
	
	int b;
	b=connect(s,(struct sockaddr*)&server,sizeof(server));
	if(b==-1){exit(0);}
	int ack=1;
	snd=send(s,&ack,sizeof(ack),0);
	rcv=recv(s,buff,sizeof(buff),0);
	if(rcv<0){exit(0);}
	printf("%s\n",buff);
	
	snd=send(s,&ack,sizeof(ack),0);
	rcv=recv(s,buff,sizeof(buff),0);
	if(rcv<0){exit(0);}
	printf("%s\n",buff);
	close(s);
	return 0;

}
