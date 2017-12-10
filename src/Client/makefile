# names	: 	oriel sabban, guy zach
# ids 	:	201052602, 203953195

Client.out: compileAll
	g++ *.o -o Client.out
	rm -f *.o
	mv Client.out ./../../exe

compileAll: ./src/*.h ./src/*.cpp
	g++ -c ./src/*.cpp

