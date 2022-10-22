#include "../inc/blackjackmlx.h"

int	player_first(t_game *game)
{
	int		card_sum = 0;
	t_cards	*card;

	card = select_card(game);
	card_sum += push_card(&game->pcards, card);
	if (card->name == 'A')
	{
		card_sum += 10;
		game->player_is_a = true;
	}
	card = select_card(game);
	card_sum += push_card(&game->pcards, card);
	if (card->name == 'A' && !game->player_is_a)
	{
		card_sum += 10;
		game->player_is_a = true;
	}
	printf("\033[0;34mPlayer's cards : \033[0;37m  %i  \n", card_sum);
	// print_cards(game->pcards, false);
	return (card_sum);
}

void	player_win(t_game *game, int player_sum, int dealer_sum)
{
	sleep(1);
	if (player_sum == dealer_sum)
	{
		printf("\033[0;34mDealer's cards : \033[0;37m  %i  \n", dealer_sum);
		// print_cards(game->dcards, false);
		printf("\033[0;34mPlayer's cards : \033[0;37m  %i  \n", player_sum);
		// print_cards(game->pcards, false);
		printf("\nDRAW\n");
		sleep(1);
	}
	else
		dealers_turn(game, dealer_sum, player_sum);
	free_cards(&game->dcards);
	free_cards(&game->pcards);
}

int	player_takes(t_game *game, int player_sum, int dealer_sum, bool *is_playing)
{
	t_cards	*card = select_card(game);
	player_sum += push_card(&game->pcards, card);
	if (card->name == 'A' && player_sum < 11)
	{
		player_sum += 10;
		game->player_is_a = true;
	}
	else if (player_sum > 21 && game->player_is_a)
	{
		player_sum -= 10;
		game->player_is_a = false;
	}
	printf("\033[0;34mDealer's cards : \033[0;37m\n");
	// print_cards(game->dcards, true);
	printf("\033[0;34mPlayer's cards : \033[0;37m  %i  \n", player_sum);
	// print_cards(game->pcards, false);
	if (player_sum == 21)
	{
		dealers_turn(game, dealer_sum, player_sum);
		*is_playing = false;
	}
	return (player_sum);
}