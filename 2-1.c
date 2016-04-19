#include <stdio.h>
#include <assert.h>

int sum(int n)
{
	int ret;
	assert(n % 2 == 0 && n > 0);

	if (n == 2)
		return 2;
	ret = sum(n - 2) + n;
	
	return ret;
}

int main(void)
{
	int value;

	printf("正の偶数を入力してください：");
	scanf("%d", &value);
	printf("sum(%d) = %d\n", value, sum(value));

	return 0;
}
