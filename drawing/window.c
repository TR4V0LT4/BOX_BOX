/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaadoun <yjaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:17:42 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/04/01 14:45:40 by yjaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

// void	open_window(t_data *game)
// {
// 	game->win = mlx_new_window(game->mlx, game->w * 50, game->h * 50,
// 			"SoLong By Yjaadoun");
// 	if (game->win == NULL)
// 	{
// 		free_map(game);
// 		free(game->mlx);
// 		exit(0);
// 	}
// }

void	close_window(t_data *game)
{
	mlx_destroy_window(game->mlx, game->win);
	// free_map(game);
	// free(game->mlx);
	exit(0);
}

int	esc_key(int key, t_data *game)
{
	if (key == 53)
		close_window(game);
	return (0);
}


int	cross_key()
{
	exit(1);
}

void	destroy_window(t_data game)
{
	mlx_hook(game.win, 2, 1L << 0, &esc_key, &game);
	mlx_hook(game.win, 17, 1L << 0, &cross_key, &game);
}
