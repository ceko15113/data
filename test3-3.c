#include <stdio.h>
#include <string.h>
#include <ctype.h>

int stack[20];
int top = -1;

void
push(int data)
{
	if (top == -1) {
		top++;
		stack[top] = data;
	}
	else {
		top++;
		stack[top] = data;
	}
}

int
pop()
{
	int n;

	n = stack[top];
	stack[top] = -1;
	top--;

	return n;
}
int
main()
{
	int i, n;
	char buf[1024];

	memset(stack, -1, sizeof(stack));
	printf("逆ポーランド記法で記述された数式を入力してください\n");
	scanf("%s", buf);
	for (i = 0; buf[i] != 0; i++) {
		n = buf[i] - '0';
		if ('0' <= buf[i] && buf[i] <= '9') {
			push(buf[i] - '0');
		}
		else {
			switch (buf[i]) {
				case '+':
				push(pop() + pop());
				break;
				case '-':
				push(pop() - pop());
				break;
				case '*':
				push(pop() * pop());
				break;
			}
		}
	}
	printf("%d\n", pop());
	return 0;
}

