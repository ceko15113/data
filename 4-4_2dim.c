#include <stdio.h>
#include <string.h>

#define WORD_MAXLEN 15
#define WORD_MAX 30

void remove_period(char *s)
{
	int i;
	for (i = 0; s[i] != 0; i++) {
		if (s[i] == '.') s[i] = 0;
	}
}

int main(void)
{
	char word[WORD_MAX][WORD_MAXLEN + 1];
	int word_len[WORD_MAXLEN] = {};
	char (*p)[WORD_MAXLEN + 1];
	int i;

	for (i = 0, p = word; i < WORD_MAX; i++) {
		printf("%d 番目の英単語を入力してください(15 文字以内):\n--> ", i + 1);
		scanf("%s", *p);
		if (**p++ == '*') break;
	}

	for (i = 0, p = word; **p != '*'; i++) {
		remove_period(*p);
		word_len[strlen(*p++) - 1]++;
	}

	printf("文字数\t出現回数\n");
	for (i = 0; i < WORD_MAXLEN; i++)
		printf("%d\t%d\n", i + 1, word_len[i]);

	return 0;
}
