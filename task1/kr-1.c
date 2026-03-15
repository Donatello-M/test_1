#include <stdio.h>


double pow(double x, int n) {
	if (n == 0)
		return 1;

	if (n < 0) {
		x = 1/x;
		n = -n;
	}
	if (n % 2 == 0)
		return pow(x*x, n/2);

	return x*pow(x, n-1);
}

int main() {
	int n;
	double x;
	printf("Введите x и n: ");
	scanf("%lf %d", &x, &n);
	double res = pow(x, n);
	printf("%lf \n", res);
	return 0;
}
