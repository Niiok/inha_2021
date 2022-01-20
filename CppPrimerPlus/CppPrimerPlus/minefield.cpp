#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

using Pos = pair<int, int>;

struct Clue;
struct Context;

using Clue = struct Clue
{
	const Pos pos_;
	Context* const context_;

	int mine_around_count_ = 0;
	bool solved_ = false;
	list<Pos> unknowns_;


	Clue(Pos position, Context* context);
	void SearchAround();
};


using Context = struct Context
{
	vector<string> minefield_;
	list<Clue> clues_;
	bool clues_need_review_ = true;


	Context(vector<string>& minefield);
	void SolveMinefield();
};


Clue::Clue(Pos position, Context* context)
	: pos_{ position }, context_{ context }
{
	mine_around_count_ = context->minefield_[pos_.first][pos_.second] - '0';
}

void Clue::SearchAround()
{
	if (solved_)
		return;

	int field_count = 0;
	int safe_count = 0;
	int mine_found_count = 0;
	int unknown_count = 0;

	unknowns_.clear();

	for (int y = pos_.first - 1; y <= pos_.first + 1; ++y)
		for (int x = pos_.second - 1; x <= pos_.second + 1; ++x)
		{
			if (y < 0 || y >= context_->minefield_.size() ||
				x < 0 || x >= context_->minefield_[0].size())
				continue;

			field_count++;

			switch (context_->minefield_[y][x])
			{
			case '.':
				unknown_count++;
				unknowns_.push_back({ y, x });
				break;
			case 'M':
				mine_found_count++;
				break;
			case 'S':
			default:	// 0 ~ 8
				safe_count++;
				break;
			}
		}


	// case : all mines already found
	if (mine_found_count == mine_around_count_)
	{
		for (auto i : unknowns_)
			context_->minefield_[i.first][i.second] = 'S';

		unknowns_.clear();
		solved_ = true;
		context_->clues_need_review_ = true;
		return;
	}

	// case : every unknowns_ are mine
	if ((mine_around_count_ - mine_found_count) == unknown_count)
	{
		for (auto i : unknowns_)
			context_->minefield_[i.first][i.second] = 'M';

		unknowns_.clear();
		solved_ = true;
		context_->clues_need_review_ = true;
		return;
	}

	// case : not solved_
	solved_ = false;
	return;
}

Context::Context(vector<string>& minefield)
	:minefield_{ minefield }
{
	for (int y = 0; y < minefield.size(); y++)
		for (int x = 0; x < minefield[y].size(); x++)
		{
			switch (minefield[y][x])
			{
			case '.':
			case 'M':
			case 'S':
				break;

			default:	// 0 ~ 8
				clues_.push_back(Clue({ y,x }, this));
				break;
			}
		}
}

void Context::SolveMinefield()
{
	while (clues_need_review_)
	{
		clues_need_review_ = false;

		for (auto& c : clues_)
		{
			// clue make `clues_need_review_` true if they find out all mines around
			c.SearchAround();
			
			// reset searched results and search again
			if (clues_need_review_)
				break;
		}
	}

	for (auto& c : clues_)
	{
		if (!c.solved_)
			for (auto& i : c.unknowns_)
				minefield_[i.first][i.second] = '?';
	}
}




int main(int argc, char** argv)
{
	vector<string> minefield;
	minefield.push_back(".1...2");
	minefield.push_back("111.3.");

	Context solver(minefield);
	solver.SolveMinefield();

	for (auto& s : solver.minefield_)
		cout << s << endl;
	


	minefield.clear();
	minefield.push_back(".3....");
	minefield.push_back("1..20.");

	Context solver2(minefield);
	solver2.SolveMinefield();

	cout << endl;
	for (auto& s : solver2.minefield_)
		cout << s << endl;
}