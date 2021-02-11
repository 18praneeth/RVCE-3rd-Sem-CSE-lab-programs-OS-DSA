#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define STACKSIZE  100

struct stack
 {
     char items[STACKSIZE]   ;
     int top ;
};

typedef struct stack STACK;

void push(STACK *s, char x)
{
     if(s->top == (STACKSIZE-1))
     {
             printf("Stack Overflow\n");
             exit(0);
     }
    s->items[++s->top] = x;
}

char pop(STACK *s)
{
     if(s->top == -1)
     {
             printf("Stack Underflow!\n");
             exit(0);
     }
    return s->items[s->top--];
}


char stackTop(STACK *s)
{
     if(s->top == -1)
     {
           printf("Underflow");
           exit(0);
     }
     return (s->items[s->top]);
}

void display(STACK *s)
{
  for(int i=0; i<=s->top; i++){
    printf("%d\n", s->items[i]);
  }
}

int preced(char symbol){
  switch(symbol){
    case '^': return 5;
    case '*':
    case '/': return 3;
    case '+':
    case '-': return 1;
  }
}


void infix_to_postfix(char infix[30], STACK *s)
{
  char postfix[30], symbol, temp;
  int i, j;
  j = 0;

  for(i=0; infix[i]!='\0';i++)
  {
    symbol = infix[i];
    if(isalnum(symbol))
    {
      postfix[j++] = symbol;
    }
    else
    {
      switch(symbol)
      {
        case '(':
                push(s, symbol);
                break;
                // display(s);
        case ')':
                temp = pop(s);
                while(temp!='('){
                  postfix[j++] = temp;
                  temp = pop(s);
                }
                break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
                if(s->top == -1 || s->items[s->top] == '('){
                  push(s, symbol);
                  // display(s);
                  break;
                }
                else{
                  while(preced(s->items[s->top]) >= preced(symbol) && s->top != -1 && s->items[s->top] != '(')
                  {
                    postfix[j++] = pop(s);
                  }
                  push(s, symbol);
                  break;
                  // display(s);
                }
      }
    }
  }
  while(s->top != -1){
    postfix[j++] = pop(s);
  }
  postfix[j] = '\0';
  printf("Postfix expression is: %s\n", postfix);
}


int main()
{
  char infix[20];
  STACK s;
  s.top = -1;
  printf("Enter infix expression\n");
  scanf("%s", infix);
  infix_to_postfix(infix, &s);

  return 0;
}
