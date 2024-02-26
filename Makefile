Compil:
	make CompilFile
	make CompilPipe

CompilFile:
	rm -rf ./bin
	rm -rf ./File_pipe
	mkdir File_pipe
	mkdir bin

CompilPipe:
	mkfifo pipe_Client_to_Server
	mkfifo pipe_Server_to_Client
	mv ./pipe* ./File_pipe/
