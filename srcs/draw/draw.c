/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senam <senam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:28:01 by seanm             #+#    #+#             */
/*   Updated: 2022/02/11 11:17:13 by senam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
*	# draw changes of game screen when event happens.
*
*	void    open_alldoors(t_vars *game)
*		: open all of the doors of exit, when player collects all the items.	
*	void    get_item(t_vars *game, t_param *param)
*		: get item of the map. and erase the item image on map.
*	void    draw_nextStep(t_vars *game, t_data img, t_param pre, t_param now)
*		: draw player charactor on the position of next step,
			when player move the charactor.
*			- draw charactor in pose matches to direction of movement.
*/

void	open_alldoors(t_vars *game)
{
	int	i;
	int	j;

	i = 0;
	game->stat.all_item = true;
	while (i < game->row)
	{
		j = 0;
		while (j < game->col)
		{
			if (game->param.map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,
					game->opened_exit.img_ptr, j * TILES, i * TILES);
			j++;
		}
		i++;
	}
}

void	get_item(t_vars *game, t_param *param)
{
	if (param->map[param->y][param->x] == 'C')
	{
		param->map[param->y][param->x] = '0';
		param->items--;
		mlx_put_image_to_window(game->mlx, game->win,
			game->tile.img_ptr, param->x * TILES, param->y * TILES);
		if (param->items == 0)
			open_alldoors(game);
	}
}

void	draw_next_step(t_vars *game, t_data img, t_param pre, t_param now)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->tile.img_ptr, pre.x * TILES, pre.y * TILES);
	mlx_put_image_to_window(game->mlx, game->win,
		img.img_ptr, now.x * TILES + 3, now.y * TILES);
}
