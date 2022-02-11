/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senam <senam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:17:48 by senam             #+#    #+#             */
/*   Updated: 2022/02/11 17:30:42 by senam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
*	# manage events happending when player type keys.
*	
*	int	x_key_clicked(void)
*		: terminate the program when X button is clicked.
*	int	key_press(int keycode, t_vars *game)
*		: handles key press event in any phase of game.
*	void	opening_phase(int keycode, t_vars *game)
*		: handles key press event in opening credit of game.
*			- ESC : exit the program.
*			- ENTER : turn intro rule intro phase.
*	void	intro_rules_phase(int keycode, t_vars *game)
*		: handles key press event in rule intro credits of game.
*			- W, A, S, D key event (move player charactor)
*	void	ending_phase(int keycode, t_vars *game)
*		: handles key press event in ending credits of game.
*			- ESC : exit the program.
*			- ENTER : free the memory of current param varibale,
*						and replay the game.
*/

int	x_key_clicked(void)
{
	exit(0);
	return (0);
}

int	key_press(int keycode, t_vars *game)
{
	if (game->stat.start == false)
		opening_phase(keycode, game);
	else if (game->stat.rules == false)
		intro_rules_phase(keycode, game);
	else if (game->stat.end == true)
		ending_phase(keycode, game);
	else if (game->stat.rules == true && game->stat.rules == true)
	{
		if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A
			|| keycode == KEY_D)
		{
			if (is_avail_move(game, &game->param, keycode) == true)
				move_player(keycode, game, game->param);
		}
	}
	return (0);
}

void	opening_phase(int keycode, t_vars *game)
{
	if (keycode == KEY_ENTER)
	{
		game->stat.start = true;
		display_rule_credit(game);
	}
	if (keycode == KEY_ESC)
		exit(0);
}

void	intro_rules_phase(int keycode, t_vars *game)
{
	if (keycode == KEY_ENTER)
	{
		game->stat.rules = true;
		start(game);
	}
}

void	ending_phase(int keycode, t_vars *game)
{
	int	i;

	i = 0;
	if (keycode == KEY_ENTER)
	{
		while (game->param.map[i])
		{
			free(game->param.map[i]);
			i++;
		}
		free(game->param.map);
		start(game);
	}
	if (keycode == KEY_ESC)
		exit(0);
}
