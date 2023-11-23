#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#define SIZE 10

void swapOperation(int *first, int *second){
	int temp = *first;
	*first = *second;
	*second = temp;
}

void bubbleSort(int listNumbers[]){
	int iterations = 0;
	for (int x = 0; x < SIZE-1; x++){
		for (int y = 0; y < (SIZE-x-1); y++){
			if (listNumbers[y] > listNumbers[y+1]){
				swapOperation(&listNumbers[y], &listNumbers[y+1]);
				iterations += 1;
			}
		}
	}
}

#endif
