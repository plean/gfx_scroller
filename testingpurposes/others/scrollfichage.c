/*
** scrollfichage.c for Scroller in /home/mei/Perso/gfx_scroller/testingpurposes
**
** Made by Michel Mancier
** Login   <mei@epitech.net>
**
** Started on  Sun Mar 20 14:38:47 2016 Michel Mancier
** Last update Sun Mar 20 20:29:50 2016 Michel Mancier
*/

#include "my.h"

static void	scrollprinter(t_bunny_pixelarray *pix,
			      t_bunny_position *pos,
			      unsigned int color)
{
  while (pos->x < WIDTH && pos->y > 0)
    {
      tekpixel(pix, pos, color);
      pos->x += 1;
      pos->y -= 1;
    }
}

static int	aff_scrolling(t_bunny_pixelarray *pix,
			      t_bunny_pixelarray *img,
			      t_bunny_position *pos,
			      int line)
{
  t_color		color;
  t_bunny_position	bis;
  int			printed;

  printed = 0;
  while (line >= 0 && pos[1].x >= 0)
    {
      while (pos[1].x >= 0)
	{
	  color.full = pl_get_color(img, pos[1].x, pos[1].y);
	  if (color.argb[ALPHA_CMP] > 0)
	    {
	      bis.x = (pos[0].x + pos[1].x) % WIDTH;
	      bis.y = (pos[0].x + pos[1].y) % WIDTH;
	      tekpixel(pix, &bis, color.full);
	      (line == 0 ? scrollprinter(pix, &bis, color.full) : 0);
	    }
	  pos[1].x -= 1;
	}
      pos[1].y -= 1;
      pos[1].x = img->clipable.buffer.width;
      line -= 1;
      printed += 1;
    }
  return (printed);
}

void			scrollfichage(t_demo *prog,
				      int x, int y)
{
  static int			frame= 0;
  static t_bunny_pixelarray	*img = NULL;
  static int			line = 0;
  t_bunny_position		pos[2];

  frame += 1;
  if (img == NULL)
    img = bunny_load_pixelarray(PATH_P "mawio.png");
  pos[0].x = x;
  pos[0].y = y;
  pos[1].x = img->clipable.buffer.width - 1;
  pos[1].y = img->clipable.buffer.height - 1;
  line = aff_scrolling(prog->pix, img, &pos[0], line);
  if (frame == 1)
    {
      line += 1;
      frame = 0;
    }
  line -= 1;
}
