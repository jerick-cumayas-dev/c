#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "functions/functions.h"
#include "algorithms/bubbleSort.h"

#define SIZE 10

int main(){
	int listNumbers[SIZE] = {0};
	int choice = 0;

	generateRandomNumbers(listNumbers);

	while (choice != -1){
	
		system("cls");
		displayMenu();
		scanf("%d", &choice);

		selected(listNumbers, choice);
		_getch();
	}

	return 0;
}

