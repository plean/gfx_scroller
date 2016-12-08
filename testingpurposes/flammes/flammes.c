/*
** flammes.c for  in /home/planch_j/rendu/Info/gfx_scroller/planch_j/flammes/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sat Mar 19 13:36:34 2016 Jean PLANCHER
** Last update Sun Mar 20 15:04:58 2016 Jean PLANCHER
*/

#include "my.h"

unsigned int	interpol(unsigned int a, unsigned int b)
{
  unsigned char alpha;

  alpha = (a >> 24);
  return (((((((a >> 16) & 255) * alpha) + (((b >> 16) & 255)
					    * (255 - alpha))) / 255) << 16)
	  + ((((((a >> 8) & 255) * alpha) + (((b >> 8) & 255)
					     * (255 - alpha))) / 255) << 8)
	  + (((((a & 255) * alpha) + ((b & 255) * (255 - alpha))) / 255)));
}

void		f_tekfull(t_flame *t)
{
  int		i;
  unsigned int	c;

  i = 0;
  while (i <= t->pix->clipable.clip_width
	 * t->pix->clipable.clip_height)
    {
      c = ((unsigned int *)t->back->pixels)[i];
      if ((c & 255) == ((c >> 8) & 255) && (c & 0xFF000000)
	  && ((c & 255) > 128))
	t->f[i] = rand() % 127;
      else if (i != 0 && i < (t->pix->clipable.clip_height - 1)
	       * t->pix->clipable.clip_width)
	t->f[i] = (t->f[i - 1] + t->f[i + 1]
		   + t->f[i + t->pix->clipable.clip_width]) * 0.334;
      ((unsigned int *)t->pix->pixels)[i] =
	interpol(t->ramp[(int)t->f[i]], c);
      i = i + 1;
    }
}

void	init_ramp(t_flame *a)
{
  int	i;

  i = -1;
  while (++i < 128)
    a->ramp[i] =
      interpol(((i * 2) << 24) + 0xFF00FFFF, 0xFF0000FF)
      | ((i * 3) << 24);
}

void	init_data(t_flame *a)
{
  int	i;

  i = 0;
  while (i < a->back->clipable.buffer.width
	 * a->back->clipable.buffer.height)
    a->f[i++] = 0;
}

void			init_flammes(t_bunny_pixelarray *pix)
{
  static unsigned int	i = 0;
  static t_flame	*my_flame = NULL;

  if (my_flame == NULL)
    {
      if ((my_flame = bunny_malloc(sizeof(t_flame))) == NULL ||
	  (my_flame->f = bunny_malloc(sizeof(char) * WIDTH * HEIGHT)) == NULL)
	return ;
      my_flame->pix = pix;
      my_flame->back = bunny_new_pixelarray(WIDTH, HEIGHT);
      fox_mod_stretch(my_flame->back, my_flame->pix);
      init_data(my_flame);
      init_ramp(my_flame);
      my_flame->pos.x = 0;
      my_flame->pos.y = 0;
      my_flame->a = 0;
    }
  i++;
  f_tekfull(my_flame);
}
