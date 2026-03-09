/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellabiad <ellabiad@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 12:03:48 by ellabiad          #+#    #+#             */
/*   Updated: 2026/03/09 09:23:46 by ellabiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../libft/libft.h"
# include <string.h>
# include <errno.h>

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
	int		pos_x;
	int		pos_y;
	char	dir;
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
int		parse_colors(char *line, t_map *map);
int		parse_textures(char *line, t_map *map);
int		parse_map(char **file, int start, t_map *map);
void	free_map(t_map *map);

//-- Filler Utils
int		skip_spaces(char *line);
void	set_map(t_map *map);
void	free_map(t_map *map);
char	*trim_nl(char *line);
int		check_empty_line(char *s);

//-- Filler Utils 2
int		found_longest_line(char **arr);
int		arr_size(char **arr);
char	*pad_line(char *line, int map_width);

//-- Filler Utils 3
int		check_valid_player(char *s, int *player, int idx, t_map *map);
int		check_valid_char(char *s, int idx);
int		check_enclosed_by_wall(char **file);

#endif