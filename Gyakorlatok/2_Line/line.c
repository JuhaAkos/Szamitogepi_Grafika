#include "line.h"
#include <SDL2/SDL.h>

#include <stdbool.h>
#include <stdio.h>
#include <math.h>

void set_line(Line* line, double x1, double y1, double x2, double y2, int R, int G, int B)
{
	line->x1 = x1;
	line->y1 = y1;
	line->x2 = x2;
	line->y2 = y2;
	line->R = R;
	line->G = G;
	line->B = B;
	
}

int main(int argc, char* argv[])
{
  int error_code;
  SDL_Window* window;
  bool need_run;
  SDL_Event event;
  SDL_Renderer* renderer;
  int i;





  error_code = SDL_Init(SDL_INIT_EVERYTHING);
  if (error_code != 0) {
    printf("[ERROR] SDL initialization error: %s\n", SDL_GetError());
    return error_code;
  }

  window = SDL_CreateWindow(
    "VONAL",
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    1000, 800, 0);

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  
  SDL_SetRenderDrawColor(renderer, 211, 228, 226, 255);
  SDL_RenderClear(renderer);  
  SDL_RenderPresent(renderer);
  
  SDL_Rect rect;
  rect.x =0;
  rect.y =0;
  rect.w =200;
  rect.h =200;

  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderFillRect(renderer, &rect );
 
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  rect.y =201;
  SDL_RenderFillRect(renderer, &rect );

  SDL_SetRenderDrawColor(renderer, 100, 220, 114, 255);
  rect.y =401;
  SDL_RenderFillRect(renderer, &rect );

  SDL_SetRenderDrawColor(renderer, 242, 202, 106, 255);
  rect.y =601;
  SDL_RenderFillRect(renderer, &rect );
  SDL_RenderPresent(renderer);
  



   

  
  
  
  int bx1, by1;
  Uint32 buttons1; 
  int bx2, by2;

  int sz=1;

  //SDL_RenderPresent(renderer);

  need_run = true;
  while (need_run) {
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
		/*
      case SDL_KEYDOWN:
        case SDL_SCANCODE_Q:
        need_run = false;
        break;
        */
  
      //egérlenyomás

      case SDL_MOUSEBUTTONDOWN:
      SDL_GetMouseState(&bx1, &by1);
      if (bx1<=200) {
        
        if (by1>0 && by1<200) {
            SDL_Log("KOCKA1\n");
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }
        else if (by1>200 && by1<400) {
            SDL_Log("KOCKA2\n");
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        }
        else if (by1>400 && by1<600) {
            SDL_Log("KOCKA3\n");
            SDL_SetRenderDrawColor(renderer, 100, 220, 114, 255);
        }
        else if (by1>600 && by1<800) {
            SDL_Log("KOCKA4\n");
            SDL_SetRenderDrawColor(renderer, 242, 202, 106, 255);
        }   
      }

      else {
          if (sz==1) {
            //buttons1 = SDL_GetMouseState(&bx1, &by1);
            //SDL_Log("Pressed here1: %d, %d", bx1, by1);
            bx2=bx1;
            by2=by1;

            sz++;
          }

          else if (sz==2) {            
            //SDL_Log("Pressed here2: %d, %d", bx1, by1);

            sz=1;
            SDL_Log("Ide kellene: %d, %d, %d, %d",bx2, by2, bx1, by1);

            
            SDL_RenderDrawLine(renderer, bx2, by2, bx1, by1);

            /* EZ HA NÉGYSZÖG KELL:
            SDL_Rect rect;

            rect.x = bx2;
            rect.y = by2;
            rect.w = abs(bx1-bx2);
            rect.h = abs(by1-by2);
            SDL_RenderFillRect( renderer, &rect );
            */
            
            SDL_RenderPresent(renderer);
          }
      }
          
        
          break;
  

      case SDL_QUIT:
        need_run = false;
        break;
      }
      
    }
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}

