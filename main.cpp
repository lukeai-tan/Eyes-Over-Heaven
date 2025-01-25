#include <SDL.h>
#include <iostream>
#include <random>
#include <ranges>
#include <algorithm>
#include "SortingAlgorithms.h"
#include "Graphics.h"
#include "Menu.h"
#undef main
using namespace std;

int main() {
	random_device rd;
	uniform_int_distribution<> d(1, 99);
	vector<int> v;
	for (int i = 0; i < 99; i++) {
		v.push_back(d(rd));
	}
    
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    /*
    SDL_CreateWindowAndRenderer(1000, 1000, 0, &window, &renderer);
    SDL_RenderSetScale(renderer, 10, 10);
    */

    main_menu(v, renderer, window);
    SDL_Delay(1000);
    return 0;
}