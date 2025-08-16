#include <stdio.h>
#include <stdlib.h>

#define MAX_SUM 2000000000  

typedef struct {
    int sum;
    int count;
} SumCount;

int compare(const void *a, const void *b) {
    return ((SumCount *)a)->sum - ((SumCount *)b)->sum;
}

int main() {
    int N;
    scanf("%d", &N);
    
    int *A = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    SumCount *sums = (SumCount *)malloc((N - 1) * sizeof(SumCount));
    int unique_sums = 0;

    for (int i = 0; i < N - 1; i++) {
        int sum = A[i] + A[i + 1];
        
        int found = 0;
        for (int j = 0; j < unique_sums; j++) {
            if (sums[j].sum == sum) {
                sums[j].count++;
                found = 1;
                break;
            }
        }
        
        if (!found) {
            sums[unique_sums].sum = sum;
            sums[unique_sums].count = 1;
            unique_sums++;
        }
    }

    int max_chunks = 0;
    for (int i = 0; i < unique_sums; i++) {
        if (sums[i].count > max_chunks) {
            max_chunks = sums[i].count;
        }
    }

    printf("%d\n", max_chunks);

    free(A);
    free(sums);
    
    return 0;
}
