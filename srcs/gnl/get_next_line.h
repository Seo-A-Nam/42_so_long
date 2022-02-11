/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senam <senam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:04:25 by senam             #+#    #+#             */
/*   Updated: 2022/02/11 11:15:52 by senam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../so_long.h"
# include <unistd.h>
# include <stdlib.h>

# define OPEN_MAX 1024
# define BUFFER_SIZE 1024

int		get_next_line(int fd, char **line);
size_t	ft_strlen(char *str);
int		find_newline(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);

#endif
