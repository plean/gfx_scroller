/*
** scrolling.c for  in /home/planch_j/rendu/Info/gfx_scroller/planch_j/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Fri Mar 18 20:47:37 2016 Jean PLANCHER
** Last update Tue Mar 22 02:37:02 2016 Jean PLANCHER
*/

#include "my.h"

static t_scrolling	*init_scroll(int k)
{
  t_bunny_pixelarray	*pix;
  t_scrolling		*scroll;

  if ((scroll = bunny_malloc(sizeof(t_scrolling))) == NULL)
    return (NULL);
  if (k == 0)
    pix = bunny_load_pixelarray(PATH_P "para1.png");
  else if (k == 1)
    pix = bunny_load_pixelarray(PATH_P "para2.png");
  else
    pix = bunny_load_pixelarray(PATH_P "para3.png");
  scroll->vit = 1 * (k + 1);
  scroll->pix = bunny_new_pixelarray(WIDTH, HEIGHT);
  fox_mod_stretch(scroll->pix, pix);
  scroll->pos = 0;
  return (scroll);
}

void			scrolling(t_bunny_pixelarray *pix, int *i)
{
  static t_scrolling	**scroll = NULL;
  static unsigned int	*pixel[NB_SCROLLS];
  int			x;
  int			k;
  int			p;

  *i = (*i - 1 + WIDTH) % WIDTH;
  full_color(pix, BLACK);
  if (scroll == NULL)
    {
      if ((scroll = bunny_malloc(sizeof(t_scrolling*) * (NB_SCROLLS + 1))) == NULL)
	return ;
      k = -1;
      while (++k < NB_SCROLLS && (scroll[k] = init_scroll(k)))
	pixel[k] = (unsigned int *)scroll[k]->pix->pixels;
    }
  k = -1;
  while (++k < NB_SCROLLS && (p = -1))
    while (++p <= WIDTH / scroll[k]->pix->clipable.clip_width && (x = -1))
	while (++x < scroll[k]->pix->clipable.clip_width *
	       (scroll[k]->pix->clipable.clip_height - 1))
	    t_tekpixel(pix, scroll[k]->pos + x / scroll[k]->pix->clipable.clip_width,
      ((*i * scroll[k]->vit) + x % scroll[k]->pix->clipable.clip_width +
       p * scroll[k]->pix->clipable.clip_width) % WIDTH, pixel[k][x]);
}
