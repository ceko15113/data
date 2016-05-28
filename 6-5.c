#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

#define MAX_SIZE 256

#define SWAP(type, x, y) \
	do { \
		type tmp; \
		tmp = x; \
		x = y; \
		y = tmp; \
	} while (0)

int main(void)
{
	FILE *fp_in, *fp_out;
	int x, y;
	int width, height;
	char r[MAX_SIZE][MAX_SIZE];
	char g[MAX_SIZE][MAX_SIZE];
	char b[MAX_SIZE][MAX_SIZE];

	fp_in = fopen("N.bmp", "rb");

	readBMPHeader(fp_in, &height, &width);

	for (y = 0; y < height; y++) {
		for (x = 0; x < width; x++) {
			fread(&b[y][x], sizeof(b[y][x]), 1, fp_in);
			fread(&g[y][x], sizeof(g[y][x]), 1, fp_in);
			fread(&r[y][x], sizeof(r[y][x]), 1, fp_in);
		}
	}

	for (y = 0; y < height; y++) {
		for (x = 0; x < width; x++) {
			if (r[y][x] == 0 && g[y][x] == 0 && b[y][x] == 0) r[y][x] = 255;
		}
	}

	for (y = 0; y < height; y++) {
		for (x = 0; x < width / 2; x++) {
			SWAP(char, r[y][width - x - 1], r[y][x]);
			SWAP(char, g[y][width - x - 1], g[y][x]);
			SWAP(char, b[y][width - x - 1], b[y][x]);
		}
	}

	fp_out = fopen("read.bmp", "wb");

	writeBMPHeader(fp_out, height, width);

	for (y = 0; y < height; y++) {
		for (x = 0; x < width; x++) {
			fwrite(&b[y][x], sizeof(b[y][x]), 1, fp_out);
			fwrite(&g[y][x], sizeof(g[y][x]), 1, fp_out);
			fwrite(&r[y][x], sizeof(r[y][x]), 1, fp_out);
		}
	}

	fclose(fp_in);
	fclose(fp_out);

	return 0;
}
