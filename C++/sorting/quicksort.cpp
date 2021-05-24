#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition_QS(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low -1;
    for (int j=low; j<high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[high], &arr[i+1]);
    return (i+1);
}

void QuickSort(int arr[], int low, int high) {
    int pivot_index;
    if (low < high) {
        pivot_index = partition_QS(arr, low, high);
        QuickSort(arr, low, pivot_index-1);
        QuickSort(arr, pivot_index+1, high);
    }
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int arr[n];
    for (int i=0; i<n; ++i) {
        cout << "Enter element "<< i+1 << ":";
        cin >> arr[i];
    }
    QuickSort(arr, 0, n-1);
    cout << "Sorted array\n";
    for (int i=0; i<n; ++i) {
        cout << arr[i] << "\t";
    }

    return 0;
}
