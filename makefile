all:
	x86_64-w64-mingw32-g++ $(wildcard *.h) $(wildcard *.cpp) -o test.exe -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lBox2D 
run:
	./test.exe
