#include <stdio.h>
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high, int pivotIndex) {
    int pivotValue = arr[pivotIndex];
    swap(&arr[pivotIndex], &arr[high]);
    int storeIndex = low;
    for (int i = low; i < high; i++) {
        if (arr[i] < pivotValue) {
            swap(&arr[i], &arr[storeIndex]);
            storeIndex++;
        }
    }
    swap(&arr[storeIndex], &arr[high]);
    return storeIndex;
}
void quickSort(int arr[], int low, int high, int pivotIndex) {
    if (low < high) {
        int pivotPos = partition(arr, low, high, pivotIndex);
        quickSort(arr, low, pivotPos - 1, pivotIndex);
        quickSort(arr, pivotPos + 1, high, pivotIndex);
    }
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[] = {12, 5, 23, 8, 19, 3, 42, 17};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, size);

    int pivotIndex;
    printf("Enter the index of the pivot element you want to use: ");
    scanf("%d", &pivotIndex);

    if (pivotIndex >= 0 && pivotIndex < size) {
        quickSort(arr, 0, size - 1, pivotIndex);
        printf("Sorted using pivot element at index %d: ", pivotIndex);
        printArray(arr, size);
    } else {
        printf("Invalid pivot index.\n");
    }

    return 0;
}
