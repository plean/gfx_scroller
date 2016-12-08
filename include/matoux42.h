/*
** matoux42.h for scroller in /home/rigaud_b/rendu/gfx_scroller/rigaud_matoux42_cookie_trollolol/include
**
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.eu>
**
** Started on  Fri Mar 18 20:48:48 2016 Matthias RIGAUD
** Last update Sun Mar 20 22:18:04 2016 Matthias RIGAUD
*/

#ifndef MATOUX_H_
# define MATOUX_H_

/*
** Include
*/

# include <lapin.h>

/*
** Defines
*/

# define	MOYCOL(x, y, z)	((x + y + z) / 3)
# define	STARTWARS	1
# define	CONTINUEWARS	0

/*
** Structures && typedef
*/

typedef struct		s_bsf
{
  double		*duration;
  double		*frequency;
  t_bunny_effect	*sound;
  int			size;
}			t_bsf;

/*
** Functions
*/

void	load_ini(char *path, t_bsf *param);
void	my_puterror(char *str, int error);
void	sampler(int *i);
char	*my_strcopy(const char *str1,
		   const char *str2);
void	masque_damier(t_bunny_pixelarray *pix);
void	masque_texture(t_bunny_pixelarray	*pix,
		       t_bunny_pixelarray	*mask,
		       t_bunny_position		*start);
void	fucking_ondulator_of_death(t_bunny_pixelarray	*pix,
				   t_bunny_pixelarray	*pic,
				   t_bunny_position	*pos);
void	plasma(t_bunny_pixelarray *pix);
void	star_wars(t_bunny_pixelarray	*pix,
		  t_bunny_pixelarray	*pic,
		  int			mode);
void	black_transit(t_bunny_pixelarray	*pix,
		      double			percent);
void	death_spiral(t_bunny_pixelarray *pixar);

/*
** End
*/

#endif /* MATOUX_H_ */
