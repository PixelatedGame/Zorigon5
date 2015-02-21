#include "Enemy.h"


Enemy::Enemy(std::string sprite_file, SDL_Rect rect, SDL_Rect collision_rect, int number_of_clip_lines, int number_of_clip_rows) :\
Entity(sprite_file, rect, collision_rect, number_of_clip_lines, number_of_clip_rows){
	Life = new Sprite("Enemy-head.png", { 0, 0, 100, 85 });
	Life_Rect = { 10, 10, 100, 85 };
}


void Enemy::update(){
	

}

