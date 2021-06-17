#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

int problem1();
int FileEncode(const char fname[]);
int FileDecode(const char fname[]);

int main()
{
	problem1();

	return 0;

}


int problem1()
{
	using namespace std;

	string fname;
	int div_num;
	char mode;

	while (1)
	{
		cout << "\n\n\tinsert file name : ";
		cin >> fname;
		fname = "../data/" + fname;
		cout << "\tchoose mode (E: encoding,   D: decoding) : ";
		cin >> mode;

		switch (mode)
		{
		case 'e':
		case 'E':
			FileEncode(fname.c_str());
			break;

		case 'd':
		case 'D':
			FileDecode(fname.c_str());
			break;

		default:
			assert(0);
			break;
		}
	}

	return 0;
}

int FileEncode(const char name[])
{
	using namespace std;

	string fname = name;
	fname = fname + ".crypt";

	fstream crypt_fout(fname, ios_base::out | ios_base::binary | ios_base::trunc);
	assert(crypt_fout.is_open());
	fstream origin_fin(name, ios_base::in | ios_base::binary);
	assert(origin_fin.is_open());

	char ch;
	while (origin_fin.read(&ch, sizeof(char)))
	{
		ch += 5;
		crypt_fout.write(&ch, sizeof(char));
	}

	crypt_fout.close();
	origin_fin.close();

	return 0;
}

int FileDecode(const char name[])
{
	using namespace std;

	string fname = name;
	fname = fname + ".crypt";

	fstream crypt_fin(fname, ios_base::in | ios_base::binary);
	assert(crypt_fin.is_open());
	fstream origin_fout(name, ios_base::out | ios_base::binary | ios_base::trunc);
	assert(origin_fout.is_open());

	char ch;
	while (crypt_fin.read(&ch, sizeof(char)))
	{
		ch -= 5;
		origin_fout.write(&ch, sizeof(char));
	}

	
	crypt_fin.close();
	origin_fout.close();

	return 0;
}

