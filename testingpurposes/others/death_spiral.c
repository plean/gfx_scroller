/*
** death_spiral.c for scroller in /home/rigaud_b/testingpurposes/others
**
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.eu>
**
** Started on  Sun Mar 20 22:13:38 2016 Matthias RIGAUD
** Last update Sun Mar 20 23:03:02 2016 Michel Mancier
*/

#include <my.h>

int	pos_eq_cen(t_bunny_position	pos,
		   t_bunny_position	c)
{
  if (pos.x <= c.x + 2 && pos.x >= c.x - 2 &&
      pos.y <= c.y + 2 && pos.y >= c.y - 2)
    return (1);
  return (0);
}

void			print_spire(t_bunny_pixelarray	*pixar,
				    t_color		color[10],
				    int			r,
				    t_bunny_position	c)
{
  t_bunny_position	pos;
  double		i;
  int			j;
  static double		movcircle = 0;

  pos.x = 0;
  pos.y = 0;
  i = 0;
  while (!pos_eq_cen(pos, c))
    {
      j = -1;
      while (++j < 10)
	{
	  pos.x = c.x + (r - 3 * j - i / 10) * cos((i + movcircle)
						   * 2 * M_PI / 360);
	  pos.y = c.y + (r - 3 * j - i / 10) * sin((i + movcircle)
						   * 2 * M_PI / 360);
	  tekpixel(pixar, &pos, color[j].full);
	}
      pos.x = c.x + (r - 9 - i / 10) * cos((i + movcircle)
					   * 2 * M_PI / 360);
      pos.y = c.y + (r - 9 - i / 10) * sin((i + movcircle) * 2 * M_PI / 360);
      i += 0.1;
    }
  movcircle += 30;
}

void			death_spiral(t_bunny_pixelarray *pixar)
{
  t_bunny_position	c;
  t_color		color[10];
  int			i;
  int			r;

  full_color(pixar, BLACK);
  i = -1;
  while (++i < 10)
    color[i].full = rand() % 0xFFFFFFFF;
  i = -1;
  c.x = pixar->clipable.buffer.width / 2;
  c.y = pixar->clipable.buffer.height / 2;
  r =  pixar->clipable.buffer.width;
  print_spire(pixar, color, r, c);
}
