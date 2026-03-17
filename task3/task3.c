#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void compute_lps(const char *pattern, int m, int *lps) {
    lps[0] = 0;
    int len = 0;
    
    for (int i = 1; i < m; i++) {
        while (len > 0 && pattern[i] != pattern[len]) {
            len = lps[len - 1];
        }
        
        if (pattern[i] == pattern[len]) {
            len++;
        }
        
        lps[i] = len;
    }
}

int kmp_search(const char *text, const char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    
    if (m > n) return -1;
    
    int *lps = (int *)malloc(m * sizeof(int));
    compute_lps(pattern, m, lps);
    
    int i = 0, j = 0;
    
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }
        
        if (j == m) {
            free(lps);
            return i - j;
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    
    free(lps);
    return -1;
}

int main() {
    printf("Задание 3: Поиск подстроки\n");
    
    int res1 = kmp_search("ABABDABACDABABCABAB", "ABABCABAB");
    printf("Поиск 'ABABCABAB': индекс = %d\n", res1);
    
    int res2 = kmp_search("Hello World", "World");
    printf("Поиск 'World': индекс = %d\n", res2);
    
    return 0;
}
