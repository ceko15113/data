#include <stdio.h>
#define MAXNUM 10
int main(void)
{
	int nin;
	int data[MAXNUM], *pdata;
	int goukei;
	int i;

	scanf("%d", &nin);
	for (i = 0; i < nin; i++)
	{
		scanf("%d", &data[i]);
	}

	pdata = data;

	for (i = 0; i < nin; i++)
	{
		*pdata++ = *(data + i) + 43;
	}

	pdata = &data[0];
	goukei = *pdata;

	for (i = 1; i < nin; i++)
	{
		goukei += *(pdata + 1);
	}
	printf("合計 = %d\n", goukei);

	return 0;
}
