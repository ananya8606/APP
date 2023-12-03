#include <stdio.h>

int isMaxHeap(int arr[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        if (arr[2 * i + 1] > arr[i]) {
            return 0;
        }
        if (2 * i + 2 < n && arr[2 * i + 2] > arr[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int T, n, x;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d", &n);
        int arr[n];
        for (int j = 0; j < n; j++) {
            scanf("%d", &x);
            arr[j] = x;
        }
        if (isMaxHeap(arr, n)) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    return 0;
}
