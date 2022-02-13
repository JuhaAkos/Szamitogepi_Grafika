#include "brick.h"

#include <stdio.h>

#include <math.h>

void set_size(Brick* brick, double a, double b, double c)
{
    if(a > 0.0) brick->a = a;
    else brick->a = NAN;

    if(b > 0.0) brick->b = b;
    else brick->b = NAN;

    if(c >0.0) brick->c = c;
    else brick->c = NAN;

}

double calc_volume(const Brick* brick)
{
	double volume = brick->a * brick->b * brick->c;
	return volume;
}

double calc_surface(const Brick* brick)
{
    double surface = 2 * (brick->a * brick->b + brick->a * brick->c + brick->b * brick->c);
	return surface;
}

void square_side(const Brick* brick)
{
    if (isnan(brick->a) || isnan(brick->b) || isnan(brick->c)) return;
    else if (brick->a == brick->b) {
        printf("The cubeoid has a square shaped side, and it's edge's length is: %lf\n", brick->a);
        return;
    }

    else if (brick->b == brick->c) {
        printf("The cubeoid has a square shaped side, and it's edge's length is: %lf\n", brick->b);
        return;
    }

    else if (brick->c == brick->a) {
        printf("The cubeoid has a square shaped side, and it's edge's length is: %lf\n", brick->c);
        return;
    }

    else {
        printf("The cubeoid has no square shaped side.\n");
        return;
    }
}