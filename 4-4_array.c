#include <stdio.h>
#include <string.h>

#define WORD_MAXLEN 15

void remove_period(char *s)
{
	int i;
	
	for (i = 0; s[i] != 0; i++) {
		if (s[i] == '.') s[i] = 0;
	}
}

int main(void)
{
	int word_len[WORD_MAXLEN] = {};
	int len;
	int i;
	char word[WORD_MAXLEN + 1];

	i = 1;
	while (1) {
		printf("%d 番目の英単語を入力してください(15 文字以内):\n--> ", i++);
		scanf("%s", word);
		remove_period(word);
		if (!strcmp(word, "*")) break;
		len = strlen(word);
		word_len[len - 1]++;
	}

	printf("文字数\t出現回数\n");
	for (i = 0; i < WORD_MAXLEN; i++)
		printf("%d\t%d\n", i + 1, word_len[i]);
	
	return 0;
}
