#include <stdio.h> 
#include <stdlib.h>
#include <malloc.h>

void randArr(int *p, int *size){
	for(int i = 0; i < *size; i++){
		p[i] = rand() % 100;
	}
}

void printArr(int *p, int *size){
	printf("\n");
	for(int i = 0; i < *size; i++){
		printf("%d ", p[i]);
	}
}

void findMinPoint(int *p, int *size, int *min,  int *index){
	*index = 0;
	*min = p[0];

	for(int i = 0; i < *size; i++){
		if(p[i] < *min){
			*min = p[i];
			*index = i;
		}
	}
	printf("\nmin = %d, ind = %d", *min, *index);
}

void findLastPoint(int *p, int *size, int *min, int *index){
	while(*size > 1){
		findMinPoint(p, size, min, index);

		if(*index < (*size - 1)){
			printf("  %d + ", p[*index + 1]);
			p[*index + 1] += *min;
			printf("%d = %d\n", *min, p[*index + 1]);
		}else{
			printf(" %d + ", p[*index - 1]);
			p[*index - 1] += *min;
			printf("%d = %d\n", *min, p[*index - 1]);
		}

		for(int i = *index; i < (*size - 1); i++){
			p[i] = p[i + 1];
		}

		*size -= 1;

		p = (int*)realloc(p, (*size) * sizeof(int));
		
		printArr(p, size);
	}
}

int main()
 {
 	int* p = NULL;
 	int size,  min, i, index;

 	printf("Enter the number of points: ");
 	scanf("%d", &size);

 	p = (int*)realloc(p, (size) * sizeof(int));
 	
 	randArr(p, &size);
 	printArr(p, &size);
 	findLastPoint(p, &size, &min, &index);

 	return 0;
 } 
