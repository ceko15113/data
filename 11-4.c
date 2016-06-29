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
	list[0].data = 1; list[0].next = 3;
	list[1].data = 9; list[1].next = 2;
	list[2].data = 4; list[2].next = 5;
	list[3].data = 3; list[3].next = 4;
	list[4].data = 5; list[4].next = 1;
	list[5].data = 15; list[5].next = -1;
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
