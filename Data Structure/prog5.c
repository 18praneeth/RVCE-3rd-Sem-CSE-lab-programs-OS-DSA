#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *addr;
};

typedef struct node *NODE;

void display(NODE head){
    NODE temp;
    if(head->addr == head){
        printf("List is empty!!");
        return;
    }
    temp = head->addr;
    while(temp != head){
        printf("%d", temp->data);
        temp = temp->addr;
    }
}

NODE insertbegin(NODE head, int item){
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->data = item;
    
    if(head->addr == head){
        head->addr = temp;
        temp->addr = head;
        return head;
    }
    temp->addr = head->addr;
    head->addr = temp;
    return head;
}

NODE insertend(NODE head, int item){
    NODE temp, cur;
    temp = (NODE)malloc(sizeof(struct node));
    temp->data = item;

    if(head->addr == head){
        head->addr = temp;
        temp->addr = head;
        return head;
    }
    cur = head->addr;
    while(cur->addr != head){
        cur = cur->addr;
    }
    cur->addr = temp;
    temp->addr = head;
    return head;
}

void addzero(NODE head1, NODE head2){
    int ct1, ct2;
    ct1 = head1->data;
    ct2 = head2->data;
    if(ct1 > ct2){
        for(int i=0; i<(ct1 - ct2); i++){
            head2 = insertend(head2, 0);
        }
    }
    if(ct1 < ct2){
        for(int i=0; i<(ct2 - ct1); i++){
            head1 = insertend(head1, 0);
        }       
    }
}

void add(NODE head1, NODE head2){
    NODE head, t1, t2;
    int sum = 0, carry = 0, x;
    head = (NODE)malloc(sizeof(struct node));
    head->addr = head;
    t1 = head1->addr;
    t2 = head2->addr;

    while(t1 != head1 && t2 != head2){
        x = t1->data + t2->data + carry;
        sum = x % 10;
        carry = x/10;
        head = insertbegin(head, sum);
        t1 = t1->addr;
        t2 = t2->addr;
    }

    if(carry > 0){
        head = insertbegin(head, carry);
    }
    printf("\nFinal sum is: ");
    display(head);
    printf("\n");
}

int main(){
    char first[20], second[20];
    NODE head1, head2;
    head1 = (NODE)malloc(sizeof(struct node));
    head2 = (NODE)malloc(sizeof(struct node));
    head1->addr = head1;
    head2->addr = head2;
    printf("Enter the first number: ");
    scanf("%s", &first);
    printf("\nThe first number is: ");
    for(int i=0; first[i]!= '\0'; i++){
        head1 = insertbegin(head1, first[i] - '0');
        printf("%d", first[i] - '0');
    }
    printf("\n");
    head1->data = strlen(first);
    printf("\nEnter the second number: ");
    scanf("%s", &second);
    printf("\nThe second number is: ");
    for(int i=0; second[i]!= '\0'; i++){
        head2 = insertbegin(head2, second[i] - '0');
        printf("%d", second[i] - '0');
    }
    printf("\n");
    head2->data = strlen(second);

    addzero(head1, head2);
    add(head1, head2);


    return 0;
}