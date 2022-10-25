#include "../inc/blackjackmlx.h"

int	dealer_first(t_game *game)
{
	int		card_sum = 0;
	t_cards	*card = select_card(game);
	card_sum += push_card(&game->dcards, card);
	if (card->name == 'A')
	{
		card_sum += 10;
		game->dealer_is_a = true;
	}
	put_card_window(game, card->card_img->addr, game->stats.dcardx ,game->stats.dcardy);
	game->stats.dcardx += 122;
	card = select_card(game);
	card_sum += push_card(&game->dcards, card);
	
	if (card->name == 'A' && !game->dealer_is_a)
	{
		card_sum += 10;
		game->dealer_is_a = true;
	}
	put_card_window(game, game->c_image._back.addr, game->stats.dcardx ,game->stats.dcardy);
	game->stats.dcardx += 122;
	return (card_sum);
}

void		dealer_takes(t_game *game)
{
	t_cards	*card = select_card(game);
	game->dealer_sum += push_card(&game->dcards, card);
	put_card_window(game, card->card_img->addr, game->stats.dcardx, game->stats.dcardy);
	game->stats.dcardx += 122;
	if (card->name == 'A' && game->dealer_sum < 11)
	{
		game->dealer_sum += 10;
		game->dealer_is_a = true;
	}
	else if (game->dealer_sum > 21 && game->dealer_is_a)
	{
		game->dealer_sum -= 10;
		game->dealer_is_a = false;
	}
}

void	dealer_win(t_game *game)
{
	// printf("\033[0;34mDealer's cards : \033[0;37m  %i  \n", dealer_sum);
	// print_cards(game->dcards, false);
	// printf("\033[0;34mPlayer's cards : \033[0;37m  %i  \n", player_sum);
	// print_cards(game->pcards, false);
	printf("\n\033[0;31mKurpiyer 21 acti !\033[0;37m\n");
	sleep(2);
	if (game->player_sum == game->dealer_sum)
		printf("\nDRAW\n");
	else
	{
		printf("\n\033[0;31mYOU LOSE\033[0;37m\n");
		game->stats.lose++;
	}
	sleep(1);
	free_cards(&game->dcards);
	free_cards(&game->pcards);
}

void	dealer_endturn(t_game *game)
{
	if (game->dealer_sum > 21 || game->dealer_sum < game->player_sum)
	{
		printf("\nYOU WIN\n");
		game->stats.win++;
	}
	else if (game->dealer_sum == game->player_sum)
	{
		printf("\nDRAW\n");
	}
	else
	{
		printf("\n\033[0;31mYOU LOSE\033[0;37m\n");
		game->stats.lose++;
	}
	sleep(2);
	reset_game(game);
	game->b_dealerturn = false;
}

void	dealers_turn(t_game *game)
{
	if (game->dealer_sum < 17 && game->dealer_sum < game->player_sum)
	{
		dealer_takes(game);
	}
	else
		dealer_endturn(game);
	sleep(1);
}
