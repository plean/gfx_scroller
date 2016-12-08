/*
** testmain.c for maintestor in /home/rigaud_b/rendu/gfx_scroller/
**
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.eu>
**
** Started on  Fri Mar 18 20:48:09 2016 Matthias RIGAUD
** Last update Tue Mar 22 10:59:55 2016 Jean PLANCHER
*/

#include "my.h"

void		change(const size_t *to_change, int to_put)
{
  size_t	*techdep;

  techdep = (size_t *)(to_change);
  *techdep = to_put;
}

void			sampler(int *i)
{
  static char		*path = PATH_M "imperial.bsf";
  static t_bsf		*param = NULL;

  if (param == NULL)
    {
      if ((param = bunny_malloc(sizeof(t_bsf))) == NULL)
	return ;
      load_ini(path, param);
    }
  if (*i == -100)
    {
      bunny_delete_sound(&param->sound->sound);
      return ;
    }
  bunny_sound_pitch(&param->sound->sound, param->frequency[*i] / 220);
  bunny_sound_play(&param->sound->sound);
  usleep(param->duration[*i] * 900);
  bunny_sound_stop(&param->sound->sound);
  *i = (*i + 1) % param->size;
}
