/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellabiad <ellabiad@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 08:51:42 by ellabiad          #+#    #+#             */
/*   Updated: 2026/03/07 08:51:42 by ellabiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

int	assign_to_identifier(char *line, char *path, t_map *map)
{
	if (ft_strncmp(line, "NO", 2) == 0 && !map->no)
	{
		map->no = path;
		return (1);
	}
	else if (ft_strncmp(line, "SO", 2) == 0 && !map->so)
	{
		map->so = path;
		return (1);
	}
	else if (ft_strncmp(line, "EA", 2) == 0 &&!map->ea)
	{
		map->ea = path;
		return (1);
	}
	else if (ft_strncmp(line, "WE", 2) == 0 && !map->we)
	{
		map->we = path;
		return (1);
	}
	return (printf("Error: identifier declared twice: %s", line), 0);
}

int	parse_textures(char *line, t_map *map)
{
	int		fd;
	int		offset;
	char	*path;

	offset = skip_spaces(line + 2);
	path = trim_nl(line + 2 + offset);
	fd = check_open(path);
	if (fd < 0)
		return (free(path), 0);
	close(fd);
	if (!assign_to_identifier(line, path, map))
		return (free(path), 0);
	return (1);
}
