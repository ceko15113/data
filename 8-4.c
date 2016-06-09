#include <stdio.h>

#define NAME_LEN 20
#define NUM 10

typedef struct {
	char name[NAME_LEN];
	double height;
	double weight;
} student_t;

void insertion(student_t student[])
{
	int i, j;
	student_t tmp;
	for (i = 1; i < NUM; i++) {
		tmp = student[i];
		for (j = i - 1; 0 <= j; j--) {
			if (student[j].height < tmp.height) {
				student[j + 1] = student[j];
			}
			else
				break;
		}
		student[j + 1] = tmp;
	}
}

int main(void)
{
	int i;
	student_t student[NUM] = {
		{"阿部", 178.5, 72.4},
		{"佐藤", 168.8, 55.5},
		{"鈴木", 163.5, 82.3}, 
		{"高橋", 185.0, 76.5},
		{"田中", 175.1, 64.2},
		{"友近", 172.3, 68.2},
		{"中島", 179.7, 77.1},
		{"原田", 182.1, 69.3},
		{"安田", 174.5, 58.8},
		{"渡辺", 176.3, 65.6}
	};

	insertion(student);

	for (i = 0; i < NUM; i++) {
		printf("%s\t%.1f\t%.1f\n",
			student[i].name, student[i].height, student[i].weight);
	}
	return 0;
}
