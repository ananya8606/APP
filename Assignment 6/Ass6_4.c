#include <stdio.h>
#include <stdlib.h>

#define nd struct node

nd
{
    int val;
    nd *left;
    nd *right;
};

// Function to count the nodes in the binary heap
int countnodes(nd *root)
{
    if (!root)
        return 0;

    return 1 + countnodes(root->left) + countnodes(root->right);
}

// Function to insert a node into the binary heap
nd *insert(nd *root, int x)
{
    if (root == NULL)
    {
        nd *curr = (nd *)malloc(sizeof(nd));
        curr->val = x;
        curr->left = NULL;
        curr->right = NULL;
        return curr;
    }

    int left = countnodes(root->left);
    int right = countnodes(root->right);

    // If left BT is not a complete binary tree, then insert in the left
    // else insert in the right or if left BT is a complete BT and nodes in left=right, insert in left
    if ((left & (left + 1)) != 0 || left == right)
    {
        root->left = insert(root->left, x);
    }
    else
    {
        root->right = insert(root->right, x);
    }

    // Assigning min value to root
    if (root->left || root->right)
    {
        if (root->left->val < root->val)
        {
            int temp = root->left->val;
            root->left->val = root->val;
            root->val = temp;
        }

        if (root->right && root->right->val < root->val)
        {
            int temp = root->right->val;
            root->right->val = root->val;
            root->val = temp;
        }
    }

    return root;
}

// Function to perform level order traversal of the binary heap
void levelOrderTraversal(nd *root)
{
    if (root == NULL)
        return;

    // Create a queue for level order traversal
    nd *queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear)
    {
        nd *tempNode = queue[front++];

        if (tempNode->left != NULL)
            queue[rear++] = tempNode->left;

        if (tempNode->right != NULL)
            queue[rear++] = tempNode->right;

        printf("%d ", tempNode->val);
    }
}

// Function to delete the rightmost leaf node from the binary heap
nd *delete(nd *root, int *x)
{
    if (root->left == NULL && root->right == NULL)
    {
        *x = root->val;
        return NULL;
    }

    int left = countnodes(root->left);
    int right = countnodes(root->right);

    // If right is not a complete binary tree, then delete from the right side
    // else delete from the left or if right is a complete binary tree and nodes in right=left, delete from right
    if ((right & (right + 1)) != 0 || left == right)
    {
        root->right = delete (root->right, x);
    }
    else
    {
        root->left = delete (root->left, x);
    }

    return root;
}

// Function to perform bottom-up heapify on the binary heap
void heapify(nd *root)
{
    if (root == NULL || root->left == NULL)
        return;

    // If root val is min then stop heapify
    if (root->val <= root->left->val && (root->right == NULL || root->val <= root->right->val))
        return;

    // Min value is assigned to root
    if (root->right)
    {
        if (root->left->val < root->right->val)
        {
            int temp = root->left->val;
            root->left->val = root->val;
            root->val = temp;
            heapify(root->left);
        }
        else
        {
            int temp = root->right->val;
            root->right->val = root->val;
            root->val = temp;
            heapify(root->right);
        }
    }
    else
    {
        int temp = root->left->val;
        root->left->val = root->val;
        root->val = temp;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    nd *root = NULL;
    int ch;

    while (1)
    {
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            // Insert
            {
                int x;
                scanf("%d", &x);
                root = insert(root, x);
                levelOrderTraversal(root);
                printf("\n");
            }
            break;

        case 2:
            // Delete min
            if (root == NULL)
            {
                printf("UNDERFLOW\n");
            }
            else
            {
                int x = 0;
                root = delete (root, &x); // Deleting rightmost leaf node and storing its value in x
                if (root == NULL)
                {
                    printf("EMPTY\n");
                }
                else
                {
                    root->val = x;  // Updating root value with leaf node's value
                    heapify(root);  // Performing heapify
                    levelOrderTraversal(root); // Printing the tree after deleting
                    printf("\n");
                }
            }
            break;

        case 3:
            // Check full
            printf("true\n");
            break;

        case 4:
            // Check empty
            if (root == NULL)
                printf("true\n");
            else
                printf("false\n");
            break;

        case 5:
            // Quit
            return 0;
        }
    }

    return 0;
}
