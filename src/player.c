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
	put_card_window(game, card->card_img->addr, game->stats.pcardx, game->stats.pcardy);
	game->stats.pcardx += 122;
	card = select_card(game);
	card_sum += push_card(&game->pcards, card);
	if (card->name == 'A' && !game->player_is_a)
	{
		card_sum += 10;
		game->player_is_a = true;
	}
	put_card_window(game, card->card_img->addr, game->stats.pcardx, game->stats.pcardy);
	game->stats.pcardx += 122;
	return (card_sum);
}

void	player_win(t_game *game)
{
	if (game->player_sum == game->dealer_sum)
	{
		// printf("\033[0;34mDealer's cards : \033[0;37m  %i  \n", dealer_sum);
		// print_cards(game->dcards, false);
		// printf("\033[0;34mPlayer's cards : \033[0;37m  %i  \n", player_sum);
		// print_cards(game->pcards, false);
		printf("\nDRAW\n");
	}
	else
		dealers_turn(game);
	free_cards(&game->dcards);
	free_cards(&game->pcards);
}

void	player_takes(t_game *game)
{
	t_cards	*card = select_card(game);
	game->player_sum += push_card(&game->pcards, card);
	if (card->name == 'A' && game->player_sum < 11)
	{
		game->player_sum += 10;
		game->player_is_a = true;
	}
	else if (game->player_sum > 21 && game->player_is_a)
	{
		game->player_sum -= 10;
		game->player_is_a = false;
	}
	put_card_window(game, card->card_img->addr, game->stats.pcardx, game->stats.pcardy);
	game->stats.pcardx += 122;
	if (game->player_sum == 21)
	{
		game->b_dealerturn = true;
	}
}