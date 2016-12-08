/*
** part5.c for scroller in /home/rigaud_b/rendu/gfx_scroller/testingpurposes/parts
**
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.eu>
**
** Started on  Sun Mar 20 23:11:24 2016 Matthias RIGAUD
** Last update Sun Mar 20 23:35:55 2016 Matthias RIGAUD
*/

#include "my.h"

void				part5(t_demo *prog, int time)
{
  static t_bunny_pixelarray	*plasm;
  static t_bunny_pixelarray	*tardis;
  t_bunny_position		pos;

  (void)time;
  pos.x = 42;
  pos.y = 42;
  if (!plasm)
    {
      tardis = bunny_load_pixelarray(PATH_P "tardis2.png");
      plasm = bunny_new_pixelarray(150, 150);
    }
  fucking_ondulator_of_death(prog->pix, tardis, &pos);
  plasma(plasm);
  pos.x = 420;
  pos.y = 420;
  fucking_ondulator_of_death(prog->pix, plasm, &pos);
  masque_damier(prog->pix);
  pos.x = 42;
  pos.y = 42;
  masque_texture(prog->pix, plasm, &pos);
}
