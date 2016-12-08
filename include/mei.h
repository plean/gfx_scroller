/*
** mei.h for Mei in /home/mei/Projets/gfx_scroller/mancie_m
**
** Made by Michel Mancier
** Login   <mei@epitech.net>
**
** Started on  Sat Mar 19 05:30:59 2016 Michel Mancier
** Last update Sun Mar 20 22:14:32 2016 Michel Mancier
*/

#ifndef	MEI_H_
# define MEI_H_

# include <lapin.h>

# define PATH "../res/picture/"

typedef struct          s_font
{
  t_bunny_pixelarray    *font;
  t_bunny_position      letter;
  int                   scale;
}                       t_font;

void			full_color(t_bunny_pixelarray	*pix,
				   unsigned int		color);
t_bunny_position	getletterdim(t_bunny_pixelarray *font);
void			tekpixel(t_bunny_pixelarray	*pix,
				 t_bunny_position	*pos,
				 unsigned int		color);
void			tek_anitext(t_bunny_pixelarray	*out,
				    const char		*str,
				    t_font		*font,
				    t_bunny_position	*pos);
void			tektext(t_bunny_pixelarray	*out,
				const char		*str,
				t_font			*font,
				t_bunny_position	*pos);
void			tektext_part(t_bunny_pixelarray	*out,
				     const char		*str,
				     t_font		*font,
				     t_bunny_position	*pos);
void			tektext_part1(t_bunny_pixelarray *out,
				      const char	 *str,
				      t_font		*font,
				      t_bunny_position	*pos);
void			tektext_part2(t_bunny_pixelarray *out,
				      const char	 *str,
				      t_font		*font,
				      t_bunny_position	*pos);
void			tektext_part3(t_bunny_pixelarray *out,
				      const char	 *str,
				      t_font		*font,
				      t_bunny_position	*pos);
unsigned int		get_color(t_bunny_pixelarray *pix, int x, int y);

#endif /* !MEI_H_ */
