#include "Sprite.h"
#include "globals.h"
#include "SDL_mixer.h"
#include "res_path.h"

using namespace std;

Sprite::Sprite(std::string sprite_file, SDL_Rect rect)
{
	this->rect = rect;

	std::vector<SDL_Texture*> texture_vector;

	std::stringstream ss(sprite_file);

	while (ss.good())
	{
		string substr;
		getline(ss, substr, ',');
		texture_vector.push_back(loadTexture(resPath + substr, renderer));
	}
	this->texture_vector = texture_vector;
}

void Sprite::render() {
	renderTexture(texture_vector[current_clip], renderer, rect);

}