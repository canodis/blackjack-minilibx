#include "../inc/blackjackmlx.h"

void	play(t_game *game);

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

int	update(t_game *game)
{
	int		dealer_sum;
	int		player_sum;
	bool	input;

	input = check_input(game);
	if (game->onetime)
	{
		if(game->card_count < 10)
		{
			printf("\n\033[0;31mDestelerde kart kalmadi deste kariliyor...\033[0;37m\n");
			free_cards(&game->cards);
			init_cards(&game->cards, game);
			game->card_count = 104;
			sleep(2);
		}
		game->player_is_a = false;
		game->dealer_is_a = false;
		game->dealer_sum = dealer_first(game);
		game->player_sum = player_first(game);
		if (dealer_sum == 21)
		{
			dealer_win(game);
			return 0;
		}
		else if (player_sum == 21)
		{
			player_win(game);
			return 0;
		}
		game->onetime = false;
	}
	if (input)
	{
		play(game);
	}
	mlx_clear_window(game->mlx, game->win);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	mlx_string_put(game->mlx, game->win, game->stats.dcardx + 50, game->stats.dcardy + 70, 0xffffff, ft_itoa(game->dealer_sum));
	mlx_string_put(game->mlx, game->win, game->stats.pcardx + 50, game->stats.pcardy + 70, 0xffffff, ft_itoa(game->player_sum));
	// t_cards	*tmp = game->pcards;
	// while (tmp)
	// {
	// 	printf("player cards : %c\n", tmp->name);
	// 	tmp = tmp->next;
	// }
	// tmp = game->dcards;
	// while (tmp)
	// {
	// 	printf("dealer cards : %c\n", tmp->name);
	// 	tmp = tmp->next;
	// }
}

void	play(t_game *game)
{
	if (game->b_dealerturn)
		dealers_turn(game);
	if (game->mouse_e == -1)
		return ;
	else if (game->mouse_e == 1)
	{
		player_takes(game);
		reset_mouse(game);
	}
	else if (game->mouse_e == 2)
	{
		// for second card
		put_card_window(game, game->pcards->next->card_img->addr, 172, 50);
		game->mouse_e = 31;
		game->b_dealerturn = true;
	}
	else if (game->mouse_e == 3)
	{
		free_all(game);
		exit(0);
	}
	if (game->player_sum > 21)
	{
		sleep(1);
		reset_game(game);
		game->stats.lose++;
		printf("lose\n");
	}
}
