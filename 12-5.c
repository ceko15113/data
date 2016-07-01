#include <stdio.h>
#include <string.h>

#define QUEUE_SIZE 5
#define NO_DATA -1

int enQueue(int);
int deQueue();
void showQueue();

int queue[QUEUE_SIZE];
int front = -1;
int rear = -1;
int num = 0;

int main(void)
{
	int n, data;

	front = 0;
	rear = 0;
	memset(queue, -1, sizeof(queue));
	do {
		printf("(1) enqueue  (2) dequeue  (0) exit : ");
		scanf("%d", &n);
		switch (n) {
			case 1:
			printf("Data: ");
			scanf("%d", &data);
			if (enQueue(data) == -1) {
				printf("Queue is full!\n");
				printf("Enqueue is failed!\n");
			}
			else {
				showQueue();
			}
			break;

			case 2:
			if (deQueue() == -1) {
				printf("Queue empty!\n");
				printf("Dequeue is failed!\n");
			} else {
				showQueue();
			}
			break;
		}
	} while (n != 0);

	return 0;
}

void showQueue()
{
	int i;

	printf("Queue: ");
	for (i = 0; i < QUEUE_SIZE; i++)
	{
		if (queue[i] != NO_DATA) {
			printf("[%3d]", queue[i]);
		}
		else {
			printf("[   ]");
		}
	}
	printf("\n");
}

int enQueue(int data)
{
	if (num == QUEUE_SIZE) return -1;
	else {
		queue[rear] = data;
		rear++;
		num++;
		if (rear == QUEUE_SIZE)
			rear = 0;
		return 0;
	}
}

int deQueue()
{
	if (num == 0) return -1;
	else {
		int data = queue[front];
		queue[front] = NO_DATA;
		front++;
		num--;
		if (front == QUEUE_SIZE) front = 0;
		return data;
	}
}
