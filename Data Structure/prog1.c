#include<stdio.h>
#include<stdlib.h>


#define STACKSIZE  50


struct stack
 {
     int items[STACKSIZE]   ;
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
     if(s->top == -1)
     {
           printf("Underflow");
           exit(0);
     }
     return (s->items[s->top]);
}

void  display(STACK *s)
{
  int i;
  if(s->top == -1)
     {
           printf("Stack Empty!\n");
           return;
     }

     printf("Stack Elements are: ");

     for(i = 0; i <= s->top; i++)
     {
      printf("%d\t",s->items[i]);
     }
}


int main()
{

  int i, x, choice, flag, Y, x1 ,x2 ,n;

  STACK st, tempst;

  st.top = -1;
  tempst.top = -1;

  printf("Stack Basic operation using Array Implementation. \n\n");

  while(1)
  {

     printf("\n\n\n1:PUSH\n2:POP\n3:Display\n4:Third Element from Top\n5:Pop n Elements\n6:Third Element from bottom\n7:exit\n");
     printf("\nEnter the Choice :");
     scanf("%d", &choice);

     switch(choice)
     {
        case 1:printf("\nEnter the element to be pushed: ");
               scanf("%d",&x);
               push(&st,x);
               break;

        case 2:x = pop(&st);
               printf("\nPopped element is %d\n",x);
               break;

        case 3 :display(&st);
               break;

        case 4:if( st.top >= 2)
               {
                   x1 = pop(&st);
                   x2 = pop(&st);

                   Y = stackTop(&st);

                   push(&st,x2);
                   push(&st,x1);

                   printf("Third Element From Top %d.\n",Y);
               }

               else
               {
                  printf("Stack has less than  3 elements.\n");
               }
               break;

        case 5:printf("Enter the number of elements to be popped:");
               scanf("%d",&n);
               if( n <= (st.top+1))
               {
                     printf("\npopped elements are : ");
                     for(i =1;i<=n;i++)
                     {
                         x=pop(&st);
                         printf("%d\t",x);
                     }
               }

               else{
                printf("Number of elements in stack  is less than %d.\n",n);
               }
               break;


        case 6:if( st.top >= 2)
               {
                   n =  st.top - 2;
                   for(i =1;i<=n;i++)
                   {
                         x=pop(&st);
                         push(&tempst,x);

                   }
                   Y =stackTop(&st);
                   for(i =1;i<=n;i++)
                   {
                         x=pop(&tempst);
                         push(&st,x);

                   }

                   printf("\nThird Element From Bottom %d\n",Y);
               }

               else{
                   printf("\nStack has less then  3 elements\n");
               }
               break;

        case 7:exit(0);

     }

  }
    return 0;
}
