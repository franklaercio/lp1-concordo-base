.DEFAULT_GOAL := all

system.o: system.cpp system.h
	g++ system.cpp -c

executor.o: executor.cpp executor.h system.o
	g++ executor.cpp -c

user.o: user.cpp user.h
	g++ user.cpp -c

server.o: server.cpp server.h
	g++ server.cpp -c	

message.o: message.cpp message.h
	g++ message.cpp -c	

channel.o: channel.cpp channel.h
	g++ channel.cpp -c

text_channel.o: text_channel.cpp text_channel.h
	g++ text_channel.cpp -c

voice_channel.o: voice_channel.cpp voice_channel.h
	g++ voice_channel.cpp -c

objects: system.o executor.o user.o server.o message.o channel.o text_channel.o voice_channel.o

concordo: objects agree.cpp
	g++ -Wall -fsanitize=address system.o executor.o user.o server.o message.o channel.o text_channel.o voice_channel.o agree.cpp -o concordo

clean:
	rm *.o usuarios.txt servidores.txt concordo

all: concordo

run:
	./concordo
