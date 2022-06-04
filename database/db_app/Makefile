


run:
	c99 version.c -o version -I/usr/include/mysql -L/usr/lib/x86_64-linux-gnu -lmysqlclient -lpthread -ldl -lz -lssl -lcrypto -lresolv -lm -lrt
	sleep 2
	./version

createdb:
	c99 createdb.c -o createdb -I /usr/include/mysql -L /usr/lib/x86_64-linux-gnu -l mysqlclient -lpthread -ldl -lz -lssl -lcrypto -lresolv -lm -lrt
	sleep 2
	./createdb
	
create_populate: .FORCE

.FORCE:
	rm create_populate
	c99 create_populate.c -o create_populate -I /usr/include/mysql -L /usr/lib/x86_64-linux-gnu -l mysqlclient -lpthread -ldl -lz -lssl -lcrypto -lresolv -lm -lrt
	sleep 2
	./create_populate
