/*
** main.c for  in /home/planch_j/rendu/Info/gfx_raytracer1/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Mon Feb 22 18:23:07 2016 Jean PLANCHER
** Last update Tue Mar 22 14:30:01 2016 Jean PLANCHER
*/

#include "my.h"

static t_bunny_response	my_exit(t_bunny_event_state state,
				t_bunny_keysym key,
				void *data)
{
  t_demo		*b;

  b = (t_demo *)data;
  (void)b;
  if (state == GO_DOWN && key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

static void	my_display(t_demo *b)
{
  bunny_blit(&(b->win->buffer), &(b->pix->clipable), NULL);
  bunny_display(b->win);
}

static t_bunny_response	refresh(void *a)
{
  t_demo		*b;
  static int		time = 0;

  b = (t_demo *)a;
  full_color(b->pix, BLACK);
  if (++time < 800)
    part1(b, time);
  else if (time < 1400)
    part2(b, time);
  else if (time < 1800)
    part3(b, time);
  else if (time < 2350)
    part4(b, time);
  else if (time < 2800)
    part5(b, time);
  else if (time < 3500)
    part6(b, time);
  else if (time < 4000)
    part7(b, time);
  else if (time < 4700)
    part8(b, time);
  else
    (time < 5400) ? init_mystic_clock(b) :my_flip(b);
  my_display(b);
  return ((time == 6500) ? EXIT_ON_SUCCESS : GO_ON);
}

int		main(void)
{
  t_demo	a;
  int		i;

  srand(time(NULL));
  a.i = 0;
  a.win = bunny_start_style(WIDTH, HEIGHT, FULLSCREEN, "test");
  a.pix = bunny_new_pixelarray(WIDTH, HEIGHT);
  full_color(a.pix, BLACK);
  bunny_blit(&(a.win->buffer), &(a.pix->clipable), NULL);
  bunny_display(a.win);
  (void)i;
  bunny_set_loop_main_function(&refresh);
  bunny_set_key_response(&my_exit);
  bunny_loop(a.win, 60, (void *)&a);
  bunny_stop(a.win);
  bunny_delete_clipable(&(a.pix->clipable));
  return (0);
}
