/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senam <senam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:45:54 by senam             #+#    #+#             */
/*   Updated: 2022/02/11 17:30:38 by senam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
*	# read '.ber' format file to get a map in (char **) pointer.
*	
*	int	count_newline(char *str)
*			: count newlines in given str.
*	int	get_row_count(void) 
*			: read file(.ber) and count the rows in given content.
*	void    get_map(char **map, int fd)
*			: read file(.ber) using gnl(),
*				and get the map as a 2d array pointer.
*	char **parse_map 
*			: get a malloced map as a 2-dimensional array pointer.
*/

int	count_newline(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

int	get_row_count(char *filename)
{
	char	buf[BUFFER_SIZE + 1];
	int		read_size;
	int		count;
	int		fd;

	read_size = 0;
	count = 0;
	error_file_format(filename);
	fd = open(filename, O_RDWR);
	error_fd(fd);
	while (1)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size <= 0)
			break ;
		count += count_newline(buf);
	}
	close(fd);
	return (count);
}

void	get_map(char **map, int fd)
{
	char	*line;
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	while (1)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
		{
			printf("Error\n[error] gnl error.\n");
			exit(0);
		}
		map[i] = line;
		if (ret == 0)
			break ;
		i++;
	}
	map[i] = NULL;
}

char	**parse_map(char *filename)
{
	char	**map;
	int		row;
	int		fd;

	row = get_row_count(filename);
	map = (char **)malloc(sizeof(char *) * row);
	if (!map)
	{
		printf("Error\n[error] malloc error\n");
		exit(0);
	}
	fd = open(filename, O_RDWR);
	error_fd(fd);
	get_map(map, fd);
	close(fd);
	if (check_map(map, row) == false)
	{
		printf("Error\n[error] Invalid map!\n");
		exit(0);
	}
	return (map);
}
