NAME = libftprintf.a
FLAG = -Wall -Wextra -Werror
SRC = 	ft_printf.c\
		def_params.c\
		find_flags.c\
		exec_undef.c\
		exec_data.c\
		put_numbers_f.c\
		def_lengths.c\
		conversion.c\
		conversion_2.c\
		def_bitend.c\
		put_numbers.c\
		put_abs.c\
		put_symbols.c\
		put_symbols_2.c\
		customize.c\
		customize_2.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c ft_printf.h
	@gcc -c $< -o $@ $(FLAG)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re