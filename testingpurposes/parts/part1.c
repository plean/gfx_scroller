/*
** part1.c for Part1 in /home/mei/Perso/gfx_scroller/testingpurposes/parts
**
** Made by Michel Mancier
** Login   <mei@epitech.net>
**
** Started on  Sun Mar 20 21:32:39 2016 Michel Mancier
** Last update Sun Mar 20 23:20:22 2016 Michel Mancier
*/

#include "my.h"

static void	starwarstext(t_bunny_pixelarray *pix)
{
  static t_bunny_position	pos = {20, 20};
  static t_font			*font = NULL;

  if (font == NULL)
    {
      if ((font = bunny_malloc(sizeof(t_font))) == NULL)
	return ;
      font->font = bunny_load_pixelarray(PATH_F "font.png");
      font->scale = 2;
      font->letter = getletterdim(font->font);
    }
  tektext(pix, "Des Tek1 remplis\nde determination\n\
   ont choisis\n  de faire face\na l'adversite et\n\
  de vaincre le\n  puissant mais\n  non invincible\nModule\n   d'Infographie.",
	  font, &pos);
}

void	part1(t_demo *prog, int time)
{
  static t_bunny_pixelarray	*starwars = NULL;

  if (starwars == NULL)
    {
      starwars = bunny_new_pixelarray(WIDTH, HEIGHT);
      full_color(starwars, 0);
      starwarstext(starwars);
      star_wars(prog->pix, starwars, CONTINUEWARS);
    }
  do_the_starfield(prog);
  if (time > 0)
    star_wars(prog->pix, starwars, CONTINUEWARS);
  if (time == 599)
    bunny_delete_clipable(&starwars->clipable);
  //  scrollfichage(prog, 100, 100);
}
