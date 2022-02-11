/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senam <senam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:04:13 by senam             #+#    #+#             */
/*   Updated: 2022/02/11 12:27:29 by senam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	find_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup(char *s1)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1);
	if (!s1)
		return (0);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	while (i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		index;
	char	*str;

	i = 0;
	j = 0;
	index = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!(str))
		return (0);
	while (s1[i])
		str[index++] = s1[i++];
	while (s2[j])
		str[index++] = s2[j++];
	str[index] = '\0';
	free(s1);
	s1 = 0;
	return (str);
}
