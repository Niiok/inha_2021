#include<stdio.h>
#include<stdlib.h>

#define MATRIX_SIZE 3

int* solution(int* matrix, int size);
int line_sum(int* matrix, int size, int x, int y);

int main()
{
	int matrix[MATRIX_SIZE][MATRIX_SIZE] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };	//행렬 선언
	int* new_matrix = solution(matrix, MATRIX_SIZE);	//solution 호출

	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			printf("%4d ", *(new_matrix+i*MATRIX_SIZE+j));	//solution-행렬 출력
		}

		printf("\n");
	}

	free(new_matrix);	//soultion에서 선언한 메모리 반환
}

int* solution(int* matrix, int size)
{
	int* new_matrix = malloc(size*size * sizeof(int));	//메모리 선언
	if (new_matrix == NULL)
		exit(1);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			*(new_matrix + i * size + j) = line_sum(matrix, size, j, i);	//값 입력을 위해 line_sum() 호출
		}
	}

	return new_matrix;
}

int line_sum(int* matrix, int size, int x, int y)
{
	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		sum += *(matrix + i * size + x);	//동일 열의 원소 더하기
		sum += *(matrix + y * size + i);	//동일 행의 원소 더하기
	}

	sum -= *(matrix + y * size + x);	//겹치는 원소값 빼기

	//printf("%d ",sum);

	return sum;	//새로운 원소값 반환
}