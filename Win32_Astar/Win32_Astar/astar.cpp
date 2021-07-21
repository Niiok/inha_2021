#include "astar.h"

int _tile[MAP_SIZE][MAP_SIZE];

list<intXY> astar(intXY src_origin, intXY dst, Astar& map)
{
	for (int y = 0; y < MAP_SIZE; ++y)
		for (int x = 0; x < MAP_SIZE; ++x)
		{
			map.dist_src[y][x] = INT_MAX/2;
			map.dist_tot[y][x] = INT_MAX/2;
			map.prior[y][x] = { -1, -1 };
		}

	map.dist_src[src_origin.y][src_origin.x] = 0;
	map.dist_tot[src_origin.y][src_origin.x] = heuristic(src_origin, dst);
	priority_queue<pair<intXY, pair<int, int>>, vector<pair<intXY, pair<int, int>>>, dist_greater> p_que;
	p_que.push({ src_origin,
		{/*map.dist_src[src_origin.y][src_origin.x] +*/ map.dist_tot[src_origin.y][src_origin.x],
		map.dist_src[src_origin.y][src_origin.x]}
		});
	intXY none = { -1, -1 };


	while (!p_que.empty())
	{
		intXY src = p_que.top().first;
		p_que.pop();

		if (map.dist_src[dst.y][dst.x] != INT_MAX/2)
			break;

		for (int dy = -1; dy < 2; ++dy)
		{
			for (int dx = -1; dx < 2; ++dx)
			{
				if (dx == 0 && dy == 0)
					continue;

				intXY nei;
				nei.x = src.x + dx;
				nei.y = src.y + dy;

				if (nei.x >= MAP_SIZE ||
					nei.y >= MAP_SIZE ||
					nei.x < 0 ||
					nei.y < 0)
					continue;


				if (map.dist_src[src.y][src.x] + (nei.x == src.x || nei.y == src.y ? 10 : 14)
					< map.dist_src[nei.y][nei.x] // better route
					&& _tile[nei.y][nei.x] == 0 // not blocked
					&& nei != map.prior[src.y][src.x]) // dont search prior node	
				{
					map.dist_src[nei.y][nei.x] = map.dist_src[src.y][src.x] + (nei.x == src.x || nei.y == src.y ? 10 : 14);	// new dist_src
					map.dist_tot[nei.y][nei.x] = map.dist_src[nei.y][nei.x] + heuristic(nei, dst);	// new dist_tot
					map.prior[nei.y][nei.x] = src;		// new route
					p_que.push({ nei, {map.dist_tot[nei.y][nei.x], map.dist_src[nei.y][nei.x]} });		// refresh / search

#ifdef _PRINT_PROGRESS
					for (int y = 0; y < MAP_SIZE; ++y)
					{
						for (int x = 0; x < MAP_SIZE; ++x)
						{
							if (_tile[y][x] != 0)
								printf(" XXX");
							else if (map.dist_src[y][x] != INT_MAX)
								printf(" %3d", map.dist_src[y][x]);
							else
								printf("  - ");
						}
						printf("\n");
					}
					printf("\n");
#endif
					if (nei == dst)
					{
						dy = 2;	// outer break
						break;
					}
				}
			}
		}
	}


	list<intXY> route;

	for (intXY i = dst; i != src_origin;)
	{
		if (i == none)
			return list<intXY>();

		route.push_front(i);
		i = map.prior[i.y][i.x];
	}
	route.push_front(src_origin);

	return route;
}



int heuristic(intXY src, intXY dst) noexcept
{
	int dx = abs(src.x - dst.x);
	int dy = abs(src.y - dst.y);
	int bigger = (dx > dy ? dx : dy);

	return (bigger * 14 - abs(dx - dy) * 4);
}