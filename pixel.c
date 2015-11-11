/*****************************************************
	^> File Name: pixel.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/11/11 - 13:41:16
****************************************************/
#include <stdio.h>
#include <math.h>
#include <SDL2/SDL.h>
#undef main
#define _sq(x) ((x)*(x)) // square
#define _cb(x) abs((x)*(x)*(x)) // absolute value of cube
#define _cr(x) (unsigned char)(pow((x),1.0/3.0)) // cube root
#define RD red
#define GR green
#define BL blue
#define DIM height
#define DM1 (height-1)
int width=512,height=512;

unsigned char RD(int i,int j);
unsigned char GR(int i,int j);
unsigned char BL(int i,int j);

unsigned char RD(int i,int j){
	return BL(i,j)/2;
}
 
unsigned char GR(int i,int j){
	return RD(i,j)/4;
}
 
unsigned char BL(int i,int j){
	return _cb(sin(i)+cos(j))*0xff;
}
void writepixel(SDL_Surface *surface)
{
	int bpp;
	int i,j;
	Uint32 *pixels;
	Uint32 color;
	Uint32 rmask,gmask,bmask,amask;
	unsigned char r,g,b;
	bpp=surface->format->BytesPerPixel;
	pixels=surface->pixels;
	rmask=surface->format->Rmask;
	gmask=surface->format->Gmask;
	bmask=surface->format->Bmask;
	amask=surface->format->Amask;
	rmask/=0xFF;
	gmask/=0xFF;
	bmask/=0xFF;
	printf("%d,\n",bpp);
	printf("%08x\n%08x\n%08x\n%08x;\n",rmask,gmask,bmask,amask);
	SDL_LockSurface(surface);
	for(i=0;i<height;++i)
	{
		for(j=0;j<width;++j,++pixels)
		{
			r=red(i,j);
			g=green(i,j);
			b=blue(i,j);
			color=0;
			color+=r*rmask;
			color+=g*gmask;
			color+=b*bmask;
			*pixels=color;
		}
	}
	SDL_UnlockSurface(surface);
}
int main(int argc, char **argv)
{
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
	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0x00, 0x00));
	writepixel(surface);
	SDL_UpdateWindowSurface(window);
	SDL_Delay(4000);
	
	SDL_FreeSurface(surface);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
