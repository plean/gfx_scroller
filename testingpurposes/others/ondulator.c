/*
** ondulator.c for scroller in /home/rigaud_b/rendu/gfx_scroller/TheDoctor/srcs
**
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.eu>
**
** Started on  Sat Mar 19 23:03:19 2016 Matthias RIGAUD
** Last update Sun Mar 20 23:24:53 2016 Michel Mancier
*/

#include <my.h>

void			my_fucking_line_of_the_death(t_bunny_position	*start,
						     int		nb,
						     t_bunny_pixelarray	*pix,
						     t_bunny_pixelarray	*pic)
{
  t_bunny_position	pos;
  t_color		*pixels;

  pos.x = start->x -1;
  pos.y = (nb + start->y) / 2;
  pixels = pic->pixels;
  while (++pos.x < pic->clipable.buffer.width + start->x)
    t_tekpixel(pix, pos.y, pos.x,
	     pixels[nb * pic->clipable.buffer.width + pos.x - start->x].full);
}

void			fucking_ondulator_of_death(t_bunny_pixelarray	*pix,
						   t_bunny_pixelarray	*pic,
						   t_bunny_position	*pos)
{
  static double		i = 0;
  t_bunny_position	start;
  int			j;

  j = - 1;
  while (++j < pic->clipable.buffer.height)
    {
      start.y = pos->y + j;
      start.x = pos->x + cos((j + i) * 0.05) * 5;
      my_fucking_line_of_the_death(&start, j, pix, pic);
    }
  i += 5;
}
