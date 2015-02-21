#ifndef DODO_H
#define DODO_H

#include "Entity.h"

enum state {SURF, ENTER_DUCK, DUCK, JUMP, SWIP, EXIT_JUMP};
class Dodo : public Entity{
private:
	int state = SURF;
	int jump_power = 0;
	int life = 3;
	int speed = 0;
	int cycle_counter = 0;
	Sprite * Life;
	SDL_Rect Life_Rect;
public:
	Dodo(std::string sprite_file = "sprite.png", SDL_Rect rect = { 200, 200, 60, 60 }, SDL_Rect collision_rect = {}, int number_of_clip_lines = 1, int number_of_clip_rows = 1);
	
	bool lost_life();
	int get_life();
	bool reset_life();
	void update();
	void on_click();
	void off_click();
	void print_life();
};

#endif // !DODO_H