#include<stdio.h>
#include<stdlib.h>
/********** STACK DEFINITION **************************************/
#define STACKSIZE  100


struct stack
 {
     char items[STACKSIZE]   ;
     int top ;
};

/********** DEFINITION OF PRIMITIVE OPERATIONS : push ,pop**************/
void push(struct stack *s, char x)
{
     if(s->top == (STACKSIZE-1))
     {
             printf("Stack Overflow\n");
             exit(0);
     }
    s->top ++;
    s->items[s->top] = x;
}
char pop(struct stack *s)
{
    char x;
     if(s->top == -1)
     {
             printf("Stack Underflow!\n");
             exit(0);
     }

    x= s->items[s->top];
    s->top --;
    return x;
}
/********DEFINITION OF  OPERATION:  StackTop**************/

char stackTop(struct stack *s)
{
     if(s->top == -1)
     {
           printf("Underflow");
           exit(0);
     }
     return (s->items[s->top]);
}



int isp(char op)
{

  switch(op)
  {
     case '+' : return 1;
     case '-' : return 1;
     case '*' : return 2;
     case '/' : return 2;
     case '$' : return 3;
     case '(' : return 0;   // least precedence
     default  : printf("\nError\n");
                exit(0);
  }
}
int icp(char op)
{

  switch(op)
  {
     case '+' : return 1;
     case '-' : return 1;
     case '*' : return 2;
     case '/' : return 2;
     case '$' : return 4;
     case '(' : return 3;  //
     default  : printf("\nError\n");
                exit(0);
  }
}
void infixToPostfix(char infix[],char postfix[])
{

  int i,j;   // i : index of infix , j: index of postfix , symb: is current i/p symbol

   char x,topsymb,symb;


  struct stack st;
  st.top =-1;

  i=0;
  j=0;

  while(infix[i] !='\0')  // while not end of input char
  {
        symb=infix[i++];

        if((symb >='A' && symb <='Z')  ||  (symb >='a' && symb <='z') ) //  for oprrand  , capital 'A'  and                                                                                               small 'z'
                postfix[j++]=symb;
        else if( symb == ')')
        {
             while(stackTop(&st) != '(')
             {
                    x=pop(&st);
                    postfix[j++]=x;
             }
             pop(&st);    // discard '('
        }
        else
        {
            while(st.top != -1)
            {
              topsymb=stackTop(&st);
              if(isp(topsymb) >= icp(symb))
              {
                 x=pop(&st);
                 postfix[j++]=x;
              }
              else
                 break;

            }
            push(&st,symb) ;  // alway push symb
        }
  }// end of input

  while(st.top !=-1)
  {
    x=pop(&st);
    postfix[j++]=x;
  }             // pop remaing operator from the stack and store in the output array

  postfix[j]='\0';  // place null char to indicate end of postfix array
}



int main()
{

   char infix[100],postfix[100];


     printf("\n Infix to Postfix Conversion ");


     printf("\nEnter the infix Expression :");
     scanf("%s",infix);
     infixToPostfix( infix, postfix);
     printf("\nPostfix Expression is %s\n",postfix);

    return 0;
}

