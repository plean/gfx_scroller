/*
** part8.c for  in /home/planch_j/rendu/Info/gfx_scroller/testingpurposes/parts/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sun Mar 20 23:11:24 2016 Jean PLANCHER
** Last update Tue Mar 22 02:10:05 2016 Jean PLANCHER
*/

#include "my.h"

void		part8(t_demo *prog, int time)
{
  (void)time;
  full_color(prog->pix, BLACK);
  tunnel(prog);
  if (time > 3200)
    scrollfichage(prog, WIDTH / 2 - 100, HEIGHT - 350);
}
