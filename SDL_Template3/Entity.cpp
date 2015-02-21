#include "Entity.h"
#include "globals.h"
#include "SDL_mixer.h"
#include "res_path.h"
#include <algorithm>

Entity::Entity(std::string sprite_file, SDL_Rect rect, SDL_Rect collision_rect, int number_of_clip_lines, int number_of_clip_rows)
{
	this->rect = rect;
	this->collision_rect = collision_rect;
	
	parseSprite(sprite_file);


	sprites.push_back(this);
	
}


void Entity::parseSprite(std::string sprite_file)
{
	texture = loadTexture(resPath + sprite_file, renderer);
	//collision_rect = { ax, ay, aw, ah };
	//collision_rect = { ax+8, ay + 38 , 32 -16, 10 };

	// this needs a better algorithm
	/*
	for (int current_row = 0; current_row < number_of_clip_rows; current_row++){
		for (int current_line = 0; current_line < number_of_clip_lines; current_line++){
			clips[(4 * current_row) + current_line].x = iW * current_line;
			clips[(4 * current_row) + current_line].y = iH * current_row;
			clips[(4 * current_row) + current_line].w = iW;
			clips[(4 * current_row) + current_line].h = iH;
		}
	}
	*/
}

void Entity::render() {
	renderTexture(texture, renderer, rect);
}

void Entity::moveAnimation(int new_direction) {
	if (new_direction == direction) {
		current_clip = ((current_clip + 1) % 4) + (direction*4);
	}
}


void Entity::turnAnimation(int new_direction) {
	if (new_direction != direction) {
		direction = new_direction;
		current_clip = 4 * direction;
	}
}


void Entity::move(int ax, int ay)
{
	
	int new_moving_direction = 0;
	bool sprite_has_moved_in_x = false;
	bool sprite_has_moved_in_y = false;
	
	if (ax < 0) new_moving_direction = face_directions::LEFT;
	if (ax > 0) new_moving_direction = face_directions::RIGHT;
	if (ay > 0) new_moving_direction = face_directions::DOWN;
	if (ay < 0) new_moving_direction = face_directions::UP;
	turnAnimation(new_moving_direction);

	bool xWithinScreen = 0 <= rect.x + ax && rect.x + rect.w + ax <= DISPLAY_WIDTH;
	bool yWithinScreen = 0 <= rect.y + ay && rect.y + rect.h + ay <= DISPLAY_HEIGHT -60 ;
	if (ax && xWithinScreen) sprite_has_moved_in_x = isAbleToMove(rect.x, ax); 
	if (ay && yWithinScreen) sprite_has_moved_in_y = isAbleToMove(rect.y, ay);

	if (sprite_has_moved_in_x || sprite_has_moved_in_y) {
		moveAnimation(new_moving_direction);
	}
	collision_rect = { rect.x + 8, rect.y + 38, collision_rect.w, collision_rect.h };
}



void Entity::update()
{ 
	/*
	int moves[] = { 2, -2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int size = sizeof(moves) / sizeof(int);
	move(moves[rand() % size], moves[rand() % size]);
	*/

}


bool Entity::CheckCollision(const SDL_Rect &rect1)
{
	
	SDL_Rect & rect2 = collision_rect;
	if (&rect1 == &rect2)
		return false;
	// Find edges of rect1
	int left1 = rect1.x;
	int right1 = rect1.x + rect1.w;
	int top1 = rect1.y;
	int bottom1 = rect1.y + rect1.h;

	// Find edges of rect2
	int left2 = rect2.x;
	int right2 = rect2.x + rect2.w;
	int top2 = rect2.y;
	int bottom2 = rect2.y + rect2.h;

	// Check edges
	if (left1 >= right2)// Left 1 is right of right 2
		return false; // No collision

	if (right1 <= left2) // Right 1 is left of left 2
		return false; // No collision

	if (top1 >= bottom2) // Top 1 is below bottom 2
		return false; // No collision

	if (bottom1 <= top2) // Bottom 1 is above top 2 
		return false; // No collision
	
	return true;
}


bool Entity::isAbleToMove(int &rect_dimension, int amount)
{
	int sprite_has_colided = 0;
	rect_dimension += amount;
	collision_rect = { rect.x + 8, rect.y + 38, collision_rect.w, collision_rect.h };
	
	for (auto p : sprites)
	{
		sprite_has_colided += CheckCollision(p->collision_rect);
	}

	if (sprite_has_colided){
		rect_dimension -= amount;
		return false;
	}
	return true;
		

}


