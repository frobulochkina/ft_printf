NAME = libftprintf.a

SRC =	ft_parsing.c\
		ft_parsing_two.c\
		ft_printf_optional.c\
		ft_printf_optional_easy.c\
		ft_printf_utils.c\
		ft_printf.c\
		ft_c.c\
		ft_d_i.c\
		ft_p.c\
		ft_procent.c\
		ft_s.c\
		ft_u.c\
		ft_x.c\
		ft_big_x.c
OBJ = $(SRC:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ) $(OBJTYPE) ft_printf.h
	ar rc $(NAME) $(OBJ)

bonus:	$(OBJ) ft_printf.h
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
