##
## Makefile for  in /home/planch_j/rendu/Info/gfx_raytracer1/src/
##
## Made by Jean PLANCHER
## Login   <planch_j@epitech.net>
##
## Started on  Mon Feb 22 18:22:55 2016 Jean PLANCHER
## Last update Tue Mar 22 11:05:38 2016 Jean PLANCHER
##

CC	= cc

RM     	= rm -f

LIBS    = -L/home/${USER}/.froot/lib/ \
          -llapin \
          -lsfml-audio \
          -lsfml-graphics \
          -lsfml-window \
          -lsfml-system \
          -lstdc++ \
          -ldl \
          -lm \
	  -L../lib \
	  -lmy \
	  -lmccloud


CFLAGS 	+= -W -Wall -Wextra -Werror
CFLAGS  += -I./include/ -I../include/ -I/home/${USER}/.froot/include/ -O3

NAME  	= mother_scroller

SRCS   	=	main.c \
		scrolling/scrolling.c \
		others/tekfunctions.c \
		sprites/sprite.c \
		others/tekpixel.c \
		retro/subres.c \
		others/starfield.c \
		tektext/anitext.c \
		others/scrollfichage.c \
		sprites/sprite2.c \
		tektext/tektext_part.c \
		tektext/tektext.c \
		tektext/tektext_part1.c \
		tektext/tektext_part2.c \
		tektext/tektext_part3.c \
		others/masque_damier_texture.c \
		others/my_strcopy.c \
		others/ondulator.c \
		others/plasma.c \
		sound/init_sound.c \
		sound/load_sound.c \
		degr_mob/degr_mob.c \
		degr_prog/degr_prog.c \
		flammes/flammes.c \
		retro/retro.c \
		tunnel/tunnel.c \
		parts/part1.c \
		parts/part2.c \
		parts/part3.c \
		parts/part4.c \
		parts/part5.c \
		parts/part6.c \
		parts/part7.c \
		parts/part8.c \
		parts/part9.c \
		others/black_transit.c \
		others/star_wars.c \
		others/death_spiral.c \
		others/mystic_clock.c \
		others/flip.c \
		others/flip_calc.c

OBJS   	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)  $(LIBS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean:   clean
	$(RM) $(NAME)

re: fclean all
