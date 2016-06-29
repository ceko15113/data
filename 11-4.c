#include <stdio.h>
#include <string.h>

#define SIZE 9

typedef struct {
	int data;
	int next;
} list_t;

void showList(list_t []);

int main(void)
{
	int i, n;
	list_t list[SIZE];

	memset(&list, -1, sizeof(list));
	for (i = 0, n = 2; i < SIZE; i++, n += 2) {
		list[i].data = n;
		if (i == SIZE - 1) break;
		list[i].next = i + 1;
	}
	printf("List: ");
	showList(list);

	return 0;
}

void showList(list_t list[])
{
	int idx = 0;

	while (idx != -1) {
		printf("%d ", list[idx].data);
		idx = list[idx].next;
	}
	printf("\n");
}
