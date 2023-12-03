#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify the array (max heap)
void heapify(int arr[], int n, int i) {
    int largest = i;  // Initialize largest as root
    int left = 2 * i + 1;  // left child
    int right = 2 * i + 2; // right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Function to insert a new element into the heap
void insertElement(int arr[], int *n, int key) {
    *n = *n + 1;
    int i = *n - 1;

    // Insert the new key at the end
    arr[i] = key;

    // Fix the max heap property if it is violated
    while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }

    printf("inserted\n");
}

// Function to delete an element from the heap
void deleteElement(int arr[], int *n, int key) {
    int i;
    for (i = 0; i < *n; i++) {
        if (arr[i] == key) {
            break;
        }
    }

    if (i == *n) {
        printf("%d not found\n", key);
        return;
    }

    // Replace the key to be deleted with the last element
    arr[i] = arr[*n - 1];
    *n = *n - 1;

    // Heapify the reduced heap
    heapify(arr, *n, i);

    printf("deleted\n");
}

// Function to display all elements in the heap
void displayElements(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice, n = 0, key;
    int *arr = (int *)malloc(100 * sizeof(int));

    while (1) {
        printf("1. Insert the element\n");
        printf("2. Delete the element\n");
        printf("3. Display all elements\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &key);
                insertElement(arr, &n, key);
                break;

            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &key);
                deleteElement(arr, &n, key);
                break;

            case 3:
                displayElements(arr, n);
                break;

            case 4:
                free(arr);
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
