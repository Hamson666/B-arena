##
## Makefile for zappy in /home/de-mat_a/rendu/PSU_2014_zappy/client/libs
## 
## Made by François De Matos
## Login   <de-mat_a@epitech.net>
## 
## Started on  Fri Jun 12 01:11:04 2015 François De Matos
## Last update Fri Jun 12 01:11:05 2015 François De Matos
##

NAME	=	libmy.so

SRCS	=	utils.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Wextra -Werror -Wall

all:		$(NAME)

$(OBJS):
		gcc -c -fPIC $(SRCS)

$(NAME):	$(OBJS)
		gcc $(OBJS) -shared -o $(NAME) $(CFLAGS)

clean:		
		rm -rf $(OBJS)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all
