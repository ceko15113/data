#include <stdio.h>

int factorial(int n)
{
	int ret;

	printf("関数 factorial(%d) に入りました\n", n);
	if (n == 0)
		ret = 1;
	else
		ret = n * factorial(n - 1);
	printf("関数 factorial(%d) から出ます：factorial(%d) = %d\n", n, n, ret);
	return ret;
}

int main(void)
{
	int n;

	printf("自然数を入力してください：");
	scanf("%d", &n);
	printf("%d の階乗は、%d です\n", n, factorial(n));
	return 0;
}
