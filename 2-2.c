/*
  データ構造 2回目 課題問題Ⅱ
 */
#include <stdio.h>

#define LEN 100  /* 文字列の上限 */

int get_length(char str[LEN]);

int main(void){
    int i, length;
    char str[LEN], reverse[LEN]; /* strを逆順にした文字列がreverse */

    printf("文字列：");
    scanf("%s", str);

    length = get_length(str);

    for (i = 0; i < length; i++) {
	reverse[i] = str[length - i - 1];
    }
    reverse[length] = '\0';

    printf("文字列の長さ：%d\n", length);
    printf("文字列（逆順）：%s\n", reverse);

    return 0;
}

int get_length(char *str){
    int len = 0;

    while (str[len] != '\0') {
	len++;
    }
    return len;
}
