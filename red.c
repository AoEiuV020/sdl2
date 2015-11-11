/*****************************************************
	^> File Name: 1.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/11/11 - 13:41:16
****************************************************/
#include <stdio.h>
#include <SDL2/SDL.h>
#undef main
int main(int argc, char **argv)
{
	int width,height;
	width=300;
	height=300;
	SDL_Window *window = NULL;
	SDL_Surface *surface = NULL;
	SDL_Init(SDL_INIT_VIDEO);
	window=SDL_CreateWindow("SDL",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,SDL_WINDOW_SHOWN);
	if(window==NULL)
	{
		fprintf(stderr,"Create: %s\n",SDL_GetError());
		return -1;
	}
	surface=SDL_GetWindowSurface(window);
	if(surface==NULL)
	{
		fprintf(stderr,"GetWindowsSerface: %s\n",SDL_GetError());
		return -2;
	}

	SDL_FillRect(surface,NULL,SDL_MapRGB(surface->format,0xFF,0x00,0x00));
	SDL_UpdateWindowSurface(window);
	SDL_Delay(2000);
	
	SDL_FreeSurface(surface);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
