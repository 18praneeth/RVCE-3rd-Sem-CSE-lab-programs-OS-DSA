#include <stdio.h>

#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;


int isFull(){
	if((front = rear + 1) || (front == 0 && rear == SIZE - 1)) return 1;
	return 0;
}

int isEmpty(){
	if (front == -1) return 1;
	return 0;
}

//Adding an element
void enQueue(int element) {
	if(isFull())
		printf("\nQueue is Full!!\n");
	else{
		if (front == -1) front = 0 ;
		rear = (rear + 1) % SIZE;
		items[rear] = element;
		printf("\nInserted -> %d", element);
	}
}

//Removing an element.

void deQueue(){
	int element;
	if (isEmpty()){
		printf("\nQueue is Empty!!\n");
		return (-1);
	}

	else{
		element = items[front];
		if (front == rear){
			front = -1;
			rear = -1;
		}
		else{
			front = (front + 1) % SIZE;
		}
		printf("\nDeleted element -> %d\n", element);
		return (element);
	}
}

//Display the queue
void display(){
	int i;
}
