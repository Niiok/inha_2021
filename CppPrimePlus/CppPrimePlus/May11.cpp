#include <iostream>
using namespace std;


int c2p2();
int c2p3();
int c2p4();
int c2p5();

int a1q1();
int max4(int a, int b, int c, int d);

int main()
{
	c2p5();

	return 0;
}

int c2p2()
{
	cout << "insert mile distance.";

	float mile;
	cin >> mile;

	cout << mile << " is " << mile * 1.60934 << "km.";

	return 0;
}

int c2p3()
{
	cout << "Three blind mice" << endl;
	cout << "Three blind mice" << endl;
	cout << "See how they run" << endl;
	cout << "See how they run" << endl;

	return 0;
}

int c2p4()
{
	cout << "Enter your name : ";
	char name[32];
	cin >> name;

	cout << "Enter your age : ";
	int age;
	cin >> age;

	cout << "Your age in month is " << age * 12 << ".";

	return 0;
}

int c2p5()
{
	cout << "Enter Celsius : ";
	int celsius;
	cin >> celsius;

	cout << "heat in Fahrenheit is " << celsius * 1.8 + 32 << ".";

	return 0;
}

int a1q1()
{
	cout << "max among 1, 2, 3, 4 is" << max4(1, 2, 3, 4) << ". ";

	return 0;
}

int max4(int a, int b, int c, int d)
{
	int max = a;
	if (max < b) max = b;
	if (max < c) max = c;
	if (max < d) max = d;

	return max;
}