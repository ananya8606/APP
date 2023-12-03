#include <stdio.h>
#include <stdlib.h>

int heap[100], size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int x) {
    heap[size] = x;
    int now = size;
    while (heap[now] > heap[(now - 1) / 2]) {
        swap(&heap[now], &heap[(now - 1) / 2]);
        now = (now - 1) / 2;
    }
    size++;
}

void deleteMax() {
    int now = 0;
    heap[now] = heap[size - 1];
    size--;
    while (1) {
        int left = now * 2 + 1, right = now * 2 + 2;
        if (left >= size) {
            break;
        }
        int max = left;
        if (right < size && heap[right] > heap[left]) {
            max = right;
        }
        if (heap[now] < heap[max]) {
            swap(&heap[now], &heap[max]);
            now = max;
        } else {
            break;
        }
    }
}

void printHeap() {
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insert(x);
    }
    printHeap();
    /*while (size > 0) {
        deleteMax();
        printHeap();
    }*/
    return 0;
}
