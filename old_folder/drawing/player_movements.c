/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaadoun <yjaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:54:41 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/04/01 15:01:25 by yjaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	move_player_w(t_data *img)
{
	if (img->map->map[(int)(img->map->y - 1)][(int)img->map->x] != '1'  || (img->map->y - (int)img->map->y > 0.2))
	{
		printf("x = %f &&  y = %f \n", img->map->x, img->map->y);
		mlx_put_image_to_window(img->mlx, img->win, img->shadow,(img->map->x * 50) - 5 , (img->map->y * 50) - 5 );
		img->map->y -= sin(img->map->angle) / 10  ;
		img->map->x += cos(img->map->angle) / 10 ;
	//	draw_map(img);
		draw_world(img);
		cast_rays(img);
	}
}

void	move_player_s(t_data *img)
{
	if (img->map->map[(int)(img->map->y + 1)][(int)img->map->x] != '1' || (img->map->y - (int)img->map->y < 0.8))
	{
		mlx_put_image_to_window(img->mlx, img->win, img->shadow,(img->map->x * 50) - 5 , (img->map->y * 50) - 5 );
		img->map->y += sin(img->map->angle) / 10;
		img->map->x -= cos(img->map->angle) / 10;
		//draw_map(img);
		draw_world(img);
		cast_rays(img);
	}
}

void	move_player_a(t_data *img)
{
	if (img->map->map[(int)(img->map->y)][(int)img->map->x - 1] != '1' ||  (img->map->x - (int)img->map->x > 0.2) )
	{
		mlx_put_image_to_window(img->mlx, img->win, img->shadow,(img->map->x * 50) - 5 , (img->map->y * 50) - 5 );
		img->map->y += sin(img->map->angle - (M_PI / 2)) / 10;
		img->map->x -= cos(img->map->angle - (M_PI / 2)) / 10;
		//draw_map(img);
		draw_world(img);
		cast_rays(img);
	}
}

void	move_player_d(t_data *img)
{
	if (img->map->map[(int)(img->map->y)][(int)img->map->x + 1] != '1' || (img->map->x - (int)img->map->x < 0.8))
	{
		mlx_put_image_to_window(img->mlx, img->win, img->shadow,(img->map->x * 50) - 5 , (img->map->y * 50) - 5 );
		img->map->y -= sin(img->map->angle - (M_PI / 2)) / 10;
		img->map->x += cos(img->map->angle - (M_PI / 2)) / 10;
		//draw_map(img);
		draw_world(img);
		cast_rays(img);
	}
}

