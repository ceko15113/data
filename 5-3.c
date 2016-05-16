#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
	double x[3];
	double y[3];
} TRIANGLE; 

int isTriangle(double distance[])
{
	int flag = 1;
	int i;

	for (i = 0; i < 3; i++) {
		if (!(distance[i] < distance[(i + 1) % 3] + distance[(i + 2) % 3])) flag = 0;
	}

	return flag;
}

void eachDistanceCalc(TRIANGLE triangle, double distance[])
{
	int i;

	for (i = 0; i < 3; i++) {
		distance[i] = sqrt(pow(triangle.x[i] - triangle.x[(i + 1) % 3], 2) + pow(triangle.y[i] - triangle.y[(i + 1) % 3], 2));
//		distance[0] = sqrt(pow(triangle.x[0] - triangle.x[1], 2) + pow(triangle.y[0] - triangle.y[1], 2));
//		distance[1] = sqrt(pow(triangle.x[1] - triangle.x[2], 2) + pow(triangle.y[1] - triangle.y[2], 2));
//		distance[2] = sqrt(pow(triangle.x[2] - triangle.x[0], 2) + pow(triangle.y[2] - triangle.y[0], 2));
	}
}

double distanceSum(TRIANGLE triangle)
{
	int i;
	double sum = 0;
	double distance[3];

	eachDistanceCalc(triangle, distance);
	if (!isTriangle(distance)) {
		printf("計算不能\n");
		exit(1);
	}
	for (i = 0; i < 3; i++) sum += distance[i];

	return sum;
}

int main(void)
{
	TRIANGLE triangle;
	int i;

	for (i = 0; i < 3; i++) {
		printf("Point %d (x,y): ", i + 1);
		scanf("%lf,%lf", &triangle.x[i], &triangle.y[i]);
	}
	printf("%lf\n", distanceSum(triangle));

	return 0;
}
