CC			= gcc -g
MINILIBX	= mlx/libmlx.a
NAME		= blackjack
SRCS 		= $(shell find src -name "*.c")
OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(MINILIBX) $(OBJS)
	$(CC) $(OBJS) -o $(NAME) mlx/libmlx.a -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -lreadline

$(MINILIBX):
	make -C mlx
	@echo "MINILIBX compile edildi !"

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	@make clean -C mlx

re: fclean all
