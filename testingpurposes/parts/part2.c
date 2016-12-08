/*
** part1.c for Part1 in /home/mei/Perso/gfx_scroller/testingpurposes/parts
**
** Made by Michel Mancier
** Login   <mei@epitech.net>
**
** Started on  Sun Mar 20 21:32:39 2016 Michel Mancier
** Last update Sun Mar 20 23:16:26 2016 Michel Mancier
*/

#include "my.h"

static void	sub_text_talk(t_demo *prog, int time, t_font **font)
{
  static t_bunny_position	pos[3] = {{30, 30}, {60, 60}, {90, 120}};

  tektext_part1(prog->pix, "Tous au Tardis!", font[0], &pos[0]);
  if (time > 950)
    tektext_part2(prog->pix, "Hackons l'Infographie!", font[2], &pos[1]);
  if (time > 1160)
    tektext_part3(prog->pix, "Mother\n    Scroller!", font[1], &pos[2]);
}

static void	tek_text_talk(t_demo *prog, int time)
{
  static t_font			*font[3] = {NULL, NULL, NULL};

  if (font[0] == NULL || font[1] == NULL || font[2] == NULL)
    {
      if (((font[0] = bunny_malloc(sizeof(t_font))) == NULL) ||
	  ((font[1] = bunny_malloc(sizeof(t_font))) == NULL) ||
	  ((font[2] = bunny_malloc(sizeof(t_font))) == NULL))
	return ;
      font[0]->font = bunny_load_pixelarray(PATH_F "font.png");
      font[1]->font = bunny_load_pixelarray(PATH_F "font_j.png");
      font[2]->font = bunny_load_pixelarray(PATH_F "font_r.png");
      font[0]->scale = 1;
      font[1]->scale = 2;
      font[2]->scale = 1;
      font[0]->letter = getletterdim(font[0]->font);
      font[1]->letter = getletterdim(font[1]->font);
      font[2]->letter = getletterdim(font[2]->font);
    }
  sub_text_talk(prog, time, &font[0]);
}
void	part2(t_demo *prog, int time)
{
  (void)time;
  do_the_starfield(prog);
  if (time == 1399)
    animated_mario(prog, 1);
  else
    animated_mario(prog, 0);
  tek_text_talk(prog, time);
}
