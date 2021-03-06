#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

#include <string>
#include "texture.h"

class Sprite{
protected:
	int current_clip = 0;
	int number_of_clip_lines = 1;
	int number_of_clip_rows = 1;

	SDL_Rect clips[16];
	std::vector<SDL_Texture*> texture_vector;
	SDL_Texture * texture;

public:
	SDL_Rect rect;

	Sprite(std::string sprite_file = "spritez.png", SDL_Rect rect = { 200, 200, 60, 60 });
	void render();


	
};

#endif // !SPRITE_H
