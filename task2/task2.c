#include <stdio.h> 
#include <stdlib.h>

void printArr(int *arr, int n){
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n\n");
}

int main(void)
{
	double average;
	int i, n, amount;
	int sum = 0;
	int check = 0;

	scanf("%d", &n);
	int arr[n];

	for(int i = 0; i < n; i++){
		arr[i] = (rand() % 100) - 50; 
	}

	printArr(arr, n);

	for(int i = 0; i < n; i++){
		average += arr[i];
	}

	average = average / n;

	for(int i = 0; i < n; i++){
		if(arr[i] > average){
			amount++;
		}
	}

	for(int i = 0; i < n; i++){
		if(arr[i] < 0 && check == 0){
			check = 1;
			for(int j = i+1; j < n; j++){
				if(arr[j] >= 0){
					sum += arr[j];
				}	printf("\n");
			}	
		}
	}

	printf("%f\n%d", average, sum);

	return 0;
}