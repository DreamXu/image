#include <iostream>
#include <cmath>
#include <cstdlib>
#include <stdio.h>

#define DIM 1024
#define DM1 (DIM - 1)
#define _sq(x) ((x) * (x)) // square
#define _cb(x) abs((x) * (x) * (x)) // absolute calue of cube
#define _cr(x) (unsigned char)(pow((x), 1.0 / 3.0)) // cube root
#define e 2.718281828459

unsigned char GB(int, int);
unsigned char BL(int, int);

unsigned char RD(int i, int j)
{
	double a = 0, b = 0, c, d, n = 0;
	while((c = a * a) + (d = b * b) < 4 && n ++ < 880) {
		b = 2 * a * b + j * 8 * e - 9 - 0.645411;
		a = c - d + i * 8 * e - 9 + 0.356888;
	}
	return 255 * pow((n - 80) / 800, 3.0);
}

unsigned char GR(int i, int j)
{
	double a = 0, b = 0, c, d, n = 0;
	while((c = a * a) + (d = b * b) < 4 && n ++ < 880) {
		b = 2 * a * b + j * 8 * e - 9 - 0.645411;
		a = c - d + i * 8 * e - 9 + 0.356888;
	}
	return 255 * pow((n - 80) / 800, 0.7);
}

unsigned char BL(int i, int j)
{
	double a = 0, b = 0, c, d, n = 0;
	while((c = a * a) + (d = b * b) < 4 && n ++ < 880) {
		b = 2 * a * b + j * 8 * e - 9 - 0.645411;
		a = c - d + i * 8 * e - 9 + 0.356888;
	}
	return 255 * pow((n - 80) / 800, 0.5);
}

void pixel_write(int, int);
FILE *fp;
int main(int argc, const char *argv[])
{

	fp = fopen("MathPic.ppm", "wb");
	fprintf(fp, "P6\n%d %d\n255\n", DIM, DIM);
	for (int j = 0; j < DIM; j++) {
		for (int i = 0; i < DIM; i++) {
			pixel_write(i, j);
		}
	}
	fclose(fp);
	return 0;
}

void pixel_write(int i, int j)
{
	static unsigned char color[3];
	color[0] = RD(i, j) & 255;
	color[1] = GR(i, j) & 255;
	color[2] = BL(i, j) & 255;
	fwrite(color, 1, 3, fp);
}
