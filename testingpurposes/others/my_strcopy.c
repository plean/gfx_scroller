/*
** my_strcopy.c for  in /home/planch_j/rendu/Info/gfx_scroller/rigaud_matoux42_cookie_trollolol/srcs/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sat Mar 19 16:18:18 2016 Jean PLANCHER
** Last update Sat Mar 19 16:23:43 2016 Jean PLANCHER
*/

#include "my.h"

char	*my_strcopy(const char *str1,
		   const char *str2)
{
  char	*new_str;
  int	i;
  int	j;

  if ((new_str = bunny_malloc(sizeof(char) * (strlen(str1) + strlen(str2))))
      == NULL)
    return (NULL);
  i = -1;
  while (str1[++i])
     new_str[i] = str1[i];
  j = -1;
  while (str2[++j])
    new_str[i + j] = str2[j];
  new_str[i + j] = 0;
  return (new_str);
}
