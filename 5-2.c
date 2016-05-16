#include <stdio.h>

#define N 5

typedef struct {
	int id;
	char name[20];
	int math;
	int english;
	int japanese;
} STUDENT;

int main(void)
{
	STUDENT student[N] = {
		{276001, "阿部", 82, 72, 90},
		{276051, "佐藤", 68, 50, 62},
		{276101, "鈴木", 42, 65, 52},
		{276151, "高橋", 92, 34, 46},
		{276201, "渡辺", 50, 70, 74}
	};
	int i;
	int mathSum = 0, englishSum = 0, japaneseSum = 0;

	printf("成績リスト\n");
	printf("学生番号\t氏名\t数学\t英語\t国語\t合計\n");
	for (i = 0; i < N; i++) {
		printf("%d\t\t%s\t%d点\t%d点\t%d点\t%d点\n",
		student[i].id, student[i].name, student[i].math, student[i].english, student[i].japanese,
		student[i].math + student[i].english + student[i].japanese);
		mathSum += student[i].math;
		englishSum += student[i].english;
		japaneseSum += student[i].japanese;
	}
	printf("平均点\t\t\t%.1f点\t%.1f点\t%.1f点\n", (double)mathSum / N, (double)englishSum / N, (double)japaneseSum / N);

	return 0;
}
