#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <filesystem>

int problem1();
int FileDivide(const char name[], int div_num);
int FileCombine(const char name[], int div_num);
int FileDivide_v2(const char name[], int div_num);
int FileCombine_v2(const char name[], int div_num);
int strstr_KMP(const char* main, const char* sub);
int strstr_KMP_Visual(const char* main, const char* sub);
int KMP_match(const char txt[], const char pat[]);

int main()
{
	char main[] = "ababbbcabababc";
	char sub[] = "ababc";
	char main2[] = "aaaaaaaaaaaaaaaaaaaaaab";
	char sub2[] = "aaaab";
	

	printf("\n\n");
	printf("%d", strstr_KMP_Visual(main, sub));
	printf("%d", strstr_KMP_Visual(main2, sub2));

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
		cout << "\tinsert division file number : ";
		cin >> div_num;
		fname = "../data/" + fname;
		cout << "\tchoose mode (D: divide,   C: combine) : ";
		cin >> mode;

		switch (mode)
		{
		case 'c':
			FileCombine(fname.c_str(), div_num);
			break;

		case 'd':
			FileDivide(fname.c_str(), div_num);
			break;

		case 'C':
			FileCombine_v2(fname.c_str(), div_num);
			break;

		case 'D':
			FileDivide_v2(fname.c_str(), div_num);
			break;

		default:
			assert(0);
			break;
		}
	}

	return 0;	
}

int FileDivide(const char name[], int div_num)
{
	using namespace std;

	fstream* div_fouts = new fstream[div_num];
	for (int i = 0; i < div_num; ++i)
	{
		string fname = name;
		fname = fname + "." + to_string(i) + ".div";

		div_fouts[i].open(fname, ios_base::out | ios_base::binary | ios_base::trunc);
		assert(div_fouts[i].is_open());
	}

	fstream origin_fin(name, ios_base::in | ios_base::binary);
	assert(origin_fin.is_open());

	char ch;
	int div = 0;
	while (origin_fin.read(&ch, sizeof(char)))
	{
		div_fouts[div].write(&ch, sizeof(char));

		++div;
		div = div % div_num;
	}

	for (int i = 0; i < div_num; ++i)
		div_fouts[i].close();
	delete[] div_fouts;
	origin_fin.close();

	return 0;
}

int FileCombine(const char name[], int div_num)
{
	using namespace std;

	fstream* div_fins = new fstream[div_num];
	for (int i = 0; i < div_num; ++i)
	{
		string fname = name;
		fname = fname + "." + to_string(i) + ".div";

		div_fins[i].open(fname, ios_base::in | ios_base::binary);
		assert(div_fins[i].is_open());
	}

	fstream origin_fout(name, ios_base::out | ios_base::binary | ios_base::trunc);
	assert(origin_fout.is_open());

	char ch;
	int div = 0;
	while (div_fins[div].read(&ch, sizeof(char)))
	{
		origin_fout.write(&ch, sizeof(char));

		++div;
		div = div % div_num;
	}

	for (int i = 0; i < div_num; ++i)
		div_fins[i].close();
	delete[] div_fins;
	origin_fout.close();

	return 0;
}


int FileDivide_v2(const char name[], int div_num)
{
	using namespace std;

	fstream* div_fouts = new fstream[div_num];
	for (int i = 0; i < div_num; ++i)
	{
		string fname = name;
		fname = fname + "." + to_string(i) + ".div2";

		div_fouts[i].open(fname, ios_base::out | ios_base::binary | ios_base::trunc);
		assert(div_fouts[i].is_open());
	}

	fstream origin_fin(name, ios_base::in | ios_base::binary);
	assert(origin_fin.is_open());

	// size calcurate
	int origin_size;
	int div_size;
	int extra_size;
	origin_fin.seekg(0, ios_base::end);
	origin_size = origin_fin.tellg();
	origin_fin.seekg(0, ios_base::beg);
	origin_size -= origin_fin.tellg();
	div_size = origin_size / div_num;
	extra_size = origin_size % div_size;
	printf("%d, %d, %d\n", origin_size, div_size, extra_size);

	//copy, paste
	char* buffer = new char[div_size];
	char ch;
	for(int i = 0; i < div_num; ++i)
	{
		origin_fin.read(buffer, div_size*sizeof(char));
		div_fouts[i].write(buffer, div_size*sizeof(char));

		if (extra_size != 0)
		{
		origin_fin.read(&ch, sizeof(char));
		div_fouts[i].write(&ch, sizeof(char));
		--extra_size;
		}
	}
	delete buffer;

	// file close, delete
	for (int i = 0; i < div_num; ++i)
		div_fouts[i].close();
	delete[] div_fouts;
	origin_fin.close();

	return 0;
}

int FileCombine_v2(const char name[], int div_num)
{
	using namespace std;

	fstream* div_fins = new fstream[div_num];
	for (int i = 0; i < div_num; ++i)
	{
		string fname = name;
		fname = fname + "." + to_string(i) + ".div2";

		div_fins[i].open(fname, ios_base::in | ios_base::binary);
		assert(div_fins[i].is_open());
	}

	fstream origin_fout(name, ios_base::out | ios_base::binary | ios_base::trunc);
	assert(origin_fout.is_open());

	// size calcurate
	int div_size;
	div_fins[div_num - 1].seekg(0, ios_base::end);
	div_size = div_fins[div_num - 1].tellg();
	div_fins[div_num - 1].seekg(0, ios_base::beg);
	div_size -= div_fins[div_num - 1].tellg();

	// copy, paste
	char* buffer = new char[div_size];
	char ch;
	for (int i = 0; i < div_num; ++i)
	{
		div_fins[i].read(buffer, sizeof(char)*div_size);
		origin_fout.write(buffer, sizeof(char)*div_size);
		
		if (div_fins[i].read(&ch, sizeof(char)))
		{
			origin_fout.write(&ch, sizeof(char));
		}
	}
	delete buffer;

	// file close, delete
	for (int i = 0; i < div_num; ++i)
		div_fins[i].close();
	delete[] div_fins;
	origin_fout.close();

	return 0;
}


int strstr_KMP(const char* main, const char* sub)
{
	int main_len = strlen(main);
	int sub_len = strlen(sub);
	int m = 0;
	int s = 0;

	int eureka = -1;

	int* jump = (int*)malloc((sub_len+1)*sizeof(int));
	assert(jump);

	jump[0] = -1;
	jump[1] = 0;
	for (int i = 1; i < sub_len; ++i)
	{
		for (int j = 0; j < i;)
		{
			if (sub[j] == sub[i])
				jump[++i] = ++j;
			else if(j == 0)
				jump[i + 1] = 0;
			else
				j = jump[j];
		}
	}

	while (m != main_len && s != sub_len)
	{
		if (main[m] == sub[s])
		{
			++m;
			++s;
		}
		else
		{
			if (s == 0)
			{
				++m;
				continue;
			}

			s = jump[s];
		}
	}

	if (m != main_len)
		eureka = m;

	free(jump);
	return eureka;
}

int strstr_KMP_Visual(const char* main, const char* sub)
{
	int main_len = strlen(main);
	int sub_len = strlen(sub);

	int eureka = -1;

	int* skip_table = (int*)calloc(sub_len+1, sizeof(int));
	assert(skip_table);

	skip_table[0] = -1;
	skip_table[1] = 0;
	for (int i = 1; i < sub_len; ++i)
	{
		for (int j = 0; j < i;)
		{
			if (sub[j] == sub[i])
			{
				skip_table[i + 1] = j + 1;
				++i;
				++j;
			}
			else if (j == 0)
			{
				skip_table[i + 1] = 0;
				break;
			}
			else
			{
				j = skip_table[j];
			}
		}
	}

	printf("\n");
	for (int i = 0; i < sub_len; ++i)
		printf(" %2c", sub[i]);
	printf("\n");
	for (int i = 0; i < sub_len; ++i)
		printf(" %2d", skip_table[i]);
	printf("\n");
	

	int s = 0;
	for (int m = 0; m <= main_len; ++m)
	{
		while (1)
		{
			printf("%s\n", main);
			for (int num = m ; num > 0; --num)
				printf(" ");

			if (main[m] == sub[s])
			{
				printf("+\n");
				for (int num = m - s; num > 0; --num)
					printf(" ");
				printf("%s\n\n", sub);

				if (s == sub_len - 1)
					eureka = m;

				++s;
				break;
			}
			else
			{
				printf("-\n");
				for (int num = m - s; num > 0; --num)
					printf(" ");
				printf("%s\n\n", sub);

				if (s == 0)
					break;

				s = skip_table[s];
			}
		}
		if (eureka != -1)
			break;
	}

	free(skip_table);
	return eureka;
}


int KMP_match(const char main[], const char sub[])
{
	int main_len = strlen(main);
	int sub_len = strlen(sub);

	int m = 1;
	int s = 0;
	int skip[1024];

	skip[1] = 0;
	while (m < main_len)
	{
		if (sub[m] == sub[s])
			skip[++m] = ++s;
		else if (s == 0)
			skip[++m] = 0;
		else
			s = skip[s];
	}


	printf("\n");
	for (int i = 0; i < sub_len; ++i)
		printf("  %c", sub[i]);
	printf("\n");
	for (int i = 1; i < sub_len; ++i)
		printf("  %d", skip[i]);
	printf("\n");


	m = s = 0;
	while (m < main_len && s < sub_len)
	{
		if (main[m] == sub[s])
		{
			m++; s++;
		}
		else if (s == 0)
			m++;
		else
			s = skip[s];
	}
	if (s == sub_len)
		return m - s;

	return -1;
}