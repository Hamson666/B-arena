##
## Makefile for B-arena in /home/de-mat_a/rendu/B-arena/server-cpp
## 
## Made by François De Matos
## 
## Started on  Mon Jul 13 23:54:30 2015 François De Matos
## Last update Tue Jul 14 00:43:03 2015 François De Matos
##

CXX	=	g++

NAME	=	b-arena-server

SRCSDIS	=	srcs/
INCSDIR	=	incs/
OBJSDIR	=	objs/

SRCS	=	$(SRCSDIR)main.cpp	\
		$(SRCSDIR)Core.cpp

OBJS	=	$(SRCS:$(SRCSDIR)%.cpp=$(OBJSDIR)%.o)

LDFLAGS	=	-I./$(INCSDIR)

all:		$(NAME)

$(OBJSDIR)%.o:	$(SRCSDIR)%.cpp
		@mkdir -p objs
		@$(CXX) -c -o $@ $< $(LDFLAGS) 2> ./.tmp || echo -n ""
		@if [ -s ./.tmp ]; then \
			echo "$< :	[ Error ]"
			cat ./.tmp ; rm -rf ./.tmp ; exit 1; \
		else \
			echo "$< :	[ Ok ]"
			cat ./.tmp ; rm -rf ./.tmp ; exit 1; \
		fi

$(NAME):	$(OBJS)
		@echo -n "Compiling :		"
		@$(CXX) $(OBJS) -o $(NAME) $(LDFLAGS)
		@echo "[ Ok ]"

clean:
		@echo -n "Erasing objects..	"
		@rm -rf $(OBJS)
		@rm -rf $(OBJSDIR)
		@echo "[ Ok ]"

fclean:		clean
		@echo -n "Erasing binary..	"
		@rm -rf $(NAME)
		@echo "[ Ok ]"

re:		fclean all
