// PROGRAM 8
// Given a String representing a parentheses-free infix arithmetic expression, implement a program to place it in a tree in
// the infix form. Assume that a variable name is a single letter. Traverse the tree to produce an equivalent postfix and
// prefix expression string.

// Algorithem to construct binary tree from infix expression

// 1. Intialise two stacks namely tree stakcs& operator stacks
// 2. Scan the Infix expression from left to right
// 3. If the scanned symbol is
    // i) operand - construct a node, push the node into tree stacks
    // ii) if operator stack is empty
            //construct a node, push the node to the operator stack
         //else  // if operator stack is not empt, until the precedance fo top of operator stack is greator than or equal to the precedance of scanned symbol
              //pop an operator from operator stack and pop2 nodes from tree stack and attach them as rightand left child of the node popped from operator stack
               //push it back to tree stack
               //if condition is not trure create a node and push it operator stack

// 4. Untill operator stack is not empty pop a nodef from operators stack and pop 2 nodes from tree stack and attach them as right and left child
// 5. Finall tree will be on the tree stack


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


struct node
{
    char info;
    struct node *left;
    struct node *right;
};

typedef struct node *NODE;

struct stack
{
    int top;
    NODE data[10];
};

typedef struct stack STACK;

int preced(char item){
    switch(item){
        case '^': return 5;
        case '*':
        case '/': return 3;
        case '+':
        case '-': return 1;
    }
}


void preorder(NODE root){
    if(root != NULL){
        printf("%c\t", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(NODE root){
    if(root != NULL){
        inorder(root->left);
        printf("%c\t", root->info);
        inorder(root->right);
    }
}

void postorder(NODE root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%c\t", root->info);
    }
}


void push(STACK *s, NODE temp){
    s->data[++(s->top)] = temp;
}

NODE pop(STACK *s){
    return (s->data[(s->top)--]);
}

NODE createnode(char item){
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->info = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

NODE createExpTree(char expr[20]){
    STACK tree, operator;
    tree.top = -1;
    operator.top = -1;
    char symbol;
    int i;
    NODE temp, t, l, r;

    for (i=0; expr[i] != '\0'; i++)
    {
        symbol = expr[i];
        temp = createnode(symbol);
        if(isalnum(symbol))
            push(&tree, temp);
        else{
            if(operator.top == -1)
                push(&operator, temp);
            else{
                while(operator.top != -1 && preced((operator.data[operator.top])->info) >= preced(symbol))
                {
                    t = pop(&operator);
                    r = pop(&tree);
                    l = pop(&tree);
                    t->right = r;
                    t->left = l;
                    push(&tree, t);
                }
                push(&operator, temp);
            }
        }
    }

    while(operator.top != -1){
      t = pop(&operator);
      r = pop(&tree);
      l = pop(&tree);
      t->right = r;
      t->left = l;
      push(&tree, t);
    }

  return pop(&tree);
}




int main()
{
    NODE root = NULL;
    char expr[20];
    printf("Read expression\n");
    scanf("%s", &expr);
    root = createExpTree(expr);
    printf("\nInorder::");
    inorder(root);
    printf("\nPreorder:");
    preorder(root);
    printf("\nPostorder:");
    postorder(root);
    return 0;
}


