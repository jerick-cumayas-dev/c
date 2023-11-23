#include <stdio.h>

#include "functions/functions.h"
#include "algorithms/bubbleSort.h"

#define SIZE 10

int main(){
	int listNumbers[SIZE] = {0};

	//Unsorted list
	printf("Unsorted list:\n");
	generateRandomNumbers(listNumbers);
	displayList(listNumbers);

	//Sorted list with bubble sort algorithm
	printf("Bubble Sort Algorithm:\n");
	bubbleSort(listNumbers);
	displayList(listNumbers);

	printf("Check list if sorted: ");
	isSorted(listNumbers);
	return 0;
}

