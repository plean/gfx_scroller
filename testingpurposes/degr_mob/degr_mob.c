/*
** degr_mob.c for  in /home/planch_j/rendu/Info/gfx_scroller/planch_j/degr_mob/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sun Mar 20 17:39:37 2016 Jean PLANCHER
** Last update Sun Mar 20 23:09:21 2016 Jean PLANCHER
*/

#include "my.h"

static void	aff_ray_low(t_bunny_pixelarray *pix, int y, int x,
			unsigned int color)
{
  t_color	c;

  c.full = color;
  while (c.argb[3] > 0)
    {
      t_tekpixel(pix, y--, x, c.full);
      c.argb[3] -= 3;
    }
}

static void	aff_ray_up(t_bunny_pixelarray *pix, int y, int x,
			unsigned int color)
{
  t_color	c;

  c.full = color;
  while (c.argb[3] > 0)
    {
      t_tekpixel(pix, y++, x, c.full);
      c.argb[3] -= 3;
    }
}

static void	aff_ray(t_bunny_pixelarray *pix, int y, int *t,
			unsigned int color)
{
  int		x;
  int		i;

  x = -1;
  while (++x < WIDTH)
    {
      i = -(*t) / 2;
      aff_ray_low(pix, y + i, x, color);
      while (++i < (*t) / 2)
	t_tekpixel(pix, y + i, x, color);
      aff_ray_up(pix, y + i, x, color);
    }
  *t += (rand() % 2) - 1;
}

void				degr_mob(t_demo *demo)
{
  static t_bunny_pixelarray	*pix = NULL;
  static unsigned int		color[NB_RAY];
  static int			y[NB_RAY];
  static int			t[NB_RAY];
  int				i;

  if (pix == NULL)
    {
      pix = bunny_new_pixelarray(WIDTH, HEIGHT);
      fox_mod_stretch(pix, demo->pix);
      i = -1;
      while (++i < NB_RAY)
	{
	  color[i] = (255 << 24) | ((rand() + i * 100) % 0xFFFFFF);
	  y[i] = (rand() + i * 10) % HEIGHT;
	  t[i] = (rand()) % 10 - 5;
	}
    }
  fox_mod_stretch(demo->pix, pix);
  i = -1;
  while (++i < NB_RAY)
    aff_ray(demo->pix, y[i], &t[i], color[i]);
}
