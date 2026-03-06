/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellabiad <ellabiad@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:53:13 by ellabiad          #+#    #+#             */
/*   Updated: 2026/03/06 14:53:13 by ellabiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

char	**arr_cpy(char **arr)
{
	int		i;
	char	**new_arr;

	i = 0;
	while (arr && arr[i])
		i++;
	new_arr = malloc(sizeof(char *) * (i + 2));
	if (!new_arr)
		return (perror("Error: malloc"), NULL);
	if (!arr)
	{
		new_arr[0] = ft_strdup("");
		new_arr[1] = NULL;
		return (new_arr);
	}
	i = -1;
	while (arr[++i])
		new_arr[i] = ft_strdup(arr[i]);
	new_arr[i] = ft_strdup("");
	new_arr[i + 1] = NULL;
	ft_free_tab(arr);
	return (new_arr);
}

char	**ft_realoc(char **arr, char *line)
{
	int		i;
	char	**new_arr;

	i = 0;
	new_arr = arr_cpy(arr);
	if (!new_arr)
	{
		if (arr)
			ft_free_tab(arr);
		return (NULL);
	}
	while (new_arr[i])
		i++;
	free(new_arr[i - 1]);
	new_arr[i - 1] = ft_strdup(line);
	return (new_arr);
}

char	**read_all(int fd)
{
	char	*line;
	char	**arr;

	arr = NULL;
	while ((line = get_next_line(fd)))
	{
		arr = ft_realoc(arr, line);
		free(line);
		if (!arr)
			return (NULL);
	}
	return (arr);
}
