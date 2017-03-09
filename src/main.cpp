#include <stdio.h>
#include <math.h>
#include <SDL2/SDL.h>

void draw_line(SDL_Renderer* renderer, int begin_x, int begin_y, int end_x, int end_y)
{
  float v_1 = abs(end_x - begin_x);
  float v_2 = abs(end_y - begin_y);

  float t = 1/(v_1 + v_2);
  v_1 *= t;
  v_2 *= t;

  float point_x = end_x;
  float point_y = end_y;

  
  for (;point_x<begin_x && point_y<begin_y;point_x +=v_1, point_y +=v_2)
    {
      SDL_RenderDrawPoint(renderer,
			  (int) point_x,
			  (int) point_y);
    }
}

int main(int argc, char* argv[])
{
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Event event;
  
  SDL_Init(SDL_INIT_VIDEO);
  SDL_CreateWindowAndRenderer(512, 512, 0,
			      &window, &renderer);

  while (true)
    {
      SDL_PollEvent(&event);
      if (event.type == SDL_QUIT)
	return 0;


      // DRAW ZONE

      SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
      SDL_RenderClear(renderer);

      SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

      //draw_line(renderer, 0, 0, 512, 512);
      //draw_line(renderer, 0, 0, 512, 512/2);
      //draw_line(renderer, 0, 0, 512/2, 512);

      draw_line(renderer, 512, 512, 0, 0);
      draw_line(renderer, 512, 512/2, 0, 0);
      draw_line(renderer, 512/2, 512, 0, 0);
      
      // END DRAW ZONE

      
      SDL_RenderPresent(renderer);
      SDL_Delay(10);
    }

  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);

  SDL_Quit();

  return 0;
}
