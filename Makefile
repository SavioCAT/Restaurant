Compil:
	make CompilFile
	make CompilPipe

CompilFile:
	rm -rf ./bin
	rm -rf ./File_pipe
	mkdir File_pipe
	mkdir bin

CompilPipe:
	mkfifo pipe_Client_vers_Serveur
	mkfifo pipe_Serveur_vers_Client
	mv ./pipe* ./File_pipe/
