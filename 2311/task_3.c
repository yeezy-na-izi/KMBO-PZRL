// bin_search

#include <stdio.h>

int bin_search(int *arr, int size, int value, int left, int right) {
    if (left > right) {
        return -1;
    }
    int mid = (left + right) / 2;
    if (arr[mid] == value) {
        return mid;
    } else if (arr[mid] > value) {
        return bin_search(arr, size, value, left, mid - 1);
    } else {
        return bin_search(arr, size, value, mid + 1, right);
    }
}

int sort(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    return 0;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    sort(arr, 9);
    int size = sizeof(arr) / sizeof(arr[0]);
    int value;
    scanf("%d", &value);
    printf("%d\n", bin_search(arr, size, value, 0, size - 1));
    return 0;
}