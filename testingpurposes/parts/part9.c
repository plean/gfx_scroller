/*
** part8.c for  in /home/planch_j/rendu/Info/gfx_scroller/testingpurposes/parts/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sun Mar 20 23:11:24 2016 Jean PLANCHER
** Last update Tue Mar 22 10:59:42 2016 Jean PLANCHER
*/

#include "my.h"

void		part9(t_demo *prog, int time)
{
  static int	i = 0;

  (void)time;
  (void)prog;
  if (time == -100)
    sampler(&time);
  else
    sampler(&i);
}
