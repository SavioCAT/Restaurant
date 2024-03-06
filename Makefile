Compil:
	make CompilFile
	make CompilPipe

CompilFile:
	rm -rf ./bin
	rm -rf ./File_pipe
	mkdir File_pipe
	mkdir bin

CompilPipe:
	mkfifo pipe_Client_to_Routing
	mkfifo pipe_Routing_to_Client
	mkfifo pipe_Routing_to_Data
	mkfifo pipe_Data_to_Routing
	mv ./pipe* ./File_pipe/
