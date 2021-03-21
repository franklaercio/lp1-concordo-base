.DEFAULT_GOAL := all

system.o: system.cpp system.h
	g++ system.cpp -c

executor.o: executor.cpp executor.h system.o
	g++ executor.cpp -c

user.o: user.cpp user.h
	g++ user.cpp -c

server.o: server.cpp server.h
	g++ server.cpp -c	

objects: system.o executor.o user.o server.o

concordo: objects agree.cpp
	g++ -Wall -fsanitize=address system.o executor.o user.o server.o agree.cpp -o concordo

clean:
	rm *.o concordo

all: concordo

run:
	./concordo
