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
	card = select_card(game);
	card_sum += push_card(&game->dcards, card);
	if (card->name == 'A' && !game->dealer_is_a)
	{
		card_sum += 10;
		game->dealer_is_a = true;
	}
	printf("\033[0;34mDealer's cards : \033[0;37m\n");
	// print_cards(game->dcards, true);
	return (card_sum);
}

int		dealer_takes(t_game *game, int dealer_sum)
{
	t_cards	*card = select_card(game);
	dealer_sum += push_card(&game->dcards, card);
	if (card->name == 'A' && dealer_sum < 11)
	{
		dealer_sum += 10;
		game->dealer_is_a = true;
	}
	else if (dealer_sum > 21 && game->dealer_is_a)
	{
		dealer_sum -= 10;
		game->dealer_is_a = false;
	}
	return (dealer_sum);
}

void	dealer_win(t_game *game, int player_sum, int dealer_sum)
{
	printf("\033[0;34mDealer's cards : \033[0;37m  %i  \n", dealer_sum);
	// print_cards(game->dcards, false);
	printf("\033[0;34mPlayer's cards : \033[0;37m  %i  \n", player_sum);
	// print_cards(game->pcards, false);
	printf("\n\033[0;31mKurpiyer 21 acti !\033[0;37m\n");
	sleep(2);
	if (player_sum == dealer_sum)
		printf("\nDRAW\n");
	else
	{
		printf("\n\033[0;31mYOU LOSE\033[0;37m\n");
		lose++;
	}
	sleep(1);
	free_cards(&game->dcards);
	free_cards(&game->pcards);
}

void	dealers_turn(t_game *game, int dealer_sum, int player_sum)
{
	printf("\033[0;34mDealer's cards : \033[0;37m  %i  \n", dealer_sum);
	// print_cards(game->dcards, false);
	printf("\033[0;34mPlayer's cards : \033[0;37m  %i  \n", player_sum);
	// print_cards(game->pcards, false);
	sleep(2);
	while (dealer_sum < 17)
	{
		dealer_sum = dealer_takes(game, dealer_sum);
		printf("\033[0;34mDealer's cards : \033[0;37m  %i  \n", dealer_sum);
		// print_cards(game->dcards, false);
		printf("\033[0;34mPlayer's cards : \033[0;37m  %i  \n", player_sum);
		// print_cards(game->pcards, false);
		sleep(1);
	}
	if (dealer_sum > 21 || dealer_sum < player_sum)
	{
		printf("\n\033[0;32mYOU WIN\033[0;37m\n");
		win++;
	}
	else if (dealer_sum == player_sum)
		printf("\nDRAW\n");
	else
	{
		printf("\n\033[0;31mYOU LOSE\033[0;37m\n");
		lose++;
	}
	sleep(1);
	// readline("Devam etmek icin ENTER'a basiniz...");
}
