/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellabiad <ellabiad@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:53:14 by ellabiad          #+#    #+#             */
/*   Updated: 2026/03/08 18:40:32 by ellabiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/parser.h"

int	main(int ac, char **av)
{
	char	*filename;
	char	**content;
	int		fd;
	t_map	*map;

	if (ac != 2)
		return (1);
	filename = av[1];
	if (!check_extension(filename))
		return (printf("Error: wrong file extension\n"), 1);
	fd = check_open(filename);
	if (fd < 0)
		return (1);
	content = read_all(fd);
	if (!content)
		return (1);
	close(fd);
	map = data_filler(content);
	ft_free_tab(content);
	if (!map)
		return (1);
	free_map(map);
	return (0);
}
