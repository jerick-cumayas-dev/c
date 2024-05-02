#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
#define SIZE 10

#include "bubbleSort.h"

void insertionSort(int listNumbers[]){
	int count = 0;
	for (int x = 1; x < SIZE ; x++){
		for (int y = x; y > 0; y--){
			if(listNumbers[y] < listNumbers[y-1]){
				swapOperation(&listNumbers[y], &listNumbers[y-1]);
			} else {
				break;
			}
		}
	}
}

void insertionSortv2(int listNumbers[]){
	int current = 0;
	int sorted_index = 0;
	for (int x = 1; x < SIZE; x++){
		current = listNumbers[x];
		sorted_index = x - 1;

		while (listNumbers[sorted_index] > current && sorted_index >= 0){
			listNumbers[sorted_index + 1] = listNumbers[sorted_index];
			sorted_index -= 1;
		}
		listNumbers[sorted_index + 1] = current;
	}
}

#endif