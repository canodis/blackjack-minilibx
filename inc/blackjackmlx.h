#ifndef BLACKJACKMLX_H
# define BLACKJACKMLX_H

# include "../mlx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/time.h>
# include <readline/readline.h>
# include <readline/history.h>

# define SCREENW 1080
# define SCREENH 860

extern int win;
extern int lose;

typedef struct s_cards
{
	int				value;
	char			name;
	struct s_cards	*next;
	struct s_cards	*prev;
}	t_cards;

typedef struct s_info
{
	void	*img;
	int		*addr;
}	t_info;

typedef struct s_buttons
{
	t_info	take;
	t_info	stop;
	t_info	exit;
}	t_buttons;

typedef struct s_cardimages
{
	t_info	a;
}	t_card_images;


typedef struct s_blackjack
{
	void			*mlx;
	void			*win;
	t_info			img;
	t_cards			*cards;
	t_cards			*pcards;
	t_cards			*dcards;
	bool			player_is_a;
	bool			dealer_is_a;
	int				card_count;
	int				mouse_x;
	int				mouse_y;
	int				mouse_e;
	int				game_event;
	t_buttons		buttons;
	t_card_images	c_image;
}	t_game;

void	init_all(t_game *game);
int		random_range(int start, int end);
bool	charcmp(char a, char b);
t_cards	*select_card(t_game *game);
void	delete_card(t_cards **lst, t_cards *card);
int		push_card(t_cards **lst, t_cards *new);
void	dealer_win(t_game *game, int player_sum, int dealer_sum);
void	player_win(t_game *game, int player_sum, int dealer_sum);
int		player_takes(t_game *game, int player_sum, int dealer_sum, bool *is_playing);
void	dealers_turn(t_game *game, int dealer_sum, int player_sum);
void	free_cards(t_cards **cards);
int		update(t_game *game);
void	init_cards(t_cards	**all_cards);
int		dealer_first(t_game *game);
int		player_first(t_game *game);
void	ft_lstadd_back(t_cards **lst, t_cards *new);
void	free_all(t_game *game);

#endif
