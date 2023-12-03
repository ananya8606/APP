#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify the array
void heapify(int arr[], int n, int i) {
    int smallest = i;  // Initialize smallest as root
    int left = 2 * i + 1;  // left child
    int right = 2 * i + 2; // right child

    // If left child is smaller than root
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    // If right child is smaller than smallest so far
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    // If smallest is not root
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        // Recursively heapify the affected sub-tree
        heapify(arr, n, smallest);
    }
}

// Function to create a min heap
void buildHeap(int arr[], int n) {
    // Index of last non-leaf node
    int startIdx = (n / 2) - 1;

    // Perform reverse level order traversal from the last non-leaf node and heapify each node
    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Function to display the heap
void displayHeap(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform k deletions and display the heap
void deleteRootKTimes(int arr[], int n, int k) {
    // Display the original heap
    printf("Heap before deletions: ");
    displayHeap(arr, n);

    // Delete the root k times
    for (int i = 0; i < k; i++) {
        // Swap the root with the last element
        swap(&arr[0], &arr[n - 1 - i]);

        // Heapify the reduced heap
        heapify(arr, n - i - 1, 0);

        // Display the heap after each deletion
        printf("Heap after deletion %d: ", i + 1);
        displayHeap(arr, n - i - 1);
    }
}

int main() {
    int T, n, k;
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        scanf("%d", &n);
        scanf("%d", &k);

        int *arr = (int *)malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        // Create the min heap
        buildHeap(arr, n);

        // Display the heap before and after k deletions
        deleteRootKTimes(arr, n, k);

        free(arr);
    }

    return 0;
}
