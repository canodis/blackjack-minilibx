#include "../inc/blackjackmlx.h"

bool	check_input(t_game *game)
{
	if (game->mouse_x >= 50 && game->mouse_x <= 340 && game->mouse_y >= 735 && game->mouse_y <= 835)
	{
		game->mouse_e = 1;
		return (true);
	}
	else if (game->mouse_x >= 390 && game->mouse_x <= 680 && game->mouse_y >= 735 && game->mouse_y <= 835)
	{
		game->mouse_e = 2;
		return (true);

	}
	else if (game->mouse_x >= 730 && game->mouse_x <= 1020 && game->mouse_y >= 735 && game->mouse_y <= 835)
	{
		game->mouse_e = 3;
		return (true);
	}
	game->mouse_e = -1;
	return (false);
}
