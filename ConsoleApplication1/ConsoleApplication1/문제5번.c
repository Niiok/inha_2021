#include<stdio.h>
#include<stdlib.h>

#define MATRIX_SIZE 3

int* solution(int* matrix, int size);
int line_sum(int* matrix, int size, int x, int y);

int main()
{
	int matrix[MATRIX_SIZE][MATRIX_SIZE] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };	//��� ����
	int* new_matrix = solution(matrix, MATRIX_SIZE);	//solution ȣ��

	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			printf("%4d ", *(new_matrix+i*MATRIX_SIZE+j));	//solution-��� ���
		}

		printf("\n");
	}

	free(new_matrix);	//soultion���� ������ �޸� ��ȯ
}

int* solution(int* matrix, int size)
{
	int* new_matrix = malloc(size*size * sizeof(int));	//�޸� ����
	if (new_matrix == NULL)
		exit(1);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			*(new_matrix + i * size + j) = line_sum(matrix, size, j, i);	//�� �Է��� ���� line_sum() ȣ��
		}
	}

	return new_matrix;
}

int line_sum(int* matrix, int size, int x, int y)
{
	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		sum += *(matrix + i * size + x);	//���� ���� ���� ���ϱ�
		sum += *(matrix + y * size + i);	//���� ���� ���� ���ϱ�
	}

	sum -= *(matrix + y * size + x);	//��ġ�� ���Ұ� ����

	//printf("%d ",sum);

	return sum;	//���ο� ���Ұ� ��ȯ
}