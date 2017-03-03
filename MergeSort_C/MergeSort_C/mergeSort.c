#define _CRT_SECURE_NO_DEPRECATE

#include<stdio.h>
#include<memory.h>
#include<stdlib.h>

int countElement(char* inputfile) {
	int result = 0;
	int temp;

	FILE *file = NULL;
	file = fopen(inputfile, "r");

	if (file != NULL) {
		while (!feof(file)) {
			fscanf(file, "%d\n", &temp);
			result++;
		}
		fclose(file);
	}

	else {
		printf("!] FILE OPEN ERROR\n");
		exit(1);
	}

	return result - 1;
}

int* readTxtfile(char* inputfile, int length) {
	int* tempArray = (int*)malloc(sizeof(int)*length);
	int temp;
	int i = 0;

	FILE *file = NULL;
	file = fopen(inputfile, "r");

	if (file != NULL) {
		while (!feof(file)) {
			fscanf(file, "%d\n", &temp);
			tempArray[i] = temp;
			i++;
		}
	}
	else {
		printf("!] FILE OPEN ERROR\n");
		exit(1);
	}

	return tempArray;
}

void writeTxtFile(int* sortedArray, char* outputfilename, int length) {
	FILE *writeFile = NULL;
	int i;
	writeFile = fopen(outputfilename, "w");

	if (writeFile != NULL) {
		for (i = 0; i < length; i++) {
			fprintf(writeFile, "%d\n", sortedArray[i]);
		}
		fclose(writeFile);
	}
	else {
		printf("!] FILE OPEN ERROR\n");
		exit(1);
	}
}

int* divideArrayFront(int* inputArray, int length){
	int* result = (int*)malloc(sizeof(int)*length / 2);
	int i = 0;
	for (; i < length / 2; i++) {
		result[i] = inputArray[i];
	}

	return result;
}

int* divideArrayBack(int* inputArray, int length) {
	int temp = length - length / 2;
	int* result = (int*)malloc(sizeof(int)*temp);
	int i = 0;
	int start = length / 2;

	for (; i < temp; i++) {
		result[i] = inputArray[i + start];
	}
	return result;
}

int* merge(int* arr1, int length1, int* arr2, int length2){
	int* mergeResult = (int*)malloc(sizeof(int)*(length1 + length2));
	int i = 0;
	int j = 0;
	int x = 0;

	while (i < length1 && j < length2) {
		if (arr1[i] > arr2[j]) {
			mergeResult[x] = arr2[j];
			j++;
		}
		else {
			mergeResult[x] = arr1[i];
			i++;
		}
		x++;
	}

	while (i<length1){
		mergeResult[x] = arr1[i];
		i++;
		x++;
	}
	while (j < length2) {
		mergeResult[x] = arr2[j];
		j++;
		x++;
	}

	return mergeResult;
}

int* mergeSort(int* inputArray, int length) {
	
	if (length == 1) {
		return inputArray;
	}
	else {
		int* temp1 = divideArrayFront(inputArray, length);
		int* temp2 = divideArrayBack(inputArray, length);

		int* mArray1 = mergeSort(temp1, length / 2);
		int* mArray2 = mergeSort(temp2, length - length / 2);

		return merge(mArray1, length/2, mArray2, length-length/2);
	}
}


int main(void) {

	char* inputFileName = "random.txt";
	char* outpuFileName = "c merge sort.txt";

	int count = countElement(inputFileName);

	int* readfile = readTxtfile(inputFileName, count);

	int* sortedArray = mergeSort(readfile, count);


	writeTxtFile(sortedArray, outpuFileName, count);

	printf("!] Sucess! \n");
}