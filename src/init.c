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

t_cards	*new_card(int value, char name, t_info *img)
{
	t_cards	*new = malloc(sizeof(t_cards));
	new->name = name;
	new->value = value;
	new->card_img = img;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_info	*select_image(t_game *game, int i)
{
	if (i == 1)
		return (&game->c_image._2);
	else if (i == 2)
		return (&game->c_image._3);
	else if (i == 3)
		return (&game->c_image._4);
	else if (i == 4)
		return (&game->c_image._5);
	else if (i == 5)
		return (&game->c_image._6);
	else if (i == 6)
		return (&game->c_image._7);
	else if (i == 7)
		return (&game->c_image._8);
	else
		return (&game->c_image._9);
}

void	init_cards(t_cards	**all_cards, t_game *game)
{
	for (int i = 0; i < 8; i++)
		ft_lstadd_back(all_cards, new_card(1, 'A', &game->c_image._a));
	for(int i = 1; i < 9; i++)
	{
		t_info	*tmp = select_image(game, i);
		for (int j = 0; j < 8; j++)
			ft_lstadd_back(all_cards, new_card(i + 1, i + 49, tmp));
	}
	for(int i = 0; i < 8; i++)
		ft_lstadd_back(all_cards, new_card(10, 't', &game->c_image._10));
	for(int i = 0; i < 8; i++)
		ft_lstadd_back(all_cards, new_card(10, 'q', &game->c_image._q));
	for(int i = 0; i < 8; i++)
		ft_lstadd_back(all_cards, new_card(10, 'j', &game->c_image._j));
	for(int i = 0; i < 8; i++)
		ft_lstadd_back(all_cards, new_card(10, 'k', &game->c_image._k));
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
	game->c_image._a.img = mlx_xpm_file_to_image(game->mlx, "sprites/1.xpm", &a, &a);
	game->c_image._a.addr = (int *)mlx_get_data_addr(game->c_image._a.img, &a, &a, &a);
	game->c_image._2.img = mlx_xpm_file_to_image(game->mlx, "sprites/2.xpm", &a, &a);
	game->c_image._2.addr = (int *)mlx_get_data_addr(game->c_image._2.img, &a, &a, &a);
	game->c_image._3.img = mlx_xpm_file_to_image(game->mlx, "sprites/3.xpm", &a, &a);
	game->c_image._3.addr = (int *)mlx_get_data_addr(game->c_image._3.img, &a, &a, &a);
	game->c_image._4.img = mlx_xpm_file_to_image(game->mlx, "sprites/4.xpm", &a, &a);
	game->c_image._4.addr = (int *)mlx_get_data_addr(game->c_image._4.img, &a, &a, &a);
	game->c_image._5.img = mlx_xpm_file_to_image(game->mlx, "sprites/5.xpm", &a, &a);
	game->c_image._5.addr = (int *)mlx_get_data_addr(game->c_image._5.img, &a, &a, &a);
	game->c_image._6.img = mlx_xpm_file_to_image(game->mlx, "sprites/6.xpm", &a, &a);
	game->c_image._6.addr = (int *)mlx_get_data_addr(game->c_image._6.img, &a, &a, &a);
	game->c_image._7.img = mlx_xpm_file_to_image(game->mlx, "sprites/7.xpm", &a, &a);
	game->c_image._7.addr = (int *)mlx_get_data_addr(game->c_image._7.img, &a, &a, &a);
	game->c_image._8.img = mlx_xpm_file_to_image(game->mlx, "sprites/8.xpm", &a, &a);
	game->c_image._8.addr = (int *)mlx_get_data_addr(game->c_image._8.img, &a, &a, &a);
	game->c_image._9.img = mlx_xpm_file_to_image(game->mlx, "sprites/9.xpm", &a, &a);
	game->c_image._9.addr = (int *)mlx_get_data_addr(game->c_image._9.img, &a, &a, &a);
	game->c_image._10.img = mlx_xpm_file_to_image(game->mlx, "sprites/10.xpm", &a, &a);
	game->c_image._10.addr = (int *)mlx_get_data_addr(game->c_image._10.img, &a, &a, &a);
	game->c_image._q.img = mlx_xpm_file_to_image(game->mlx, "sprites/q.xpm", &a, &a);
	game->c_image._q.addr = (int *)mlx_get_data_addr(game->c_image._q.img, &a, &a, &a);
	game->c_image._j.img = mlx_xpm_file_to_image(game->mlx, "sprites/j.xpm", &a, &a);
	game->c_image._j.addr = (int *)mlx_get_data_addr(game->c_image._j.img, &a, &a, &a);
	game->c_image._k.img = mlx_xpm_file_to_image(game->mlx, "sprites/k.xpm", &a, &a);
	game->c_image._k.addr = (int *)mlx_get_data_addr(game->c_image._k.img, &a, &a, &a);
}

void	init_all(t_game *game)
{
	init_values(game);
	init_images(game);
	init_cards(&game->cards, game);
	game->win = mlx_new_window(game->mlx, SCREENW, SCREENH, "blackjack");
}