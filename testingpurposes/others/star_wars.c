/*
** star_wars.c for scroller in /home/rigaud_b/rendu/gfx_scroller/TheDoctor/srcs
**
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.eu>
**
** Started on  Sun Mar 20 18:45:35 2016 Matthias RIGAUD
** Last update Sun Mar 20 23:04:54 2016 Michel Mancier
*/

#include "my.h"

int	get_i(int j, int k, double size, t_bunny_pixelarray *pic)
{
  return ((int)(j * pic->clipable.buffer.width + k
		* pic->clipable.buffer.width / size));
}

void			star_wars(t_bunny_pixelarray	*pix,
				  t_bunny_pixelarray	*pic,
				  int			mode)
{
  static int		i;
  t_bunny_position	pos;
  double		size;
  int			j;
  int			k;

  if (mode == STARTWARS)
    i = 1;
  pos.y = pix->clipable.buffer.height - i - 1;
  j = -1;
  while (++pos.y < pix->clipable.buffer.height
	 && ++j < pic->clipable.buffer.height)
    {
      size = (pos.y / (double)(pix->clipable.buffer.height - 50))
	* (double)(pic->clipable.buffer.width);
      pos.x = (pix->clipable.buffer.width - size) / 2 - 1;
      k = -1;
      if (pos.y > pix->clipable.buffer.height / 6)
	while (++k < size && ++pos.x >= -500)
	  t_tekpixel(pix, pos.y, pos.x, ((unsigned int *)
					 pic->pixels)[get_i(j, k, size, pic)]);
    }
  i++;
}
