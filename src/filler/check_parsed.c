/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellabiad <ellabiad@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 08:35:07 by ellabiad          #+#    #+#             */
/*   Updated: 2026/03/07 08:35:07 by ellabiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

int	check_parsed_elements(t_map *map)
{
	if (map->no == NULL || map->so == NULL
		|| map->we == NULL || map->ea == NULL)
		return (0);
	if (map->floor_set == 0 || map->ceiling_set == 0)
		return (0);
	return (1);
}
