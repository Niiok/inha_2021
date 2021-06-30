#include "GamePlay.h"

using namespace Game;


GamePlay::GamePlay(HWND hWnd) : GameState(hWnd)
{
	for (int i = 0; i < num_of_wall_; ++i)
		walls_.push_back(DefenseWall(i, num_of_wall_));

	prev_score_ = score_;
}
GamePlay::~GamePlay()
{

}


int GamePlay::Draw(HDC hdc)
{

	gap_ += score_ - prev_score_;
	gap_ += score_ - prev_score_;
	if (gap_ > 0)
		gap_--;
	if (gap_ > 0)
		gap_--;
	prev_score_ = score_;

	GetClientRect(hWnd_, &client_);
	client_.bottom = client_.bottom - client_.top;
	client_.right = client_.right - client_.left;
	client_.top = 0;
	client_.left = 0;

	for (auto i : bullets_)
		i.Draw(hdc, client_);
	turret_.Draw(hdc, client_);
	for (auto i : walls_)
		i.Draw(hdc, client_);
	for (auto i : enemies_)
		i.Draw(hdc, client_);

	char str[32];
	wchar_t wstr[32];
	sprintf(str, "Spawn Rate : %f", spawn_rate_);
	mbstowcs(wstr, str, strlen(str) + 1);
	LPWSTR wptr = wstr;
	TextOut(hdc, client_.right*0.43f, client_.bottom*0.15f + 16, wptr, _tcslen(wstr));

	sprintf(str, "Score : %d", score_);
	mbstowcs(wstr, str, strlen(str) + 1);
	wptr = wstr;
	TextOut(hdc, client_.right*0.46f, client_.bottom*0.15f - gap_, wptr, _tcslen(wstr));

	TextOut(hdc, client_.right*0.01f, client_.bottom*0.01f, str_, _tcslen(str_));

	return 0;
}

int GamePlay::Update()
{
	static float cool_down = spawn_rate_;

	for (auto i = bullets_.begin() ; i != bullets_.end();)
	{
		int ret = i->Update(enemies_, client_);
		if (ret == -1)
			i = bullets_.erase(i);
		else if (ret < -1)
		{
			i = bullets_.erase(i);
			score_ -= ret;
		}
		else
			++i;
	}

	for (auto i = enemies_.begin(); i != enemies_.end();)
	{
		int ret = i->Update(walls_, client_);
		if (ret == -1)
			i = enemies_.erase(i);
		else if (ret == -100)
		{
			return Next();
		}
		else 
			++i;
	}

	cool_down -= 1.0f;
	if (cool_down <= 0.0f)
	{
		cool_down = spawn_rate_;
		float blah = (rand() % 1000) / 10000.0f + 0.95f;
		spawn_rate_ *= blah;
		enemies_.push_back(Enemy());
	}
	return 0;
}

int GamePlay::Input(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_LEFT:
		case 'A':
			turret_.SpinCCW();
			turret_.Shoot(bullets_);
			break;
		case VK_RIGHT:
		case 'D':
			turret_.SpinCW();
			turret_.Shoot(bullets_);
			break;
		case VK_SPACE:
			turret_.Shoot(bullets_);
			break;
		}
		break;
	case WM_KEYUP:
		break;
	case WM_CHAR:
		break;
	case WM_LBUTTONDOWN:
		turret_.Shoot(bullets_);
		break;
	case WM_RBUTTONDOWN:
		break;
	}

	return 0;
}

int GamePlay::Next()
{
	GameOver* temp = new GameOver(hWnd_);
	temp->SetChar(str_);
	temp->SetScore(score_);

	next_ = temp;
	b_quit_ = 1;
	return 0;
}

int GamePlay::SetChar(TCHAR* str)
{
	_tcscpy(str_, str);
	
	return 0;
}





void Turret::Draw(HDC hdc, RECT client)
{
	MoveToEx(hdc, client.right * center_.x, client.bottom * center_.y, NULL);
	LineTo(hdc, client.right * (center_.x + cosf(spin_ * TORAD)) ,
		client.bottom * (center_.y - sinf(spin_ * TORAD)));

	Ellipse(hdc, client.right * center_.x - radius_,
		client.bottom * center_.y - radius_,
		client.right * center_.x + radius_,
		client.bottom * center_.y + radius_);
}

void Turret::Shoot(std::vector<Bullet>& buls)
{
	buls.push_back(Bullet(spin_));
}


Bullet::Bullet(float spin)
{
	vec_ = { cosf(spin*TORAD)*0.1f, sinf(spin*TORAD)*-0.1f };
	//center_.x += cosf(spin*TORAD)*0.1f;
	//center_.y -= sinf(spin*TORAD)*0.1f;

}

void Bullet::Draw(HDC hdc, RECT client)
{
	HBRUSH new_brush = CreateSolidBrush(RGB(0, 0, 0));
	HBRUSH old_brush = (HBRUSH)SelectObject(hdc, new_brush);

	Ellipse(hdc, client.right * center_.x - radius_,
		client.bottom * center_.y - radius_,
		client.right * center_.x + radius_,
		client.bottom * center_.y + radius_);

	SelectObject(hdc, old_brush);
	DeleteObject(new_brush);
}

int Bullet::Update(std::vector<Enemy>& enemies, RECT client)
{
	center_.x += vec_.x;
	center_.y += vec_.y;

	if (center_.x < -0.5 || center_.x > 1.5 || center_.y < -0.5 || center_.y > 1.5)
		return -1;

	return Collision(enemies, client);
}

int Bullet::Collision(std::vector<Enemy>& enemies, RECT client)
{
	for (auto i = enemies.begin(); i != enemies.end(); )
	{
		if (client.right * center_.x - radius_ <= i->center_.x*client.right + i->width_ / 2 
			&& client.right * center_.x + radius_ >= i->center_.x*client.right - i->width_ / 2)
		{
			if (client.bottom * center_.y - radius_ <= i->center_.y*client.bottom + i->height_ / 2 
				&& client.bottom * center_.y + radius_ >= i->center_.y*client.bottom - i->height_ / 2)
			{
				i->hp_ -= damage_;
				if (i->hp_ <= 0)
				{
					i = enemies.erase(i);
					return -5;
				}
				return -2;
			}
			else
				++i;
		}
		else
			++i;
	}

	return 0;
}


Enemy::Enemy()
{
	int random = rand();
	center_ = { float(random %1024)/1024.0f, -0.1f };
	vec_ = { 0.0f, float(random % 10) / 1500.0f };
	width_ = random % 30 + 20;
	height_ = random % 101 + 50;
}

void Enemy::Draw(HDC hdc, RECT client)
{
	HBRUSH new_brush = CreateSolidBrush(RGB(255, (WORD)255 - hp_, (WORD)255 - hp_));
	HBRUSH old_brush = (HBRUSH)SelectObject(hdc, new_brush);

	Rectangle(hdc, center_.x*client.right - width_ / 2,
		center_.y*client.bottom - height_ / 2,
		center_.x*client.right + width_ / 2,
		center_.y*client.bottom + height_ / 2);

	SelectObject(hdc, old_brush);
	DeleteObject(new_brush);
}

int Enemy::Update(std::vector<DefenseWall>& walls, RECT client)
{
	center_.x += vec_.x;
	center_.y += vec_.y;

	if (center_.x < -0.5 || center_.x > 1.5 || center_.y < -0.5 )
		return -1;

	if (Collision(walls, client) == -1)
		return -1;

	if (center_.y > 1.0)
		return -100;

	return 0;
}

int Enemy::Collision(std::vector<DefenseWall>& walls, RECT client)
{
	for (auto i = walls.begin(); i != walls.end(); )
	{
		if (center_.x > i->point_.x && center_.x < i->point_.x + (float)1/i->total_)
		{
			if (i->point_.y * client.bottom < center_.y*client.bottom + height_ / 2)
			{
				i->hp_ -= damage_;
				if (i->hp_ <= 0)
					i = walls.erase(i);
				return -1;
			}
			else
				++i;
		}
		else
			++i;
	}

	return 0;
}


DefenseWall::DefenseWall(int number, int total)
{
	point_.x = (float)number / (float)total;
	point_.y = 0.9f;
	total_ = total;
}

void DefenseWall::Draw(HDC hdc, RECT client)
{
	HBRUSH new_brush = CreateSolidBrush(RGB((WORD)255 - hp_, (WORD)hp_, 0));
	HBRUSH old_brush = (HBRUSH)SelectObject(hdc, new_brush);

	Rectangle(hdc, point_.x * client.right,
		point_.y* client.bottom,
		point_.x*client.right + client.right / total_,
		point_.y*client.bottom + client.bottom / total_);

	SelectObject(hdc, old_brush);
	DeleteObject(new_brush);
}
