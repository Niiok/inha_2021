#include <iostream>
#include <string>
#include <vector>

#include <cstring>
#include <cstdlib>

int Input_AtTail(int value);
int Search_Linear(int value);
int Search_LinearVisual(int value);
int Search_BinaryVisual(int value);

int Show_FormatHead();
int Show_FormatBody(int index);

void* bsearchx(const void* key, const void* base, size_t nmemb, size_t size, int(*compar)(const void*, const void*));
int compar_sample(const void* key, const void* compare);


static std::vector<int> _vector_integer;

int main()
{
	for (int i = 1; i < 39; ++i)
		_vector_integer.push_back(i);

	while (1)
	{
		int menu = 0;

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "\t 1. Input -\t input at tail \n";
		std::cout << "\t 2. Search -\t linear search value \n";
		std::cout << "\t 3. Search -\t linear search value (visual) \n";
		std::cout << "\t 4. Search -\t binary search value (visual) \n";
		std::cout << "\n\t Select menu : ";
		std::cin >> menu;
		std::cout << std::endl;

		switch (menu)
		{

		case 1:
		{
			std::cout << "\n input : ";
			int num;
			std::cin >> num;
			Input_AtTail(num); 
		} break;

		case 2:
		{
			std::cout << "\n search : ";
			int num;
			std::cin >> num;
			Search_Linear(num);
		} break;

		case 3:
		{
			std::cout << "\n search : ";
			int num;
			std::cin >> num;
			Search_LinearVisual(num);
		} break;
		
		case 4:
		{
			std::cout << "\n search : ";
			int num;
			std::cin >> num;
			Search_BinaryVisual(num);
		} break;

		case 99:
		{
			std::cout << "\n search : ";
			int num;
			std::cin >> num;
			std::cout << bsearchx(&num, (void*)&_vector_integer[0], _vector_integer.size(), sizeof(std::vector<int>), compar_sample) << std::endl;
		}

		default :
			system("cls");
		}
	}
}


int Input_AtTail(int value)
{
	_vector_integer.push_back(value);
	return 0;
}


int Search_Linear(int value)
{
	for (int i = 0; i < _vector_integer.size(); ++i)
	{
		std::cout << _vector_integer[i] << " ";
		if (_vector_integer[i] == value)
			return i;
	}

	return -1;
}

int Search_LinearVisual(int value)
{
	int vec_size = _vector_integer.size();

	Show_FormatHead();

	int i = 0;
	for (; i < vec_size; ++i)
	{
		Show_FormatBody(i);

		if (_vector_integer[i] == value)
			break;	
	}
	if (i == vec_size)
		return -1;
	else
		printf("%d는 x[%d]에 존재합니다.", value, i);

	return i;
}


int Search_BinaryVisual(int value)
{
	int from = 0;
	int to = _vector_integer.size();

	Show_FormatHead();

	int i = to/2;
	while (i != -1)
	{
		Show_FormatBody(i);

		if (_vector_integer[i] == value)
			break;
		else if (_vector_integer[i] > value)
		{
			to = i - 1;
			i = (to + from) / 2;
		}
		else if (_vector_integer[i] < value)
		{
			from = i + 1;
			i = (to + from) / 2;
		}
		else if (from >= to)
		{
			i = -1;
			break;
		}
	}
	if (i == -1)
		return -1;
	else
	printf("%d는 x[%d]에 존재합니다.", value, i);

	return i;
}




int Show_FormatHead()
{
	int vec_size = _vector_integer.size();

	printf("    |");
	for (int i = 0; i < vec_size; ++i)
	{
		printf("%3d  |", i);
	}printf("\n----+");

	for (int i = 0; i < vec_size; ++i)
	{
		printf("------");
	}printf("\n");

	return 0;
}

int Show_FormatBody(int index)
{
	int vec_size = _vector_integer.size();

	printf("    |");
	for (int j = 0; j < vec_size; ++j)
	{
		if (index == j)
			printf("  *   ");
		else
			printf("      ");
	}printf("\n");

	printf("%3d |", index);
	for (int j = 0; j < vec_size; ++j)
		printf("%3d  |", _vector_integer[j]);
	printf("\n");

	return 0;
}



void* bsearchx(const void* key, const void* base, size_t nmemb, size_t size, int(*compar)(const void*, const void*))
{
	// key : to search
	// base : array address
	// nmemb : number of array members
	// size : size of array element
	// blahblah : compare function's pointer

	size_t from = 0;
	size_t to = nmemb;
	size_t i = (from + to) / 2;

	while (i != -1)
	{
		//Show_FormatBody(i);

		char* i_address = (char*)base + (i * size);

		if (compar(i_address, key) == 0)
		{
			while (compar(i_address - size, key) == 0)
			{
				i_address = i_address - size;
			}
			break;
		}
		else if (compar(i_address, key) > 0)
		{
			to = i - 1;
			i = (to + from) / 2;
		}
		else if (compar(i_address, key) < 0)
		{
			from = i + 1;
			i = (to + from) / 2;
		}
		else if (from >= to)
		{
			i = -1;
			break;
		}
	}
	if (i == -1)
		return NULL;
	else
		return (char*)base + (i*size);
}

int compar_sample(const void* key, const void* compare)
{
	int* a = (int*)key;
	int* b = (int*)compare;

	if (*a == *b)
		return 0;
	else if (*a > *b)
		return 1;
	else if (*a < *b)
		return -1;
}