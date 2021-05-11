#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int Manager_ManagerInit();

FILE* Manager_FileLoad(const char* file_name);

const char* Manager_MemmoryAllocate(int size);

int Manager_FileUnload(FILE* file_address);

int Manager_MemmoryFree(const char* memmory_address);


int Manager_ManagerQuit();
