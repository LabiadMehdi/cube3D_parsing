/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellabiad <ellabiad@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 12:03:48 by ellabiad          #+#    #+#             */
/*   Updated: 2026/03/07 11:21:34 by ellabiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../libft/libft.h"

typedef struct s_map
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor;
	int		ceiling;
	int		floor_set;
	int		ceiling_set;
	char	**map;
	int		map_w;
	int		map_h;
	// double	pos_x;
	// double	pos_y;
	// double	dir_x;
	// double	dir_y;
	// double	plane_x;
	// double	plane_y;
}	t_map;

//-- Checker
int		check_extension(char *filename);
int		check_open(char *filename);
char	**read_all(int fd);

//-- Filler
int		check_parsed_elements(t_map *map);
t_map	*data_filler(char **file);
int		parse_elements(char *line, t_map *map, int line_idx);
void	free_map(t_map *map);

//-- Utils
int	skip_spaces(char *line);

#endif