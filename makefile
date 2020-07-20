SOURCES = $(wildcard src/*.h) $(wildcard src/*.cpp) $(wildcard Chassis/*.h) $(wildcard Chassis/*.cpp) 
APP_NAME = Test

ifeq ($(OS),Windows_NT)
	OSFLAG += -D WIN32
	ifeq ($(PROCESSOR_ARCHITEW6432),AMD64)
		OSFLAG += -D AMD64
		CC = x86_64-w64-mingw32-g++ 
		LIBRARIES = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lSDL2_net -lBox2D
	else
        ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
            OSFLAG += -D AMD64
        endif
        ifeq ($(PROCESSOR_ARCHITECTURE),x86)
            OSFLAG += -D IA32
        endif
    endif
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		OSFLAG += -D LINUX
		CC = g++
		LIBRARIES = -lSDL2 -lSDL2main -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lSDL2_net -lBox2D

		DIST := $(shell lsb_release -si)
		ifeq ($(DIST),Ubuntu)
			INSTALL_CMD = 	sudo apt-get install libsdl2-dev libsdl2-2.0-0 \
						libjpeg-dev libwebp-dev libtiff5-dev libsdl2-image-dev libsdl2-image-2.0-0 \
						libmikmod-dev libfishsound1-dev libsmpeg-dev liboggz2-dev libflac-dev libfluidsynth-dev libsdl2-mixer-dev libsdl2-mixer-2.0-0 \
						libfreetype6-dev libsdl2-ttf-dev libsdl2-ttf-2.0-0 \
						libbox2d-dev libbox2d2.3.0 -y
		endif
		ifeq ($(DIST),LinuxMint)
			INSTALL_CMD = 	sudo apt-get install libsdl2-dev libsdl2-2.0-0 \
						libjpeg-dev libwebp-dev libtiff5-dev libsdl2-image-dev libsdl2-image-2.0-0 \
						libmikmod-dev libfishsound1-dev libsmpeg-dev liboggz2-dev libflac-dev libfluidsynth-dev libsdl2-mixer-dev libsdl2-mixer-2.0-0 \
						libfreetype6-dev libsdl2-ttf-dev libsdl2-ttf-2.0-0 \
						libbox2d-dev libbox2d2.3.0 -y
		endif
		ifeq ($(DIST),ARCH)
		endif
	endif
	ifeq ($(UNAME_S),Darwin)
		OSFLAG += -D OSX
	endif
	UNAME_P := $(shell uname -p)
	ifeq ($(UNAME_P),x86_64)
		OSFLAG += -D AMD64
	endif
	ifneq ($(filter %86,$(UNAME_P)),)
		OSFLAG += -D IA32
	endif
	ifneq ($(filter arm%,$(UNAME_P)),)
		OSFLAG += -D ARM
	endif
endif

install:
	$(INSTALL_CMD)

compile:
	@echo $(OSFLAG)
	$(CC) $(SOURCES) -o $(APP_NAME) $(LIBRARIES)
run:
	./$(APP_NAME)