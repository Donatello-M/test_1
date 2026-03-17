#include <stdio.h>
#include <limits.h>

int reverse_integer(int x) {
    long rev = 0;
    int temp = x;
    
    while (temp != 0) {
        int digit = temp % 10;
        rev = rev * 10 + digit;
        
        if (rev > INT_MAX || rev < INT_MIN) {
            return 0;
        }
        
        temp /= 10;
    }
    
    return (int)rev;
}

int main() {
    printf("Задание 1: Разворот целого числа\n");
    
    printf("reverse_integer(123) = %d\n", reverse_integer(123));
    printf("reverse_integer(-123) = %d\n", reverse_integer(-123));
    printf("reverse_integer(120) = %d\n", reverse_integer(120));
    printf("reverse_integer(0) = %d\n", reverse_integer(0));
    
    return 0;
}
