/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellabiad <ellabiad@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 09:56:42 by ellabiad          #+#    #+#             */
/*   Updated: 2026/03/08 09:56:42 by ellabiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

int	check_valid_char(char *s, int idx)
{
	int		i;
	char	c;

	i = 0;
	while (s[i])
	{
		c = s[i];
		if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'W'
			|| c == 'E' || c == ' ' || (c >= 9 && c <= 13))
			i++;
		else
			return (printf
				("Error: invalid input detected line %i column %i\n",
					idx, i + 1),
				0);
	}
	return (1);
}

int	check_valid_player(char *s, int *player, int idx, t_map *map)
{
	int		i;
	char	c;

	i = 0;
	while (s[i])
	{
		c = s[i];
		if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		{
			if (*player == 1)
				return (printf
					("Error: player declared twice line %i column %i\n",
						idx, i + 1),
					0);
			else
			{
				map->dir = c;
				*player = i;
				break ;
			}
		}
		i++;
	}
	return (1);
}

char	get_char(char **file, int y, int x)
{
	if (y < 0 || !file[y] || x < 0 || x >= (int)ft_strlen(file[y]))
		return (' ');
	else if (file[y][x] == '\n')
		return (' ');
	return (file[y][x]);
}

int	check_enclosed_by_wall(char **file)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (file[y])
	{
		x = 0;
		while (file[y][x])
		{
			c = file[y][x];
			if (c == '0' || c == 'N' || c == 'W' || c == 'E' || c == 'S')
			{
				if (get_char(file, y - 1, x) == ' '
					|| get_char(file, y + 1, x) == ' '
					|| get_char(file, y, x - 1) == ' '
					|| get_char(file, y, x + 1) == ' ')
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
