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
	mlx_destroy_image(game->mlx, game->c_image._a.img);
	mlx_destroy_image(game->mlx, game->c_image._2.img);
	mlx_destroy_image(game->mlx, game->c_image._3.img);
	mlx_destroy_image(game->mlx, game->c_image._4.img);
	mlx_destroy_image(game->mlx, game->c_image._5.img);
	mlx_destroy_image(game->mlx, game->c_image._6.img);
	mlx_destroy_image(game->mlx, game->c_image._7.img);
	mlx_destroy_image(game->mlx, game->c_image._8.img);
	mlx_destroy_image(game->mlx, game->c_image._9.img);
	mlx_destroy_image(game->mlx, game->c_image._10.img);
	mlx_destroy_image(game->mlx, game->c_image._q.img);
	mlx_destroy_image(game->mlx, game->c_image._j.img);
	mlx_destroy_image(game->mlx, game->c_image._k.img);
	free_cards(&game->cards);
	free_cards(&game->pcards);
	free_cards(&game->dcards);
	mlx_destroy_window(game->mlx, game->win);
}