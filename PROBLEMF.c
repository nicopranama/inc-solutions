#include <stdio.h>

long long max_productivity(int N, int K, int R) {
    // Check if impossible to distribute
    if (R < N || K < N) return 0;

    // Initialize productivity
    long long productivity = 0;

    // Calculate base problems and ratings
    int base_k = K / N;
    int remainder_k = K % N;

    int base_r = R / N;
    int remainder_r = R % N;

    // Total problems and ratings must be distributed
    int k = base_k; // start with base_k
    int r = base_r; // start with base_r

    // Calculate productivity day by day
    for (int i = 0; i < N; i++) {
        // For each day, assign the current k and r
        productivity += (long long)k * r;

        // Update k: it can decrease only after the first day
        if (i < remainder_k) k++;  // Distribute remainder to the first few days

        // Update r: it can increase if there's remainder
        if (i < remainder_r) r++;  // Distribute remainder to the first few days

        // Ensure k decreases or stays the same for the next day
        if (i < N - 1) {
            k = base_k + (i + 1 < remainder_k ? 1 : 0);
        }
    }

    return productivity;
}

int main() {
    int T;
    scanf("%d", &T);

    long long results[T];

    for (int i = 0; i < T; i++) {
        int N, K, R;
        scanf("%d %d %d", &N, &K, &R);
        results[i] = max_productivity(N, K, R);
    }

    for (int i = 0; i < T; i++) {
        printf("%lld\n", results[i]);
    }

    return 0;
}

