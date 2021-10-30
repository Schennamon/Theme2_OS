#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "lib.h"

int main(){
	int sizeOfArray = 0;
	int *arrayList = (int*)malloc(sizeOfArray * sizeof(int));

	add(arrayList, &sizeOfArray, 10);
	add(arrayList, &sizeOfArray, 20);
	insert(arrayList, &sizeOfArray, 1, 15);
	insert(arrayList, &sizeOfArray, 0, 5);
	size(&sizeOfArray);
	printArrayList(arrayList, &sizeOfArray);

	remove(arrayList, &sizeOfArray, 1);
	printArrayList(arrayList, &sizeOfArray);

	set(arrayList, 2, 50);
	printArrayList(arrayList, &sizeOfArray);

	printf("%d\n", get(arrayList, 2));
}