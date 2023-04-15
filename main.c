#define _CRT_SECURE_NO_WARNINGS
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

		char s[128];
		printf("Vvedite circle: ");
		fgets(s, 127, stdin);

		if ( strcmp(s, "circle(") == 0 ) {
			arr[i][0] = atof(s + 7);

			char* s1 = strstr(s, " ");
			arr[i][1] = atof(s1);

			char* s2 = strstr(s, ",");
			arr[i][2] = atof(s2 + 1);

			printf("Circle added\n");

			i++;
		}
		else {
			printf("Wrong circle format!\n");
		}
	}

	int j;
	for (j = 0; j < i; j++) {
		printf("circle(%f %f, %f)\n", arr[j][0], arr[j][1], arr[j][2]);
	}

	return 0;
}