#include<iostream>
#include <cstring>

int c3q1();
int c3q3();
int c3q5();
int c3q7();
int listing04_2();
int listing04_4();

int a1q4(int, int, int);
int a1q4_(int, int, int);
int a1q18(int n);

int main()
{

	a1q18(4);

	return 0;
}

int c3q1()
{
	int height_cm;

	std::cout << "write your height into cm. : _______\b\b\b\b\b\b";
	std::cin >> height_cm;
	
	const float height_m = (float)height_cm / 100.0;
	std::cout << "\nYour height in meter is : " << height_m;

	return 0;
}
int c3q3()
{
	int latitude_d;
	int latitude_m;
	int latitude_s;

	std::cout << "������ ��, ��, �� ������ �Է��Ͻÿ�:";
	std::cout << "\n����, ������ �Է��Ͻÿ�: ";
	std::cin >> latitude_d;
	std::cout << "������, �а��� �Է��Ͻÿ�: ";
	std::cin >> latitude_m;
	std::cout << "������, �ʰ��� �Է��Ͻÿ�: ";
	std::cin >> latitude_s;
	std::cout << latitude_d << "��, " << latitude_m << "��, " << latitude_s << "�� = " << (float)latitude_d + (float)latitude_m/60 + (float)latitude_s/3600 << "��\n\n";

	return 0;
}

int c3q5()
{
	long long population_world;
	long long population_country;

	std::cout << "���� �α����� �Է��Ͻÿ�: ";
	std::cin >> population_world;
	
	std::cout << "���� �α����� �Է��Ͻÿ�: ";
	std::cin >> population_country;

	std::cout << "���� �α������� ������ �����ϴ� ������ " << (static_cast<float>(population_country) / static_cast<float>(population_world)) * 100 << "% �̴�.\n";

	return 0;
}

int c3q7()
{
	float gasolin_european;	// 100 km per liter		// liter/100km
	float gasolin_american;	// gallon per mile		// mile/gallon

			// 100km == 62.14 mile			// 1 gallon == 3.875 liter

	std::cout << "insert gasolin usage into european style. (1 liter / 100 km) : ";
	std::cin >> gasolin_european;

	gasolin_american = (1.0 / gasolin_european) * 62.14 * 3.875;

	std::cout << "gasolin usage in american style is " << gasolin_american << ". \n";
	

	return 0;
}

int listing04_2()
{
	using namespace std;
	const int Size = 15;
	char name1[Size];
	char name2[Size] = "C++owboy";

	cout << "�ȳ��ϼ���! ���� " << name2 << "�Դϴ�! �Ƿ����� ������?\n";
	cin >> name1;
	cout << "��, " << name1 << " ��! ����� �̸��� " << strlen(name1) << "���Դϴٸ� \n";
	cout << sizeof(name1) << "����Ʈ ũ���� �迭�� ����Ǿ����ϴ�.\n";
	cout << "�̸��� " << name1[0] << "�ڷ� �����ϴ±���.\n";
	name2[3] = '\0';
	cout << "�� �̸��� ó�� �� ���ڴ� ������ �����ϴ�: " << name2 << endl;

	return 0;
}

int listing04_4()
{
	using namespace std;
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	cout << "�̸��� �Է��Ͻʽÿ�:\n";
	cin.getline(name, ArSize);
	cout << "�����ϴ� ����Ʈ�� �Է��Ͻʽÿ�:\n";
	cin.getline(dessert, ArSize);
	cout << "���ִ� " << dessert << "����Ʈ�� �غ��ϰڽ��ϴ�. " << name << "��. \n";


	return 0;
}

int a1q4(int a, int b, int c)
{
	int max = a;
	int min = a;

	if (max < b)
		max = b;
	if (min > b)
		min = b;

	if (max < c)
		max = c;
	if (min > c)
		min = c;

	if (max != c && min != c)
		return c;
	else if (max != b && min != b)
		return b;
	else
		return a;
}

int a1q4_(int a, int b, int c)
{
	/*if (a < b)
		if (a < c)
			if (b < c) return b;
			else return c;
		else
			return a;
	else if(b < c)
		if( )
*/
	return 0;
}

int a1q18(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < n * 2 - 1; j++)
		{
			if (j < i - 1 || j >= 2 * n - i)
				std::cout << ' ';
			else
				std::cout << i;
		}
		std::cout << std::endl;
	}

	return 0;
}