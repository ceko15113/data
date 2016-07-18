#include <stdio.h>

int
fibonacci(int n)
{
	if (n == 0 || n == 1)
		return n;
	
	return fibonacci(n - 1) + fibonacci(n - 2);
}

int
main(void)
{
	int n;

	printf("n 番目のフィボナッチ数を求めます。\n");
	printf("n の値は？：");
	scanf("%d", &n);
	printf("%d 番目のフィボナッチ数は %d です。\n", n, fibonacci(n));
	
	return 0;
}

