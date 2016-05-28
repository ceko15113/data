#include <stdio.h>
#include <stdlib.h>

struct student {
	int id;
	char name[32];
};

int main(void)
{
	int i;
	FILE *fp;

	struct student gakusei[3] = {
		{276001, "sato"},
		{276002, "suzuki"},
		{276003, "tanaka"}
	};
	fp = fopen("out.txt", "w");
	for (i = 0; i < 3; i++) {
		fprintf(fp, "学生番号：%d, 氏名：%s\n", gakusei[i].id, gakusei[i].name);
	}
	fclose(fp);

	return 0;
}
