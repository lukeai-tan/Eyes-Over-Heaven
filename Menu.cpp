#include <SDL.h>
#include "SortingAlgorithms.h"
#include "Graphics.h"
#include "Menu.h"
#include <iostream>
#include <string>
using namespace std;


void main_menu(vector<int> &list, SDL_Renderer* renderer, SDL_Window* window) {
	cout << "~~Sorting Algorithms~~" << endl;
	cout << "1. Insertion Sort" << endl;
	cout << "2. Bubble Sort" << endl;
	cout << "3. Merge Sort" << endl;
	cout << "4. Quick Sort" << endl;
	cout << "5. Bogo Sort (close the terminal to quit)" << endl;
	cout << "Input the corresponding number of each sort to see the visualisation" << endl;
	int input;
	cin >> input;

	SDL_CreateWindowAndRenderer(1000, 1000, 0, &window, &renderer);
	SDL_RenderSetScale(renderer, 10, 10);
	switch (input) {
	case 1:
		cout << "Insertion Sort selected" << endl;
		insertionSort(list, renderer);
		sortedState(list, renderer);
		break;
	case 2:
		cout << "Bubble Sort selected" << endl;
		bubbleSort(list, renderer);
		sortedState(list, renderer);
		break;
	case 3:
		cout << "Merge Sort selected" << endl;
		mergeSort(list, 0, 98, renderer);
		sortedState(list, renderer);
		break;
	case 4:
		cout << "Quick Sort selected" << endl;
		quickSort(list, 0, 98, renderer);
		sortedState(list, renderer);
		break;
	case 5:
		cout << "Bogo Sort selected" << endl;
		bogoSort(list, renderer);
		sortedState(list, renderer);
		break;
	default:
		cout << "No sort selected. Exiting..." << endl;
		break;
	}

}