/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senam <senam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:04:04 by senam             #+#    #+#             */
/*   Updated: 2022/02/11 12:31:56 by senam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	error_return(char **backup)
{
	if (*backup)
	{
		free(*backup);
		*backup = 0;
	}
	return (-1);
}

int	get_one_line(char **backup, char **line, int nl_idx)
{
	char	*tmp;

	(*backup)[nl_idx] = '\0';
	*line = ft_strdup(*backup);
	if (!line)
		return (error_return(backup));
	tmp = ft_strdup(*backup + nl_idx + 1);
	if (!tmp)
		return (error_return(backup));
	free(*backup);
	*backup = tmp;
	tmp = 0;
	return (1);
}

int	get_all(char **backup, char **line)
{
	int		nl_idx;

	nl_idx = find_newline(*backup);
	if (*backup && (nl_idx >= 0))
		return (get_one_line(backup, line, nl_idx));
	else if (*backup)
	{
		*line = ft_strdup(*backup);
		free(*backup);
		*backup = 0;
	}
	return (0);
}

int	read_file_lines(int fd, char *buf, char **line, char **backup)
{
	int	read_size;
	int	nl_idx;

	while (1)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size <= 0)
			break ;
		buf[read_size] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buf);
		if (!backup[fd])
			return (-1);
		nl_idx = find_newline(backup[fd]);
		if (nl_idx >= 0)
			return (get_one_line(&backup[fd], line, nl_idx));
	}
	if (read_size < 0)
		return (error_return(&backup[fd]));
	return (get_all(&backup[fd], line));
}

int	get_next_line(int fd, char **line)
{
	static char	*backup[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];

	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!backup[fd])
	{
		backup[fd] = (char *)malloc(sizeof(char));
		if (!backup[fd])
			return (-1);
		backup[fd][0] = '\0';
	}
	return (read_file_lines(fd, buf, line, backup));
}
