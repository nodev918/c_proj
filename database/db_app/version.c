#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  printf("MYSQL client version: %s\n", mysql_get_client_info());\
    exit(0);
}
