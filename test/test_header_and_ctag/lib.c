#include <stdio.h>
#include <string.h>
#include "lib.h"

void hello(char *str){
  for (size_t i=0;i<strlen(str);i++){
    printf("%c",str[i]);
  }
}

void read_file(char *str){

}
