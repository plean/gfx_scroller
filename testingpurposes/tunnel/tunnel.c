/*
** tunnel.c for  in /home/planch_j/rendu/Info/gfx_scroller/planch_j/tunnel/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sun Mar 20 15:25:37 2016 Jean PLANCHER
** Last update Sun Mar 20 17:10:43 2016 Jean PLANCHER
*/

#include "my.h"

static void		pl_tekcircle(t_bunny_pixelarray *pix,
				     t_bunny_position *pos,
				     double radius)
{
  double		i;
  double		angle;
  t_bunny_position	pos2;

  i = 0;
  while (i < 360)
    {
      angle = i * M_PI / 180;
      pos2.x = pos->x + cos(angle) * radius;
      pos2.y = pos->y + sin(angle) * radius;
      t_tekpixel(pix, pos2.y, pos2.x, 0xFFFFFFFF);
      i = i + 5;
    }
}

static void	tunnel_suite(t_bunny_pixelarray *pix, int i)
{
  const t_bunny_position	*pos1;
  t_bunny_position		pos2;

  pos1 = bunny_get_mouse_position();
  //full_color(pix, BLACK);
  pos2.x = pos1->x + ((WIDTH / 2 - pos1->x) * i * 2) / (WIDTH - 120);
  pos2.y = pos1->y + ((HEIGHT / 2 - pos1->y) * i * 2) / (HEIGHT - 120);
  pl_tekcircle(pix, &pos2, LR_START + i);
  pl_tekcircle(pix, &pos2, LR_START + (i << 1));
  pl_tekcircle(pix, &pos2, LR_START + (i << 2));
  pl_tekcircle(pix, &pos2, LR_START + (i << 3));
  pl_tekcircle(pix, &pos2, LR_START + (i << 4));
  pl_tekcircle(pix, &pos2, LR_START + (i << 5));
  pl_tekcircle(pix, &pos2, LR_START + (i << 6));
}

void			tunnel(t_demo *demo)
{
  static t_bunny_pixelarray	*pix = NULL;

  if (pix == NULL)
    {
      pix = bunny_new_pixelarray(WIDTH, HEIGHT);
      fox_mod_stretch(pix, demo->pix);
    }
  fox_mod_stretch(demo->pix, pix);
  tunnel_suite(demo->pix, demo->i);
  demo->i += 1 + demo->i / 100;
  if (demo->i > 10)
    demo->i = 1;
}
