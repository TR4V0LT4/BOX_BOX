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
		if(img->map->angle < 0)
			img->map->angle += (2 * M_PI);
		//draw_map(img);
		draw_world(img);
		cast_rays(img);
	}
	if (keycode == 123)
	{ 
		
		img->map->angle += 0.1;
		if(img->map->angle > (2 * M_PI))
			img->map->angle -= (2 * M_PI);
		//draw_map(img);
		draw_world(img);
		cast_rays(img);
	}
	return (0);
}
int comp(float z,  float y)
{
	float eps = 0.000000000001;
	return ( fabs(z - y) <= eps);
}

double cast_rays1(t_data *img , float view)
{	
	float	ry = 0;
	float 	rx = 0;
	int line = 0;
	float ray = 0;
	int next_x = 0;
	int next_y = 0;
	
	line = floor(img->map->y) ;
	ry = img->map->y - (float)line; 
	rx = (ry / tan(view))  ;
	ray =  (sqrt((pow(ry,2)+pow(rx,2))));	
	next_y = floor(img->map->y - ry );
	next_x = floor(img->map->x + rx );
	
if((next_y < ((img->height / 50)) && next_y > 0) && (next_x <= (img->width / 50 ) && next_x >= 0))
	if(img->map->map[next_y - 1  ][next_x ] == '1')
		return ray;

			while (TRUE)
			 {	
					ry += 1; 
					rx = fabs((fabs(ry) / tan(view)));
					next_x = floor(img->map->x + rx );
					next_y = floor(img->map->y - ry);
					ray =  sqrt((pow(ry,2) + pow(rx,2)));

					if((next_y < ((img->height / 50)) && next_y > 0) && (next_x <= (img->width / 50 ) && next_x >= 0))
					{
						if(img->map->map[next_y - 1  ][next_x ] == '1')
							break;		
					}
					else
						break;
			 }
	return (ray);
}
double cast_rays2(t_data *img , float view)
{
	float	ry = 0;
	float 	rx = 0;
	float ray = 0;
	int next_x = 0;
	int next_y = 0;	
	
	rx =   ceil(img->map->x) - img->map->x  ;
	ry = rx * tan( view); 
	ray =  (sqrt((pow(ry,2)+pow(rx,2))));	
	next_y = floor(img->map->y - ry );
	next_x = floor(img->map->x + rx ) ;

if((next_y < ((img->height / 50)) && next_y > 0) && (next_x <= (img->width / 50 ) && next_x >= 0))
	if(img->map->map[next_y ][next_x ] == '1')
		return ray;

	 	while(TRUE)
		{	
	 			rx +=  1;
				ry = rx * tan( view); 
				if(ry > img->map->y)
					ry = img->map->y;
				ray =  (sqrt((pow(ry,2)+pow(rx,2))));	
				next_y = floor(img->map->y - ry );
				next_x = floor(img->map->x + rx ) ;
				if((next_y < ((img->height / 50)) && next_y > 0) && (next_x <= (img->width / 50 ) && next_x >= 0))
				{
					if(img->map->map[next_y ][next_x ] == '1')
						break;		
				}
				else
					break;
		} 		
	return (ray);
}

double cast_rays3(t_data *img, float view)
{
	float	ry = 0;
	float 	rx = 0;
	float ray = 0;
	int next_x = 0;
	int next_y = 0;	
	
	rx =  img->map->x - floor(img->map->x);
	ry = rx * tan(M_PI -  view);
	ray =  (sqrt((pow(ry,2)+pow(rx,2))));	
	next_y = floor(img->map->y - ry );
	next_x = floor(img->map->x - rx ) ;

	if((next_y < ((img->height / 50)) && next_y > 0) && (next_x <= (img->width / 50 ) && next_x >= 0))
	 	if(img->map->map[next_y ][next_x - 1 ] == '1')
	 		return ray;

	 	while(TRUE)
		{	
	 			rx +=  1;
				ry = rx * tan( M_PI  - view); 
				ray =  (sqrt((pow(ry,2)+pow(rx,2))));	
				next_y = floor(img->map->y - ry );
				next_x = floor(img->map->x - rx ) ;
				if((next_y < ((img->height / 50)) && next_y > 0) && (next_x <= (img->width / 50 ) && next_x >= 0))
				{
						
					if(img->map->map[next_y ][next_x -  1] == '1')
						break;		
				}
				else
					break;
		} 		
	return (ray);
}

double cast_rays4(t_data *img, float view)
{	
	float	ry = 0;
	float 	rx = 0;
	int line = 0;
	float ray = 0;
	int next_x = 0;
	int next_y = 0;
	
	line = floor(img->map->y) ;
	ry = img->map->y - (float)line; 
	rx = (ry / tan(M_PI - view))  ;
	ray =  (sqrt((pow(ry,2)+pow(rx,2))));	
	next_y = floor(img->map->y - ry );
	next_x = floor(img->map->x - rx );
	
	if((next_y < ((img->height / 50)) && next_y > 0) && (next_x <= (img->width / 50 ) && next_x >= 0))
		if(img->map->map[next_y - 1  ][next_x ] == '1')
			return ray;

			while (TRUE)
			 {	
					ry += 1; 
					rx = fabs((fabs(ry) / tan(M_PI - view)));
					next_x = floor(img->map->x - rx );
					next_y = floor(img->map->y - ry);
					ray =  sqrt((pow(ry,2) + pow(rx,2)));

					if((next_y < ((img->height / 50)) && next_y > 0) && (next_x <= (img->width / 50 ) && next_x >= 0))
					{
						if(img->map->map[next_y - 1  ][next_x ] == '1')
							break;		
					}
					else
						break;	
			 }
	return (ray);
}

double cast_rays5(t_data *img, float view)
{	
	float	ry = 0;
	float 	rx = 0;
	int line = 0;
	float ray = 0;
	int next_x = 0;
	int next_y = 0;
	
	line = ceil(img->map->y) ;
	ry = (float)line -  img->map->y  ; 
	rx = (ry / tan(view - M_PI))  ;
	ray =  (sqrt((pow(ry,2)+pow(rx,2))));	
	next_y = floor(img->map->y + ry );
	next_x = floor(img->map->x - rx );
	
	if((next_y < ((img->height / 50)) && next_y > 0) && (next_x <= (img->width / 50 ) && next_x >= 0))
		if(img->map->map[next_y   ][next_x ] == '1')
			return ray;

			while (TRUE)
			 {				
					ry += 1; 
					rx = fabs((fabs(ry) / tan(M_PI - view)));
					next_x = floor(img->map->x - rx );
					next_y = floor(img->map->y + ry);
					ray =  sqrt((pow(ry,2) + pow(rx,2)));

					if((next_y < ((img->height / 50)) && next_y > 0) && (next_x <= (img->width / 50 ) && next_x >= 0))
					{
						if(img->map->map[next_y   ][next_x ] == '1')
							break;		
					}
					else
						break;
			
			 }
	return (ray);
}

double cast_rays6(t_data *img, float view)
{	
	float	ry = 0;
	float 	rx = 0;
	int line = 0;
	float ray = 0;
	int next_x = 0;
	int next_y = 0;
	
	line = ceil(img->map->y) ;
	ry = (float)line -  img->map->y  ; 
	rx = ry * tan( ((3 * M_PI) / 2) - view )  ;
	ray =  (sqrt((pow(ry,2)+pow(rx,2))));	
	next_y = floor(img->map->y + ry );
	next_x = floor(img->map->x - rx );
	
	if((next_y < ((img->height / 50)) && next_y > 0) && (next_x <= (img->width / 50 ) && next_x >= 0))
		if(img->map->map[next_y ][next_x ] == '1')
			return ray;

			while (TRUE)
			 {	
					ry += 1; 
					rx = (ry * tan( ((3 * M_PI) / 2) - view )) ;
					next_x = floor(img->map->x - rx );
					next_y = floor(img->map->y + ry);
					ray =  sqrt((pow(ry,2) + pow(rx,2)));

					if((next_y < ((img->height / 50)) && next_y > 0) && (next_x <= (img->width / 50 ) && next_x >= 0))
					{
						if(img->map->map[next_y   ][next_x  ] == '1')
							break;		
					}
					else
						break;
			 }
	return (ray);
}



void cast_rays(t_data *img)
{
	 double ray1 = 0;
	double ray2 = 0;
	 double ray3 = 0;
	 double ray4 = 0;
	 double ray5 = 0;
	 double ray6 = 0;
	// - (M_PI / 6);
	double i = 0; 
	double x = 0;
	while(i <=  (M_PI / 3))
	{
		img->map->view = img->map->angle + i;
		if(img->map->view >= (2 * M_PI))
			img->map->view -= (2 * M_PI);
		if( img->map->view >= 0 &&  img->map->view <= (M_PI / 2) )	
		{
			
		  		ray1 = cast_rays1(img,img->map->view);
		 		ray2 = cast_rays2(img, img->map->view);	
				
				if (ray2 && ray1 > ray2  )
		 			dala(img,ray2,&x);
				else
	 				dala(img,ray1,&x);
	 	}
		else  if( img->map->view > (M_PI / 2) && img->map->view < M_PI )	
		{
			ray4 = cast_rays4(img,img->map->view);
			ray3 = cast_rays3(img,img->map->view);	
			 if (ray3 && ray4 > ray3  )
			  	dala(img,ray3,&x);
			else
	 			dala(img,ray4,&x);
		 }
		 else  if( img->map->view >= M_PI && img->map->view <  (( 3 * M_PI) / 2 ) )	
		{
			ray5 = cast_rays5(img,img->map->view);
			ray3 = cast_rays3(img,img->map->view);	
			
			if (ray3 && ray5 > ray3  )
		  		dala(img,ray3,&x);
			else
	 			dala(img,ray5,&x);	
		 }
		else  if( img->map->view >=  (( 3 * M_PI) / 2 )  && img->map->view <= M_PI * 2 )	
		{
			ray6 = cast_rays6(img,img->map->view);
			ray2 = cast_rays2(img,img->map->view);	
			
			if (ray2 && ray6 > ray2  )
			  dala(img,ray2,&x);
			else
	 			dala(img,ray6,&x);
		 }
		  
		i += 0.005;
		x += 1;
	}
} 	
	
void dala(t_data *img , double ray, double *x)
{
	double y;
	int color = 0x000000;
	
		 y = img->height / 2;
		int i = (( ray ) * 50) ;
		int j = 3;
		while(j--)
		{
			i = (( ray ) * 50) ;
			while(i--) 
			{
				mlx_pixel_put(img->mlx,img->win, *x, y, color);
				y -= 1;
 			}
		 	*x += 0.11;
		}

}

void draw_rays(t_data *img , float ray ,int color )
{
	double x;
	double y;
	
		 y = img->map->y * 50;
		 x = img->map->x * 50;
		int i = (( ray ) * 50);
		while(i--) 
		{
			mlx_pixel_put(img->mlx,img->win, x, y, color);
			y -= sin(img->map->view);
			x += cos(img->map->view);
 		}

}
t_data	init_func(t_data img)
{
	img.height = (img.map->len - 1) * 50;
	img.width = (img.map->long_line ) * 50;
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
	//draw_map(&img);
	//player moves//
	//cast_rays(&img);

	draw_world(&img);
	destroy_window(img);
	mlx_hook(img.win, 2, 0L, move_player, &img);
	mlx_loop(img.mlx);
}
