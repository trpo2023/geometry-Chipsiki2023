#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ctest.h"

int readCircle(float* circle, char* s);
void printCircle(float* circle, char* s);

CTEST(circles, readcircle) {
   char* str = "circle(1 1, 2)";
   float circle[3];
   readCircle(circle, str);

   float expectRes[3] = {1.0, 1.0, 2.0};

   ASSERT_DATA((char*)expectRes, 3 * sizeof(float), (char*)circle, 3 * sizeof(float));
}

CTEST(circles, writecircle) {
    float circle[3] = {1.0, 1.0, 2.0};
    char str[128];
    printCircle(circle, str);
    ASSERT_STR("circle(1.00 1.00, 2.00)", str);
}

int circles (){
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

        char s[128];
        fgets(s, 127, stdin);

		int code = readCircle(arr[i], s);

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
        char str[128];
        printCircle(arr[j], str);
        printf("%s\n", str);
	}

	return 0;
}

int readCircle(float* circle, char* s) {
	circle[0] = atof(s + 7);

	char* s1 = strstr(s, " ");
	circle[1] = atof(s1);

	char* s2 = strstr(s, ",");
	circle[2] = atof(s2 + 1);

	return 0;
}

void printCircle(float* circle, char* s) {
    sprintf(s, "circle(%.2f %.2f, %.2f)", circle[0], circle[1], circle[2]);
}

