/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:49:17 by agiliber          #+#    #+#             */
/*   Updated: 2024/08/06 14:52:31 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_libft.h"

void	free_everything(char **s)
{
	int	index;

	index = 0;
	while (s[index])
	{
		free(s[index]);
		index++;
	}
	free(s);
}
