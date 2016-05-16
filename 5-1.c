#include <stdio.h>

struct student {
	int id;
	char name[20];
	double height;
	double weight;
};

int main(void)
{
	struct student gakusei[5];
	int i;

	printf("構造体配列のサイズ：%d Byte\n", (int)sizeof(gakusei));
	for (i = 0; i < 5; i++) {
		printf("学生番号：");
		scanf("%d", &gakusei[i].id);
		printf("氏名：");
		scanf("%s", gakusei[i].name);
		printf("身長：");
		scanf("%lf", &gakusei[i].height);
		printf("体重：");
		scanf("%lf", &gakusei[i].weight);
	}
	for (i = 0; i < 5; i++) {
		printf("学生番号：%d　氏名：%s　身長：%.1lf cm　体重：%.1lf kg\n",
		gakusei[i].id, gakusei[i].name, gakusei[i].height, gakusei[i].weight);
	}
	return 0;
}
