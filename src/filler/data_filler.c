/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_filler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellabiad <ellabiad@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:34:18 by ellabiad          #+#    #+#             */
/*   Updated: 2026/03/06 15:34:18 by ellabiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

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

t_map	*data_filler(char **file)
{
	int		i;
	t_map	*map;

	i = 0;
	map = malloc(sizeof(t_map));
	if (!map)
		return (ft_free_tab(file), perror("malloc"), NULL);
	set_map(map);
	while (parse_elements(file[i], map, i))
		i++;
	if (check_parsed_elements(map) == -1)
		return (printf("Error: one or more textures missing\n"), NULL);
	if (check_parsed_elements(map) == -2)
		return (printf("Error: one or more colors missing\n"), NULL);
	parse_map(file + i, map);
	return (map);
}
