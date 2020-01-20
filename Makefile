NAME = libftprintf.a
FLAG = -Wall -Wextra -Werror
SRC = 	ft_printf.c\
		def_params.c\
		exec_undef.c\
		find_flags.c\
		execution_f.c\
		def_lengths.c\
		conversion.c\
		put_numbers.c\
		put_symbols.c
OBJ = $(SRC:.c=.o)

TMP = main.c ##### DELL IT <<<<<<<<<<<<<
TMPO = $(TMP:.c=.o) #### DELL IT <<<<<<<<<<<<

all: $(NAME)

$(NAME): $(OBJ) $(TMPO) ### FIX IT <<<<<<<<<<<
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@gcc -o 00 $(NAME) $(TMPO) #### DELL IT <<<<<<<<<<

%.o: %.c ft_printf.h
	@gcc -c $< -o $@ $(FLAG)

clean:
	@rm -f $(OBJ)
	@rm -f $(TMPO) #### DELL IT <<<<<<<<<<<<

fclean: clean
	@rm -f $(NAME)
	@rm -f 00 #### DELL IT <<<<<<<<<<<<

re: fclean all

.PHONY: all clean fclean re