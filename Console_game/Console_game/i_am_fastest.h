#pragma once
#include"console_game.h"
#include"manager.h"
#include<windows.h>
#include<math.h>
#include<conio.h>

#define ECEL_POWER 0.1
#define DECEL_POWER 1.001
#define TIME_LIMIT (3600*3)
#define COLLISION_ACCURACY 100;

int GS_IAF_Game();
static int Game_Init();
static int Game_Quit();
static int Game_Collision();
static int Game_Draw();
static int IAF_Beep();

int GS_IAF_Title();
static int Title_Init();
static int Title_Quit();
static int Title_Select();
static int Title_Draw();

int GS_IAF_GameOver();
static int GameOver_Init();
static int GameOver_Quit();
static int GameOver_Select();
static int GameOver_Draw();


static int MapRead(const char*);
static int MapReadError(char i);





static CHAR title_image[30][120] = {
	"                                                                                                                       ",
	"                                                                                                                       ",
	"                                                                                                                       ",
	"                                                                                                                       ",
	"                                               `7MMF'      db      `7MM\"\"\"YMM                                          ",
	"                                                 MM;       MM:       MM    `7                                          ",
	"                                                 MM      ,V^MM.      MM   d                                            ",
	"                                                 MM     ,M  `MM      MM\"\"MM                                            ",
	"                                                 MM     AbmmmqMA     MM   Y                                            ",
	"                                                 MM    A'     VML    MM                                                ", 
	"                                               .JMML..AMA.   .AMMA..JMML.                                              ",
	"                                                                                                                       ",
	"                                                                                                                       ",
	"                                                                                                                       ",
	"                               ┬   ┌─┐┌┬┐   ┌─┐┌─┐┌─┐┌┬┐┌─┐┌─┐┌┬┐                          ",
	"                               │   ├─┤│││   ├┤  ├─┤└─┐  │  ├┤  └─┐  │                            ",
	"                               ┴   ┴  ┴┴  ┴   └    ┴  ┴└─┘  ┴  └─┘└─┘  ┴                            ",
	"                                                                                                                       ",
	"                                                                                                                       ",
	"                                                                                                                       ",
	"                                                                                                                       ",
	"                                                                                                                       ",
	"                                                                                                                       ",
	"                                                                                                                       ",
	"                                                                                                                       ",
	"                                                                                                                       ",
	"                                                                                                                       ",
	"                                                                                                                       ",
	"                                                                                                                       ",
	"                                                                                                                       "
};

//static CHAR title_image2[30][120] = {
//	"                                                                                                                       ",
//	"                                       ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄                                           ",
//	"                                      ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌                                          ",
//	"                                       ▀▀▀▀█░█▀▀▀▀ ▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀▀▀                                           ",
//	"                                           ▐░▌     ▐░▌       ▐░▌▐░▌                                                    ",
//	"                                           ▐░▌     ▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄▄▄                                           ",
//	"                                           ▐░▌     ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌                                          ",
//	"                                           ▐░▌     ▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀▀▀                                           ",
//	"                                           ▐░▌     ▐░▌       ▐░▌▐░▌                                                    ",
//	"                                       ▄▄▄▄█░█▄▄▄▄ ▐░▌       ▐░▌▐░▌                                                    ",
//	"                                      ▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░▌                                                    ",
//	"                                       ▀▀▀▀▀▀▀▀▀▀▀  ▀         ▀  ▀                                                     ",
//	"                                                                                                                       ",
//	"                ██╗     █████╗ ███╗   ███╗    ███████╗ █████╗ ███████╗████████╗███████╗███████╗████████╗               ",
//	"                ██║    ██╔══██╗████╗ ████║    ██╔════╝██╔══██╗██╔════╝╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝               ",
//	"                ██║    ███████║██╔████╔██║    █████╗  ███████║███████╗   ██║   █████╗  ███████╗   ██║                  ",
//	"                ██║    ██╔══██║██║╚██╔╝██║    ██╔══╝  ██╔══██║╚════██║   ██║   ██╔══╝  ╚════██║   ██║                  ",
//	"                ██║    ██║  ██║██║ ╚═╝ ██║    ██║     ██║  ██║███████║   ██║   ███████╗███████║   ██║                  ",
//	"                ╚═╝    ╚═╝  ╚═╝╚═╝     ╚═╝    ╚═╝     ╚═╝  ╚═╝╚══════╝   ╚═╝   ╚══════╝╚══════╝   ╚═╝                  ",
//	"                                                                                                                       ",
//	"                                                                                                                       ",
//	"                                                                                                                       ",
//	"                                                                                                                       ",
//	"                                                                                                                       ",
//	"                                                                                                                       ",
//	"                                                                                                                       ",
//	"                                                                                                                       ",
//	"                                                                                                                       ",
//	"                                                                                                                       "
//};