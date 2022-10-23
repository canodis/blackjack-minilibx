#include "../inc/blackjackmlx.h"


void	reset_mouse(t_game *game)
{
	game->mouse_x = 0;
	game->mouse_y = 0;
}

bool	check_input(t_game *game)
{
	if (game->mouse_x >= 50 && game->mouse_x <= 340 && game->mouse_y >= 735 && game->mouse_y <= 835)
	{
		game->game_event = 1;
		reset_mouse(game);
		return (true);
	}
	else if (game->mouse_x >= 390 && game->mouse_x <= 680 && game->mouse_y >= 735 && game->mouse_y <= 835)
	{
		game->game_event = 2;
		reset_mouse(game);
		return (true);

	}
	else if (game->mouse_x >= 730 && game->mouse_x <= 1020 && game->mouse_y >= 735 && game->mouse_y <= 835)
	{
		game->game_event = 3;
		reset_mouse(game);
		return (true);
	}
	game->game_event = -1;
	return (false);
}
