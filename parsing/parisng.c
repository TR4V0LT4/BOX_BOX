/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parisng.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaadoun <yjaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:56:12 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/03/31 15:54:15 by yjaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	initialisation(t_map *map)
{
	map->line = NULL;
	map->map = NULL;
	map->so_path = NULL;
	map->we_path = NULL;
	map->ea_path = NULL;
	map->no_path = NULL;
	map->c_color = NULL;
	map->f_color = NULL;
	map->long_line = 0;
	map->len = 0;
}

t_map	*parsing(char *av)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	initialisation(map);
	map->line = get_map(av);
	map_elements(map);
	check_border(map);
	return (map);
}
