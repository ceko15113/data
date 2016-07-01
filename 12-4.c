#include <stdio.h>
#include <string.h>

#define STACK_SIZE 5
#define NO_DATA -1

int push(int data);
int pop();
void showStack();

int stack[STACK_SIZE];
int sp = -1;

int main(void)
{
	int n, data;

	memset(stack, 0, sizeof(stack));
	do {
		printf("(1) push  (2) pop  (0) exit : ");
		scanf("%d", &n);
		switch (n) {
			case 1:
			printf("Data: ");
			scanf("%d", &data);
			if (push(data) == -1) {
				printf("Stack overflow!\n");
				printf("Stack push is failed!\n");
			}
			else {
				showStack();
			}
			break;

			case 2:
			if (pop() == -1) {
				printf("Stack empty!\n");
				printf("Stack pop is failed!\n");
			} else {
				showStack();
			}
			break;
		}
	} while (n != 0);

	return 0;
}

void showStack() {
	int i;
	printf("Stack: ");
	for (i = 0; i <= sp; i++) {
		printf("[%d]", stack[i]);
	}
	printf("\n");
}

int push(int data)
{
	sp++;
	if (sp == STACK_SIZE) {
		sp--;
		return -1;
	}
	else {
		stack[sp] = data;
		return 0;
	}
}

int pop()
{
	if (sp < 0)
		return -1;
	else {
		int data = stack[sp];
		sp--;
		return data;
	}
}
