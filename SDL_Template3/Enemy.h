#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

enum state { SURF, ENTER_DUCK, DUCK, JUMP, SWIP, EXIT_JUMP };
class Enemy : public Entity{
private:


public:
	Enemy(std::string sprite_file = "sprite.png", SDL_Rect rect = { 200, 200, 60, 60 }, SDL_Rect collision_rect = {}, int number_of_clip_lines = 1, int number_of_clip_rows = 1);
	SDL_Rect Life_Rect;
	void update();
};

#endif // !ENEMY_H