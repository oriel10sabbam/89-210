# name	: 	oriel sabban
# id 	:	201052602

a.out: compileAll
	g++ *.o 
	rm -f *.o

compileAll: *.h *.cpp
	g++ -c *.cpp

run:
	./a.out
