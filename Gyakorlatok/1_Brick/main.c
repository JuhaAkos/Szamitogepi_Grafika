#include "brick.h"

#include <stdio.h>

int main(int argc, char* argv[])
{
	Brick brick;
	double volume;
    double surface;
	
	set_size(&brick, 10, 10, 3);
	volume = calc_volume(&brick);
    surface = calc_surface(&brick);

    square_side(&brick);
	
	printf("Brick volume: %lf\nBrick surface: %lf\n", volume, surface );
	
	return 0;
}