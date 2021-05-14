#include <iostream>
#include <string>

using namespace std;

string dec_to_numeral(int, int);
int numeral_to_dec(string, int);
int char_to_num(char);
char num_to_char(int);


string dec_to_numeral(int dec, int numeral)
{
	int count;
	int i;

	if (numeral > 36)
		return "error";

	count = 0;
	static string num_string;
	num_string = "";

	while (1)
	{
		count = count + 1;
		if (!(pow(numeral, count) <= dec)) break;
	}

	i = count - 1;

	while (1)
	{
		num_string/*[count - i-1]*/ += num_to_char(dec / pow(numeral, i));
		dec = dec % (int)pow(numeral, i);
		i = i - 1;
		if (!(i >= 0)) break;
	}
	cout << num_string << endl;

	return num_string;
}


char num_to_char(int num)
{
	char character;

	if (num < 10)
	{
		character = ((char)((int) '0') + num);
	}
	else
	{
		character = ((char)((int) 'A') + num - 10);
	}

	return character;
}


int numeral_to_dec(string num_string, int numeral)
{
	int length;
	int i;

	if (numeral > 36)
		return -1;

	length = num_string.length();
	i = 1;
	int dec = 0;
	while (1)
	{
		dec = dec + pow(numeral, (i - 1))*char_to_num(num_string[length - i]);
		i = i + 1;
		if (!(i <= length)) break;
	}
	cout << dec << endl;

	return dec;
}


int char_to_num(char character)
{
	int num;

	if (character >= '0' && character <= '9')
	{
		num = ((int)character) - ((int) '0');
	}
	else
	{
		if (character >= 'A' && character <= 'Z')
		{
			num = ((int)character) - ((int) 'A') + 10;
		}
		else
		{
			cout << "error" << endl;
		}
	}

	return num;
}


int main()
{
	int dec;
	string num_string;

	dec = numeral_to_dec("3E8", 16);
	num_string = dec_to_numeral(dec, 2);

	return 0;
}
