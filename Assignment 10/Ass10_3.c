#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int val;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *root, int x)
{
    if (root == NULL)
    {
        struct node *curr = (struct node *)malloc(sizeof(struct node));
        curr->val = x;
        curr->left = NULL;
        curr->right = NULL;
        return curr;
    }

    if (x <= root->val)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

struct node *ll(struct node *root)
{
    if (root->left == NULL)
    {
        printf("rotation cant be performed\n");
        return root;
    }
    struct node *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    return temp;
}

struct node *rr(struct node *root)
{
    if (root->right == NULL)
    {
        printf("rotation cant be performed\n");
        return root;
    }
    struct node *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    return temp;
}

struct node *search(int x, struct node *root, char rot[])
{
    if (!root)
        return root;
    if (root->val == x)
    {

        if (strcmp(rot, "left") == 0)
        {
            struct node *temp = rr(root);
            if (temp->left == root)
            {
                printf("Rotated Successfully\n");
            }
            return temp;
        }
        else
        {
            struct node *temp = ll(root);
            if (temp->right == root)
            {
                printf("Rotated Successfully\n");
            }
            return temp;
        }
    }
    else if (x < root->val)
        root->left = search(x, root->left, rot);
    else
        root->right = search(x, root->right, rot);

    return root;
}

void inorder(struct node *root)
{
    if (!root)
        return;

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}
int main()
{
    int n;
    scanf("%d", &n);
    struct node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }
    int key;
    char rot[20];
    printf("enter key astruct node the rotation to be performed to rotate: ");
    scanf("%d %s", &key, rot);
    root = search(key, root, rot);
    inorder(root);
    return 0;
}
