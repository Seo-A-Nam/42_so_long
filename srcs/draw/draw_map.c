/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senam <senam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:39:40 by senam             #+#    #+#             */
/*   Updated: 2022/02/11 13:50:49 by senam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
*	# Make image of initial map.
*
*	void    draw_pixels_of_texture(t_vars *game, char *filename, int row, int col)
*		- put texture image of given filename at given position.
*	void    draw_pixels_of_floor(t_vars *game, int row, int col)
*		- put floor tile image at given position.	
*	void    draw_map(t_vars *game)
*		- draw an image of initial map. (wall, items, floor, exit)
*/

void	draw_pixels_of_texture(t_vars *game, char *filename, int row, int col)
{
	t_data	texture;
	int		width;
	int		height;
	int		r;
	int		c;

	r = 0;
	c = 0;
	texture.img_ptr = mlx_xpm_file_to_image(game->mlx,
			filename, &width, &height);
	texture.data = (int *)mlx_get_data_addr(texture.img_ptr,
			&texture.bpp, &texture.size_l, &texture.endian);
	row *= TILES;
	col *= TILES;
	while (r < TILES)
	{
		c = 0;
		while (c < TILES)
		{
			game->map_img.data[(r + row)*(game->width) + (c + col)]
				= texture.data[r * TILES + c];
			c++;
		}
		r++;
	}
}

void	draw_pixels_of_floor(t_vars *game, int row, int col)
{
	int	r;
	int	c;

	r = 0;
	row *= TILES;
	col *= TILES;
	while (r < TILES)
	{
		c = 0;
		while (c < TILES)
		{
			game->map_img.data[(r + row)*(game->width)
				+ (c + col)] = 0x4AA8D8;
			c++;
		}
		r++;
	}
}

void	draw_map(t_vars *game)
{
	int	r;
	int	c;

	r = 0;
	while (r < game->row)
	{
		c = 0;
		while (c < game->col)
		{
			if (game->origin.map[r][c] == '1')
				draw_pixels_of_texture(game, "../sprite/wall.xpm", r, c);
			else if (game->origin.map[r][c] == 'C')
				draw_pixels_of_texture(game, "../sprite/item.xpm", r, c);
			else if (game->origin.map[r][c] == 'E')
				draw_pixels_of_texture(game,
					"../sprite/closed_exit.xpm", r, c);
			else
				draw_pixels_of_floor(game, r, c);
			c++;
		}
		r++;
	}
}
