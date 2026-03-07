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
