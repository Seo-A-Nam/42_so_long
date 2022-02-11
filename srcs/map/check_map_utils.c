/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senam <senam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:17:44 by senam             #+#    #+#             */
/*   Updated: 2022/02/11 11:16:28 by senam            ###   ########.fr       */
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

bool	is_map_component(char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'P' || c == 'E')
		return (true);
	return (false);
}

bool	is_horizon_wall(char *line, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (line[i] != '1')
			return (false);
		i++;
	}	
	return (true);
}

bool	is_vertic_wall(char *line, int len)
{
	if (line[0] == '1' && line[len - 1] == '1')
		return (true);
	return (false);
}

void	count_map_component(char c, int *start_point, int *item, int *exit)
{
	if (c == 'P')
		(*start_point)++;
	else if (c == 'C')
		(*item)++;
	else if (c == 'E')
		(*exit)++;
}

bool	is_count_valid(int start_point, int item, int exit)
{
	if (start_point != 1)
		return (false);
	if (item == 0 || exit == 0)
		return (false);
	return (true);
}
