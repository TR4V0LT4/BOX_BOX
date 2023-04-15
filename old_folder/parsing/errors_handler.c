/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaadoun <yjaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:03:32 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/03/18 13:51:43 by yjaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

// TO DO SGFT 
t_bool	is_map_valid(t_map *map)
{
	int	i;
	int	j;

	i = 1;
	while (map->map[i] != NULL)
	{
		j = 1;
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == '0')
			{
				if (!ft_strchr("01", map->map[i][j + 1])
					|| !ft_strchr("01", map->map[i][j - 1])
					|| !ft_strchr("01", map->map[i - 1][j])
					|| !ft_strchr("01", map->map[i + 1][j]))
					return (FALSE);
			}	
			j++;
		}
		i++;
	}
	return (TRUE);
}
