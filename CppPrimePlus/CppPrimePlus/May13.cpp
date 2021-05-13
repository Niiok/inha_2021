#include <iostream>
#include<string>
#include<vector>
#include<array>

int listing04_24();
int c4q2();
int c4q5_6_9();
int c4q7_8();
int problem1();
int c5q7();
int c5q8();
char* number_trans(int num, int trans);

int main()
{
	number_trans(1000, 16);

	return 0;
}

int listing04_24()
{
	using namespace std;

	double a1[4] = { 1.2, 2.4, 3.6, 4.8 };

	vector<double> a2(4);
	a2[0] = 1.0 / 3.0;
	a2[1] = 1.0 / 5.0;
	a2[2] = 1.0 / 7.0;
	a2[3] = 1.0 / 9.0;

	array<double, 4> a3 = { 3.14, 2.72, 1.62, 1.41 };
	array<double, 4> a4;

	a4 = a3;

	cout << "a1[2]: " << a1[2] << " at " << &a1[2] << endl;
	cout << "a2[2]: " << a2[2] << " at " << &a2[2] << endl;
	cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
	cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;

	a1[-2] = 20.2;
	cout << "a1[-2]: " << a1[-2] << " at " << &a1[-2] << endl;
	cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
	cout << "a4{2]: " << a4[2] << " at " << &a4[2] << endl;



	return 0;
}

int c4q2()
{
	using namespace std;
	const int ArSize = 20;
	string name;
	string dessert;

	cout << "이름을 입력하십시오:\n";
	//cin.getline(name, ArSize);
	getline(cin, name);
	cout << "좋아하는 디저트를 입력하십시오:\n";
	//cin.getline(dessert, ArSize);
	getline(cin, dessert);
	cout << "맛있는 " << dessert << "디저트를 준비하겠습니다. " << name << "님. \n";

	return 0;
}

int c4q5_6_9()
{
	// c4q5

	using namespace std;

	struct CandyBar {
		string name;
		float weight;
		int calorie;
	};

	CandyBar snack = { "Mocha Munch", 2.3, 350 };

	cout << snack.name << "'s weight : " << snack.weight << "\n";
	cout << snack.name << "'s calorie : " << snack.calorie << "\n";



	// c4q6

	CandyBar snacks[3];
	snacks[0] = { "Jaws Bar", 4.4, 444 };
	snacks[1] = { "Choco Milk", 1.1, 500 };
	snacks[2] = { "Mint Choco Bar", 3.5, 666 };

	int snacks_length = sizeof(snacks) / sizeof(CandyBar);
	for (int i = 0; i < snacks_length; i++)
	{
		cout << snacks[i].name << "'s weight : " << snacks[i].weight << "\n";
		cout << snacks[i].name << "'s calorie : " << snacks[i].calorie << "\n";
	}
	


	// c4q9

	CandyBar* snacks_m[3] = { (CandyBar*)new CandyBar, (CandyBar*)new CandyBar, (CandyBar*)new CandyBar };
	
	*snacks_m[0] = { "Jaws Bar", 4.4, 444 };
	*snacks_m[1] = { "Choco Milk", 1.1, 500 };
	*snacks_m[2] = { "Mint Choco Bar", 3.5, 666 };

	int snacks_length_m = 3;
	for (int i = 0; i < snacks_length_m; i++)
	{
		cout << snacks_m[i]->name << "'s weight : " << snacks_m[i]->weight << "\n";
		cout << snacks_m[i]->name << "'s calorie : " << snacks_m[i]->calorie << "\n";
		delete snacks_m[i];
	}



	return 0;
}

int c4q7_8()
{

	// c4q7

	using namespace std;

	struct TCL_Pizza {
		string name;
		float diameter;
		float weight;
	};

	TCL_Pizza sample;

	cout << "insert pizza's name : ";
	getline(cin, sample.name);
	cout << "insert pizza's diameter : ";
	cin >> sample.diameter;
	cout << "insert pizza's weight : ";
	cin >> sample.weight;

	cout << sample.name << "'s diameter is " << sample.diameter << ". \n";
	cout << sample.name << "'s weight is " << sample.weight << ". \n";


	// c4q8

	TCL_Pizza* sample_m = new TCL_Pizza;

	cout << "insert pizza's diameter : ";
	cin >> sample_m->diameter;
	cin.ignore();
	cout << "insert pizza's name : ";
	getline(cin, sample_m->name);
	cout << "insert pizza's weight : ";
	cin >> sample_m->weight;

	cout << sample_m->name << "'s diameter is " << sample_m->diameter << ". \n";
	cout << sample_m->name << "'s weight is " << sample_m->weight << ". \n";

	delete sample_m;


	return 0;
}

int problem1()
{
	std::string test_word;
	bool b_is_palindrome = true;

	std::cout << "insert word : ";
	std::getline(std::cin, test_word);


	for (int i = 0, count = test_word.size()/2; i < count; ++i)
	{
		if (test_word[i] != test_word[test_word.size() - i - 1])
		{
			b_is_palindrome = false;
			break;
		}
	}


	if (b_is_palindrome == false)
		std::cout << test_word << " is not palindrome.";
	else if(b_is_palindrome == true)
		std::cout << test_word << " is palindrome.";
		

	return 0;
}

int c5q7()
{
	using namespace std;

	struct Car {
		string company;
		int manifact_year;
	};

	int car_num;
	cout << "몇 대의 차를 목록으로 관리하시겠습니까? ";
	cin >> car_num;
	cin.ignore();

	vector<Car> cars(car_num);

	for (int i = 1; i <= car_num; ++i)
	{
		cout << "자동차 #" << i << " : \n";
		cout << "제작업체 : ";
		getline(cin, cars[i - 1].company);
		cout << "제작년도 : ";
		cin >> cars[i - 1].manifact_year;
		cin.ignore();
	}

	cout << "현재 귀하가 보유하고 있는 자동차 목록은 다음과 같습니다.\n";

	for (int i = 1; i <= car_num; ++i)
	{
		cout << cars[i-1].manifact_year << "년형 " << cars[i-1].company << "\n";
	}

	return 0;
}

int c5q8()
{

	return 0;
}

char* number_trans(int num, int trans)
{
	static char string[256];
	memset(string, 0, 256);

	if (trans > 36)
		return NULL;

	int count = 0;
	while (1)
	{
		if (pow(trans, count) > num)
			break;

		++count;
	}

	for (int i = count-1; i >= 0; --i)
	{
		int div = pow(trans, i);

		int character = num / div;

		if (character < 10)
			string[count - i-1] = (char)character + '0';
		else
			string[count - i-1] = (char)character-10 + 'A';

		num = num % div;
	}
	

	printf("%s", string);
	//return string;
}

char* numeral_translator(char* num_from, int numeral_from, int numeral_to)
{

	if (numeral_from > 36 || numeral_to > 36)
		return NULL;

	double num_dec;
	int num_len = strlen(num_from);
	for (int i = 0; i < num_len; ++i)
	{
		if(num_from[i] < )
		num_from[]
	}

	//return string;
}