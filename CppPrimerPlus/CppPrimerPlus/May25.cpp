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

	//����� Ȧ������ �繰�Ը� �����ִ�.

	return 0;
}
