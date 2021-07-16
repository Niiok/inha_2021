// MultiThread.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <process.h>
#include <windows.h>

int Value = 0;
int ValuePlusOne = 0;
int Count = 0;
int Sema = 0;
CRITICAL_SECTION cs;

DWORD WINAPI ThFunc1(LPVOID lpParam);
DWORD WINAPI ThFunc2(LPVOID lpParam);
unsigned __stdcall ThFunc3(LPVOID lpParam);
unsigned __stdcall ThFunc4(LPVOID lpParam);

int main()
{
	InitializeCriticalSection(&cs);

	DWORD dwThID1, dwThID2;
	HANDLE hThreads[2];

	unsigned long ulStackSize = 0;


	dwThID1 = 0;
	dwThID2 = 0;
	hThreads[0] = NULL;
	hThreads[1] = NULL;

	/*{
		hThreads[0] = CreateThread(NULL, ulStackSize, ThFunc1, NULL,
			CREATE_SUSPENDED, &dwThID1);
		hThreads[1] = CreateThread(NULL, ulStackSize, ThFunc2, NULL,
			CREATE_SUSPENDED, &dwThID2);
	}*/

	hThreads[0] = (HANDLE)_beginthreadex(NULL, 0, (unsigned(__stdcall*) (void*)) ThFunc3,
		NULL, 0, (unsigned*)&dwThID1);
	hThreads[1] = (HANDLE)_beginthreadex(NULL, 0, (unsigned(__stdcall*) (void*)) ThFunc4,
		NULL, 0, (unsigned*)&dwThID2);

	if (hThreads[0] == 0 || hThreads[1] == 0)
		exit(1);

	ResumeThread(hThreads[0]);
	ResumeThread(hThreads[1]);

	ExitThread(dwThID1);
	DWORD dwExitCode = 0;
	GetExitCodeThread(hThreads[0], &dwExitCode);
	if (dwExitCode == STILL_ACTIVE)
	{
		CloseHandle(hThreads[0]);
		TerminateThread(hThreads[0], dwExitCode);
	}

	WaitForMultipleObjects(2, hThreads, TRUE, INFINITE);

	CloseHandle(hThreads[0]);
	CloseHandle(hThreads[1]);

	DeleteCriticalSection(&cs);
}

DWORD WINAPI ThFunc1(LPVOID lpParam)
{
	while (1)
	{
		EnterCriticalSection(&cs);

		Value = rand() % 1000;
		ValuePlusOne = Value + 1;

		LeaveCriticalSection(&cs);
	}
}

DWORD WINAPI ThFunc2(LPVOID lpParam)
{
	while (1)
	{
		EnterCriticalSection(&cs);

		if (Value + 1 != ValuePlusOne)
			std::cout << ++Count << " -> " << Value + 1 << " : " << ValuePlusOne << "\n";

		LeaveCriticalSection(&cs);
	}
}

unsigned __stdcall ThFunc3(LPVOID lpParam)
{
	while (1)
	{
		//EnterCriticalSection(&cs);

		Value = rand() % 1000;
		ValuePlusOne = Value + 1;

		//LeaveCriticalSection(&cs);
	}
}

unsigned __stdcall ThFunc4(LPVOID lpParam)
{
	while (1)
	{
		//EnterCriticalSection(&cs);

		if (Value + 1 != ValuePlusOne)
			std::cout << ++Count << " -> " << Value + 1 << " : " << ValuePlusOne << "\n";

		//LeaveCriticalSection(&cs);
	}

}

