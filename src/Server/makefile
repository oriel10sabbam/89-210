# names	: 	oriel sabban, guy zach
# ids 	:	201052602, 203953195

Server.out: compileAll
	g++ *.o -o Server.out -pthread
	rm -f *.o
	mv Server.out ./../../exe

compileAll: ./src/*.h ./src/*.cpp
	g++ -c ./src/*.cpp  -pthread


