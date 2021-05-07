#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<mmsystem.h>
#pragma comment (lib, "winmm.lib")

//PlaySound(TEXT("../data/bgm.wav"),NULL,SND_ASYNC);


#define WIDTH 120
#define HEIGHT 30

enum GameStage {
	GameStage_Quit,
	GameStage_Entry,
	GameStage_Title_IAF,
	GameStage_IamFastest,
	GameStage_GameOver_IAF,
	GameStage_Title_ED,
	GameStage_EscapeDream,
	GameStage_GameOver_ED,
	GameStage_TotalGameStage
};

#ifdef MAIN_DECLARE

int _stage = GameStage_Title_IAF;		//FSM based on State class to judge what to do on main loop
int _score = 0;
const float _FPS = 120.0f;
CHAR_INFO _char_canvas[WIDTH * HEIGHT];		//canvas to share abroad states
#include"type_define.h"
#include"manager.h"
#include"i_am_fastest.h"
#undef MAIN_DECLARE

#else

extern int _stage;
extern int _score;
extern float _FPS;
extern CHAR_INFO _char_canvas[WIDTH * HEIGHT];

#endif // !EXTERN_DECLARE
