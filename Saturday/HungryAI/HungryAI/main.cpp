#include <stdio.h>

class World;
class HungryAI;

class HungryAI
{
	float hungry_point = 1.0f;
	int breads;
	bool ate = false;
	bool CanIEat();
	bool AmIFull();

public:
	void Action(World* world);
};

class World
{
	HungryAI agent;

public:
	int bread_count = 20;

	void MainLoop()
	{
		for(int i = 0; i < 30; ++i)
		{
			agent.Action(this);
		}
	}
};

int main()
{
	World world;

	world.MainLoop();
}


bool HungryAI::CanIEat()
{
	if (breads > 0)
		return true;
	else
		return false;
}

bool HungryAI::AmIFull()
{
	if (hungry_point > 0)
		return false;
	else
		return true;
}

void HungryAI::Action(World* world)
{
	breads = world->bread_count;


	bool am_i_full = AmIFull();
	bool can_i_eat = CanIEat();


	if (am_i_full == true)
	{
		printf("I AM FULL\n");
		ate = false;
	}
	else if (can_i_eat == true)
	{
		printf("I EAT BREAD\n");
		ate = true;
		hungry_point -= 0.1f;
	}
	else if(can_i_eat == false)
	{
		printf("NOTHING TO EAT\n");
		ate = false;
	}


	if (ate == true)
		world->bread_count--;
}