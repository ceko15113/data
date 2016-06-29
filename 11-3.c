#include <stdio.h>
#include <string.h>

#define SIZE 9

void showList(int []);
int insertNode(int, int, int []);
int deleteNode(int, int []);

int main(void)
{
	int i, n, l, d;
	int data[SIZE];

	memset(data, -1, sizeof(data));
	for (i = 0, n = 2; i < SIZE; i++, n += 20) {
		data[i] = n;
	}
	while (1) {
		showList(data);
		printf("insert = 0, delete = 1, exit = 2: ");
		scanf("%d", &n);
		switch (n) {
			case 0:
			printf("locate: ");
			scanf("%d", &l);
			printf("data: ");
			scanf("%d", &d);
			insertNode(l, d, data);
			break;
			case 1:
			printf("locate: ");
			scanf("%d", &l);
			deleteNode(l, data);
			break;
			case 2:
			return 0;
		}
	}
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

int deleteNode(int no, int data[])
{
	int n, i, tmp;

	no--;
	for (n = 0; n < SIZE; n++) {
		if (data[n] == -1) break;
	}
	if (no < 0 || n <= no) return -1;
	else {
		tmp = data[no];
		for (i = no + 1; i < n; i++) {
			data[i - 1] = data[i];
		}
		data[n - 1] = -1;
		return tmp;
	}
}

int insertNode(int no, int insdata, int data[])
{
	int i, n;

	no--;
	for (n = 0; n < SIZE; n++) {
		if (data[n] == -1) break;
	}
	if (n == SIZE) return -1;
	else if (n < no) return -1;
	else {
		for (i = n - 1; i >= no; i--) {
			data[i + 1] = data[i];
		}
		data[no] = insdata;
		return 0;
	}
}
