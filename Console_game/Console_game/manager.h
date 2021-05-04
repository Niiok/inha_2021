#pragma once
#include "console_game.h"

int ManagerInit();

FILE* FileLoad(char*);

char* MemmoryAllocate(int);

int FileUnload();

int ManagerQuit();