#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "Sprite.h"
#include <vector>

class Background : public Sprite{
	std::vector< Sprite * > background_objects;
	
public:
	Background();
	void render();
};
#endif // !BACKGROUND_H
