#include "octree.h"

int main()
{
	Octree<int> oct;

	for (int y = 0; y < 100; y += 1)
		for (int x = 0; x < 100; x += 1)
			oct.insert(OctreeKey(0, x, y, 0), 1000*y+x);

			oct.insert(OctreeKey(0, 500, 500, 0), -1);

	std::set<int> wow;
	int s = 2;
	int result = oct.getDataAround(OctreeKey(2, s, s, s), &wow);

	printf("result = %d, %d objects\n", result, wow.size());

	for (int y = 0; y < 100; y += 1)
		for (int x = 0; x < 100; x += 1)
			oct.erase(OctreeKey(0, x, y, 0), 1000*y+x);

			oct.erase(OctreeKey(0, 500, 500, 0), -1);

	

}