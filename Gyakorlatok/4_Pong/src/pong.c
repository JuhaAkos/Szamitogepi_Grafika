#include "pong.h"
#include <SDL2/SDL.h>

void init_pong(Pong* pong, int width, int height)
{
    pong->width = width;
    pong->height = height;
    init_pad(&(pong->left_pad), 0, height, RED_THEME);
    init_pad(&(pong->right_pad), width - 50, height, GREEN_THEME);
    init_ball(&(pong->ball), width / 2, height / 2);
    pong->left_score=0;
    pong->right_score=0;
}

void update_pong(Pong* pong, double time)
{
    update_pad(&(pong->left_pad), time);
    update_pad(&(pong->right_pad), time);
    update_ball(&(pong->ball), time);
    bounce_ball(pong);
}

void render_pong(Pong* pong)
{
    render_pad(&(pong->left_pad));
    render_pad(&(pong->right_pad));
    render_ball(&(pong->ball));
}

void set_left_pad_position(Pong* pong, float position)
{
    set_pad_position(&(pong->left_pad), position);
}

void set_left_pad_speed(Pong* pong, float speed)
{
    set_pad_speed(&(pong->left_pad), speed);
}

void set_right_pad_position(Pong* pong, float position)
{
    set_pad_position(&(pong->right_pad), position);
}

void set_right_pad_speed(Pong* pong, float speed)
{
    set_pad_speed(&(pong->right_pad), speed);
}

void radius_ball_plus(Pong* pong) //labda növelés
{
	if (pong->ball.radius <= 100) {
        pong->ball.radius=pong->ball.radius*1.25;
    }
}

void radius_ball_minus(Pong* pong) //labda csökkentés
{
    if (pong->ball.radius >= 5) {
	    pong->ball.radius=pong->ball.radius/1.25;
    }
}

void ball_placement (Pong* pong, int vx, int vy) //labda áthelyezése kattintásra
{   
    pong->ball.x=vx;
    pong->ball.y=vy;
}

void bounce_ball(Pong* pong)
{
    if (pong->ball.y<=(pong->left_pad.y+pong->left_pad.height) && pong->ball.y>=(pong->left_pad.y)) {
		if (pong->ball.x - pong->ball.radius < 50) {    //bal
        pong->ball.x = pong->ball.radius + 50;
        pong->ball.speed_x *= -1;
		}
	}
    
	if (pong->ball.y<=(pong->right_pad.y+pong->right_pad.height) && pong->ball.y>=(pong->right_pad.y)) {
        if (pong->ball.x + pong->ball.radius > pong->width - 50) {      //jobb
            pong->ball.x = pong->width - pong->ball.radius - 50;
            pong->ball.speed_x *= -1;
        }
    }

    //HA A LABDA KIMEGY OLDALT:
    if (pong->ball.x - pong->ball.radius < 0) {    //bal
        pong->ball.x = 500;  //A képernyő közepére
        pong->ball.y = 300;
        pong->ball.speed_x *= -1;

        //eredmeny kiiras jobb
        pong->right_score+=1; 
        
        SDL_Log("Az allas %d - %d\n",pong->left_score,pong->right_score);
		}

    if (pong->ball.x + pong->ball.radius > pong->width) {      //jobb
            pong->ball.x = 500;  //A képernyő közepére
            pong->ball.y = 300;
            pong->ball.speed_x *= -1;

        //eredmeny kiiras bal
        pong->left_score+=1; 

        SDL_Log("Az allas %d - %d\n",pong->left_score,pong->right_score);
        }

    if (pong->ball.y - pong->ball.radius < 0) {  //felül határ
        pong->ball.y = pong->ball.radius;
        pong->ball.speed_y *= -1;
    }
	
    if (pong->ball.y + pong->ball.radius > pong->height) {   // alul határ
        pong->ball.y = pong->height - pong->ball.radius;
        pong->ball.speed_y *= -1;
    }
}
