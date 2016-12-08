/*
** plasma.c for scroller in /home/rigaud_b/rendu/gfx_scroller/TheDoctor/srcs
**
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.eu>
**
** Started on  Sun Mar 20 09:21:54 2016 Matthias RIGAUD
** Last update Sun Mar 20 23:05:19 2016 Matthias RIGAUD
*/

#include <my.h>

void	adj_color(t_color *new_color, double adj[4], t_color *color, int i)
{
  new_color->argb[0] = color->argb[0] + i * adj[0];
  new_color->argb[1] = color->argb[1] + i * adj[1];
  new_color->argb[2] = color->argb[2] + i * adj[2];
  new_color->argb[3] = color->argb[3] + i * adj[3];
}

void            set_palette(t_color *pal, t_color color[2], int y, int dist)
{
  double        adj[4];
  int           i;

  adj[0] = (double)(color[1].argb[0] - color[0].argb[0]) / dist;
  adj[1] = (double)(color[1].argb[1] - color[0].argb[1]) / dist;
  adj[2] = (double)(color[1].argb[2] - color[0].argb[2]) / dist;
  adj[3] = (double)(color[1].argb[3] - color[0].argb[3]) / dist;
  i = y + 1;
  while (--i > y - dist)
    adj_color(&pal[i], adj, &color[0], y - i);
  return ;
}

void		my_palette(t_color *pal)
{
  t_color	color[2];

  color[0].full = 0xFFFFFFFF;
  color[1].full = 0xFFFF0000;
  set_palette(pal, color, 256, 64);
  color[0].full = 0xFFFF0000;
  color[1].full = 0xFFFFFFFF;
  set_palette(pal, color, 192, 64);
  color[0].full = 0xFFFFFFFF;
  color[1].full = 0xFFFF0000;
  set_palette(pal, color, 128, 64);
  color[0].full = 0xFFFF0000;
  color[1].full = 0xFFFFFFFF;
  set_palette(pal, color, 64, 65);
}

void			plasma(t_bunny_pixelarray *pix)
{
  static int		adder = 0;
  static t_color	pal[257];
  t_bunny_position	pos;
  double		i;
  double		j;
  int			color;

  if (!adder)
    my_palette(pal);
  j = - 1;
  while (++j < pix->clipable.buffer.width && (i = -1))
    {
      pos.y = j;
      while (++i < pix->clipable.buffer.width && (pos.x = i) >= 0)
        {
	  color = (int)((128.0 + (128.0 * sin(pos.x / 16.0))
			 + 128.0 + (128.0 * sin(pos.y / 8.0))
			 + 128.0 + (128.0 * sin((pos.x + pos.y) / 16.0))
			 + 128.0 + (128.0 * sin(sqrt((double)(pos.x * pos.x
							      + pos.y * pos.y))
						/ 8.0))) / 4);
          tekpixel(pix, &pos, pal[(color + adder) % 250].full);
        }
    }
  adder += 5;
}
