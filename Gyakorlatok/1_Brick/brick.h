#ifndef BRICK_H
#define BRICK_H

//a téglalap három éle
typedef struct Brick
{
	double a;
	double b;
	double c;
} Brick;

//brick set
void set_size(Brick* brick, double a, double b, double c);

//volume
double calc_volume(const Brick* brick);

//surface
double calc_surface(const Brick* brick);

//oldal négyzet-e?
void square_side(const Brick* brick);


#endif
