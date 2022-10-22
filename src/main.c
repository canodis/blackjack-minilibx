#include "../inc/blackjackmlx.h"

int	lose;
int	win;

void	print_cards(t_game *game)
{
	while (game->cards)
	{
		printf("value : %d  ||  name : %c\n", game->cards->value, game->cards->name);
		game->cards = game->cards->next;
	}
}

int	key_events(int key_code, t_game *game)
{
	if (key_code == 65307)
	{
		mlx_destroy_window(game->mlx, game->win);
		free_cards(&game->cards);
		exit(0);
	}
	return (0);
}

int	mouse_event(int event, int x, int y,t_game *game)
{
	game->mouse_x = x;
	game->mouse_y = y;
	game->mouse_e = event;
}

int main(int ac, char **av)
{
	t_game	game;
	init_all(&game);
	mlx_key_hook(game.win, key_events, &game);
	mlx_loop_hook(game.mlx, update, &game);
	mlx_mouse_hook(game.win, mouse_event, &game);
	mlx_loop(game.mlx);
}
