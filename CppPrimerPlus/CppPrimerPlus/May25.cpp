#include<iostream>
#include<vector>

int problem1();

int main()
{

	problem1();
}

int problem1()
{
	int student = 100;
	int opened = sqrt(student);
	std::vector<int> opened_cabinet;

	for (int i = 1; i <= opened; ++i)
	{
		opened_cabinet.push_back(i*i);
		std::cout << i * i << "  ";
	}

	//약수가 홀수개인 사물함만 열려있다.

	return 0;
}
