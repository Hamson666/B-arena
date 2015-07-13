##
## Makefile for Zappy in /home/de-mat_a/rendu/PSU_2014_zappy/server
## 
## Made by François De Matos
## Login   <de-mat_a@epitech.net>
## 
## Started on  Mon Jun  1 10:18:48 2015 François De Matos
## Last update Thu Jul  9 00:10:32 2015 François De Matos
##

CC	=	gcc
RM	=	rm -rf

NAME	=	../zappy_server

SRCSDIR	=	srcs/
INCSDIR	=	incs/
OBJSDIR	=	objs/
LIBSDIR	=	libs/

SRCS	=	$(SRCSDIR)main.c \
		$(SRCSDIR)game.c \
		$(SRCSDIR)connection.c \
		$(SRCSDIR)list_teams.c \
		$(SRCSDIR)map.c \
		$(SRCSDIR)objects.c \
		$(SRCSDIR)players.c \
		$(SRCSDIR)queue.c \
		$(SRCSDIR)verify_args.c \
		$(SRCSDIR)opt.c \
		$(SRCSDIR)opt2.c \
		$(SRCSDIR)fill_tabs.c \
		$(SRCSDIR)cmds1.c \
		$(SRCSDIR)cmds2.c \
		$(SRCSDIR)cmds3.c \
		$(SRCSDIR)voir.c \
		$(SRCSDIR)broadcast.c \
		$(SRCSDIR)printing.c \
		$(SRCSDIR)init_plyr.c \
		$(SRCSDIR)cmds4.c \
		$(SRCSDIR)incantation1.c \
		$(SRCSDIR)incantation2.c \
		$(SRCSDIR)consum1.c \
		$(SRCSDIR)consum2.c \
		$(SRCSDIR)drop_ressources1.c \
		$(SRCSDIR)drop_ressources2.c

OBJS	=	$(SRCS:$(SRCSDIR)%.c=$(OBJSDIR)%.o)

CFLAGS	=	-Wall -Wextra -Werror

IFLAGS	=	-I./$(INCSDIR)
IFLAGS	+=	-I./$(LIBSDIR)

LDFLAGS	=	-L./$(LIBSDIR) -lmy -Wl,-rpath=$(PWD)/$(LIBSDIR)
LDFLAGS	+=	-lm

all:		$(NAME)

lib:
		@echo ""
		@echo "Compiling lib : "
		@make -C ./libs
		@echo "[ OK ]"

$(OBJSDIR)%.o:	$(SRCSDIR)%.c
		@mkdir -p $(OBJSDIR)
		@$(CC) -c -o $@ $< $(IFLAGS) $(CFLAGS) 2> ./.tmp || echo -n ""
		@if [ -s ./.tmp ]; then \
			echo "Compiling $< : [ Error ]" ; \
			cat ./.tmp ; rm -r ./.tmp ; exit 1; \
		else \
			echo "Compiling $< : [ OK ]" ; \
			rm -r ./.tmp ; \
		fi

$(NAME):	lib $(OBJS)
		@$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) $(IFLAGS) $(CFLAGS)
		@echo ""
		@echo "Compilation OK"

clean:
		@echo -n "Erasing objects : "
		@$(RM) $(OBJS)
		@$(RM) $(OBJSDIR)
		@echo "[ OK ]"
		@echo -n "Eragins lib objects : "
		@make clean -C ./libs
		@echo "[ OK ]"

fclean:		clean
		@echo -n "Erasing binary : "
		@$(RM) $(NAME)
		@echo "[ OK ]"
		@echo -n "Eragins lib binary : "
		@make fclean -C ./libs
		@echo "[ OK ]"

re:		fclean all
