Compil:
	make CompilFile
	make CompilCode
	touch ./bin/value.txt

CompilFile:
	rm -rf ./bin
	mkdir bin

CompilCode:
	gcc ./src/main_routing.c ./src/pipe_controler.c -o ./bin/main_routing.out -Wall
	gcc ./src/client.c ./src/pipe_controler.c -o ./bin/main_client.out -Wall
	gcc ./src/data.c ./src/pipe_controler.c -o ./bin/main_server.out -Wall

