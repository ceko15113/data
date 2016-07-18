#include <stdio.h>
#include <stdlib.h>

#define NUM 10

typedef struct {
	int id;
	char name[20];
	int jap;
	int math;
	int eng;
} student_t;

int bin_search(student_t x[], int n, int key)
{
	int pl, pr, pc;

	pl = 0;
	pr = NUM - 1;
	while (1) {
		if (pr < pl) return -1;
		pc = (pl + pr) / 2;
		if (x[pc].id < key)
			pl = pc + 1;
		else if (key < x[pc].id)
			pr = pc - 1;
		else if (x[pc].id == key)
			return pc;
	}
}

int main(void)
{
	int idx, key;
	student_t student[] = {
		{6101, "Erika", 98, 76, 85},
		{6102, "Fumiyasu", 47, 88, 91},
		{6103, "Rika", 56, 90, 78},
		{6104, "Shoya", 65, 76, 83},
		{6105, "Sho", 79, 73, 82},
		{6106, "Tatsuya", 89, 48, 90},
		{6107, "Kazunori", 68, 77, 85},
		{6108, "Katsuhiro", 91, 65, 59},
		{6109, "Tomohiro", 79, 62, 89},
		{6110, "Masato", 85, 88, 79}
	};

	printf("学生番号を入力してください：");
	scanf("%d", &key);
	idx = bin_search(student, NUM, key);
	if (idx == -1) {
		printf("その学生はいません。\n");
		exit(1);
	}
	printf("%s さん（%d）の成績は、国語 %d 点、数学 %d 点、英語 %d 点、合計 %d 点です。\n",
		student[idx].name, student[idx].id, student[idx].jap, student[idx].math, student[idx].eng,
		student[idx].jap + student[idx].math + student[idx].eng
	);
	
	return 0;
}
