/*
** tektext.c for TekText in /home/mei/Rendu/gfx_tekgui/tcore
**
** Made by Michel Mancier
** Login   <mei@epitech.net>
**
** Started on  Wed Feb 24 11:19:48 2016 Michel Mancier
** Last update Sun Mar 20 23:33:39 2016 Michel Mancier
*/

#include "my.h"

void		init_tek_text(t_demo *prog)
{
  static t_bunny_position	pos1 = {WIDTH / 2, HEIGHT / 2};
  static t_bunny_position	pos2 = {0, HEIGHT / 2};
  static t_font			*font = NULL;
  static t_font			*title = NULL;

  if (font == NULL || title == NULL)
    {
      if ((font = bunny_malloc(sizeof(t_font))) == NULL ||
	  (title = bunny_malloc(sizeof(t_font))) == NULL)
	return ;
      font->font = bunny_load_pixelarray(PATH_F "font.png");
      title->font = bunny_load_pixelarray(PATH_F "title.png");
      font->scale = 1;
      title->scale = 1;
      font->letter = getletterdim(font->font);
      title->letter = getletterdim(title->font);
    }
  pos1.x += 1;
  pos1.y = (int)((HEIGHT >> 1) + ((HEIGHT >> 1) * (cos(pos1.x * 0.1))) / 4);
  pos2.x += 2;
  pos2.y = (int)((HEIGHT >> 1) + ((HEIGHT >> 1) * (cos(pos2.x * 0.1))) / 6);
  tektext(prog->pix, "Keur sur vous. <3.", font, &pos1);
  tektext(prog->pix, "SUPER MARIO\n  BROS. 3", title, &pos2);
}

void	print_scale(t_bunny_pixelarray *out,
		    t_bunny_position *pos,
		    t_color *color,
		    int scale)
{
  t_bunny_position	bis;
  int	yx[2];

  yx[0] = -1;
  while (++yx[0] < scale)
    {
      yx[1] = -1;
      while (++yx[1] < scale)
	{
	  bis.x = pos->x + yx[1];
	  bis.y = pos->y + yx[0];
	  tekpixel(out, &bis, color->full);
	}
    }
}

void	draw_letter(t_bunny_pixelarray *out,
		    t_font *font,
		    char c,
		    t_bunny_position *bis)
{
  int			i;
  int			yx[2];
  t_color		color;
  t_bunny_position	pos;

  i = c * font->letter.x;
  yx[0] = -1;
  while (++yx[0] < font->letter.y)
    {
      yx[1] = -1;
      while (++yx[1] < font->letter.x)
	{
	  color.full = pl_get_color(font->font, yx[1] + i, yx[0]);
	  pos.x = bis->x + yx[1] * font->scale;
	  pos.y = bis->y + yx[0] * font->scale;
	  (pos.x < 0 ? pos.x += WIDTH : 0);
	  (pos.x >= WIDTH ? pos.x = pos.x % WIDTH : 0);
	  (pos.y < 0 ? pos.y += HEIGHT : 0);
	  (pos.y >= HEIGHT ? pos.y = pos.y % HEIGHT : 0);
	  if (color.argb[ALPHA_CMP] > 0)
	    print_scale(out, &pos, &color, font->scale);
	}
    }
}

void	tektext(t_bunny_pixelarray	*out,
		const char		*str,
		t_font			*font,
		t_bunny_position	*pos)
{
  int			i;
  t_bunny_position	bis;

  bis.x = pos->x;
  bis.y = pos->y;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
	{
	  bis.x = pos->x;
	  bis.y += font->letter.y * font->scale + 1;;
	}
      else
	{
	  draw_letter(out, font, str[i], &bis);
	  bis.x += font->letter.x * font->scale + 1;
	}
      ++i;
    }
}
