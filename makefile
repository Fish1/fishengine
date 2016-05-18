program:
	g++ -std=c++11 -c src/*.cpp
	ar rcs lib/libfishengine.a *.o 
	rm *.o
	cp src/*.h inc
