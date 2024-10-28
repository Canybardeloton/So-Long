/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_final.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:57:41 by agiliber          #+#    #+#             */
/*   Updated: 2024/08/26 15:03:33 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_final(t_data *data, char **map, char *full_map)
{
	if (full_map != NULL)
		free(full_map);
	free_everything(map);
	close_instructions(data);
	error_handling(data);
	free(data);
}
