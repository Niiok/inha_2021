#include <iostream>
#include <string>
#include <vector>

#include <cstring>
#include <cstdlib>

int Input_AtTail(int value);
int Search_Linear(int value);

static std::vector<int> _vector_integer;

int main()
{
	while (1)
	{
		int menu;

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "\t 1. Input -\t input at tail \n";
		std::cout << "\t 2. Search -\t linear search value \n";
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