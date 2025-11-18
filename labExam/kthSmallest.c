#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

// Function to generate unique random values
void generateDistinctRandom(int a[], int n) {
    int used[N + 1] = {0};
    for(int i = 0; i < n; i++) {
        int num;
        do {
            num = rand() % (n + 1);
        } while(used[num]);
        used[num] = 1;
        a[i] = num;
    }
}

// Partition function used in quickselect
int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
        if(a[j] <= pivot) {
            i++;
            int temp = a[i]; a[i] = a[j]; a[j] = temp;
        }
    }
    int temp = a[i + 1]; a[i + 1] = a[high]; a[high] = temp;
    return i + 1;
}

// Quickselect algorithm
int quickSelect(int a[], int low, int high, int k) {
    if(low == high) return a[low];

    int p = partition(a, low, high);
    int position = p - low + 1;

    if(position == k)
        return a[p];
    else if(position > k)
        return quickSelect(a, low, p - 1, k);
    else
        return quickSelect(a, p + 1, high, k - position);
}

int main() {
    int arr[N];
    srand(time(NULL));

    generateDistinctRandom(arr, N);

    printf("Generated Array:\n");
    for(int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");

    clock_t start = clock();

    int k1 = 5, k2 = 10, k3 = 15;
    int ans1 = quickSelect(arr, 0, N - 1, k1);
    int ans2 = quickSelect(arr, 0, N - 1, k2);
    int ans3 = quickSelect(arr, 0, N - 1, k3);

    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n5 th smallest: %d\n", ans1);
    printf("10 th smallest: %d\n", ans2);
    printf("15 th smallest: %d\n", ans3);

    printf("\nRunning time: %f seconds\n", time_taken);

    return 0;
}
