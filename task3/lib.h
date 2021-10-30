 
#include <stdio.h>
#include <stdlib.h>

struct Student{
	char lastName[12];
	int groupe;
	int gradeWeb;
	int gradeLanguages;
	int gradeInfoSystems;
};

void inputData(Student *list, int *index){
	int check = 0;
	int groupe, gradeWeb, gradeLanguages, gradeInfoSystems;

	printf("Enter your last name: ");
	scanf("%s", list[*index].lastName);

	printf("Enter your groupe number(1-4): ");
	scanf("%d", &groupe);
	if(groupe > 0 && groupe < 5){
		list[*index].groupe = groupe;
	}else{
		while(check == 0){
			printf("Enter a group number from 1 to 4: ");
			scanf("%d", &groupe);
			if(groupe > 0 && groupe < 5){
				check = 1;
			}
		}
	}

	printf("Enter your grade of Web: ");
	scanf("%d", &gradeWeb);
	list[*index].gradeWeb = gradeWeb;

	printf("Enter your grade of Languages: ");
	scanf("%d", &gradeLanguages);
	list[*index].gradeLanguages = gradeLanguages;

	printf("Enter your grade of InfoSystems: ");
	scanf("%d", &gradeInfoSystems);
	list[*index].gradeInfoSystems = gradeInfoSystems;
	printf("\n");

	*index += 1;
}

void getDebtors(Student *list, int *index){
	int check = 0;
	for(int i = 0; i <= *index; i++){
		if(list[i].gradeWeb <= 2 || list[i].gradeLanguages <= 2 || list[i].gradeInfoSystems <= 2){
			printf("%s\n", list[i].lastName);
			check = 1;
		}
	}

	if(check == 0){
		printf("There are no debtors!");
	}
}

void getPercent(Student *list, int *index){
	int amount = 0;
	int percent;
	for(int i = 0; i < *index; i++){
		if(list[i].gradeWeb > 3 && list[i].gradeLanguages > 3 && list[i].gradeInfoSystems > 3){
			amount++;
		}
	}

	percent = (100 / (*index)) * amount;

	printf("Percent = %d\n", percent);
}

void getBestLesson(Student *list, int *index){
	int i, max;
	int indMax = 0;
	int grade[3] = {0};

	for(i = 0; i < *index; i++){
		grade[0] += list[i].gradeWeb;
		grade[1] += list[i].gradeLanguages;
		grade[2] += list[i].gradeInfoSystems;
	}

	max = grade[0];
	for(i = 0; i < 3; i++){
		if (grade[i] > max){
			max = grade[i];
			indMax = i;
		}
	}

	switch(indMax){
		case 0: 
			printf("Best lesson: Web\n");
		break;

		case 1: 
			printf("Best lesson: Languages\n");
		break;

		case 2:
			printf("Best lesson: InfoSystems\n");
		break;
	}
}

void getWorstGroupe(Student *list, int *index){
	int min;
	int indMin;
	int grade[4] = {0};

	for(int i = 0; i < *index; i++){
		if(list[i].groupe == 1){
			grade[0] += (list[i].gradeWeb + list[i].gradeLanguages + list[i].gradeInfoSystems);
		}
		if(list[i].groupe == 2){
			grade[1] += (list[i].gradeWeb + list[i].gradeLanguages + list[i].gradeInfoSystems);
		}
		if(list[i].groupe == 3){
			grade[2] += (list[i].gradeWeb + list[i].gradeLanguages + list[i].gradeInfoSystems);
		}
		if(list[i].groupe == 4){
			grade[3] += (list[i].gradeWeb + list[i].gradeLanguages + list[i].gradeInfoSystems);
		}
	}

	min = grade[0];
	indMin = 0;
	for(int i = 0; i < 4; i++){
		if(grade[i] < grade[indMin]){
			min = grade[i];
			indMin = i;
		}
	}

	switch(indMin){
		case 0: 
			printf("Wrost groupe: 1\n");
		break;

		case 1: 
			printf("Wrost groupe: 2\n");
		break;

		case 2:
			printf("Wrost groupe: 3\n");
		break;

		case 3:
			printf("Wrost groupe: 4\n");
		break;
	}

}