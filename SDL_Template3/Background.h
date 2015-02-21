#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "Sprite.h"
#include <vector>

class Background{
	std::vector< Sprite * > background_objects;
	
public:
	Background();
	void render();
};
#endif // !BACKGROUND_H
