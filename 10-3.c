#include <stdio.h>
#include <stdlib.h>

#define MAX 2000
#define FMAX 20

void swap(int *x, int *y);
void quick(int a[], int left, int right);
int bin_search(int a[], int n, int key);
int lin_search(int a[], int n, int key);
void print_result(int, int);

int n_comp;

int main(void)
{
	int i;
	int seisu[MAX];
	int n, key, idx;
	char fname[FMAX];
	FILE *fp;

	n = MAX;
	printf("\n");
	printf("Input file name: ");
	scanf("%s", fname);
	fp = fopen(fname, "r");
	if (!fp) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < n; i++) {
		fscanf(fp, "%d", &seisu[i]);
	}
	printf("Number to search: ");
	scanf("%d", &key);
	printf("\n");
	n_comp = 0;
	idx = lin_search(seisu, n, key);
	n_comp = idx;
	printf("--------- Results ---------\n");
	printf("\n");
	printf("Linear search:\n");
	print_result(key, idx);
	printf("\n");
	quick(seisu, 0, n);
	n_comp = 0;
	bin_search(seisu, n, key);
	printf("Binary search:\n");
	print_result(key, idx);
	printf("\n");

	fclose(fp);
	return 0;
}

void swap(int *x, int *y)
{
	int tmp = *x;
	
	*x = *y;
	*y = tmp;
}

void
quick(int a[], int left, int right)
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
		quick(a, left, pr);
	}
	if (pl < right) {
		quick(a, pl, right);
	}
}

int bin_search(int x[], int n, int key)
{
	int pl, pr, pc;

	pl = 0;
	pr = n - 1;
	while (1) {
		if (pr < pl) return -1;
		pc = (pl + pr) / 2;
		if (x[pc] < key) {
			pl = pc + 1;
			n_comp++;
		}
		else if (key < x[pc]) {
			pr = pc - 1;
			n_comp++;
		}
		else if (x[pc] == key)
			return pc;
	}
}

int lin_search(int a[], int n, int key)
{
	int i = 0;

	while (1) {
		if (i == n)
			return -1;
		if (a[i] == key) {
			return i;
		}
		i++;
	}
}

void print_result(int key, int idx)
{
	if (idx == -1)
		printf("Searching was failed!\n");
	else
		printf("%d is located at %d\n", key, idx);
	printf("n_comp: %d\n", n_comp);
}
