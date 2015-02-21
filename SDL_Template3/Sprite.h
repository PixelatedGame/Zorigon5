#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>
#include "texture.h"

class Sprite{
private:
	int current_clip = 0;
	int number_of_clip_lines = 1;
	int number_of_clip_rows = 1;

	SDL_Rect clips[16];
	SDL_Texture * texture;
	void moveAnimation(int new_direction);
	void parseSprite(std::string sprite_file);

public:
	SDL_Rect rect;

	Sprite(std::string sprite_file = "sprite.png", SDL_Rect rect = { 200, 200, 60, 60 });
	void render();


	
};

#endif // !SPRITE_H
