#include <stdio.h>

int main(void)
{
	int a = 100;
	float b = 18.25;
	printf("a の値は %d、アドレスは %p です。\n", a, &a);
	printf("b の値は %f、アドレスは %p です。\n", b, &b);
	return 0;
}
