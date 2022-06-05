#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

# define MAX 1000

int main(){
  hello("function");
  
  int num;
  FILE *fp;
  char line[MAX];


  fp = fopen("hello.txt","r");
  
  if(fp == NULL){
    printf("Error!");
    exit(1);
  }

  while (fgets(line, MAX , fp)){
    printf(line);
  }
  
  fclose(fp);
  return 0;

 
}
