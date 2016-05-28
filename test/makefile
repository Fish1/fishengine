program:
	g++ -std=c++11 -c -I ../inc -L ../lib -static src/*.cpp -lfishengine	
	g++ *.o -o fe-app -lsfml-graphics -lsfml-window -lsfml-system -L ../lib -lfishengine
	rm *.o
