#include<stdio.h>
#define ARR_LEN 5

int pair_check(int* arr, int size, int target);

int main()
{
	int nums[ARR_LEN] = {1, 2, 3, 4, 5};	//nums ǥ��
	int success = 0;
	int target = 9;	//target ��

	for (int i = 0; i < ARR_LEN; i++)
	{
		success = pair_check(nums+i, ARR_LEN-i, target);	//����ǥ���� ������� ù��° �ε����� �� �ε��� ����
															//���н� 0 ����

		if (success)	//pair_check()�� 0�� �ƴ� �ε��� ���� ������ ���
		{
			printf("[%d, %d]", i, i + success);	//result ���
												//success = �ι�° �ε��� - ù��° �ε���
			break;
		}
	}
	if (!success)	//���� ǥ���� ���� ���
		printf("[ ]");	//result ���

}


int pair_check(int* arr, int size, int target)
{
	for (int i = 1; i < size; i++)
	{
		if (*arr + *(arr + i) == target)
			return i;	//(�ι�° �ε��� - ù��° �ε���) ����
	}

	return 0;
}
