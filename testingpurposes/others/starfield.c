/*
** starfield.c for Starlol in /home/mei/Perso/gfx_scroller/testingpurposes
**
** Made by Michel Mancier
** Login   <mei@epitech.net>
**
** Started on  Sun Mar 20 06:33:36 2016 Michel Mancier
** Last update Sun Mar 20 07:30:02 2016 Michel Mancier
*/

#include "my.h"

static void	set_the_stars(t_star	*stars)
{
  int	i;

  i = 0;
  while (i < NB_STARS)
    {
      stars[i].pos.x = rand() % WIDTH;
      stars[i].speed.y = (rand() % 10) + 2;
      stars[i].speed.x = -((rand() % 10) / 2) - 2;
      stars[i].pos.y = rand() % HEIGHT;
      ++i;
    }
}

static void	draw_star(t_bunny_pixelarray	*pix,
			  t_bunny_position	*pos,
			  unsigned int		col)
{
  t_bunny_position	bis1;
  t_bunny_position	bis2;
  t_bunny_position	bis3;
  t_bunny_position	bis4;

  bis1.x = pos->x - 1;
  bis1.y = pos->y;
  bis2.x = pos->x + 1;
  bis2.y = pos->y;
  bis3.x = pos->x;
  bis3.y = pos->y - 1;
  bis4.x = pos->x;
  bis4.y = pos->y + 1;
  tekpixel(pix, &bis1, col);
  tekpixel(pix, &bis2, col);
  tekpixel(pix, &bis3, col);
  tekpixel(pix, &bis4, col);
  tekpixel(pix, pos, col);
}

static void	starfield(t_bunny_pixelarray	*pix,
		  t_star		*stars,
		  unsigned int		col)
{
  t_bunny_position	pos_star;
  size_t		i;

  i = 0;
  while (i < NB_STARS)
    {
      stars[i].pos.x += stars[i].speed.x;
      if (stars[i].pos.y > HEIGHT || stars[i].pos.x > WIDTH
	  || stars[i].pos.x < 0)
	{
	  stars[i].pos.y = rand() % HEIGHT;
	  stars[i].pos.x = WIDTH;
	}
      pos_star.x = stars[i].pos.x;
      pos_star.y = stars[i].pos.y;
      draw_star(pix, &pos_star, col);
      ++i;
    }
}

void		do_the_starfield(t_demo *prog)
{
  static char	ready = 0;
  static t_star	red[NB_STARS];
  static t_star yellow[NB_STARS];
  static t_star white[NB_STARS];

  if (ready == 0)
    {
      set_the_stars(&red[0]);
      set_the_stars(&yellow[0]);
      set_the_stars(&white[0]);
      ready = 1;
    }
  starfield(prog->pix, &red[0], RED);
  starfield(prog->pix, &yellow[0], YELLOW);
  starfield(prog->pix, &white[0], WHITE);
}
