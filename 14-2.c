#include <stdio.h>
#include <string.h>

#define ALNUM 25

typedef struct {
	char c;
	int cnt;
} init_t;

void
swap(init_t *a, init_t *b)
{
	init_t tmp = *a;
	*a = *b;
	*b = tmp;
}

void
quick(init_t a[], int left, int right)
{
	int pl = left;
	int pr = right;
	int pivot;

	pivot = (a[pl].cnt + a[pr].cnt) / 2;

	while (1) {
		while (a[pl].cnt > pivot) {
			pl++;
		}
		while (pivot > a[pr].cnt) {
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

int
main(void)
{
	int i;
	char head;
	char buf[1024];
	init_t word[ALNUM];

	memset(word, 0, sizeof(word));
	for (i = 0; i < ALNUM; i++) {
		word[i].c = 'a' + i;
	}
	for (;;) {
		printf("英単語を入力してください：");
		scanf("%s", buf);
		head = buf[0];
		if (head == 'z') break;
		word[head - 'a'].cnt++;
	}
	quick(word, 0, ALNUM - 1);
	for (i = 0; i < 5; i++) {
		if (0 < word[i].cnt) {
			printf("%c：%d 回\n", word[i].c, word[i].cnt);
		}
	}

	return 0;
}
