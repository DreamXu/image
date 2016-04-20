#include <iostream>
#include <cmath>
#include <cstdlib>
#include <stdio.h>

#define DIM 1024
#define DM1 (DIM - 1)
#define _sq(x) ((x) * (x)) // square
#define _cb(x) abs((x) * (x) * (x)) // absolute calue of cube
#define _cr(x) (unsigned char)(pow((x), 1.0 / 3.0)) // cube root

unsigned char GB(int, int);
unsigned char BL(int, int);

unsigned char RD(int i, int j)
{
	// YOUR CODE HERE
}

unsigned char GR(int i, int j)
{
	// YOUR CODE HERE
}

unsigned char BL(int i, int j)
{
	// YOUR CODE HERE
}

void pixel_write(int, int);
FILE *fp;
int main(int argc, const char *argv[])
{

	fp = open("MathPic.ppm", "wb");
	fprintf(fp, "P6\n%d %d\n255\n", DIM, DIM);
	for (int j = 0; j < DIM; J++) {
		for (int i = 0; i < DIM; I++) {
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
