#include <stdio.h>
#define NUM 20 

int
binary_search(int a[], int key);

int
main(void)
{
	int a[] = {1, 2, 4, 5, 6, 7, 9, 10, 11, 13, 15, 16, 17, 18, 19, 20, 22, 24, 27, 29};
	int i, locate;

	printf("探索する値\t探索結果\tインデックス\n");
	for (i = 0; i < NUM; i++) {
		locate = binary_search(a, i);
		printf("%d\t\t", i);
		if (locate == -1) {
			printf("失敗\t\t");
		}
		else {
			printf("成功\t\t");
		}
		if (locate != -1) {
			printf("%d", locate);
		}
		printf("\n");
	}

	return 0;
}

int
binary_search(int a[], int key)
{
	int pl, pr, pc;

	pl = 0; pr = NUM - 1;
	while (1) {
		if (pr < pl) return -1;
		pc = (pl + pr) / 2;
		if (a[pc] < key)
			pl = pc + 1;
		else if (key < a[pc])
			pr = pc - 1;
		else if (a[pc] == key)
			return pc;
	}
}
