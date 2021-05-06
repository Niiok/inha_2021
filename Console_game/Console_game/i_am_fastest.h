#pragma once
#include"console_game.h"
#include"manager.h"
#include <windows.h>

int GS_IAF();
static int Stage_Init();
static int Stage_Quit();

static int Stage_Collision();
static int Stage_Draw();

static int MapRead();
