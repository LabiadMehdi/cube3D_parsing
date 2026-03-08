/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellabiad <ellabiad@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 13:45:41 by ellabiad          #+#    #+#             */
/*   Updated: 2026/03/06 13:45:41 by ellabiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

int	check_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len > 4 && (ft_strncmp(filename + (len - 4), ".cub", 4) == 0))
		return (1);
	return (0);
}

int	check_open(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (printf("Error: %s\n", strerror(errno)), fd);
	return (fd);
}
