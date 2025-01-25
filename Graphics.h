#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <vector>
#include <SDL.h>

void printState(std::vector<int>& v, SDL_Renderer* renderer, unsigned int orange, unsigned int blue);

void sortedState(std::vector<int>& v, SDL_Renderer* renderer);

#endif
