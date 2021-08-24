#include "RB_Player.h"

RB_Player::~RB_Player()
{
	for (auto it = attached_.begin(); it != attached_.end(); ++it)
		delete *it;
}

void RB_Player::Plan()
{
	oun::floatXYZ plan = getLocation();
	float plan_vol = getVolume();
	int dir_x = 1;
	int dir_y = 1;

	if (SDLpp_Game::keystate[SDL_SCANCODE_UP])
	{
		plan.y -= getSpeed() * plan_vol;
		dir_y--;
	}
	if (SDLpp_Game::keystate[SDL_SCANCODE_DOWN])
	{
		plan.y += getSpeed() * plan_vol;
		dir_y++;
	}
	if (SDLpp_Game::keystate[SDL_SCANCODE_LEFT])
	{
		plan.x -= getSpeed() * plan_vol;
		dir_x--;
	}
	if (SDLpp_Game::keystate[SDL_SCANCODE_RIGHT])
	{
		plan.x += getSpeed() * plan_vol;
		dir_x++;
	}
	if (SDLpp_Game::keystate[SDL_SCANCODE_EQUALS])
		plan_vol *= 1.1;
	if (SDLpp_Game::keystate[SDL_SCANCODE_MINUS])
		plan_vol /= 1.1;
	if (SDLpp_Game::keystate[SDL_SCANCODE_ESCAPE])
	{
		auto& arounds = RB_Manager::Instance().getObjects();

		for (auto it = arounds.begin(); it != arounds.end();)
		{
			auto value = *(it++);
			
			delete (Object*)value;
		}

	}

	getWorld()->setZoom(5 / getVolume() + 3);

	setPlanLocation(plan);
	if (plan_vol * getWorld()->getZoom() * 2 < MAX_SPACE_SCALE)
		setPlanVolume(plan_vol);

	//	0	1	2
	//	3	4	5
	//	6	7	8
	state_ = SDLpp_Animator::State_Walk;

	switch (dir_x + dir_y * 3)
	{
	case 4: // idle
		state_ = SDLpp_Animator::State_Idle;
		direct_ = SDLpp_Animator::Left;
		break;
	case 0:	// up-left
		direct_ = SDLpp_Animator::UpLeft;
		break;
	case 1:	// up
		direct_ = SDLpp_Animator::Up;
		break;
	case 2:	// up-right
		direct_ = SDLpp_Animator::UpRight;
		break;
	case 3:	// left
		direct_ = SDLpp_Animator::Left;
		break;
	case 5:	// right
		direct_ = SDLpp_Animator::Right;
		break;
	case 6:	// down-left
		direct_ = SDLpp_Animator::DownLeft;
		break;
	case 7:	// down
		direct_ = SDLpp_Animator::Down;
		break;
	case 8:	// down-right
		direct_ = SDLpp_Animator::DownRight;
		break;
	default:
		assert(dir_x + dir_y * 3 > 8);
		break;
	}

}

void RB_Player::Update()
{

	collision_ = ObjectArea((iObject*)this);
	collision_.x += collision_.w * 0.2;
	collision_.y += collision_.w * 0.4;
	collision_.w *= 0.6;
	collision_.h *= 0.6;

	auto& objects = RB_Manager::Instance().getWorld().getObjectsAround();

	for (auto it = objects.begin(); it != objects.end();)
	{
		if (*it == this)
		{
			it++;
			continue;
		}

		auto value = *it;
		++it;

		if (CheckCollision(value))
		{
			if (getVolume() > (value)->getVolume() * 2)
				AttachObjectToBall((RB_Object*)value);
			else
			{
				setPlanLocation(getLocation());
				break;
			}
		}
	}

	Locate();


}

void RB_Player::Draw() const
{
	SDL_Rect area = ObjectArea((iObject*)this);

	//SDL_RenderCopy(SDLpp_Game::renderer, )
	/*SDL_SetRenderDrawColor(SDLpp_Game::renderer, 200, 200, 200, 100);
	SDL_RenderFillRect(SDLpp_Game::renderer, &area);*/
	
	animator_->DrawSprite(state_, direct_, (SDL_GetTicks() % 390)/100, &area);

	// attacheds
	for (auto it = attached_.begin(); it != attached_.end(); ++it)
	{
		SDL_SetRenderDrawColor(SDLpp_Game::renderer, 100, 0, 50, 30);
		//SDL_RenderFillRect(SDLpp_Game::renderer, );
	}


	//printf("%d : %f %f\n", in_world_, getLocation().x, getLocation().y);
	//printf("%f %f\n\n", getPlanLocation().x, getPlanLocation().y);
}



bool RB_Player::OverlapRect(SDL_Rect a, SDL_Rect b) const
{
	int a_x = (a.x * 2 + a.w) / 2;
	int a_y = (a.y * 2 + a.h) / 2;
	int b_x = (b.x * 2 + b.w) / 2;
	int b_y = (b.y * 2 + b.h) / 2;

	if (abs(a_x - b_x) <= a.w / 2 + b.w / 2 &&
		abs(a_y - b_y) <= a.h / 2 + b.h / 2)
		return true;
	else
		return false;
}

bool RB_Player::CheckCollision(iObject * obj) const
{
	SDL_Rect obj_rect = ObjectArea(obj);
	obj_rect.h /= 2;
	obj_rect.y += obj_rect.h;

#ifdef COLLISION_SHOW
	SDL_SetRenderDrawColor(SDLpp_Game::renderer, 255, 0, 0, 125);
	SDL_RenderDrawRect(SDLpp_Game::renderer, &obj_rect);
	SDL_SetRenderDrawColor(SDLpp_Game::renderer, 0, 255, 0, 125);
	SDL_RenderDrawRect(SDLpp_Game::renderer, &collision_);
#endif

	if (OverlapRect(obj_rect, collision_))
		return true;
	else
		return false;
}


bool RB_Player::AttachObjectToBall(RB_Object * obj)
{
	if (!obj->Quit())
		return false;

	RB_Manager::Instance().getObjects().erase((RB_Object*)obj);

	attached_.push_back(obj);
	if (attached_.size() > MAX_ATTACHED_OBJECTS_ON_BALL)
	{
		delete attached_.front();
		attached_.pop_front();
	}

	setPlanVolume(getVolume() + obj->getVolume() / 32);

	return true;
}
