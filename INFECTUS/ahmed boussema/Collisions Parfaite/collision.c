#include "collision.h"

SDL_Color GetPixel (SDL_Surface* pSurface , int x , int y) 
 {
  SDL_Color color;
  Uint32 col = 0 ;

  //determine position
  char* pPosition = ( char* ) pSurface->pixels ;

  //offset by y
  pPosition += ( pSurface->pitch * y ) ;

  //offset by x
  pPosition += ( pSurface->format->BytesPerPixel * x ) ;

  //copy pixel data
  memcpy ( &col , pPosition , pSurface->format->BytesPerPixel ) ;

  //convert color
  SDL_GetRGB ( col , pSurface->format , &color.r , &color.g , &color.b ) ;
  return ( color ) ;
}

int collision(SDL_Surface *obstacle, Personnage *perso, int m)
{  int colli=1; SDL_Rect position; SDL_Surface *current;
	position=perso->pos;
	current=perso->current;
    SDL_Color c = GetPixel(obstacle, position.x + current->w/2, position.y);
    SDL_Color c2 = GetPixel(obstacle, position.x + current->w/2, position.y + current->h);
    SDL_Color c3 = GetPixel(obstacle, position.x + current->w, position.y + current->h/2);
    SDL_Color c4 = GetPixel(obstacle, position.x , position.y + current->h/2);
    if(c.r == 255 && c.g == 255 && c.b ==255 && m==0)
{
        colli=0;
    }
    if(c2.r == 255 && c2.g == 255 && c2.b ==255 && m==2)
{
        colli=0;
    }
    if(c3.r == 255 && c3.g == 255 && c3.b ==255 & m==3)
{
        colli=0;
    }
if(c4.r == 255 && c4.g == 255 && c4.b ==255 & m==1)
{
        colli=0;
    }
return colli;     
}

int collisionPNJ(SDL_Surface *obstacle,PNJ *pnj, int value)
{  int colli=1; SDL_Rect positionx; SDL_Surface *currentx;
	positionx=pnj->pos;
	currentx=pnj->current;
    SDL_Color c = GetPixel(obstacle, positionx.x + currentx->w/2, positionx.y);
    SDL_Color c2 = GetPixel(obstacle, positionx.x + currentx->w/2, positionx.y + currentx->h);
    SDL_Color c3 = GetPixel(obstacle, positionx.x + currentx->w, positionx.y + currentx->h/2);
    SDL_Color c4 = GetPixel(obstacle, positionx.x , positionx.y + currentx->h/2);
    if(c.r == 255 && c.g == 255 && c.b ==255 && value==0)
{
        colli=0;
    }
    if(c2.r == 255 && c2.g == 255 && c2.b ==255 && value==2)
{
        colli=0;
    }
    if(c3.r == 255 && c3.g == 255 && c3.b ==255 & value==3)
{
        colli=0;
    }
if(c4.r == 255 && c4.g == 255 && c4.b ==255 & value==1)
{
        colli=0;
    }
return colli;     
}
