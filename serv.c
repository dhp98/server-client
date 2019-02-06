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
	int s,ns,snd,rcv;
	char buff[50];
	
	server.sin_family=AF_INET;
	server.sin_port=htons(po);
	server.sin_addr.s_addr=htonl(INADDR_ANY);
	
	s=socket(AF_INET,SOCK_STREAM,0);
	if(s==-1){exit(0);}
	
	int b;
	b=bind(s,(struct sockaddr*)&server,sizeof(server));
	if(b==-1){exit(0);}
	
	b=listen(s,3);
	if(b==-1){exit(0);}///////
	
	int cli =sizeof(client);
	ns=accept(s,(struct sockaddr*)&client,&cli);
	if(ns==-1){exit(0);}
	
	FILE* file;
	file = fopen("abc.txt","r");
	if(!file){printf("FILE OPENING ERROR"); exit(0);}
	
	char temp[20];
	char rev[50],uppr[50];
	
	if(fgets(temp,20, file) != NULL){
	printf("%s",temp);
	
	} 
		
	pid_t pid;
	
	pid=fork();		
		if(pid>0){
		int i,k;
		k=0;
		for(i=strlen(temp)-1;i>=0;i--){
			rev[k++]=temp[i];
		}
		printf("PARENT : %s\n",rev);
		int ack;
		rcv =recv(ns,&ack,sizeof(ack),0);
		snd=send(ns,rev,sizeof(rev),0);
		exit(0);
		}
		if(pid==0){
		printf("/nchild");
		int j;
		for(j=0;j<strlen(temp);j++){
			if(temp[j]>='a' && temp[j]<='z'){
				temp[j] = temp[j] - 32;
			}
		}
		int ack;
		rcv =recv(ns,&ack,sizeof(ack),0);
		snd=send(ns,temp,sizeof(temp),0);
		exit(0);
		}
	
	
	
	}
	
