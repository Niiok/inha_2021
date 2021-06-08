#ifndef ___SORT_H___
#define ___SORT_H___

#include"TnT.h"

int compare_sorting();
int comparator(const void*, const void*);

int BubbleSort(int size, int arr[]);
int SimpleBubbleSort(int size, int arr[]);
int CocktailSort(int size, int arr[]);
int SimpleSelectionSort(int size, int arr[]);
int MinMaxSelectionSort(int size, int arr[]);
int InsertionSort(int size, int arr[]);
int ShellSort(int size, int arr[]);

int BubbleSortShow(int size, int arr[], int index);
int SelectSortShow(int size, int arr[], int index, int min, int max);
int InsertSortShow(int size, int arr[], int index);
int ShellSortShow(int size, int arr[], int index1, int index2);


#endif
