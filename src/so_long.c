/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:09:05 by agiliber          #+#    #+#             */
/*   Updated: 2024/08/27 13:25:10 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char	**map;
	char	*full_map;
	t_data	*data;

	if (ac < 2)
		return (ft_putstr_fd("Error\nNot enough arguments\n", 2), FALSE);
	full_map = open_map(av);
	if (full_map == NULL)
		return (ft_putstr_fd("Error\nCant get map\n", 2), FALSE);
	map = ft_split(full_map, '\n');
	if (!map)
		return (free(full_map), ft_putstr_fd("Error\nMap error\n", 2), FALSE);
	free(full_map);
	if (map_check(map) == FALSE)
		return (free_everything(map), ft_putstr_fd("Error\nCheck\n", 2), FALSE);
	data = malloc(sizeof(t_data));
	if (!data)
		return (free(full_map), free_everything(map), FALSE);
	if (init_struc(data, map) == FALSE)
		return (free_final(data, map, full_map), \
			ft_putstr_fd("Error\nFill struc failed\n", 2), FALSE);
	if (!start_rendering(data))
		return (free_final(data, map, full_map), \
			ft_putstr_fd("Error\nRendering\n", 2), FALSE);
	return (free_final(data, map, full_map), FALSE);
}
