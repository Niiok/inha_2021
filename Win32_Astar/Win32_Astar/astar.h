#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <queue>

//#define _PRINT_PROGRESS
#define MAP_SIZE 50

using namespace std;

typedef struct intXY {
	int x = -1;
	int y = -1;

	inline bool operator== (intXY comp) const noexcept { return x == comp.x && y == comp.y; }
	inline bool operator!= (intXY comp) const noexcept { return !operator== (comp); }

}intXY;


typedef struct Astar {
	int dist_src[MAP_SIZE][MAP_SIZE];
	int dist_tot[MAP_SIZE][MAP_SIZE];
	intXY prior[MAP_SIZE][MAP_SIZE];
} Astar;

class dist_greater {
public:
	inline bool operator() (pair<intXY, pair<int, int>> a, pair<intXY, pair<int, int>> b) const noexcept
	{
		if (a.second.first != b.second.first)
			return a.second.first > b.second.first;	// compare total distance
		else
			return a.second.second > b.second.second;	// compare src distance
	}
};

list<intXY> astar(intXY src, intXY dst, Astar& map);

int heuristic(intXY src, intXY dst) noexcept;