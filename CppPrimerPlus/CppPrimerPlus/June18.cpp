#include <iostream>
#include <assert.h>
#include "TnT.h"

int strstr_BM(const char* main, const char* sub);
int strstr_BM_Visual(const char* main, const char* sub);
int strstr_KMP(const char* main, const char* sub);
int strstr_BruteForce(char* main, char* sub);
int KMP_match(const char main[], const char sub[]);
int bm_match(const char main[], const char sub[]);

int main()
{
	char main[] = "dsfasfsdfsaabc";
	char sub[] = "abc";
	char main2[] = "abzfsafsdfvababababfabcababc";
	char sub2[] = "ababc";
	TestArray<char> main3(100000000);
	main3.MakeStr();
	main3.arr()[99999994] = 'a';
	main3.arr()[99999995] = 'b';
	main3.arr()[99999996] = 'a';
	main3.arr()[99999997] = 'b';
	main3.arr()[99999998] = 'c';
	char sub3[] = "ababc";
	StopWatch stopwatch;

	stopwatch.Start();
	printf("\n\tBruteForce\n");
	printf("%d\n", strstr_BruteForce(main, sub));
	printf("%d\n", strstr_BruteForce(main2, sub2));
	printf("%d\n", strstr_BruteForce(main3.arr(), sub3));
	stopwatch.Stop();

	stopwatch.Start();
	printf("\n\tKMP\n");
	printf("%d\n", strstr_KMP(main, sub));
	printf("%d\n", strstr_KMP(main2, sub2));
	printf("%d\n", strstr_KMP(main3.arr(), sub3));
	stopwatch.Stop();

	stopwatch.Start();
	printf("\n\tBM\n");
	printf("%d\n", strstr_BM(main, sub));
	printf("%d\n", strstr_BM(main2, sub2));
	printf("%d\n", strstr_BM(main3.arr(), sub3));
	stopwatch.Stop();

	return 0;

}

int strstr_BM(const char* main, const char* sub)
{
	int main_len = strlen(main);
	int sub_len = strlen(sub);
	int m = sub_len - 1;
	int s = sub_len - 1;
	int jump[256];
	for (int i = 0; i < 256; ++i)
		jump[i] = sub_len;

	for (int i = 0; i < sub_len-1; ++i)
	{
		jump[sub[i]] = sub_len - i - 1;
	}

	m = s = sub_len - 1;


	while (s >= 0 && m < main_len )
	{
		if (main[m] == sub[s])
		{
			--m;
			--s;
		}
		else
		{
			m += (jump[main[m]] > sub_len - s) ? jump[main[m]] : sub_len - s;
			s = sub_len - 1;
		}
	}

	if (s == -1)
		return m + 1;
	return -1;
}

int strstr_BM_Visual(const char* main, const char* sub)
{
	int main_len = strlen(main);
	int sub_len = strlen(sub);
	int m = sub_len - 1;
	int s = sub_len - 1;
	int jump[256];
	for (int i = 0; i < 256; ++i)
		jump[i] = sub_len;

	printf("\t%d, %d\n\n", main_len, sub_len);

	printf("\n");
	for (int i = 0; i < sub_len; ++i)
		printf(" %2c", sub[i]);
	printf("\n");
	for (int i = 0; i < sub_len; ++i)
		printf(" %2d", jump[sub[i]]);
	printf("\n");

	for (int i = 0; i < sub_len-1; ++i)
	{
		jump[sub[i]] = sub_len - i - 1;
	}

	m = s = sub_len - 1;

	printf("\n");
	for (int i = 0; i < sub_len; ++i)
		printf(" %2c", sub[i]);
	printf("\n");
	for (int i = 0; i < sub_len; ++i)
		printf(" %2d", jump[sub[i]]);
	printf("\n");

	while (s >= 0 && m < main_len && (s < sub_len && m >= 0))
	{
		printf("%s\n", main);
		for (int num = m; num > 0; --num)
			printf(" ");

		if (main[m] == sub[s])
		{
			printf("+\n");
			for (int num = m - s; num > 0; --num)
				printf(" ");
			printf("%s\n\n", sub);

			--m;
			--s;
		}
		else
		{
			printf("-\n");
			for (int num = m - s; num > 0; --num)
				printf(" ");
			printf("%s\n\n", sub);
			m += jump[main[m]];
			s = sub_len - 1;
		}
	}
	if (s == -1)
		return m + 1;
	if(m>=main_len)
		return -1;
	return -2;
}

int strstr_KMP(const char* main, const char* sub)
{
	int main_len = strlen(main);
	int sub_len = strlen(sub);
	int m = 1;
	int s = 0;
	int eureka = -1;

	int* jump = (int*)malloc((sub_len + 1) * sizeof(int));
	assert(jump);

	jump[0] = -1;
	jump[1] = 0;

	while (m < sub_len)
	{
		if (sub[m] == sub[s])
			jump[++m] = ++s;
		else if (s == 0)
			jump[++m] = 0;
		else
			s = jump[s];
	}

	while (m != main_len && s != sub_len)
	{
		if (main[m] == sub[s])
		{
			++m;
			++s;
		}
		else if (s == 0)
			++m;
		else
			s = jump[s];
	}

	if (s == sub_len)
		eureka = m - s;

	free(jump);
	return eureka;
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


int KMP_match(const char main[], const char sub[])
{
	int main_len = strlen(main);
	int sub_len = strlen(sub);

	int m = 1;
	int s = 0;
	int skip[1024];

	skip[1] = 0;
	while (m < sub_len)
	{
		if (sub[m] == sub[s])
			skip[++m] = ++s;
		else if (s == 0)
			skip[++m] = 0;
		else
			s = skip[s];
	}

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

int bm_match(const char main[], const char sub[])
{
	int m, s;
	int main_len = strlen(main);
	int sub_len = strlen(sub);
	int jump[256];
	for (m = 0; m < 256; ++m)
		jump[m] = sub_len;
	for (m = 0; m < sub_len - 1; ++m)
		jump[sub[m]] = sub_len - m - 1;

	while (m < main_len)
	{
		s = sub_len - 1;
		while (main[m] == sub[s])
		{
			if (s == 0)
				return m;
			--m;
			--s;
		}
		m += (jump[main[m]] > sub_len - s) ? jump[main[m]] : sub_len - s;
	}

	return -1;
}