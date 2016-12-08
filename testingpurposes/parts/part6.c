/*
** part6.c for  in /home/planch_j/rendu/Info/gfx_scroller/testingpurposes/parts/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sun Mar 20 23:01:29 2016 Jean PLANCHER
** Last update Sun Mar 20 23:06:31 2016 Jean PLANCHER
*/

#include "my.h"

void		part6(t_demo *prog, int time)
{
  static int	i = 0;

  (void)time;
  if (i == 0)
    {
      i = 1;
      fox_mod_stretch(prog->pix, bunny_load_pixelarray(PATH_P "fireflower.png"));
    }
  init_flammes(prog->pix);
}
