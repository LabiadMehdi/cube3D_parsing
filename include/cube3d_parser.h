/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_parser.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellabiad <ellabiad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 12:03:48 by ellabiad          #+#    #+#             */
/*   Updated: 2026/03/05 12:39:00 by ellabiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_PARSER_H
# define CUBE3D_PARSER_H

#include "../libft/libft.h"

typedef struct s_game
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor[3];
	int		ceiling[3];
	char	**map;
	int		map_width;
	int		map_heigth;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plance_y;
}	t_game;

#endif