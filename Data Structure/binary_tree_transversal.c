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
