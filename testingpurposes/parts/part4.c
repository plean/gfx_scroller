/*
** part4.c for  in /home/planch_j/rendu/Info/gfx_scroller/testingpurposes/parts/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sun Mar 20 22:52:37 2016 Jean PLANCHER
** Last update Tue Mar 22 02:39:47 2016 Jean PLANCHER
*/

#include "my.h"

void	part4(t_demo *prog, int time)
{
  if (time == 1800)
    prog->i = 0;
  scrolling(prog->pix, &prog->i);
  init_tek_text(prog);
  if (time > 2000)
    init_degr_prog(prog);
}
