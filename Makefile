##
## Makefile for midnight in /home/keolas_s//test/systeme_unix/midnight
## 
## Made by souvisay keolasy
## Login   <keolas_s@epitech.net>
## 
## Started on  Tue Nov 19 19:00:54 2013 souvisay keolasy
## Last update Fri Dec 13 09:03:35 2013 souvisay keolasy
##

SRCSDIR	= sources
INCSDIR	= includes
BINSDIR	= bin
BONUDIR	= bonus

NAME	= $(BINSDIR)/midnight

SRCS	= $(SRCSDIR)/main.c \
	  $(SRCSDIR)/newitem.c \
	  $(SRCSDIR)/sort_item.c \
	  $(SRCSDIR)/mkbox.c \
	  $(SRCSDIR)/printfield.c \
	  $(SRCSDIR)/get_file.c \
	  $(SRCSDIR)/arrow.c \
	  $(SRCSDIR)/move.c \
	  $(SRCSDIR)/clear_screen.c \
	  $(SRCSDIR)/printw_error.c \
	  $(SRCSDIR)/exec_sh.c

OBJS	= $(SRCS:.c=.o)


LIB	= tools

CFLAGS	= -Wall -Wextra -ansi -std=c89 -pedantic 
CFLAGS	+= -I $(INCSDIR) -I /usr/include/ncurses
LDFLAGS	+= -ltools -L ./tools  -lmenu -lpanel -lncurses

DEBUG	= false

ifeq	($(DEBUG), true)
	CFLAGS	+= -ggdb3
	CC	= clang
else
	CC	= gcc
	CLFAGS	+= -O2
endif

RM	= rm -fr

all: $(NAME)

%.o: %.c
	@ echo	"  CC		$<"
	@ $(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJS)
	@ echo	"  BIN		$(NAME)"
	@ $(CC) -o $(NAME) $(OBJS)  $(LDFLAGS)

lib:
	@ make re -C $(LIB)

clean:
	@ echo	"  RM		$(OBJS)"
	@ $(RM) $(OBJS)

fclean:	clean
	@ echo	"  RM		$(NAME)"
	@ $(RM) $(NAME)

re:	fclean	lib	all

.PHONY: clean	fclean	lib all
