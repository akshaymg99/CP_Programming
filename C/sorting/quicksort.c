#include <stdio.h>

void printArray(int a[], int size) {
    for (int i=0; i<size; i++) {
        printf("%d", a[i]);
    }
    printf("\n");

}

void swap(int* a, int* b ) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low-1;
    for (int j=low; j<=high-1; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);

}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pivot_index;
        pivot_index = partition(arr, low, high);
        quickSort(arr, low, pivot_index-1);
        quickSort(arr, pivot_index+1, high);
    }
}

int main() {
    int arr[] = {5, 3, 7, 1, 9, 8, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0, n-1);
    printf("Sorted array \n");
    printArray(arr, n);

    return 0;
}
