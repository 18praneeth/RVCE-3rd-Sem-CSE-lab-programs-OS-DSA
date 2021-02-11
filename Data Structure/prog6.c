// Sparse Matrix using Doubly linked list
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int row, col, data;
    struct node *next;
    struct node *prev;
};

typedef struct node *NODE;

NODE insertend(NODE start, int row, int col, int data){
    NODE temp, current;
    temp = (NODE)malloc(sizeof(struct node));
    temp->row = row;
    temp->col = col;
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;
    if (start == NULL){
        return temp;
    }
    current = start;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = temp;
    temp->prev = current;
    return start;
}


void dispalay(NODE start){
    NODE temp;
    if(start == NULL){
        printf("List is Empty\n");
    }
    else{
        printf("\nRow\tCol\tData\n");
        temp = start;
        while(temp != NULL){
            printf("%d\t%d\t%d\t\n",temp->row, temp->col, temp->data );
            temp = temp->next;
        }
    }
}

void displaymatrix(NODE start, int row, int col){
    int i, j;
    NODE temp;
    temp = start;
    printf("The Matrix is:\n");
    for(i=1; i<=row; i++){
        for(j=1; j<=col; j++){
            if(temp!=NULL && temp->row == i && temp->col == j){
                printf("%d\t", temp->data );
                temp = temp->next;
            }
            else{
                printf("0\t");
            }

        }
        printf("\n");
    }
}


int main()
{
    NODE start = NULL;
    int m, n, i, j, item, temp, row, col;
    printf("\nEnter the order of Sparse Matrix\n");
    scanf("%d%d", &m,&n);
    // printf("\nRead Matrix\n");
    printf("\nEnter the number of non-zero entries:");
    scanf("%d", &temp);
    printf("\nNOTE: Please take first index as 1\n");
    for(i=1; i<=temp; i++){
        printf("\nEnter the row number of [%d] element: ", i);
        scanf("%d", &row);
        printf("\nEnter the col number of [%d] element: ", i);
        scanf("%d", &col);
        printf("\nEnter the [%d] element:", i);
        scanf("%d", &item);
        start = insertend(start, row, col, item);
    }
    // for(i=1; i<=m; i++){
    //     for(j=1; j<=n; j++){
    //         scanf("%d", &item);
    //         if(item != 0){
    //             start = insertend(start, i, j, item);
    //         }
    //     }
    // }
    printf("The linked list is:\n");
    dispalay(start);
    displaymatrix(start, m, n);
    return 0;
}
