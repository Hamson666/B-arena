##
## Makefile for zappy in /home/de-mat_a/rendu/PSU_2014_zappy/server/libs
## 
## Made by François De Matos
## Login   <de-mat_a@epitech.net>
## 
## Started on  Mon Jun  1 15:49:42 2015 François De Matos
## Last update Tue Jun 30 20:06:41 2015 François De Matos
##

NAME	=	libmy.so

SRCS	=	utils.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Wextra -Werror -Wall

LDFLAGS	=	-lm

all:		$(NAME)

$(OBJS):
		gcc -c -fPIC $(SRCS)

$(NAME):	$(OBJS)
		gcc $(OBJS) -shared -o $(NAME) $(CFLAGS) $(LDFLAGS)

clean:		
		rm -rf $(OBJS)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all
