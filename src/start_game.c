#include "../inc/blackjackmlx.h"

int	dcardx = 50;
int	dcardy = 50;

bool	onetime = true;

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
	button_bar(game);
	if (onetime)
	{
		if(game->card_count < 10)
		{
			printf("\n\033[0;31mDestelerde kart kalmadi deste kariliyor...\033[0;37m\n");
			free_cards(&game->cards);
			init_cards(&game->cards, game);
			game->card_count = 104;
			sleep(3);
		}
		game->player_is_a = false;
		game->dealer_is_a = false;
		game->dealer_sum = dealer_first(game);
		game->player_sum = player_first(game);
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
		onetime = false;
	}
	if (input)
	{
		
		play(game);
		// free_cards(&game->dcards);
		// free_cards(&game->pcards);
	}
	else
		printf("input yoq\n");

	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}

void	play(t_game *game)
{
	bool	this_turn = true;

	if (game->game_event == 1)
		game->player_sum = player_takes(game, game->player_sum , game->dealer_sum, &this_turn);
	else if (game->game_event == 2)
	{
		this_turn = false;
		dealers_turn(game, game->dealer_sum, game->player_sum);
	}
	else if (game->game_event == 3)
	{
		free_all(game);
		exit(0);
	}
	if (game->player_sum > 21)
	{
			lose++;
		sleep(1);
		this_turn = false;
	}
}