/*
** tektext.c for TekText in /home/mei/Rendu/gfx_tekgui/tcore
**
** Made by Michel Mancier
** Login   <mei@epitech.net>
**
** Started on  Wed Feb 24 11:19:48 2016 Michel Mancier
** Last update Sun Mar 20 22:15:24 2016 Michel Mancier
*/

#include "my.h"

static void	print_scale(t_bunny_pixelarray *out,
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

static void	draw_letter(t_bunny_pixelarray *out,
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

static int	getletter(void)
{
  static int	limit = 0;
  static int	frame = 0;

  frame += 1;
  if (frame == 8)
    {
      frame = 0;
      if (limit < 100)
	limit += 1;
    }
  return (limit);
}

void	tektext_part3(t_bunny_pixelarray	*out,
		      const char		*str,
		      t_font		*font,
		      t_bunny_position	*pos)
{
  int			i;
  int			limit = 0;
  t_bunny_position	bis;

  limit = getletter();
  bis.x = pos->x;
  bis.y = pos->y;
  i = 0;
  while (str[i] != '\0' && i < limit)
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
