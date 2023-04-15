/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaadoun <yjaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:01:36 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/03/31 15:56:18 by yjaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	skip_spaces_begin(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != SPACE && str[i] != TAB)
			return (i);
		else
			i++;
	}
	return (i);
}

void	color_textures(t_map *map)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (i < 6)
	{
		j = skip_spaces_begin(map->line[i]);
		if (!ft_strncmp((map->line[i] + j), "WE ", 3))
			map->we_path = ft_strdup(map->line[i] + j);
		else if (!ft_strncmp((map->line[i] + j), "NO ", 3))
			map->no_path = ft_strdup(map->line[i] + j);
		else if (!ft_strncmp((map->line[i] + j), "SO ", 3))
			map->so_path = ft_strdup(map->line[i] + j);
		else if (!ft_strncmp((map->line[i] + j), "EA ", 3))
			map->ea_path = ft_strdup(map->line[i] + j);
		else if (!ft_strncmp((map->line[i] + j), "F ", 2))
			map->f_color = ft_strdup(map->line[i] + j);
		else if (!ft_strncmp((map->line[i] + j), "C ", 2))
			map->c_color = ft_strdup(map->line[i] + j);
		else
			exit_error("ERROR : wrong elements in map\n");
		i++;
	}
}

void	filling_map(t_map *map)
{
	int	j;
	int	i;

	i = 6;
	j = 0;
	map->len = doble_arr_len(map->line) - 5;
	map->map = malloc(sizeof(char *) * map->len);
	while (map->line[i] != NULL)
	{
		map->map[j] = ft_strdup(map->line[i]);
		i++;
		j++;
	}
	map->map[j] = NULL;
}

void	map_elements(t_map *map)
{
	color_textures(map);
	filling_map(map);
	player_position(map);
	map->long_line = longest_line(map->map);
}
