#include <stdio.h>
#include <stdlib.h>

int n_comp = 0, n_exchange = 0, n_shift = 0, n_insert = 0;

void bubble(int [], int);
void insertion(int [], int);
void swap(int *, int *);
void setRandomValue(int [], int);

int main(void)
{
	int i, num;

	printf("要素数：");
	scanf("%d", &num);
	printf("\n");

	printf("* * * 要素数 %d 個の場合 * * *\n", num);
	printf("\n");

	int data_bub[num], data_ins[num];

	setRandomValue(data_bub, num);
	for (i = 0; i < num; i++) data_ins[i] = data_bub[i];

	bubble(data_bub, num);
	printf("- - - - バブルソート - - - -\n");
	printf("比較回数：%d\n", n_comp);
	printf("交換回数：%d\n", n_exchange);
	printf("\n");

	n_comp = 0;

	insertion(data_ins, num);
	printf("- - - - 挿入ソート - - - -\n");
	printf("比較回数：%d\n", n_comp);
	printf("シフト回数：%d\n", n_shift);
	printf("挿入回数：%d\n", n_insert);
}

void bubble(int data[], int num)
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

void insertion(int data[], int num)
{
	int i, j, tmp;
	for (i = 1; i < num; i++) {
		n_comp++;
		tmp = data[i];
		for (j = i - 1; 0 <= j; j--) {
			if (tmp < data[j]) {
				n_shift++;
				data[j + 1] = data[j];
			}
			else
				break;
		}
		n_insert++;
		data[j + 1] = tmp;
	}
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void setRandomValue(int data[], int num)
{
	int i;
	for (i = 0; i < num; i++)
		data[i] = rand();
}
