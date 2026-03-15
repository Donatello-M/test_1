#include <stdio.h>
#define N 1000

 int max_len(int * nums, int n) {
	int m = 1;
	int current = 1;
	for (int i = 1; i < n; ++i) {
		if (nums[i-1]*nums[i] < 0)
			current += 1;
		else {
			m = (current > m ? current : m);
			current = 1;
		}
	}
	m = (current > m ? current : m);
	return m;
 }

int main() {
	int x[N];
	int n;
	printf("Введите количество чисел последовательности: ");
	scanf("%d", &n);
	printf("Введите числа: ");
	for (int i = 0; i < n; ++i)
		scanf("%d", x + i);

	int m = max_len(x, n);
	printf("Максимальная длина подпоследовательности с чередующимися знаками: %d \n", m);

	return 0;
}
