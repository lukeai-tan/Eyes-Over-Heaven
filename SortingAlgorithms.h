#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <vector>
#include <SDL.h>

void insertionSort(std::vector<int>& arr, SDL_Renderer* renderer);
void bubbleSort(std::vector<int>& list, SDL_Renderer* renderer);
void mergeSort(std::vector<int>& arr, int left, int right, SDL_Renderer* renderer);
void quickSort(std::vector<int>& vec, int low, int high, SDL_Renderer* renderer);
void bogoSort(std::vector<int>& a, SDL_Renderer* renderer);

#endif
