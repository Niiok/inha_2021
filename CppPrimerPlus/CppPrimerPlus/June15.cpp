#include <iostream>
#include <fstream>	// file input/output
#include <string>
#include <cstdlib>
#include <vector>

int listing_17_11();
int listing_17_16();
int listing_17_18();
int listing_17_20();
int strstr_BruteForce(char* main, char* sub);
int strstr_BruteForce_Visual(char* main, char* sub);

int main()
{
	char main_arr[] = "aabbabcaba";
	char sub_arr[] = "abc";
	char sub_arr2[] = "fff";

	int index = strstr_BruteForce_Visual(main_arr, sub_arr);
	printf("%s\n", main_arr);
	printf("%s\n", sub_arr);
	printf("%d\n\n\n\n", index);
	
	index = strstr_BruteForce_Visual(main_arr, sub_arr2);
	printf("%s\n", main_arr);
	printf("%s\n", sub_arr2);
	printf("%d\n\n\n\n", index);


	return 0;
}

int listing_17_11()
{
	using namespace std;
	cout << "수를 입력하십시오. : ";

	int sum = 0;
	int input;

	while (cin >> input)
	{
		sum += input;
	}

	cout << "last : " << input << "\n";
	cout << "sum : " << sum << "\n";

	return 0;
}

int listing_17_16()
{
	using namespace std;

	string filename;

	cout << "새 파일을 위한 이름을 입력하십시오. : ";
	cin >> filename;
	filename = "../data/" + filename;

	ofstream fout(filename.c_str());

	fout << "비밀번호 노출에 주의하십시오.\n";
	cout << "비밀번호를 입력하십시오. : ";
	float secret;
	cin >> secret;
	fout << "귀하의 비밀번호는 " << secret << "입니다.\n";
	fout.close();


	ifstream fin(filename.c_str());
	cout << "파일의 내용은 다음과 같습니다 : \n";
	char ch;
	
	while (fin.get(ch))
		cout << ch;

	cout << "프로그램을 종료합니다. \n";
	fin.close();

	return 0;
}

int listing_17_18()
{
	const char * file = "guests.txt";

	using namespace std;

	char ch;

	ifstream fin;
	fin.open(file);

	if (fin.is_open())
	{
		cout << file << "파일의 현재 내용은 다음과 같습니다.\n";
		while (fin.get(ch))
			cout << ch;
		fin.close();
	}

	ofstream fout(file, ios_base::out | ios_base::app);
	if (!fout.is_open())
	{
		cerr << "출력을 위해 " << file << " 파일을 열 수 없습니다.\n";
		exit(EXIT_FAILURE);
	}

	cout <<	"새로운 손님 이름들을 입력하십시오 (끝내려면 빈 줄 입력) : \n";
	string name;
	while (getline(cin, name) && name.size() > 0)
	{
		fout << name << endl;
	}
	fout.close();

	fin.clear();
	fin.open(file);
	if (fin.is_open())
	{
		cout << file << " 파일의 개정된 내용은 다음과 같습니다 : \n";
		while (fin.get(ch))
			cout << ch;
		fin.close();
	}
	cout << "프로그램을 종료합니다. \n";

	return 0;
}


const int LIM = 20;

struct planet {
	char namep[LIM];
	double population;
	double g;
};

int listing_17_20()
{
	const char* file = "planets.dat";


	return 0;
}


int strstr_BruteForce(char* main, char* sub)
{
	int main_len = strlen(main);
	int sub_len = strlen(sub);

	int eureka = -1;

	for (int i = 0; i <= main_len - sub_len; ++i)
	{
		for (int j = 0; j < sub_len; ++j)
		{
			if (main[i + j] == sub[j])
			{
				if (j == sub_len - 1)
					eureka = i;
				continue;
			}
			else
				break;
		}
		if (eureka != -1)
			break;
	}

	return eureka;
}

int strstr_BruteForce_Visual(char* main, char* sub)
{
	int main_len = strlen(main);
	int sub_len = strlen(sub);

	int eureka = -1;

	for (int i = 0; i <= main_len - sub_len; ++i)
	{
		for (int j = 0; j < sub_len; ++j)
		{
			printf("%s\n", main);
			for (int num = i+j; num > 0; --num)
				printf(" ");

			if (main[i + j] == sub[j])
			{
				if (j == sub_len - 1)
					eureka = i;

				printf("+\n");
				for (int num = i; num > 0; --num)
					printf(" ");
				printf("%s\n\n", sub);
				continue;
			}
			else
			{
				printf("-\n");
				for (int num = i; num > 0; --num)
					printf(" ");
				printf("%s\n\n", sub);
				break;
			}
		}
		if (eureka != -1)
			break;
	}

	return eureka;
}
