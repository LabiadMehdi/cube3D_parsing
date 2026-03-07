/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellabiad <ellabiad@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 06:57:34 by ellabiad          #+#    #+#             */
/*   Updated: 2026/03/07 06:57:34 by ellabiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

int	check_empty_line(char *s)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13)))
		i++;
	if (s[i] != '\0')
		return (0);
	return (1);
}

int	parse_elements(char *line, t_map *map, int line_idx)
{
	(void)map;
	(void)line_idx;
	if (ft_strncmp(line, "NO", 2) == 0
		|| ft_strncmp(line, "SO", 2) == 0
		|| ft_strncmp(line, "WE", 2) == 0
		|| ft_strncmp(line, "EA", 2) == 0)
	{
		parse_textures(line + 4, map)
		return (1);
	}
	else if (ft_strncmp(line, "F", 1) == 0
			|| ft_strncmp(line, "C", 1) == 0)
	{
		parse_colors(line + 2, map)
		return (1);
	}
	else if (check_empty_line(line))
		return (1);
	if (check_parsed_elements(map))
		return (0);
	return (printf("Error: at line -> %i : %s\n", line_idx, line), 0);
}
