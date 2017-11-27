# names	: 	oriel sabban, guy zach
# ids 	:	201052602, 203953195

a.out: compileAll
	g++ *.o 
	rm -f *.o

compileAll: src/*.h src/*.cpp
	g++ -c src/*.cpp

run:
	./a.out
