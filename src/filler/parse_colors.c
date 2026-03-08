/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellabiad <ellabiad@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 08:36:18 by ellabiad          #+#    #+#             */
/*   Updated: 2026/03/07 08:36:18 by ellabiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

int	check_arr_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	is_num(char *s)
{
	int i = 0;
	
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_range(char **arr)
{
	int	r;
	int	g;
	int	b;

	if (!is_num(arr[0]) || !is_num(arr[1]) || !is_num(arr[2]))
        return (0);
	r = ft_atoi(arr[0]);
	g = ft_atoi(arr[1]);
	b = ft_atoi(arr[2]);
	if (r < 0 || r > 255)
		return (0);
	if (g < 0 || g > 255)
		return (0);
	if (b < 0 || b > 255)
		return (0);
	return (1);
}

int	assign_rgb(char id, char **arr_rgb, t_map *map)
{
	int		r;
	int		g;
	int		b;
	int		rgb;

	r = ft_atoi(arr_rgb[0]);
	g = ft_atoi(arr_rgb[1]);
	b = ft_atoi(arr_rgb[2]);
	rgb = (r << 16) | (g << 8) | b;
	if (id == 'F')
	{
		if (map->floor_set)
			return (0);
		map->floor = rgb;
		map->floor_set = 1;
	}
	else
	{
		if (map->ceiling_set)
			return (0);
		map->ceiling = rgb;
		map->ceiling_set = 1;
	}
	return (1);
}

int	parse_colors(char *line, t_map *map)
{
	char	**arr_rgb;
	char	*set_rgb;

	set_rgb = trim_nl(line);
	if (!set_rgb)
		return (printf("Error: %s\n", strerror(errno)), 0);
	arr_rgb = ft_split(set_rgb + 1 + skip_spaces(set_rgb + 1), ',');
	if (!arr_rgb)
		return (free(set_rgb), printf("Error: %s\n", strerror(errno)), 0);
	free(set_rgb);
	if (check_arr_size(arr_rgb) != 3 || !check_range(arr_rgb))
		return (ft_free_tab(arr_rgb),
			printf("Error: cannot convert RGB at line %s", line), 0);
	if (!assign_rgb(line[0], arr_rgb, map))
		return (ft_free_tab(arr_rgb),
			printf("Error: value declared twice at line %s", line), 0);
	ft_free_tab(arr_rgb);
	return (1);
}
