CC = gcc -Wall -O1 -g
LDFLAGS = -lpthread

all: server client_prova


server: server.c common.h log.h log.c
	$(CC) -o server server.c log.c $(LDFLAGS)
	
client_prova: client_prova.c common.h 
	$(CC) -o client_prova client_prova.c log.c $(LDFLAGS)
run:
	./server

:phony
clean:
	rm -f server
