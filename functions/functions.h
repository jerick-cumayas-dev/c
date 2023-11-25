#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "../algorithms/bubbleSort.h"
#include "../algorithms/insertionSort.h"
#define SIZE 10

void displayMenu(){
	printf("Algorithms:\n"
			"0. Generate Random Numbers\n"
			"1. Display List\n"
			"2. Bubble Sort Algorithm\n"
			"3. Insertion Sort Algorithm\n"
			"Choice: ");
}

void displayList(int listNumbers[]){
	for (int x = 0; x < SIZE; x++){
		printf("List Number [%d] = %d\n", x, listNumbers[x]);
	}
}

void generateRandomNumbers(int listNumbers[]){
	srand(time(NULL));
	for (int x = 0; x < SIZE; x++){
		listNumbers[x] = rand()%100;
	}
}

bool isSorted(int listNumbers[]){
	int count = 0;

	for (int x = 0; x < SIZE - 1; x++){
		if (listNumbers[x] > listNumbers[x+1]){
			count += 1;
		}
	}

	if (count > 0){
		printf("false");
		return false;
	} else {
		printf("true");
		return true;
	}
}

void selected(int listNumbers[], int choice){
	switch (choice){
		case 0: displayList(listNumbers);
			break;
		case 1: generateRandomNumbers(listNumbers);	
				displayList(listNumbers);
			break;
		case 2: bubbleSort(listNumbers); 
				displayList(listNumbers);
			break;
		case 3: insertionSort(listNumbers);
				displayList(listNumbers);
			break;
		default: printf("Invalid entry.");
			break;
	}
}

#endif