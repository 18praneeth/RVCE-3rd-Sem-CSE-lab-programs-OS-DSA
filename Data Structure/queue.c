//Queue is using array

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef struct queue{
	int items[SIZE] ;
	int front ;
	int rear ;
}Queue;

void enque(Queue *q, int x){
	if (q->rear == SIZE - 1){
		printf("\nQueue is full");
	}
	else{
		if (q->front = -1){
			q->front = 0;
		}
		q->items[++ q->rear] = x ;
		printf("\nInserted -> %d",x);
	}
}


void deque(Queue *q){
	if (q->front == -1)
		printf("\nQueue is Empty");
	else{
		printf("\nDeleted %d",q->items[q->front]);
		q->front ++ ;
		if (q->front > q->rear)
			q->front = q->rear = -1;
	}
}

void display(Queue q){
	if (q.rear == -1)
		printf("\nQueue is Empty");
	else{
		int i;
		printf("\nQueue Elements are:\n");
		for (i = q.front; i<= q.rear ; i ++){
			printf("%d ", q.items[i] );
		}
	}
}



int main()
{
	/* code */
	Queue queue ;

	queue.front = queue.rear = -1;

	enque(&queue, 3);
	display(queue);
	enque(&queue, 4);
	display(queue);
	deque(&queue);
	display(queue);


	return 0;
}
