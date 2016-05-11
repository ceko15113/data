#include <stdio.h>
#include <stdlib.h>

int find(char *s, char c)
{
	int num = 0;
	while (*s != 0) {
		num++;
		if (*s == ' ') {
			return num;
		}
		s++;
	}
	return -1;
}

int main(void)
{
	int i;
	char name[] = "Nihon University";
	char *p;
	char *str;
	int num = 0;

	p = name;
	num = find(p, ' ');
	if (num != -1)
		printf("%d文字目に見つかりました！\n", num);
	else {
		printf("スペース記号は見つかりませんでした");
		return 0;
	}

	str = (char *)malloc((num + 1) * sizeof(char));

	for (i = 0; i < num; i++) {
		*(str + i) = name[i];
	}
	*(str + i) = 0;

	printf("%s\n", str);

	free(str);

	return 0;
}
