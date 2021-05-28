#include <iostream>
#include <string>
#include<cassert>
#define ALPHA_NUM 26


std::string mosaic(std::string&, char*);


int main()
{
	std::string correct_word = "banana";

	char alphabet[ALPHA_NUM] = { 0, };
	int chance = 5;
	int mistake = 0;
	int loops = 0;
	char character = 0;

	while (chance > 0)
	{
		std::string mosaiced_word = mosaic(correct_word, alphabet);

		printf("�ܾ��� �� ���ڸ� �Է��Ͻÿ�. %s > ", mosaiced_word.c_str());
		std::cin >> character;
		std::cin.seekg(0);

		if (character >= 'a' && character <= 'z')
		{
			character -= 'a';
		}
		else if (character >= 'A' && character <= 'Z')
		{
			character -= 'A';
		}
		else
		{
			printf("�߸��� ����, �ٽ��Է��ϼ���.\n");
			continue;
		}

		alphabet[character] = 1;
		std::string changed_word = mosaic(correct_word, alphabet);
		printf("                             %s\n", changed_word.c_str());


		++loops;

		if (changed_word == correct_word)
			break;

		if(changed_word == mosaiced_word)
			++mistake;
	}

	printf("�� %d�� ����, %d�� ���� ����!  %s\n", mistake, loops , correct_word.c_str());
}


std::string mosaic(std::string& original, char* alphabet)
{
	std::string victem = original;

	for (int i = 0; i < strlen(original.c_str()); ++i)
	{
		char character = original[i];

		if (character >= 'a' && character <= 'z')
		{
			character -= 'a';
		}
		else if (character >= 'A' && character <= 'Z')
		{
			character -= 'A';
		}
		else
			assert(0);

		if (alphabet[character] == 0)
		{
			victem[i] = '*';
		}
	}


	return victem;
}