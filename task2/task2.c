#include <stdio.h>

int max_substring(int arr[], int n) {
    int max_len = 1;
    int current = 1;
    
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i-1]) {
            current++;
            if (current > max_len) {
                max_len = current;
            }
        } else {
            current = 1;
        }
    }
    
    return max_len;
}

int main() {
    printf("Задание 2: Наибольшая подпоследовательность\n");
    
    int arr[] = {1, 2, 2, 2, 3, 3, 3, 3, 4};
    int result = max_substring(arr, 9);
    
    printf("Результат: %d\n", result);
    
    return 0;
}
