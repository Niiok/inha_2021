CPP = main.cpp

COMPILER = g++

INCLUDE = -ID:/SDL/mingw/include

LIBRARY = -LD:/SDL/mingw/lib

LINK = -lmingw32 -lSDL2main -lSDL2

FLAG = -w -Wl,-subsystem,windows

RESULT_NAME = SDL_Mirror


all : $(CPP)
	$(COMPILER) $(CPP) $(INCLUDE) $(LIBRARY) $(LINK) $(FLAG) -o $(RESULT_NAME)