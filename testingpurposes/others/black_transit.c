/*
** black_transit.c for scroller in /home/rigaud_b/rendu/gfx_scroller/testingpurposes/others
**
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.eu>
**
** Started on  Sun Mar 20 21:51:38 2016 Matthias RIGAUD
** Last update Sun Mar 20 21:57:31 2016 Matthias RIGAUD
*/

#include <my.h>

void		black_transit(t_bunny_pixelarray	*pix,
			      double			percent)
{
  int		i;
  t_color	*pixels;

  pixels = pix->pixels;
  i = -1;
  while (++i < pix->clipable.buffer.height * pix->clipable.buffer.width)
    {
      pixels[i].argb[0] = pixels[i].argb[0] / 100.0 * (100.0 - percent);
      pixels[i].argb[1] = pixels[i].argb[1] / 100.0 * (100.0 - percent);
      pixels[i].argb[2] = pixels[i].argb[2] / 100.0 * (100.0 - percent);
    }
}
