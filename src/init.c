#include "../inc/blackjackmlx.h"

void	ft_lstadd_back(t_cards **lst, t_cards *new)
{
	t_cards	*last_elem;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last_elem = *lst;
	while(last_elem->next != NULL)
		last_elem = last_elem->next;
	last_elem->next = new;
	new->prev = last_elem;
}

t_cards	*new_card(int value, char name)
{
	t_cards	*new = malloc(sizeof(t_cards));
	new->name = name;
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	init_cards(t_cards	**all_cards)
{
	for (int i = 0; i < 8; i++)
		ft_lstadd_back(all_cards, new_card(1, 'A'));
	for(int i = 1; i < 9; i++)
	{
		for (int j = 0; j < 8; j++)
			ft_lstadd_back(all_cards, new_card(i + 1, i + 49));
	}
	for(int i = 0; i < 8; i++)
		ft_lstadd_back(all_cards, new_card(10, 't'));
	for(int i = 0; i < 8; i++)
		ft_lstadd_back(all_cards, new_card(10, 'j'));
	for(int i = 0; i < 8; i++)
		ft_lstadd_back(all_cards, new_card(10, 'q'));
	for(int i = 0; i < 8; i++)
		ft_lstadd_back(all_cards, new_card(10, 'k'));
}

void	init_values(t_game *game)
{
	game->cards = NULL;
	game->pcards = NULL;
	game->dcards = NULL;
	game->player_is_a = false;
	game->mouse_x = 0;
	game->mouse_y = 0;
	game->mouse_e = 0;
	game->dealer_is_a = false;
	game->card_count = 104;
	game->mlx = mlx_init();
}

void	init_images(t_game *game)
{
	int a;
	game->img.img = mlx_new_image(game->mlx, SCREENW, SCREENH);
	game->img.addr = (int *)mlx_get_data_addr(game->img.img, &a, &a, &a);

	game->buttons.take.img = mlx_xpm_file_to_image(game->mlx, "sprites/take.xpm", &a, &a);
	game->buttons.stop.img = mlx_xpm_file_to_image(game->mlx, "sprites/stop.xpm", &a, &a);
	game->buttons.exit.img = mlx_xpm_file_to_image(game->mlx, "sprites/exit.xpm", &a, &a);

	game->buttons.take.addr = (int *)mlx_get_data_addr(game->buttons.take.img, &a, &a, &a);
	game->buttons.stop.addr = (int *)mlx_get_data_addr(game->buttons.stop.img, &a, &a, &a);
	game->buttons.exit.addr = (int *)mlx_get_data_addr(game->buttons.exit.img, &a, &a, &a);

	game->c_image.a.img = mlx_xpm_file_to_image(game->mlx, "sprites/1.xpm", &a, &a);
	game->c_image.a.addr = (int *)mlx_get_data_addr(game->c_image.a.img, &a, &a, &a);
}

void	init_all(t_game *game)
{
	init_values(game);
	init_cards(&game->cards);
	game->win = mlx_new_window(game->mlx, SCREENW, SCREENH, "blackjack");
	init_images(game);
}