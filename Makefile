NAME = so_long

LIBFT_PATH = ./libft_2.0

LIBFT = $(LIBFT_PATH)/libft.a

SRC_DIR = ./src/
SRCS = $(addprefix $(SRC_DIR),\
		so_long.c		\
		init_map.c		\
		so_long_utils.c)

CC = gcc

FLAGS = -Wall -Wextra -Werror -g3

OBJS = $(SRCS:$(SRC_DIR)%.c=$(SRC_DIR)%.o)

INCLUDE = -L $(LIBFT_PATH) -lft

$(NAME) : $(OBJS)
	make -C $(LIBFT_PATH)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(INCLUDE)

$(OBJS): $(SRC_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	make clean -C $(LIBFT_PATH)
	rm -rf $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
