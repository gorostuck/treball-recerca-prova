#include <stdio.h>

#include <SDL2/SDL.h>

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
      
      // END DRAW ZONE

      
      SDL_RenderPresent(renderer);
      SDL_Delay(10);
    }

  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);

  SDL_Quit();

  return 0;
}
