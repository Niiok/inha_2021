#include<stdio.h>
#define ARR_LEN 5

int pair_check(int* arr, int size, int target);

int main()
{
	int nums[ARR_LEN] = {1, 2, 3, 4, 5};	//nums 표본
	int success = 0;
	int target = 9;	//target 값

	for (int i = 0; i < ARR_LEN; i++)
	{
		success = pair_check(nums+i, ARR_LEN-i, target);	//성공표본이 있을경우 첫번째 인덱스를 뺀 인덱스 리턴
															//실패시 0 리턴

		if (success)	//pair_check()가 0이 아닌 인덱스 값을 리턴한 경우
		{
			printf("[%d, %d]", i, i + success);	//result 출력
												//success = 두번째 인덱스 - 첫번째 인덱스
			break;
		}
	}
	if (!success)	//성공 표본이 없을 경우
		printf("[ ]");	//result 출력

}


int pair_check(int* arr, int size, int target)
{
	for (int i = 1; i < size; i++)
	{
		if (*arr + *(arr + i) == target)
			return i;	//(두번째 인덱스 - 첫번째 인덱스) 리턴
	}

	return 0;
}
