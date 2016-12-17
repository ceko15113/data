#include <stdio.h>
#include <string.h>

#define QUEUE_SIZE 5
#define NO_DATA -1

int queue[QUEUE_SIZE];
int front = 0;
int rear = 0;
int num = 0;

void show();
int enqueue(int);
int dequeue();

int main(void)
{
	int i;

	memset(queue, -1, sizeof(queue));
	show();
	for (i = 1; i <= 4; i++) {
		printf("%d をエンキュー\n", i);
		enqueue(i);
	}
	show();
	for (i = 1; i <= 3; i++) {
		printf("%d をデキュー\n", i);
		dequeue();
	}
	show();
	for (i = 5; i <= 6; i++) {
		printf("%d をエンキュー\n", i);
		enqueue(i);
	}
	show();
	return 0;
}

void show()
{
	int i, idx;

#ifdef TEXT
	printf("キューの中身を表示：");
	idx = front;
	for (i = 0; i < QUEUE_SIZE; i++) {
		if (queue[idx] != NO_DATA)
			printf("[%3d]", queue[idx++]);
		else
			printf("[   ]");
		if (idx == QUEUE_SIZE) idx = 0;
	}
#else
	idx = front;
	for (i = 0; i < num; i++) {
		printf("%d ", queue[idx++]);
		if (QUEUE_SIZE == idx) idx = 0;
	}
#endif
	printf("\n");
}

int enqueue(int data)
{
	if (num == QUEUE_SIZE)
		return -1;
	else {
		queue[rear] = data;
		rear++;
		num++;
		if (rear == QUEUE_SIZE) rear = 0;
		return 0;
	}
}

int dequeue()
{
	if (num == 0)
		return -1;
	else {
		int data = queue[front];
		queue[front] = NO_DATA;
		front++;
		num--;
		if (front == QUEUE_SIZE) front = 0;
		return data;
	}
}
