#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *right;
    struct node *left;
};

typedef struct node *NODE;

NODE createBST(NODE root, int item)
{
    NODE temp, cur, prev;
    temp = (NODE)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;
    if(root == NULL)
    {
        return temp;
    }

    prev = NULL;
    cur = root;

    while(cur != NULL)
    {
        prev = cur;
        if(item < cur->data)
            cur = cur->left;
        else
            cur = cur->right;
    }
    if(prev->data > item)
        prev->left = temp;
    else
        prev->right = temp;
    return root;
}

NODE inorder_successor(NODE root){
    NODE cur = root;
    while(cur->left != NULL)
        cur = cur->left;
    return cur;
}

NODE deletenode(NODE root, int key)
{
    NODE temp;
    if(root == NULL)
        return root;
    if(key < root->data){
        root->left = deletenode(root->left, key);
    }
    else if(key > root->data){
        root->right = deletenode(root->right, key);
    }
    else{
        if(root->left == NULL){
            temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            temp = root->left;
            free(root);
            return temp;
        }
        temp = inorder_successor(root->right);
        root->data = temp->data;
        root->right = deletenode(root->right, temp->data);
    }
    return root;
}

// Pre Order (NLR)

void preorder(NODE root){
    if(root != NULL){
        printf("%d\n", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder (LNR)

void inorder(NODE root){
    if(root != NULL){
        inorder(root->left);
        printf("%d\n", root->data);
        inorder(root->right);
    }
}

// Postorder (LRN)

void postorder(NODE root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d\n", root->data);
    }
}


int main(int argc, char const *argv[])
{
    NODE root = NULL;
    int ch, item, key;
    for(;;){
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Preorder\n");
        printf("4. Inorder\n");
        printf("5. Postorder\n");
        printf("6. Exit\n");
        printf("\nRead choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: printf("Read element to be insterted\n");
                    scanf("%d", &item);
                    root = createBST(root, item);
                    break;
            case 2: printf("\nRead node to be deleted:\n");
                    scanf("%d", &key);
                    root = deletenode(root, key);
                    break;
            case 3: printf("Preodrer\n");
                    preorder(root);
                    break;
            case 4: printf("Inorder\n");
                    inorder(root);
                    break;
            case 5: printf("Post order\n");
                    postorder(root);
                    break;
            case 6: printf("Exit\n");
                    exit(0);
        }
    }
    return 0;
}
