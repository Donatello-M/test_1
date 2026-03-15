#include <stdio.h>
#include <string.h>

int isAnagram(char a[], char b[]) {

    if (strlen(a) != strlen(b)) {
        return 0;
    }

    int count[26] = {0};

    for (int i = 0; i < strlen(a); i++) {
        count[a[i] - 'a']++;
        count[b[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            return 0;
        }
    }

    return 1;
}

int main() {

    int n;
    scanf("%d", &n);

    char words[n][50];

    for (int i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }

    for (int i = 0; i < n; i++) {

        printf("%s: ", words[i]);

        for (int j = 0; j < n; j++) {

            if (isAnagram(words[i], words[j])) {
                printf("%s ", words[j]);
            }

        }

        printf("\n");
    }

    return 0;
}
