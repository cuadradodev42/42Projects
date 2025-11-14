NAME = push_swap
SOURCES = \
	push_swap.c\
	parse.c\
	algorithms.c\
	ft_aux.c\
	setup.c\
	push.c\
	swap.c\
	rotates.c\
	rev_rotates.c\
	radix_aux.c\

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

Libft_dir = Lib_ft
Libft = $(Libft_dir)/libft.a

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(Libft):
	@echo "compilando libft"
	make -C $(Libft_dir)

$(NAME): $(Libft) $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) -L$(Libft_dir) -lft

%.o: %.c push_swap.h
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	make -C $(Libft_dir) clean
	rm -f $(OBJECTS)

fclean: clean
	make -C $(Libft_dir) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
