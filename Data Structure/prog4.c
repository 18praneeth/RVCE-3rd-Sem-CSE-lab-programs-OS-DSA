// Polynomial multiplication using singly linked list
// Assumption
// 1. Polynomial has single variable
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int co, po;
    struct node *addr ;
};

typedef struct node *NODE ;


NODE insertnd(NODE start, int co, int po){
    NODE temp, current;
    temp = (NODE)malloc(sizeof(struct node));
    temp->co = co;
    temp->po = po;
    temp->addr = NULL;

    // Adding element for first time
    if (start == NULL)
        return temp;

    current = start;
    while (current->addr != NULL){
        current = current ->addr ;
    }
    current->addr = temp;
    return start;
}


void display(NODE start){
    NODE temp;
    if (start == NULL)
        printf("Polynomial is empty\n");
    else{
        temp = start;
        while(temp->addr != NULL){
            printf("%dx^%d + ", temp->co, temp->po);
            temp = temp->addr;
        }
        printf("%dx^%d", temp->co, temp->po );
    }
}

NODE addpoly(NODE res, int co, int po){
    NODE  temp, current;
    int flag = 0;
    temp = (NODE)malloc(sizeof(struct node));
    temp->co = co;
    temp->po = po;
    temp->addr = NULL;
    if (res == NULL)
        return temp;
    current = res;
    while(current!=NULL){
        if(current->po == po){
            current->co = current->co + co ;
            flag = 1;
        }
        current = current->addr;
    }
    if(flag == 0)    {
       current = res;
       while(current->addr!=NULL)
             current = current->addr;
      current->addr = temp;
    }
    return res;

}

NODE multiplypoly(NODE poly1, NODE poly2){
    NODE first, second, res = NULL;
    for (first=poly1; first!=NULL; first=first->addr){
        for(second=poly2; second!=NULL; second=second->addr){
            res = addpoly(res, first->co*second->co, first->po+second->po);
        }
    }
    return res;
}



int main()
{
    NODE poly1 = NULL, poly2 = NULL, res;
    int i, n, co, po;
    printf("\nRead no of terms of first Polynomial\n");
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        printf("Read co & po of %d term\n",i );
        scanf("%d%d", &co, &po);
        poly1 = insertnd(poly1, co, po);
    }
    printf("The first Polynomial is\n");
    display(poly1);

    printf("\nRead no of terms of second Polynomial:\n");
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        printf("Enter co & po of %d term\n", i );
        scanf("%d%d", &co, &po);
        poly2 = insertnd(poly2, co, po);
    }
    printf("The second Polynomial is:\n");
    display(poly2);

    // result
    res = multiplypoly(poly1, poly2);
    printf("\nThe resultant Polynomial is\n");
    display(res);
    return 0;
}
