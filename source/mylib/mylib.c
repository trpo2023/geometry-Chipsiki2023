#include "mylib.h"

int readCircle(float* circle) {
	char s[128];
	fgets(s, 127, stdin);

	circle[0] = atof(s + 7);

	char* s1 = strstr(s, " ");
	circle[1] = atof(s1);

	char* s2 = strstr(s, ",");
	circle[2] = atof(s2 + 1);

	return 0;
}

void printCircle(float* circle) {
	printf("circle(%f %f, %f)\n", circle[0], circle[1], circle[2]);
}
