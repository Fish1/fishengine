CC = g++
CFLAGS = -std=c++11 -c
MACROS = -DDEBUG
SRC = src/*.cpp

LIB_CRE = ar rcs
LIB_OUT = lib/libfishengine.a
LIB_SRC = *.o

program:
	$(CC) $(CFLAGS) $(MACROS) $(SRC)
	$(LIB_CRE) $(LIB_OUT) $(LIB_SRC) 
	rm *.o
	cp src/*.h inc
