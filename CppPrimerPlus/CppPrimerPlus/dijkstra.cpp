#include <iostream>
#include <vector>
#include <list>
#include <queue>

#define _PRINT_PROGRESS

using namespace std;

vector<vector<int>> _matrix;
vector<int> _distance;
vector<int> _prior;

class dist_greater {
public:
	bool operator() (pair<int, int> a, pair<int, int> b)
	{
		if (a.second > b.second)
			return true;
		else
			return false;
	}
};

list<int> dijkstra(int src, int dst);


int main()
{
	int node_num = 0;
	int src, dst;

	printf("edge weight input : ");
	cin >> node_num;

	for (int i = 0; i < node_num; ++i)
	{
		_matrix.push_back(vector<int>());

		for (int j = 0; j < node_num; ++j)
		{
			int num;
			cin >> num;

			_matrix[i].push_back(num);
		}

		_distance.push_back(INT_MAX);
		_prior.push_back(-1);
	}


	printf("source and destination input : ");
	cin >> src >> dst;
	rewind(stdin);

	_distance[src] = 0;

	list<int> result = dijkstra(src, dst);


	printf("\n");
	for (auto i = result.begin(); i != result.end(); ++i)
	{
		printf(" %d ->", *i);
	}
	printf("\b\b  \n\t minimum weight : %d\n", _distance[dst]);

	return 0;
}

list<int> dijkstra(int src_origin, int dst)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, dist_greater> _s_que;
	_s_que.push({src_origin, _distance[src_origin]});


	while (!_s_que.empty())
	{
		int src = _s_que.top().first;
		_s_que.pop();

		if (src == dst)
			break;

		for (int i = 0; i < _matrix[src].size(); ++i)
		{
			if (_distance[src] + _matrix[src][i] < _distance[i] &&	// better route
				_matrix[src][i] != 0)	// have edge
			{
				_distance[i] = _distance[src] + _matrix[src][i];	// new weight
				_prior[i] = src;		// new route
				_s_que.push({ i, _distance[i] });			// refresh/search

#ifdef _PRINT_PROGRESS
				for (int j = 0; j < _matrix.size(); ++j)
				{
					if (_distance[j] != INT_MAX)
						printf(" %2d", _distance[j]);
					else
						printf("  -");
				}
				printf("\n");
#endif
			}
		}

	}


	list<int> route;

	for (int i = dst; i != src_origin;)
	{
		if (i == -1)
			return list<int>();

		route.push_front(i);
		i = _prior[i];
	}
	route.push_front(src_origin);

	return route;
}
