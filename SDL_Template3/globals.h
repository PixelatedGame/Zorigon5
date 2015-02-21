
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
	DISPLAY_WIDTH = 1136
	, DISPLAY_HEIGHT = 640
	, UPDATE_INTERVAL = 1000 / 60
	, HERO_SPEED = 20
};


#endif 