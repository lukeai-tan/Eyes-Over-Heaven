#include "SortingAlgorithms.h"
#include "Graphics.h"
#include <algorithm>
#include <SDL.h>
#include <random>
using namespace std;


void insertionSort(vector<int>& arr, SDL_Renderer* renderer)
{
    size_t n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        printState(arr, renderer, i, j);

        // display to window
        SDL_RenderPresent(renderer);
        SDL_Delay(50);
    }
}

void bubbleSort(vector<int>& list, SDL_Renderer* renderer) {
    size_t n = list.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (list[j] > list[j + 1]) {
                swap(list[j], list[j + 1]);
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderClear(renderer);
                printState(list, renderer, i, j);

                // display to window
                SDL_RenderPresent(renderer);
                SDL_Delay(10);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> leftArr(n1), rightArr(n2);

    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right, SDL_Renderer* renderer) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, renderer);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        printState(arr, renderer, left, mid);
        SDL_RenderPresent(renderer);
        SDL_Delay(50);

        mergeSort(arr, mid + 1, right, renderer);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        printState(arr, renderer, mid + 1, right);
        SDL_RenderPresent(renderer);
        SDL_Delay(50);

        merge(arr, left, mid, right);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        printState(arr, renderer, -1, -1);
        SDL_RenderPresent(renderer);
        SDL_Delay(50);
    }
}

bool isSorted(vector<int>& a)
{
    size_t n = a.size();
    while (--n > 0) {
        if (a[n] < a[n - 1]) {
            return false;
        }
    }
    return true;
}

void shuffle(vector<int>& a)
{
    size_t n = a.size();
    for (int i = 0; i < n; i++) {
        swap(a[i], a[rand() % n]);
    }
}

int partition(vector<int>& vec, int low, int high) {
    int pivot = vec[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (vec[j] <= pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[high]);
    return (i + 1);
}

void quickSort(vector<int>& vec, int low, int high, SDL_Renderer* renderer) {

    if (low < high) {
        int pi = partition(vec, low, high);

        quickSort(vec, low, pi - 1, renderer);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        printState(vec, renderer, low, pi - 1);
        SDL_RenderPresent(renderer);
        SDL_Delay(50);

        quickSort(vec, pi + 1, high, renderer);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        printState(vec, renderer, pi + 1, high);
        SDL_RenderPresent(renderer);
        SDL_Delay(50);
    }
}

void bogoSort(vector<int>& a, SDL_Renderer* renderer)
{
    size_t n = a.size();
    while (!isSorted(a)) {
        shuffle(a);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        printState(a, renderer, -1, -1);
        SDL_RenderPresent(renderer);
        SDL_Delay(10);
    }
}