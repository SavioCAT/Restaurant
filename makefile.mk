CC = gcc
CFLAGS = -Wall

all: Restaurant

Restaurant: Application_Cliente.o initialisation.o
	$(CC) $(CFLAGS) -o Restaurant Application_Cliente.o initialisation.o

Application_Cliente.o: Application_Cliente.c
	$(CC) $(CFLAGS) -c Application_Cliente.c
	
initialisation.o: initialisation.c
	$(CC) $(CFLAGS) -c initialisation.c

