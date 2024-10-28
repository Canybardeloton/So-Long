/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dimensions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:59:11 by agiliber          #+#    #+#             */
/*   Updated: 2024/08/19 10:17:15 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_length(int index, char **input)
{
	int	index_x;
	int	length;

	(void)index;
	index_x = 0;
	length = 0;
	while (input[index_x])
	{
		length++;
		index_x++;
	}
	return (length);
}

int	map_width(int index, char **input)
{
	int	index_y;
	int	width;

	width = 0;
	index_y = 0;
	while (input[index][index_y])
	{
		width++;
		index_y++;
	}
	return (width);
}

int	count_words(char *input)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (input[i])
	{
		count++;
		i++;
	}
	return (count);
}
