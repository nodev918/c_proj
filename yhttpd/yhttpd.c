#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<signal.h>
#include<fcntl.h>

#define CONNMAX 1000
#define BYTES 1024


char *ROOT;
int listenfd, clients[CONNMAX];
void error(char *);

void respond(int);
void startServer(char *);


int main(int argc, char* argv[]){
  struct sockaddr_in clientaddr;
  socklen_t addrlen;
  char c;

  //Default VAlues PATH = PWD and PORT=10001
  char PORT[6];
  ROOT = getenv("PWD");
  strcpy(PORT,"10001");

  int slot = 0;

  //Parsing the command line arguments

  while((c=getopt(argc,argv,"p:r:")) != -1){
    switch(c)
    {
      case 'r':
        ROOT = malloc(strlen(optarg));
        strcpy(ROOT,optarg);
        break;
      case 'p':
        strcpy(PORT,optarg);
        break;
      case '?':
        fprintf(stderr,"Wrong arguments given!!!\n");
        exit(1);
      default:
        exit(1);
    }
  }

  printf("Server started at port no.%s%s%s with root %s%s%s\n","\033[92m",PORT,"\033[0m","\033[92m",ROOT,"\033[0m");

  
  // Setting all elements to -1: signifies there is no client connected
  int i;
  for ( i=0; i<CONNMAX; i++){
    clients[i] = -1 ;
  }
  
  startServer(PORT);

  // ACCEPT connections
  while(1){
    addrlen = sizeof(clientaddr);
    clients[slot] = accept (listenfd, (struct sockaddr *) &clientaddr, &addrlen);

    if (clients[slot]<0){ 
      error ("accept() error");
    }
    else{
      if ( fork()==0){
        respond(slot);
        exit(0);
      }
    }
    while (clients[slot]!=-1){
      slot = (slot+1)%CONNMAX;
    }
  }
  return 0;
}

void startServer(char *port){

}

void respond(int n){

}


