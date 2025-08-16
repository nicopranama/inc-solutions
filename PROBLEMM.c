#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N;
    scanf("%d", &N);
    
    int size = 3 * N;
    int A[size];
    
    for (int i = 0; i < size; i++) {
        scanf("%d", &A[i]);
    }
    
    qsort(A, size, sizeof(int), compare);
    
    int strength = A[N];
    
    printf("%d\n", strength);
    
    return 0;
}

