/*
** sprite2.c for Sprite2 in /home/mei/Perso/gfx_scroller/testingpurposes
**
** Made by Michel Mancier
** Login   <mei@epitech.net>
**
** Started on  Sun Mar 20 18:28:54 2016 Michel Mancier
** Last update Sun Mar 20 23:25:59 2016 Michel Mancier
*/

#include "my.h"

static void	print_rainbow(t_bunny_pixelarray *pix,
			      t_bunny_pixelarray *rainbow,
			      t_bunny_position *offset,
			      int state)
{
  t_bunny_position	pos;
  int			x;
  int			y;
  int			scale;
  t_color		color;

  scale = state * 80;
  y = -1;
  while (++y < 35)
    {
      x = -1;
      while (++x < 80)
	{
	  color.full = pl_get_color(rainbow, scale + x, y);
	  pos.x = 50 + offset->x + x;
	  pos.y = 50 + offset->y + y;
	  (pos.x < 0 ? pos.x += WIDTH : 0);
	  (pos.x >= WIDTH ? pos.x = pos.x % WIDTH : 0);
	  (pos.y < 0 ? pos.y += HEIGHT : 0);
	  (pos.y >= HEIGHT ? pos.y = pos.y % HEIGHT : 0);
	  if (color.argb[ALPHA_CMP] > 0)
	    tekpixel(pix, &pos, color.full);
	}
    }
}

static void	print_tardis(t_bunny_pixelarray *pix,
			     t_bunny_pixelarray *tardis,
			     t_bunny_position *offset,
			     int state)
{
  t_bunny_position	pos;
  int			x;
  int			y;
  int			scale;
  t_color		color;

  scale = state * 54;
  y = -1;
  while (++y < 96)
    {
      x = -1;
      while (++x < 54)
	{
	  color.full = pl_get_color(tardis, scale + x, y);
	  pos.x = 130 + offset->x + x;
	  pos.y = 25 + offset->y + y;
	  (pos.x < 0 ? pos.x += WIDTH : 0);
	  (pos.x >= WIDTH ? pos.x = pos.x % WIDTH : 0);
	  (pos.y < 0 ? pos.y += HEIGHT : 0);
	  (pos.y >= HEIGHT ? pos.y = pos.y % HEIGHT : 0);
	  if (color.argb[ALPHA_CMP] > 0)
	    tekpixel(pix, &pos, color.full);
	}
    }
}

static t_bunny_position	fctend(t_bunny_position offset,
			       t_bunny_pixelarray *tardis,
			       t_bunny_pixelarray *rainbow,
			       char save)
{
  offset.x = offset.x % WIDTH;
  if (save == 1)
    {
      bunny_delete_clipable(&tardis->clipable);
      bunny_delete_clipable(&rainbow->clipable);
    }
  return (offset);
}

void	animated_tardis(t_demo *prog, char save)
{
  static int			frame = 0;
  static int			state = 0;
  static t_bunny_pixelarray	*tardis = NULL;
  static t_bunny_pixelarray	*rainbow = NULL;
  static t_bunny_position      	offset = {0, 0};

  offset.x += 3;
  offset.y = (int)(((HEIGHT >> 1) + ((HEIGHT >> 1) * (cos(offset.x * 0.1))) / 8)
		   - 125);
  if (tardis == NULL && rainbow == NULL)
    {
      tardis = bunny_load_pixelarray(PATH_P "tardis.png");
      rainbow = bunny_load_pixelarray(PATH_P "rainbow.png");
    }
  frame += 1;
  if (frame == 40)
    {
      state += 1;
      if (state == 2)
	state = 0;
      frame = 0;
    }
  print_rainbow(prog->pix, rainbow, &offset, state);
  print_tardis(prog->pix, tardis, &offset, state);
  offset = fctend(offset, tardis, rainbow, save);
}
