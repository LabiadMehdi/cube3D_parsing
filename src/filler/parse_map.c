/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellabiad <ellabiad@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 09:17:54 by ellabiad          #+#    #+#             */
/*   Updated: 2026/03/07 09:17:54 by ellabiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

int	is_valid_map_lcp(char *s, int idx, int *player, t_map *map)
{
	if (check_empty_line(s))
		return (printf("Error: empty line at line %i\n", idx), 0);
	if (!check_valid_char(s, idx))
		return (0);
	if (!check_valid_player(s, player, idx, map))
		return (0);
	return (1);
}

int	is_valid_map(char **file, int start, t_map *map)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	j = 0;
	player = 0;
	while (file[i])
	{
		if (!is_valid_map_lcp(file[i], i + start, &player, map))
			return (0);
		if (player && j == 0)
			j = i;
		i++;
	}
	if (player)
	{
		map->pos_y = j;
		map->pos_x = player;
	}
	if (player == 0)
		return (printf("Error: no player on the map\n"), 0);
	if (!check_enclosed_by_wall(file))
		return (printf("Error: map is not enclosed by wall\n"), 0);
	return (1);
}

int	parse_map(char **file, int start, t_map *map)
{
	char	**parsed_map;
	int		i;
	int		longest_line;

	if (!is_valid_map(file, start, map))
		return (0);
	parsed_map = malloc(sizeof(char *) * (arr_size(file) + 1));
	if (!parsed_map)
		return (printf("Error: %s\n", strerror(errno)), 0);
	parsed_map[arr_size(file)] = NULL;
	i = 0;
	longest_line = found_longest_line(file);
	while (file[i])
	{
		parsed_map[i] = pad_line(file[i], longest_line);
		if (!parsed_map[i])
			return (printf("Error: %s\n", strerror(errno)),
				ft_free_tab(parsed_map), 0);
		i++;
	}
	map->map = parsed_map;
	map->map_w = i;
	map->map_h = longest_line;
	return (1);
}
