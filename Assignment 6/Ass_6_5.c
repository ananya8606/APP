#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i, int *swaps) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        (*swaps)++;
        heapify(arr, n, largest, swaps);
    }
}

void buildHeap(int arr[], int n, int *swaps) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, swaps);
    }
}

int minSwapsToMaxHeap(int arr[], int n) {
    int swaps = 0;

    buildHeap(arr, n, &swaps);

    return swaps;
}

int main() {
    int T; // Number of test cases
    scanf("%d", &T);

    while (T--) {
        int n; // Size of the array
        scanf("%d", &n);

        int arr[n]; // Array elements
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        int result = minSwapsToMaxHeap(arr, n);
        printf("%d\n", result);
    }

    return 0;
}
