#include "../inc/blackjackmlx.h"

void	button_bar(t_game *game)
{
	int	imgx = 0;
	int	imgy;
	int	image_width = 290;

	// take button
	for (int x = 50; x < 340; x++)
	{
		imgy = 0;
		for (int y = 735; y < 835; y++)
		{
			game->img.addr[y * SCREENW + x] = game->buttons.take.addr[imgy * image_width + imgx];
			imgy++;
		}
		imgx++;
	}
	// stop button
	imgx = 0;
	for (int x = 390; x < 680; x++)
	{
		imgy = 0;
		for (int y = 735; y < 835; y++)
		{
			game->img.addr[y * SCREENW + x] = game->buttons.stop.addr[imgy * image_width + imgx];
			imgy++;
		}
		imgx++;
	}
	//exit button
	imgx = 0;
	for (int x = 730; x < 1020; x++)
	{
		imgy = 0;
		for (int y = 735; y < 835; y++)
		{
			game->img.addr[y * SCREENW + x] = game->buttons.exit.addr[imgy * image_width + imgx];
			imgy++;
		}
		imgx++;
	}
	//line
	for (int x = 0; x < SCREENW - 1; x++)
	{
		// 710 bar position
		// 375 half of screen
		game->img.addr[710 * SCREENW + x] = 0xffffff;
		game->img.addr[375 * SCREENW + x] = 0xffffff;
	}
}

void	put_card_window(t_game *game, int *img, int x, int y)
{
	int picy;
	int picx = 0;
	int finishx = x + cardw;
	int	finishy = y + cardh;

	for (int _x = x; _x < finishx; _x++)
	{
		picy = 0;
		for (int _y = y; _y < finishy; _y++)
		{
			game->img.addr[_y * SCREENW + _x] = img[picy * cardw + picx]; 
			picy++;
		}
		picx++;
	}
}
