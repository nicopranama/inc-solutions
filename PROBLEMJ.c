#include <stdio.h>
#include <stdlib.h>

int find_min_swaps(int *A, int N) {
    int left = 0;
    int right = N - 1;

    // Find the end of the longest descending prefix from the start
    while (left < N - 1 && A[left] > A[left + 1]) {
        left++;
    }

    // If the entire array is in descending order, return 0
    if (left == N - 1) return 0;

    // Find the start of the longest ascending suffix from the end
    while (right > 0 && A[right - 1] < A[right]) {
        right--;
    }

    // Check if we can form a valid valley by comparing boundaries
    if (A[left] < A[right]) return -1;

    // Calculate the minimum swaps needed to form the valley
    return N - (left + 1);
}

int main() {
    int N;
    scanf("%d", &N);
    int *A = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int result = find_min_swaps(A, N);
    printf("%d\n", result);

    free(A);
    return 0;
}

