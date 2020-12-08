// Binary order transversal
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

// Iterative function to perform preorder traversal

void preorder_iter(NODE root){
    NODE cur, s[10];
    int top = -1;
    if(root != NULL){
        printf("No Traversal\n");
        return;
    }
    cur = root;
    while(1){
        while(cur != NULL){
            printf("%d\t", cur->data );
            s[++ top] = cur;
            cur = cur->left
        }
        if(top != -1){
            cur = s[top--];
            cur = cur->right;
        }
        else{
            return;
        }
    }
}

// Iterative function to perform inorder traversal

void inorder_iter(NODE root){
    NODE cur, s[10];
    int top = -1;
    if(root != NULL){
        printf("No Traversal\n");
        return;
    }
    cur = root;
    while(1){
        while(cur != NULL){
            s[++ top] = cur;
            cur = cur->left
        }
        if(top != -1){
            cur = s[top--];
            printf("%d\t", cur->data );
            cur = cur->right;
        }
        else{
            return;
        }
    }
}


// Iterative function to perform postorder traversal

void postorder_iter(NODE root){
    NODE cur, s[10];
    int top = -1;
    if(root != NULL){
        printf("No Traversal\n");
        return;
    }
    cur = root;
    while(1){
        while(cur != NULL){
            s[++ top] = cur;
            cur = cur->left
        }
        if(top != -1){
            cur = s[top--];
            cur = cur->right;
        }
        else{
            printf("%d\t", cur->data );
        }
    }
}
