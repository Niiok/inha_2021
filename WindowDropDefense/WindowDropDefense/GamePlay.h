#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include "GameLogin.h"
#include "GameOver.h"
#include "GameState.h"
#include <vector>
#include <math.h>
#include <atlbase.h>

#define TORAD M_PI / 180

namespace Game {

	struct XY {
		float x;
		float y;
	};


	class Bullet;
	class Enemy;
	class DefenseWall;


	class Turret {
	public:
		Turret() {};
	private:
		XY center_ = { 0.5f, 0.95f };
		float spin_ = 90.0f;
		int radius_ = 100;
	public:
		void Draw(HDC hdc, RECT client);
		inline void SpinCW() { spin_ = (spin_ <= -10 ? 185 : spin_ - 2); }
		inline void SpinCCW() { spin_ = (spin_ >= 190 ? -5 : spin_ + 2); }
		void Shoot(std::vector<Bullet>& buls);
	};


	class Bullet {
	public:
		Bullet(float spin);
	private:
		XY center_ = { 0.5f, 0.95f };
		XY vec_;
		float damage_ = 70.0f;
		float radius_ = 10.0f;
	public:
		void Draw(HDC hdc, RECT client);
		int Update(std::vector<Enemy>& enemies, RECT client);
		int Collision(std::vector<Enemy>& enemies, RECT client);	// collide with enemy
	};


	class Enemy {
	public:
		Enemy();
	private:
		XY center_;
		XY vec_;
		float hp_ = 255.0f;
		float damage_ = 50.0f;
		int width_;
		int height_;
	public:
		void Draw(HDC hdc, RECT client);
		int Update(std::vector<DefenseWall>& walls, RECT client);
		int Collision(std::vector<DefenseWall>& walls, RECT client);	// collide with wall
		friend int Bullet::Collision(std::vector<Enemy>&, RECT);
	};


	class DefenseWall {
	public:
		DefenseWall(int, int);
	private:
		XY point_;
		float hp_ = 255.0f;
		int total_;
	public:
		void Draw(HDC hdc, RECT client);
		inline float get_hp_() { return hp_; }
		friend int Enemy::Collision(std::vector<DefenseWall>&, RECT);
	};




	class GamePlay : public GameState
	{
	public:
		//GamePlay();
		GamePlay(HWND hWnd);
		~GamePlay();

	protected:
		TCHAR str_[LOGIN_STRMAX];
		int score_ = 0;
		friend int GameState::Next();

		int num_of_wall_ = 8;
		float spawn_rate_ = 100.0f;
		Turret turret_;
		std::vector<DefenseWall> walls_;
		std::vector<Bullet> bullets_;
		std::vector<Enemy> enemies_;

	public:
		int Draw(HDC hdc) override;
		int Update() override;
		int Input(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;
		int Next() override;
		int SetChar(TCHAR* str);

	};




}