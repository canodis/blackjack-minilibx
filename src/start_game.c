#include "../inc/blackjackmlx.h"

void	play(t_game *game, int player_sum, int dealer_sum);

void	free_cards(t_cards **cards)
{
	if (*cards && !(*cards)->next)
		free(*cards);
	if (*cards && (*cards)->next)
		(*cards) = (*cards)->next;
	while (*cards)
	{
		free((*cards)->prev);
		(*cards)->prev = NULL;
		*cards = (*cards)->next;
	}
	cards = NULL;
}

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

void	button_bar(t_game *game)
{
	int	imgx = 0;
	int	imgy;
	int	image_width = 290;
	// take button
	for (int x = 50; x < 340; x++)
	{
		imgy = 0;
		for (int y = 735; y < 835; y++)
		{
			game->img.addr[y * SCREENW + x] = game->buttons.take.addr[imgy * image_width + imgx];
			imgy++;
		}
		imgx++;
	}
	// stop button
	imgx = 0;
	for (int x = 390; x < 680; x++)
	{
		imgy = 0;
		for (int y = 735; y < 835; y++)
		{
			game->img.addr[y * SCREENW + x] = game->buttons.stop.addr[imgy * image_width + imgx];
			imgy++;
		}
		imgx++;
	}
	//exit button
	imgx = 0;
	for (int x = 730; x < 1020; x++)
	{
		imgy = 0;
		for (int y = 735; y < 835; y++)
		{
			game->img.addr[y * SCREENW + x] = game->buttons.exit.addr[imgy * image_width + imgx];
			imgy++;
		}
		imgx++;
	}
	//line
	for (int x = 0; x < SCREENW - 1; x++)
	{
		game->img.addr[710 * SCREENW + x] = 0xffffff;
		game->img.addr[375 * SCREENW + x] = 0xffffff;
	}
}

int	update(t_game *game)
{
	int		dealer_sum;
	int		player_sum;

	button_bar(game);
	if (check_input(game))
	{
		if(game->card_count < 10)
		{
			printf("\n\033[0;31mDestelerde kart kalmadi deste kariliyor...\033[0;37m\n");
			free_cards(&game->cards);
			init_cards(&game->cards);
			game->card_count = 104;
			sleep(3);
		}
		game->player_is_a = false;
		game->dealer_is_a = false;
		dealer_sum = dealer_first(game);
		player_sum = player_first(game);
		if (dealer_sum == 21)
		{
			dealer_win(game, player_sum, dealer_sum);
			return 0;
		}
		else if (player_sum == 21)
		{
			player_win(game, player_sum, dealer_sum);
			return 0;
		}
		play(game, player_sum, dealer_sum);
		free_cards(&game->dcards);
		free_cards(&game->pcards);
	}
	else
		printf("input yoq\n");
	// mlx_clear_window(game->mlx, game->win);
	int picy;
	int picx = 0;
	for (int x = 50; x < 141; x++)
	{
		picy = 0;
		for (int y = 50; y < 183; y++)
		{
			game->img.addr[y * SCREENW + x] = game->c_image.a.addr[picy * 92 + picx]; 
			picy++;
		}
		picx++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}

void	play(t_game *game, int player_sum, int dealer_sum)
{
	char *input = malloc(31);
	bool	is_playing = true;
	
	while (is_playing)
	{
		printf("\033[0;37mTake card : 1\nStop : 2\nExit : 3\nStats : 4\n");
		// input = readline(">");
		if (!strcmp(input, "1"))
			player_sum = player_takes(game, player_sum ,dealer_sum, &is_playing);
		else if (!strcmp(input, "2"))
		{
			is_playing = false;
			dealers_turn(game, dealer_sum, player_sum);
		}
		else if (!strcmp(input,"3"))
		{
			free_cards(&game->cards);
			exit(0);
		}
		else if (!strcmp(input,"4"))
			;// stats();
		else
			printf("\033[0;31mPlease enter a valid value !\n\033[0;37m");
		if (player_sum > 21)
		{
			printf("\n\033[0;31mYOU LOSE\033[0;37m\n");
			lose++;
			sleep(1);
			is_playing = false;
		}
	}
}