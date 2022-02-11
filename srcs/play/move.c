/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senam <senam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:45:59 by senam             #+#    #+#             */
/*   Updated: 2022/02/11 17:30:45 by senam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
*	# move charactor while playing game.
*
*	void    move_position(int keycode, t_param *param)
*		: change coordinate of player according to direction of movement.
*	void    move_player(int keycode, t_vars *game, t_param pre)
*		: move player to typed direction.
*			- End the game if player reaches to exit after collecting all the stars.
*			- count the steps of player and print it.
*			- get item if player meets that.
*	bool    isAvail_move(t_vars *game, t_param *param, int keycode)
*		: check if player can move to typed direction.
*			- player cannot go through walls ('1')
*			- player cannot go in exit before collecting all the stars.
*/

void	move_position(int keycode, t_param *param)
{
	if (keycode == KEY_W)
		param->y--;
	else if (keycode == KEY_S)
		param->y++;
	else if (keycode == KEY_A)
		param->x--;
	else if (keycode == KEY_D)
		param->x++;
}

void	move_player(int keycode, t_vars *game, t_param pre)
{
	move_position(keycode, &game->param);
	get_item(game, &game->param);
	if (keycode == KEY_W)
		draw_next_step(game, game->pose.up, pre, game->param);
	else if (keycode == KEY_S)
		draw_next_step(game, game->pose.down, pre, game->param);
	else if (keycode == KEY_A)
		draw_next_step(game, game->pose.left, pre, game->param);
	else if (keycode == KEY_D)
		draw_next_step(game, game->pose.right, pre, game->param);
	game->steps++;
	printf("steps : %d\n", game->steps);
	if (game->param.map[game->param.y][game->param.x] == 'E'
		&& game->stat.all_item == true)
		display_ending_credit(game);
}

bool	is_avail_move(t_vars *game, t_param *param, int keycode)
{
	t_param	next;

	next.x = param->x;
	next.y = param->y;
	move_position(keycode, &next);
	if (param->map[next.y][next.x] == '1')
		return (false);
	if (param->map[next.y][next.x] == 'E' && game->stat.all_item == false)
		return (false);
	return (true);
}
