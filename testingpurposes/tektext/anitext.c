/*
** tektext.c for TekText in /home/mei/Rendu/gfx_tekgui/tcore
**
** Made by Michel Mancier
** Login   <mei@epitech.net>
**
** Started on  Wed Feb 24 11:19:48 2016 Michel Mancier
** Last update Sun Mar 20 14:32:07 2016 Michel Mancier
*/

#include "my.h"

void		init_tek_ani_text(t_demo *prog)
{
  static t_bunny_position	pos1 = {100, 100};
  static t_font			*font = NULL;

  if (font == NULL)
    {
      if ((font = bunny_malloc(sizeof(t_font))) == NULL)
	return ;
      font->font = bunny_load_pixelarray(PATH_F "animated.png");
      font->scale = 2;
      font->letter = getletterdim(font->font);
    }
  pos1.x += 3;
  pos1.y += 3;
  tek_anitext(prog->pix, "SCROLLER", font, &pos1);
}

void	print_ani_scale(t_bunny_pixelarray *out,
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

static int	gettextframe(void)
{
  static int	frame = 0;
  static int	scale = 0;

  frame += 1;
  if (frame == 30)
    {
      frame = 0;
      scale += 1;
      if (scale == 6)
	scale = 0;
    }
  return (scale * 32);
}
void	draw_ani_letter(t_bunny_pixelarray *out,
			t_font *font,
			char c,
			t_bunny_position *bis)
{
  int			i;
  int			j;
  int			yx[2];
  t_color		color;
  t_bunny_position	pos;

  i = c * font->letter.x;
  j = gettextframe();
  yx[0] = -1;
  while (++yx[0] < font->letter.y)
    {
      yx[1] = -1;
      while (++yx[1] < font->letter.x)
	{
	  color.full = pl_get_color(font->font, yx[1] + i, yx[0] + j);
	  pos.x = bis->x + yx[1] * font->scale;
	  pos.y = bis->y + yx[0] * font->scale;
	  (pos.x < 0 ? pos.x += WIDTH : 0);
	  (pos.x >= WIDTH ? pos.x = pos.x % WIDTH : 0);
	  (pos.y < 0 ? pos.y += HEIGHT : 0);
	  (pos.y >= HEIGHT ? pos.y = pos.y % HEIGHT : 0);
	  if (color.argb[ALPHA_CMP] > 0)
	    print_ani_scale(out, &pos, &color, font->scale);
	}
    }
}

void	tek_anitext(t_bunny_pixelarray	*out,
		    const char		*str,
		    t_font		*font,
		    t_bunny_position	*pos)
{
  int			i;
  t_bunny_position	bis;

  bis.x = pos->x;
  bis.y = pos->y;
  i = 0;
  if (font->letter.y != 32)
    font->letter.y = 32;
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
	{
	  bis.x = pos->x;
	  bis.y += font->letter.y * font->scale + 1;;
	}
      else
	{
	  draw_ani_letter(out, font, str[i], &bis);
	  bis.x += font->letter.x * font->scale + 1;
	}
      ++i;
    }
}
