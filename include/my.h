/*
** my.h for Day09 in /home/mancie_m/rendu/rendu_J09/Piscine_C_J09/include
**
** Made by michel mancier
** Login   <mancie_m@epitech.net>
**
** Started on  Thu Oct  8 11:32:48 2015 michel mancier
** Last update Tue Mar 22 14:33:36 2016 Jean PLANCHER
*/

#ifndef MY_H_
# define MY_H_

int	my_char_isalphanum(char c);
int	my_char_isdigit(char c);
int	my_is_prime_finder(int nb);
int	my_getnbr(char *str);
int	my_getnbr_strict(char *str);
int	my_isneg(int nb);
int	my_is_prime(int nombre);
int	my_power_rec(int nb, int power);
void	my_putchar(char c);
void	my_putint(int c);
int	my_put_nbr(int nb);
int	my_putstr(char *str);
char	*my_revstr(char *str);
int	my_showmem(char *str, int size);
int	my_showstr(char *str);
void	my_sort_int_tab(int *tab, int size);
int	my_square_root(int nb);
char	*my_strcapitalize(char *str);
char	*my_strcat(char *dest, char *src);
int	my_strcmp(char *s1, char *s2);
char	*my_strcpy(char *dest, char *src);
int	my_str_isalpha(char *str);
int	my_str_islower(char *str);
int	my_str_isnum(char *str);
int	my_str_isprintable(char *str);
int	my_str_isupper(char *str);
int	my_strlen(char *str);
char	*my_strlowcase(char *str);
char	*my_strncat(char *dest, char *src, int nb);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_strncpy(char *dest, char *src, int nb);
char	*my_strstr(char *str, char *to_find);
char	*my_strupcase(char *str);
int	my_swap(int *a, int *b);
int	my_putnbr_base(int nbr, char *base);
int	my_getnbr_base(char *str, char *base);
char	*my_strdup(char *src);
char	*sum_params(int argc, char **argv);
int	my_show_wordtab(char **tab);
char	**my_str_to_wordtab(char *str);
char	**my_str_to_tab(char *str, char sep1, char sep2);
char	*convert_base(char *nbr, char *base_from, char *base_to);
char	*my_int_to_str(int nb);
int	my_intlen(int nb);
void	my_show_int_array(int *array, int len);
char	*my_getenv(char *env, char part, char sep);
int	my_envlen(char *env, char part, char sep);
char	*clean_str(char *buffer, char tofree);
void	my_free_2dtab(char **tab);
int	my_tablen(char **tab);

/*
** -------------------------------------------------
** Function Principal ----------------------------------
** -------------------------------------------------
*/

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <lapin.h>
# include <math.h>
#include <string.h>
# include "foxtek.h"
# include "jean.h"
# include "mei.h"
# include "matoux42.h"

# define WIDTH (640)
# define HEIGHT (480)
# define PATH_F "../res/font/"
# define PATH_M "../res/music/"
# define PATH_P "../res/picture/"

typedef	struct		s_star
{
  t_bunny_position	pos;
  t_bunny_position	speed;
}			t_star;

# define NB_STARS	(500)

typedef struct		s_demo
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*mask;
  int			i;
}			t_demo;

void	part1(t_demo *prog, int time);
void	part2(t_demo *prog, int time);
void	part3(t_demo *prog, int time);
void	part4(t_demo *prog, int time);
void	part5(t_demo *prog, int time);
void	part6(t_demo *prog, int time);
void	part7(t_demo *prog, int time);
void	part8(t_demo *prog, int time);
void	part9(t_demo *prog, int time);

void	init_tek_text(t_demo *prog);
void	init_tek_ani_text(t_demo *prog);
void	init_tek_part_text(t_demo *prog);
void	tunnel(t_demo *prog);
void	animated_mario(t_demo *prog, char save);
void	animated_tardis(t_demo *prog, char save);
void	init_degr_prog(t_demo *demo);
void	subres(t_demo *prog);
void	do_the_starfield(t_demo *prog);
void	degr_mob(t_demo *demo);
void	scrollfichage(t_demo *prog, int x, int y);
void	init_mystic_clock(t_demo *a);
void	my_flip(t_demo *b);

/*
** -------------------------------------------------
** Match & Nmatch ----------------------------------
** -------------------------------------------------
*/

int	match(char *s1, char *s2);
int	nmatch(char *s1, char *s2);

/*
** -------------------------------------------------
** Partie get_next_line ----------------------------
** -------------------------------------------------
*/

# ifndef READ_SIZE
#  define READ_SIZE (1024)
# endif /* !READ_SIZE */

char	*get_next_line(const int fd);

/*
** -------------------------------------------------
** Partie my_printf --------------------------------
** -------------------------------------------------
*/

# include <stdarg.h>
# include <errno.h>

# define FOREDARK "\033[30m"
# define FORERED "\033[31m"
# define FOREGREEN "\033[32m"
# define FOREYELLOW "\033[33m"
# define FOREBLUE "\033[34m"
# define FOREMAGENTA "\033[35m"
# define FORECYAN "\033[36m"
# define FOREWHITE "\033[37m"
# define FORERESET "\033[39m"
# define BACKDARK "\033[40m"
# define BACKRED "\033[41m"
# define BACKGREEN "\033[42m"
# define BACKYELLOW "\033[43m"
# define BACKBLUE "\033[44m"
# define BACKMAGENTA "\033[45m"
# define BACKCYAN "\033[46m"
# define BACKWHITE "\033[47m"
# define BACKRESET "\033[49m"
# define STYLEBOLD "\033[1m"
# define STYLEUNDERLINED "\033[4m"
# define STYLERESET "\033[0m"

int	my_printf(int mode, const char *format, ...);
int	printf_stdout(const char *format, int n, va_list *ap);
int	printf_stderr(const char *format, int n, va_list *ap);

void	errcreate(int (*fct[128])(va_list *, int));
void	create(int (*fct[128])(va_list *, int));

int	my_printchar(char c, int n);
int	my_printstr(char *str, int n);
int	my_printnbr(int nb, int mode, int n);
int	my_printnbr_base(long nb, char *base, int n);
int	my_printstroct(char *str, int n);

int	print_percent(va_list *ap, int n);
int	error_noflag(va_list *ap, int n);
int	print_char(va_list *ap, int n);
int	print_str(va_list *ap, int n);
int	print_nbr(va_list *ap, int n);
int	print_bin(va_list *ap, int n);
int	print_oct(va_list *ap, int n);
int	print_hex_min(va_list *ap, int n);
int	print_hex_maj(va_list *ap, int n);
int	print_nbr_uns(va_list *ap, int n);
int	print_ptr(va_list *ap, int n);
int	print_stroct(va_list *ap, int n);
int	stock_n(va_list *ap, int n);
int	print_errno(va_list *ap, int n);

int	my_errchar(char c, int n);
int	my_errstr(char *str, int n);
int	my_errnbr(int nb, int mode, int n);
int	my_errnbr_base(long nb, char *base, int n);
int	my_errstroct(char *str, int n);

int	err_percent(va_list *ap, int n);
int	eerror_noflag(va_list *ap, int n);
int	err_char(va_list *ap, int n);
int	err_str(va_list *ap, int n);
int	err_nbr(va_list *ap, int n);
int	err_bin(va_list *ap, int n);
int	err_oct(va_list *ap, int n);
int	err_hex_min(va_list *ap, int n);
int	err_hex_maj(va_list *ap, int n);
int	err_nbr_uns(va_list *ap, int n);
int	err_ptr(va_list *ap, int n);
int	err_stroct(va_list *ap, int n);
int	estock_n(va_list *ap, int n);
int	err_errno(va_list *ap, int n);

#endif /* !MY_H_ */
