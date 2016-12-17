#include <stdio.h>
#define N 5

typedef struct {
	int id;
	char name[20];
	int score;
} student_t;

void printStructure(student_t []);
void quickSort(student_t [], int, int);
void swap(student_t *, student_t *);

int main(void)
{
	student_t student[] = {
		{101, "斉藤", 76},
		{103, "田中", 53},
		{100, "中野", 81},
		{102, "松本", 93},
		{104, "吉田", 85}
	};
	
	printf("＜ソート前＞\n");
	printStructure(student);
	quickSort(student, 0, N - 1);
	printf("\n");
	printf("＜ソート後＞\n");
	printStructure(student);

	return 0;
}


void printStructure(student_t student[])
{
	int i;

	printf("学生番号\t名前\t\t点数\n");
	for (i = 0; i < N; i++) {
		printf("%d\t\t%s\t\t%d\n", student[i].id, student[i].name, student[i].score);
	}
}

void quickSort(student_t a[], int left, int right)
{
	int pl = left;
	int pr = right;
	int pivot = (a[pl].id + a[pr].id) / 2;

	while (1) {
		while (a[pl].id < pivot) pl++;
		while (pivot < a[pr].id) pr--;
		if (pr < pl) break;
		swap(&a[pl], &a[pr]);
		pl++;
		pr--;
	}
	if (left < pr) quickSort(a, left, pr);
	if (pl < right) quickSort(a, pl, right);
}

void swap(student_t *a, student_t *b)
{
	student_t tmp = *a;
	*a = *b;
	*b = tmp;
}
