#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* createNode(int data) {
    struct node* n = malloc(sizeof(struct node));
    if (n == NULL) exit(1);

    n->data = data;
    n->left = n->right = NULL;
    return n;
}

int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }

    return -1;
}

struct node* buildTree(int preorder[], int inorder[],
                       int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd)
        return NULL;

    int value = preorder[*preIndex];
    (*preIndex)++;

    struct node* root = createNode(value);

    if (inStart == inEnd)
        return root;

    int position = search(inorder, inStart, inEnd, value);

    root->left = buildTree(preorder, inorder,
                           inStart, position - 1, preIndex);

    root->right = buildTree(preorder, inorder,
                            position + 1, inEnd, preIndex);

    return root;
}

void postorder(struct node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int preorder[] = {1, 2, 4, 5, 3};
    int inorder[] = {4, 2, 5, 1, 3};
    int preIndex = 0;
    int n = 5;

    struct node* root = buildTree(preorder, inorder,
                                  0, n - 1, &preIndex);

    printf("Postorder: ");
    postorder(root);

    printf("\n");
    return 0;
}