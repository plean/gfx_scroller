/*
** mystic_clock.c for  in /home/planch_j/rendu/Info/gfx_scroller/testingpurposes/others/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Tue Mar 22 02:42:58 2016 Jean PLANCHER
** Last update Tue Mar 22 02:55:22 2016 Jean PLANCHER
*/

#include "my.h"

static int	if_in_array(t_bunny_pixelarray *pix, int x, int y)
{
  if (x < 0 || y < 0 ||
      x >= pix->clipable.clip_width || y >= pix->clipable.clip_width)
    return (0);
  return (1);
}

static void		t_tekcircle(t_bunny_pixelarray *pix,
				    t_bunny_position *pos,
				    double radius,
				    unsigned int color)
{
  t_bunny_position	pos2;
  t_color		t;
  double		i;
  double		j;

  t.full = color;
  i = -radius;
  while (i <= radius)
    {
      j = -radius;
      while (j <= radius)
	{
	  if (i * i + j * j < radius * radius &&
	      i * i + j * j > radius * radius - 2 * radius &&
	      if_in_array(pix, pos->x + i, pos->y + j))
	    {
	      pos2.x = pos->x + i;
	      pos2.y = pos->y + j;
	      tekpixel(pix, &pos2, t.full);
	    }
	  j++;
	}
      i++;
    }
}

static void		mystic_clock(t_bunny_pixelarray *pix,
				     const t_bunny_circle *circle,
				     double angle,
				     size_t depth)
{
  t_bunny_circle	test;
  t_color		c;

  test.position = circle->position;
  t_tekcircle(pix, &test.position, circle->radius, circle->color);
  test.position.x += (cos(-angle) * circle->radius);
  test.position.y += (sin(-angle) * circle->radius);
  test.radius = circle->radius / 2;
  c.full = circle->color;
  c.argb[0] = 255 - c.argb[0];
  c.argb[1] = 255 - c.argb[1];
  c.argb[2] = 255 - c.argb[2];
  test.color = c.full;
  if (depth > 1)
    mystic_clock(pix, &test, -angle * 2, --depth);
}

void	init_mystic_clock(t_demo *a)
{
  static t_bunny_circle	circle;
  static double		angle = 0;

  if (angle == 0)
    {
      circle.position.x = WIDTH / 2;
      circle.position.y = HEIGHT / 2;
      circle.radius = WIDTH / 10;
      circle.color = RED;
      angle = 1;
    }
  mystic_clock(a->pix, &circle, angle, 5);
  mystic_clock(a->pix, &circle, angle - M_PI, 5);
  angle += 0.05;
  if (angle > 3 * M_PI)
    angle -= 2 * M_PI;
}
