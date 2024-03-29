#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
struct Tree {
    int val;
    int count;
    struct Tree* left;
    struct Tree* right;
};

struct Tree* new_node(int val)
{
    struct Tree* x = (struct Tree*) malloc(sizeof(struct Tree));
    x->val = val;
    x->left = NULL;
    x->right = NULL;
    return x;
};

struct Tree* insert(struct Tree* root, int val)
{
    if(root == NULL) {
        return new_node(val);
    }
    else {
         if (val == root->val) {
       		(root->count)++;
   	 }
        else if(root->val > val) {
            root->left=insert(root->left,val);
        }
        else
            root->right=insert(root->right,val);
    }
    return root;
}

int totalNodes(struct Tree* tree)
{
    if (tree == NULL)
        return 0;
    else
        return (totalNodes(tree->left) + totalNodes(tree->right) + 1);
}
//todo External Nodes (recursion)--9
int totalExternalNodes(struct Tree* tree)
{
    if (tree == NULL)
        return 0;
    else if ((tree->left == NULL) && (tree->right == NULL))
        return 1;
    else
        return (totalExternalNodes(tree->left) + totalExternalNodes(tree->right));
}
//todo Internal Nodes (recursion)--10
int totalInternalNodes(struct Tree* tree)
{
    if ((tree == NULL) || ((tree->left == NULL) && (tree->right == NULL)))
        return 0;
    else {
        return (totalInternalNodes(tree->left) + totalInternalNodes(tree->right) + 1);
        }
}

//function to find the minimum value in a node
struct Tree* find_minimum(struct Tree* root) {
  if (root == NULL)
    return NULL;
  else if (root -> left != NULL) // node with minimum value will have no left child
    return find_minimum(root -> left); // left most element will be minimum
  return root;
}

// Function to insert values level-wise into the binary tree
struct Tree* insertLevelOrder(int arr[], struct Tree* root, int i, int n) {
    if (i < n) {
        root = new_node(arr[i]);

        // Insert left child
        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);

        // Insert right child
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

char search(struct Tree* root, int val)
{
    if(root == NULL) {
        return 'n';
    }
    else {
        if(root->val == val) {
            return 'y';
        }
        else if(root->val > val) {
            return search(root->left,val);
        }
        else {
            return search(root->right,val);
        }
    }
}

void preorder(struct Tree* root)
{
    if(root == NULL)
    return;
    printf("%d_",root->val);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Tree* root)
{
    if(root == NULL)
    return;
    inorder(root->left);
    printf("%d_",root->val);
    inorder(root->right);
}

 void postorder(struct Tree* root)
 {
    if(root == NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    printf("%d_",root->val);
}

void root_to_leaf(struct Tree* root,int path[],int pathLen)
{
    if(root == NULL)
        return;
    path[pathLen] = root->val;
    pathLen++;
    if(root->left == NULL && root->right==NULL) {
        for(int i=0;i<pathLen;i++) {
            printf("%d ",path[i]);
        }
        printf("\n");
    }
    else {
    root_to_leaf(root->left,path,pathLen);
    root_to_leaf(root->right,path,pathLen);
    }
}

void no_of_leaves(struct Tree* root , int *c,int *sum)
{
    if(root == NULL)
        return;
    if(root->left == NULL && root->right == NULL) {
        (*c)++;
        *sum=*sum+root->val;
    }
    else{
        no_of_leaves(root->left,c,sum);
        no_of_leaves(root->right,c,sum);
    }
}

int same_tree(struct Tree* root,struct Tree* root1)
{
    if(!root || !root1) {
        return root==root1;
    }
    return ((root->val == root1->val) && same_tree(root->left,root1->left) && same_tree(root->right,root1->right));
}

struct Tree* make_tree(int n,int inorder[n],int postorder[n],int map[],int inStart,int inEnd,int postStart,int postEnd)
{
    if(inStart>inEnd || postStart>postEnd) {
        return NULL;
    }
    int val=postorder[postEnd];
    struct Tree* root = new_node(val);
    int rootIdx = map[val];
    int leftSubtreeSize = rootIdx-inStart;
    int rightSubtreeSize = inEnd-rootIdx;
    root->left = make_tree(n,inorder,postorder,map,inStart,rootIdx-1,postStart,postStart+leftSubtreeSize-1);
    root->right= make_tree(n,inorder,postorder,map,rootIdx+1,inEnd,postStart+leftSubtreeSize,postEnd-1);
    return root;
}

struct Tree* make_full_binary_tree(int n,int preorder[n],int postorder[n],int map[],int preStart,int preEnd,int postStart,int postEnd)
{
    if(preStart>preEnd || postStart>postEnd) {
        return NULL;
    }
    int val = preorder[preStart];
    struct Tree* root = new_node(val);
    if(preStart == preEnd) {
        return root;
    }
    int t = preorder[preStart+1];
    int idx = map[t];
    int leftSubtreeSize = idx-postStart+1;
    root->left = make_full_binary_tree(n,preorder,postorder,map,preStart+1,preStart+leftSubtreeSize,postStart,postStart+leftSubtreeSize-1);
    root->right = make_full_binary_tree(n,preorder,postorder,map,preStart+leftSubtreeSize+1,preEnd,postStart+leftSubtreeSize,postEnd-1);
    return root;
}

void delete_bst(struct Tree* root)
{
    if(root == NULL)
        return;
    delete_bst(root->left);
    delete_bst(root->right);
    printf("%d ",root->val);
    free(root);
}

struct Tree* mirror_image(struct Tree* root)
{
    if (root == NULL) {
        return NULL;
    }
    struct Tree* root1 = new_node(root->val);
    root1->left = mirror_image(root->right);
    root1->right = mirror_image(root->left);

    return root1;
}

void distance_k(struct Tree* root,int k,int c)
{
    if(root == NULL) {
        return;
    }
    if(c == k) {
        printf("%d ",root->val);
        return;
    }
    distance_k(root->left,k,c+1);
    distance_k(root->right,k,c+1);
}

void inorder_p_s(struct Tree* root,int inorder[],int *k)
{
    if(root == NULL) {
        return;
    }
    inorder_p_s(root->left,inorder,k);
    inorder[(*k)++]=root->val;
    inorder_p_s(root->right,inorder,k);
}

void ancestors(struct Tree* root,int val)
{
    if(root==NULL) {
        return;
    }
    if(root->val == val) {
        return;
    }
    printf("%d ",root->val);
    if(val<root->val) {
    ancestors(root->left,val);
    }
    else {
    ancestors(root->right,val);
    }
}

struct Tree* delete_terminal(struct Tree* root)
{
    if(root == NULL) {
        return NULL;
    }
     if(!root->left && !root->right) {
        free(root);
        return NULL;
    }
    root->left=delete_terminal(root->left);
    root->right=delete_terminal(root->right);
    return root;
}

void sum(struct Tree* root,int *s)
{
    if(root == NULL) {
        return;
    }
    *s=*s+root->val;
    sum(root->left,s);
    sum(root->right,s);
}

int sum_tree(struct Tree* root)
{
    if(root == NULL)
        return 1;
    int s=0;
    sum(root->right,&s);
    sum(root->left,&s);
    if(s==root->val)
        return 1;
    return 0;
}

struct Tree* LCA(struct Tree* root, int n1, int n2)
{
    // Your code here
    if (root == NULL)
        return root;
    if (root->val == n1 || root->val == n2)
        return root;

    struct Tree* left = LCA(root->left, n1, n2);
    struct Tree* right = LCA(root->right, n1, n2);

    if (left != NULL && right != NULL)
        return root;
    if (left == NULL && right == NULL)
        return NULL;
    if (left != NULL)
        return LCA(root->left, n1, n2);

    return LCA(root->right, n1, n2);
}

// Returns level of key k if it is present in
// tree, otherwise returns -1
int findLevel(struct Tree* root, int k, int level)
{
    if (root == NULL)
        return -1;
    if (root->val == k)
        return level;

    int left = findLevel(root->left, k, level + 1);
    if (left == -1)
        return findLevel(root->right, k, level + 1);
    return left;
}

int findDistance(struct Tree* root, int a, int b)
{
    // Your code here
    struct Tree* lca = LCA(root, a, b);

    int d1 = findLevel(lca, a, 0);
    int d2 = findLevel(lca, b, 0);

    return d1 + d2;
}

// Helper function to find the height
// of a given node in the binary tree
int findHeightUtil(struct Tree* root, int x,
                   int *height)
{
    // Base Case
    if (root == NULL) {
        return -1;
    }

    // Store the maximum height of
    // the left and right subtree
    int leftHeight = findHeightUtil(
        root->left, x, height);

    int rightHeight
        = findHeightUtil(
            root->right, x, height);
    int ans;
    // Update height of the current node
    if(leftHeight>rightHeight)
        ans = leftHeight + 1;
    else
        ans = rightHeight + 1;

    // If current node is the required node
    if (root->val == x)
        *height = ans;

    return ans;
}

// Function to find the height of
// a given node in a Binary Tree
int findHeight(struct Tree* root, int x)
{
    // Store the height of
    // the given node
    int h = -1;

    // Stores height of the Tree
    int maxHeight = findHeightUtil(root, x, &h);

    // Return the height
    return h;
}

void inorder_1(struct Tree* root,int depth)
{
    if(root == NULL) {
        return;
    }
    inorder_1(root->left,depth+1);
    printf("%d",root->val);
    printf(" Height: %d",findHeight(root,root->val));
    printf(" Depth: %d\n",depth);
    inorder_1(root->right,depth + 1);
}

// Function to perform in-order traversal, print unique values, and delete duplicates
struct Tree* removeDuplicates(struct Tree* root, int* prevValue) {
    if (root == NULL) {
        return NULL;
    }

    // Recursively process left subtree
    root->left = removeDuplicates(root->left, prevValue);

    // Check if the current node has the same value as the previous node
    if (*prevValue == root->val) {
        // Delete the duplicate node
        free(root);
        return NULL;
    }

    // Print the unique value
    printf("%d ", root->val);

    // Update the previous value to the current node's value
    *prevValue = root->val;

    // Recursively process right subtree
    root->right = removeDuplicates(root->right, prevValue);

    return root;
}

// Print nodes at a current level
void printCurrentLevel(struct Tree* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->val);
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

// Compute the "height" of a tree -- the number of
// nodes along the longest path from the root node
// down to the farthest leaf node
int height(struct Tree* node)
{
    if (node == NULL)
        return 0;
    else {

        // Compute the height of each subtree
        int lheight = height(node->left);
        int rheight = height(node->right);

        // Use the larger one
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

// Function to print level order traversal a tree
void printLevelOrder(struct Tree* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}

// Function to perform post-order traversal and truncate nodes
struct Tree* pruneNodes(struct Tree* root, int k, int *sum) {
    if (root == NULL)
        return NULL;

    // Post-order traversal
    root->left = pruneNodes(root->left, k, sum);
    root->right = pruneNodes(root->right, k, sum);

    // Update the sum of the current path
    *sum = (*sum)+ root->val;

    // If the sum of the current path is less than k, prune the subtree
    if (*sum < k) {
        free(root);
        return NULL;
    }

    return root;
}

//function to delete the duplicate element
struct Tree* Delete(struct Tree* root,int value)
{

	if(root==NULL)
		return root;
	else if(value< root->val)
	{
		root->left= Delete(root->left,value);
	}
	else if(value> root->val)
	{
		root->right= Delete(root->right,value);
	}


	return root;

}
//function to display all the element present in the binary search tree and call Delete()
void display(struct Tree* root)
{
    if (root != NULL)
    {
        display(root->left);
        if(root->count>1)
       {
           Delete(root,root->val);
       }
       else
        printf("%d ",root->val);
        display(root->right);

    }
}

int check_bst(struct Tree* root,int min,int max)
{
	if(root == NULL) {
		return 1;
	}
	if(root->val < min || root->val > max) {
        return 0;
	}
	return check_bst(root->left,min,(root->val)-1) && check_bst(root->right,(root->val)+1,max);
}

// Function to delete a node in the BST
struct Tree* deleteNode(struct Tree* root, int key) {
    if (root == NULL) {
        return root;
    }

    // Traverse the tree to find the node to be deleted
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Tree* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Tree* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct Tree* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }

        // Copy the inorder successor's data to this node
        root->val = temp->val;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

int main()
{
    int n;
    scanf("%d",&n);
    struct Tree* root = NULL;
    int val;
    /*int inorder[n];*/
    /*int postorder[n];
    int preorder[n];*/
    /*for(int i=0;i<n;i++) {
        scanf("%d",&val);
        inorder[i]=val;
    }*/
    /*for(int i=0;i<n;i++) {
        scanf("%d",&val);
        preorder[i]=val;
    }
    for(int i=0;i<n;i++) {
        scanf("%d",&val);
        postorder[i]=val;
    }
    int map[1000];
    for(int i=0;i<n;i++) {
        map[postorder[i]]=i;
    }
    root = make_full_binary_tree(n,preorder,postorder,map,0,n-1,0,n-1);
    inorder(root);*/

    /*int map[1000];
    for(int i=0;i<n;i++) {
        map[inorder[i]]=i;
    }
    root = make_tree(n,inorder,postorder,map,0,n-1,0,n-1);
    preorder(root);*/
    for(int i=0;i<n;i++) {
        scanf("%d",&val);
        root = insert(root,val);
    }
    printf("Total Nodes: %d ",totalNodes(root));
    printf("Total Internal Nodes: %d ",totalInternalNodes(root));
    printf("Total External Nodes: %d ",totalExternalNodes(root));
    /*deleteNode(root,5);
    inorder(root);*/
    /*int values[n];
    for(int i=0;i<n;i++) {
        scanf("%d",&val);
        values[i]=val;
    }
    root = insertLevelOrder(values, root, 0, n);*/
    /*int sum = 0;
    int k;
    scanf("%d",&k);
    root = pruneNodes(root, k, &sum);*/
    /*inorder(root);*/
    /*display(root);
    printf("\n");*/
    /*preorder(root);
    printf("\n");
    if(check_bst(root,INT_MIN,INT_MAX)) {
    	printf("BST \n");
    } else {
    	printf("Not a BST \n");
    }*/
    /*printLevelOrder(root);*/
    /*inorder_1(root,0);*/
    /*int key1,key2;
    scanf("%d",&key1);
    scanf("%d",&key2);
    printf("%d",findDistance(root,key1,key2));*/
    /*if(sum_tree(root)) {
        printf("1");
    }
    else {
        printf("0");
    }*/
    /*struct Tree* root1 = delete_terminal(root);
    preorder(root1);*/
    /*int node;
    scanf("%d",&node);
    ancestors(root,node);*/
    /*int k=0;
    int inorder[n];
    inorder_p_s(root,inorder,&k);
    for(int i=0;i<n;i++){
      if(inorder[i]==node) {
            if(i>0) {
                printf("Predecessor is: %d\n",inorder[i-1]);
            }
            if(i<n-1) {
                printf("Successor is: %d\n",inorder[i+1]);
            }
            break;
        }
    }*/
    /*delete_bst(root);*/
    /*struct Tree* root1 = mirror_image(root);
    preorder(root1);*/
    /*int k;
    scanf("%d",&k);
    int c=0;
    distance_k(root,k,c);*/
    /*char y[k];
    for(int i=0;i<k;i++) {
        scanf("%d",&val);
        y[i]=search(root,val);
    }
    for(int i=0;i<k;i++) {
        printf(" %c\n",y[i]);
    }
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);*/
    /*struct Tree* root1=NULL;
    for(int i=0;i<n;i++) {
        scanf("%d",&val);
        root=insert(root,val);
    }
     for(int i=0;i<n;i++) {
        scanf("%d",&val);
        root1=insert(root1,val);
    }
    if(same_tree(root,root1))
        printf("y");
    else
        printf("n");
    int path[n];
    int pathLen=0;
    root_to_leaf(root,path,pathLen);
    int c=0,sum=0;
    no_of_leaves(root,&c,&sum);
    printf("%d\n",c);
    printf("%d\n",sum);*/
    return 0;
}
