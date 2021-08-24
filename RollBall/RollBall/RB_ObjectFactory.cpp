#include "RB_ObjectFactory.h"

int RB_ObjectFactory::instance_count = 0;
std::map<RB_Object::ID, SDLpp_Animator*> RB_ObjectFactory::animators;

RB_ObjectFactory::RB_ObjectFactory()
{
	++instance_count;
}

RB_ObjectFactory::~RB_ObjectFactory()
{
	--instance_count;

	if (instance_count == 0)
	{
		for (auto it = animators.begin(); it != animators.end(); ++it)
			delete it->second;

		animators.clear();
	}
	else if (instance_count < 0)
		SDL_assert(!"RB_ObjectFactory : instance count has corrupted!");
}


RB_Object * RB_ObjectFactory::Create(RB_Object::ID id, float x, float y)
{
	RB_Object* ret = NULL;

	switch (id)
	{
	case RB_Object::ID_Player:
		ret = new RB_Player(RB_Manager::Instance().getWorld().getCenterSpace(), { x, y, 0 }, 0.5);
		((RB_Player*)ret)->setSpeed(0.1);
		RB_Manager::Instance().getWorld().setFocus((oun::iDomain*)ret);
		break;

	case RB_Object::ID_Crab:
		ret = new RB_Object(RB_Manager::Instance().getWorld().getCenterSpace(), { x, y, 0 }, 0.1);
		break;

	case RB_Object::ID_Box:
		ret = new RB_Object(RB_Manager::Instance().getWorld().getCenterSpace(), { x, y, 0 }, 0.5);
		break;

	case RB_Object::ID_Cow:
		ret = new RB_Object(RB_Manager::Instance().getWorld().getCenterSpace(), { x, y, 0 }, 2);
		break;

	case RB_Object::ID_House:
		ret = new RB_Object(RB_Manager::Instance().getWorld().getCenterSpace(), { x, y, 0 }, 5);
		break;
		
	case RB_Object::ID_Tree:
		ret = new RB_Object(RB_Manager::Instance().getWorld().getCenterSpace(), { x, y, 0 }, 10);
		break;
	
	case RB_Object::ID_Building:
		ret = new RB_Object(RB_Manager::Instance().getWorld().getCenterSpace(), { x, y, 0 }, 30);
		break;

	default:
		assert(!"Wrong Object ID");
		break;
	}


	// set animator
	auto it = animators.find(id);
	if (it == animators.end())
	{
		switch (id)
		{
		case RB_Object::ID_Player:
			SetPlayerAnim();
			break;
		case RB_Object::ID_Box:
			SetBoxAnim();

		default:
			break;
		}

		it = animators.find(id);
	}

	if (it != animators.end())
		ret->setAnimator(it->second);

	return ret;
}


void RB_ObjectFactory::SetPlayerAnim()
{
	//	0	1	2
	//	3	4	5
	//	6	7	8

	SDLpp_Animator* player_anim_ = new SDLpp_Animator("../data/prince.png");
	SDL_Rect area = { 0, 0, 64, 64 };

	// idle left
	for (int x = 0; x < 3; ++x)
	{
		area.x = 64 * x;
		player_anim_->AddArea(SDLpp_Animator::State_Idle, SDLpp_Animator::Left, x, &area, SDL_FLIP_NONE);
	}

	// walk down
	area.y = 64;
	for (int x = 0; x < 4; ++x)
	{
		area.x = 64 * x;
		player_anim_->AddArea(SDLpp_Animator::State_Walk, SDLpp_Animator::Down, x, &area, SDL_FLIP_NONE);
	}

	// walk down left & down right
	area.y = 128;
	for (int x = 0; x < 4; ++x)
	{
		area.x = 64 * x;
		player_anim_->AddArea(SDLpp_Animator::State_Walk, SDLpp_Animator::DownLeft, x, &area, SDL_FLIP_NONE);
		player_anim_->AddArea(SDLpp_Animator::State_Walk, SDLpp_Animator::DownRight, x, &area, SDL_FLIP_HORIZONTAL);
	}

	// walk left & right
	area.y = 192;
	for (int x = 0; x < 4; ++x)
	{
		area.x = 64 * x;
		player_anim_->AddArea(SDLpp_Animator::State_Walk, SDLpp_Animator::Left, x, &area, SDL_FLIP_NONE);
		player_anim_->AddArea(SDLpp_Animator::State_Walk, SDLpp_Animator::Right, x, &area, SDL_FLIP_HORIZONTAL);
	}

	// walk up left & up right
	area.y = 256;
	for (int x = 0; x < 4; ++x)
	{
		area.x = 64 * x;
		player_anim_->AddArea(SDLpp_Animator::State_Walk, SDLpp_Animator::UpLeft, x, &area, SDL_FLIP_NONE);
		player_anim_->AddArea(SDLpp_Animator::State_Walk, SDLpp_Animator::UpRight, x, &area, SDL_FLIP_HORIZONTAL);
	}

	// walk up
	area.y = 320;
	for (int x = 0; x < 4; ++x)
	{
		area.x = 64 * x;
		player_anim_->AddArea(SDLpp_Animator::State_Walk, SDLpp_Animator::Up, x, &area, SDL_FLIP_NONE);
	}

	animators.insert({ RB_Object::ID_Player, player_anim_});
}

void RB_ObjectFactory::SetBoxAnim()
{
	SDLpp_Animator* box_anim_ = new SDLpp_Animator("../data/box.png");
	SDL_Rect area = { 0, 0, 512, 512 };

	// idle middle
	for (int x = 0; x < 1; ++x)
	{
		//area.x = 64 * x;
		box_anim_->AddArea(SDLpp_Animator::State_Idle, SDLpp_Animator::Middle, x, &area, SDL_FLIP_NONE);
	}

	animators.insert({ RB_Object::ID_Box, box_anim_});
}
