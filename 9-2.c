#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INIT_ELEM 20
#define N 5

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
		perror("malloc");
		exit(EXIT_FAILURE);
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
	int i, j, bufsize;
	int *quick[N], *bubble[N];

	for (i = 0, bufsize = INIT_ELEM; i < N; i++, bufsize += 20) {
		quick[i] = (int *)xmalloc(bufsize * sizeof(int));
		bubble[i] = (int *)xmalloc(bufsize * sizeof(int));
		setRandomValue(quick[i], bufsize);
		for (j = 0; j < bufsize; j++) bubble[i][j] = quick[i][j];
	}

	printf("＜クイックソート法＞\n");
	printf("\n");
	for (i = 0, bufsize = INIT_ELEM; i < N; i++, bufsize += 20) {
		printf("　データ数：%d 個\n", bufsize);
		n_comp = n_exchange = 0;
		quick_sort(quick[i], 0, bufsize - 1);
		printf("　比較回数：%d 回\n", n_comp);
		printf("　交換回数：%d 回\n", n_exchange);
		printf("\n");
	}
	printf("\n");

	printf("＜バブルソート法＞\n");
	printf("\n");
	for (i = 0, bufsize = INIT_ELEM; i < N; i++, bufsize += 20) {
		printf("　データ数：%d 個\n", bufsize);
		n_comp = n_exchange = 0;
		bubble_sort(bubble[i], bufsize);
		printf("　比較回数：%d 回\n", n_comp);
		printf("　交換回数：%d 回\n", n_exchange);
		printf("\n");
	}
	printf("\n");

	return 0;
}
