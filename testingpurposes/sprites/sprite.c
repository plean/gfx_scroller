/*
** sprite.c for Sprite in /home/mei/Projets/gfx_scroller/mancie_m
**
** Made by Michel Mancier
** Login   <mei@epitech.net>
**
** Started on  Sat Mar 19 16:03:37 2016 Michel Mancier
** Last update Sun Mar 20 23:19:03 2016 Michel Mancier
*/

#include "my.h"

static void     print_luigi(t_bunny_pixelarray  *pix,
			    t_bunny_pixelarray  *luigi,
			    int			state)
{
  t_bunny_position	pos;
  int			x;
  int			y;
  int			scale;
  t_color		color;

  scale = state * 115;
  y = -1;
  while (++y < 190)
    {
      x = -1;
      while (++x < 115)
	{
	  color.full = pl_get_color(luigi, scale + x, y);
	  pos.x = 485 + x;
	  pos.y = 280 + y;
	  if (color.argb[ALPHA_CMP] > 0)
	    tekpixel(pix, &pos, color.full);
	}
    }
}

static void	print_mario(t_bunny_pixelarray	*pix,
			    t_bunny_pixelarray	*mario,
			    int			state)
{
  t_bunny_position	pos;
  int			x;
  int			y;
  int			scale;
  t_color		color;

  scale = state * 115;
  y = -1;
  while (++y < 170)
    {
      x = -1;
      while (++x < 115)
	{
	  color.full = pl_get_color(mario, scale + x, y);
	  pos.x = 20 + x;
	  pos.y = 300 + y;
	  if (color.argb[ALPHA_CMP] > 0)
	    tekpixel(pix, &pos, color.full);
	}
    }
}

void	animated_mario(t_demo *prog, char save)
{
  static int			frame = 0;
  static int			state = 0;
  static t_bunny_pixelarray	*mario = NULL;
  static t_bunny_pixelarray	*luigi = NULL;

  if (mario == NULL && luigi == NULL)
    {
      mario = bunny_load_pixelarray(PATH_P "mario.png");
      luigi = bunny_load_pixelarray(PATH_P "luigi.png");
    }
  frame += 1;
  if (frame == 4)
    {
      state += 1;
      if (state == 12)
	state = 0;
      frame = 0;
    }
  print_mario(prog->pix, mario, state);
  print_luigi(prog->pix, luigi, state);
  (save == 1 ? bunny_delete_clipable(&mario->clipable) : 0);
  (save == 1 ? bunny_delete_clipable(&luigi->clipable) : 0);
}
