#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int key) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node *node) {
    if (node == NULL)
        return 0;
    return 1 + max(height(node->left), height(node->right));
}

int isAVL(struct Node *root) {
    if (root == NULL)
        return 1;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (abs(leftHeight - rightHeight) <= 1 && isAVL(root->left) && isAVL(root->right))
        return 1;

    return 0;
}

int main() {
    struct Node *root = NULL;
    int n, key;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the keys for each node:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &key);
        root = insert(root, key);
    }

    if (isAVL(root))
        printf("The BST is an AVL tree.\n");
    else
        printf("The BST is not an AVL tree.\n");

    // Clean up: free allocated memory
    // Implement your own tree deallocation logic based on your tree structure
    // ...

    return 0;
}
