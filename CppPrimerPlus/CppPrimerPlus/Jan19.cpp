#include <set>
#include <iostream>
#include <numeric>

using namespace std;

int genenumber(int generator)
{
	int ret = generator;

	while (generator > 0)
	{
		ret += generator % 10;
		generator *= 0.1f;
	}

	return ret;
}


int main(int argc, char** argv)
{
	set<int> gene_nums;
	int whole_accumulate;
	int neg_accumulate;
	int N = 5000;

	whole_accumulate = N * (N - 1) * 0.5f;

	for (int i = 1; i < N; ++i)
	{
		int self = genenumber(i);
		if (self < N)
			gene_nums.insert(self);
	}
	neg_accumulate = accumulate(gene_nums.begin(), gene_nums.end(), 0);

	cout << whole_accumulate - neg_accumulate;
}