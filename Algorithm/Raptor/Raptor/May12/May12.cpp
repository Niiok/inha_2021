#include <iostream>
#include <string>

using namespace std;

void a1q9(int a, int b)
{
	int sum;
	int end;
	int start;

	if (a > b)
	{
		start = b;
		end = a;
	}
	else
	{
		start = a;
		end = b;
	}
	sum = 0;
	while (1)
	{
		sum = start + sum;
		start = start + 1;
		if (start > end) break;
	}
	cout << sum << endl;}

int main()
{

	a1q9(-3, 10);

	return 0;
}
