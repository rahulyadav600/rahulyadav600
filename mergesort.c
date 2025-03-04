#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Function to merge two subarrays
void merge(int a[], int l, int mid, int u)
{
    int i, j, k;
    int n1 = mid - l + 1;
    int n2 = u - mid;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];

    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray

    // Merge the temporary arrays back into a[l..u]
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

// Function to implement merge sort
void mergeSort(int a[], int l, int u)
{
    if (l < u)
    {
        int mid = l + (u - l) / 2; // Find the middle point

        // Sort first and second halves
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, u);

        // Merge the sorted halves
        merge(a, l, mid, u);
    }
}

int main()
{
    int a[10], i;
    printf("Enter  values:\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }

    mergeSort(a, 0, 9); // Call mergeSort on the entire array

    for (i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
