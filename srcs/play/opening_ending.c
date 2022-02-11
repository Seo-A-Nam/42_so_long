/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opening_ending.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senam <senam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:52:02 by senam             #+#    #+#             */
/*   Updated: 2022/02/11 17:30:46 by senam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
*	# display intro images of game rule, opening and ending in each phase.
*
*	void    display_opening_credit(t_vars *game)
*		: display opening credit image.
*	void    display_ending_credit(t_vars *game)
*		: display rule intro image.
*	void    display_rule_credit(t_vars *game)
*		: display ending credit image.
*/

void	display_opening_credit(t_vars *game)
{
	t_data	opening;
	int		width;
	int		height;

	opening.img_ptr = mlx_xpm_file_to_image(game->mlx,
			"../sprite/opening.xpm", &width, &height);
	mlx_put_image_to_window(game->mlx, game->win, opening.img_ptr, 0, 0);
}

void	display_ending_credit(t_vars *game)
{
	t_data	ending;
	int		width;
	int		height;

	game->stat.end = true;
	ending.img_ptr = mlx_xpm_file_to_image(game->mlx,
			"../sprite/ending.xpm", &width, &height);
	mlx_put_image_to_window(game->mlx, game->win, ending.img_ptr, 0, 0);
}

void	display_rule_credit(t_vars *game)
{
	t_data	rules;
	int		width;
	int		height;

	rules.img_ptr = mlx_xpm_file_to_image(game->mlx,
			"../sprite/rules.xpm", &width, &height);
	mlx_put_image_to_window(game->mlx, game->win, rules.img_ptr, 0, 0);
}
