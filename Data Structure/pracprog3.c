#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 10

struct queue{
    int front, rear;
    char data[size][100];
};

typedef struct queue QUEUE;

void sender(QUEUE *q, char message[100]){
    if(q->front == (q->rear + 1)%size){
        printf("Queue is full!!");
        return;
    }
    q->rear = (q->rear + 1)%size;
    strcpy(q->data[q->rear], message);
    if(q->front == -1){
        q->front ++;
    }
}

void receiver(QUEUE *q){
    if(q->front == -1){
        printf("Queue is Empty\n");
        return;
    }

    printf("Deleted message %s\n", q->data[q->front]);
    if(q->rear == q->front){
        q->rear = -1;
        q->front = -1;
        return;
    }
    q->front = (q->front + 1)%size;
}

void display(QUEUE q){
    printf("\n");
    if(q.front == -1){
        printf("Queue is empty!!");
        return;
    }
    int i;
    for(i=q.front; i!=q.rear; i++){
        printf("%s\n", q.data[i]);
    }
    printf("%s\n", q.data[i]);
}

int main()
{
    int choice;
    QUEUE q;
    char message[50];
    q.front = -1;
    q.rear = -1;
    while(1){
        printf("1. Sender\n");
        printf("2. Receiver\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter the choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the message to be sent: ");
            scanf(" %[^\n]", message);
            sender(&q, message);
            break;
        case 2:
            receiver(&q);
            break;
        case 3:
            display(q);
            break;
        default:
            exit(0);
            break;
        }
        
    }
    return 0;
}
