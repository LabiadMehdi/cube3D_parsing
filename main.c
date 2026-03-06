/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellabiad <ellabiad@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:53:14 by ellabiad          #+#    #+#             */
/*   Updated: 2026/03/06 14:34:47 by ellabiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/parser.h"

int main(int ac, char **av)
{
	char *filename;

	if (ac != 2)
		return (1);
	filename = av[1];
	check_open(filename);
	return (0);
}