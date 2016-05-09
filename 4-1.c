#include <stdio.h>

void fstrcpy(char *p1, char *p2);
void fstrcat(char *p1, char *p2);

int main(void)
{
	char moji1[10], moji2[10];

	fstrcpy(moji1, "ABC");
	fstrcpy(moji2, "DEF");
	fstrcat(moji1, moji2);

	printf("moji1: %s\n", moji1);
	printf("moji2: %s\n", moji2);

	return 0;
}

void fstrcpy(char *p1, char *p2)
{
	while (*p2 != 0) {
		*p1++ = *p2++;
	}
	*p1 = 0;
}

void fstrcat(char *p1, char *p2)
{
	while (*p1 != 0) {
		p1++;
	}
	while (*p2 != 0) {
		*p1++ = *p2++;
	}
	*p1 = 0;
}
