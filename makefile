all:
	x86_64-w64-mingw32-g++ $(wildcard *.h) $(wildcard *.cpp) -o test.exe -lmingw32 -lSDL2main -lSDL2 -lBox2D 
run:
	./test.exe
