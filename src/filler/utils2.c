/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellabiad <ellabiad@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 17:30:06 by ellabiad          #+#    #+#             */
/*   Updated: 2026/03/07 17:30:06 by ellabiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

int	arr_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	found_longest_line(char **arr)
{
	int	max;

	max = 0;
	while (*arr)
	{
		if ((int)ft_strlen(*arr) > max)
			max = ft_strlen(*arr);
		arr++;
	}
	return (max);
}

char	*pad_line(char *line, int map_width)
{
	char	*res;
	int		i;

	res = malloc(map_width + 1);
	if (!res)
		return (printf("Error: %s\n", strerror(errno)), NULL);
	i = 0;
	while (i < map_width)
	{
		if (line && *line == ' ')
		{
			res[i] = '1';
			line++;
		}
		else if (line && *line != '\0')
			res[i] = *line++;
		else
			res[i] = '1';
		i++;
	}
	return (res);
}
