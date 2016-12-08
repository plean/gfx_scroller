/*
** tekpixel.c for Tekpixel in /home/mei/Rendu/gfx_tekgui
**
** Made by Michel Mancier
** Login   <mancie_m@epitech.net>
**
** Started on  Wed Feb 24 10:32:58 2016 Michel Mancier
** Last update Sat Mar 19 05:56:42 2016 Michel Mancier
*/

#include <lapin.h>
#include "mei.h"

void	tekpixel(t_bunny_pixelarray	*pix,
		 t_bunny_position	*pos,
		 unsigned int		color)
{
  if (pos->y < pix->clipable.buffer.height && pos->y >= 0 &&
      pos->x < pix->clipable.buffer.width && pos->x >= 0)
    ((unsigned int *)(pix->pixels))[(pos->y *
				     pix->clipable.clip_width) + pos->x] = color;
}
