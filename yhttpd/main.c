#include <stdio.h>

#define MAX 100

int main(){
  
  char str[MAX];
  char ch;


  FILE *file;

  file = fopen("index.html","r");
  
  if (file == NULL){
    printf("fopen error\n");
    return 1;
  }else{
    while((ch=fgetc(file)) != EOF){
      printf("%c",ch);
    }

    fclose(file);
    return 0;
  }
  
  
  

}
