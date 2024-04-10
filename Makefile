Compil:
	make CompilFile
	make CompilCode

CompilFile:
	rm -rf ./bin
	mkdir bin

CompilPipe:
	mkfifo pipe_Client_to_Routing
	mkfifo pipe_Routing_to_Client
	mkfifo pipe_Routing_to_Data
	mkfifo pipe_Data_to_Routing
	mv ./pipe* ./File_pipe/

CompilCode:
	gcc ./src/main_routing.c ./src/pipe_controler.c -o ./bin/main_routing.out
	gcc ./src/client.c ./src/pipe_controler.c -o ./bin/main_client.out

