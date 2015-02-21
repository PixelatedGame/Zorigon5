#include "Dodo.h"


Dodo::Dodo(std::string sprite_file, SDL_Rect rect, SDL_Rect collision_rect, int number_of_clip_lines, int number_of_clip_rows):\
Entity(sprite_file, rect, collision_rect, number_of_clip_lines, number_of_clip_rows){

}

bool Dodo::reset_life(){
	life = 3;
	return true;
}

bool Dodo::lost_life(){
	if (life > 0){
		life -= 1;
		return true;
	}
	else
		return false;
}

int Dodo::get_life(){
	return life;
}

void Dodo::update(){
	switch (state)
	{
	case SURF:
		rect.y = 300;
		break;
	case ENTER_DUCK:
		if (cycle_counter >= 70){
			state = DUCK;
			cycle_counter = 0;
		}
		cycle_counter += 1;
		rect.y = 380;
		break;
	case DUCK:
		cycle_counter = 0;
		jump_power += 1;
		rect.y = 400;
		break;
	case JUMP:
		if (cycle_counter == 0){
			rect.y = 300;
		}
		if (cycle_counter >= (jump_power/3) || rect.y==0){
			cycle_counter = 0;
			state = SWIP;
		}
		cycle_counter += 1;
		rect.y -= 1;
		break;
	case SWIP:
		jump_power = 0;
		if (rect.y >= 300){
			rect.y = 300;
			cycle_counter = 0;
			state = SURF;
		}
		if (cycle_counter == 2){
			rect.y += 1;
			cycle_counter = 0;
		}
		cycle_counter += 1;


		break;

	case EXIT_JUMP:
		jump_power = 0;
		if (rect.y>=300){
			rect.y = 300;
			cycle_counter = 0;
			state = SURF;
		}

		rect.y += 1;
		cycle_counter = 0;
		break;

	default:
		break;
	}
	
}

void Dodo::on_click(){
	switch (state)
	{
	case SURF:
		state = ENTER_DUCK;
		break;
	case JUMP:
	case SWIP:
		state = EXIT_JUMP;
		break;
	default:
		break;
	}
}

void Dodo::off_click(){
	switch (state)
	{
	case DUCK:
		state = JUMP;
		break;
	case EXIT_JUMP:
		state = SWIP;
		break;
	default:
		break;
	}
}