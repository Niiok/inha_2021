#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <vector>
#include <ctime>

template<typename T>
class TooBig {
private:
	T cutoff;

public:
	TooBig(const T& t) : cutoff{t} {}
	bool operator() (const T& v) { return v > cutoff; }
};

void outint(int u) { std::cout << u << " "; }
int listing_16_15();
int c16q7();
std::vector<int> Lotto(int range, int ball_num);

int main()
{
	c16q7();
}


int listing_16_15()
{
	using std::list;
	using std::cout;
	using std::endl;

	TooBig<int> f100(100);
	int vals[10] = { 50, 100, 90, 180, 60, 210, 415, 88, 188, 201 };
	list<int> yadayada(vals, vals + 10);
	list<int> etcetera(vals, vals + 10);

	cout << "원래의 리스트: \n";
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;

	yadayada.remove_if(f100);
	etcetera.remove_if(TooBig<int>(200));

	cout << "정비된 리스트: \n";

	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;

	return 0;
}

int c16q7()
{
	std::vector<int> winners;
	winners = Lotto(51, 6);

	for (int var : winners)
		std::cout << var << " ";

	return 0;
}

std::vector<int> Lotto(int range, int ball_num)
{
	std::vector<int> all_num;
	std::vector<int> ret_vec;

	for (int i = 1; i <= range; ++i)
		all_num.push_back(i);

	srand(time(NULL));
	std::random_shuffle(all_num.begin(), all_num.end());

	for (int i = 0; i < ball_num; ++i)
		ret_vec.push_back(all_num[i]);

	std::sort(ret_vec.begin(), ret_vec.end());

	return ret_vec;
}