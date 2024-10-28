/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rules2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:57:06 by agiliber          #+#    #+#             */
/*   Updated: 2024/08/27 11:12:29 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_exit(char **map)
{
	int	index_x;
	int	index_y;
	int	count;

	index_x = 0;
	index_y = 0;
	count = 0;
	while (map[index_x])
	{
		index_y = 0;
		while (map[index_x][index_y])
		{
			if (map[index_x][index_y] == 'E')
				count++;
			index_y++;
		}
		index_x++;
	}
	if (count == 0)
		return (FALSE);
	if (count > 1)
		return (FALSE);
	return (TRUE);
}

int	check_start(char **map)
{
	int	index_x;
	int	index_y;
	int	count;

	index_x = 0;
	index_y = 0;
	count = 0;
	while (map[index_x])
	{
		index_y = 0;
		while (map[index_x][index_y])
		{
			if (map[index_x][index_y] == 'P')
				count++;
			index_y++;
		}
		index_x++;
	}
	if (count == 0)
		return (FALSE);
	if (count > 1)
		return (FALSE);
	return (TRUE);
}

int	check_filling(char **map)
{
	int	index_x;
	int	index_y;

	index_x = 0;
	index_y = 0;
	while (map[index_x])
	{
		index_y = 0;
		while (map[index_x][index_y])
		{
			if (map[index_x][index_y] == '1' || map[index_x][index_y] == '0'
				|| map[index_x][index_y] == 'E' || map[index_x][index_y] == 'P'
				|| map[index_x][index_y] == 'C')
			index_y++;
			else
				return (FALSE);
		}
		index_x++;
	}
	return (TRUE);
}
