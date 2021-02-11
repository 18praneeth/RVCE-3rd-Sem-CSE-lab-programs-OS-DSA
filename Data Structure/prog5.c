#include <stdio.h>
#include <malloc.h>

struct Node
{
    int digit;
    struct Node *address;
};

typedef struct Node *NODE;

NODE insertBegin(NODE head, int item)
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct Node));
    temp->digit = item;
    if (head->address == NULL)
    {
        temp->address = head;
        head->address = temp;
        return head;
    }
    temp->address = head->address;
    head->address = temp;
    return head;
}

NODE insertEnd(NODE head, int item)
{
    NODE temp, cur;
    temp = (NODE)malloc(sizeof(struct Node));
    temp->digit = item;
    if (head->address == NULL)
    {
        temp->address = head;
        head->address = temp;
        return head;
    }
    cur = head->address;
    while (cur->address != head)
    {
        cur = cur->address;
    }
    cur->address = temp;
    temp->address = head;
    return head;
}

void Display(NODE head)
{
    NODE temp;
    if (head->address == head)
    {
        printf("List is Empty\n");
    }
    else
    {
        temp = head->address;
        while (temp != head)
        {
            printf("%d", temp->digit);
            temp = temp->address;
        }
        printf("\n");
    }
}

void addZero(NODE head1, NODE head2)
{
    int ct1 = 1, ct2 = 1, i;
    NODE t1, t2;
    t1 = head1->address;
    while (t1 != head1)
    {
        ct1 = ct1 + 1;
        t1 = t1->address;
    }
    t2 = head2->address;
    while (t2 != head2)
    {
        ct2 = ct2 + 1;
        t2 = t2->address;
    }
    if (ct1 > ct2)
    {
        for (int i = 1; i <= ct1 - ct2; i++)
        {
            head2 = insertBegin(head2, 0);
        }
    }
    else
    {
        for (int i = 1; i <= ct2 - ct1; i++)
        {
            head1 = insertBegin(head1, 0);
        }
    }
}

NODE Reverse(NODE head)
{
    NODE cur, prev, next;
    cur = head->address;
    prev = head;
    while (cur != head)
    {
        next = cur->address;
        cur->address = prev;
        prev = cur;
        cur = next;
    }
    head->address = prev;
    return head;
}

void Add(NODE head1, NODE head2)
{
    NODE head, t1, t2;
    int sum = 0, carry = 0, x;
    head = (NODE)malloc(sizeof(struct Node));
    head->address = head;
    head1 = Reverse(head1);
    head2 = Reverse(head2);
    t1 = head1->address;
    t2 = head2->address;
    while (t1 != head1 && t2 != head2)
    {
        x = t1->digit + t2->digit + carry;
        sum = x % 10;
        carry = x / 10;
        head = insertBegin(head, sum);
        t1 = t1->address;
        t2 = t2->address;
    }
    if (carry > 0)
    {
        head = insertBegin(head, carry);
    }
    printf("Final Added Number is : ");
    Display(head);
}

int main()
{
    char first[20], second[20];
    NODE head1, head2;
    head1 = (NODE)malloc(sizeof(struct Node));
    head2 = (NODE)malloc(sizeof(struct Node));
    head1->address = head1;
    head2->address = head2;
    printf("Enter First Number : ");
    scanf("%s", &first);
    for (int i = 0; first[i] != '\0'; i++)
    {
        head1 = insertEnd(head1, first[i] - '0');
    }
    printf("Enter Second Number : ");
    scanf("%s", &second);
    for (int i = 0; second[i] != '\0'; i++)
    {
        head2 = insertEnd(head2, second[i] - '0');
    }
    addZero(head1, head2);
    printf("First Number : ");
    Display(head1);
    printf("Second Number : ");
    Display(head2);
    Add(head1, head2);
    return 0;
}
