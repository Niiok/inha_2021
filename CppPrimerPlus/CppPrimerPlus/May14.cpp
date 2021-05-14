#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>

int problem1();
int problem2();
int listing6_15();
int listing6_16();
int c6q4();
int problem3();
int listing7_18();
int prime_finder(int);
int prime_finder_ver2(int);
int IsLeapYear(int year);

int main()
{
	std::cout << "prime numbers before " << 1000 << " is " << prime_finder_ver2(1000);

}

int problem1()
{
	using namespace std;

	float a;	
	float v;	

	cout << "Speed and Accelation : ";
	cin >> v >> a;

	cout << "Minimum runway length : " << (double)pow(v, 2) / (a*2);

	return 0;
}


int problem2()
{
	struct Point {
		float x = 0;
		float y = 0;
		float z = 0;
	};
	Point pos[2];

	std::cout << "입력 x1, y1 : ";
	std::cin >> pos[0].x >> pos[0].y;
	
	std::cout << "입력 x2, y2 : ";
	std::cin >> pos[1].x >> pos[1].y;
	
	std::cout << "두 점 사이의 거리는 : " << sqrt(pow(pos[0].x - pos[1].x, 2) + pow(pos[0].y - pos[1].y, 2) + pow(pos[0].z - pos[1].z, 2));
	
	return 0;
}

int listing6_15()
{
	char automobile[50];
	int year;
	double a_price;
	double d_price;

	std::ofstream outFile;
	outFile.open("carinfo.txt");

	std::cout << "자동차 메이커와 차종을 입력하시오. : ";
	std::cin.getline(automobile, 50);
	std::cout << "연식을 입력하시오 : ";
	std::cin >> year;
	std::cout << "구입 가격을 입력하시오: ";
	std::cin >> a_price;
	d_price = 0.913 * a_price;


	std::cout << std::fixed;
	std::cout.precision(2);
	std::cout.setf(std::ios_base::showpoint);
	std::cout << "메이커와 차종 : " << automobile << std::endl;
	std::cout << "연식 : " << year << std::endl;
	std::cout << "구입 가격 : " << a_price << std::endl;
	std::cout << "현재 가격 : " << d_price << std::endl;
	

	outFile << std::fixed;
	outFile.precision(2);
	outFile.setf(std::ios_base::showpoint);
	outFile << "메이커와 차종 : " << automobile << std::endl;
	outFile << "연식 : " << year << std::endl;
	outFile << "구입 가격 : " << a_price << std::endl;
	outFile << "현재 가격 : " << d_price << std::endl;


	outFile.close();

	return 0;
}

int listing6_16()
{
	const int SIZE = 60;

	char filename[SIZE];
	std::ifstream inFile;
	std::cout << "데이터 파일의 이름을 입력하시오. : ";
	std::cin.getline(filename, SIZE);
	inFile.open(filename);

	if (!inFile.is_open())
	{
		std::cout << filename << " 파일을 열 수 없습니다." << std::endl;

	}

	return 0;
}

int c6q4()
{
	const int strsize = 64;
	const int list_length = 5;

	struct bop {
		char fullname[strsize];
		char title[strsize];
		char bopname[strsize];
		int preference;
		char* names[3] = {fullname, title, bopname};
	};

	bop name_list[list_length] = {
		{"Tom", "mr.T", "TOM" , 1},
		{"Sam", "mr.S", "SAM", 2},
		{"Jay", "mr.J", "JAY", 1},
		{"Jullie", "ms.J", "JUL", 0},
		{"Mitt", "ms. M", "MIS", 2}
	};

		while (1)
		{
			char menu = 0;
			int name_show = 0;
			bool pref = false;

			std::cout << "\n\n\nBenevolent Order of Programmers\n";
			std::cout << "a. 실명으로 열람\t\tb. 직함으로 열람\n";
			std::cout << "c. BOP 아이디로 열람\t\td. 회원이 지정한 것으로 열람\n";
			std::cout << "q. 종료\n\n";

			std::cout << "\t원하는 것을 선택하십시오 : ";

			std::cin >> menu;

			switch (menu)
			{
			case 'a':
				name_show = 0;
				break;

			case 'b':
				name_show = 1;
				break;

			case 'c':
				name_show = 2;
				break;

			case 'd':
				pref = true;
				break;

			case 'q':
				return 0;

			default:
				system("cls");
				continue;
			}

			for (int i = 0; i < list_length; ++i)
			{
				if (pref == false)
					std::cout << name_list[i].names[name_show] << std::endl;
				else
					std::cout << name_list[i].names[name_list[i].preference] << std::endl;
			}
		}


	return 0;
}

int problem3()
{
	struct Point {
		float x = 0;
		float y = 0;
		float z = 0;
	};
	Point pos[3];

	std::cout << "입력 x1, y1 : ";
	std::cin >> pos[0].x >> pos[0].y;

	std::cout << "입력 x2, y2 : ";
	std::cin >> pos[1].x >> pos[1].y;
	
	std::cout << "입력 x3, y3 : ";
	std::cin >> pos[2].x >> pos[2].y;

	//	pos0.x - pos2.x		pos0.y - pos2.y
	//	pos1.x - pos2.x		pos1.y - pos2.y
	//

	std::cout << "삼각형의 넓이 : " << abs(((pos[0].x - pos[2].x) * (pos[1].y - pos[2].y)) - ((pos[0].y - pos[2].y) * (pos[1].x - pos[2].x))) / 2 << " .\n";


	return 0;
}

int listing7_18()
{
	double gildong(int);
	double moonsoo(int);

	void estimate(int lines, double(*pf)(int));

	using namespace std;
	int code;

	cout << "필요한 코드의 행 수를 입력하시오: ";
	cin >> code;
	cout << "길동 예상시간: ";
	estimate(code, gildong);
	cout << "문수 예상시간: ";
	estimate(code, moonsoo);

	return 0;
}
double gildong(int lns)
{
	return 0.05 * lns;
}
double moonsoo(int lns)
{
	return 0.03 * lns + 0.0004 * lns * lns;
}
void estimate(int lines, double(*pf)(int))
{
	using namespace std;
	cout << lines << "행을 작성하는 데 ";
	cout << pf(lines) << "시간이 걸립니다.\n";
}

int prime_finder(int till)
{

	for (int i = 2; i <= till; ++i)
	{
		int j = 2;

		for (; j < i; ++j)
		{
			if (i % j == 0)
				break;
		}
		
		if (j == i)
			std::cout << i << std::endl;
	}

	return 0;
}

int prime_finder_ver2(int till)
{
	if (till < 2)
		return 0;

	std::cout << 2 << std::endl;

	if (till < 3)
		return 1;

	std::vector<int> primes = {3};
	std::cout << 3 << std::endl;

	for (int i = 5; i <= till; i = i + 2)	// no even number
	{
		bool b_is_prime = true;

		for (int j = 0; primes[j]*primes[j] <= i; ++j)
		{
			if (i % primes[j] == 0)
			{
				b_is_prime = false;
				break;
			}
		}
		
		if (b_is_prime == true)
		{
			std::cout << i << std::endl;
			primes.push_back(i);
		}
	}

	return primes.size() + 1;
}


int IsLeapYear(int year)
{
	if (year % 400)
		return 1;
	else if (year % 100)
		return 0;
	else if (year % 4 == 0)
		return 1;
	else
		return 0;
}