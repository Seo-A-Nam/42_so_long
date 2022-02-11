/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senam <senam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:10:44 by senam             #+#    #+#             */
/*   Updated: 2022/02/11 14:02:55 by senam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
*   # handle error happening while parsing map.
*
*	bool	error_file_format(char *filename)
*			: check if the format of given file is '.ber'.
*	bool	error_fd(int fd)
*			: exception handling when fail to open() file.
*/

bool	error_file_format(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (filename[len - 3] == 'b' && filename[len - 2] == 'e'
		&& filename[len - 1] == 'r')
		return (true);
	printf
		("Error\n[error] wrong foramt of map file. use file of '.ber' format.");
	exit(0);
	return (false);
}

bool	error_fd(int fd)
{
	if (fd < 0)
	{
		printf("Error\n[error] cannot open the map file");
		exit(0);
	}
	return (false);
}
