##
## Makefile for magic21 in /home/keolas_s//test/prog_elem/magic21/tools
## 
## Made by souvisay keolasy
## Login   <keolas_s@epitech.net>
## 
## Started on  Wed Sep 25 09:08:15 2013 souvisay keolasy
## Last update Wed Dec  4 00:24:57 2013 souvisay keolasy
##

NAME	= libtools.a

SRCS	= my_strlen.c \
	  my_bzero.c \
	  my_malloc.c \
	  print_error.c \
	  my_fd_func.c \
	  my_putstr.c \
	  my_memset.c \
	  my_putchar.c \
	  my_putnbr.c \
	  my_getnbr.c \
	  my_strcmp.c \
	  my_strcmp_case.c \
	  my_strncmp.c \
	  my_strdup.c \
	  my_strndup.c \
	  my_revstr.c \
	  my_stradd.c \
	  my_fd_func.c

OBJS	= $(SRCS:.c=.o)

AR	= ar rc
RANLIB	= ranlib

RM	= rm -rf

CFLAGS	= -Wall -Wextra -ansi -pedantic
CFLAGS	+=-I ../includes

DEBUG	= false


all:	$(NAME)

ifeq	(false, $(DEBUG))

%.o:	%.c
	@ $(CC) -c -o $@ $< $(CFLAGS)

$(NAME):$(OBJS)
	@ $(AR) $(NAME) $(OBJS)
	@ $(RANLIB) $(NAME)
	@ echo	"  LIB		$(NAME)"

clean:
	@ $(RM) $(OBJS)

fclean:clean
	@ $(RM) $(NAME)

else

%.o:	%.c
	@ echo	"  CC		$<"
	@ $(CC) -c -o $@ $< $(CFLAGS)

$(NAME):$(OBJS)
	$(AR) $(NAME) $(OBJS)
	$(RANLIB) $(NAME)

clean:
	$(RM) $(OBJS)

fclean:clean
	$(RM) $(NAME)

endif

re:	fclean	all


.PHONY:	all	clean	fclean