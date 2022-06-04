#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>

void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);
}

int main(int argc, char **argv)
{
  MYSQL *con = mysql_init(NULL);
  
  if (con == NULL) {
    fprintf(stderr, "%s\n", mysql_error(con));
    exit(1);
  }

  if (mysql_real_connect(con, "localhost", "user_c", "12345", "testdb", 0,NULL,0) == NULL){
    printf("connect db. \n");
    finish_with_error(con);
  }

 if (mysql_query(con, "DROP TABLE IF EXISTS cars")){ 
     printf("drop table. \n");
     finish_with_error(con);
 }

 if (mysql_query(con, "CREATE TABLE cars(id int AUTO_INCREMENT, name VARCHAR(255), price INT, PRIMARY KEY (id))")){
   printf("create table. \n"); 
   finish_with_error(con);
 }

 if (mysql_query(con, "INSERT INTO cars(name,price) VALUES('Audi',52642)")){
    finish_with_error(con);
 }

 if (mysql_query(con, "INSERT INTO cars(name,price) VALUES('Mercedes',57127)")){
    finish_with_error(con);
 }

 if (mysql_query(con, "INSERT INTO cars(name,price) VALUES('Skoda',9000)")){
    finish_with_error(con);
 }


 mysql_close(con);
 exit(0);





}
