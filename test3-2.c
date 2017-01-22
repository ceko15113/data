#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int n;
	int cnt;
} num_t;

void
insert(num_t a[], int n)
{
	int i, j;
	num_t tmp;

	for (i = 1; i < n; i++) {
		tmp = a[i];
		for (j = i - 1; j >= 0; j--) {
			if (a[j].cnt > tmp.cnt) {
				a[j + 1] = a[j];
			}
			else {
				break;
			}
		}
		a[j + 1] = tmp;
	}
}
int
main()
{
	int i, n;
	int buf;
	num_t num[10];

	memset(num, 0, sizeof(num));
	for (i = 0; i < 10; i++) {
		num[i].n = i;
	}
	printf("0〜99までの数字を入力してください(-1を入力すると終了)\n");
	while (1) {
		scanf("%d", &buf);
		if (buf == -1) break;
		n = buf % 10;
		num[n].cnt++;
	}
	insert(num, 10);
	printf("一の位　出現回数\n");
	for (i = 0; i < 10; i++) {
		printf("%d　　　%d\n", num[i].n, num[i].cnt);
	}

	return 0;
}

