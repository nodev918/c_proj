#include <stdio.h>
#include <stdlib.h>
char *ROOT;

int main(int argc, char* argv[]){
  
  ROOT = getenv("PWD");
  printf("%s\n",ROOT);
  return 0;
}
