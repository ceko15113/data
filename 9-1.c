#include <stdio.h>

#define N 10

int path = 0;

void print_array(int a[])
{
	int i;
	for (i = 0; i < N; i++) printf("%d ", a[i]);
	printf("\n");
}

void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void quick(int a[], int left, int right)
{
	int pl = left;
	int pr = right;
	int pivot;
	int i;

	printf("%d 回目の呼び出し：\n", ++path);
	printf("＜開始時＞\n");

	pivot = (a[pl] + a[pr]) / 2;

	printf("　左端の添え字：%d\n", pl);
	printf("　右端の添え字：%d\n", pl);
	printf("　ピボットの値：%d\n", pivot);
	printf("　左端〜右端の値：");
	print_array(a);

	while (1) {
		while (a[pl] < pivot) {
			pl++;
		}
		while (pivot < a[pr]) {
			pr--;
		}
		if (pr < pl)
			break;

		swap(&a[pl], &a[pr]);
		pl++;
		pr--;
	}

	printf("＜ソーティング結果＞\n");
	print_array(a);
	printf("\n");

	if (left < pr) {
		quick(a, left, pr);
	}
	if (pl < right) {
		quick(a, pl, right);
	}
}

int main(void)
{
	int a[] = {7, 2, 5, 3, 1, 10, 6, 8, 9, 4};
	quick(a, 0, 9);
	return 0;
}
