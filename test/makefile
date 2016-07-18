program:
	g++ -std=c++11 -c -I ../inc -L ../lib -static src/*.cpp -lfishengine	
	#g++ *.o -o fe-app -L ../lib -lsfml-graphics -lsfml-window -lsfml-system -lfishengine
	g++ *.o -o fe-app -L ../lib -lfishengine -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
	rm *.o
