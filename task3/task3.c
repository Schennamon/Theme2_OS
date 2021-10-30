#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main(){
	int index = 0;
	int menu_bar;
	Student list[30];

	while(menu_bar != 6){
		printf("1. Get list of debtors.\n");
		printf("2. Get percent of good students.\n");
		printf("3. Get name of best lesson.\n");
		printf("4. Get name of the worst groupe.\n");
		printf("5. Input data.\n");
		printf("6. Exit.\n\n");
		printf("Enter your choice: ");

		scanf("%d", &menu_bar);
		printf("\n");

		switch(menu_bar){

			case 1: getDebtors(list, &index);
			break;

			case 2: getPercent(list, &index);
			break;

			case 3: getBestLesson(list, &index);
			break;

			case 4: getWorstGroupe(list, &index);
			break;

			case 5: inputData(list, &index);
			break;
		}
	}

 	return 0;
 } 
