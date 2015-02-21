#pragma once
#ifndef TEXTURE_H
#define TEXTURE_H
#include <SDL_image.h>
#include <iostream>
#include <string>

void logSDLError(std::ostream &os, const std::string &msg);
SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren);
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, SDL_Rect dst,
	SDL_Rect *clip = nullptr);
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y,
	SDL_Rect *clip = nullptr);

#endif