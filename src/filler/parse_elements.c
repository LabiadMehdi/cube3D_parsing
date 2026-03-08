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

int	parse_elements(char *line, t_map *map, int line_idx)
{
	if (ft_strncmp(line, "NO", 2) == 0
		|| ft_strncmp(line, "SO", 2) == 0
		|| ft_strncmp(line, "WE", 2) == 0
		|| ft_strncmp(line, "EA", 2) == 0)
		return (parse_textures(line, map));
	else if (ft_strncmp(line, "F", 1) == 0
		|| ft_strncmp(line, "C", 1) == 0)
		return (parse_colors(line, map));
	else if (check_empty_line(line))
		return (1);
	if (check_parsed_elements(map))
		return (0);
	return (printf("Error: at line: %i: %s", line_idx, line), 0);
}
