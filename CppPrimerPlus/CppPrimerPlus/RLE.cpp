#include <iostream>
#include <math.h>
#include <limits.h>
#include <vector>
#include <queue>
#include <list>
#include <numeric>

using namespace std;
using gap_index = pair<int, int>;
using value_index = pair<int, int>;


gap_index find_biggest_gap(const vector<int>& arr, int begin, int end)
{

	gap_index ret = {abs(arr[begin+1] - arr[begin+2]), begin+1};

	if (end - begin < 3)
		return ret;

	for (int i = begin+1; i < end-2; ++i)
	{
		if (abs(arr[i] - arr[i + 1]) > ret.first)
			ret = { arr[i] - arr[i + 1], i };
	}

	return ret;
}

vector<int> RLE(vector<int>& arr, int zip_chunk)
{
	vector<int> rle;
	priority_queue<gap_index, vector<gap_index>, greater<gap_index>> candidates;
	
	int arr_len = arr.size();

	for (int i = 1; i < zip_chunk; ++i)
	{
		int index = arr_len / zip_chunk * i;
		if (index + 1 == arr_len)
			break;
		int diff = abs(arr[index] - arr[index + 1]);

		candidates.push({ diff, index });
	}

	for (auto i = arr.begin(); i != --arr.end(); ++i)
	{
		if (abs(*i - *(i + 1)) > candidates.top().first)
		{
			candidates.pop();
			candidates.push({ abs(*i - *(i + 1)),i - arr.begin() });
		}
	}	


	vector<int> ordered;
	for (; !candidates.empty();)
	{
		int ord = candidates.top().second;
		candidates.pop();
		ordered.push_back(ord);
	}
	sort(ordered.rbegin(), ordered.rend());

	//// removing one-iter-gap & wide-iter-gap
	//vector<int> neighboring_index;
	//for (int divided_count = 0; divided_count < ordered.size() - 1; ++divided_count)
	//{
	//	if (ordered[divided_count + 1] - ordered[divided_count] == 1)
	//		neighboring_index.push_back(ordered[divided_count]);
	//}
	//
	//for (int chance = 0; chance < neighboring_index.size(); ++chance)
	//{
	//	pair<int, int> max_gap;	// <iter, gap size>
	//	for (int divided_count = 0; divided_count < ordered.size() - 1; ++divided_count)
	//	{
	//		if (ordered[divided_count + 1] - ordered[divided_count] > max_gap.second)
	//			max_gap = { ordered[divided_count], ordered[divided_count + 1] - ordered[divided_count] };
	//	}

	//	gap_index new_pin = find_biggest_gap(arr, max_gap.first, max_gap.first + max_gap.second);
	//	ordered.push_back(new_pin.second);
	//	sort(ordered.rbegin(), ordered.rend());
	//}

	//for (auto divided_count : neighboring_index)
	//{
	//	gap_index nei1, nei2;
	//	nei1 = { abs(arr[divided_count] - arr[divided_count + 1]), divided_count };
	//	nei2 = { abs(arr[divided_count + 1] - arr[divided_count + 2]), divided_count + 1 };

	//	if (nei1.first < nei2.first)
	//		ordered.erase(find(ordered.begin(), ordered.end(), nei1.second));
	//	else
	//		ordered.erase(find(ordered.begin(), ordered.end(), nei2.second));
	//}


	// making rle_block
	int sum = 0;
	int count = 0;
	for (auto i = arr.begin(); i != arr.end(); ++i)
	{
		sum += *i;
		count++;

		if (!ordered.empty() && i - arr.begin() == ordered.back())
		{
			rle.push_back(count);
			rle.push_back(round((float)sum / count));
			ordered.pop_back();
			sum = 0;
			count = 0;
		}
	}
	rle.push_back(count);
	rle.push_back(sum / count);

	return rle;
}



using rle_block = pair<int, int>;		// count, average

using Chunk = struct Chunk
{
public:
	Chunk(const vector<int>& origin, int begin, int end)
		: origin{ origin }, begin{ begin }, end{end}
	{
		get_error();
	}
	//~Chunk()
	//{
	//	if (this != NULL && divided != NULL)
	//		delete divided;
	//}

private:
	const vector<int>& origin;
	int begin;
	int end;
	long long error_point = -1;
	Chunk* divided = NULL;
	long long divided_error_point = -1;

public:

	long long get_error()
	{
		if (error_point == -1) 
		{
			float average = (float)accumulate(origin.begin() + begin, origin.begin() + end, 0) / (end - begin);

			error_point = 0;
			for (auto i = origin.begin() + begin; i != origin.begin() + end; ++i)
			{
				error_point += (average - *i) * (average - *i);
			}
		}

		return error_point;
	}
	int get_begin()
	{
		return begin;
	}
	int get_end()
	{
		return end;
	}
	void set_begin_end(int new_begin, int new_end)
	{
		begin = new_begin;
		end = new_end;
		error_point = -1;
	}

	void find_divide()
	{
		if (begin + 1 > end)
		{
			divided_error_point = INT_MAX;
			return;
		}

		if (divided == NULL)
		{
			divided = new Chunk(origin, begin, begin + 1);
			Chunk divided2(origin, begin + 1, end);

			divided_error_point = divided->get_error() + divided2.get_error();
			int div_point = begin + 1;

			for (int i = 2; i < end - begin; ++i)
			{
				divided->set_begin_end(begin, begin + i);
				divided2.set_begin_end(begin + i, end);

				if (divided_error_point > divided->get_error() + divided2.get_error())
				{
					divided_error_point = divided->get_error() + divided2.get_error();
					div_point = begin + i;
				}
			}

			divided->set_begin_end(begin, div_point);
		}
	}

	long long get_divided_error()
	{
		if (divided_error_point == -1)
			find_divide();

		return divided_error_point;
	}

	Chunk adjust_divide()
	{
		find_divide();

		Chunk ret = *divided;
		set_begin_end(ret.get_end(), end);

		delete divided;
		divided = NULL;
		divided_error_point = -1;

		return ret;
	}

	rle_block get_rle_block()
	{
		rle_block ret;
		ret.first = end - begin;
		ret.second = round((float)accumulate(origin.begin() + begin, origin.begin() + end, 0) / ret.first);

		return ret;
	}
};



vector<int> RLE2(vector<int>& arr, int zip_chunk)
{
	vector<Chunk> chunks;

	chunks.insert(chunks.begin(), Chunk(arr, 0, arr.size()));

	for (int divided_count = 0; divided_count < zip_chunk - 1; ++divided_count)
	{
		long long max_reduced_error = INT_MIN;
		int div_index;

		for (int i = 0; i < chunks.size(); i++)
		{
			long long error_gap = chunks[i].get_error() - chunks[i].get_divided_error();

			if (error_gap > max_reduced_error)
			{
				max_reduced_error = error_gap;
				div_index = i;
			}
		}

		Chunk to_insert = chunks[div_index].adjust_divide();
		chunks.insert(chunks.begin() + div_index, to_insert);
	}

	vector<int> ret;

	for (auto iter : chunks)
	{
		rle_block to_push_back = iter.get_rle_block();
		ret.push_back(to_push_back.first);
		ret.push_back(to_push_back.second);
	}
	
	return ret;
}

float RMSE(const vector<int>& origin, const vector<int>& rle)
{
	float ret = 0;
	vector<int> unzip;
	for (auto i = rle.begin(); i != rle.end();)
	{
		for (int j = *i; j > 0; --j)
		{
			unzip.push_back(*(i + 1));
		}
		++i; ++i;
	}

	for (int i = 0; i < origin.size(); ++i)
	{
		ret += (origin[i] - unzip[i]) * (origin[i] - unzip[i]);
	}

	ret /= origin.size();
	ret = sqrt(ret);

	return ret;
}


int main(int argc, char** argv)
{
	int in;
	vector<int> arr;

	cin >> in;

	for (int i = 0; i < in; i++)
	{
		int num;
		cin >> num;

		arr.push_back(num);
	}

	cin >> in;

	vector<int> rle = RLE2(arr, in);

	for (auto i = rle.begin(); i != rle.end();)
	{
		printf("(%3d, ", *(i++));
		printf("%3d) ", *(i++));
		if ((i - rle.begin()) % 16 == 0)
			printf("\n");
	}

	printf("%f", RMSE(arr, rle));
	printf("\n");
}