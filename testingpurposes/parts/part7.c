/*
** part7.c for  in /home/planch_j/rendu/Info/gfx_scroller/testingpurposes/parts/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sun Mar 20 23:01:33 2016 Jean PLANCHER
** Last update Tue Mar 22 01:57:10 2016 Jean PLANCHER
*/

#include "my.h"

void		part7(t_demo *prog, int time)
{
  (void)time;
  full_color(prog->pix, BLACK);
  degr_mob(prog);
}
