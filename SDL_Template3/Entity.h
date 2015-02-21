
#ifndef ENTITY_H
#define ENTITY_H

#include "Sprite.h"
#include <string>
#include <vector>


class Entity: public Sprite {
private:
	int direction = 0;
	//int iW = 32, iH = 48;
	//int current_clip = 0;
//	int number_of_clip_lines = 1;
	//int number_of_clip_rows = 1;
	
//	SDL_Rect clips[16];
	//SDL_Texture * texture;
	void moveAnimation(int new_direction);
	void parseSprite(std::string sprite_file);
public:
	SDL_Rect collision_rect;
	SDL_Rect rect;
	void render();
	void update();
	void move(int ax = 0, int ay = 0);

	// bool isAbleToMove(int &rect_dimension, int ax);

	bool is_x_in_screen(int ax);

	bool CheckCollision(const SDL_Rect &rect1);
	Entity(std::string sprite_file = "sprite.png", SDL_Rect rect = { 200, 200, 60, 60 }, SDL_Rect collision_rect = {}, int number_of_clip_lines = 1, int number_of_clip_rows = 1);
	void turnAnimation(int new_direction);
	bool isAbleToMove(int &rect_dimension, int amount);
};


class HasSprite {
protected:
	Entity * sprite;
};


#endif 