#define _CRT_SECURE_NO_WARNINGS
#include "mylib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (){
	float arr [10][3];
	char c=0;
	int i=0;
	while (i<10){

		printf("1 - vvesti circle, 2 - stop: ");
		scanf("%c", &c);
		fgetc(stdin);

		if (c == '2') {
			break;
		}

		printf("Vvedite circle: ");

		int code = readCircle(arr[i]);

		if (code != 0) {
			printf("Wrong circle!\n");
		}
		else {
			printf("Circle added!\n");
			i++;
		}
	}

	int j;
	for (j = 0; j < i; j++) {
		printCircle(arr[j]);
	}

	return 0;
}
