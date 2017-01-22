#include <stdio.h>

int
func(int n, int r)
{
	if (n == 0)
		return n;
	return n + r * func(n - 1, r);
}

int
main()
{
	int n, r;

	printf("n の値は？：");
	scanf("%d", &n);
	printf("r の値は？；");
	scanf("%d", &r);
	printf("f(n) は %d です\n", func(n, r));

	return 0;
}
