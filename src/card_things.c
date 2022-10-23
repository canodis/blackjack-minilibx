#include "../inc/blackjackmlx.h"

void	delete_card(t_cards **lst, t_cards *card)
{
	t_cards	*tmp;

	tmp = *lst;
	while(tmp->next)
	{
		if (charcmp(tmp->name, card->name))
		{
			if (tmp->prev)
			{
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
			}
			else
			{
				(*lst)->next->prev = NULL;
				*lst = tmp->next;
			}
			free(tmp);
			break;
		}
		tmp = tmp->next;
	}
}

t_cards	*card_dup(t_cards *card)
{
	t_cards	*new = malloc(sizeof(t_cards));
	new->name = card->name;
	new->value = card->value;
	new->card_img = card->card_img;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_cards	*take_card(t_game *game, int card_i)
{
	t_cards	*tmp = game->cards;
	t_cards	*res;
	for (int i = 0; tmp && i < card_i; i++)
		tmp = tmp->next;
	game->card_count--;
	res = card_dup(tmp);
	delete_card(&game->cards, tmp);
	return (res);
}

t_cards	*select_card(t_game *game)
{
	int	card_idx = random_range(0, game->card_count - 1);
	t_cards *select_card = take_card(game, card_idx);
	return (select_card);
}

int	push_card(t_cards **lst, t_cards *new)
{
	ft_lstadd_back(lst, new);
	return (new->value);
}