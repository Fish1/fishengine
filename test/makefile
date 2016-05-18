program:
	g++ -c -I ../inc -L ../lib -static *.cpp -lfishengine	
	g++ *.o -o fe-app -lsfml-graphics -lsfml-window -lsfml-system -L ../lib -lfishengine
	rm *.o
