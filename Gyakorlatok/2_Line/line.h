//#include <SDL2/SDL.h>

#ifndef LINE_H
#define LINE_H

/**
 * Data of a circle object in Descartes coordinate system
 */
typedef struct Line
{
	double x1;
	double y1;
	double x2;
	double y2;
	int R;
	int G;
	int B;
} Line;


void set_line(Line* line, double x1, double y1, double x2, double y2, int R, int G, int B);
/*
Calculate the area of the circle.

double calc_circle_area(const Circle* circle);
*/

#endif // CIRCLE_H
