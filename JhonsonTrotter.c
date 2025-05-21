#include <stdio.h>
#include <stdlib.h>

#define LEFT  -1
#define RIGHT 1

// Structure to represent a mobile element
typedef struct {
    int value;
    int direction; // -1 for LEFT, +1 for RIGHT
} Element;

// Find the largest mobile element index
int largestMobile(Element arr[], int n) {
    int maxIndex = -1;
    int maxValue = -1;

    for (int i = 0; i < n; i++) {
        int dir = arr[i].direction;
        int adj = i + dir;
        if (adj >= 0 && adj < n) {
            if (arr[i].value > arr[adj].value && arr[i].value > maxValue) {
                maxValue = arr[i].value;
                maxIndex = i;
            }
        }
    }
    return maxIndex;
}

// Swap two elements
void swap(Element *a, Element *b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}

// Print current permutation
void printPermutation(Element arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i].value);
    printf("\n");
}

void johnsonTrotter(int n) {
    // Initialize elements and directions (all to LEFT initially)
    Element arr[n];
    for (int i = 0; i < n; i++) {
        arr[i].value = i + 1;
        arr[i].direction = LEFT;
    }

    printPermutation(arr, n);

    while (1) {
        int mobileIndex = largestMobile(arr, n);
        if (mobileIndex == -1) break; // No mobile element means all permutations generated

        int dir = arr[mobileIndex].direction;
        int adj = mobileIndex + dir;

        // Swap with adjacent element in its direction
        swap(&arr[mobileIndex], &arr[adj]);

        // Update the index after swap
        mobileIndex = adj;

        // Reverse direction of all elements greater than moved element's value
        int movedValue = arr[mobileIndex].value;
        for (int i = 0; i < n; i++) {
            if (arr[i].value > movedValue) {
                arr[i].direction = -arr[i].direction;
            }
        }

        printPermutation(arr, n);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    johnsonTrotter(n);
    return 0;
}
