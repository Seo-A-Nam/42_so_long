/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senam <senam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:09:57 by senam             #+#    #+#             */
/*   Updated: 2022/02/11 11:16:38 by senam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
*	# Check if the map is valid.
*
*	1. check if the map is bounded with walls('1')
*	2. check if the map is in rectangular shape.
*	3. check if map only consist of given component
*		- 0(space), 1(wall), C(item), E(exit), P(startPoint)
*	4. check the count of each componenet is valid. 
*		- start point should to be 1.
*		- item and exit has to be more than 1.
*	5. you don't have to check way to exit exists.
*		- if you want to check if the way exists, dfs would be the most popular way.
*/

void	init_check_map_vars(int *i, int *start_point, int *item, int *exit)
{
	*i = 0;
	*start_point = 0;
	*item = 0;
	*exit = 0;
}

bool	check_rectangular_shape(int col, char *line)
{
	int	len;

	len = ft_strlen(line);
	if (col == len)
		return (true);
	return (false);
}

bool	check_map_line(char *line,
				int *start_point, int *item, int *exit)
{
	int	j;
	int	len;

	j = 0;
	len = ft_strlen(line);
	while (j < len)
	{
		if (!is_vertic_wall(line, len))
			return (false);
		if (!is_map_component(line[j]))
			return (false);
		count_map_component(line[j], start_point, item, exit);
		j++;
	}
	return (true);
}

bool	check_map(char **map, int row)
{
	int	i;
	int	col;
	int	start_point;
	int	item;
	int	exit;

	init_check_map_vars(&i, &start_point, &item, &exit);
	col = ft_strlen(map[0]);
	while (i < row)
	{
		if (i == 0 || i == row - 1)
		{
			if (!is_horizon_wall(map[i], col))
				return (false);
		}
		if (!check_rectangular_shape(col, map[i]))
			return (false);
		if (!check_map_line(map[i], &start_point, &item, &exit))
			return (false);
		i++;
	}
	if (!is_count_valid(start_point, item, exit))
		return (false);
	return (true);
}
