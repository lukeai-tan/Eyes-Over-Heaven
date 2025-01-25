#include "Graphics.h"
#include <SDL.h>
using namespace std;

void printState(vector<int>& v, SDL_Renderer* renderer, unsigned int orange, unsigned int blue) {
    int index = 0;
    for (int i : v) {
        if (index == orange) { // index i
            SDL_SetRenderDrawColor(renderer, 255, 140, 0, 255);
        }
        else if (index == blue) { // index j
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        }
        else { // white
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }
        SDL_RenderDrawLine(renderer, index, 99, index, 99 - i);
        index += 1;
    }
}

void sortedState(vector<int>& v, SDL_Renderer* renderer) {
    int index = 0;
    for (int i : v) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        //SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderDrawLine(renderer, index, 99, index, 99 - i);
        SDL_RenderPresent(renderer);
        SDL_Delay(10);
        index++;
    }
}