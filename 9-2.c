#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n_comp, n_exchange;

void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void *
xmalloc(size_t sz)
{
	void *ptr;
	ptr = malloc(sz);
	if (!ptr) {
		printf("malloc: メモリを確保できません\n");
		exit(1);
	}
	return ptr;
}

void bubble_sort(int data[], int num)
{
	int i, j;
	for (i = num - 1; 0 <= i; i--) {
		for (j = 0; j < i; j++) {
			n_comp++;
			if (data[j + 1] < data[j]) {
				swap(&data[j + 1], &data[j]);
				n_exchange++;
			}
		}
	}
}

void quick_sort(int a[], int left, int right)
{
	int pl = left;
	int pr = right;
	int pivot;
	int i;

	pivot = (a[pl] + a[pr]) / 2;

	while (1) {
		while (a[pl] < pivot) {
			pl++;
		}
		while (pivot < a[pr]) {
			pr--;
		}
		if (pr < pl) {
			n_comp++;
			break;
		}

		swap(&a[pl], &a[pr]);
		n_exchange++;
		pl++;
		pr--;
	}

	if (left < pr) {
		quick_sort(a, left, pr);
	}
	if (pl < right) {
		quick_sort(a, pl, right);
	}
}

void setRandomValue(int data[], int num)
{
	int i;
	srand(time(NULL));
	for (i = 0; i < num; i++)
		data[i] = rand() % 100000;
}

int main(void)
{
	int i, j;
	int *quick[5], *bubble[5];

	for (i = 0, j = 20; i < 5; i++, j += 20) {
		quick[i] = (int *)xmalloc(j);
		bubble[i] = (int *)xmalloc(j);
		setRandomValue(quick[i], j);
		bubble[i][j] = quick[i][j];
	}

	printf("＜クイックソート法＞\n");
	for (i = 0, j = 20; i < 5; i++, j += 20) {
		printf("　データ数：%d 個\n", j);
		n_comp = n_exchange = 0;
		quick_sort(quick[i], 0, j - 1);
		printf("　比較回数：%d 回\n", n_comp);
		printf("　交換回数：%d 回\n", n_exchange);
	}

	printf("＜バブルソート法＞\n");
	for (i = 0, j = 20; i < 5; i++, j += 20) {
		printf("　データ数：%d 個\n", j);
		n_comp = n_exchange = 0;
		bubble_sort(bubble[i], j);
		printf("　比較回数：%d 回\n", n_comp);
		printf("　交換回数：%d 回\n", n_exchange);
	}

	return 0;
}


