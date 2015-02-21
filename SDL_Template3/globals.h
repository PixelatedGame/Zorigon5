
#ifndef GLOBALS_H
#define GLOBALS_H
#include <vector>

#include "Entity.h"


extern std::vector< Entity * > sprites;
extern std::string resPath;
extern SDL_Window* window;
extern SDL_Renderer* renderer;

enum face_directions {
	DOWN,
	LEFT,
	RIGHT,
	UP

};


enum {
	DISPLAY_WIDTH = 800
	, DISPLAY_HEIGHT = 600
	, UPDATE_INTERVAL = 1000 / 20
	, HERO_SPEED = 20
};


#endif 