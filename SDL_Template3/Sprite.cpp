#include "Sprite.h"
#include "globals.h"
#include "SDL_mixer.h"
#include "res_path.h"
#include <algorithm>


Sprite::Sprite(std::string sprite_file, SDL_Rect rect)
{
	this->rect = rect;
	texture = loadTexture(resPath + sprite_file, renderer);
	
}

void Sprite::render() {
	renderTexture(texture, renderer, rect);

}