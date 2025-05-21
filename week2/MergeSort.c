#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // For sleep function

// Function to merge two subarrays
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
   
    int L[n1], R[n2];
   
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
   
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
   
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
   
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to implement merge sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
       
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
       
        merge(arr, left, mid, right);
        usleep(500000); // Adding a slight delay (500 milliseconds)
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
   
    int arr[n];
    srand(time(0)); // Seed for random number generation
   
    // Generating random numbers for the array
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Random numbers between 0 and 999
    }
   
    printf("Given array is:\n");
    printArray(arr, n);
   
    clock_t start, end;
    double cpu_time_used;
   
    start = clock();
    mergeSort(arr, 0, n - 1);
    end = clock();
   
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
   
    printf("\nSorted array is:\n");
    printArray(arr, n);
   
    printf("Time taken: %f seconds\n", cpu_time_used);
   
    return 0;
}