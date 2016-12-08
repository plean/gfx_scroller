/*
** load_sound.c for  in /home/planch_j/rendu/Info/gfx_scroller/rigaud_matoux42_cookie_trollolol/srcs/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sat Mar 19 16:02:55 2016 Jean PLANCHER
** Last update Sat Mar 19 21:41:27 2016 Jean PLANCHER
*/

#include "my.h"

void	my_puterror(char *str, int nb)
{
  fprintf(stderr, "%s\n", str);
  exit(nb);
}

int	check_nb(const char *nb)
{
  int	i;
  int	point;

  point = 0;
  i = -1;
  while (nb[++i])
    if (nb[i] < 48 || nb[i] > 57)
      {
	if (nb[i] == '.' && !point && i)
	  {
	    point = 1;
	    continue;
	  }
	return (0);
      }
  return (1);
}

void			load_ini(char	*path,
				 t_bsf	*param)
{
  t_bunny_ini		*file;
  int			i;
  t_bunny_ini_scope	*scope;
  const char		*nb;

  if (!(file = bunny_load_ini(path)) ||
      !(scope = bunny_ini_next(file, bunny_ini_first(file))) ||
      !(param->sound = bunny_load_effect
	(my_strcopy(PATH_M, bunny_ini_scope_get_field(scope, "sample", 0)))))
    my_puterror("Error load ini", 42);
  param->size = -1;
  while (bunny_ini_scope_get_field(scope, "duration", ++param->size));
  if (!(param->duration = malloc(param->size * sizeof(double))) ||
      !(param->frequency = malloc(param->size * sizeof(double))))
    my_puterror("Error Malloc", 42);
  i = -1;
  while ((nb = bunny_ini_scope_get_field(scope, "duration", ++i)))
    if (check_nb(nb))
      param->duration[i] = atof(nb);
  i = -1;
  while ((nb = bunny_ini_scope_get_field(scope, "frequency", ++i)))
    if (check_nb(nb))
      param->frequency[i] = atof(nb);
  bunny_delete_ini(file);
}
