#include <stdio.h>
#define NUM 10

void insertion(int a[], int n);
int bin_search(int a[], int n, int key);

int main(void)
{
	int i, key, idx;
	int x[NUM];

	printf("\n");
	printf("Input integer number %d times\n", NUM);
	for (i = 0; i < NUM; i++) {
		printf("x[%d]: ", i);
		scanf("%d", &x[i]);
	}
	insertion(x, NUM);
	printf("\n");
	printf("Result: ");
	for (i = 0; i < NUM; i++) {
		printf("%d ", x[i]);
	}
	printf("\n");
	printf("\n");
	printf("Number to search: ");
	scanf("%d", &key);
	idx = bin_search(x, NUM, key);
	if (idx == -1)
		printf("Searching was failed!\n");
	else
		printf("%d is located at %d\n", key, idx);
	printf("\n");
	
	return 0;
}

void insertion(int x[], int num)
{
	int i, j, tmp;
	for (i = 1; i < num; i++) {
		tmp = x[i];
		for (j = i - 1; 0 <= j; j--) {
			if (tmp < x[j]) {
				x[j + 1] = x[j];
			}
			else
				break;
		}
		x[j + 1] = tmp;
	}
}

int bin_search(int x[], int n, int key)
{
	int pl, pr, pc;

	pl = 0;
	pr = NUM - 1;
	while (1) {
		if (pr < pl) return -1;
		pc = (pl + pr) / 2;
		if (x[pc] < key)
			pl = pc + 1;
		else if (key < x[pc])
			pr = pc - 1;
		else if (x[pc] == key)
			return pc;
	}
}
