#pragma once

#include <stdlib.h>
#include <memory.h>>
#include <stdio.h>

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

	return result;
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