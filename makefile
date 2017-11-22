# name	: 	oriel sabban
# id 	:	201052602

a.out: compileAll
	g++ *.o 
	rm -f *.o

compileAll: src/*.h src/*.cpp
	g++ -c src/*.cpp

run:
	./a.out
