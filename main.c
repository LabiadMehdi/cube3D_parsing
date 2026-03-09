/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellabiad <ellabiad@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:53:14 by ellabiad          #+#    #+#             */
/*   Updated: 2026/03/09 09:30:23 by ellabiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/parser.h"

void	print_arr(char **arr)
{
	int	i = 0;
	while (arr[i])
	{
		printf("%s", arr[i++]);
		if (arr[i])
			printf("\n");
	}
}

void	print_map(t_map *map)
{
	printf("%s\n", map->no);
	printf("%s\n", map->so);
	printf("%s\n", map->we);
	printf("%s\n", map->ea);
	printf("%i\n", map->floor);
	printf("%i\n", map->ceiling);
	print_arr(map->map);
	printf("\n%i\n", map->pos_x);
	printf("%i\n", map->pos_y);
	printf("%c\n", map->dir);
}

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
	print_map(map);
	free_map(map);
	return (0);
}
