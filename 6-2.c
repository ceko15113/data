#include <stdio.h>
#include <stdlib.h>

#define FILENAME "out.txt"

int main(void)
{
	FILE *fp;
	int y, m, d;
	double h, w;
	char fn[20], ln[20];

	fp = fopen(FILENAME, "w");

	printf("誕生年：");
	scanf("%d", &y);
	printf("誕生月：");
	scanf("%d", &m);
	printf("誕生日：");
	scanf("%d", &d);
	printf("\n");

	printf("身長：");
	scanf("%lf", &h);
	printf("体重：");
	scanf("%lf", &w);
	printf("\n");

	printf("名字：");
	scanf("%s", ln);
	printf("名前：");
	scanf("%s", fn);

	fprintf(fp, "%d %d %d\n", y, m, d);
	fprintf(fp, "%f %f\n", h, w);
	fprintf(fp, "%s %s\n", ln, fn);

	fclose(fp);

	return 0;
}
