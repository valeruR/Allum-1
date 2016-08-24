##
## Makefile for allum1 in /home/valeru_r/rendu/Prog_Elem/Allum-1/CPE_2015_Allum1
## 
## Made by valeru_r
## Login   <valeru_r@epitech.net>
## 
## Started on  Tue Feb  9 14:26:44 2016 valeru_r
## Last update Wed Jun  1 21:19:17 2016 Reever Valerus
##

CC		=	gcc

RM		=	rm -f

NAME		=	allum1

DIR_SRCS	=	srcs

SRCS		=	$(DIR_SRCS)/lib_functions.c \
			$(DIR_SRCS)/lib_functions2.c \
			$(DIR_SRCS)/main_function.c \
			$(DIR_SRCS)/opponent.c \
			$(DIR_SRCS)/get_next_line.c \
			$(DIR_SRCS)/tab_functions.c \
			$(DIR_SRCS)/main.c

OBJS		=	$(SRCS:.c=.o)

CFLAGS		=	-Iinclude

all		:	$(NAME)

$(NAME)		:	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re
