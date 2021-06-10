#include <iostream>	
#include <string>
#include <vector>
#include <algorithm>

struct Review {
	std::string title;
	int rating;
};

int listing_16_1();
int listing_16_8();
bool FillReview(Review& rr);
void ShowReview(const Review& rr);
int listing_16_9();
bool operator< (const Review& r1, const Review& r2);
bool worseThan(const Review& r1, const Review& r2);

int main()
{
	listing_16_9();
}

int listing_16_1()
{
	using namespace std;

	string one("Lottery Winner!");
	cout << one << endl;

	string two(20, '$');
	cout << two << endl;

	string three(one);
	cout << three << endl;

	one += "Oops!";
	cout << one << endl;
	two = "Sorry! That was ";
	three[0] = 'P';
	
	string four;
	four = two + three;
	cout << four << endl;

	char alls[] = "All's well that ends well";

	string five(alls, 20);
	cout << five << "!\n";

	string six(alls + 6, alls + 10);
	cout << six << ", ";

	string seven(&five[6], &five[10]);
	cout << seven << "...\n";

	string eight(four, 7, 16);
	cout << eight << "in motion!" << endl;


	return 0;
}

int listing_16_8()
{
	using std::cout;
	using std::vector;
	vector<Review> books;
	Review temp;
	while (FillReview(temp))
		books.push_back(temp);
	int num = books.size();
	if (num > 0)
	{
		cout << "�����մϴ�. ����� ������ ���� �Է��ϼ̽��ϴ�.\n" << "���\t����\n";
		for (int i = 0; i < num; ++i)
			ShowReview(books[i]);
		cout << "�� �� �� ����Ѵ�:\n" << "���\t����\n";
		vector<Review>::iterator pr;
		for (pr = books.begin(); pr != books.end(); ++pr)
			ShowReview(*pr);
		vector<Review> oldlist(books);

		if (num > 3)
		{
			//remove 2 elements
			books.erase(books.begin() + 1, books.begin() + 3);
			cout << "������ ��:\n";
			for (pr = books.begin(); pr != books.end(); ++pr)
				ShowReview(*pr);
			//insert 1 element
			books.insert(books.begin(), oldlist.begin() + 1, oldlist.begin() + 2);
			cout << "������ ��:\n";
			for (pr = books.begin(); pr != books.end(); ++pr)
				ShowReview(*pr);
		}
		books.swap(oldlist);
		cout << "oldlist�� books�� ��ȯ�� ��:\n";
		for (pr = books.begin(); pr != books.end(); ++pr)
			ShowReview(*pr);
	}
	else
		cout << "�Է��� ���� ����, ���� ���� �����ϴ�.\n";

	return 0;
}

bool FillReview(Review& rr)
{
	std::cout << "å ������ �Է��Ͻʽÿ� (�������� quit�� �Է�) : ";
	std::getline(std::cin, rr.title);
	if (rr.title == "quit")
		return false;
	std::cout << "å ���(0-10)�� �Է��Ͻʽÿ� : ";
	std::cin >> rr.rating;
	if (!std::cin)
		return false;
	//remove resting input line	
	while (std::cin.get() != '\n')
		continue;
	return true;
}
void ShowReview(const Review& rr)
{
	std::cout << rr.rating << "\t" << rr.title << std::endl;
}

int listing_16_9()
{
	using namespace std;

	vector<Review> books;
	Review temp;
	while (FillReview(temp))
		books.push_back(temp);
	if (books.size() > 0)
	{
		cout << "�����մϴ�. ����� ������ ����" << books.size() << "���� å ����� �Է��ϼ̽��ϴ�.\n" << "���\t����\n";
		for_each(books.begin(), books.end(), ShowReview);

		sort(books.begin(), books.end());
		cout << "å ������ �������� ����: \n���\t����\n";
		for_each(books.begin(), books.end(), ShowReview);
		
		sort(books.begin(), books.end(), worseThan);
		cout << "å ����� �������� ����: \n���\t����\n";
		for_each(books.begin(), books.end(), ShowReview);
		
		random_shuffle(books.begin(), books.end());
		cout << "������ ������ �ٽ� ��ġ: \n���\t����\n";
		for_each(books.begin(), books.end(), ShowReview);
	}
	else
		cout << "�Է��� ���� ����, ���� ���� �����ϴ�.\n";
	
	return 0;
}

bool operator< (const Review& r1, const Review& r2)
{
	if (r1.title < r2.title)
		return true;
	else if (r1.title == r2.title && r1.rating < r2.rating)
		return true;
	else
		return false;
}
bool worseThan(const Review& r1, const Review& r2)
{
	if (r1.rating < r2.rating)
		return true;
	else
		return false;
}
