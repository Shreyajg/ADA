#include <stdio.h>
#include <stdlib.h>

// Utility function to get max of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Knapsack function
void knapSack(int** WeightCost, int size, int capacity) {
    int** table = (int**)malloc((size + 1) * sizeof(int*));
    for (int i = 0; i <= size; i++) {
        table[i] = (int*)calloc(capacity + 1, sizeof(int));
    }

    for (int i = 1; i <= size; i++) {
        for (int w = 1; w <= capacity; w++) {
            int weight = WeightCost[i - 1][0];
            int value = WeightCost[i - 1][1];
            if (weight <= w) {
                table[i][w] = max(table[i - 1][w], table[i - 1][w - weight] + value);
            } else {
                table[i][w] = table[i - 1][w];
            }
        }
    }
    printf("Knapsack Table\n");
    for(int i=0;i<=size;i++)
    {
        for(int j=0;j<=capacity;j++)
        {
            printf("%d ",table[i][j]);
        }
        printf("\n");
    }

    // Final result
    printf("Maximum profit: %d\n", table[size][capacity]);

    // Cleanup
    for (int i = 0; i <= size; i++) {
        free(table[i]);
    }
    free(table);
}

// Driver code
int main() {
    int size, capacity;
    printf("Enter number of items: ");
    scanf("%d", &size);
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    int** WeightCost = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        WeightCost[i] = (int*)malloc(2 * sizeof(int));
        printf("Enter weight and value for item %d: ", i + 1);
        scanf("%d %d", &WeightCost[i][0], &WeightCost[i][1]);
    }

    knapSack(WeightCost, size, capacity);

    for (int i = 0; i < size; i++) {
        free(WeightCost[i]);
    }
    free(WeightCost);

    return 0;
}
