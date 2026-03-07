/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellabiad <ellabiad@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 11:20:59 by ellabiad          #+#    #+#             */
/*   Updated: 2026/03/07 11:20:59 by ellabiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

int	skip_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	return (i);
}

void	set_map(t_map *map)
{
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->floor = 0;
	map->ceiling = 0;
	map->floor_set = 0;
	map->ceiling_set = 0;
	map->map = NULL;
	map->map_w = 0;
	map->map_h = 0;
}

void	free_map(t_map *map)
{
	if (!map)
		return ;
	if (map->no)
		free(map->no);
	if (map->so)
		free(map->so);
	if (map->we)
		free(map->we);
	if (map->ea)
		free(map->ea);
	if (map->map)
		ft_free_tab(map->map);
	free(map);
}

char	*trim_nl(char *line)
{
	char	*path;
	int		i;

	i = 0;
	path = malloc(ft_strlen(line) + 1);
	if (!path)
		return (perror("malloc"), NULL);
	while (line[i] && line[i] != '\n')
	{
		path[i] = line[i];
		i++;
	}
	path[i] = '\0';
	return (path);
}
