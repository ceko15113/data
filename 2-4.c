#include <stdio.h>

double point(int n)
{
	double p;
	int i;

	if (n == 0)
		p = 0;
	if (n == 1)
		p = 10;
	if (2 <= n && n <= 10)
		p = 5 + point(n - 1);
	if (10 < n)
		p = (int)point(n - 1) * 1.1;

	return p;
}

int main(void)
{
	int n;

	printf("いくつ買いますか？：");
	scanf("%d", &n);
	printf("ポイントは %d 点です\n", (int) point(n));

	return 0;
}
