#include <stdio.h>
#include <stdlib.h>
#define NUM 4
#define LEN 10
#define COL 2

int main(void)
{
	int i, max, max_idx;
	char pref[NUM][LEN];
	int data[COL][NUM];
	double density[NUM];
	FILE *fp;

	for (i = 0; i < NUM; i++) {
		printf("%d 番目の都道府県名は？：", i + 1);
		scanf("%s", pref[i]);
		printf("人口は？：");
		scanf("%d", &data[0][i]);
		printf("面積(km^2)は？：");
		scanf("%d", &data[1][i]);
		density[i] = (double)data[0][i] / data[1][i];
	}
	max = density[0];
	max_idx = 0;
	for (i = 1; i < NUM; i++) {
		if (max < density[i]) {
			max = density[i];
			max_idx = i;
		}
	}
	fp = fopen("out.txt", "w");
	if (!fp) {
		perror("fopen");
		exit(1);
	}
	for (i = 0; i < NUM; i++) {
		fprintf(fp, "%s %d %d %.1f\n", pref[i], data[0][i], data[1][i], density[i]);
	}
	fprintf(fp, "-----------------------------\n");
	fprintf(fp, "最も人口密度が高いのは%sです。\n", pref[max_idx]);

	printf("ファイル out.txt に出力します。");

	return 0;
}
