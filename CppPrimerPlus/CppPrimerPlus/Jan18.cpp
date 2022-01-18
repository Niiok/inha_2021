#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

using Pos = pair<int, int>;

using Gunner = struct Gunner
{
	Gunner(Pos pos, vector<vector<bool>>& stage)
		: pos{ pos }
	{
		auto find_result = ranges.find(pos);

		if (find_result == ranges.end())
		{
			// x++
			Pos area = pos;
			area.second++;
			for (; area.second < stage[0].size(); area.second++)
			{
				if (stage[area.first][area.second])
					break;
				else
					killable_area.insert(area);
			}

			// x--
			area = pos;
			area.second--;
			for (; area.second >= 0; area.second--)
			{
				if (stage[area.first][area.second])
					break;
				else
					killable_area.insert(area);
			}

			// y++
			area = pos;
			area.first++;
			for (; area.first < stage.size(); area.first++)
			{
				if (stage[area.first][area.second])
					break;
				else
					killable_area.insert(area);
			}

			// y--
			area = pos;
			area.first--;
			for (; area.first >= 0; area.first--)
			{
				if (stage[area.first][area.second])
					break;
				else
					killable_area.insert(area);
			}

			ranges.insert({ pos, killable_area });
		}
		else
			killable_area = (*find_result).second;
	}

	static map<Pos, set<Pos>> ranges;

	Pos pos;
	set<Pos> killable_area;
};

map<Pos, set<Pos>> Gunner::ranges;

void show_map(vector<vector<bool>>& stage, vector<Gunner>& gunners)
{
	Pos pos = { 0,0 };

	printf("\n");

	for (pos.first = 0; pos.first < stage.size(); pos.first++)
	{
		for (pos.second = 0; pos.second < stage[0].size(); pos.second++)
		{
			bool gunner = false;

			for (auto& g : gunners)
			{
				if (g.pos == pos)
				{
					gunner = true;
					printf("♂");
					break;
				}
			}

			if (!gunner)
				if (stage[pos.first][pos.second])
					printf("■");
				else
					printf("□");
		}
		printf("\n");
	}

}


void recur_gunner(pair<int, int>& sol, vector<vector<bool>>& stage, vector<Gunner>& gunners)
{
	Pos area = { 0,0 };

	if (!gunners.empty())
	{
		area = gunners.back().pos;

		if (area.second == stage[0].size() - 1)
		{
			area.first++;
			area.second = 0;
		}
		else
			area.second++;
	}


	for (; area.first < stage.size(); area.first++)
	{
		for (; area.second < stage[0].size(); area.second++)
		{
			bool died = false;

			for (auto& g : gunners)
			{
				if (g.killable_area.find(area) == g.killable_area.end())
					continue;
				else
				{
					died = true;
					break;
				}
			}

			if (died || stage[area.first][area.second])
				continue;

			gunners.push_back(Gunner(area, stage));

			recur_gunner(sol, stage, gunners);

			gunners.pop_back();
		}
		area.second = 0;
	}

	if (sol.first == gunners.size())
	{
		sol.second++;
		show_map(stage, gunners);
	}
	else if (sol.first < gunners.size())
	{
		sol.first = gunners.size();
		sol.second = 1;
		show_map(stage, gunners);
	}
}


pair<int, int> best_peace(vector<vector<bool>>& stage)
{
	pair<int, int> solution = { 0,0 };
	vector<Gunner> gunners;

	recur_gunner(solution, stage, gunners);

	return solution;
}




int main(int argc, char** argv)
{
	int map_size;
	vector<vector<bool>> stage;

	cin >> map_size;

	stage.assign(map_size, vector<bool>());
	for (auto& v : stage)
		v.assign(map_size, false);

	wchar_t input;
	int y = 0;
	int x = 0;

	while (wscanf(L"%c", &input) && y < map_size)
	{
		bool in = false;
		//printf("%d ", input);

		if (x == map_size)
		{
			y++;
			x = 0;
		}

		if (input == 224)
		{
			stage[y][x] = false;
			in = true;
		}
		else if (input == 225)
		{
			stage[y][x] = true;
			in = true;
		}

		if (in)
			if (x < stage[y].size())
				++x;
	}

	pair<int,int> solution = best_peace(stage);

	printf("최대 %d명, %d가지", solution.first, solution.second);

}