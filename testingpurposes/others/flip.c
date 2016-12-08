/*
** flip.c for  in /home/planch_j/rendu/Info/gfx_scroller/testingpurposes/others/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Tue Mar 22 03:03:46 2016 Jean PLANCHER
** Last update Tue Mar 22 03:17:13 2016 Jean PLANCHER
*/

#include "my.h"

static void			particles(t_bunny_pixelarray *pix,
					  t_bunny_particle *pos,
					  size_t len)
{
  t_bunny_position	position;
  int			i;

  i = -1;
  while (++i < (int)len)
    {
      position.x = pos[i].x + pix->clipable.clip_width / 2;
      position.y = pix->clipable.clip_height - pos[i].y - 1;
      tekpixel(pix, &position, pos[i].color);
    }
}

void	rand_particule(t_bunny_particle *pos)
{
  int	i;

  i = rand();
  pos->x = rand() % WIDTH - WIDTH / 2;
  pos->y = rand() % HEIGHT;
  pos->z = rand() % WIDTH;
  pos->x_speed = cos(i);
  pos->z_speed = sin(i);
  pos->y_speed = rand() % 100 + 1;
  pos->color =  rand() % 0xFFFFFFFF;
}

void				my_flip(t_demo *b)
{
  static t_bunny_particle	*pos = NULL;
  int				i;

  if (pos == NULL)
    {
      if ((pos = bunny_malloc(sizeof(t_bunny_particle) * CACA)) == NULL)
	return ;
      b->i = 0;
      i = -1;
      while (++i < CACA)
	rand_particule(&pos[i]);
    }
  particles(b->pix, pos, CACA);
  rotate(pos, CACA, 0.1);
  if (b->i > 500)
    physics(pos, CACA);
  b->i++;
}
