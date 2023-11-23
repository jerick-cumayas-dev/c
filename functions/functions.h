#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define SIZE 10

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

#endif