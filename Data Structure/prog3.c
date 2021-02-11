#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define size 5

struct Queue
{
    int front, rear;
    char data[size][100];
};


typedef struct Queue queue;


void sender(queue *q, char item[100])
{
    if (q->front == ((q->rear + 1) % size))
        printf("Queue Full \n");
    else
    {
        q->rear = (q->rear + 1) % size;
        strcpy(q->data[q->rear], item);
        //printf("%s\n",q->data[q->rear] );
        if (q->front == -1)
            q->front++;
    }
}


void reciever(queue *q)
{
    char *del;
    if (q->front == -1)
        printf("Queue is empty \n");
    else
    {
        del = q->data[q->front];
        printf("Messaged Recieved is : %s\n", del);
        if (q->front == q->rear)
        {
            q->front = -1;
            q->rear = -1;
        }
        else
            q->front = (q->front + 1) % size;
    }
}


void display(queue q)
{
    printf("\n");
    int i;
    if (q.front == -1)
        printf( "Queue is Empty\n");
    else
    {
        printf("Queue Content is : \n");
        //i = q.front;
        //while(i != q.rear){
            //printf("%s\n", q.data[i] );
            //i = (i + 1) % size ;
        //}
        for (i = q.front; i != q.rear; i = (i + 1) % size)
            printf("%s\n", q.data[i]);
        printf("%s\n", q.data[i]);
    }
    printf("\n");
}


int main()
{
    int ch;
    char message[20];
    queue q;
    q.front = -1, q.rear = -1;
    while (1)
    {
        printf("Choose an option: \n");
        printf("\t1) Sender\n");
        printf("\t2) Reciever\n");
        printf("\t3) Display\n");
        printf("\t4) Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter message to be Sent: ");
            //getchar();
            scanf(" %[^\n]", message);
            sender(&q, message);
            break;
        case 2:
            reciever(&q);
            break;
        case 3:
            display(q);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Enter Valid Option");
            exit(0);
            break;
        }
    }
    return 0;
}
