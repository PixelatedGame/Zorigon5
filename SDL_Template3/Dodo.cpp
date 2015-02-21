#include "Dodo.h"


Dodo::Dodo(std::string sprite_file, SDL_Rect rect, SDL_Rect collision_rect, int number_of_clip_lines, int number_of_clip_rows):\
Entity(sprite_file, rect, collision_rect, number_of_clip_lines, number_of_clip_rows){
	Life = new Sprite("dodo-head.png", { 0, 0, 100, 85 });
	Life_Rect = { 10, 10, 100, 85 };
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
		rect.y = 330;
		break;
	case ENTER_DUCK:
		if (cycle_counter >= 70){
			state = DUCK;
			cycle_counter = 0;
		}
		cycle_counter += 1;
		rect.y = 330;
		break;
	case DUCK:
		cycle_counter = 0;
		jump_power += 1;
		rect.y = 400;
		break;
	case JUMP:
		if (cycle_counter == 0){
			rect.y = 330;
		}
		if (cycle_counter >= (jump_power/3) || rect.y==80){
			cycle_counter = 0;
			state = SWIP;
		}
		cycle_counter += 1;
		rect.y -= 1;
		break;
	case SWIP:
		jump_power = 0;
		if (rect.y >= 330){
			rect.y = 330;
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
		if (rect.y>=330){
			rect.y = 330;
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

void Dodo::print_life(){
	SDL_Rect temp_rect = Life->rect;
	for (int i = 0; i < life; i++){
		Life->render();
		Life->rect.x += 100;
	}
	Life->rect = temp_rect;
}
