#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

// Function to heapify a subtree rooted with node i, which is an index in array a[].
// n is the size of the heap
void heap(int a[], int n, int i) {
    int largest = i;   // Initialize largest as root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && a[left] > a[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && a[right] > a[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        // Recursively heapify the affected subtree
        heap(a, n, largest);
    }
}

// Function to perform heap sort
void heapSort(int a[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heap(a, n, i);

    // One by one extract elements from the heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        // Call heapify on the reduced heap
        heap(a, i, 0);
    }
}

int main() {
    int a[10], i;
    printf("Enter 10 values:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }

    heapSort(a, 10); // Call heapSort on the array

    printf("Sorted array:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
