#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INIT_ELEM 5000
#define N 5

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

void
bubble_sort(int data[], int num)
{
	int i, j;
	for (i = num - 1; 0 <= i; i--) {
		for (j = 0; j < i; j++) {
			if (data[j + 1] < data[j]) {
				swap(&data[j + 1], &data[j]);
			}
		}
	}
}

void
quick_sort(int a[], int left, int right)
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
			break;
		}

		swap(&a[pl], &a[pr]);
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

void
setRandomValue(int data[], int num)
{
	int i;
	srand(time(NULL));
	for (i = 0; i < num; i++)
		data[i] = rand() % 10000;
}

int
main(void)
{
	int i, j, bufsize;
	int *quick[N], *bubble[N];
	time_t start, end;

	for (i = 0, bufsize = INIT_ELEM; i < N; i++, bufsize *= 2) {
		quick[i] = (int *)xmalloc(bufsize * sizeof(int));
		bubble[i] = (int *)xmalloc(bufsize * sizeof(int));
		setRandomValue(quick[i], bufsize);
		for (j = 0; j < bufsize; j++) bubble[i][j] = quick[i][j];
	}

	printf("＜クイックソート法＞\n");
	printf("\n");
	for (i = 0, j = INIT_ELEM; i < N; i++, j *= 2) {
		printf("　データ数：%d 個\n", j);
		start = clock();
		quick_sort(quick[i], 0, j - 1);
		end = clock();
		printf("　計算時間：%.3f 秒\n", (float)(end - start) / CLOCKS_PER_SEC);
		printf("\n");
	}

	printf("\n");

	printf("＜バブルソート法＞\n");
	printf("\n");
	for (i = 0, j = INIT_ELEM; i < N; i++, j *= 2) {
		printf("　データ数：%d 個\n", j);
		start = clock();
		bubble_sort(bubble[i], j);
		end = clock();
		printf("　計算時間：%.3f 秒\n", (float)(end - start) / CLOCKS_PER_SEC);
		printf("\n");
	}

	return 0;
}
