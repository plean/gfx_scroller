/*
** rertro.c for  in /home/planch_j/rendu/Info/gfx_scroller/planch_j/retro/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sun Mar 20 18:48:29 2016 Jean PLANCHER
** Last update Sun Mar 20 22:24:27 2016 Jean PLANCHER
*/

#include "my.h"

static unsigned char	wt_red(unsigned char c)
{
  if (c < 32)
    return (0);
  if (c < 88)
    return (64);
  if (c < 120)
    return (112);
  if (c < 136)
    return (128);
  if (c < 168)
    return (144);
   return ((c < 224) ? 192 : 255);
}

static unsigned char	wt_green(unsigned char c)
{
  if (c < 24)
    return (0);
  if (c < 56)
    return (48);
  if (c < 88)
    return (64);
  if (c < 120)
    return (112);
  if (c < 136)
    return (128);
   return ((c < 160) ? 192 : 255);
}

static unsigned char	wt_blue(unsigned char c)
{
  if (c < 24)
    return (0);
  if (c < 56)
    return (48);
  if (c < 96)
    return (64);
  if (c < 136)
    return 128;
   return ((c < 160) ? 192 : 255);
}

static unsigned int	wt_color(t_color c)
{
  t_color		t;

  t.argb[3] = 255;
  t.argb[0] = wt_red(c.argb[0]);
  t.argb[1] = wt_green(c.argb[1]);
  t.argb[2] = wt_blue(c.argb[2]);
  return (t.full);
}

void		retro(t_bunny_pixelarray *pix)
{
  unsigned int	*pixel;
  t_color	c;
  int		i;

  i = -1;
  pixel = (unsigned int *)pix->pixels;
  while (++i < WIDTH * HEIGHT)
    {
      c.full = pixel[i];
      pixel[i] = wt_color(c);
    }
}
