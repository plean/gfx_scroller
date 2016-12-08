/*
** tekfunctions.c for  in /home/planch_j/rendu/Info/gfx_scroller/planch_j/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sat Mar 19 00:40:11 2016 Jean PLANCHER
** Last update Sun Mar 20 18:45:21 2016 Michel Mancier
*/

#include "my.h"

void		full_color(t_bunny_pixelarray *pix, unsigned int color)
{
  unsigned int	*pixel;
  int		i;

  i = -1;
  pixel = (unsigned int *)pix->pixels;
  while (++i < WIDTH * HEIGHT)
    pixel[i] = color;
}

void            t_tekpixel(t_bunny_pixelarray *pix,
			   int y, int x,
			   unsigned int color)
{
  unsigned int  *pixel;
  double        percent;
  t_color       t;
  t_color       c;

  t.full = color;
  percent = t.argb[3] / 255.0;
  c.full = pl_get_color(pix, x, y);
  c.argb[2] = t.argb[2] * percent + c.argb[2] * (1 - percent);
  c.argb[1] = t.argb[1] * percent + c.argb[1] * (1 - percent);
  c.argb[0] = t.argb[0] * percent + c.argb[0] * (1 - percent);
  //printf("%x %x\n", c.full, t.full);
  pixel = (unsigned int*)pix->pixels;
  if (x < pix->clipable.clip_width &&
      y < pix->clipable.clip_height && x >= 0 && y >= 0)
    pixel[pix->clipable.clip_width * y + x] = c.full;
}

t_bunny_position	getletterdim(t_bunny_pixelarray *font)
{
  t_bunny_position	letter;

  letter.x = font->clipable.buffer.width / 128;
  letter.y = font->clipable.buffer.height;
  return (letter);
}

unsigned int	pl_get_color(t_bunny_pixelarray *pix,
			     int x,
			     int y)
{
  t_bunny_position      pos;
  unsigned int          *pixel;

  if (x < 0 || y < 0 || x >= pix->clipable.clip_width ||
      y >= pix->clipable.clip_height)
    return (0);
  pos.x = x;
  pos.y = y;
  pixel = (unsigned int*)pix->pixels;
  return (pixel[pix->clipable.clip_width * pos.y + pos.x]);
}
