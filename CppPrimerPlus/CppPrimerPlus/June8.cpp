#include"TnT.h"
#include"queue.h"
#include<vector>
#include<algorithm>


int problem1();
int p1_solution(int l, std::vector<int> v);
int c14p3();

int main()
{
	problem1();

}

int problem1()
{
	std::vector<int> street_lamps = { 15, 5, 3, 7, 9, 14, 0 };
	int road_length = 15;

	std::cout << p1_solution(road_length, street_lamps);

	return 0;
}

int p1_solution(int l, std::vector<int> v)
{
	int v_length = v.size();
	int max_dist;
	int d;

	std::sort(v.begin(), v.end());
	v.push_back(l + (l-v.back()));		//end of road

	max_dist =  v[0] + v[0];		//start of road



	for (int i = 0; i < v_length; ++i)
	{
		if (v[i + 1] - v[i] > max_dist)
			max_dist = v[i + 1] - v[i];
	}

	d = ceil((double)max_dist / 2);
	
	v.pop_back();

	return d;
}

int c14p3()
{

}