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

#endif