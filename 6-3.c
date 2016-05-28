#include <stdio.h>
#include <stdlib.h>

#define FILENAME "foo.txt"

#define CUR_Y 2016
#define CUR_M 5
#define CUR_D 20

int ageCalc(int y, int m, int d)
{
	int i;
	int age;

	age = CUR_Y - y;
	if (CUR_M <= m) age--;
	if (CUR_M == m && d <= CUR_D) age++;

	return age;
}

int main(void)
{
	int i;
	FILE *fp;
	int y, m, d;
	double h, w;
	char fn[20], ln[20];

	fp = fopen(FILENAME, "r");

	fscanf(fp, "%d %d %d", &y, &m, &d);
	fscanf(fp, "%lf %lf", &h, &w);
	fscanf(fp, "%s %s", ln, fn);

	printf("氏名は %s %s です\n", ln, fn);
	printf("生年月日は %d 年 %d 月 %d 日です（%d 歳）\n", y, m, d, ageCalc(y, m, d));
	printf("身長は %.1f cm　体重は %.1f Kg です\n", h, w);

	fclose(fp);
	return 0;
}
