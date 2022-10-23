#include "../inc/blackjackmlx.h"

int	lose = 0;
int	win = 0;
int	cardw = 92;
int	cardh = 134;

int	key_events(int key_code, t_game *game)
{
	if (key_code == 65307)
	{
		free_all(game);
		exit(0);
	}
	return (0);
}

int	mouse_events(int event, int x, int y,t_game *game)
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
	mlx_mouse_hook(game.win, mouse_events, &game);
	mlx_loop(game.mlx);
}
