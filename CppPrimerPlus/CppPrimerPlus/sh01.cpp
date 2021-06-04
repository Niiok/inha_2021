#include <iostream>
#include "StopWatch.h"
#include "GenNum.h"

using namespace std;


void swap(int & a, int & b)
{
	int temp = a;
	a = b;
	b = temp;
}

template <typename T>
void Print(T * arr, T here, T len, T ch) {
	T i;

	for (i = 0; i < here - 1; i++)
		cout << arr[i] << "   ";

	cout << arr[here - 1] << " " << ch << " " << arr[here] << "   ";

	for (i = here + 1; i < len; i++)
		cout << arr[i] << "   ";

	cout << endl;
}


template <typename T>
void bubble_ver1(T *arr, T len)
{
	T i, j, cmp = 0, chg = 0;

	for (i = 0; i < len - 1; i++)
	{
		//cout << "패스" << i + 1 << endl;

		for (j = len - 1; j > i; j--)
		{
			if (arr[j - 1] > arr[j])
			{
				//cmp++;
				//chg++;
				swap(arr[j - 1], arr[j]);
				//Print(arr, j, len, '+');
			}/*
			else {
				cmp++;
				Print(arr, j, len, '-');
			}*/
		}
	}
	//cout << "비교를 " << cmp << "회 했습니다. " << endl;
	//cout << "교환을 " << chg << "회 했습니다. " << endl << endl;


}



template <typename T>
void bubble_ver2(T *arr, T len)
{
	T i, j, chk = 0, cmp = 0, chg = 0;

	for (i = 0; i < len - 1; i = chk)
	{
		//cout << "패스" << i + 1 << endl;
		chk++;
		for (j = len - 1; j > i - 1; j--)
		{
			if (arr[j - 1] > arr[j])
			{
				//cmp++;
				//chg++;
				swap(arr[j - 1], arr[j]);
				chk = j;
				//Print(arr, j, len, '+');
			}/*
			else {
				cmp++;
				Print(arr, j, len, '-');
			}*/
		}
	}
	//cout << "비교를 " << cmp << "회 했습니다. " << endl;
	//cout << "교환을 " << chg << "회 했습니다. " << endl << endl;
}


int main()
{
	/*
	const int ArrSize = 7;

	int arr1[ArrSize] = { 1,3,9,4,7,8,6 };
	int len1 = sizeof(arr1) / sizeof(arr1[0]);

	int arr2[ArrSize] = { 7,6,5,4,3,2,1 };
	int len2 = sizeof(arr2) / sizeof(arr2[0]);

	//bubble_ver1(arr1, len1);
	bubble_ver2(arr2, len2);

		*/
	long long ArrSize = 100000;
	long long * arr1 = new long long[ArrSize];
	long long * arr2 = new long long[ArrSize];
	GenNum(arr1, ArrSize);
	CopyNum(arr1, arr2, ArrSize);

	StopWatch s;


	s.start();
	bubble_ver1(arr1, ArrSize);
	s.stop();
	cout << "버전 1 소요시간: " << s.getElapsedTime() << "ms" << endl;

	s.start();
	bubble_ver2(arr2, ArrSize);
	s.stop();
	cout << "버전 2 소요시간: " << s.getElapsedTime() << "ms" << endl;


