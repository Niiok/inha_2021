#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int ManagerInit();

FILE* FileLoad(const char*);

const char* MemmoryAllocate(int);

int FileUnload();

int ManagerQuit();
