# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/18 02:28:40 by gusalves          #+#    #+#              #
#    Updated: 2021/08/18 02:28:40 by gusalves         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SOURCES			=	ft_atoi.c ft_atoli.c ft_bzero.c ft_calloc.c ft_isalnum.c
SOURCES			+=	ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c
SOURCES			+=	ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c
SOURCES			+=	ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c
SOURCES			+=	ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c
SOURCES			+=	ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c
SOURCES			+=	ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c
SOURCES			+=	ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c
SOURCES			+=	ft_tolower.c ft_toupper.c get_next_line.c

SOURCES_BONUS	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c
SOURCES_BONUS	+=	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c
SOURCES_BONUS	+=	ft_lstiter.c ft_lstmap.c

OBJECTS			= 	$(SOURCES:.c=.o)

OBJECTS_BONUS	= 	$(SOURCES_BONUS:.c=.o)

NAME			=	libft.a

CC				=	gcc
AR				=	ar
RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror -g
ARFLAGS 		=	rcs

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJECTS)
				$(AR) $(ARFLAGS) $(NAME) $(OBJECTS)

bonus:			$(NAME) $(OBJECTS_BONUS)
				$(AR) $(ARFLAGS) $(NAME) $(OBJECTS_BONUS)

runw:
				bash warmachine/grademe.sh -u -ob

runww:
				bash Libftest/grademe.sh -u -ob

clean:
				$(RM) $(OBJECTS) $(OBJECTS_BONUS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re bonus
