/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senam <senam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:21:01 by senam             #+#    #+#             */
/*   Updated: 2022/02/11 11:33:07 by senam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
*	# initializing process when starting game.
*
*	void    minilibx_init(t_vars *game)
*		: get mlx graphic pointer and window pointer.
*	void    map_init(t_vars *game, char *filename)
*		: read map from a file. and make image of initial map.
*	void    param_init(t_vars *game, t_param *param)
*		: initialize coordinate of start point. and count total items.
*/

void	minilibx_init(t_vars *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width, game->height, "so_long");
}

void	map_init(t_vars *game, char *filename)
{
	game->origin.map = parse_map(filename);
	game->map_img.img_ptr = mlx_new_image(game->mlx, game->width, game->height);
	game->map_img.data = (int *)mlx_get_data_addr(game->map_img.img_ptr,
			&game->map_img.bpp, &game->map_img.size_l, &game->map_img.endian);
	draw_map(game);
}

void	param_init(t_vars *game, t_param *param)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->row)
	{
		j = 0;
		while (j < game->col)
		{
			if (param->map[i][j] == 'P')
			{
				param->y = i;
				param->x = j;
			}
			if (param->map[i][j] == 'C')
				param->items++;
			j++;
		}
		i++;
	}
}
