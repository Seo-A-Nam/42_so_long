/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senam <senam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:36:56 by seanm             #+#    #+#             */
/*   Updated: 2022/02/11 11:33:08 by senam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
*	# initializing process when starting game.
*
*	void    image_init(t_vars *game)
*		: load or make image to use it in game.
*			- make image of floor tile, opened door.
*			- load images of charctor in 4 direction movement.	 
*	void    color_box_init(t_vars *game, t_data *image, int color)
*		: make solid color square image of given color.
*	void    pose_image_init(t_vars *game)
*		: load images of charctor in 4 direction movement.
*/

void	image_init(t_vars *game)
{
	color_box_init(game, &game->tile, 0x4AA8D8);
	color_box_init(game, &game->opened_exit, 0xFFFFC2);
	pose_image_init(game);
}

void	color_box_init(t_vars *game, t_data *image, int color)
{
	int	r;
	int	c;

	r = 0;
	image->img_ptr = mlx_new_image(game->mlx, TILES, TILES);
	image->data = (int *)mlx_get_data_addr(image->img_ptr,
			&image->bpp, &image->size_l, &image->endian);
	while (r < TILES)
	{
		c = 0;
		while (c < TILES)
		{
			image->data[r * TILES + c] = color;
			c++;
		}
		r++;
	}
}

void	pose_image_init(t_vars *game)
{
	int	width;
	int	height;

	game->pose.right.img_ptr = mlx_xpm_file_to_image(game->mlx,
			"../sprite/right.xpm", &width, &height);
	game->pose.left.img_ptr = mlx_xpm_file_to_image(game->mlx,
			"../sprite/left.xpm", &width, &height);
	game->pose.up.img_ptr = mlx_xpm_file_to_image(game->mlx,
			"../sprite/up.xpm", &width, &height);
	game->pose.down.img_ptr = mlx_xpm_file_to_image(game->mlx,
			"../sprite/down.xpm", &width, &height);
	game->pose.stand.img_ptr = mlx_xpm_file_to_image(game->mlx,
			"../sprite/stand.xpm", &width, &height);
}
