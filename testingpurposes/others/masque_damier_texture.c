/*
** masque_damier_texture.c for scroller in /home/rigaud_b/rendu/srcs
**
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.eu>
**
** Started on  Sat Mar 19 18:07:35 2016 Matthias RIGAUD
** Last update Sun Mar 20 21:25:00 2016 Michel Mancier
*/

#include <my.h>

void		masque_damier(t_bunny_pixelarray *pix)
{
  int		i;
  t_color	*pixels;

  pixels = pix->pixels;
  i = -1;
  while (++i < pix->clipable.buffer.height * pix->clipable.buffer.width)
    if ((i / pix->clipable.buffer.width % 100 < 50 &&
	i % pix->clipable.buffer.width % 100 >= 50) ||
	(i / pix->clipable.buffer.width % 100 >= 50 &&
	i % pix->clipable.buffer.width % 100 < 50))
      pixels[i].full = RGBA_C((255 - pixels[i].argb[0]),
			      (255 - pixels[i].argb[1]),
			      (255 - pixels[i].argb[2]),
			      pixels[i].argb[3]);
}

int			give_i_pic(t_bunny_pixelarray	*pix,
				   t_bunny_pixelarray	*mask,
				   int			i,
				   t_bunny_position	*pos)
{
  return ((pos->y + i / mask->clipable.buffer.width)
	  * pix->clipable.buffer.width + pos->x
	  + i % mask->clipable.buffer.width);
}

void		masque_texture(t_bunny_pixelarray	*pix,
			       t_bunny_pixelarray	*mask,
			       t_bunny_position		*pos)
{
  int		i;
  int		j;
  t_color	*pixels;
  t_color	*pixels_m;

  pixels = pix->pixels;
  pixels_m = mask->pixels;
  i = -1;
  while (++i < mask->clipable.buffer.height * mask->clipable.buffer.width)
    if (MOYCOL(pixels_m[i].argb[0],
	       pixels_m[i].argb[1],
	       pixels_m[i].argb[2]) < 127 && (j = give_i_pic(pix, mask, i, pos)) >= 0)
      pixels[j].full = RGBA_C((255 - pixels[j].argb[0]),
			      (255 - pixels[j].argb[1]),
			      (255 - pixels[j].argb[2]),
			      pixels[j].argb[3]);
}
