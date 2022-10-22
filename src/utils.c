#include "../inc/blackjackmlx.h"

int	random_range(int start, int end)
{
	struct timeval	t;
	time_t			seed;
	gettimeofday(&t, NULL);
	seed = t.tv_sec + t.tv_usec;
	srand(seed);
	return ((rand() % (end - start + 1)) + start);
}

bool	charcmp(char a, char b)
{
	if (a == b)
		return true;
	return false;
}

void	free_all(t_game *game)
{
	mlx_destroy_image(game->mlx, game->buttons.take.img);
	mlx_destroy_image(game->mlx, game->buttons.stop.img);
	mlx_destroy_image(game->mlx, game->buttons.exit.img);
	mlx_destroy_image(game->mlx, game->img.img);
	free_cards(&game->cards);
	free_cards(&game->pcards);
	free_cards(&game->dcards);
	mlx_destroy_window(game->mlx, game->win);
}