#include<stdio.h>
#include<stdlib.h>

#define STACKSIZE  50

struct stack
 {
     int items[STACKSIZE];
     int top ;
};

typedef struct stack STACK;

void push(STACK *s, int x)
{
     if(s->top == (STACKSIZE-1))
     {
        printf("Stack Overflow\n");
        exit(0);
     }
     s->items[++ s->top] = x;
}


int pop(struct stack *s)
{
     int x;
     if(s->top == -1)
     {
             printf("Stack Underflow!\n");
             exit(0);
     }
    return (s->items[s->top--]);
}


int stackTop(STACK *s)
{
     return (s->items[s->top]);
}

void display(STACK s){
    if(s.top == -1){
        printf("Stack is empty!!\n");
        return;
    }
    printf("\nStack Contents are: ");
    for(int i=0; i<=s.top; i++)
        printf("%d, "s.items[i]);
}


int main(){
    int i, flag, choice, data, pop;
    STACK st, tempst;
    st.top = -1;
    st.tempst = -1;

    while (1)
    {
     printf("\n\n\n1:PUSH\n2:POP\n3:Display\n4:Third Element from Top\n5:Pop n Elements\n6:Third Element from bottom\n7:exit\n");
     printf("\nEnter the Choice :");
     scanf("%d", &choice);
     
     switch(choice){
         case 1:
                printf("Enter the element to be pushed");
                scanf("%d", &data);
                push(&st, data);
                break;
         case 2:
                printf("Element Popped: %d", pop(&st));
                break;
         case 3:
                display(st);
                break;
         case 4:
                if(st.top >= 2){
                    int x1, x2;
                    x1 = pop(&st);
                    x2 = pop(&st);
                    printf("Third element from top is %d\n", stackTop(&st));
                    push(&st, x2);
                    push(&st, x1);
                }
                else
                    printf("Stack has less than 3 elements\n");
                break;
         case 5:
                printf("Enter the number of elements to be popped: ");
                scanf("%d", &pop);

                if(pop <= (s.top + 1)){
                    printf("Popped elements are: ");
                    for(i=0; i<= pop; i++){
                        printf("%d\t", pop(&st));
                    }
                }
                else{
                    printf("Not enough elements to be popped");
                }
                break;

     }


    }
    
    return 0;
}