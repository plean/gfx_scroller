/*
** jean.h for  in /home/planch_j/rendu/Info/gfx_scroller/planch_j/include/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Fri Mar 18 20:06:45 2016 Jean PLANCHER
** Last update Tue Mar 22 03:08:10 2016 Jean PLANCHER
*/

#ifndef	JEAN_H_
# define JEAN_H_

# include <lapin.h>

# define NB_SCROLLS (3)
# define GREATER(x, y) ((x > y) ? x : y)
# define SS_WALL (0xFF000000)
# define LR_START (20)
# define NB_RAY (10)
# define CACA (1000)

typedef struct		s_scrolling
{
  t_bunny_pixelarray	*pix;
  int			pos;
  int			vit;
}			t_scrolling;

typedef struct          s_flame
{
  t_bunny_pixelarray    *pix;
  t_bunny_pixelarray	*back;
  char                  *f;
  int                   ramp[128];
  t_bunny_position      pos;
  int                   a;
}                       t_flame;

typedef struct		s_point
{
  t_bunny_position	*coord;
}			t_point;

typedef struct	s_fonc
{
  double	coef;
  double	ord;
}		t_fonc;

typedef struct		s_bunny_circle
{
  t_bunny_position	position;
  double		radius;
  unsigned int		color;
}			t_bunny_circle;

typedef struct		s_bunny_particle
{
  double		x;
  double		y;
  double		z;
  double		x_speed;
  double		y_speed;
  double		z_speed;
  unsigned int		color;
}			t_bunny_particle;

void		scrolling(t_bunny_pixelarray *pix, int *i);
void		full_color(t_bunny_pixelarray *pix, unsigned int color);
void		t_tekpixel(t_bunny_pixelarray *pix,
		   int y, int x,
		   unsigned int color);
unsigned int	pl_get_color(t_bunny_pixelarray *pix,
			     int x,
			     int y);
void		init_flammes(t_bunny_pixelarray *pix);
void		init_soft_shadow(t_bunny_pixelarray *pix);
void		check_line(t_bunny_pixelarray *pix,
			   const t_bunny_position *pos, int e);
void		pl_tekline(t_bunny_pixelarray *pix, t_bunny_position *pos,
			   int e);
void		rotate(t_bunny_particle *pos,
		       size_t len,
		       double rad);
void		physics(t_bunny_particle *pos,
		size_t len);

#endif /* !JEAN_H_ */
