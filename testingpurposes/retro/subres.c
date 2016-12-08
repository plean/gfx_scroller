/*
** subres.c for Truc in /home/mei/Perso/gfx_scroller/testingpurposes
**
** Made by Michel Mancier
** Login   <mei@epitech.net>
**
** Started on  Sun Mar 20 05:53:41 2016 Michel Mancier
** Last update Sun Mar 20 05:57:56 2016 Michel Mancier
*/

#include "my.h"

void	subres(t_demo *prog)
{
  t_bunny_pixelarray	*retro;
  t_bunny_pixelarray	*backon;

  retro = bunny_new_pixelarray(320, 240);
  backon = bunny_new_pixelarray(640, 480);
  fox_mod_stretch(retro, prog->pix);
  fox_mod_stretch(backon, retro);
  bunny_blit(&prog->win->buffer, &backon->clipable, NULL);
  bunny_display(prog->win);
  bunny_delete_clipable(&retro->clipable);
  bunny_delete_clipable(&backon->clipable);
}
