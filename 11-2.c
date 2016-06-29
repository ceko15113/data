#include <stdio.h>
#include <string.h>

#define SIZE 9

void showList(int []);

int main(void)
{
	int i, n;
	int list[SIZE];

	for (i = 0, n = 2; i < SIZE; i++, n += 2) {
		list[i] = n;
	}
	showList(list);

	return 0;
}

void showList(int data[])
{
	int i;

	printf("List: ");
	for (i = 0; i < SIZE; i++) {
		if (data[i] != -1)
			printf("%4d", data[i]);
		else
			break;
	}
	printf("\n");
}
