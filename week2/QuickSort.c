#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<unistd.h>
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[], int l, int r)
{
    int i = l - 1;
    int p = a[r];
    for (int j = l; j < r; j++)
    {
        if (a[j] < p)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[r]);
    return i + 1;
}

void quickSort(int a[], int l, int r)
{
    if (l < r)
    {
        int p = partition(a, l, r);
        quickSort(a, l, p - 1);
        quickSort(a, p + 1, r);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements in the array:\n");
    scanf("%d", &n);
    int a[n];
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    quickSort(a, 0, n - 1);
    usleep(2000);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\nTime taken: %f seconds\n", cpu_time_used);

    return 0;
}
