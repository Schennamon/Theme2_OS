 void printArrayList(int *arrayList, int *size){
	for(int i = 0; i < *size; i++){
		printf("%d ", arrayList[i]);
	}
	printf("\n");
}

void size(int *size){
	printf("%d\n", *size);
}

void add(int *arrayList, int *size, int num){
	*size += 1;

	arrayList = (int*)realloc(arrayList, *size * sizeof(int));
	arrayList[*size - 1] = num;
}

void insert(int *arrayList, int *size, int index, int num){
	*size += 1;

	arrayList = (int*)realloc(arrayList, *size * sizeof(int));

	for(int i = *size - 1; i > index; i--){
		arrayList[i] = arrayList[i - 1];
	}

	arrayList[index] = num;
}

void remove(int *arrayList, int *size, int index){
	for(int i = index; i < *size - 1; i++){
		arrayList[i] = arrayList[i + 1];
	}

	*size -= 1;
	 arrayList = (int*)realloc(arrayList, *size * sizeof(int));
}

void set(int *arrayList, int index, int num){
	arrayList[index] = num;
}

int get(int *arrayList, int index){
	return arrayList[index];
}

