/*
** flip_calc.c for  in /home/planch_j/rendu/Info/gfx_scroller/testingpurposes/others/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Tue Mar 22 03:04:56 2016 Jean PLANCHER
** Last update Tue Mar 22 03:15:31 2016 Jean PLANCHER
*/

#include "my.h"

static void	mult_mat(t_bunny_particle *pos,
		 double *v,
		 double rad)
{
  pos->x = v[0] * cos(rad) + v[1] * sin(rad);
  pos->z = v[0] * -sin(rad) + v[1] * cos(rad);
}

void		rotate(t_bunny_particle *pos,
		       size_t len,
		       double rad)
{
  double	*v;
  int		i;

  i = -1;
  v = bunny_malloc(sizeof(double) * 2);
  while (++i < (int)len)
    {
      v[0] = pos[i].x;
      v[1] = pos[i].z;
      mult_mat(&pos[i], v, rad);
  }
}

void	physics(t_bunny_particle *pos,
		size_t len)
{
  int	i;
  int	k;

  i = -1;
  while (++i < (int)len)
    {
      k = rand();
      pos[i].x += pos[i].x_speed;
      pos[i].y += pos[i].y_speed;
      pos[i].z += pos[i].z_speed * 10;
      if (pos[i].y < 0)
	{
	  pos[i].x = 0;
	  pos[i].y = 0;
	  pos[i].z = 0;
	  pos[i].x_speed = cos(k);
	  pos[i].z_speed = sin(k);
	  pos[i].y_speed = rand() % 100 + 1;
	}
      pos[i].y_speed *= (pos[i].y_speed < 0) ? 1.2 : 0.8;
      if (pos[i].y_speed < 0.55 && pos[i].y_speed >= 0)
	pos[i].y_speed *= -1;
    }
}
