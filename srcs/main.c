/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senam <senam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:57:08 by senam             #+#    #+#             */
/*   Updated: 2022/02/11 17:30:52 by senam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
*	# start and initiate game.
*
*	void    get_initial_settings(t_vars *game, t_param *param, t_param *origin)
*		: copy initial setting data from backup data to param.
*			- param : variable containing info of current coordinate, items, map.
*	void	set_size(t_vars *game, char *filename)
*		: set size values of game. (row, column, width, height)
*	void    init(t_vars *game, char *filename)
*		: initialize data when program is initiated.
*	int     start(t_vars *game)
*		: start or restart the game.
*			- bring initial settings
*			- draw map and draw charactor at the start point.
*	int     main(int argc, char **argv)
*		: initiate game and keep the program work.
*/

void	get_initial_settings(t_vars *game, t_param *param, t_param *origin)
{
	int	i;

	i = 0;
	param->map = (char **)malloc(sizeof(char *) * game->row);
	while (i < game->row)
	{
		param->map[i] = ft_strdup(origin->map[i]);
		i++;
	}
	param->map[game->row] = 0;
	param->x = origin->x;
	param->y = origin->y;
	param->items = origin->items;
}

void	set_size(t_vars *game, char *filename)
{
	char	*line;
	int		fd;
	int		ret;

	fd = open(filename, O_RDWR);
	ret = get_next_line(fd, &line);
	if (ret == -1)
		exit(0);
	game->row = get_row_count(filename);
	game->col = ft_strlen(line);
	game->width = game->col * TILES;
	game->height = game->row * TILES;
	free(line);
	close(fd);
}

void	init(t_vars *game, char *filename)
{
	game->stat.start = false;
	game->stat.rules = false;
	game->origin.items = 0;
	set_size(game, filename);
	minilibx_init(game);
	map_init(game, filename);
	image_init(game);
	param_init(game, &game->origin);
	display_opening_credit(game);
	mlx_hook(game->win, X_EVENT_KEYPRESS, 0, &key_press, game);
	mlx_hook(game->win, X_EVENT_EXIT, 0, &x_key_clicked, 0);
}

int	start(t_vars *game)
{
	game->stat.end = false;
	game->stat.all_item = false;
	game->steps = 0;
	get_initial_settings(game, &game->param, &game->origin);
	mlx_put_image_to_window(game->mlx, game->win, game->map_img.img_ptr, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->pose.stand.img_ptr,
		game->param.x * TILES + 3, game->param.y * TILES);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	game;

	if (argc != 2)
	{
		printf("Error\n[error] wrong number of argument.\n");
		exit(0);
	}
	init(&game, argv[1]);
	mlx_loop(game.mlx);
	return (0);
}
