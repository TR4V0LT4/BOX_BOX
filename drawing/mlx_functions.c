/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaadoun <yjaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:39:06 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/04/01 17:00:21 by yjaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	move_player(int keycode, t_data *img)
{
	if (keycode == W_KEY)
		move_player_w(img);
	if (keycode == A_KEY)
		move_player_a(img);
	if (keycode == D_KEY)
		move_player_d(img);
	if (keycode == S_KEY)
		move_player_s(img);
	if (keycode == ESC_KEY)
		close_window(img);
	if (keycode == 124)
	{ 
		img->map->angle -= 0.1;
		draw_map(img);
		cast_rays(img);
	}
	if (keycode == 123)
	{ 
		img->map->angle += 0.1;
		draw_map(img);
		cast_rays(img);
	}
	return (0);
}
int comp(float z,  float y)
{
	float eps = 0.000000000001;
	return ( fabs(z - y) <= eps);
}

void cast_rays(t_data *img)
{	
	float	ry = 0;
	float 	rx = 0;
	int line;
	double y;
	double x;
	double ray;
	int i;
	int next_x;
	int next_y;

	y = img->map->y * 50;
	x = img->map->x * 50;

	line = floor(img->map->y) ;
	ry = img->map->y - (float)line; 
	rx = (ry / tan(img->map->angle))  ;
	ray =  (sqrt((pow(ry,2)+pow(rx,2))));	
	next_y = floor(img->map->y - ry );
	next_x = floor(img->map->x + rx );
	while(img->map->map[next_x ][next_y -1 ] != '1')
	{
		printf("wall[%d][%d] = %c \n",next_x, next_y ,img->map->map[next_x][next_y]);
			ry += 1; 
	 		rx = (ry / tan(img->map->angle))  ;
		 	ray =  sqrt((pow(ry,2)+pow(rx,2))) ;
		next_y = floor(img->map->y - ry );
		next_x = floor(img->map->x + rx );
		printf("next_x = %d && next_y = %d\n", next_x, next_y);
	}
	i = (( ray ) * 50);
	while(i--) 
	{
		mlx_pixel_put(img->mlx,img->win, x, y, 0xfee440);
		y -= sin(img->map->angle);
		x += cos(img->map->angle);
 	}
	printf(" ==============================> after : rx == %f  && ry == %f ray = %f\n", rx * 50 , ry * 50, ray * 50 );
	mlx_pixel_put(img->mlx,img->win, rx * 50, (img->map->y -ry) *50, 0xd90429);
}

t_data	init_func(t_data img)
{
	img.height = (img.map->len - 1) * 50;
	img.width = (img.map->long_line - 1) * 50;
	img.map->y = img.map->y_player;
	img.map->x = img.map->x_player;
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, img.width, img.height, "Hello");
	img.img = mlx_new_image(img.mlx, img.width, img.height);
	return (img);
}

void	ft_images(t_data *img)
{
	img->wall = mlx_xpm_file_to_image(img->mlx, "./images/wall.xpm",
		&img->width, &img->height);
	img->player = mlx_xpm_file_to_image(img->mlx, "./images/player.xpm",
		&img->width, &img->height);
	img->shadow = mlx_xpm_file_to_image(img->mlx, "./images/background.xpm",
		&img->width, &img->height);
}

void raycasting(t_data img)
{
	img = init_func(img);
	ft_images(&img);
	img.height = (img.map->len - 1) * 50;
	img.width = (img.map->long_line - 1) * 50;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	draw_map(&img);
	//player moves//
	//cast_rays(&img);
	destroy_window(img);
	mlx_hook(img.win, 2, 0L, move_player, &img);
	mlx_loop(img.mlx);
}
