/*
** degr_prog.c for  in /home/planch_j/rendu/Info/gfx_scroller/planch_j/degr_prog/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sun Mar 20 13:37:14 2016 Jean PLANCHER
** Last update Sun Mar 20 17:27:04 2016 Jean PLANCHER
*/

#include "my.h"

static void	degr_prog(t_demo *demo, t_bunny_pixelarray *pix)
{
  t_color	c;
  int		i;

  i = -1;
  while (++i < WIDTH * HEIGHT)
    {
      c.full = pl_get_color(pix, i % WIDTH, i / WIDTH);
      c.argb[0] = (c.argb[0] + demo->i) % 255;
      c.argb[1] = (c.argb[1] + demo->i) % 255;
      c.argb[2] = (c.argb[2] + demo->i) % 255;
      t_tekpixel(demo->pix, i / WIDTH, i % WIDTH, c.full);
    }
}

void				init_degr_prog(t_demo *demo)
{
  static t_bunny_pixelarray	*pix = NULL;

  if (pix == NULL)
    pix = bunny_new_pixelarray(WIDTH, HEIGHT);
  //fox_mod_stretch(pix, bunny_load_pixelarray("../mancie_m/" "tardis.png"));
  fox_mod_stretch(pix, demo->pix);
  degr_prog(demo, pix);
}
