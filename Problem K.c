#include <stdio.h>
#include <string.h>

int is_divisible_by_3(const char *num_str) {
    int sum = 0;
    for (int i = 0; num_str[i] != '\0'; i++) {
        sum += num_str[i] - '0';
    }
    return sum % 3 == 0;
}

int can_make_move(const char *num_str) {
    for (int i = 0; i < strlen(num_str) - 2; i++) {
        if (is_divisible_by_3(num_str + i)) {
            return 1;
        }
    }
    return 0;
}

int play_game(const char *num_str, int is_anda_turn) {
    if (!can_make_move(num_str)) {
        return !is_anda_turn; // Opponent wins
    }

    for (int i = 0; i < strlen(num_str) - 2; i++) {
        if (is_divisible_by_3(num_str + i)) {
            char new_num_str[100000];
            strncpy(new_num_str, num_str, i);
            strncpy(new_num_str + i, num_str + i + 1, strlen(num_str) - i - 1);
            new_num_str[strlen(num_str) - 1] = '\0';

            if (!play_game(new_num_str, !is_anda_turn)) {
                return is_anda_turn; // Current player wins
            }
        }
    }

    return !is_anda_turn; // Opponent wins
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        char N[100001];
        scanf("%s", N);

        if (play_game(N, 1)) {
            printf("Anda\n");
        } else {
            printf("Kamu\n");
        }
    }

    return 0;
}
