#pragma once
#include"console_game.h"
#include"manager.h"
#include<windows.h>
#include<math.h>
#include<conio.h>

#define ECEL_POWER 0.1
#define DECEL_POWER 1.001
#define TIME_LIMIT (3600*3)

int GS_IAF();
static int Stage_Init();
static int Stage_Quit();
static int Stage_Collision();
static int Stage_Draw();
static int MapRead();
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

static CHAR title_image2[30][120] = {
	"                                                                                                                       ",
	"                                       ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄                                           ",
	"                                      ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌                                          ",
	"                                       ▀▀▀▀█░█▀▀▀▀ ▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀▀▀                                           ",
	"                                           ▐░▌     ▐░▌       ▐░▌▐░▌                                                    ",
	"                                           ▐░▌     ▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄▄▄                                           ",
	"                                           ▐░▌     ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌                                          ",
	"                                           ▐░▌     ▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀▀▀                                           ",
	"                                           ▐░▌     ▐░▌       ▐░▌▐░▌                                                    ",
	"                                       ▄▄▄▄█░█▄▄▄▄ ▐░▌       ▐░▌▐░▌                                                    ",
	"                                      ▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░▌                                                    ",
	"                                       ▀▀▀▀▀▀▀▀▀▀▀  ▀         ▀  ▀                                                     ",
	"                                                                                                                       ",
	"                ██╗     █████╗ ███╗   ███╗    ███████╗ █████╗ ███████╗████████╗███████╗███████╗████████╗               ",
	"                ██║    ██╔══██╗████╗ ████║    ██╔════╝██╔══██╗██╔════╝╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝               ",
	"                ██║    ███████║██╔████╔██║    █████╗  ███████║███████╗   ██║   █████╗  ███████╗   ██║                  ",
	"                ██║    ██╔══██║██║╚██╔╝██║    ██╔══╝  ██╔══██║╚════██║   ██║   ██╔══╝  ╚════██║   ██║                  ",
	"                ██║    ██║  ██║██║ ╚═╝ ██║    ██║     ██║  ██║███████║   ██║   ███████╗███████║   ██║                  ",
	"                ╚═╝    ╚═╝  ╚═╝╚═╝     ╚═╝    ╚═╝     ╚═╝  ╚═╝╚══════╝   ╚═╝   ╚══════╝╚══════╝   ╚═╝                  ",
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