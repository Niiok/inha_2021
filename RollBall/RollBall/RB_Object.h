#include <oun_Object.h>
#include <SDL.h>
#include "SDL_Game.h"
#include "SDL_Animator.h"

class RB_Object 
	: public oun::Object
{
public:
	RB_Object(oun::Space* space, oun::floatXYZ loc, float vol) : oun::Object(space, loc, vol) {}
	~RB_Object() override {}

	void Plan() override;
	void Update() override;
	void Draw() const override;

private:
	SDL_Animator* animator_;

};