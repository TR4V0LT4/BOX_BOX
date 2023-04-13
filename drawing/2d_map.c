#include "../cub.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int draw_lines(t_data *img )
{
	float x = 0 ;
	float y = 0 ;
	int color = 0xdee2e6;
		
	while(x < img->width )
	{
		y = 0;
		while(y < img->height)
		{
			mlx_pixel_put(img->mlx, img->win, x, y, color);	
				y++;
			}
			x += 50;
		}
	y = 0;
	x = 0;
	while(y < img->height)
	{
		x = 0;
		while(x < img->width)
		{
			mlx_pixel_put(img->mlx,img->win, x   , y ,color);	
			x++;
		}
		y += 50;
	}
	return 0;
}

int	draw_map(t_data *img)
{
	int row = doble_arr_len(img->map->map);
	int col = longest_line(img->map->map) ;
	int x = 0;
	int y ;
	while (x < row )
	{
		y = 0;
		while (y < col )
		{
			if(img->map->map[x][y] == '1')
				mlx_put_image_to_window(img->mlx, img->win, img->wall,y * 50 , x * 50 );	
			else
				mlx_put_image_to_window(img->mlx, img->win, img->shadow,y * 50 , x * 50 );	
			y++;
		}

		x++;
	}
	draw_lines(img);
	mlx_put_image_to_window(img->mlx, img->win, img->player, (img->map->x * 50) - 5, (img->map->y * 50) - 5);
	return (0);
}

void draw_world(t_data *img)
{
	int i = 0;
	int j;
	int color = 0xade8f4;


		while(i < img->height )
		{	
			if(i > img->height / 2)
				color = 0x283618;

			j = 0;
			while(j < (img->width + 50) )
			{
				my_mlx_pixel_put(img,j, i, color);
				j++;
			}	
			i++;
		}

}
