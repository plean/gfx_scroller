/*
** part1.c for Part1 in /home/mei/Perso/gfx_scroller/testingpurposes/parts
**
** Made by Michel Mancier
** Login   <mei@epitech.net>
**
** Started on  Sun Mar 20 21:32:39 2016 Michel Mancier
** Last update Sun Mar 20 23:25:47 2016 Michel Mancier
*/

#include "my.h"

void	part3(t_demo *prog, int time)
{
  static t_bunny_pixelarray	*tardis = NULL;
  static t_bunny_position	pos = {20, 20};

  if (tardis == NULL)
      tardis = bunny_load_pixelarray(PATH_P "tardis2.png");
  (void)time;
  death_spiral(prog->pix);
  fucking_ondulator_of_death(prog->pix, tardis, &pos);
  if (time == 1799)
    {
      animated_tardis(prog, 1);
      bunny_delete_clipable(&tardis->clipable);
    }
  else
    animated_tardis(prog, 0);
}
