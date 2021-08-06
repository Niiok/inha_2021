#include "octree.h"

int main()
{
	Octree<int> oct;
	OctreeKey key(1, 0, 0, 0);

	for (int y = 0; y < MAX_OCTREE_SCALE; y += 10000)
		for (int x = 0; x < MAX_OCTREE_SCALE; x += 10000)
			oct.insert(OctreeKey(1, x, y, 0), x*y/10000);
	
	for (int y = 0; y < MAX_OCTREE_SCALE; y += 10000)
		for (int x = 0; x < MAX_OCTREE_SCALE; x += 10000)
			oct.erase(OctreeKey(1, x, y, 0), x*y/10000);


	

}