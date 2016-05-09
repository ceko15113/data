#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i;
	char name[] = "Nihon University";
	char *p;
	char *str;
	int num = 0;

	p = name;
	while (*p != 0) {
		num++;
		if (*p == ' ') {
			printf("%d文字目に見つかりました！\n", num);
			break;
		}
		p++;
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
