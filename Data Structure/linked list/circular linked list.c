#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *next;
};

struct node *head;

struct node *createnode(int ele){
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->info = ele;
    p->next =  p;
    return p;
}

void display(){
    if(head == NULL)
        printf("empty list");
    else{
        struct node *q;
        q = head;
        while(q->next != head){
            printf("%d  ", q->info);
            q = q->next;
        }
        printf("%d", q->info);
    printf("\n");
    }
}

void insertfront(int ele){
    struct node *p, *q;
    p = createnode(ele);

    if (head == NULL)
        head = p;
    else {
        q = head;
        p->next = head;
        while(q->next != head)
            q = q->next;
        q->next = p;
        head = p;
    }
    display();
}

void deletefront(){
    if(head == NULL)
        printf("underflow");
    else if(head->next == head){
        free(head);
        head = NULL;
        display();
    }
    else{
        struct node *q, *p;
        q = head;
        head = head->next;
        p =  head;
        while(p->next != q)
            p = p->next;
        p->next = head;
        free(q);
        display();
    }
}

void insertend(int ele){
    struct node *p;
    p = createnode(ele);
    if(head == NULL)
        head = p;
    else{
        struct node *q;
        q = head;

        while(q->next != head)
            q = q->next;
        q->next = p;
        p->next = head;
    }
    display();
}

void deleteend(){
    if(head == NULL)
        printf("underflow");
    else if(head->next == head){
        free(head);
        head = NULL;
        display();
    }
    else{
        struct node *q, *p;
        q = head;
        while((q->next)->next != head)
            q = q->next;
        p = q->next;
        q->next = head;
        free(p);
        display();
    }
}

int main(){
    int ch, ele;
    head = NULL;

    while(1){
        printf("\n1.insertfront 2.display 3.deletefront 4.insertend 5.deleteend\n");
        scanf("%d", &ch);

        switch(ch){
            case 1: printf("enter elen: ");
                    scanf("%d", &ele);
                    insertfront(ele);
                    break;
            case 2: display();
                    break;
            case 3: deletefront();
                    break;
            case 4: printf("enter elen: ");
                    scanf("%d", &ele);
                    insertend(ele);
                    break;
            case 5: deleteend();
                    break;
            default: return 0;
        }
    }
    return 0;
}

