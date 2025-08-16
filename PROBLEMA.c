#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool consonant(char ch) {
    return !(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

void spelling(char *word, char *result) {
    int len = strlen(word);
    int pos = 0;
    for (int i = 0; i < len; i++) {
        if (word[i] == 'c') {
            if (i < len - 1 && word[i + 1] == 'h') {
                result[pos++] = 'c';
                i++;
            } else if (i < len - 1 && (word[i + 1] == 'e' || word[i + 1] == 'i' || word[i + 1] == 'y')) {
                result[pos++] = 's';
            } else if (i == len - 1 || (i < len - 1 && consonant(word[i + 1]) && word[i + 1] != 'h' && word[i + 1] != 'y')) {
                result[pos++] = 'k';
            } else {
                result[pos++] = 'k';
            }
        } else {
            result[pos++] = word[i];
        }
    }
    result[pos] = '\0';
}

int main() {
    int N;
    scanf("%d", &N);

    char word[101];
    char results[N][101];
    
    for (int i = 0; i < N; i++) {
        scanf("%s", word);
        spelling(word, results[i]);
    }
    
    for (int i = 0; i < N; i++) {
        printf("%s\n", results[i]);
    }

    return 0;
}

